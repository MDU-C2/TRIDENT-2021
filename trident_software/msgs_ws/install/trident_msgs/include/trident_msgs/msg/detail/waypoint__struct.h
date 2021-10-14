// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from trident_msgs:msg/Waypoint.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__WAYPOINT__STRUCT_H_
#define TRIDENT_MSGS__MSG__DETAIL__WAYPOINT__STRUCT_H_

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
// Member 'action'
#include "trident_msgs/msg/detail/waypoint_action__struct.h"

// Struct defined in msg/Waypoint in the package trident_msgs.
typedef struct trident_msgs__msg__Waypoint
{
  geometry_msgs__msg__Pose pose;
  trident_msgs__msg__WaypointAction action;
} trident_msgs__msg__Waypoint;

// Struct for a sequence of trident_msgs__msg__Waypoint.
typedef struct trident_msgs__msg__Waypoint__Sequence
{
  trident_msgs__msg__Waypoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__msg__Waypoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRIDENT_MSGS__MSG__DETAIL__WAYPOINT__STRUCT_H_
