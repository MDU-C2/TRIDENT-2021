// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from trident_msgs:srv/KalmanSensorService.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "trident_msgs/srv/detail/kalman_sensor_service__rosidl_typesupport_introspection_c.h"
#include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "trident_msgs/srv/detail/kalman_sensor_service__functions.h"
#include "trident_msgs/srv/detail/kalman_sensor_service__struct.h"


// Include directives for member types
// Member `state`
// Member `covar`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void KalmanSensorService_Request__rosidl_typesupport_introspection_c__KalmanSensorService_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__srv__KalmanSensorService_Request__init(message_memory);
}

void KalmanSensorService_Request__rosidl_typesupport_introspection_c__KalmanSensorService_Request_fini_function(void * message_memory)
{
  trident_msgs__srv__KalmanSensorService_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember KalmanSensorService_Request__rosidl_typesupport_introspection_c__KalmanSensorService_Request_message_member_array[2] = {
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__srv__KalmanSensorService_Request, state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "covar",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__srv__KalmanSensorService_Request, covar),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers KalmanSensorService_Request__rosidl_typesupport_introspection_c__KalmanSensorService_Request_message_members = {
  "trident_msgs__srv",  // message namespace
  "KalmanSensorService_Request",  // message name
  2,  // number of fields
  sizeof(trident_msgs__srv__KalmanSensorService_Request),
  KalmanSensorService_Request__rosidl_typesupport_introspection_c__KalmanSensorService_Request_message_member_array,  // message members
  KalmanSensorService_Request__rosidl_typesupport_introspection_c__KalmanSensorService_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  KalmanSensorService_Request__rosidl_typesupport_introspection_c__KalmanSensorService_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t KalmanSensorService_Request__rosidl_typesupport_introspection_c__KalmanSensorService_Request_message_type_support_handle = {
  0,
  &KalmanSensorService_Request__rosidl_typesupport_introspection_c__KalmanSensorService_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, srv, KalmanSensorService_Request)() {
  if (!KalmanSensorService_Request__rosidl_typesupport_introspection_c__KalmanSensorService_Request_message_type_support_handle.typesupport_identifier) {
    KalmanSensorService_Request__rosidl_typesupport_introspection_c__KalmanSensorService_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &KalmanSensorService_Request__rosidl_typesupport_introspection_c__KalmanSensorService_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/srv/detail/kalman_sensor_service__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/srv/detail/kalman_sensor_service__functions.h"
// already included above
// #include "trident_msgs/srv/detail/kalman_sensor_service__struct.h"


// Include directives for member types
// Member `residual`
// Member `gain`
// Member `observationmatrix`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void KalmanSensorService_Response__rosidl_typesupport_introspection_c__KalmanSensorService_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__srv__KalmanSensorService_Response__init(message_memory);
}

void KalmanSensorService_Response__rosidl_typesupport_introspection_c__KalmanSensorService_Response_fini_function(void * message_memory)
{
  trident_msgs__srv__KalmanSensorService_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember KalmanSensorService_Response__rosidl_typesupport_introspection_c__KalmanSensorService_Response_message_member_array[3] = {
  {
    "residual",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__srv__KalmanSensorService_Response, residual),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gain",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__srv__KalmanSensorService_Response, gain),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "observationmatrix",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__srv__KalmanSensorService_Response, observationmatrix),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers KalmanSensorService_Response__rosidl_typesupport_introspection_c__KalmanSensorService_Response_message_members = {
  "trident_msgs__srv",  // message namespace
  "KalmanSensorService_Response",  // message name
  3,  // number of fields
  sizeof(trident_msgs__srv__KalmanSensorService_Response),
  KalmanSensorService_Response__rosidl_typesupport_introspection_c__KalmanSensorService_Response_message_member_array,  // message members
  KalmanSensorService_Response__rosidl_typesupport_introspection_c__KalmanSensorService_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  KalmanSensorService_Response__rosidl_typesupport_introspection_c__KalmanSensorService_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t KalmanSensorService_Response__rosidl_typesupport_introspection_c__KalmanSensorService_Response_message_type_support_handle = {
  0,
  &KalmanSensorService_Response__rosidl_typesupport_introspection_c__KalmanSensorService_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, srv, KalmanSensorService_Response)() {
  if (!KalmanSensorService_Response__rosidl_typesupport_introspection_c__KalmanSensorService_Response_message_type_support_handle.typesupport_identifier) {
    KalmanSensorService_Response__rosidl_typesupport_introspection_c__KalmanSensorService_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &KalmanSensorService_Response__rosidl_typesupport_introspection_c__KalmanSensorService_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "trident_msgs/srv/detail/kalman_sensor_service__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers trident_msgs__srv__detail__kalman_sensor_service__rosidl_typesupport_introspection_c__KalmanSensorService_service_members = {
  "trident_msgs__srv",  // service namespace
  "KalmanSensorService",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // trident_msgs__srv__detail__kalman_sensor_service__rosidl_typesupport_introspection_c__KalmanSensorService_Request_message_type_support_handle,
  NULL  // response message
  // trident_msgs__srv__detail__kalman_sensor_service__rosidl_typesupport_introspection_c__KalmanSensorService_Response_message_type_support_handle
};

static rosidl_service_type_support_t trident_msgs__srv__detail__kalman_sensor_service__rosidl_typesupport_introspection_c__KalmanSensorService_service_type_support_handle = {
  0,
  &trident_msgs__srv__detail__kalman_sensor_service__rosidl_typesupport_introspection_c__KalmanSensorService_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, srv, KalmanSensorService_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, srv, KalmanSensorService_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, srv, KalmanSensorService)() {
  if (!trident_msgs__srv__detail__kalman_sensor_service__rosidl_typesupport_introspection_c__KalmanSensorService_service_type_support_handle.typesupport_identifier) {
    trident_msgs__srv__detail__kalman_sensor_service__rosidl_typesupport_introspection_c__KalmanSensorService_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)trident_msgs__srv__detail__kalman_sensor_service__rosidl_typesupport_introspection_c__KalmanSensorService_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, srv, KalmanSensorService_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, srv, KalmanSensorService_Response)()->data;
  }

  return &trident_msgs__srv__detail__kalman_sensor_service__rosidl_typesupport_introspection_c__KalmanSensorService_service_type_support_handle;
}
