// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from point_pubsub:msg/Symbol.idl
// generated code does not contain a copyright notice

#ifndef POINT_PUBSUB__MSG__DETAIL__SYMBOL__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define POINT_PUBSUB__MSG__DETAIL__SYMBOL__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "point_pubsub/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "point_pubsub/msg/detail/symbol__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace point_pubsub
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_point_pubsub
cdr_serialize(
  const point_pubsub::msg::Symbol & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_point_pubsub
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  point_pubsub::msg::Symbol & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_point_pubsub
get_serialized_size(
  const point_pubsub::msg::Symbol & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_point_pubsub
max_serialized_size_Symbol(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace point_pubsub

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_point_pubsub
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, point_pubsub, msg, Symbol)();

#ifdef __cplusplus
}
#endif

#endif  // POINT_PUBSUB__MSG__DETAIL__SYMBOL__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
