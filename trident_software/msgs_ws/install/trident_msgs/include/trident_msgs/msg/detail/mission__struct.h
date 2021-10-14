// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from trident_msgs:msg/Mission.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__MISSION__STRUCT_H_
#define TRIDENT_MSGS__MSG__DETAIL__MISSION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'waypoints'
#include "trident_msgs/msg/detail/waypoint__struct.h"

// Struct defined in msg/Mission in the package trident_msgs.
typedef struct trident_msgs__msg__Mission
{
  trident_msgs__msg__Waypoint__Sequence waypoints;
} trident_msgs__msg__Mission;

// Struct for a sequence of trident_msgs__msg__Mission.
typedef struct trident_msgs__msg__Mission__Sequence
{
  trident_msgs__msg__Mission * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__msg__Mission__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRIDENT_MSGS__MSG__DETAIL__MISSION__STRUCT_H_
