// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from point_msg_interface:msg/Pointmsg.idl
// generated code does not contain a copyright notice
#include "point_msg_interface/msg/detail/pointmsg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `point_data`
#include "rosidl_runtime_c/string_functions.h"
// Member `point`
#include "geometry_msgs/msg/detail/point_stamped__functions.h"

bool
point_msg_interface__msg__Pointmsg__init(point_msg_interface__msg__Pointmsg * msg)
{
  if (!msg) {
    return false;
  }
  // point_data
  if (!rosidl_runtime_c__String__init(&msg->point_data)) {
    point_msg_interface__msg__Pointmsg__fini(msg);
    return false;
  }
  // point
  if (!geometry_msgs__msg__PointStamped__init(&msg->point)) {
    point_msg_interface__msg__Pointmsg__fini(msg);
    return false;
  }
  return true;
}

void
point_msg_interface__msg__Pointmsg__fini(point_msg_interface__msg__Pointmsg * msg)
{
  if (!msg) {
    return;
  }
  // point_data
  rosidl_runtime_c__String__fini(&msg->point_data);
  // point
  geometry_msgs__msg__PointStamped__fini(&msg->point);
}

point_msg_interface__msg__Pointmsg *
point_msg_interface__msg__Pointmsg__create()
{
  point_msg_interface__msg__Pointmsg * msg = (point_msg_interface__msg__Pointmsg *)malloc(sizeof(point_msg_interface__msg__Pointmsg));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(point_msg_interface__msg__Pointmsg));
  bool success = point_msg_interface__msg__Pointmsg__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
point_msg_interface__msg__Pointmsg__destroy(point_msg_interface__msg__Pointmsg * msg)
{
  if (msg) {
    point_msg_interface__msg__Pointmsg__fini(msg);
  }
  free(msg);
}


bool
point_msg_interface__msg__Pointmsg__Sequence__init(point_msg_interface__msg__Pointmsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  point_msg_interface__msg__Pointmsg * data = NULL;
  if (size) {
    data = (point_msg_interface__msg__Pointmsg *)calloc(size, sizeof(point_msg_interface__msg__Pointmsg));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = point_msg_interface__msg__Pointmsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        point_msg_interface__msg__Pointmsg__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
point_msg_interface__msg__Pointmsg__Sequence__fini(point_msg_interface__msg__Pointmsg__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      point_msg_interface__msg__Pointmsg__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

point_msg_interface__msg__Pointmsg__Sequence *
point_msg_interface__msg__Pointmsg__Sequence__create(size_t size)
{
  point_msg_interface__msg__Pointmsg__Sequence * array = (point_msg_interface__msg__Pointmsg__Sequence *)malloc(sizeof(point_msg_interface__msg__Pointmsg__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = point_msg_interface__msg__Pointmsg__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
point_msg_interface__msg__Pointmsg__Sequence__destroy(point_msg_interface__msg__Pointmsg__Sequence * array)
{
  if (array) {
    point_msg_interface__msg__Pointmsg__Sequence__fini(array);
  }
  free(array);
}
