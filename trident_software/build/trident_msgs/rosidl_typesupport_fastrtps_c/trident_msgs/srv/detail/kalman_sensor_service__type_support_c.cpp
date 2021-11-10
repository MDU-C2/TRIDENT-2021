// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from trident_msgs:srv/KalmanSensorService.idl
// generated code does not contain a copyright notice
#include "trident_msgs/srv/detail/kalman_sensor_service__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "trident_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "trident_msgs/srv/detail/kalman_sensor_service__struct.h"
#include "trident_msgs/srv/detail/kalman_sensor_service__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // covar, state
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // covar, state

// forward declare type support functions


using _KalmanSensorService_Request__ros_msg_type = trident_msgs__srv__KalmanSensorService_Request;

static bool _KalmanSensorService_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _KalmanSensorService_Request__ros_msg_type * ros_message = static_cast<const _KalmanSensorService_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: state
  {
    size_t size = ros_message->state.size;
    auto array_ptr = ros_message->state.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: covar
  {
    size_t size = ros_message->covar.size;
    auto array_ptr = ros_message->covar.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _KalmanSensorService_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _KalmanSensorService_Request__ros_msg_type * ros_message = static_cast<_KalmanSensorService_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: state
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->state.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->state);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->state, size)) {
      return "failed to create array for field 'state'";
    }
    auto array_ptr = ros_message->state.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: covar
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->covar.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->covar);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->covar, size)) {
      return "failed to create array for field 'covar'";
    }
    auto array_ptr = ros_message->covar.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trident_msgs
size_t get_serialized_size_trident_msgs__srv__KalmanSensorService_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _KalmanSensorService_Request__ros_msg_type * ros_message = static_cast<const _KalmanSensorService_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name state
  {
    size_t array_size = ros_message->state.size;
    auto array_ptr = ros_message->state.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name covar
  {
    size_t array_size = ros_message->covar.size;
    auto array_ptr = ros_message->covar.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _KalmanSensorService_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_trident_msgs__srv__KalmanSensorService_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trident_msgs
size_t max_serialized_size_trident_msgs__srv__KalmanSensorService_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: state
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: covar
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _KalmanSensorService_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_trident_msgs__srv__KalmanSensorService_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_KalmanSensorService_Request = {
  "trident_msgs::srv",
  "KalmanSensorService_Request",
  _KalmanSensorService_Request__cdr_serialize,
  _KalmanSensorService_Request__cdr_deserialize,
  _KalmanSensorService_Request__get_serialized_size,
  _KalmanSensorService_Request__max_serialized_size
};

static rosidl_message_type_support_t _KalmanSensorService_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_KalmanSensorService_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trident_msgs, srv, KalmanSensorService_Request)() {
  return &_KalmanSensorService_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "trident_msgs/srv/detail/kalman_sensor_service__struct.h"
// already included above
// #include "trident_msgs/srv/detail/kalman_sensor_service__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"  // gain, observationmatrix, residual
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"  // gain, observationmatrix, residual

// forward declare type support functions


using _KalmanSensorService_Response__ros_msg_type = trident_msgs__srv__KalmanSensorService_Response;

static bool _KalmanSensorService_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _KalmanSensorService_Response__ros_msg_type * ros_message = static_cast<const _KalmanSensorService_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: residual
  {
    size_t size = ros_message->residual.size;
    auto array_ptr = ros_message->residual.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: gain
  {
    size_t size = ros_message->gain.size;
    auto array_ptr = ros_message->gain.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: observationmatrix
  {
    size_t size = ros_message->observationmatrix.size;
    auto array_ptr = ros_message->observationmatrix.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _KalmanSensorService_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _KalmanSensorService_Response__ros_msg_type * ros_message = static_cast<_KalmanSensorService_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: residual
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->residual.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->residual);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->residual, size)) {
      return "failed to create array for field 'residual'";
    }
    auto array_ptr = ros_message->residual.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: gain
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->gain.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->gain);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->gain, size)) {
      return "failed to create array for field 'gain'";
    }
    auto array_ptr = ros_message->gain.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: observationmatrix
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->observationmatrix.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->observationmatrix);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->observationmatrix, size)) {
      return "failed to create array for field 'observationmatrix'";
    }
    auto array_ptr = ros_message->observationmatrix.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trident_msgs
size_t get_serialized_size_trident_msgs__srv__KalmanSensorService_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _KalmanSensorService_Response__ros_msg_type * ros_message = static_cast<const _KalmanSensorService_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name residual
  {
    size_t array_size = ros_message->residual.size;
    auto array_ptr = ros_message->residual.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gain
  {
    size_t array_size = ros_message->gain.size;
    auto array_ptr = ros_message->gain.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name observationmatrix
  {
    size_t array_size = ros_message->observationmatrix.size;
    auto array_ptr = ros_message->observationmatrix.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _KalmanSensorService_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_trident_msgs__srv__KalmanSensorService_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trident_msgs
size_t max_serialized_size_trident_msgs__srv__KalmanSensorService_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: residual
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: gain
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: observationmatrix
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _KalmanSensorService_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_trident_msgs__srv__KalmanSensorService_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_KalmanSensorService_Response = {
  "trident_msgs::srv",
  "KalmanSensorService_Response",
  _KalmanSensorService_Response__cdr_serialize,
  _KalmanSensorService_Response__cdr_deserialize,
  _KalmanSensorService_Response__get_serialized_size,
  _KalmanSensorService_Response__max_serialized_size
};

static rosidl_message_type_support_t _KalmanSensorService_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_KalmanSensorService_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trident_msgs, srv, KalmanSensorService_Response)() {
  return &_KalmanSensorService_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "trident_msgs/srv/kalman_sensor_service.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t KalmanSensorService__callbacks = {
  "trident_msgs::srv",
  "KalmanSensorService",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trident_msgs, srv, KalmanSensorService_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trident_msgs, srv, KalmanSensorService_Response)(),
};

static rosidl_service_type_support_t KalmanSensorService__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &KalmanSensorService__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trident_msgs, srv, KalmanSensorService)() {
  return &KalmanSensorService__handle;
}

#if defined(__cplusplus)
}
#endif
