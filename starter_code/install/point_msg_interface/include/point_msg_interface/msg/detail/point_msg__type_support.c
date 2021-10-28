// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from point_msg_interface:msg/PointMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "point_msg_interface/msg/detail/point_msg__rosidl_typesupport_introspection_c.h"
#include "point_msg_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "point_msg_interface/msg/detail/point_msg__functions.h"
#include "point_msg_interface/msg/detail/point_msg__struct.h"


// Include directives for member types
// Member `point_data`
#include "rosidl_runtime_c/string_functions.h"
// Member `point`
#include "geometry_msgs/msg/point_stamped.h"
// Member `point`
#include "geometry_msgs/msg/detail/point_stamped__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void PointMsg__rosidl_typesupport_introspection_c__PointMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  point_msg_interface__msg__PointMsg__init(message_memory);
}

void PointMsg__rosidl_typesupport_introspection_c__PointMsg_fini_function(void * message_memory)
{
  point_msg_interface__msg__PointMsg__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember PointMsg__rosidl_typesupport_introspection_c__PointMsg_message_member_array[2] = {
  {
    "point_data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(point_msg_interface__msg__PointMsg, point_data),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "point",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(point_msg_interface__msg__PointMsg, point),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers PointMsg__rosidl_typesupport_introspection_c__PointMsg_message_members = {
  "point_msg_interface__msg",  // message namespace
  "PointMsg",  // message name
  2,  // number of fields
  sizeof(point_msg_interface__msg__PointMsg),
  PointMsg__rosidl_typesupport_introspection_c__PointMsg_message_member_array,  // message members
  PointMsg__rosidl_typesupport_introspection_c__PointMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  PointMsg__rosidl_typesupport_introspection_c__PointMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t PointMsg__rosidl_typesupport_introspection_c__PointMsg_message_type_support_handle = {
  0,
  &PointMsg__rosidl_typesupport_introspection_c__PointMsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_point_msg_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, point_msg_interface, msg, PointMsg)() {
  PointMsg__rosidl_typesupport_introspection_c__PointMsg_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PointStamped)();
  if (!PointMsg__rosidl_typesupport_introspection_c__PointMsg_message_type_support_handle.typesupport_identifier) {
    PointMsg__rosidl_typesupport_introspection_c__PointMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &PointMsg__rosidl_typesupport_introspection_c__PointMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
