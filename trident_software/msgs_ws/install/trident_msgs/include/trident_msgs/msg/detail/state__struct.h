// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from trident_msgs:msg/State.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__STATE__STRUCT_H_
#define TRIDENT_MSGS__MSG__DETAIL__STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'twist'
#include "geometry_msgs/msg/detail/twist__struct.h"

// Struct defined in msg/State in the package trident_msgs.
typedef struct trident_msgs__msg__State
{
  geometry_msgs__msg__Pose pose;
  geometry_msgs__msg__Twist twist;
} trident_msgs__msg__State;

// Struct for a sequence of trident_msgs__msg__State.
typedef struct trident_msgs__msg__State__Sequence
{
  trident_msgs__msg__State * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__msg__State__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRIDENT_MSGS__MSG__DETAIL__STATE__STRUCT_H_
