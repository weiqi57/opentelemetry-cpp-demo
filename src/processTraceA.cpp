// Copyright The OpenTelemetry Authors
// SPDX-License-Identifier: Apache-2.0

#include "opentelemetry/exporters/otlp/otlp_http_exporter_factory.h"
#include "opentelemetry/exporters/otlp/otlp_http_exporter_options.h"
#include "opentelemetry/context/propagation/global_propagator.h"
#include "opentelemetry/context/propagation/text_map_propagator.h"
#include "opentelemetry/nostd/shared_ptr.h"
#include "opentelemetry/sdk/trace/simple_processor_factory.h"
#include "opentelemetry/sdk/trace/tracer_context.h"
#include "opentelemetry/sdk/trace/tracer_provider_factory.h"
#include "opentelemetry/trace/provider.h"
#include "opentelemetry/trace/propagation/http_trace_context.h"
#include "opentelemetry/sdk/resource/semantic_conventions.h"
#include "opentelemetry/sdk/common/global_log_handler.h"

#include <string>
#include <iostream>
#include "include/httplib.h"
#include <iomanip>  // std::hex, std::setfill, std::setw

namespace trace     = opentelemetry::trace;
namespace trace_sdk = opentelemetry::sdk::trace;
namespace otlp      = opentelemetry::exporter::otlp;
namespace internal_log = opentelemetry::sdk::common::internal_log;
namespace resource = opentelemetry::sdk::resource;
namespace nostd = opentelemetry::nostd;
namespace propagation = opentelemetry::context::propagation;

namespace
{
    opentelemetry::exporter::otlp::OtlpHttpExporterOptions opts;
    std::shared_ptr<opentelemetry::sdk::trace::TracerProvider> provider;

    void InitTracer()
    {
        std::cout << "Initializing tracer..." << std::endl;
        // 创建 OTLP HTTP 导出器, 负责将追踪数据发送到远程服务器，opts 中的 URL 指定了目标服务地址。
        auto exporter  = otlp::OtlpHttpExporterFactory::Create(opts);
        // 创建简单处理器, 负责接收并处理 Span 数据
        auto processor = trace_sdk::SimpleSpanProcessorFactory::Create(std::move(exporter));

        // 设置资源属性, 定义了追踪数据的元信息
        resource::ResourceAttributes attributes = {
                {resource::SemanticConventions::kServiceName, "process-demo-A"},   // 自定义应用名
                {resource::SemanticConventions::kHostName, "v7-virtual-machine"}   // hostName
        };
        // 创建资源
        auto resource = opentelemetry::sdk::resource::Resource::Create(attributes);

        // 创建追踪提供者, 负责管理追踪器和上下文
        std::shared_ptr<opentelemetry::trace::TracerProvider> api_provider =
                trace_sdk::TracerProviderFactory::Create(std::move(processor), std::move(resource));
        // 设置全局追踪提供者
        trace::Provider::SetTracerProvider(api_provider);


        //propagation::GlobalTextMapPropagator::SetGlobalPropagator(nostd::shared_ptr<trace::propagation::HttpTraceContext>());

        // 设置默认的全局传播器
        propagation::GlobalTextMapPropagator::SetGlobalPropagator(
                nostd::shared_ptr<propagation::TextMapPropagator>(new trace::propagation::HttpTraceContext()));

        std::cout << "Tracer initialized successfully." << std::endl;
    }

    void CleanupTracer()
    {
        std::shared_ptr<opentelemetry::trace::TracerProvider> none;
        trace::Provider::SetTracerProvider(none);
    }

    // HttpHeadersCarrier 实现
    /*
     * Carrier 是一个适配器，用于在应用程序的上下文和特定的传输机制（例如 HTTP headers）之间传递数据
     * TextMapCarrier 是 OpenTelemetry 中的抽象类，用于定义如何存取键值对。
     *
     * HttpHeadersCarrier 是自定义实现的 TextMapCarrier，
     * 用于适配 std::map<std::string, std::string> 类型的 HTTP headers
     * Get() 和 Set() 方法定义了如何从 Carrier 中读取和写入键值对。
     */
    class HttpHeadersCarrier : public opentelemetry::context::propagation::TextMapCarrier
    {
    public:
        explicit HttpHeadersCarrier(std::map<std::string, std::string> &headers) : headers_(headers) {}

        nostd::string_view Get(nostd::string_view key) const noexcept override
        {
            auto it = headers_.find(std::string(key));
            if (it != headers_.end())
            {
                return it->second;
            }
            return "";
        }

        void Set(nostd::string_view key, nostd::string_view value) noexcept override
        {
            headers_[std::string(key)] = std::string(value);
            std::cout << "Carrier Set: " << key << " = " << value << std::endl;
        }

        std::map<std::string, std::string> &headers_;
    };

    void SendToProcessB(const std::map<std::string, std::string> &headers)
    {
        try {
            std::cout << "Sending Headers:" << std::endl;
            for (const auto& header : headers) {
                std::cout << header.first << ": " << header.second << std::endl;
            }

            // 使用 localhost 或 127.0.0.1
            httplib::Client client("127.0.0.1", 8080);

            // 设置更长的连接超时时间
            client.set_connection_timeout(0, 500000); // 500 毫秒
            client.set_read_timeout(5, 0);   // 5 秒
            client.set_write_timeout(5, 0);  // 5 秒

            httplib::Headers http_headers;
            for (const auto &header : headers)
            {
                http_headers.emplace(header.first, header.second);
            }

            // 发送 POST 请求到 ProcessB 的指定路径
            auto res = client.Post("/process_b_endpoint", http_headers, "", "application/json");

            if (!res) {
                auto err = res.error();
                std::cerr << "HTTP Client Error: " << httplib::to_string(err) << std::endl;

                // 详细的错误诊断
                switch (err) {
                    case httplib::Error::Connection:
                        std::cerr << "Connection failed. Ensure ProcessB is running on 127.0.0.1:8080" << std::endl;
                        break;
                    case httplib::Error::BindIPAddress:
                        std::cerr << "Failed to bind IP address" << std::endl;
                        break;
                    case httplib::Error::Read:
                        std::cerr << "Read error" << std::endl;
                        break;
                    default:
                        std::cerr << "Unknown error" << std::endl;
                }
                return;
            }

            if (res->status == 200)
            {
                std::cout << "Headers successfully sent to ProcessB!" << std::endl;
            }
            else
            {
                std::cerr << "Failed to send headers, ProcessB responded with status: " << res->status << std::endl;
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Exception in SendToProcessB: " << e.what() << std::endl;
        }
    }

    std::string BytesToHex(const uint8_t *bytes, size_t size)
    {
        std::ostringstream hex_stream;
        for (size_t i = 0; i < size; ++i)
        {
            hex_stream << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[i]);
        }
        return hex_stream.str();
    }

    void ProcessA()
    {
        auto tracer = opentelemetry::trace::Provider::GetTracerProvider()->GetTracer("process-a");
        // 创建一个 Span
        auto span = tracer->StartSpan("span-a");
        trace::Scope scope(span);

        // 获取当前上下文
        /*
         * 上下文是 OpenTelemetry 的核心概念之一，用于存储和传播与当前操作相关的信息（例如 Span 的标识符、跟踪 ID）。
            当前上下文包含了当前活跃的 Span 信息

            使用 RuntimeContext::GetCurrent() 获取当前线程的上下文。
            当前 Span 会自动绑定到上下文中，使后续操作可以透明地访问追踪信息。
         */
        auto current_ctx = opentelemetry::context::RuntimeContext::GetCurrent();

        auto span_instance = trace::GetSpan(current_ctx);
        if (span_instance == nullptr)
        {
            std::cerr << "No active span in the current context." << std::endl;
            return;
        }

        auto span_context = trace::GetSpan(current_ctx)->GetContext();
        auto trace_id = span_context.trace_id();
        auto span_id = span_context.span_id();
        std::cout << "Trace ID: " << BytesToHex(trace_id.Id().data(), trace_id.kSize) << std::endl;
        std::cout << "Span ID: " << BytesToHex(span_id.Id().data(), span_id.kSize) << std::endl;

        // 创建 Carrier
        /*
         * Carrier 是一个适配器，用于在应用程序的上下文和特定的传输机制（例如 HTTP headers）之间传递数据。
         * TextMapCarrier 是 OpenTelemetry 中的抽象类，用于定义如何存取键值对。
         */
        std::map<std::string, std::string> headers;
        HttpHeadersCarrier carrier(headers);

        // 调试输出地址
        std::cout << "Headers address: " << &headers << std::endl;
        std::cout << "Carrier headers address: " << &(carrier.headers_) << std::endl;

        // 将上下文注入到 Carrier
        /*
         * Propagator 的作用：
            Propagator 是 OpenTelemetry 提供的传播器，负责在上下文和 Carrier 之间注入或提取数据。
            GlobalTextMapPropagator 是默认的全局传播器，遵循 W3C Trace Context 标准。

            调用 Inject(carrier, current_ctx) 方法，将当前上下文中的追踪信息写入到 Carrier（即 headers）中。
            Inject() 的工作原理：
            将当前上下文中的 Trace ID、Span ID 和其他元信息转换为键值对。
            按照 W3C 标准格式（例如 traceparent 和 tracestate）写入到 Carrier。
         */
        if ( !span->GetContext().IsValid())
        {
            std::cout << "Current context does not have a valid span." << std::endl;
        }
        else
        {
            std::cout << "Span context is valid. Injecting headers..." << std::endl;
            propagation::GlobalTextMapPropagator::GetGlobalPropagator()->Inject(carrier, current_ctx);
        }

        std::cout << "Injected Headers:" << std::endl;
        if (headers.empty())
        {
            std::cout << "Headers are empty!" << std::endl;
        }
        for (const auto &header : headers)
        {
            std::cout << header.first << ": " << header.second << std::endl;
        }

        // 这里可以通过 IPC、HTTP 请求等方式传递 headers
        // 将注入的 headers 发送给 ProcessB
        SendToProcessB(headers);
    }

}  // namespace


int main(int argc, char *argv[])
{
    std::string urlString = "http://localhost:4318/v1/traces";  //Jeajer UI
    opts.url = urlString;
    std::cout << "urlString:" << urlString << std::endl;

    InitTracer();

    ProcessA();

    CleanupTracer();

    std::cout << "end" << std::endl;
}
