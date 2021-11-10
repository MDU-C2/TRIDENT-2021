// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from trident_msgs:msg/MotorOutputs.idl
// generated code does not contain a copyright notice
#include "trident_msgs/msg/detail/motor_outputs__rosidl_typesupport_fastrtps_cpp.hpp"
#include "trident_msgs/msg/detail/motor_outputs__struct.hpp"

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
bool cdr_serialize(
  const trident_msgs::msg::MotorOutput &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  trident_msgs::msg::MotorOutput &);
size_t get_serialized_size(
  const trident_msgs::msg::MotorOutput &,
  size_t current_alignment);
size_t
max_serialized_size_MotorOutput(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace trident_msgs


namespace trident_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trident_msgs
cdr_serialize(
  const trident_msgs::msg::MotorOutputs & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: motor_outputs
  {
    size_t size = ros_message.motor_outputs.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      trident_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.motor_outputs[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trident_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  trident_msgs::msg::MotorOutputs & ros_message)
{
  // Member: motor_outputs
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.motor_outputs.resize(size);
    for (size_t i = 0; i < size; i++) {
      trident_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.motor_outputs[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trident_msgs
get_serialized_size(
  const trident_msgs::msg::MotorOutputs & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: motor_outputs
  {
    size_t array_size = ros_message.motor_outputs.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        trident_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.motor_outputs[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trident_msgs
max_serialized_size_MotorOutputs(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: motor_outputs
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        trident_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_MotorOutput(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _MotorOutputs__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const trident_msgs::msg::MotorOutputs *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MotorOutputs__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<trident_msgs::msg::MotorOutputs *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MotorOutputs__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const trident_msgs::msg::MotorOutputs *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MotorOutputs__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_MotorOutputs(full_bounded, 0);
}

static message_type_support_callbacks_t _MotorOutputs__callbacks = {
  "trident_msgs::msg",
  "MotorOutputs",
  _MotorOutputs__cdr_serialize,
  _MotorOutputs__cdr_deserialize,
  _MotorOutputs__get_serialized_size,
  _MotorOutputs__max_serialized_size
};

static rosidl_message_type_support_t _MotorOutputs__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MotorOutputs__callbacks,
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
get_message_type_support_handle<trident_msgs::msg::MotorOutputs>()
{
  return &trident_msgs::msg::typesupport_fastrtps_cpp::_MotorOutputs__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, trident_msgs, msg, MotorOutputs)() {
  return &trident_msgs::msg::typesupport_fastrtps_cpp::_MotorOutputs__handle;
}

#ifdef __cplusplus
}
#endif
