// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from zbar_ros_interfaces:msg/Symbol.idl
// generated code does not contain a copyright notice

#ifndef ZBAR_ROS_INTERFACES__MSG__DETAIL__SYMBOL__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define ZBAR_ROS_INTERFACES__MSG__DETAIL__SYMBOL__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "zbar_ros_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "zbar_ros_interfaces/msg/detail/symbol__struct.hpp"

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

namespace zbar_ros_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zbar_ros_interfaces
cdr_serialize(
  const zbar_ros_interfaces::msg::Symbol & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zbar_ros_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  zbar_ros_interfaces::msg::Symbol & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zbar_ros_interfaces
get_serialized_size(
  const zbar_ros_interfaces::msg::Symbol & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zbar_ros_interfaces
max_serialized_size_Symbol(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace zbar_ros_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zbar_ros_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, zbar_ros_interfaces, msg, Symbol)();

#ifdef __cplusplus
}
#endif

#endif  // ZBAR_ROS_INTERFACES__MSG__DETAIL__SYMBOL__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
