// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from trident_msgs:action/StartMission.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__ACTION__DETAIL__START_MISSION__STRUCT_H_
#define TRIDENT_MSGS__ACTION__DETAIL__START_MISSION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in action/StartMission in the package trident_msgs.
typedef struct trident_msgs__action__StartMission_Goal
{
  uint8_t structure_needs_at_least_one_member;
} trident_msgs__action__StartMission_Goal;

// Struct for a sequence of trident_msgs__action__StartMission_Goal.
typedef struct trident_msgs__action__StartMission_Goal__Sequence
{
  trident_msgs__action__StartMission_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__StartMission_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

// Struct defined in action/StartMission in the package trident_msgs.
typedef struct trident_msgs__action__StartMission_Result
{
  bool success;
  rosidl_runtime_c__String message;
} trident_msgs__action__StartMission_Result;

// Struct for a sequence of trident_msgs__action__StartMission_Result.
typedef struct trident_msgs__action__StartMission_Result__Sequence
{
  trident_msgs__action__StartMission_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__StartMission_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

// Struct defined in action/StartMission in the package trident_msgs.
typedef struct trident_msgs__action__StartMission_Feedback
{
  int16_t status;
  rosidl_runtime_c__String message;
  int16_t waypoints_completed;
} trident_msgs__action__StartMission_Feedback;

// Struct for a sequence of trident_msgs__action__StartMission_Feedback.
typedef struct trident_msgs__action__StartMission_Feedback__Sequence
{
  trident_msgs__action__StartMission_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__StartMission_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "trident_msgs/action/detail/start_mission__struct.h"

// Struct defined in action/StartMission in the package trident_msgs.
typedef struct trident_msgs__action__StartMission_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  trident_msgs__action__StartMission_Goal goal;
} trident_msgs__action__StartMission_SendGoal_Request;

// Struct for a sequence of trident_msgs__action__StartMission_SendGoal_Request.
typedef struct trident_msgs__action__StartMission_SendGoal_Request__Sequence
{
  trident_msgs__action__StartMission_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__StartMission_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

// Struct defined in action/StartMission in the package trident_msgs.
typedef struct trident_msgs__action__StartMission_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} trident_msgs__action__StartMission_SendGoal_Response;

// Struct for a sequence of trident_msgs__action__StartMission_SendGoal_Response.
typedef struct trident_msgs__action__StartMission_SendGoal_Response__Sequence
{
  trident_msgs__action__StartMission_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__StartMission_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

// Struct defined in action/StartMission in the package trident_msgs.
typedef struct trident_msgs__action__StartMission_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} trident_msgs__action__StartMission_GetResult_Request;

// Struct for a sequence of trident_msgs__action__StartMission_GetResult_Request.
typedef struct trident_msgs__action__StartMission_GetResult_Request__Sequence
{
  trident_msgs__action__StartMission_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__StartMission_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "trident_msgs/action/detail/start_mission__struct.h"

// Struct defined in action/StartMission in the package trident_msgs.
typedef struct trident_msgs__action__StartMission_GetResult_Response
{
  int8_t status;
  trident_msgs__action__StartMission_Result result;
} trident_msgs__action__StartMission_GetResult_Response;

// Struct for a sequence of trident_msgs__action__StartMission_GetResult_Response.
typedef struct trident_msgs__action__StartMission_GetResult_Response__Sequence
{
  trident_msgs__action__StartMission_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__StartMission_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "trident_msgs/action/detail/start_mission__struct.h"

// Struct defined in action/StartMission in the package trident_msgs.
typedef struct trident_msgs__action__StartMission_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  trident_msgs__action__StartMission_Feedback feedback;
} trident_msgs__action__StartMission_FeedbackMessage;

// Struct for a sequence of trident_msgs__action__StartMission_FeedbackMessage.
typedef struct trident_msgs__action__StartMission_FeedbackMessage__Sequence
{
  trident_msgs__action__StartMission_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__action__StartMission_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRIDENT_MSGS__ACTION__DETAIL__START_MISSION__STRUCT_H_
