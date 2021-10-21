// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from zbar_ros_interfaces:msg/Symbol.idl
// generated code does not contain a copyright notice

#ifndef ZBAR_ROS_INTERFACES__MSG__DETAIL__SYMBOL__STRUCT_H_
#define ZBAR_ROS_INTERFACES__MSG__DETAIL__SYMBOL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/string.h"
// Member 'points'
#include "geometry_msgs/msg/detail/point__struct.h"

// Struct defined in msg/Symbol in the package zbar_ros_interfaces.
typedef struct zbar_ros_interfaces__msg__Symbol
{
  rosidl_runtime_c__String data;
  geometry_msgs__msg__Point__Sequence points;
} zbar_ros_interfaces__msg__Symbol;

// Struct for a sequence of zbar_ros_interfaces__msg__Symbol.
typedef struct zbar_ros_interfaces__msg__Symbol__Sequence
{
  zbar_ros_interfaces__msg__Symbol * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zbar_ros_interfaces__msg__Symbol__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ZBAR_ROS_INTERFACES__MSG__DETAIL__SYMBOL__STRUCT_H_
