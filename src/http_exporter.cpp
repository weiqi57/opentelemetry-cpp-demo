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


namespace trace     = opentelemetry::trace;
namespace trace_sdk = opentelemetry::sdk::trace;
namespace otlp      = opentelemetry::exporter::otlp;
namespace internal_log = opentelemetry::sdk::common::internal_log;
namespace resource = opentelemetry::sdk::resource;
namespace nostd = opentelemetry::nostd;

namespace
{
    opentelemetry::exporter::otlp::OtlpHttpExporterOptions opts;
    void InitTracer()
    {
        // 创建 OTLP HTTP 导出器, 负责将追踪数据发送到远程服务器，opts 中的 URL 指定了目标服务地址。
        auto exporter  = otlp::OtlpHttpExporterFactory::Create(opts);
        // 创建简单处理器, 负责接收并处理 Span 数据
        auto processor = trace_sdk::SimpleSpanProcessorFactory::Create(std::move(exporter));

        // 设置资源属性, 定义了追踪数据的元信息
        resource::ResourceAttributes attributes = {
                {resource::SemanticConventions::kServiceName, "otlp-http-demo"},   // 自定义应用名
                {resource::SemanticConventions::kHostName, "v7-virtual-machine"}   // hostName
        };
        // 创建资源
        auto resource = opentelemetry::sdk::resource::Resource::Create(attributes);

        // 创建追踪提供者, 负责管理追踪器和上下文
        std::shared_ptr<opentelemetry::trace::TracerProvider> provider =
                trace_sdk::TracerProviderFactory::Create(std::move(processor), std::move(resource));
        // 设置全局追踪提供者
        trace::Provider::SetTracerProvider(provider);
    }

    void CleanupTracer()
    {
        std::shared_ptr<opentelemetry::trace::TracerProvider> none;
        trace::Provider::SetTracerProvider(none);
    }

    nostd::shared_ptr<trace::Tracer> get_tracer()
    {
        auto provider = trace::Provider::GetTracerProvider();
        return provider->GetTracer("library name to trace", OPENTELEMETRY_SDK_VERSION);
    }

    void f1()
    {
        // 创建一个新的Span，记录f1函数调用
        auto scoped_span = trace::Scope(get_tracer()->StartSpan("f1"));
    }

    void f2()
    {
        // 创建一个子Span，记录整个f2函数的调用
        auto scoped_span = trace::Scope(get_tracer()->StartSpan("f2"));

        f1();
        f1();
    }

    void foo_library()
    {
        // 创建顶层 Span, 记录 foo_library的运行实际
        auto scoped_span = trace::Scope(get_tracer()->StartSpan("library"));
        // 用 trace::Scope 包裹后，Span 会在作用域结束时自动结束

        f2();

        // 记录了什么:
        // 1, foo_library 的调用开始时间。
        // 2. 函数运行的持续时间。
        // 3. f2 函数调用期间，foo_library 的上下文作为 f2 的父 Span。


        // 每次调用 StartSpan 时都会创建一个新的 Span，记录当前操作的起点。
        // 调用 trace::Scope 会将 Span 自动与当前线程的上下文绑定
        // 使用 trace::Scope 时，Span 的生命周期由作用域控制。
        // 作用域结束时（}），Span 自动结束，记录操作的结束时间，并发送给追踪处理器。
        // 每个子 Span 都会继承父 Span 的上下文，形成调用链。
    }
}  // namespace

/*
  Usage:
  - example_otlp_http
  - example_otlp_http <URL>
  - example_otlp_http <URL> <DEBUG>
  - example_otlp_http <URL> <DEBUG> <BIN>
  <DEBUG> = yes|no, to turn console debug on or off
  <BIN> = bin, to export in binary format
*/
int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        opts.url = argv[1];
        if (argc > 2)
        {
            std::string debug  = argv[2];
            opts.console_debug = debug != "" && debug != "0" && debug != "no";
        }

        if (argc > 3)
        {
            std::string binary_mode = argv[3];
            if (binary_mode.size() >= 3 && binary_mode.substr(0, 3) == "bin")
            {
                opts.content_type = otlp::HttpRequestContentType::kBinary;
            }
        }
    }

    if (opts.console_debug)
    {
        internal_log::GlobalLogHandler::SetLogLevel(internal_log::LogLevel::Debug);
    }

    InitTracer();

    foo_library();

    CleanupTracer();
}
