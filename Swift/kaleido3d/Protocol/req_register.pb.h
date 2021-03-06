// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: req_register.proto

#ifndef PROTOBUF_req_5fregister_2eproto__INCLUDED
#define PROTOBUF_req_5fregister_2eproto__INCLUDED

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
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protocol {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_req_5fregister_2eproto();
void protobuf_AssignDesc_req_5fregister_2eproto();
void protobuf_ShutdownFile_req_5fregister_2eproto();

class req_register;

// ===================================================================

class req_register : public ::google_public::protobuf::Message {
 public:
  req_register();
  virtual ~req_register();

  req_register(const req_register& from);

  inline req_register& operator=(const req_register& from) {
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
  static const req_register& default_instance();

  void Swap(req_register* other);

  // implements Message ----------------------------------------------

  req_register* New() const;
  void CopyFrom(const ::google_public::protobuf::Message& from);
  void MergeFrom(const ::google_public::protobuf::Message& from);
  void CopyFrom(const req_register& from);
  void MergeFrom(const req_register& from);
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

  // accessors -------------------------------------------------------

  // required string username = 1;
  inline bool has_username() const;
  inline void clear_username();
  static const int kUsernameFieldNumber = 1;
  inline const ::std::string& username() const;
  inline void set_username(const ::std::string& value);
  inline void set_username(const char* value);
  inline void set_username(const char* value, size_t size);
  inline ::std::string* mutable_username();
  inline ::std::string* release_username();
  inline void set_allocated_username(::std::string* username);

  // required string password = 2;
  inline bool has_password() const;
  inline void clear_password();
  static const int kPasswordFieldNumber = 2;
  inline const ::std::string& password() const;
  inline void set_password(const ::std::string& value);
  inline void set_password(const char* value);
  inline void set_password(const char* value, size_t size);
  inline ::std::string* mutable_password();
  inline ::std::string* release_password();
  inline void set_allocated_password(::std::string* password);

  // required string email = 3;
  inline bool has_email() const;
  inline void clear_email();
  static const int kEmailFieldNumber = 3;
  inline const ::std::string& email() const;
  inline void set_email(const ::std::string& value);
  inline void set_email(const char* value);
  inline void set_email(const char* value, size_t size);
  inline ::std::string* mutable_email();
  inline ::std::string* release_email();
  inline void set_allocated_email(::std::string* email);

  // optional int32 sex = 4;
  inline bool has_sex() const;
  inline void clear_sex();
  static const int kSexFieldNumber = 4;
  inline ::google_public::protobuf::int32 sex() const;
  inline void set_sex(::google_public::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:protocol.req_register)
 private:
  inline void set_has_username();
  inline void clear_has_username();
  inline void set_has_password();
  inline void clear_has_password();
  inline void set_has_email();
  inline void clear_has_email();
  inline void set_has_sex();
  inline void clear_has_sex();

  ::google_public::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* username_;
  ::std::string* password_;
  ::std::string* email_;
  ::google_public::protobuf::int32 sex_;

  mutable int _cached_size_;
  ::google_public::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_req_5fregister_2eproto();
  friend void protobuf_AssignDesc_req_5fregister_2eproto();
  friend void protobuf_ShutdownFile_req_5fregister_2eproto();

  void InitAsDefaultInstance();
  static req_register* default_instance_;
};
// ===================================================================


// ===================================================================

// req_register

// required string username = 1;
inline bool req_register::has_username() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void req_register::set_has_username() {
  _has_bits_[0] |= 0x00000001u;
}
inline void req_register::clear_has_username() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void req_register::clear_username() {
  if (username_ != &::google_public::protobuf::internal::kEmptyString) {
    username_->clear();
  }
  clear_has_username();
}
inline const ::std::string& req_register::username() const {
  return *username_;
}
inline void req_register::set_username(const ::std::string& value) {
  set_has_username();
  if (username_ == &::google_public::protobuf::internal::kEmptyString) {
    username_ = new ::std::string;
  }
  username_->assign(value);
}
inline void req_register::set_username(const char* value) {
  set_has_username();
  if (username_ == &::google_public::protobuf::internal::kEmptyString) {
    username_ = new ::std::string;
  }
  username_->assign(value);
}
inline void req_register::set_username(const char* value, size_t size) {
  set_has_username();
  if (username_ == &::google_public::protobuf::internal::kEmptyString) {
    username_ = new ::std::string;
  }
  username_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* req_register::mutable_username() {
  set_has_username();
  if (username_ == &::google_public::protobuf::internal::kEmptyString) {
    username_ = new ::std::string;
  }
  return username_;
}
inline ::std::string* req_register::release_username() {
  clear_has_username();
  if (username_ == &::google_public::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = username_;
    username_ = const_cast< ::std::string*>(&::google_public::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void req_register::set_allocated_username(::std::string* username) {
  if (username_ != &::google_public::protobuf::internal::kEmptyString) {
    delete username_;
  }
  if (username) {
    set_has_username();
    username_ = username;
  } else {
    clear_has_username();
    username_ = const_cast< ::std::string*>(&::google_public::protobuf::internal::kEmptyString);
  }
}

// required string password = 2;
inline bool req_register::has_password() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void req_register::set_has_password() {
  _has_bits_[0] |= 0x00000002u;
}
inline void req_register::clear_has_password() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void req_register::clear_password() {
  if (password_ != &::google_public::protobuf::internal::kEmptyString) {
    password_->clear();
  }
  clear_has_password();
}
inline const ::std::string& req_register::password() const {
  return *password_;
}
inline void req_register::set_password(const ::std::string& value) {
  set_has_password();
  if (password_ == &::google_public::protobuf::internal::kEmptyString) {
    password_ = new ::std::string;
  }
  password_->assign(value);
}
inline void req_register::set_password(const char* value) {
  set_has_password();
  if (password_ == &::google_public::protobuf::internal::kEmptyString) {
    password_ = new ::std::string;
  }
  password_->assign(value);
}
inline void req_register::set_password(const char* value, size_t size) {
  set_has_password();
  if (password_ == &::google_public::protobuf::internal::kEmptyString) {
    password_ = new ::std::string;
  }
  password_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* req_register::mutable_password() {
  set_has_password();
  if (password_ == &::google_public::protobuf::internal::kEmptyString) {
    password_ = new ::std::string;
  }
  return password_;
}
inline ::std::string* req_register::release_password() {
  clear_has_password();
  if (password_ == &::google_public::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = password_;
    password_ = const_cast< ::std::string*>(&::google_public::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void req_register::set_allocated_password(::std::string* password) {
  if (password_ != &::google_public::protobuf::internal::kEmptyString) {
    delete password_;
  }
  if (password) {
    set_has_password();
    password_ = password;
  } else {
    clear_has_password();
    password_ = const_cast< ::std::string*>(&::google_public::protobuf::internal::kEmptyString);
  }
}

// required string email = 3;
inline bool req_register::has_email() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void req_register::set_has_email() {
  _has_bits_[0] |= 0x00000004u;
}
inline void req_register::clear_has_email() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void req_register::clear_email() {
  if (email_ != &::google_public::protobuf::internal::kEmptyString) {
    email_->clear();
  }
  clear_has_email();
}
inline const ::std::string& req_register::email() const {
  return *email_;
}
inline void req_register::set_email(const ::std::string& value) {
  set_has_email();
  if (email_ == &::google_public::protobuf::internal::kEmptyString) {
    email_ = new ::std::string;
  }
  email_->assign(value);
}
inline void req_register::set_email(const char* value) {
  set_has_email();
  if (email_ == &::google_public::protobuf::internal::kEmptyString) {
    email_ = new ::std::string;
  }
  email_->assign(value);
}
inline void req_register::set_email(const char* value, size_t size) {
  set_has_email();
  if (email_ == &::google_public::protobuf::internal::kEmptyString) {
    email_ = new ::std::string;
  }
  email_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* req_register::mutable_email() {
  set_has_email();
  if (email_ == &::google_public::protobuf::internal::kEmptyString) {
    email_ = new ::std::string;
  }
  return email_;
}
inline ::std::string* req_register::release_email() {
  clear_has_email();
  if (email_ == &::google_public::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = email_;
    email_ = const_cast< ::std::string*>(&::google_public::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void req_register::set_allocated_email(::std::string* email) {
  if (email_ != &::google_public::protobuf::internal::kEmptyString) {
    delete email_;
  }
  if (email) {
    set_has_email();
    email_ = email;
  } else {
    clear_has_email();
    email_ = const_cast< ::std::string*>(&::google_public::protobuf::internal::kEmptyString);
  }
}

// optional int32 sex = 4;
inline bool req_register::has_sex() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void req_register::set_has_sex() {
  _has_bits_[0] |= 0x00000008u;
}
inline void req_register::clear_has_sex() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void req_register::clear_sex() {
  sex_ = 0;
  clear_has_sex();
}
inline ::google_public::protobuf::int32 req_register::sex() const {
  return sex_;
}
inline void req_register::set_sex(::google_public::protobuf::int32 value) {
  set_has_sex();
  sex_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol

#ifndef SWIG
namespace google_public {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_req_5fregister_2eproto__INCLUDED
