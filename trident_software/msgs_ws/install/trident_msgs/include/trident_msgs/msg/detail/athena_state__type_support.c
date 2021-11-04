// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from trident_msgs:msg/AthenaState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "trident_msgs/msg/detail/athena_state__rosidl_typesupport_introspection_c.h"
#include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "trident_msgs/msg/detail/athena_state__functions.h"
#include "trident_msgs/msg/detail/athena_state__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void AthenaState__rosidl_typesupport_introspection_c__AthenaState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__msg__AthenaState__init(message_memory);
}

void AthenaState__rosidl_typesupport_introspection_c__AthenaState_fini_function(void * message_memory)
{
  trident_msgs__msg__AthenaState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember AthenaState__rosidl_typesupport_introspection_c__AthenaState_message_member_array[6] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__msg__AthenaState, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__msg__AthenaState, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "heading",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__msg__AthenaState, heading),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velx",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__msg__AthenaState, velx),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vely",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__msg__AthenaState, vely),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velheading",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__msg__AthenaState, velheading),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers AthenaState__rosidl_typesupport_introspection_c__AthenaState_message_members = {
  "trident_msgs__msg",  // message namespace
  "AthenaState",  // message name
  6,  // number of fields
  sizeof(trident_msgs__msg__AthenaState),
  AthenaState__rosidl_typesupport_introspection_c__AthenaState_message_member_array,  // message members
  AthenaState__rosidl_typesupport_introspection_c__AthenaState_init_function,  // function to initialize message memory (memory has to be allocated)
  AthenaState__rosidl_typesupport_introspection_c__AthenaState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t AthenaState__rosidl_typesupport_introspection_c__AthenaState_message_type_support_handle = {
  0,
  &AthenaState__rosidl_typesupport_introspection_c__AthenaState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, msg, AthenaState)() {
  if (!AthenaState__rosidl_typesupport_introspection_c__AthenaState_message_type_support_handle.typesupport_identifier) {
    AthenaState__rosidl_typesupport_introspection_c__AthenaState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &AthenaState__rosidl_typesupport_introspection_c__AthenaState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
