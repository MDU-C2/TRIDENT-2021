// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from trident_msgs:action/GotoPose.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__ACTION__DETAIL__GOTO_POSE__STRUCT_H_
#define TRIDENT_MSGS__ACTION__DETAIL__GOTO_POSE__STRUCT_H_

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

// Struct defined in action/GotoPose in the package trident_msgs.
typedef struct trident_msgs__action__GotoPose_Goal
{
  geometry_msgs__msg__Pose pose;
} trident_msgs__action__GotoPose_Goal;

// Struct for a sequence of trident_msgs__action__GotoPose_Goal.
typedef struct trident_msgs__action__GotoPose_Goal__Sequence
{
  trident_msgs__action__GotoPose_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__GotoPose_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"
// Member 'delta_pose'
// already included above
// #include "geometry_msgs/msg/detail/pose__struct.h"

// Struct defined in action/GotoPose in the package trident_msgs.
typedef struct trident_msgs__action__GotoPose_Result
{
  int16_t status;
  rosidl_runtime_c__String message;
  geometry_msgs__msg__Pose delta_pose;
  double distance_to_goal;
} trident_msgs__action__GotoPose_Result;

// Struct for a sequence of trident_msgs__action__GotoPose_Result.
typedef struct trident_msgs__action__GotoPose_Result__Sequence
{
  trident_msgs__action__GotoPose_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__GotoPose_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'delta_pose'
// already included above
// #include "geometry_msgs/msg/detail/pose__struct.h"

// Struct defined in action/GotoPose in the package trident_msgs.
typedef struct trident_msgs__action__GotoPose_Feedback
{
  int16_t status;
  rosidl_runtime_c__String message;
  geometry_msgs__msg__Pose delta_pose;
  double distance_to_goal;
} trident_msgs__action__GotoPose_Feedback;

// Struct for a sequence of trident_msgs__action__GotoPose_Feedback.
typedef struct trident_msgs__action__GotoPose_Feedback__Sequence
{
  trident_msgs__action__GotoPose_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__GotoPose_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "trident_msgs/action/detail/goto_pose__struct.h"

// Struct defined in action/GotoPose in the package trident_msgs.
typedef struct trident_msgs__action__GotoPose_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  trident_msgs__action__GotoPose_Goal goal;
} trident_msgs__action__GotoPose_SendGoal_Request;

// Struct for a sequence of trident_msgs__action__GotoPose_SendGoal_Request.
typedef struct trident_msgs__action__GotoPose_SendGoal_Request__Sequence
{
  trident_msgs__action__GotoPose_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__GotoPose_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

// Struct defined in action/GotoPose in the package trident_msgs.
typedef struct trident_msgs__action__GotoPose_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} trident_msgs__action__GotoPose_SendGoal_Response;

// Struct for a sequence of trident_msgs__action__GotoPose_SendGoal_Response.
typedef struct trident_msgs__action__GotoPose_SendGoal_Response__Sequence
{
  trident_msgs__action__GotoPose_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__GotoPose_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

// Struct defined in action/GotoPose in the package trident_msgs.
typedef struct trident_msgs__action__GotoPose_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} trident_msgs__action__GotoPose_GetResult_Request;

// Struct for a sequence of trident_msgs__action__GotoPose_GetResult_Request.
typedef struct trident_msgs__action__GotoPose_GetResult_Request__Sequence
{
  trident_msgs__action__GotoPose_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__GotoPose_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "trident_msgs/action/detail/goto_pose__struct.h"

// Struct defined in action/GotoPose in the package trident_msgs.
typedef struct trident_msgs__action__GotoPose_GetResult_Response
{
  int8_t status;
  trident_msgs__action__GotoPose_Result result;
} trident_msgs__action__GotoPose_GetResult_Response;

// Struct for a sequence of trident_msgs__action__GotoPose_GetResult_Response.
typedef struct trident_msgs__action__GotoPose_GetResult_Response__Sequence
{
  trident_msgs__action__GotoPose_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__GotoPose_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "trident_msgs/action/detail/goto_pose__struct.h"

// Struct defined in action/GotoPose in the package trident_msgs.
typedef struct trident_msgs__action__GotoPose_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  trident_msgs__action__GotoPose_Feedback feedback;
} trident_msgs__action__GotoPose_FeedbackMessage;

// Struct for a sequence of trident_msgs__action__GotoPose_FeedbackMessage.
typedef struct trident_msgs__action__GotoPose_FeedbackMessage__Sequence
{
  trident_msgs__action__GotoPose_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__GotoPose_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRIDENT_MSGS__ACTION__DETAIL__GOTO_POSE__STRUCT_H_
