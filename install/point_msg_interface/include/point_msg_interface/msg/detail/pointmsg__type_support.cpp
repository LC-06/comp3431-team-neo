// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from point_msg_interface:msg/Pointmsg.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "point_msg_interface/msg/detail/pointmsg__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace point_msg_interface
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Pointmsg_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) point_msg_interface::msg::Pointmsg(_init);
}

void Pointmsg_fini_function(void * message_memory)
{
  auto typed_message = static_cast<point_msg_interface::msg::Pointmsg *>(message_memory);
  typed_message->~Pointmsg();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Pointmsg_message_member_array[2] = {
  {
    "point_data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(point_msg_interface::msg::Pointmsg, point_data),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "point",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::PointStamped>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(point_msg_interface::msg::Pointmsg, point),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Pointmsg_message_members = {
  "point_msg_interface::msg",  // message namespace
  "Pointmsg",  // message name
  2,  // number of fields
  sizeof(point_msg_interface::msg::Pointmsg),
  Pointmsg_message_member_array,  // message members
  Pointmsg_init_function,  // function to initialize message memory (memory has to be allocated)
  Pointmsg_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Pointmsg_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Pointmsg_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace point_msg_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<point_msg_interface::msg::Pointmsg>()
{
  return &::point_msg_interface::msg::rosidl_typesupport_introspection_cpp::Pointmsg_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, point_msg_interface, msg, Pointmsg)() {
  return &::point_msg_interface::msg::rosidl_typesupport_introspection_cpp::Pointmsg_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
