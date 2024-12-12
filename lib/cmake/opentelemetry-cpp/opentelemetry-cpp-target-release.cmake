#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "opentelemetry-cpp::proto" for configuration "Release"
set_property(TARGET opentelemetry-cpp::proto APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::proto PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_proto.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::proto )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::proto "${_IMPORT_PREFIX}/lib/opentelemetry_proto.lib" )

# Import target "opentelemetry-cpp::proto_grpc" for configuration "Release"
set_property(TARGET opentelemetry-cpp::proto_grpc APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::proto_grpc PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_proto_grpc.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::proto_grpc )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::proto_grpc "${_IMPORT_PREFIX}/lib/opentelemetry_proto_grpc.lib" )

# Import target "opentelemetry-cpp::common" for configuration "Release"
set_property(TARGET opentelemetry-cpp::common APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::common PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_common.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::common )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::common "${_IMPORT_PREFIX}/lib/opentelemetry_common.lib" )

# Import target "opentelemetry-cpp::trace" for configuration "Release"
set_property(TARGET opentelemetry-cpp::trace APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::trace PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_trace.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::trace )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::trace "${_IMPORT_PREFIX}/lib/opentelemetry_trace.lib" )

# Import target "opentelemetry-cpp::metrics" for configuration "Release"
set_property(TARGET opentelemetry-cpp::metrics APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::metrics PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_metrics.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::metrics )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::metrics "${_IMPORT_PREFIX}/lib/opentelemetry_metrics.lib" )

# Import target "opentelemetry-cpp::logs" for configuration "Release"
set_property(TARGET opentelemetry-cpp::logs APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::logs PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_logs.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::logs )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::logs "${_IMPORT_PREFIX}/lib/opentelemetry_logs.lib" )

# Import target "opentelemetry-cpp::version" for configuration "Release"
set_property(TARGET opentelemetry-cpp::version APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::version PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_version.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::version )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::version "${_IMPORT_PREFIX}/lib/opentelemetry_version.lib" )

# Import target "opentelemetry-cpp::resources" for configuration "Release"
set_property(TARGET opentelemetry-cpp::resources APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::resources PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_resources.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::resources )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::resources "${_IMPORT_PREFIX}/lib/opentelemetry_resources.lib" )

# Import target "opentelemetry-cpp::http_client_curl" for configuration "Release"
set_property(TARGET opentelemetry-cpp::http_client_curl APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::http_client_curl PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_http_client_curl.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::http_client_curl )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::http_client_curl "${_IMPORT_PREFIX}/lib/opentelemetry_http_client_curl.lib" )

# Import target "opentelemetry-cpp::opentelemetry_cpp" for configuration "Release"
set_property(TARGET opentelemetry-cpp::opentelemetry_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::opentelemetry_cpp PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_cpp.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/opentelemetry_cpp.dll"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::opentelemetry_cpp )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::opentelemetry_cpp "${_IMPORT_PREFIX}/lib/opentelemetry_cpp.lib" "${_IMPORT_PREFIX}/bin/opentelemetry_cpp.dll" )

# Import target "opentelemetry-cpp::otlp_recordable" for configuration "Release"
set_property(TARGET opentelemetry-cpp::otlp_recordable APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::otlp_recordable PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_otlp_recordable.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::otlp_recordable )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::otlp_recordable "${_IMPORT_PREFIX}/lib/opentelemetry_otlp_recordable.lib" )

# Import target "opentelemetry-cpp::otlp_grpc_client" for configuration "Release"
set_property(TARGET opentelemetry-cpp::otlp_grpc_client APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::otlp_grpc_client PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_otlp_grpc_client.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::otlp_grpc_client )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::otlp_grpc_client "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_otlp_grpc_client.lib" )

# Import target "opentelemetry-cpp::otlp_grpc_exporter" for configuration "Release"
set_property(TARGET opentelemetry-cpp::otlp_grpc_exporter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::otlp_grpc_exporter PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_otlp_grpc.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::otlp_grpc_exporter )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::otlp_grpc_exporter "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_otlp_grpc.lib" )

# Import target "opentelemetry-cpp::otlp_grpc_log_record_exporter" for configuration "Release"
set_property(TARGET opentelemetry-cpp::otlp_grpc_log_record_exporter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::otlp_grpc_log_record_exporter PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_otlp_grpc_log.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::otlp_grpc_log_record_exporter )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::otlp_grpc_log_record_exporter "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_otlp_grpc_log.lib" )

# Import target "opentelemetry-cpp::otlp_grpc_metrics_exporter" for configuration "Release"
set_property(TARGET opentelemetry-cpp::otlp_grpc_metrics_exporter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::otlp_grpc_metrics_exporter PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_otlp_grpc_metrics.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::otlp_grpc_metrics_exporter )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::otlp_grpc_metrics_exporter "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_otlp_grpc_metrics.lib" )

# Import target "opentelemetry-cpp::otlp_http_client" for configuration "Release"
set_property(TARGET opentelemetry-cpp::otlp_http_client APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::otlp_http_client PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_otlp_http_client.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::otlp_http_client )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::otlp_http_client "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_otlp_http_client.lib" )

# Import target "opentelemetry-cpp::otlp_http_exporter" for configuration "Release"
set_property(TARGET opentelemetry-cpp::otlp_http_exporter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::otlp_http_exporter PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_otlp_http.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::otlp_http_exporter )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::otlp_http_exporter "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_otlp_http.lib" )

# Import target "opentelemetry-cpp::otlp_http_log_record_exporter" for configuration "Release"
set_property(TARGET opentelemetry-cpp::otlp_http_log_record_exporter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::otlp_http_log_record_exporter PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_otlp_http_log.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::otlp_http_log_record_exporter )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::otlp_http_log_record_exporter "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_otlp_http_log.lib" )

# Import target "opentelemetry-cpp::otlp_http_metric_exporter" for configuration "Release"
set_property(TARGET opentelemetry-cpp::otlp_http_metric_exporter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::otlp_http_metric_exporter PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_otlp_http_metric.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::otlp_http_metric_exporter )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::otlp_http_metric_exporter "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_otlp_http_metric.lib" )

# Import target "opentelemetry-cpp::ostream_span_exporter" for configuration "Release"
set_property(TARGET opentelemetry-cpp::ostream_span_exporter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::ostream_span_exporter PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_ostream_span.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::ostream_span_exporter )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::ostream_span_exporter "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_ostream_span.lib" )

# Import target "opentelemetry-cpp::ostream_metrics_exporter" for configuration "Release"
set_property(TARGET opentelemetry-cpp::ostream_metrics_exporter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::ostream_metrics_exporter PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_ostream_metrics.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::ostream_metrics_exporter )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::ostream_metrics_exporter "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_ostream_metrics.lib" )

# Import target "opentelemetry-cpp::ostream_log_record_exporter" for configuration "Release"
set_property(TARGET opentelemetry-cpp::ostream_log_record_exporter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::ostream_log_record_exporter PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_ostream_logs.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::ostream_log_record_exporter )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::ostream_log_record_exporter "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_ostream_logs.lib" )

# Import target "opentelemetry-cpp::in_memory_span_exporter" for configuration "Release"
set_property(TARGET opentelemetry-cpp::in_memory_span_exporter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::in_memory_span_exporter PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_in_memory.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::in_memory_span_exporter )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::in_memory_span_exporter "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_in_memory.lib" )

# Import target "opentelemetry-cpp::in_memory_metric_exporter" for configuration "Release"
set_property(TARGET opentelemetry-cpp::in_memory_metric_exporter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(opentelemetry-cpp::in_memory_metric_exporter PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_in_memory_metric.lib"
  )

list(APPEND _cmake_import_check_targets opentelemetry-cpp::in_memory_metric_exporter )
list(APPEND _cmake_import_check_files_for_opentelemetry-cpp::in_memory_metric_exporter "${_IMPORT_PREFIX}/lib/opentelemetry_exporter_in_memory_metric.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
