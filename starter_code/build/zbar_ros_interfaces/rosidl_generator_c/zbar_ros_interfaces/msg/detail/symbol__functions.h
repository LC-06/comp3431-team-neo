// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from zbar_ros_interfaces:msg/Symbol.idl
// generated code does not contain a copyright notice

#ifndef ZBAR_ROS_INTERFACES__MSG__DETAIL__SYMBOL__FUNCTIONS_H_
#define ZBAR_ROS_INTERFACES__MSG__DETAIL__SYMBOL__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "zbar_ros_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "zbar_ros_interfaces/msg/detail/symbol__struct.h"

/// Initialize msg/Symbol message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * zbar_ros_interfaces__msg__Symbol
 * )) before or use
 * zbar_ros_interfaces__msg__Symbol__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_zbar_ros_interfaces
bool
zbar_ros_interfaces__msg__Symbol__init(zbar_ros_interfaces__msg__Symbol * msg);

/// Finalize msg/Symbol message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_zbar_ros_interfaces
void
zbar_ros_interfaces__msg__Symbol__fini(zbar_ros_interfaces__msg__Symbol * msg);

/// Create msg/Symbol message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * zbar_ros_interfaces__msg__Symbol__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_zbar_ros_interfaces
zbar_ros_interfaces__msg__Symbol *
zbar_ros_interfaces__msg__Symbol__create();

/// Destroy msg/Symbol message.
/**
 * It calls
 * zbar_ros_interfaces__msg__Symbol__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_zbar_ros_interfaces
void
zbar_ros_interfaces__msg__Symbol__destroy(zbar_ros_interfaces__msg__Symbol * msg);


/// Initialize array of msg/Symbol messages.
/**
 * It allocates the memory for the number of elements and calls
 * zbar_ros_interfaces__msg__Symbol__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_zbar_ros_interfaces
bool
zbar_ros_interfaces__msg__Symbol__Sequence__init(zbar_ros_interfaces__msg__Symbol__Sequence * array, size_t size);

/// Finalize array of msg/Symbol messages.
/**
 * It calls
 * zbar_ros_interfaces__msg__Symbol__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_zbar_ros_interfaces
void
zbar_ros_interfaces__msg__Symbol__Sequence__fini(zbar_ros_interfaces__msg__Symbol__Sequence * array);

/// Create array of msg/Symbol messages.
/**
 * It allocates the memory for the array and calls
 * zbar_ros_interfaces__msg__Symbol__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_zbar_ros_interfaces
zbar_ros_interfaces__msg__Symbol__Sequence *
zbar_ros_interfaces__msg__Symbol__Sequence__create(size_t size);

/// Destroy array of msg/Symbol messages.
/**
 * It calls
 * zbar_ros_interfaces__msg__Symbol__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_zbar_ros_interfaces
void
zbar_ros_interfaces__msg__Symbol__Sequence__destroy(zbar_ros_interfaces__msg__Symbol__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // ZBAR_ROS_INTERFACES__MSG__DETAIL__SYMBOL__FUNCTIONS_H_
