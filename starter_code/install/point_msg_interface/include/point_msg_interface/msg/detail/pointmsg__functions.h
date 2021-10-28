// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from point_msg_interface:msg/Pointmsg.idl
// generated code does not contain a copyright notice

#ifndef POINT_MSG_INTERFACE__MSG__DETAIL__POINTMSG__FUNCTIONS_H_
#define POINT_MSG_INTERFACE__MSG__DETAIL__POINTMSG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "point_msg_interface/msg/rosidl_generator_c__visibility_control.h"

#include "point_msg_interface/msg/detail/pointmsg__struct.h"

/// Initialize msg/Pointmsg message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * point_msg_interface__msg__Pointmsg
 * )) before or use
 * point_msg_interface__msg__Pointmsg__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_point_msg_interface
bool
point_msg_interface__msg__Pointmsg__init(point_msg_interface__msg__Pointmsg * msg);

/// Finalize msg/Pointmsg message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_point_msg_interface
void
point_msg_interface__msg__Pointmsg__fini(point_msg_interface__msg__Pointmsg * msg);

/// Create msg/Pointmsg message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * point_msg_interface__msg__Pointmsg__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_point_msg_interface
point_msg_interface__msg__Pointmsg *
point_msg_interface__msg__Pointmsg__create();

/// Destroy msg/Pointmsg message.
/**
 * It calls
 * point_msg_interface__msg__Pointmsg__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_point_msg_interface
void
point_msg_interface__msg__Pointmsg__destroy(point_msg_interface__msg__Pointmsg * msg);


/// Initialize array of msg/Pointmsg messages.
/**
 * It allocates the memory for the number of elements and calls
 * point_msg_interface__msg__Pointmsg__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_point_msg_interface
bool
point_msg_interface__msg__Pointmsg__Sequence__init(point_msg_interface__msg__Pointmsg__Sequence * array, size_t size);

/// Finalize array of msg/Pointmsg messages.
/**
 * It calls
 * point_msg_interface__msg__Pointmsg__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_point_msg_interface
void
point_msg_interface__msg__Pointmsg__Sequence__fini(point_msg_interface__msg__Pointmsg__Sequence * array);

/// Create array of msg/Pointmsg messages.
/**
 * It allocates the memory for the array and calls
 * point_msg_interface__msg__Pointmsg__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_point_msg_interface
point_msg_interface__msg__Pointmsg__Sequence *
point_msg_interface__msg__Pointmsg__Sequence__create(size_t size);

/// Destroy array of msg/Pointmsg messages.
/**
 * It calls
 * point_msg_interface__msg__Pointmsg__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_point_msg_interface
void
point_msg_interface__msg__Pointmsg__Sequence__destroy(point_msg_interface__msg__Pointmsg__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // POINT_MSG_INTERFACE__MSG__DETAIL__POINTMSG__FUNCTIONS_H_
