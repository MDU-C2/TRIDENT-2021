// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from trident_msgs:srv/KalmanSensorService.idl
// generated code does not contain a copyright notice
#include "trident_msgs/srv/detail/kalman_sensor_service__rosidl_typesupport_fastrtps_cpp.hpp"
#include "trident_msgs/srv/detail/kalman_sensor_service__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace trident_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trident_msgs
cdr_serialize(
  const trident_msgs::srv::KalmanSensorService_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: state
  {
    cdr << ros_message.state;
  }
  // Member: covar
  {
    cdr << ros_message.covar;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trident_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  trident_msgs::srv::KalmanSensorService_Request & ros_message)
{
  // Member: state
  {
    cdr >> ros_message.state;
  }

  // Member: covar
  {
    cdr >> ros_message.covar;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trident_msgs
get_serialized_size(
  const trident_msgs::srv::KalmanSensorService_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: state
  {
    size_t array_size = ros_message.state.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.state[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: covar
  {
    size_t array_size = ros_message.covar.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.covar[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trident_msgs
max_serialized_size_KalmanSensorService_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: state
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: covar
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

static bool _KalmanSensorService_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const trident_msgs::srv::KalmanSensorService_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _KalmanSensorService_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<trident_msgs::srv::KalmanSensorService_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _KalmanSensorService_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const trident_msgs::srv::KalmanSensorService_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _KalmanSensorService_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_KalmanSensorService_Request(full_bounded, 0);
}

static message_type_support_callbacks_t _KalmanSensorService_Request__callbacks = {
  "trident_msgs::srv",
  "KalmanSensorService_Request",
  _KalmanSensorService_Request__cdr_serialize,
  _KalmanSensorService_Request__cdr_deserialize,
  _KalmanSensorService_Request__get_serialized_size,
  _KalmanSensorService_Request__max_serialized_size
};

static rosidl_message_type_support_t _KalmanSensorService_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_KalmanSensorService_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace trident_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_trident_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<trident_msgs::srv::KalmanSensorService_Request>()
{
  return &trident_msgs::srv::typesupport_fastrtps_cpp::_KalmanSensorService_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, trident_msgs, srv, KalmanSensorService_Request)() {
  return &trident_msgs::srv::typesupport_fastrtps_cpp::_KalmanSensorService_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace trident_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trident_msgs
cdr_serialize(
  const trident_msgs::srv::KalmanSensorService_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: residual
  {
    cdr << ros_message.residual;
  }
  // Member: gain
  {
    cdr << ros_message.gain;
  }
  // Member: observationmatrix
  {
    cdr << ros_message.observationmatrix;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trident_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  trident_msgs::srv::KalmanSensorService_Response & ros_message)
{
  // Member: residual
  {
    cdr >> ros_message.residual;
  }

  // Member: gain
  {
    cdr >> ros_message.gain;
  }

  // Member: observationmatrix
  {
    cdr >> ros_message.observationmatrix;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trident_msgs
get_serialized_size(
  const trident_msgs::srv::KalmanSensorService_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: residual
  {
    size_t array_size = ros_message.residual.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.residual[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gain
  {
    size_t array_size = ros_message.gain.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.gain[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: observationmatrix
  {
    size_t array_size = ros_message.observationmatrix.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.observationmatrix[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trident_msgs
max_serialized_size_KalmanSensorService_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: residual
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: gain
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: observationmatrix
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

static bool _KalmanSensorService_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const trident_msgs::srv::KalmanSensorService_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _KalmanSensorService_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<trident_msgs::srv::KalmanSensorService_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _KalmanSensorService_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const trident_msgs::srv::KalmanSensorService_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _KalmanSensorService_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_KalmanSensorService_Response(full_bounded, 0);
}

static message_type_support_callbacks_t _KalmanSensorService_Response__callbacks = {
  "trident_msgs::srv",
  "KalmanSensorService_Response",
  _KalmanSensorService_Response__cdr_serialize,
  _KalmanSensorService_Response__cdr_deserialize,
  _KalmanSensorService_Response__get_serialized_size,
  _KalmanSensorService_Response__max_serialized_size
};

static rosidl_message_type_support_t _KalmanSensorService_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_KalmanSensorService_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace trident_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_trident_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<trident_msgs::srv::KalmanSensorService_Response>()
{
  return &trident_msgs::srv::typesupport_fastrtps_cpp::_KalmanSensorService_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, trident_msgs, srv, KalmanSensorService_Response)() {
  return &trident_msgs::srv::typesupport_fastrtps_cpp::_KalmanSensorService_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace trident_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _KalmanSensorService__callbacks = {
  "trident_msgs::srv",
  "KalmanSensorService",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, trident_msgs, srv, KalmanSensorService_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, trident_msgs, srv, KalmanSensorService_Response)(),
};

static rosidl_service_type_support_t _KalmanSensorService__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_KalmanSensorService__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace trident_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_trident_msgs
const rosidl_service_type_support_t *
get_service_type_support_handle<trident_msgs::srv::KalmanSensorService>()
{
  return &trident_msgs::srv::typesupport_fastrtps_cpp::_KalmanSensorService__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, trident_msgs, srv, KalmanSensorService)() {
  return &trident_msgs::srv::typesupport_fastrtps_cpp::_KalmanSensorService__handle;
}

#ifdef __cplusplus
}
#endif
