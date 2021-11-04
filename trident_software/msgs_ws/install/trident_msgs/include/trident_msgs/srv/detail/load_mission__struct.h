// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from trident_msgs:srv/LoadMission.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION__STRUCT_H_
#define TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'mission'
#include "trident_msgs/msg/detail/mission__struct.h"

// Struct defined in srv/LoadMission in the package trident_msgs.
typedef struct trident_msgs__srv__LoadMission_Request
{
  trident_msgs__msg__Mission mission;
} trident_msgs__srv__LoadMission_Request;

// Struct for a sequence of trident_msgs__srv__LoadMission_Request.
typedef struct trident_msgs__srv__LoadMission_Request__Sequence
{
  trident_msgs__srv__LoadMission_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__srv__LoadMission_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/LoadMission in the package trident_msgs.
typedef struct trident_msgs__srv__LoadMission_Response
{
  bool success;
  rosidl_runtime_c__String message;
} trident_msgs__srv__LoadMission_Response;

// Struct for a sequence of trident_msgs__srv__LoadMission_Response.
typedef struct trident_msgs__srv__LoadMission_Response__Sequence
{
  trident_msgs__srv__LoadMission_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__srv__LoadMission_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION__STRUCT_H_
