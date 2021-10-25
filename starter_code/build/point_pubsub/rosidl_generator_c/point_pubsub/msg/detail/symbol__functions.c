// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from point_pubsub:msg/Symbol.idl
// generated code does not contain a copyright notice
#include "point_pubsub/msg/detail/symbol__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/string_functions.h"
// Member `points`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
point_pubsub__msg__Symbol__init(point_pubsub__msg__Symbol * msg)
{
  if (!msg) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__String__init(&msg->data)) {
    point_pubsub__msg__Symbol__fini(msg);
    return false;
  }
  // points
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->points, 0)) {
    point_pubsub__msg__Symbol__fini(msg);
    return false;
  }
  return true;
}

void
point_pubsub__msg__Symbol__fini(point_pubsub__msg__Symbol * msg)
{
  if (!msg) {
    return;
  }
  // data
  rosidl_runtime_c__String__fini(&msg->data);
  // points
  geometry_msgs__msg__Point__Sequence__fini(&msg->points);
}

point_pubsub__msg__Symbol *
point_pubsub__msg__Symbol__create()
{
  point_pubsub__msg__Symbol * msg = (point_pubsub__msg__Symbol *)malloc(sizeof(point_pubsub__msg__Symbol));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(point_pubsub__msg__Symbol));
  bool success = point_pubsub__msg__Symbol__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
point_pubsub__msg__Symbol__destroy(point_pubsub__msg__Symbol * msg)
{
  if (msg) {
    point_pubsub__msg__Symbol__fini(msg);
  }
  free(msg);
}


bool
point_pubsub__msg__Symbol__Sequence__init(point_pubsub__msg__Symbol__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  point_pubsub__msg__Symbol * data = NULL;
  if (size) {
    data = (point_pubsub__msg__Symbol *)calloc(size, sizeof(point_pubsub__msg__Symbol));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = point_pubsub__msg__Symbol__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        point_pubsub__msg__Symbol__fini(&data[i - 1]);
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
point_pubsub__msg__Symbol__Sequence__fini(point_pubsub__msg__Symbol__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      point_pubsub__msg__Symbol__fini(&array->data[i]);
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

point_pubsub__msg__Symbol__Sequence *
point_pubsub__msg__Symbol__Sequence__create(size_t size)
{
  point_pubsub__msg__Symbol__Sequence * array = (point_pubsub__msg__Symbol__Sequence *)malloc(sizeof(point_pubsub__msg__Symbol__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = point_pubsub__msg__Symbol__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
point_pubsub__msg__Symbol__Sequence__destroy(point_pubsub__msg__Symbol__Sequence * array)
{
  if (array) {
    point_pubsub__msg__Symbol__Sequence__fini(array);
  }
  free(array);
}
