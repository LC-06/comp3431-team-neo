// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from zbar_ros_interfaces:msg/Symbol.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "zbar_ros_interfaces/msg/detail/symbol__rosidl_typesupport_introspection_c.h"
#include "zbar_ros_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "zbar_ros_interfaces/msg/detail/symbol__functions.h"
#include "zbar_ros_interfaces/msg/detail/symbol__struct.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/string_functions.h"
// Member `points`
#include "geometry_msgs/msg/point.h"
// Member `points`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Symbol__rosidl_typesupport_introspection_c__Symbol_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  zbar_ros_interfaces__msg__Symbol__init(message_memory);
}

void Symbol__rosidl_typesupport_introspection_c__Symbol_fini_function(void * message_memory)
{
  zbar_ros_interfaces__msg__Symbol__fini(message_memory);
}

size_t Symbol__rosidl_typesupport_introspection_c__size_function__Point__points(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * Symbol__rosidl_typesupport_introspection_c__get_const_function__Point__points(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * Symbol__rosidl_typesupport_introspection_c__get_function__Point__points(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

bool Symbol__rosidl_typesupport_introspection_c__resize_function__Point__points(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember Symbol__rosidl_typesupport_introspection_c__Symbol_message_member_array[2] = {
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zbar_ros_interfaces__msg__Symbol, data),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zbar_ros_interfaces__msg__Symbol, points),  // bytes offset in struct
    NULL,  // default value
    Symbol__rosidl_typesupport_introspection_c__size_function__Point__points,  // size() function pointer
    Symbol__rosidl_typesupport_introspection_c__get_const_function__Point__points,  // get_const(index) function pointer
    Symbol__rosidl_typesupport_introspection_c__get_function__Point__points,  // get(index) function pointer
    Symbol__rosidl_typesupport_introspection_c__resize_function__Point__points  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Symbol__rosidl_typesupport_introspection_c__Symbol_message_members = {
  "zbar_ros_interfaces__msg",  // message namespace
  "Symbol",  // message name
  2,  // number of fields
  sizeof(zbar_ros_interfaces__msg__Symbol),
  Symbol__rosidl_typesupport_introspection_c__Symbol_message_member_array,  // message members
  Symbol__rosidl_typesupport_introspection_c__Symbol_init_function,  // function to initialize message memory (memory has to be allocated)
  Symbol__rosidl_typesupport_introspection_c__Symbol_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Symbol__rosidl_typesupport_introspection_c__Symbol_message_type_support_handle = {
  0,
  &Symbol__rosidl_typesupport_introspection_c__Symbol_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_zbar_ros_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zbar_ros_interfaces, msg, Symbol)() {
  Symbol__rosidl_typesupport_introspection_c__Symbol_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!Symbol__rosidl_typesupport_introspection_c__Symbol_message_type_support_handle.typesupport_identifier) {
    Symbol__rosidl_typesupport_introspection_c__Symbol_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Symbol__rosidl_typesupport_introspection_c__Symbol_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
