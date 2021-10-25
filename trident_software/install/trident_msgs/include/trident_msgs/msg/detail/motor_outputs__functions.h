// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from trident_msgs:msg/MotorOutputs.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUTS__FUNCTIONS_H_
#define TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUTS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "trident_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "trident_msgs/msg/detail/motor_outputs__struct.h"

/// Initialize msg/MotorOutputs message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * trident_msgs__msg__MotorOutputs
 * )) before or use
 * trident_msgs__msg__MotorOutputs__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
bool
trident_msgs__msg__MotorOutputs__init(trident_msgs__msg__MotorOutputs * msg);

/// Finalize msg/MotorOutputs message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__msg__MotorOutputs__fini(trident_msgs__msg__MotorOutputs * msg);

/// Create msg/MotorOutputs message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * trident_msgs__msg__MotorOutputs__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
trident_msgs__msg__MotorOutputs *
trident_msgs__msg__MotorOutputs__create();

/// Destroy msg/MotorOutputs message.
/**
 * It calls
 * trident_msgs__msg__MotorOutputs__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__msg__MotorOutputs__destroy(trident_msgs__msg__MotorOutputs * msg);


/// Initialize array of msg/MotorOutputs messages.
/**
 * It allocates the memory for the number of elements and calls
 * trident_msgs__msg__MotorOutputs__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
bool
trident_msgs__msg__MotorOutputs__Sequence__init(trident_msgs__msg__MotorOutputs__Sequence * array, size_t size);

/// Finalize array of msg/MotorOutputs messages.
/**
 * It calls
 * trident_msgs__msg__MotorOutputs__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__msg__MotorOutputs__Sequence__fini(trident_msgs__msg__MotorOutputs__Sequence * array);

/// Create array of msg/MotorOutputs messages.
/**
 * It allocates the memory for the array and calls
 * trident_msgs__msg__MotorOutputs__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
trident_msgs__msg__MotorOutputs__Sequence *
trident_msgs__msg__MotorOutputs__Sequence__create(size_t size);

/// Destroy array of msg/MotorOutputs messages.
/**
 * It calls
 * trident_msgs__msg__MotorOutputs__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__msg__MotorOutputs__Sequence__destroy(trident_msgs__msg__MotorOutputs__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUTS__FUNCTIONS_H_
