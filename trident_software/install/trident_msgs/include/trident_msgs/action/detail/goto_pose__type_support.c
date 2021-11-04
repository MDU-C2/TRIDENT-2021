// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from trident_msgs:action/GotoPose.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "trident_msgs/action/detail/goto_pose__rosidl_typesupport_introspection_c.h"
#include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "trident_msgs/action/detail/goto_pose__functions.h"
#include "trident_msgs/action/detail/goto_pose__struct.h"


// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/pose.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GotoPose_Goal__rosidl_typesupport_introspection_c__GotoPose_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__GotoPose_Goal__init(message_memory);
}

void GotoPose_Goal__rosidl_typesupport_introspection_c__GotoPose_Goal_fini_function(void * message_memory)
{
  trident_msgs__action__GotoPose_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GotoPose_Goal__rosidl_typesupport_introspection_c__GotoPose_Goal_message_member_array[1] = {
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__GotoPose_Goal, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GotoPose_Goal__rosidl_typesupport_introspection_c__GotoPose_Goal_message_members = {
  "trident_msgs__action",  // message namespace
  "GotoPose_Goal",  // message name
  1,  // number of fields
  sizeof(trident_msgs__action__GotoPose_Goal),
  GotoPose_Goal__rosidl_typesupport_introspection_c__GotoPose_Goal_message_member_array,  // message members
  GotoPose_Goal__rosidl_typesupport_introspection_c__GotoPose_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  GotoPose_Goal__rosidl_typesupport_introspection_c__GotoPose_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GotoPose_Goal__rosidl_typesupport_introspection_c__GotoPose_Goal_message_type_support_handle = {
  0,
  &GotoPose_Goal__rosidl_typesupport_introspection_c__GotoPose_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_Goal)() {
  GotoPose_Goal__rosidl_typesupport_introspection_c__GotoPose_Goal_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!GotoPose_Goal__rosidl_typesupport_introspection_c__GotoPose_Goal_message_type_support_handle.typesupport_identifier) {
    GotoPose_Goal__rosidl_typesupport_introspection_c__GotoPose_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GotoPose_Goal__rosidl_typesupport_introspection_c__GotoPose_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/goto_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/goto_pose__functions.h"
// already included above
// #include "trident_msgs/action/detail/goto_pose__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"
// Member `delta_pose`
// already included above
// #include "geometry_msgs/msg/pose.h"
// Member `delta_pose`
// already included above
// #include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GotoPose_Result__rosidl_typesupport_introspection_c__GotoPose_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__GotoPose_Result__init(message_memory);
}

void GotoPose_Result__rosidl_typesupport_introspection_c__GotoPose_Result_fini_function(void * message_memory)
{
  trident_msgs__action__GotoPose_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GotoPose_Result__rosidl_typesupport_introspection_c__GotoPose_Result_message_member_array[4] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__GotoPose_Result, status),  // bytes offset in struct
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
    offsetof(trident_msgs__action__GotoPose_Result, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "delta_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__GotoPose_Result, delta_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance_to_goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__GotoPose_Result, distance_to_goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GotoPose_Result__rosidl_typesupport_introspection_c__GotoPose_Result_message_members = {
  "trident_msgs__action",  // message namespace
  "GotoPose_Result",  // message name
  4,  // number of fields
  sizeof(trident_msgs__action__GotoPose_Result),
  GotoPose_Result__rosidl_typesupport_introspection_c__GotoPose_Result_message_member_array,  // message members
  GotoPose_Result__rosidl_typesupport_introspection_c__GotoPose_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  GotoPose_Result__rosidl_typesupport_introspection_c__GotoPose_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GotoPose_Result__rosidl_typesupport_introspection_c__GotoPose_Result_message_type_support_handle = {
  0,
  &GotoPose_Result__rosidl_typesupport_introspection_c__GotoPose_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_Result)() {
  GotoPose_Result__rosidl_typesupport_introspection_c__GotoPose_Result_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!GotoPose_Result__rosidl_typesupport_introspection_c__GotoPose_Result_message_type_support_handle.typesupport_identifier) {
    GotoPose_Result__rosidl_typesupport_introspection_c__GotoPose_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GotoPose_Result__rosidl_typesupport_introspection_c__GotoPose_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/goto_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/goto_pose__functions.h"
// already included above
// #include "trident_msgs/action/detail/goto_pose__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"
// Member `delta_pose`
// already included above
// #include "geometry_msgs/msg/pose.h"
// Member `delta_pose`
// already included above
// #include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GotoPose_Feedback__rosidl_typesupport_introspection_c__GotoPose_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__GotoPose_Feedback__init(message_memory);
}

void GotoPose_Feedback__rosidl_typesupport_introspection_c__GotoPose_Feedback_fini_function(void * message_memory)
{
  trident_msgs__action__GotoPose_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GotoPose_Feedback__rosidl_typesupport_introspection_c__GotoPose_Feedback_message_member_array[4] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__GotoPose_Feedback, status),  // bytes offset in struct
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
    offsetof(trident_msgs__action__GotoPose_Feedback, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "delta_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__GotoPose_Feedback, delta_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance_to_goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__GotoPose_Feedback, distance_to_goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GotoPose_Feedback__rosidl_typesupport_introspection_c__GotoPose_Feedback_message_members = {
  "trident_msgs__action",  // message namespace
  "GotoPose_Feedback",  // message name
  4,  // number of fields
  sizeof(trident_msgs__action__GotoPose_Feedback),
  GotoPose_Feedback__rosidl_typesupport_introspection_c__GotoPose_Feedback_message_member_array,  // message members
  GotoPose_Feedback__rosidl_typesupport_introspection_c__GotoPose_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  GotoPose_Feedback__rosidl_typesupport_introspection_c__GotoPose_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GotoPose_Feedback__rosidl_typesupport_introspection_c__GotoPose_Feedback_message_type_support_handle = {
  0,
  &GotoPose_Feedback__rosidl_typesupport_introspection_c__GotoPose_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_Feedback)() {
  GotoPose_Feedback__rosidl_typesupport_introspection_c__GotoPose_Feedback_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!GotoPose_Feedback__rosidl_typesupport_introspection_c__GotoPose_Feedback_message_type_support_handle.typesupport_identifier) {
    GotoPose_Feedback__rosidl_typesupport_introspection_c__GotoPose_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GotoPose_Feedback__rosidl_typesupport_introspection_c__GotoPose_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/goto_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/goto_pose__functions.h"
// already included above
// #include "trident_msgs/action/detail/goto_pose__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "trident_msgs/action/goto_pose.h"
// Member `goal`
// already included above
// #include "trident_msgs/action/detail/goto_pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GotoPose_SendGoal_Request__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__GotoPose_SendGoal_Request__init(message_memory);
}

void GotoPose_SendGoal_Request__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Request_fini_function(void * message_memory)
{
  trident_msgs__action__GotoPose_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GotoPose_SendGoal_Request__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__GotoPose_SendGoal_Request, goal_id),  // bytes offset in struct
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
    offsetof(trident_msgs__action__GotoPose_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GotoPose_SendGoal_Request__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Request_message_members = {
  "trident_msgs__action",  // message namespace
  "GotoPose_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(trident_msgs__action__GotoPose_SendGoal_Request),
  GotoPose_SendGoal_Request__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Request_message_member_array,  // message members
  GotoPose_SendGoal_Request__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  GotoPose_SendGoal_Request__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GotoPose_SendGoal_Request__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Request_message_type_support_handle = {
  0,
  &GotoPose_SendGoal_Request__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_SendGoal_Request)() {
  GotoPose_SendGoal_Request__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  GotoPose_SendGoal_Request__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_Goal)();
  if (!GotoPose_SendGoal_Request__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    GotoPose_SendGoal_Request__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GotoPose_SendGoal_Request__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/goto_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/goto_pose__functions.h"
// already included above
// #include "trident_msgs/action/detail/goto_pose__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GotoPose_SendGoal_Response__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__GotoPose_SendGoal_Response__init(message_memory);
}

void GotoPose_SendGoal_Response__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Response_fini_function(void * message_memory)
{
  trident_msgs__action__GotoPose_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GotoPose_SendGoal_Response__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__GotoPose_SendGoal_Response, accepted),  // bytes offset in struct
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
    offsetof(trident_msgs__action__GotoPose_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GotoPose_SendGoal_Response__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Response_message_members = {
  "trident_msgs__action",  // message namespace
  "GotoPose_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(trident_msgs__action__GotoPose_SendGoal_Response),
  GotoPose_SendGoal_Response__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Response_message_member_array,  // message members
  GotoPose_SendGoal_Response__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  GotoPose_SendGoal_Response__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GotoPose_SendGoal_Response__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Response_message_type_support_handle = {
  0,
  &GotoPose_SendGoal_Response__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_SendGoal_Response)() {
  GotoPose_SendGoal_Response__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!GotoPose_SendGoal_Response__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    GotoPose_SendGoal_Response__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GotoPose_SendGoal_Response__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "trident_msgs/action/detail/goto_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers trident_msgs__action__detail__goto_pose__rosidl_typesupport_introspection_c__GotoPose_SendGoal_service_members = {
  "trident_msgs__action",  // service namespace
  "GotoPose_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // trident_msgs__action__detail__goto_pose__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // trident_msgs__action__detail__goto_pose__rosidl_typesupport_introspection_c__GotoPose_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t trident_msgs__action__detail__goto_pose__rosidl_typesupport_introspection_c__GotoPose_SendGoal_service_type_support_handle = {
  0,
  &trident_msgs__action__detail__goto_pose__rosidl_typesupport_introspection_c__GotoPose_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_SendGoal)() {
  if (!trident_msgs__action__detail__goto_pose__rosidl_typesupport_introspection_c__GotoPose_SendGoal_service_type_support_handle.typesupport_identifier) {
    trident_msgs__action__detail__goto_pose__rosidl_typesupport_introspection_c__GotoPose_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)trident_msgs__action__detail__goto_pose__rosidl_typesupport_introspection_c__GotoPose_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_SendGoal_Response)()->data;
  }

  return &trident_msgs__action__detail__goto_pose__rosidl_typesupport_introspection_c__GotoPose_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/goto_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/goto_pose__functions.h"
// already included above
// #include "trident_msgs/action/detail/goto_pose__struct.h"


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

void GotoPose_GetResult_Request__rosidl_typesupport_introspection_c__GotoPose_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__GotoPose_GetResult_Request__init(message_memory);
}

void GotoPose_GetResult_Request__rosidl_typesupport_introspection_c__GotoPose_GetResult_Request_fini_function(void * message_memory)
{
  trident_msgs__action__GotoPose_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GotoPose_GetResult_Request__rosidl_typesupport_introspection_c__GotoPose_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__GotoPose_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GotoPose_GetResult_Request__rosidl_typesupport_introspection_c__GotoPose_GetResult_Request_message_members = {
  "trident_msgs__action",  // message namespace
  "GotoPose_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(trident_msgs__action__GotoPose_GetResult_Request),
  GotoPose_GetResult_Request__rosidl_typesupport_introspection_c__GotoPose_GetResult_Request_message_member_array,  // message members
  GotoPose_GetResult_Request__rosidl_typesupport_introspection_c__GotoPose_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  GotoPose_GetResult_Request__rosidl_typesupport_introspection_c__GotoPose_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GotoPose_GetResult_Request__rosidl_typesupport_introspection_c__GotoPose_GetResult_Request_message_type_support_handle = {
  0,
  &GotoPose_GetResult_Request__rosidl_typesupport_introspection_c__GotoPose_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_GetResult_Request)() {
  GotoPose_GetResult_Request__rosidl_typesupport_introspection_c__GotoPose_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!GotoPose_GetResult_Request__rosidl_typesupport_introspection_c__GotoPose_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    GotoPose_GetResult_Request__rosidl_typesupport_introspection_c__GotoPose_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GotoPose_GetResult_Request__rosidl_typesupport_introspection_c__GotoPose_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/goto_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/goto_pose__functions.h"
// already included above
// #include "trident_msgs/action/detail/goto_pose__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "trident_msgs/action/goto_pose.h"
// Member `result`
// already included above
// #include "trident_msgs/action/detail/goto_pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GotoPose_GetResult_Response__rosidl_typesupport_introspection_c__GotoPose_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__GotoPose_GetResult_Response__init(message_memory);
}

void GotoPose_GetResult_Response__rosidl_typesupport_introspection_c__GotoPose_GetResult_Response_fini_function(void * message_memory)
{
  trident_msgs__action__GotoPose_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GotoPose_GetResult_Response__rosidl_typesupport_introspection_c__GotoPose_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__GotoPose_GetResult_Response, status),  // bytes offset in struct
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
    offsetof(trident_msgs__action__GotoPose_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GotoPose_GetResult_Response__rosidl_typesupport_introspection_c__GotoPose_GetResult_Response_message_members = {
  "trident_msgs__action",  // message namespace
  "GotoPose_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(trident_msgs__action__GotoPose_GetResult_Response),
  GotoPose_GetResult_Response__rosidl_typesupport_introspection_c__GotoPose_GetResult_Response_message_member_array,  // message members
  GotoPose_GetResult_Response__rosidl_typesupport_introspection_c__GotoPose_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  GotoPose_GetResult_Response__rosidl_typesupport_introspection_c__GotoPose_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GotoPose_GetResult_Response__rosidl_typesupport_introspection_c__GotoPose_GetResult_Response_message_type_support_handle = {
  0,
  &GotoPose_GetResult_Response__rosidl_typesupport_introspection_c__GotoPose_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_GetResult_Response)() {
  GotoPose_GetResult_Response__rosidl_typesupport_introspection_c__GotoPose_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_Result)();
  if (!GotoPose_GetResult_Response__rosidl_typesupport_introspection_c__GotoPose_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    GotoPose_GetResult_Response__rosidl_typesupport_introspection_c__GotoPose_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GotoPose_GetResult_Response__rosidl_typesupport_introspection_c__GotoPose_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "trident_msgs/action/detail/goto_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers trident_msgs__action__detail__goto_pose__rosidl_typesupport_introspection_c__GotoPose_GetResult_service_members = {
  "trident_msgs__action",  // service namespace
  "GotoPose_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // trident_msgs__action__detail__goto_pose__rosidl_typesupport_introspection_c__GotoPose_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // trident_msgs__action__detail__goto_pose__rosidl_typesupport_introspection_c__GotoPose_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t trident_msgs__action__detail__goto_pose__rosidl_typesupport_introspection_c__GotoPose_GetResult_service_type_support_handle = {
  0,
  &trident_msgs__action__detail__goto_pose__rosidl_typesupport_introspection_c__GotoPose_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_GetResult)() {
  if (!trident_msgs__action__detail__goto_pose__rosidl_typesupport_introspection_c__GotoPose_GetResult_service_type_support_handle.typesupport_identifier) {
    trident_msgs__action__detail__goto_pose__rosidl_typesupport_introspection_c__GotoPose_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)trident_msgs__action__detail__goto_pose__rosidl_typesupport_introspection_c__GotoPose_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_GetResult_Response)()->data;
  }

  return &trident_msgs__action__detail__goto_pose__rosidl_typesupport_introspection_c__GotoPose_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/goto_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/goto_pose__functions.h"
// already included above
// #include "trident_msgs/action/detail/goto_pose__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "trident_msgs/action/goto_pose.h"
// Member `feedback`
// already included above
// #include "trident_msgs/action/detail/goto_pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GotoPose_FeedbackMessage__rosidl_typesupport_introspection_c__GotoPose_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__GotoPose_FeedbackMessage__init(message_memory);
}

void GotoPose_FeedbackMessage__rosidl_typesupport_introspection_c__GotoPose_FeedbackMessage_fini_function(void * message_memory)
{
  trident_msgs__action__GotoPose_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GotoPose_FeedbackMessage__rosidl_typesupport_introspection_c__GotoPose_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__GotoPose_FeedbackMessage, goal_id),  // bytes offset in struct
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
    offsetof(trident_msgs__action__GotoPose_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GotoPose_FeedbackMessage__rosidl_typesupport_introspection_c__GotoPose_FeedbackMessage_message_members = {
  "trident_msgs__action",  // message namespace
  "GotoPose_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(trident_msgs__action__GotoPose_FeedbackMessage),
  GotoPose_FeedbackMessage__rosidl_typesupport_introspection_c__GotoPose_FeedbackMessage_message_member_array,  // message members
  GotoPose_FeedbackMessage__rosidl_typesupport_introspection_c__GotoPose_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  GotoPose_FeedbackMessage__rosidl_typesupport_introspection_c__GotoPose_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GotoPose_FeedbackMessage__rosidl_typesupport_introspection_c__GotoPose_FeedbackMessage_message_type_support_handle = {
  0,
  &GotoPose_FeedbackMessage__rosidl_typesupport_introspection_c__GotoPose_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_FeedbackMessage)() {
  GotoPose_FeedbackMessage__rosidl_typesupport_introspection_c__GotoPose_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  GotoPose_FeedbackMessage__rosidl_typesupport_introspection_c__GotoPose_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoPose_Feedback)();
  if (!GotoPose_FeedbackMessage__rosidl_typesupport_introspection_c__GotoPose_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    GotoPose_FeedbackMessage__rosidl_typesupport_introspection_c__GotoPose_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GotoPose_FeedbackMessage__rosidl_typesupport_introspection_c__GotoPose_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
