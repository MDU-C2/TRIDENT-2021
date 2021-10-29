// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from trident_msgs:action/HoldPose.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__ACTION__DETAIL__HOLD_POSE__STRUCT_H_
#define TRIDENT_MSGS__ACTION__DETAIL__HOLD_POSE__STRUCT_H_

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

// Struct defined in action/HoldPose in the package trident_msgs.
typedef struct trident_msgs__action__HoldPose_Goal
{
  geometry_msgs__msg__Pose pose;
  int64_t duration;
} trident_msgs__action__HoldPose_Goal;

// Struct for a sequence of trident_msgs__action__HoldPose_Goal.
typedef struct trident_msgs__action__HoldPose_Goal__Sequence
{
  trident_msgs__action__HoldPose_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__HoldPose_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"
// Member 'pose_mean'
// Member 'pose_variance'
// already included above
// #include "geometry_msgs/msg/detail/pose__struct.h"

// Struct defined in action/HoldPose in the package trident_msgs.
typedef struct trident_msgs__action__HoldPose_Result
{
  int64_t duration;
  int16_t status;
  rosidl_runtime_c__String message;
  geometry_msgs__msg__Pose pose_mean;
  geometry_msgs__msg__Pose pose_variance;
} trident_msgs__action__HoldPose_Result;

// Struct for a sequence of trident_msgs__action__HoldPose_Result.
typedef struct trident_msgs__action__HoldPose_Result__Sequence
{
  trident_msgs__action__HoldPose_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__HoldPose_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'pose_mean'
// Member 'pose_variance'
// already included above
// #include "geometry_msgs/msg/detail/pose__struct.h"

// Struct defined in action/HoldPose in the package trident_msgs.
typedef struct trident_msgs__action__HoldPose_Feedback
{
  int16_t status;
  rosidl_runtime_c__String message;
  geometry_msgs__msg__Pose pose_mean;
  geometry_msgs__msg__Pose pose_variance;
} trident_msgs__action__HoldPose_Feedback;

// Struct for a sequence of trident_msgs__action__HoldPose_Feedback.
typedef struct trident_msgs__action__HoldPose_Feedback__Sequence
{
  trident_msgs__action__HoldPose_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__HoldPose_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "trident_msgs/action/detail/hold_pose__struct.h"

// Struct defined in action/HoldPose in the package trident_msgs.
typedef struct trident_msgs__action__HoldPose_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  trident_msgs__action__HoldPose_Goal goal;
} trident_msgs__action__HoldPose_SendGoal_Request;

// Struct for a sequence of trident_msgs__action__HoldPose_SendGoal_Request.
typedef struct trident_msgs__action__HoldPose_SendGoal_Request__Sequence
{
  trident_msgs__action__HoldPose_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__HoldPose_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

// Struct defined in action/HoldPose in the package trident_msgs.
typedef struct trident_msgs__action__HoldPose_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} trident_msgs__action__HoldPose_SendGoal_Response;

// Struct for a sequence of trident_msgs__action__HoldPose_SendGoal_Response.
typedef struct trident_msgs__action__HoldPose_SendGoal_Response__Sequence
{
  trident_msgs__action__HoldPose_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__HoldPose_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

// Struct defined in action/HoldPose in the package trident_msgs.
typedef struct trident_msgs__action__HoldPose_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} trident_msgs__action__HoldPose_GetResult_Request;

// Struct for a sequence of trident_msgs__action__HoldPose_GetResult_Request.
typedef struct trident_msgs__action__HoldPose_GetResult_Request__Sequence
{
  trident_msgs__action__HoldPose_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__HoldPose_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "trident_msgs/action/detail/hold_pose__struct.h"

// Struct defined in action/HoldPose in the package trident_msgs.
typedef struct trident_msgs__action__HoldPose_GetResult_Response
{
  int8_t status;
  trident_msgs__action__HoldPose_Result result;
} trident_msgs__action__HoldPose_GetResult_Response;

// Struct for a sequence of trident_msgs__action__HoldPose_GetResult_Response.
typedef struct trident_msgs__action__HoldPose_GetResult_Response__Sequence
{
  trident_msgs__action__HoldPose_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__HoldPose_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "trident_msgs/action/detail/hold_pose__struct.h"

// Struct defined in action/HoldPose in the package trident_msgs.
typedef struct trident_msgs__action__HoldPose_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  trident_msgs__action__HoldPose_Feedback feedback;
} trident_msgs__action__HoldPose_FeedbackMessage;

// Struct for a sequence of trident_msgs__action__HoldPose_FeedbackMessage.
typedef struct trident_msgs__action__HoldPose_FeedbackMessage__Sequence
{
  trident_msgs__action__HoldPose_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__HoldPose_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRIDENT_MSGS__ACTION__DETAIL__HOLD_POSE__STRUCT_H_
