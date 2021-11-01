// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from trident_msgs:srv/GetState.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__SRV__DETAIL__GET_STATE__STRUCT_H_
#define TRIDENT_MSGS__SRV__DETAIL__GET_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/GetState in the package trident_msgs.
typedef struct trident_msgs__srv__GetState_Request
{
  uint8_t structure_needs_at_least_one_member;
} trident_msgs__srv__GetState_Request;

// Struct for a sequence of trident_msgs__srv__GetState_Request.
typedef struct trident_msgs__srv__GetState_Request__Sequence
{
  trident_msgs__srv__GetState_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__srv__GetState_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'state'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/GetState in the package trident_msgs.
typedef struct trident_msgs__srv__GetState_Response
{
  bool success;
  rosidl_runtime_c__String state;
  int64_t int_state;
} trident_msgs__srv__GetState_Response;

// Struct for a sequence of trident_msgs__srv__GetState_Response.
typedef struct trident_msgs__srv__GetState_Response__Sequence
{
  trident_msgs__srv__GetState_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__srv__GetState_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRIDENT_MSGS__SRV__DETAIL__GET_STATE__STRUCT_H_
