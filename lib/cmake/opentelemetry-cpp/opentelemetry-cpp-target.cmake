# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.8)
   message(FATAL_ERROR "CMake >= 3.0.0 required")
endif()
if(CMAKE_VERSION VERSION_LESS "3.0.0")
   message(FATAL_ERROR "CMake >= 3.0.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 3.0.0...3.29)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_cmake_targets_defined "")
set(_cmake_targets_not_defined "")
set(_cmake_expected_targets "")
foreach(_cmake_expected_target IN ITEMS opentelemetry-cpp::proto opentelemetry-cpp::proto_grpc opentelemetry-cpp::api opentelemetry-cpp::sdk opentelemetry-cpp::common opentelemetry-cpp::trace opentelemetry-cpp::metrics opentelemetry-cpp::logs opentelemetry-cpp::version opentelemetry-cpp::resources opentelemetry-cpp::ext opentelemetry-cpp::http_client_curl opentelemetry-cpp::opentelemetry_cpp opentelemetry-cpp::otlp_recordable opentelemetry-cpp::otlp_grpc_client opentelemetry-cpp::otlp_grpc_exporter opentelemetry-cpp::otlp_grpc_log_record_exporter opentelemetry-cpp::otlp_grpc_metrics_exporter opentelemetry-cpp::otlp_http_client opentelemetry-cpp::otlp_http_exporter opentelemetry-cpp::otlp_http_log_record_exporter opentelemetry-cpp::otlp_http_metric_exporter opentelemetry-cpp::ostream_span_exporter opentelemetry-cpp::ostream_metrics_exporter opentelemetry-cpp::ostream_log_record_exporter opentelemetry-cpp::in_memory_span_exporter opentelemetry-cpp::in_memory_metric_exporter opentelemetry-cpp::etw_exporter)
  list(APPEND _cmake_expected_targets "${_cmake_expected_target}")
  if(TARGET "${_cmake_expected_target}")
    list(APPEND _cmake_targets_defined "${_cmake_expected_target}")
  else()
    list(APPEND _cmake_targets_not_defined "${_cmake_expected_target}")
  endif()
endforeach()
unset(_cmake_expected_target)
if(_cmake_targets_defined STREQUAL _cmake_expected_targets)
  unset(_cmake_targets_defined)
  unset(_cmake_targets_not_defined)
  unset(_cmake_expected_targets)
  unset(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT _cmake_targets_defined STREQUAL "")
  string(REPLACE ";" ", " _cmake_targets_defined_text "${_cmake_targets_defined}")
  string(REPLACE ";" ", " _cmake_targets_not_defined_text "${_cmake_targets_not_defined}")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_cmake_targets_defined_text}\nTargets not yet defined: ${_cmake_targets_not_defined_text}\n")
endif()
unset(_cmake_targets_defined)
unset(_cmake_targets_not_defined)
unset(_cmake_expected_targets)


# Compute the installation prefix relative to this file.
get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
if(_IMPORT_PREFIX STREQUAL "/")
  set(_IMPORT_PREFIX "")
endif()

# Create imported target opentelemetry-cpp::proto
add_library(opentelemetry-cpp::proto STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::proto PROPERTIES
  INTERFACE_LINK_LIBRARIES "absl::bad_variant_access;protobuf::libprotobuf"
)

# Create imported target opentelemetry-cpp::proto_grpc
add_library(opentelemetry-cpp::proto_grpc STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::proto_grpc PROPERTIES
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::proto;\$<LINK_ONLY:absl::synchronization>"
)

# Create imported target opentelemetry-cpp::api
add_library(opentelemetry-cpp::api INTERFACE IMPORTED)

set_target_properties(opentelemetry-cpp::api PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "HAVE_ABSEIL;HAVE_MSGPACK;OPENTELEMETRY_ABI_VERSION_NO=1"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "absl::bad_variant_access;absl::any;absl::base;absl::bits;absl::city"
)

# Create imported target opentelemetry-cpp::sdk
add_library(opentelemetry-cpp::sdk INTERFACE IMPORTED)

set_target_properties(opentelemetry-cpp::sdk PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target opentelemetry-cpp::common
add_library(opentelemetry-cpp::common STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::common PROPERTIES
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::api;opentelemetry-cpp::sdk;Threads::Threads;absl::strings"
)

# Create imported target opentelemetry-cpp::trace
add_library(opentelemetry-cpp::trace STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::trace PROPERTIES
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::common;opentelemetry-cpp::resources"
)

# Create imported target opentelemetry-cpp::metrics
add_library(opentelemetry-cpp::metrics STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::metrics PROPERTIES
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::common;opentelemetry-cpp::resources"
)

# Create imported target opentelemetry-cpp::logs
add_library(opentelemetry-cpp::logs STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::logs PROPERTIES
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::resources;opentelemetry-cpp::common"
)

# Create imported target opentelemetry-cpp::version
add_library(opentelemetry-cpp::version STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::version PROPERTIES
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::api;opentelemetry-cpp::sdk"
)

# Create imported target opentelemetry-cpp::resources
add_library(opentelemetry-cpp::resources STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::resources PROPERTIES
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::common"
)

# Create imported target opentelemetry-cpp::ext
add_library(opentelemetry-cpp::ext INTERFACE IMPORTED)

set_target_properties(opentelemetry-cpp::ext PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::api"
)

# Create imported target opentelemetry-cpp::http_client_curl
add_library(opentelemetry-cpp::http_client_curl STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::http_client_curl PROPERTIES
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::common;opentelemetry-cpp::ext;\$<LINK_ONLY:CURL::libcurl>"
)

# Create imported target opentelemetry-cpp::opentelemetry_cpp
add_library(opentelemetry-cpp::opentelemetry_cpp SHARED IMPORTED)

# Create imported target opentelemetry-cpp::otlp_recordable
add_library(opentelemetry-cpp::otlp_recordable STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::otlp_recordable PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::logs;opentelemetry-cpp::metrics;opentelemetry-cpp::trace;opentelemetry-cpp::resources;opentelemetry-cpp::proto"
)

# Create imported target opentelemetry-cpp::otlp_grpc_client
add_library(opentelemetry-cpp::otlp_grpc_client STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::otlp_grpc_client PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::sdk;opentelemetry-cpp::common;opentelemetry-cpp::ext;opentelemetry-cpp::proto_grpc;\$<LINK_ONLY:gRPC::grpc++>"
)

# Create imported target opentelemetry-cpp::otlp_grpc_exporter
add_library(opentelemetry-cpp::otlp_grpc_exporter STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::otlp_grpc_exporter PROPERTIES
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::otlp_recordable;opentelemetry-cpp::otlp_grpc_client"
)

# Create imported target opentelemetry-cpp::otlp_grpc_log_record_exporter
add_library(opentelemetry-cpp::otlp_grpc_log_record_exporter STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::otlp_grpc_log_record_exporter PROPERTIES
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::otlp_recordable;opentelemetry-cpp::otlp_grpc_client"
)

# Create imported target opentelemetry-cpp::otlp_grpc_metrics_exporter
add_library(opentelemetry-cpp::otlp_grpc_metrics_exporter STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::otlp_grpc_metrics_exporter PROPERTIES
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::otlp_recordable;opentelemetry-cpp::otlp_grpc_client"
)

# Create imported target opentelemetry-cpp::otlp_http_client
add_library(opentelemetry-cpp::otlp_http_client STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::otlp_http_client PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::sdk;opentelemetry-cpp::ext;\$<LINK_ONLY:opentelemetry-cpp::proto>;\$<LINK_ONLY:opentelemetry-cpp::http_client_curl>;\$<LINK_ONLY:nlohmann_json::nlohmann_json>;absl::strings"
)

# Create imported target opentelemetry-cpp::otlp_http_exporter
add_library(opentelemetry-cpp::otlp_http_exporter STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::otlp_http_exporter PROPERTIES
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::otlp_recordable;opentelemetry-cpp::otlp_http_client"
)

# Create imported target opentelemetry-cpp::otlp_http_log_record_exporter
add_library(opentelemetry-cpp::otlp_http_log_record_exporter STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::otlp_http_log_record_exporter PROPERTIES
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::otlp_recordable;opentelemetry-cpp::otlp_http_client"
)

# Create imported target opentelemetry-cpp::otlp_http_metric_exporter
add_library(opentelemetry-cpp::otlp_http_metric_exporter STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::otlp_http_metric_exporter PROPERTIES
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::otlp_recordable;opentelemetry-cpp::otlp_http_client"
)

# Create imported target opentelemetry-cpp::ostream_span_exporter
add_library(opentelemetry-cpp::ostream_span_exporter STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::ostream_span_exporter PROPERTIES
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::trace"
)

# Create imported target opentelemetry-cpp::ostream_metrics_exporter
add_library(opentelemetry-cpp::ostream_metrics_exporter STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::ostream_metrics_exporter PROPERTIES
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::metrics"
)

# Create imported target opentelemetry-cpp::ostream_log_record_exporter
add_library(opentelemetry-cpp::ostream_log_record_exporter STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::ostream_log_record_exporter PROPERTIES
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::logs"
)

# Create imported target opentelemetry-cpp::in_memory_span_exporter
add_library(opentelemetry-cpp::in_memory_span_exporter STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::in_memory_span_exporter PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::trace"
)

# Create imported target opentelemetry-cpp::in_memory_metric_exporter
add_library(opentelemetry-cpp::in_memory_metric_exporter STATIC IMPORTED)

set_target_properties(opentelemetry-cpp::in_memory_metric_exporter PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::metrics"
)

# Create imported target opentelemetry-cpp::etw_exporter
add_library(opentelemetry-cpp::etw_exporter INTERFACE IMPORTED)

set_target_properties(opentelemetry-cpp::etw_exporter PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "opentelemetry-cpp::api;opentelemetry-cpp::trace;nlohmann_json::nlohmann_json;opentelemetry-cpp::logs"
)

# Load information for each installed configuration.
file(GLOB _cmake_config_files "${CMAKE_CURRENT_LIST_DIR}/opentelemetry-cpp-target-*.cmake")
foreach(_cmake_config_file IN LISTS _cmake_config_files)
  include("${_cmake_config_file}")
endforeach()
unset(_cmake_config_file)
unset(_cmake_config_files)

# Cleanup temporary variables.
set(_IMPORT_PREFIX)

# Loop over all imported files and verify that they actually exist
foreach(_cmake_target IN LISTS _cmake_import_check_targets)
  if(CMAKE_VERSION VERSION_LESS "3.28"
      OR NOT DEFINED _cmake_import_check_xcframework_for_${_cmake_target}
      OR NOT IS_DIRECTORY "${_cmake_import_check_xcframework_for_${_cmake_target}}")
    foreach(_cmake_file IN LISTS "_cmake_import_check_files_for_${_cmake_target}")
      if(NOT EXISTS "${_cmake_file}")
        message(FATAL_ERROR "The imported target \"${_cmake_target}\" references the file
   \"${_cmake_file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
      endif()
    endforeach()
  endif()
  unset(_cmake_file)
  unset("_cmake_import_check_files_for_${_cmake_target}")
endforeach()
unset(_cmake_target)
unset(_cmake_import_check_targets)

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
