// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: opentelemetry/proto/resource/v1/resource.proto
// Protobuf C++ Version: 5.26.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_opentelemetry_2fproto_2fresource_2fv1_2fresource_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_opentelemetry_2fproto_2fresource_2fv1_2fresource_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION != 5026001
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
#include "opentelemetry/proto/common/v1/common.pb.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_opentelemetry_2fproto_2fresource_2fv1_2fresource_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_opentelemetry_2fproto_2fresource_2fv1_2fresource_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_opentelemetry_2fproto_2fresource_2fv1_2fresource_2eproto;
namespace opentelemetry {
namespace proto {
namespace resource {
namespace v1 {
class Resource;
struct ResourceDefaultTypeInternal;
extern ResourceDefaultTypeInternal _Resource_default_instance_;
}  // namespace v1
}  // namespace resource
}  // namespace proto
}  // namespace opentelemetry
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace opentelemetry {
namespace proto {
namespace resource {
namespace v1 {

// ===================================================================


// -------------------------------------------------------------------

class Resource final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:opentelemetry.proto.resource.v1.Resource) */ {
 public:
  inline Resource() : Resource(nullptr) {}
  ~Resource() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR Resource(
      ::google::protobuf::internal::ConstantInitialized);

  inline Resource(const Resource& from) : Resource(nullptr, from) {}
  inline Resource(Resource&& from) noexcept
      : Resource(nullptr, std::move(from)) {}
  inline Resource& operator=(const Resource& from) {
    CopyFrom(from);
    return *this;
  }
  inline Resource& operator=(Resource&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Resource& default_instance() {
    return *internal_default_instance();
  }
  static inline const Resource* internal_default_instance() {
    return reinterpret_cast<const Resource*>(
        &_Resource_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(Resource& a, Resource& b) { a.Swap(&b); }
  inline void Swap(Resource* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Resource* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Resource* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<Resource>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Resource& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const Resource& from) { Resource::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(Resource* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "opentelemetry.proto.resource.v1.Resource"; }

 protected:
  explicit Resource(::google::protobuf::Arena* arena);
  Resource(::google::protobuf::Arena* arena, const Resource& from);
  Resource(::google::protobuf::Arena* arena, Resource&& from) noexcept
      : Resource(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kAttributesFieldNumber = 1,
    kDroppedAttributesCountFieldNumber = 2,
  };
  // repeated .opentelemetry.proto.common.v1.KeyValue attributes = 1;
  int attributes_size() const;
  private:
  int _internal_attributes_size() const;

  public:
  void clear_attributes() ;
  ::opentelemetry::proto::common::v1::KeyValue* mutable_attributes(int index);
  ::google::protobuf::RepeatedPtrField<::opentelemetry::proto::common::v1::KeyValue>* mutable_attributes();

  private:
  const ::google::protobuf::RepeatedPtrField<::opentelemetry::proto::common::v1::KeyValue>& _internal_attributes() const;
  ::google::protobuf::RepeatedPtrField<::opentelemetry::proto::common::v1::KeyValue>* _internal_mutable_attributes();
  public:
  const ::opentelemetry::proto::common::v1::KeyValue& attributes(int index) const;
  ::opentelemetry::proto::common::v1::KeyValue* add_attributes();
  const ::google::protobuf::RepeatedPtrField<::opentelemetry::proto::common::v1::KeyValue>& attributes() const;
  // uint32 dropped_attributes_count = 2;
  void clear_dropped_attributes_count() ;
  ::uint32_t dropped_attributes_count() const;
  void set_dropped_attributes_count(::uint32_t value);

  private:
  ::uint32_t _internal_dropped_attributes_count() const;
  void _internal_set_dropped_attributes_count(::uint32_t value);

  public:
  // @@protoc_insertion_point(class_scope:opentelemetry.proto.resource.v1.Resource)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      1, 2, 1,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::RepeatedPtrField< ::opentelemetry::proto::common::v1::KeyValue > attributes_;
    ::uint32_t dropped_attributes_count_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_opentelemetry_2fproto_2fresource_2fv1_2fresource_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Resource

// repeated .opentelemetry.proto.common.v1.KeyValue attributes = 1;
inline int Resource::_internal_attributes_size() const {
  return _internal_attributes().size();
}
inline int Resource::attributes_size() const {
  return _internal_attributes_size();
}
inline ::opentelemetry::proto::common::v1::KeyValue* Resource::mutable_attributes(int index)
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable:opentelemetry.proto.resource.v1.Resource.attributes)
  return _internal_mutable_attributes()->Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField<::opentelemetry::proto::common::v1::KeyValue>* Resource::mutable_attributes()
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable_list:opentelemetry.proto.resource.v1.Resource.attributes)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _internal_mutable_attributes();
}
inline const ::opentelemetry::proto::common::v1::KeyValue& Resource::attributes(int index) const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:opentelemetry.proto.resource.v1.Resource.attributes)
  return _internal_attributes().Get(index);
}
inline ::opentelemetry::proto::common::v1::KeyValue* Resource::add_attributes() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::opentelemetry::proto::common::v1::KeyValue* _add = _internal_mutable_attributes()->Add();
  // @@protoc_insertion_point(field_add:opentelemetry.proto.resource.v1.Resource.attributes)
  return _add;
}
inline const ::google::protobuf::RepeatedPtrField<::opentelemetry::proto::common::v1::KeyValue>& Resource::attributes() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_list:opentelemetry.proto.resource.v1.Resource.attributes)
  return _internal_attributes();
}
inline const ::google::protobuf::RepeatedPtrField<::opentelemetry::proto::common::v1::KeyValue>&
Resource::_internal_attributes() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.attributes_;
}
inline ::google::protobuf::RepeatedPtrField<::opentelemetry::proto::common::v1::KeyValue>*
Resource::_internal_mutable_attributes() {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return &_impl_.attributes_;
}

// uint32 dropped_attributes_count = 2;
inline void Resource::clear_dropped_attributes_count() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.dropped_attributes_count_ = 0u;
}
inline ::uint32_t Resource::dropped_attributes_count() const {
  // @@protoc_insertion_point(field_get:opentelemetry.proto.resource.v1.Resource.dropped_attributes_count)
  return _internal_dropped_attributes_count();
}
inline void Resource::set_dropped_attributes_count(::uint32_t value) {
  _internal_set_dropped_attributes_count(value);
  // @@protoc_insertion_point(field_set:opentelemetry.proto.resource.v1.Resource.dropped_attributes_count)
}
inline ::uint32_t Resource::_internal_dropped_attributes_count() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.dropped_attributes_count_;
}
inline void Resource::_internal_set_dropped_attributes_count(::uint32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.dropped_attributes_count_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace v1
}  // namespace resource
}  // namespace proto
}  // namespace opentelemetry


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_opentelemetry_2fproto_2fresource_2fv1_2fresource_2eproto_2epb_2eh
