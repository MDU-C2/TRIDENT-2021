// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from trident_msgs:msg/Mission.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__MISSION__FUNCTIONS_H_
#define TRIDENT_MSGS__MSG__DETAIL__MISSION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "trident_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "trident_msgs/msg/detail/mission__struct.h"

/// Initialize msg/Mission message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * trident_msgs__msg__Mission
 * )) before or use
 * trident_msgs__msg__Mission__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
bool
trident_msgs__msg__Mission__init(trident_msgs__msg__Mission * msg);

/// Finalize msg/Mission message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__msg__Mission__fini(trident_msgs__msg__Mission * msg);

/// Create msg/Mission message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * trident_msgs__msg__Mission__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
trident_msgs__msg__Mission *
trident_msgs__msg__Mission__create();

/// Destroy msg/Mission message.
/**
 * It calls
 * trident_msgs__msg__Mission__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__msg__Mission__destroy(trident_msgs__msg__Mission * msg);


/// Initialize array of msg/Mission messages.
/**
 * It allocates the memory for the number of elements and calls
 * trident_msgs__msg__Mission__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
bool
trident_msgs__msg__Mission__Sequence__init(trident_msgs__msg__Mission__Sequence * array, size_t size);

/// Finalize array of msg/Mission messages.
/**
 * It calls
 * trident_msgs__msg__Mission__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__msg__Mission__Sequence__fini(trident_msgs__msg__Mission__Sequence * array);

/// Create array of msg/Mission messages.
/**
 * It allocates the memory for the array and calls
 * trident_msgs__msg__Mission__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
trident_msgs__msg__Mission__Sequence *
trident_msgs__msg__Mission__Sequence__create(size_t size);

/// Destroy array of msg/Mission messages.
/**
 * It calls
 * trident_msgs__msg__Mission__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__msg__Mission__Sequence__destroy(trident_msgs__msg__Mission__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // TRIDENT_MSGS__MSG__DETAIL__MISSION__FUNCTIONS_H_
