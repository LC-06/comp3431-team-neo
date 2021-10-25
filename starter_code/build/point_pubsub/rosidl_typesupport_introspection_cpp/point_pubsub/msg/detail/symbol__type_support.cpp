// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from point_pubsub:msg/Symbol.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "point_pubsub/msg/detail/symbol__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace point_pubsub
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Symbol_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) point_pubsub::msg::Symbol(_init);
}

void Symbol_fini_function(void * message_memory)
{
  auto typed_message = static_cast<point_pubsub::msg::Symbol *>(message_memory);
  typed_message->~Symbol();
}

size_t size_function__Symbol__points(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Symbol__points(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__Symbol__points(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void resize_function__Symbol__points(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Symbol_message_member_array[2] = {
  {
    "data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(point_pubsub::msg::Symbol, data),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "points",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(point_pubsub::msg::Symbol, points),  // bytes offset in struct
    nullptr,  // default value
    size_function__Symbol__points,  // size() function pointer
    get_const_function__Symbol__points,  // get_const(index) function pointer
    get_function__Symbol__points,  // get(index) function pointer
    resize_function__Symbol__points  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Symbol_message_members = {
  "point_pubsub::msg",  // message namespace
  "Symbol",  // message name
  2,  // number of fields
  sizeof(point_pubsub::msg::Symbol),
  Symbol_message_member_array,  // message members
  Symbol_init_function,  // function to initialize message memory (memory has to be allocated)
  Symbol_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Symbol_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Symbol_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace point_pubsub


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<point_pubsub::msg::Symbol>()
{
  return &::point_pubsub::msg::rosidl_typesupport_introspection_cpp::Symbol_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, point_pubsub, msg, Symbol)() {
  return &::point_pubsub::msg::rosidl_typesupport_introspection_cpp::Symbol_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
