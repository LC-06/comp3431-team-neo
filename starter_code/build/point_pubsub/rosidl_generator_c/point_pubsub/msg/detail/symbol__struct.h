// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from point_pubsub:msg/Symbol.idl
// generated code does not contain a copyright notice

#ifndef POINT_PUBSUB__MSG__DETAIL__SYMBOL__STRUCT_H_
#define POINT_PUBSUB__MSG__DETAIL__SYMBOL__STRUCT_H_

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

// Struct defined in msg/Symbol in the package point_pubsub.
typedef struct point_pubsub__msg__Symbol
{
  rosidl_runtime_c__String data;
  geometry_msgs__msg__Point__Sequence points;
} point_pubsub__msg__Symbol;

// Struct for a sequence of point_pubsub__msg__Symbol.
typedef struct point_pubsub__msg__Symbol__Sequence
{
  point_pubsub__msg__Symbol * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} point_pubsub__msg__Symbol__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // POINT_PUBSUB__MSG__DETAIL__SYMBOL__STRUCT_H_
