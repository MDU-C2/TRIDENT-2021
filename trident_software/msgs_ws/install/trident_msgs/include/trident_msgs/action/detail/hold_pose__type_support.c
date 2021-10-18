// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from trident_msgs:action/HoldPose.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "trident_msgs/action/detail/hold_pose__rosidl_typesupport_introspection_c.h"
#include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "trident_msgs/action/detail/hold_pose__functions.h"
#include "trident_msgs/action/detail/hold_pose__struct.h"


// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/pose.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void HoldPose_Goal__rosidl_typesupport_introspection_c__HoldPose_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__HoldPose_Goal__init(message_memory);
}

void HoldPose_Goal__rosidl_typesupport_introspection_c__HoldPose_Goal_fini_function(void * message_memory)
{
  trident_msgs__action__HoldPose_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember HoldPose_Goal__rosidl_typesupport_introspection_c__HoldPose_Goal_message_member_array[2] = {
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__HoldPose_Goal, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "duration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__HoldPose_Goal, duration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers HoldPose_Goal__rosidl_typesupport_introspection_c__HoldPose_Goal_message_members = {
  "trident_msgs__action",  // message namespace
  "HoldPose_Goal",  // message name
  2,  // number of fields
  sizeof(trident_msgs__action__HoldPose_Goal),
  HoldPose_Goal__rosidl_typesupport_introspection_c__HoldPose_Goal_message_member_array,  // message members
  HoldPose_Goal__rosidl_typesupport_introspection_c__HoldPose_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  HoldPose_Goal__rosidl_typesupport_introspection_c__HoldPose_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t HoldPose_Goal__rosidl_typesupport_introspection_c__HoldPose_Goal_message_type_support_handle = {
  0,
  &HoldPose_Goal__rosidl_typesupport_introspection_c__HoldPose_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_Goal)() {
  HoldPose_Goal__rosidl_typesupport_introspection_c__HoldPose_Goal_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!HoldPose_Goal__rosidl_typesupport_introspection_c__HoldPose_Goal_message_type_support_handle.typesupport_identifier) {
    HoldPose_Goal__rosidl_typesupport_introspection_c__HoldPose_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &HoldPose_Goal__rosidl_typesupport_introspection_c__HoldPose_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/hold_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/hold_pose__functions.h"
// already included above
// #include "trident_msgs/action/detail/hold_pose__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"
// Member `mean_pose_deviation`
// already included above
// #include "geometry_msgs/msg/pose.h"
// Member `mean_pose_deviation`
// already included above
// #include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void HoldPose_Result__rosidl_typesupport_introspection_c__HoldPose_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__HoldPose_Result__init(message_memory);
}

void HoldPose_Result__rosidl_typesupport_introspection_c__HoldPose_Result_fini_function(void * message_memory)
{
  trident_msgs__action__HoldPose_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember HoldPose_Result__rosidl_typesupport_introspection_c__HoldPose_Result_message_member_array[3] = {
  {
    "duration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__HoldPose_Result, duration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__HoldPose_Result, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mean_pose_deviation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__HoldPose_Result, mean_pose_deviation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers HoldPose_Result__rosidl_typesupport_introspection_c__HoldPose_Result_message_members = {
  "trident_msgs__action",  // message namespace
  "HoldPose_Result",  // message name
  3,  // number of fields
  sizeof(trident_msgs__action__HoldPose_Result),
  HoldPose_Result__rosidl_typesupport_introspection_c__HoldPose_Result_message_member_array,  // message members
  HoldPose_Result__rosidl_typesupport_introspection_c__HoldPose_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  HoldPose_Result__rosidl_typesupport_introspection_c__HoldPose_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t HoldPose_Result__rosidl_typesupport_introspection_c__HoldPose_Result_message_type_support_handle = {
  0,
  &HoldPose_Result__rosidl_typesupport_introspection_c__HoldPose_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_Result)() {
  HoldPose_Result__rosidl_typesupport_introspection_c__HoldPose_Result_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!HoldPose_Result__rosidl_typesupport_introspection_c__HoldPose_Result_message_type_support_handle.typesupport_identifier) {
    HoldPose_Result__rosidl_typesupport_introspection_c__HoldPose_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &HoldPose_Result__rosidl_typesupport_introspection_c__HoldPose_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/hold_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/hold_pose__functions.h"
// already included above
// #include "trident_msgs/action/detail/hold_pose__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"
// Member `mean_pose_deviation`
// already included above
// #include "geometry_msgs/msg/pose.h"
// Member `mean_pose_deviation`
// already included above
// #include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void HoldPose_Feedback__rosidl_typesupport_introspection_c__HoldPose_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__HoldPose_Feedback__init(message_memory);
}

void HoldPose_Feedback__rosidl_typesupport_introspection_c__HoldPose_Feedback_fini_function(void * message_memory)
{
  trident_msgs__action__HoldPose_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember HoldPose_Feedback__rosidl_typesupport_introspection_c__HoldPose_Feedback_message_member_array[3] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__HoldPose_Feedback, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__HoldPose_Feedback, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mean_pose_deviation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__HoldPose_Feedback, mean_pose_deviation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers HoldPose_Feedback__rosidl_typesupport_introspection_c__HoldPose_Feedback_message_members = {
  "trident_msgs__action",  // message namespace
  "HoldPose_Feedback",  // message name
  3,  // number of fields
  sizeof(trident_msgs__action__HoldPose_Feedback),
  HoldPose_Feedback__rosidl_typesupport_introspection_c__HoldPose_Feedback_message_member_array,  // message members
  HoldPose_Feedback__rosidl_typesupport_introspection_c__HoldPose_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  HoldPose_Feedback__rosidl_typesupport_introspection_c__HoldPose_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t HoldPose_Feedback__rosidl_typesupport_introspection_c__HoldPose_Feedback_message_type_support_handle = {
  0,
  &HoldPose_Feedback__rosidl_typesupport_introspection_c__HoldPose_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_Feedback)() {
  HoldPose_Feedback__rosidl_typesupport_introspection_c__HoldPose_Feedback_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!HoldPose_Feedback__rosidl_typesupport_introspection_c__HoldPose_Feedback_message_type_support_handle.typesupport_identifier) {
    HoldPose_Feedback__rosidl_typesupport_introspection_c__HoldPose_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &HoldPose_Feedback__rosidl_typesupport_introspection_c__HoldPose_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/hold_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/hold_pose__functions.h"
// already included above
// #include "trident_msgs/action/detail/hold_pose__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "trident_msgs/action/hold_pose.h"
// Member `goal`
// already included above
// #include "trident_msgs/action/detail/hold_pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void HoldPose_SendGoal_Request__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__HoldPose_SendGoal_Request__init(message_memory);
}

void HoldPose_SendGoal_Request__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Request_fini_function(void * message_memory)
{
  trident_msgs__action__HoldPose_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember HoldPose_SendGoal_Request__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__HoldPose_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__HoldPose_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers HoldPose_SendGoal_Request__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Request_message_members = {
  "trident_msgs__action",  // message namespace
  "HoldPose_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(trident_msgs__action__HoldPose_SendGoal_Request),
  HoldPose_SendGoal_Request__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Request_message_member_array,  // message members
  HoldPose_SendGoal_Request__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  HoldPose_SendGoal_Request__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t HoldPose_SendGoal_Request__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Request_message_type_support_handle = {
  0,
  &HoldPose_SendGoal_Request__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_SendGoal_Request)() {
  HoldPose_SendGoal_Request__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  HoldPose_SendGoal_Request__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_Goal)();
  if (!HoldPose_SendGoal_Request__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    HoldPose_SendGoal_Request__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &HoldPose_SendGoal_Request__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/hold_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/hold_pose__functions.h"
// already included above
// #include "trident_msgs/action/detail/hold_pose__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void HoldPose_SendGoal_Response__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__HoldPose_SendGoal_Response__init(message_memory);
}

void HoldPose_SendGoal_Response__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Response_fini_function(void * message_memory)
{
  trident_msgs__action__HoldPose_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember HoldPose_SendGoal_Response__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__HoldPose_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__HoldPose_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers HoldPose_SendGoal_Response__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Response_message_members = {
  "trident_msgs__action",  // message namespace
  "HoldPose_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(trident_msgs__action__HoldPose_SendGoal_Response),
  HoldPose_SendGoal_Response__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Response_message_member_array,  // message members
  HoldPose_SendGoal_Response__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  HoldPose_SendGoal_Response__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t HoldPose_SendGoal_Response__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Response_message_type_support_handle = {
  0,
  &HoldPose_SendGoal_Response__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_SendGoal_Response)() {
  HoldPose_SendGoal_Response__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!HoldPose_SendGoal_Response__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    HoldPose_SendGoal_Response__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &HoldPose_SendGoal_Response__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "trident_msgs/action/detail/hold_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers trident_msgs__action__detail__hold_pose__rosidl_typesupport_introspection_c__HoldPose_SendGoal_service_members = {
  "trident_msgs__action",  // service namespace
  "HoldPose_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // trident_msgs__action__detail__hold_pose__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // trident_msgs__action__detail__hold_pose__rosidl_typesupport_introspection_c__HoldPose_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t trident_msgs__action__detail__hold_pose__rosidl_typesupport_introspection_c__HoldPose_SendGoal_service_type_support_handle = {
  0,
  &trident_msgs__action__detail__hold_pose__rosidl_typesupport_introspection_c__HoldPose_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_SendGoal)() {
  if (!trident_msgs__action__detail__hold_pose__rosidl_typesupport_introspection_c__HoldPose_SendGoal_service_type_support_handle.typesupport_identifier) {
    trident_msgs__action__detail__hold_pose__rosidl_typesupport_introspection_c__HoldPose_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)trident_msgs__action__detail__hold_pose__rosidl_typesupport_introspection_c__HoldPose_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_SendGoal_Response)()->data;
  }

  return &trident_msgs__action__detail__hold_pose__rosidl_typesupport_introspection_c__HoldPose_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/hold_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/hold_pose__functions.h"
// already included above
// #include "trident_msgs/action/detail/hold_pose__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void HoldPose_GetResult_Request__rosidl_typesupport_introspection_c__HoldPose_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__HoldPose_GetResult_Request__init(message_memory);
}

void HoldPose_GetResult_Request__rosidl_typesupport_introspection_c__HoldPose_GetResult_Request_fini_function(void * message_memory)
{
  trident_msgs__action__HoldPose_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember HoldPose_GetResult_Request__rosidl_typesupport_introspection_c__HoldPose_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__HoldPose_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers HoldPose_GetResult_Request__rosidl_typesupport_introspection_c__HoldPose_GetResult_Request_message_members = {
  "trident_msgs__action",  // message namespace
  "HoldPose_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(trident_msgs__action__HoldPose_GetResult_Request),
  HoldPose_GetResult_Request__rosidl_typesupport_introspection_c__HoldPose_GetResult_Request_message_member_array,  // message members
  HoldPose_GetResult_Request__rosidl_typesupport_introspection_c__HoldPose_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  HoldPose_GetResult_Request__rosidl_typesupport_introspection_c__HoldPose_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t HoldPose_GetResult_Request__rosidl_typesupport_introspection_c__HoldPose_GetResult_Request_message_type_support_handle = {
  0,
  &HoldPose_GetResult_Request__rosidl_typesupport_introspection_c__HoldPose_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_GetResult_Request)() {
  HoldPose_GetResult_Request__rosidl_typesupport_introspection_c__HoldPose_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!HoldPose_GetResult_Request__rosidl_typesupport_introspection_c__HoldPose_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    HoldPose_GetResult_Request__rosidl_typesupport_introspection_c__HoldPose_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &HoldPose_GetResult_Request__rosidl_typesupport_introspection_c__HoldPose_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/hold_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/hold_pose__functions.h"
// already included above
// #include "trident_msgs/action/detail/hold_pose__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "trident_msgs/action/hold_pose.h"
// Member `result`
// already included above
// #include "trident_msgs/action/detail/hold_pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void HoldPose_GetResult_Response__rosidl_typesupport_introspection_c__HoldPose_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__HoldPose_GetResult_Response__init(message_memory);
}

void HoldPose_GetResult_Response__rosidl_typesupport_introspection_c__HoldPose_GetResult_Response_fini_function(void * message_memory)
{
  trident_msgs__action__HoldPose_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember HoldPose_GetResult_Response__rosidl_typesupport_introspection_c__HoldPose_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__HoldPose_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__HoldPose_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers HoldPose_GetResult_Response__rosidl_typesupport_introspection_c__HoldPose_GetResult_Response_message_members = {
  "trident_msgs__action",  // message namespace
  "HoldPose_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(trident_msgs__action__HoldPose_GetResult_Response),
  HoldPose_GetResult_Response__rosidl_typesupport_introspection_c__HoldPose_GetResult_Response_message_member_array,  // message members
  HoldPose_GetResult_Response__rosidl_typesupport_introspection_c__HoldPose_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  HoldPose_GetResult_Response__rosidl_typesupport_introspection_c__HoldPose_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t HoldPose_GetResult_Response__rosidl_typesupport_introspection_c__HoldPose_GetResult_Response_message_type_support_handle = {
  0,
  &HoldPose_GetResult_Response__rosidl_typesupport_introspection_c__HoldPose_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_GetResult_Response)() {
  HoldPose_GetResult_Response__rosidl_typesupport_introspection_c__HoldPose_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_Result)();
  if (!HoldPose_GetResult_Response__rosidl_typesupport_introspection_c__HoldPose_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    HoldPose_GetResult_Response__rosidl_typesupport_introspection_c__HoldPose_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &HoldPose_GetResult_Response__rosidl_typesupport_introspection_c__HoldPose_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "trident_msgs/action/detail/hold_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers trident_msgs__action__detail__hold_pose__rosidl_typesupport_introspection_c__HoldPose_GetResult_service_members = {
  "trident_msgs__action",  // service namespace
  "HoldPose_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // trident_msgs__action__detail__hold_pose__rosidl_typesupport_introspection_c__HoldPose_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // trident_msgs__action__detail__hold_pose__rosidl_typesupport_introspection_c__HoldPose_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t trident_msgs__action__detail__hold_pose__rosidl_typesupport_introspection_c__HoldPose_GetResult_service_type_support_handle = {
  0,
  &trident_msgs__action__detail__hold_pose__rosidl_typesupport_introspection_c__HoldPose_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_GetResult)() {
  if (!trident_msgs__action__detail__hold_pose__rosidl_typesupport_introspection_c__HoldPose_GetResult_service_type_support_handle.typesupport_identifier) {
    trident_msgs__action__detail__hold_pose__rosidl_typesupport_introspection_c__HoldPose_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)trident_msgs__action__detail__hold_pose__rosidl_typesupport_introspection_c__HoldPose_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_GetResult_Response)()->data;
  }

  return &trident_msgs__action__detail__hold_pose__rosidl_typesupport_introspection_c__HoldPose_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/hold_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/hold_pose__functions.h"
// already included above
// #include "trident_msgs/action/detail/hold_pose__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "trident_msgs/action/hold_pose.h"
// Member `feedback`
// already included above
// #include "trident_msgs/action/detail/hold_pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void HoldPose_FeedbackMessage__rosidl_typesupport_introspection_c__HoldPose_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__HoldPose_FeedbackMessage__init(message_memory);
}

void HoldPose_FeedbackMessage__rosidl_typesupport_introspection_c__HoldPose_FeedbackMessage_fini_function(void * message_memory)
{
  trident_msgs__action__HoldPose_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember HoldPose_FeedbackMessage__rosidl_typesupport_introspection_c__HoldPose_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__HoldPose_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__HoldPose_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers HoldPose_FeedbackMessage__rosidl_typesupport_introspection_c__HoldPose_FeedbackMessage_message_members = {
  "trident_msgs__action",  // message namespace
  "HoldPose_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(trident_msgs__action__HoldPose_FeedbackMessage),
  HoldPose_FeedbackMessage__rosidl_typesupport_introspection_c__HoldPose_FeedbackMessage_message_member_array,  // message members
  HoldPose_FeedbackMessage__rosidl_typesupport_introspection_c__HoldPose_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  HoldPose_FeedbackMessage__rosidl_typesupport_introspection_c__HoldPose_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t HoldPose_FeedbackMessage__rosidl_typesupport_introspection_c__HoldPose_FeedbackMessage_message_type_support_handle = {
  0,
  &HoldPose_FeedbackMessage__rosidl_typesupport_introspection_c__HoldPose_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_FeedbackMessage)() {
  HoldPose_FeedbackMessage__rosidl_typesupport_introspection_c__HoldPose_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  HoldPose_FeedbackMessage__rosidl_typesupport_introspection_c__HoldPose_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, HoldPose_Feedback)();
  if (!HoldPose_FeedbackMessage__rosidl_typesupport_introspection_c__HoldPose_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    HoldPose_FeedbackMessage__rosidl_typesupport_introspection_c__HoldPose_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &HoldPose_FeedbackMessage__rosidl_typesupport_introspection_c__HoldPose_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
