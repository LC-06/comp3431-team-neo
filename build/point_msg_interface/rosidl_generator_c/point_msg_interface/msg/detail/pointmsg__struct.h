// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from point_msg_interface:msg/Pointmsg.idl
// generated code does not contain a copyright notice

#ifndef POINT_MSG_INTERFACE__MSG__DETAIL__POINTMSG__STRUCT_H_
#define POINT_MSG_INTERFACE__MSG__DETAIL__POINTMSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'point_data'
#include "rosidl_runtime_c/string.h"
// Member 'point'
#include "geometry_msgs/msg/detail/point_stamped__struct.h"

// Struct defined in msg/Pointmsg in the package point_msg_interface.
typedef struct point_msg_interface__msg__Pointmsg
{
  rosidl_runtime_c__String point_data;
  geometry_msgs__msg__PointStamped point;
} point_msg_interface__msg__Pointmsg;

// Struct for a sequence of point_msg_interface__msg__Pointmsg.
typedef struct point_msg_interface__msg__Pointmsg__Sequence
{
  point_msg_interface__msg__Pointmsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} point_msg_interface__msg__Pointmsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // POINT_MSG_INTERFACE__MSG__DETAIL__POINTMSG__STRUCT_H_
