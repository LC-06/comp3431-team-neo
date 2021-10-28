// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from point_msg_interface:msg/Pointmsg.idl
// generated code does not contain a copyright notice
#include "point_msg_interface/msg/detail/pointmsg__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "point_msg_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "point_msg_interface/msg/detail/pointmsg__struct.h"
#include "point_msg_interface/msg/detail/pointmsg__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "geometry_msgs/msg/detail/point_stamped__functions.h"  // point
#include "rosidl_runtime_c/string.h"  // point_data
#include "rosidl_runtime_c/string_functions.h"  // point_data

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_point_msg_interface
size_t get_serialized_size_geometry_msgs__msg__PointStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_point_msg_interface
size_t max_serialized_size_geometry_msgs__msg__PointStamped(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_point_msg_interface
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, PointStamped)();


using _Pointmsg__ros_msg_type = point_msg_interface__msg__Pointmsg;

static bool _Pointmsg__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Pointmsg__ros_msg_type * ros_message = static_cast<const _Pointmsg__ros_msg_type *>(untyped_ros_message);
  // Field name: point_data
  {
    const rosidl_runtime_c__String * str = &ros_message->point_data;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: point
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, PointStamped
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->point, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _Pointmsg__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Pointmsg__ros_msg_type * ros_message = static_cast<_Pointmsg__ros_msg_type *>(untyped_ros_message);
  // Field name: point_data
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->point_data.data) {
      rosidl_runtime_c__String__init(&ros_message->point_data);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->point_data,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'point_data'\n");
      return false;
    }
  }

  // Field name: point
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, PointStamped
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->point))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_point_msg_interface
size_t get_serialized_size_point_msg_interface__msg__Pointmsg(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Pointmsg__ros_msg_type * ros_message = static_cast<const _Pointmsg__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name point_data
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->point_data.size + 1);
  // field.name point

  current_alignment += get_serialized_size_geometry_msgs__msg__PointStamped(
    &(ros_message->point), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Pointmsg__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_point_msg_interface__msg__Pointmsg(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_point_msg_interface
size_t max_serialized_size_point_msg_interface__msg__Pointmsg(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: point_data
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: point
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__PointStamped(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _Pointmsg__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_point_msg_interface__msg__Pointmsg(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Pointmsg = {
  "point_msg_interface::msg",
  "Pointmsg",
  _Pointmsg__cdr_serialize,
  _Pointmsg__cdr_deserialize,
  _Pointmsg__get_serialized_size,
  _Pointmsg__max_serialized_size
};

static rosidl_message_type_support_t _Pointmsg__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Pointmsg,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, point_msg_interface, msg, Pointmsg)() {
  return &_Pointmsg__type_support;
}

#if defined(__cplusplus)
}
#endif
