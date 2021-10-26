// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from trident_msgs:srv/GuidanceRequest.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__SRV__DETAIL__GUIDANCE_REQUEST__STRUCT_H_
#define TRIDENT_MSGS__SRV__DETAIL__GUIDANCE_REQUEST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/GuidanceRequest in the package trident_msgs.
typedef struct trident_msgs__srv__GuidanceRequest_Request
{
  int64_t duration;
} trident_msgs__srv__GuidanceRequest_Request;

// Struct for a sequence of trident_msgs__srv__GuidanceRequest_Request.
typedef struct trident_msgs__srv__GuidanceRequest_Request__Sequence
{
  trident_msgs__srv__GuidanceRequest_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__srv__GuidanceRequest_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'reference_position'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'message'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/GuidanceRequest in the package trident_msgs.
typedef struct trident_msgs__srv__GuidanceRequest_Response
{
  bool accepted;
  geometry_msgs__msg__Point reference_position;
  rosidl_runtime_c__String message;
} trident_msgs__srv__GuidanceRequest_Response;

// Struct for a sequence of trident_msgs__srv__GuidanceRequest_Response.
typedef struct trident_msgs__srv__GuidanceRequest_Response__Sequence
{
  trident_msgs__srv__GuidanceRequest_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__srv__GuidanceRequest_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRIDENT_MSGS__SRV__DETAIL__GUIDANCE_REQUEST__STRUCT_H_
