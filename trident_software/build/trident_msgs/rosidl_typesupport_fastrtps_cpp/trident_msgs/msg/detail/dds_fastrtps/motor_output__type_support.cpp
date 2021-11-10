// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from trident_msgs:msg/MotorOutput.idl
// generated code does not contain a copyright notice
#include "trident_msgs/msg/detail/motor_output__rosidl_typesupport_fastrtps_cpp.hpp"
#include "trident_msgs/msg/detail/motor_output__struct.hpp"

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

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trident_msgs
cdr_serialize(
  const trident_msgs::msg::MotorOutput & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: id
  cdr << ros_message.id;
  // Member: value
  cdr << ros_message.value;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trident_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  trident_msgs::msg::MotorOutput & ros_message)
{
  // Member: id
  cdr >> ros_message.id;

  // Member: value
  cdr >> ros_message.value;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trident_msgs
get_serialized_size(
  const trident_msgs::msg::MotorOutput & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: id
  {
    size_t item_size = sizeof(ros_message.id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: value
  {
    size_t item_size = sizeof(ros_message.value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trident_msgs
max_serialized_size_MotorOutput(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: id
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: value
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _MotorOutput__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const trident_msgs::msg::MotorOutput *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MotorOutput__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<trident_msgs::msg::MotorOutput *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MotorOutput__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const trident_msgs::msg::MotorOutput *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MotorOutput__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_MotorOutput(full_bounded, 0);
}

static message_type_support_callbacks_t _MotorOutput__callbacks = {
  "trident_msgs::msg",
  "MotorOutput",
  _MotorOutput__cdr_serialize,
  _MotorOutput__cdr_deserialize,
  _MotorOutput__get_serialized_size,
  _MotorOutput__max_serialized_size
};

static rosidl_message_type_support_t _MotorOutput__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MotorOutput__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace trident_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_trident_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<trident_msgs::msg::MotorOutput>()
{
  return &trident_msgs::msg::typesupport_fastrtps_cpp::_MotorOutput__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, trident_msgs, msg, MotorOutput)() {
  return &trident_msgs::msg::typesupport_fastrtps_cpp::_MotorOutput__handle;
}

#ifdef __cplusplus
}
#endif
