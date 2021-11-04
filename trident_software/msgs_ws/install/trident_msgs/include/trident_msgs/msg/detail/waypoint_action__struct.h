// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from trident_msgs:msg/WaypointAction.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__MSG__DETAIL__WAYPOINT_ACTION__STRUCT_H_
#define TRIDENT_MSGS__MSG__DETAIL__WAYPOINT_ACTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/WaypointAction in the package trident_msgs.
typedef struct trident_msgs__msg__WaypointAction
{
  int16_t action_type;
  int16_t action_param;
} trident_msgs__msg__WaypointAction;

// Struct for a sequence of trident_msgs__msg__WaypointAction.
typedef struct trident_msgs__msg__WaypointAction__Sequence
{
  trident_msgs__msg__WaypointAction * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__msg__WaypointAction__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRIDENT_MSGS__MSG__DETAIL__WAYPOINT_ACTION__STRUCT_H_
