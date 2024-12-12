// Copyright The OpenTelemetry Authors
// SPDX-License-Identifier: Apache-2.0

#include "opentelemetry/exporters/otlp/otlp_http_exporter_factory.h"
#include "opentelemetry/exporters/otlp/otlp_http_exporter_options.h"
#include "opentelemetry/context/propagation/global_propagator.h"
#include "opentelemetry/context/propagation/text_map_propagator.h"
#include "opentelemetry/exporters/ostream/span_exporter_factory.h"
#include "opentelemetry/nostd/shared_ptr.h"
#include "opentelemetry/sdk/trace/simple_processor_factory.h"
#include "opentelemetry/sdk/trace/tracer_context.h"
#include "opentelemetry/sdk/trace/tracer_context_factory.h"
#include "opentelemetry/sdk/trace/tracer_provider_factory.h"
#include "opentelemetry/trace/propagation/http_trace_context.h"
#include "opentelemetry/trace/provider.h"
#include "opentelemetry/ext/http/client/http_client_factory.h"
#include "opentelemetry/sdk/resource/semantic_conventions.h"
#include "opentelemetry/sdk/common/global_log_handler.h"

#include <string>
#include <iostream>
#include <curl/curl.h>
#include "include/httplib.h"


namespace trace     = opentelemetry::trace;
namespace trace_sdk = opentelemetry::sdk::trace;
namespace otlp      = opentelemetry::exporter::otlp;
namespace internal_log = opentelemetry::sdk::common::internal_log;
namespace resource = opentelemetry::sdk::resource;
namespace nostd = opentelemetry::nostd;
namespace propagation = opentelemetry::context::propagation;

namespace {
    opentelemetry::exporter::otlp::OtlpHttpExporterOptions opts;
    std::shared_ptr<opentelemetry::sdk::trace::TracerProvider> provider;

    void InitTracer() {
        std::cout << "Initializing tracer..." << std::endl;
        // 创建 OTLP HTTP 导出器, 负责将追踪数据发送到远程服务器，opts 中的 URL 指定了目标服务地址。
        auto exporter = otlp::OtlpHttpExporterFactory::Create(opts);
        // 创建简单处理器, 负责接收并处理 Span 数据
        auto processor = trace_sdk::SimpleSpanProcessorFactory::Create(std::move(exporter));

        // 设置资源属性, 定义了追踪数据的元信息
        resource::ResourceAttributes attributes = {
                {resource::SemanticConventions::kServiceName, "process-demo-B"},   // 自定义应用名
                {resource::SemanticConventions::kHostName,    "v7-virtual-machine"}   // hostName
        };
        // 创建资源
        auto resource = opentelemetry::sdk::resource::Resource::Create(attributes);

        // 创建追踪提供者, 负责管理追踪器和上下文
        std::shared_ptr<opentelemetry::trace::TracerProvider> api_provider =
                trace_sdk::TracerProviderFactory::Create(std::move(processor), std::move(resource));
        // 设置全局追踪提供者
        trace::Provider::SetTracerProvider(api_provider);

        // 设置默认的全局传播器
        propagation::GlobalTextMapPropagator::SetGlobalPropagator(
                nostd::shared_ptr<propagation::TextMapPropagator>(new trace::propagation::HttpTraceContext()));

        std::cout << "Tracer initialized successfully." << std::endl;
    }

    void CleanupTracer() {
        std::shared_ptr<opentelemetry::trace::TracerProvider> none;
        trace::Provider::SetTracerProvider(none);
        std::cout << "Tracer cleanup completed." << std::endl;
    }

    // HttpHeadersCarrier 实现
    class HttpHeadersCarrier : public opentelemetry::context::propagation::TextMapCarrier {
    public:
        explicit HttpHeadersCarrier(std::map<std::string, std::string> &headers) : headers_(headers) {}

        nostd::string_view Get(nostd::string_view key) const noexcept override {
            auto it = headers_.find(std::string(key));
            if (it != headers_.end()) {
                std::cout << "Header found: " << key << " = " << it->second << std::endl;
                return it->second;
            }
            std::cout << "Header not found for key: " << key << std::endl;
            return "";
        }

        void Set(nostd::string_view key, nostd::string_view value) noexcept override {
            headers_[std::string(key)] = std::string(value);
            std::cout << "Carrier Set: " << key << " = " << value << std::endl;
        }

        std::map<std::string, std::string> &headers_;
    };

    void startServer() {
        httplib::Server server;

        server.Post("/process_b_endpoint", [](const httplib::Request &req, httplib::Response &res) {
            std::cout << "ProcessB received here" << std::endl;

            if(req.headers.empty()){
                std::cout << "Request headers are empty!" << std::endl;
                return;
            } else {
                std::cout << "Received headers:" << std::endl;
                for (const auto& header : req.headers) {
                    std::cout << header.first << ": " << header.second << std::endl;
                }
            }
            std::cout << std::endl;

            // 提取 HTTP Headers
            std::map<std::string, std::string> headers(req.headers.begin(), req.headers.end());
            HttpHeadersCarrier carrier(headers);

            // 提取父上下文并关联 Span
            auto propagator = propagation::GlobalTextMapPropagator::GetGlobalPropagator();
            std::cout << "Global propagator: " << (propagator ? "initialized" : "not initialized") << std::endl;

            opentelemetry::context::Context ctx;
            auto parent_ctx = propagator->Extract(carrier, ctx);

            // 创建新的 Span，并将其关联到提取的上下文
            auto tracer = opentelemetry::trace::Provider::GetTracerProvider()->GetTracer("process-b");
            if (!tracer) {
                std::cout << "Tracer is invalid!" << std::endl;
            }

            opentelemetry::trace::StartSpanOptions options;
            options.parent = parent_ctx;  // 直接设置 parent 属性

            auto span = tracer->StartSpan("span-b", options);
            if (span) {
                std::cout << "New span created successfully!" << std::endl;
            } else {
                std::cout << "Failed to create new span!" << std::endl;
            }

            // 响应请求
            res.set_content("Received headers and created a new span!", "text/plain");
            std::cout << "processB finish" << std::endl << std::endl;
        });

        std::cout << "ProcessB is attempting to listen at http://127.0.0.1:8080" << std::endl;
        if (!server.listen("127.0.0.1", 8080)) {
            std::cerr << "Failed to start server on 127.0.0.1:8080!" << std::endl;
            exit(1);
        }
        std::cout << "ProcessB successfully started on 127.0.0.1:8080" << std::endl;
    }
}
// namespace

int main(int argc, char *argv[])
{
    std::string urlString = "http://localhost:4318/v1/traces";  //Jeajer UI
    opts.url = urlString;
    std::cout << "urlString:" << urlString << std::endl;

    InitTracer();
    startServer();
    CleanupTracer();
    return 0;
}
