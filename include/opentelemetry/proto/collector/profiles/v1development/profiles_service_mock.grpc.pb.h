// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: opentelemetry/proto/collector/profiles/v1development/profiles_service.proto

#ifndef GRPC_MOCK_opentelemetry_2fproto_2fcollector_2fprofiles_2fv1development_2fprofiles_5fservice_2eproto__INCLUDED
#define GRPC_MOCK_opentelemetry_2fproto_2fcollector_2fprofiles_2fv1development_2fprofiles_5fservice_2eproto__INCLUDED

#include "opentelemetry/proto/collector/profiles/v1development/profiles_service.pb.h"
#include "opentelemetry/proto/collector/profiles/v1development/profiles_service.grpc.pb.h"

#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/sync_stream.h>
#include <gmock/gmock.h>
namespace opentelemetry {
namespace proto {
namespace collector {
namespace profiles {
namespace v1development {

class MockProfilesServiceStub : public ProfilesService::StubInterface {
 public:
  MOCK_METHOD3(Export, ::grpc::Status(::grpc::ClientContext* context, const ::opentelemetry::proto::collector::profiles::v1development::ExportProfilesServiceRequest& request, ::opentelemetry::proto::collector::profiles::v1development::ExportProfilesServiceResponse* response));
  MOCK_METHOD3(AsyncExportRaw, ::grpc::ClientAsyncResponseReaderInterface< ::opentelemetry::proto::collector::profiles::v1development::ExportProfilesServiceResponse>*(::grpc::ClientContext* context, const ::opentelemetry::proto::collector::profiles::v1development::ExportProfilesServiceRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncExportRaw, ::grpc::ClientAsyncResponseReaderInterface< ::opentelemetry::proto::collector::profiles::v1development::ExportProfilesServiceResponse>*(::grpc::ClientContext* context, const ::opentelemetry::proto::collector::profiles::v1development::ExportProfilesServiceRequest& request, ::grpc::CompletionQueue* cq));
};

}  // namespace v1development
}  // namespace profiles
}  // namespace collector
}  // namespace proto
}  // namespace opentelemetry


#endif  // GRPC_MOCK_opentelemetry_2fproto_2fcollector_2fprofiles_2fv1development_2fprofiles_5fservice_2eproto__INCLUDED