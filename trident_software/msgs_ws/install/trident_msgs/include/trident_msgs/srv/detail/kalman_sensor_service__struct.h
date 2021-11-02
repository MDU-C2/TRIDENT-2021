// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from trident_msgs:srv/KalmanSensorService.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__SRV__DETAIL__KALMAN_SENSOR_SERVICE__STRUCT_H_
#define TRIDENT_MSGS__SRV__DETAIL__KALMAN_SENSOR_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'state'
// Member 'covar'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in srv/KalmanSensorService in the package trident_msgs.
typedef struct trident_msgs__srv__KalmanSensorService_Request
{
  rosidl_runtime_c__float__Sequence state;
  rosidl_runtime_c__float__Sequence covar;
} trident_msgs__srv__KalmanSensorService_Request;

// Struct for a sequence of trident_msgs__srv__KalmanSensorService_Request.
typedef struct trident_msgs__srv__KalmanSensorService_Request__Sequence
{
  trident_msgs__srv__KalmanSensorService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__srv__KalmanSensorService_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'residual'
// Member 'gain'
// Member 'observationmatrix'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in srv/KalmanSensorService in the package trident_msgs.
typedef struct trident_msgs__srv__KalmanSensorService_Response
{
  rosidl_runtime_c__float__Sequence residual;
  rosidl_runtime_c__float__Sequence gain;
  rosidl_runtime_c__float__Sequence observationmatrix;
} trident_msgs__srv__KalmanSensorService_Response;

// Struct for a sequence of trident_msgs__srv__KalmanSensorService_Response.
typedef struct trident_msgs__srv__KalmanSensorService_Response__Sequence
{
  trident_msgs__srv__KalmanSensorService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trident_msgs__srv__KalmanSensorService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRIDENT_MSGS__SRV__DETAIL__KALMAN_SENSOR_SERVICE__STRUCT_H_
