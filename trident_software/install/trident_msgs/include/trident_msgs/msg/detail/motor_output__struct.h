// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from trident_msgs:msg/MotorOutput.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUT__STRUCT_H_
#define TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUT__STRUCT_H_

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
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/MotorOutput in the package trident_msgs.
typedef struct trident_msgs__msg__MotorOutput
{
  rosidl_runtime_c__int64__Sequence motor_outputs;
} trident_msgs__msg__MotorOutput;

// Struct for a sequence of trident_msgs__msg__MotorOutput.
typedef struct trident_msgs__msg__MotorOutput__Sequence
{
  trident_msgs__msg__MotorOutput * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__msg__MotorOutput__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRIDENT_MSGS__MSG__DETAIL__MOTOR_OUTPUT__STRUCT_H_
