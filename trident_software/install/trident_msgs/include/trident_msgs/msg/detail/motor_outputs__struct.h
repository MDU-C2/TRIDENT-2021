// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from trident_msgs:msg/MotorOutputs.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUTS__STRUCT_H_
#define TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'motor_outputs'
#include "trident_msgs/msg/detail/motor_output__struct.h"

// Struct defined in msg/MotorOutputs in the package trident_msgs.
typedef struct trident_msgs__msg__MotorOutputs
{
  trident_msgs__msg__MotorOutput__Sequence motor_outputs;
} trident_msgs__msg__MotorOutputs;

// Struct for a sequence of trident_msgs__msg__MotorOutputs.
typedef struct trident_msgs__msg__MotorOutputs__Sequence
{
  trident_msgs__msg__MotorOutputs * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__msg__MotorOutputs__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUTS__STRUCT_H_
