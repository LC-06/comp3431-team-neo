// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from point_msg_interface:msg/Pointmsg.idl
// generated code does not contain a copyright notice
#include "point_msg_interface/msg/detail/pointmsg__rosidl_typesupport_fastrtps_cpp.hpp"
#include "point_msg_interface/msg/detail/pointmsg__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace geometry_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::PointStamped &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  geometry_msgs::msg::PointStamped &);
size_t get_serialized_size(
  const geometry_msgs::msg::PointStamped &,
  size_t current_alignment);
size_t
max_serialized_size_PointStamped(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace geometry_msgs


namespace point_msg_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_point_msg_interface
cdr_serialize(
  const point_msg_interface::msg::Pointmsg & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: point_data
  cdr << ros_message.point_data;
  // Member: point
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.point,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_point_msg_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  point_msg_interface::msg::Pointmsg & ros_message)
{
  // Member: point_data
  cdr >> ros_message.point_data;

  // Member: point
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.point);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_point_msg_interface
get_serialized_size(
  const point_msg_interface::msg::Pointmsg & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: point_data
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.point_data.size() + 1);
  // Member: point

  current_alignment +=
    geometry_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.point, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_point_msg_interface
max_serialized_size_Pointmsg(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: point_data
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: point
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        geometry_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_PointStamped(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _Pointmsg__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const point_msg_interface::msg::Pointmsg *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Pointmsg__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<point_msg_interface::msg::Pointmsg *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Pointmsg__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const point_msg_interface::msg::Pointmsg *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Pointmsg__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Pointmsg(full_bounded, 0);
}

static message_type_support_callbacks_t _Pointmsg__callbacks = {
  "point_msg_interface::msg",
  "Pointmsg",
  _Pointmsg__cdr_serialize,
  _Pointmsg__cdr_deserialize,
  _Pointmsg__get_serialized_size,
  _Pointmsg__max_serialized_size
};

static rosidl_message_type_support_t _Pointmsg__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Pointmsg__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace point_msg_interface

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_point_msg_interface
const rosidl_message_type_support_t *
get_message_type_support_handle<point_msg_interface::msg::Pointmsg>()
{
  return &point_msg_interface::msg::typesupport_fastrtps_cpp::_Pointmsg__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, point_msg_interface, msg, Pointmsg)() {
  return &point_msg_interface::msg::typesupport_fastrtps_cpp::_Pointmsg__handle;
}

#ifdef __cplusplus
}
#endif
