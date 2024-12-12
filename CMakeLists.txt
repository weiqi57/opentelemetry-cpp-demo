cmake_minimum_required(VERSION 3.20.0)
project(opentelemetry-http-demo)

# 添加项目的 include 目录
include_directories(${CMAKE_SOURCE_DIR}/include)

find_package(opentelemetry-cpp CONFIG REQUIRED)
#find_package(protobuf)
#find_package(gRPC)
find_package(CURL REQUIRED)
find_package(nlohmann_json)

# 定义第一个目标 otel-http-export-demo
add_executable(otel-http-export-demo src/http_exporter.cc)
target_link_libraries(otel-http-export-demo
        opentelemetry-cpp::trace
        opentelemetry-cpp::common
        opentelemetry-cpp::http_client_curl
        opentelemetry-cpp::otlp_http_exporter
        #opentelemetry-cpp::otlp_grpc_exporter
        opentelemetry-cpp::otlp_http_client
        opentelemetry-cpp::otlp_recordable
        opentelemetry-cpp::resources
)

# 定义第二个目标 process-trace-demoA
add_executable(process-trace-demoA src/processTraceA.cc)
target_link_libraries(process-trace-demoA
        opentelemetry-cpp::trace
        opentelemetry-cpp::otlp_http_exporter
        opentelemetry-cpp::resources
)


add_executable(process-trace-demoB
        src/processTraceB.cc)
target_link_libraries(process-trace-demoB
        opentelemetry-cpp::trace
        opentelemetry-cpp::otlp_http_exporter
        opentelemetry-cpp::resources
)



