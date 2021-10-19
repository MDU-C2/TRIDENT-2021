// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from trident_msgs:srv/LoadMissionPlan.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION_PLAN__STRUCT_H_
#define TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION_PLAN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'latitude'
// Member 'longitude'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in srv/LoadMissionPlan in the package trident_msgs.
typedef struct trident_msgs__srv__LoadMissionPlan_Request
{
  rosidl_runtime_c__float__Sequence latitude;
  rosidl_runtime_c__float__Sequence longitude;
} trident_msgs__srv__LoadMissionPlan_Request;

// Struct for a sequence of trident_msgs__srv__LoadMissionPlan_Request.
typedef struct trident_msgs__srv__LoadMissionPlan_Request__Sequence
{
  trident_msgs__srv__LoadMissionPlan_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__srv__LoadMissionPlan_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/LoadMissionPlan in the package trident_msgs.
typedef struct trident_msgs__srv__LoadMissionPlan_Response
{
  int8_t status;
} trident_msgs__srv__LoadMissionPlan_Response;

// Struct for a sequence of trident_msgs__srv__LoadMissionPlan_Response.
typedef struct trident_msgs__srv__LoadMissionPlan_Response__Sequence
{
  trident_msgs__srv__LoadMissionPlan_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__srv__LoadMissionPlan_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION_PLAN__STRUCT_H_
