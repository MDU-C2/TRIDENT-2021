// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from trident_msgs:action/GotoWaypoint.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "trident_msgs/action/detail/goto_waypoint__rosidl_typesupport_introspection_c.h"
#include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "trident_msgs/action/detail/goto_waypoint__functions.h"
#include "trident_msgs/action/detail/goto_waypoint__struct.h"


// Include directives for member types
// Member `waypoint`
#include "trident_msgs/msg/waypoint.h"
// Member `waypoint`
#include "trident_msgs/msg/detail/waypoint__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GotoWaypoint_Goal__rosidl_typesupport_introspection_c__GotoWaypoint_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__GotoWaypoint_Goal__init(message_memory);
}

void GotoWaypoint_Goal__rosidl_typesupport_introspection_c__GotoWaypoint_Goal_fini_function(void * message_memory)
{
  trident_msgs__action__GotoWaypoint_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GotoWaypoint_Goal__rosidl_typesupport_introspection_c__GotoWaypoint_Goal_message_member_array[1] = {
  {
    "waypoint",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__GotoWaypoint_Goal, waypoint),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GotoWaypoint_Goal__rosidl_typesupport_introspection_c__GotoWaypoint_Goal_message_members = {
  "trident_msgs__action",  // message namespace
  "GotoWaypoint_Goal",  // message name
  1,  // number of fields
  sizeof(trident_msgs__action__GotoWaypoint_Goal),
  GotoWaypoint_Goal__rosidl_typesupport_introspection_c__GotoWaypoint_Goal_message_member_array,  // message members
  GotoWaypoint_Goal__rosidl_typesupport_introspection_c__GotoWaypoint_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  GotoWaypoint_Goal__rosidl_typesupport_introspection_c__GotoWaypoint_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GotoWaypoint_Goal__rosidl_typesupport_introspection_c__GotoWaypoint_Goal_message_type_support_handle = {
  0,
  &GotoWaypoint_Goal__rosidl_typesupport_introspection_c__GotoWaypoint_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_Goal)() {
  GotoWaypoint_Goal__rosidl_typesupport_introspection_c__GotoWaypoint_Goal_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, msg, Waypoint)();
  if (!GotoWaypoint_Goal__rosidl_typesupport_introspection_c__GotoWaypoint_Goal_message_type_support_handle.typesupport_identifier) {
    GotoWaypoint_Goal__rosidl_typesupport_introspection_c__GotoWaypoint_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GotoWaypoint_Goal__rosidl_typesupport_introspection_c__GotoWaypoint_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__functions.h"
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GotoWaypoint_Result__rosidl_typesupport_introspection_c__GotoWaypoint_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__GotoWaypoint_Result__init(message_memory);
}

void GotoWaypoint_Result__rosidl_typesupport_introspection_c__GotoWaypoint_Result_fini_function(void * message_memory)
{
  trident_msgs__action__GotoWaypoint_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GotoWaypoint_Result__rosidl_typesupport_introspection_c__GotoWaypoint_Result_message_member_array[3] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__GotoWaypoint_Result, status),  // bytes offset in struct
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
    offsetof(trident_msgs__action__GotoWaypoint_Result, message),  // bytes offset in struct
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
    offsetof(trident_msgs__action__GotoWaypoint_Result, distance_to_goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GotoWaypoint_Result__rosidl_typesupport_introspection_c__GotoWaypoint_Result_message_members = {
  "trident_msgs__action",  // message namespace
  "GotoWaypoint_Result",  // message name
  3,  // number of fields
  sizeof(trident_msgs__action__GotoWaypoint_Result),
  GotoWaypoint_Result__rosidl_typesupport_introspection_c__GotoWaypoint_Result_message_member_array,  // message members
  GotoWaypoint_Result__rosidl_typesupport_introspection_c__GotoWaypoint_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  GotoWaypoint_Result__rosidl_typesupport_introspection_c__GotoWaypoint_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GotoWaypoint_Result__rosidl_typesupport_introspection_c__GotoWaypoint_Result_message_type_support_handle = {
  0,
  &GotoWaypoint_Result__rosidl_typesupport_introspection_c__GotoWaypoint_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_Result)() {
  if (!GotoWaypoint_Result__rosidl_typesupport_introspection_c__GotoWaypoint_Result_message_type_support_handle.typesupport_identifier) {
    GotoWaypoint_Result__rosidl_typesupport_introspection_c__GotoWaypoint_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GotoWaypoint_Result__rosidl_typesupport_introspection_c__GotoWaypoint_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__functions.h"
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GotoWaypoint_Feedback__rosidl_typesupport_introspection_c__GotoWaypoint_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__GotoWaypoint_Feedback__init(message_memory);
}

void GotoWaypoint_Feedback__rosidl_typesupport_introspection_c__GotoWaypoint_Feedback_fini_function(void * message_memory)
{
  trident_msgs__action__GotoWaypoint_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GotoWaypoint_Feedback__rosidl_typesupport_introspection_c__GotoWaypoint_Feedback_message_member_array[3] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__GotoWaypoint_Feedback, status),  // bytes offset in struct
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
    offsetof(trident_msgs__action__GotoWaypoint_Feedback, message),  // bytes offset in struct
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
    offsetof(trident_msgs__action__GotoWaypoint_Feedback, distance_to_goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GotoWaypoint_Feedback__rosidl_typesupport_introspection_c__GotoWaypoint_Feedback_message_members = {
  "trident_msgs__action",  // message namespace
  "GotoWaypoint_Feedback",  // message name
  3,  // number of fields
  sizeof(trident_msgs__action__GotoWaypoint_Feedback),
  GotoWaypoint_Feedback__rosidl_typesupport_introspection_c__GotoWaypoint_Feedback_message_member_array,  // message members
  GotoWaypoint_Feedback__rosidl_typesupport_introspection_c__GotoWaypoint_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  GotoWaypoint_Feedback__rosidl_typesupport_introspection_c__GotoWaypoint_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GotoWaypoint_Feedback__rosidl_typesupport_introspection_c__GotoWaypoint_Feedback_message_type_support_handle = {
  0,
  &GotoWaypoint_Feedback__rosidl_typesupport_introspection_c__GotoWaypoint_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_Feedback)() {
  if (!GotoWaypoint_Feedback__rosidl_typesupport_introspection_c__GotoWaypoint_Feedback_message_type_support_handle.typesupport_identifier) {
    GotoWaypoint_Feedback__rosidl_typesupport_introspection_c__GotoWaypoint_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GotoWaypoint_Feedback__rosidl_typesupport_introspection_c__GotoWaypoint_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__functions.h"
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "trident_msgs/action/goto_waypoint.h"
// Member `goal`
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GotoWaypoint_SendGoal_Request__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__GotoWaypoint_SendGoal_Request__init(message_memory);
}

void GotoWaypoint_SendGoal_Request__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Request_fini_function(void * message_memory)
{
  trident_msgs__action__GotoWaypoint_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GotoWaypoint_SendGoal_Request__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__GotoWaypoint_SendGoal_Request, goal_id),  // bytes offset in struct
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
    offsetof(trident_msgs__action__GotoWaypoint_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GotoWaypoint_SendGoal_Request__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Request_message_members = {
  "trident_msgs__action",  // message namespace
  "GotoWaypoint_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(trident_msgs__action__GotoWaypoint_SendGoal_Request),
  GotoWaypoint_SendGoal_Request__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Request_message_member_array,  // message members
  GotoWaypoint_SendGoal_Request__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  GotoWaypoint_SendGoal_Request__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GotoWaypoint_SendGoal_Request__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Request_message_type_support_handle = {
  0,
  &GotoWaypoint_SendGoal_Request__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_SendGoal_Request)() {
  GotoWaypoint_SendGoal_Request__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  GotoWaypoint_SendGoal_Request__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_Goal)();
  if (!GotoWaypoint_SendGoal_Request__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    GotoWaypoint_SendGoal_Request__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GotoWaypoint_SendGoal_Request__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__functions.h"
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GotoWaypoint_SendGoal_Response__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__GotoWaypoint_SendGoal_Response__init(message_memory);
}

void GotoWaypoint_SendGoal_Response__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Response_fini_function(void * message_memory)
{
  trident_msgs__action__GotoWaypoint_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GotoWaypoint_SendGoal_Response__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__GotoWaypoint_SendGoal_Response, accepted),  // bytes offset in struct
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
    offsetof(trident_msgs__action__GotoWaypoint_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GotoWaypoint_SendGoal_Response__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Response_message_members = {
  "trident_msgs__action",  // message namespace
  "GotoWaypoint_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(trident_msgs__action__GotoWaypoint_SendGoal_Response),
  GotoWaypoint_SendGoal_Response__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Response_message_member_array,  // message members
  GotoWaypoint_SendGoal_Response__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  GotoWaypoint_SendGoal_Response__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GotoWaypoint_SendGoal_Response__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Response_message_type_support_handle = {
  0,
  &GotoWaypoint_SendGoal_Response__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_SendGoal_Response)() {
  GotoWaypoint_SendGoal_Response__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!GotoWaypoint_SendGoal_Response__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    GotoWaypoint_SendGoal_Response__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GotoWaypoint_SendGoal_Response__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers trident_msgs__action__detail__goto_waypoint__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_service_members = {
  "trident_msgs__action",  // service namespace
  "GotoWaypoint_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // trident_msgs__action__detail__goto_waypoint__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // trident_msgs__action__detail__goto_waypoint__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t trident_msgs__action__detail__goto_waypoint__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_service_type_support_handle = {
  0,
  &trident_msgs__action__detail__goto_waypoint__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_SendGoal)() {
  if (!trident_msgs__action__detail__goto_waypoint__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_service_type_support_handle.typesupport_identifier) {
    trident_msgs__action__detail__goto_waypoint__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)trident_msgs__action__detail__goto_waypoint__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_SendGoal_Response)()->data;
  }

  return &trident_msgs__action__detail__goto_waypoint__rosidl_typesupport_introspection_c__GotoWaypoint_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__functions.h"
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__struct.h"


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

void GotoWaypoint_GetResult_Request__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__GotoWaypoint_GetResult_Request__init(message_memory);
}

void GotoWaypoint_GetResult_Request__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Request_fini_function(void * message_memory)
{
  trident_msgs__action__GotoWaypoint_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GotoWaypoint_GetResult_Request__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__GotoWaypoint_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GotoWaypoint_GetResult_Request__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Request_message_members = {
  "trident_msgs__action",  // message namespace
  "GotoWaypoint_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(trident_msgs__action__GotoWaypoint_GetResult_Request),
  GotoWaypoint_GetResult_Request__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Request_message_member_array,  // message members
  GotoWaypoint_GetResult_Request__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  GotoWaypoint_GetResult_Request__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GotoWaypoint_GetResult_Request__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Request_message_type_support_handle = {
  0,
  &GotoWaypoint_GetResult_Request__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_GetResult_Request)() {
  GotoWaypoint_GetResult_Request__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!GotoWaypoint_GetResult_Request__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    GotoWaypoint_GetResult_Request__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GotoWaypoint_GetResult_Request__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__functions.h"
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "trident_msgs/action/goto_waypoint.h"
// Member `result`
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GotoWaypoint_GetResult_Response__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__GotoWaypoint_GetResult_Response__init(message_memory);
}

void GotoWaypoint_GetResult_Response__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Response_fini_function(void * message_memory)
{
  trident_msgs__action__GotoWaypoint_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GotoWaypoint_GetResult_Response__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__GotoWaypoint_GetResult_Response, status),  // bytes offset in struct
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
    offsetof(trident_msgs__action__GotoWaypoint_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GotoWaypoint_GetResult_Response__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Response_message_members = {
  "trident_msgs__action",  // message namespace
  "GotoWaypoint_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(trident_msgs__action__GotoWaypoint_GetResult_Response),
  GotoWaypoint_GetResult_Response__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Response_message_member_array,  // message members
  GotoWaypoint_GetResult_Response__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  GotoWaypoint_GetResult_Response__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GotoWaypoint_GetResult_Response__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Response_message_type_support_handle = {
  0,
  &GotoWaypoint_GetResult_Response__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_GetResult_Response)() {
  GotoWaypoint_GetResult_Response__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_Result)();
  if (!GotoWaypoint_GetResult_Response__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    GotoWaypoint_GetResult_Response__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GotoWaypoint_GetResult_Response__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers trident_msgs__action__detail__goto_waypoint__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_service_members = {
  "trident_msgs__action",  // service namespace
  "GotoWaypoint_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // trident_msgs__action__detail__goto_waypoint__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // trident_msgs__action__detail__goto_waypoint__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t trident_msgs__action__detail__goto_waypoint__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_service_type_support_handle = {
  0,
  &trident_msgs__action__detail__goto_waypoint__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_GetResult)() {
  if (!trident_msgs__action__detail__goto_waypoint__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_service_type_support_handle.typesupport_identifier) {
    trident_msgs__action__detail__goto_waypoint__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)trident_msgs__action__detail__goto_waypoint__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_GetResult_Response)()->data;
  }

  return &trident_msgs__action__detail__goto_waypoint__rosidl_typesupport_introspection_c__GotoWaypoint_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__functions.h"
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "trident_msgs/action/goto_waypoint.h"
// Member `feedback`
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GotoWaypoint_FeedbackMessage__rosidl_typesupport_introspection_c__GotoWaypoint_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__GotoWaypoint_FeedbackMessage__init(message_memory);
}

void GotoWaypoint_FeedbackMessage__rosidl_typesupport_introspection_c__GotoWaypoint_FeedbackMessage_fini_function(void * message_memory)
{
  trident_msgs__action__GotoWaypoint_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GotoWaypoint_FeedbackMessage__rosidl_typesupport_introspection_c__GotoWaypoint_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__GotoWaypoint_FeedbackMessage, goal_id),  // bytes offset in struct
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
    offsetof(trident_msgs__action__GotoWaypoint_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GotoWaypoint_FeedbackMessage__rosidl_typesupport_introspection_c__GotoWaypoint_FeedbackMessage_message_members = {
  "trident_msgs__action",  // message namespace
  "GotoWaypoint_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(trident_msgs__action__GotoWaypoint_FeedbackMessage),
  GotoWaypoint_FeedbackMessage__rosidl_typesupport_introspection_c__GotoWaypoint_FeedbackMessage_message_member_array,  // message members
  GotoWaypoint_FeedbackMessage__rosidl_typesupport_introspection_c__GotoWaypoint_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  GotoWaypoint_FeedbackMessage__rosidl_typesupport_introspection_c__GotoWaypoint_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GotoWaypoint_FeedbackMessage__rosidl_typesupport_introspection_c__GotoWaypoint_FeedbackMessage_message_type_support_handle = {
  0,
  &GotoWaypoint_FeedbackMessage__rosidl_typesupport_introspection_c__GotoWaypoint_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_FeedbackMessage)() {
  GotoWaypoint_FeedbackMessage__rosidl_typesupport_introspection_c__GotoWaypoint_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  GotoWaypoint_FeedbackMessage__rosidl_typesupport_introspection_c__GotoWaypoint_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, GotoWaypoint_Feedback)();
  if (!GotoWaypoint_FeedbackMessage__rosidl_typesupport_introspection_c__GotoWaypoint_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    GotoWaypoint_FeedbackMessage__rosidl_typesupport_introspection_c__GotoWaypoint_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GotoWaypoint_FeedbackMessage__rosidl_typesupport_introspection_c__GotoWaypoint_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
