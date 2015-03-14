// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: request.proto

#ifndef PROTOBUF_request_2eproto__INCLUDED
#define PROTOBUF_request_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "req_register.pb.h"
#include "req_statistic.pb.h"
// @@protoc_insertion_point(includes)

namespace protocol {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_request_2eproto();
void protobuf_AssignDesc_request_2eproto();
void protobuf_ShutdownFile_request_2eproto();

class meta_request;

enum meta_request_Type {
  meta_request_Type_REGISTER = 0
};
bool meta_request_Type_IsValid(int value);
const meta_request_Type meta_request_Type_Type_MIN = meta_request_Type_REGISTER;
const meta_request_Type meta_request_Type_Type_MAX = meta_request_Type_REGISTER;
const int meta_request_Type_Type_ARRAYSIZE = meta_request_Type_Type_MAX + 1;

const ::google_public::protobuf::EnumDescriptor* meta_request_Type_descriptor();
inline const ::std::string& meta_request_Type_Name(meta_request_Type value) {
  return ::google_public::protobuf::internal::NameOfEnum(
    meta_request_Type_descriptor(), value);
}
inline bool meta_request_Type_Parse(
    const ::std::string& name, meta_request_Type* value) {
  return ::google_public::protobuf::internal::ParseNamedEnum<meta_request_Type>(
    meta_request_Type_descriptor(), name, value);
}
// ===================================================================

class meta_request : public ::google_public::protobuf::Message {
 public:
  meta_request();
  virtual ~meta_request();

  meta_request(const meta_request& from);

  inline meta_request& operator=(const meta_request& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google_public::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google_public::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google_public::protobuf::Descriptor* descriptor();
  static const meta_request& default_instance();

  void Swap(meta_request* other);

  // implements Message ----------------------------------------------

  meta_request* New() const;
  void CopyFrom(const ::google_public::protobuf::Message& from);
  void MergeFrom(const ::google_public::protobuf::Message& from);
  void CopyFrom(const meta_request& from);
  void MergeFrom(const meta_request& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google_public::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google_public::protobuf::io::CodedOutputStream* output) const;
  ::google_public::protobuf::uint8* SerializeWithCachedSizesToArray(::google_public::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google_public::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef meta_request_Type Type;
  static const Type REGISTER = meta_request_Type_REGISTER;
  static inline bool Type_IsValid(int value) {
    return meta_request_Type_IsValid(value);
  }
  static const Type Type_MIN =
    meta_request_Type_Type_MIN;
  static const Type Type_MAX =
    meta_request_Type_Type_MAX;
  static const int Type_ARRAYSIZE =
    meta_request_Type_Type_ARRAYSIZE;
  static inline const ::google_public::protobuf::EnumDescriptor*
  Type_descriptor() {
    return meta_request_Type_descriptor();
  }
  static inline const ::std::string& Type_Name(Type value) {
    return meta_request_Type_Name(value);
  }
  static inline bool Type_Parse(const ::std::string& name,
      Type* value) {
    return meta_request_Type_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // required string uin = 1;
  inline bool has_uin() const;
  inline void clear_uin();
  static const int kUinFieldNumber = 1;
  inline const ::std::string& uin() const;
  inline void set_uin(const ::std::string& value);
  inline void set_uin(const char* value);
  inline void set_uin(const char* value, size_t size);
  inline ::std::string* mutable_uin();
  inline ::std::string* release_uin();
  inline void set_allocated_uin(::std::string* uin);

  // required .protocol.meta_request.Type type = 2;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 2;
  inline ::protocol::meta_request_Type type() const;
  inline void set_type(::protocol::meta_request_Type value);

  // optional .protocol.req_register registerInfo = 3;
  inline bool has_registerinfo() const;
  inline void clear_registerinfo();
  static const int kRegisterInfoFieldNumber = 3;
  inline const ::protocol::req_register& registerinfo() const;
  inline ::protocol::req_register* mutable_registerinfo();
  inline ::protocol::req_register* release_registerinfo();
  inline void set_allocated_registerinfo(::protocol::req_register* registerinfo);

  // optional .protocol.req_statistic statisticInfo = 4;
  inline bool has_statisticinfo() const;
  inline void clear_statisticinfo();
  static const int kStatisticInfoFieldNumber = 4;
  inline const ::protocol::req_statistic& statisticinfo() const;
  inline ::protocol::req_statistic* mutable_statisticinfo();
  inline ::protocol::req_statistic* release_statisticinfo();
  inline void set_allocated_statisticinfo(::protocol::req_statistic* statisticinfo);

  // @@protoc_insertion_point(class_scope:protocol.meta_request)
 private:
  inline void set_has_uin();
  inline void clear_has_uin();
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_registerinfo();
  inline void clear_has_registerinfo();
  inline void set_has_statisticinfo();
  inline void clear_has_statisticinfo();

  ::google_public::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* uin_;
  ::protocol::req_register* registerinfo_;
  ::protocol::req_statistic* statisticinfo_;
  int type_;

  mutable int _cached_size_;
  ::google_public::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_request_2eproto();
  friend void protobuf_AssignDesc_request_2eproto();
  friend void protobuf_ShutdownFile_request_2eproto();

  void InitAsDefaultInstance();
  static meta_request* default_instance_;
};
// ===================================================================


// ===================================================================

// meta_request

// required string uin = 1;
inline bool meta_request::has_uin() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void meta_request::set_has_uin() {
  _has_bits_[0] |= 0x00000001u;
}
inline void meta_request::clear_has_uin() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void meta_request::clear_uin() {
  if (uin_ != &::google_public::protobuf::internal::kEmptyString) {
    uin_->clear();
  }
  clear_has_uin();
}
inline const ::std::string& meta_request::uin() const {
  return *uin_;
}
inline void meta_request::set_uin(const ::std::string& value) {
  set_has_uin();
  if (uin_ == &::google_public::protobuf::internal::kEmptyString) {
    uin_ = new ::std::string;
  }
  uin_->assign(value);
}
inline void meta_request::set_uin(const char* value) {
  set_has_uin();
  if (uin_ == &::google_public::protobuf::internal::kEmptyString) {
    uin_ = new ::std::string;
  }
  uin_->assign(value);
}
inline void meta_request::set_uin(const char* value, size_t size) {
  set_has_uin();
  if (uin_ == &::google_public::protobuf::internal::kEmptyString) {
    uin_ = new ::std::string;
  }
  uin_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* meta_request::mutable_uin() {
  set_has_uin();
  if (uin_ == &::google_public::protobuf::internal::kEmptyString) {
    uin_ = new ::std::string;
  }
  return uin_;
}
inline ::std::string* meta_request::release_uin() {
  clear_has_uin();
  if (uin_ == &::google_public::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = uin_;
    uin_ = const_cast< ::std::string*>(&::google_public::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void meta_request::set_allocated_uin(::std::string* uin) {
  if (uin_ != &::google_public::protobuf::internal::kEmptyString) {
    delete uin_;
  }
  if (uin) {
    set_has_uin();
    uin_ = uin;
  } else {
    clear_has_uin();
    uin_ = const_cast< ::std::string*>(&::google_public::protobuf::internal::kEmptyString);
  }
}

// required .protocol.meta_request.Type type = 2;
inline bool meta_request::has_type() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void meta_request::set_has_type() {
  _has_bits_[0] |= 0x00000002u;
}
inline void meta_request::clear_has_type() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void meta_request::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::protocol::meta_request_Type meta_request::type() const {
  return static_cast< ::protocol::meta_request_Type >(type_);
}
inline void meta_request::set_type(::protocol::meta_request_Type value) {
  assert(::protocol::meta_request_Type_IsValid(value));
  set_has_type();
  type_ = value;
}

// optional .protocol.req_register registerInfo = 3;
inline bool meta_request::has_registerinfo() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void meta_request::set_has_registerinfo() {
  _has_bits_[0] |= 0x00000004u;
}
inline void meta_request::clear_has_registerinfo() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void meta_request::clear_registerinfo() {
  if (registerinfo_ != NULL) registerinfo_->::protocol::req_register::Clear();
  clear_has_registerinfo();
}
inline const ::protocol::req_register& meta_request::registerinfo() const {
  return registerinfo_ != NULL ? *registerinfo_ : *default_instance_->registerinfo_;
}
inline ::protocol::req_register* meta_request::mutable_registerinfo() {
  set_has_registerinfo();
  if (registerinfo_ == NULL) registerinfo_ = new ::protocol::req_register;
  return registerinfo_;
}
inline ::protocol::req_register* meta_request::release_registerinfo() {
  clear_has_registerinfo();
  ::protocol::req_register* temp = registerinfo_;
  registerinfo_ = NULL;
  return temp;
}
inline void meta_request::set_allocated_registerinfo(::protocol::req_register* registerinfo) {
  delete registerinfo_;
  registerinfo_ = registerinfo;
  if (registerinfo) {
    set_has_registerinfo();
  } else {
    clear_has_registerinfo();
  }
}

// optional .protocol.req_statistic statisticInfo = 4;
inline bool meta_request::has_statisticinfo() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void meta_request::set_has_statisticinfo() {
  _has_bits_[0] |= 0x00000008u;
}
inline void meta_request::clear_has_statisticinfo() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void meta_request::clear_statisticinfo() {
  if (statisticinfo_ != NULL) statisticinfo_->::protocol::req_statistic::Clear();
  clear_has_statisticinfo();
}
inline const ::protocol::req_statistic& meta_request::statisticinfo() const {
  return statisticinfo_ != NULL ? *statisticinfo_ : *default_instance_->statisticinfo_;
}
inline ::protocol::req_statistic* meta_request::mutable_statisticinfo() {
  set_has_statisticinfo();
  if (statisticinfo_ == NULL) statisticinfo_ = new ::protocol::req_statistic;
  return statisticinfo_;
}
inline ::protocol::req_statistic* meta_request::release_statisticinfo() {
  clear_has_statisticinfo();
  ::protocol::req_statistic* temp = statisticinfo_;
  statisticinfo_ = NULL;
  return temp;
}
inline void meta_request::set_allocated_statisticinfo(::protocol::req_statistic* statisticinfo) {
  delete statisticinfo_;
  statisticinfo_ = statisticinfo;
  if (statisticinfo) {
    set_has_statisticinfo();
  } else {
    clear_has_statisticinfo();
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol

#ifndef SWIG
namespace google_public {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::protocol::meta_request_Type>() {
  return ::protocol::meta_request_Type_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_request_2eproto__INCLUDED