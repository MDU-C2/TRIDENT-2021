// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from trident_msgs:srv/GetGoalPose.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__SRV__DETAIL__GET_GOAL_POSE__STRUCT_H_
#define TRIDENT_MSGS__SRV__DETAIL__GET_GOAL_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/GetGoalPose in the package trident_msgs.
typedef struct trident_msgs__srv__GetGoalPose_Request
{
  uint8_t structure_needs_at_least_one_member;
} trident_msgs__srv__GetGoalPose_Request;

// Struct for a sequence of trident_msgs__srv__GetGoalPose_Request.
typedef struct trident_msgs__srv__GetGoalPose_Request__Sequence
{
  trident_msgs__srv__GetGoalPose_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__srv__GetGoalPose_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"
// Member 'goal_pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

// Struct defined in srv/GetGoalPose in the package trident_msgs.
typedef struct trident_msgs__srv__GetGoalPose_Response
{
  bool success;
  rosidl_runtime_c__String message;
  geometry_msgs__msg__Pose goal_pose;
} trident_msgs__srv__GetGoalPose_Response;

// Struct for a sequence of trident_msgs__srv__GetGoalPose_Response.
typedef struct trident_msgs__srv__GetGoalPose_Response__Sequence
{
  trident_msgs__srv__GetGoalPose_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__srv__GetGoalPose_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRIDENT_MSGS__SRV__DETAIL__GET_GOAL_POSE__STRUCT_H_
