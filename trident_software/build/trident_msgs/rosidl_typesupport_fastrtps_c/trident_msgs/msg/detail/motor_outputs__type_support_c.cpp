// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from trident_msgs:msg/MotorOutputs.idl
// generated code does not contain a copyright notice
#include "trident_msgs/msg/detail/motor_outputs__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "trident_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "trident_msgs/msg/detail/motor_outputs__struct.h"
#include "trident_msgs/msg/detail/motor_outputs__functions.h"
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

#include "trident_msgs/msg/detail/motor_output__functions.h"  // motor_outputs

// forward declare type support functions
size_t get_serialized_size_trident_msgs__msg__MotorOutput(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_trident_msgs__msg__MotorOutput(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trident_msgs, msg, MotorOutput)();


using _MotorOutputs__ros_msg_type = trident_msgs__msg__MotorOutputs;

static bool _MotorOutputs__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MotorOutputs__ros_msg_type * ros_message = static_cast<const _MotorOutputs__ros_msg_type *>(untyped_ros_message);
  // Field name: motor_outputs
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, trident_msgs, msg, MotorOutput
      )()->data);
    size_t size = ros_message->motor_outputs.size;
    auto array_ptr = ros_message->motor_outputs.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _MotorOutputs__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MotorOutputs__ros_msg_type * ros_message = static_cast<_MotorOutputs__ros_msg_type *>(untyped_ros_message);
  // Field name: motor_outputs
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, trident_msgs, msg, MotorOutput
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->motor_outputs.data) {
      trident_msgs__msg__MotorOutput__Sequence__fini(&ros_message->motor_outputs);
    }
    if (!trident_msgs__msg__MotorOutput__Sequence__init(&ros_message->motor_outputs, size)) {
      return "failed to create array for field 'motor_outputs'";
    }
    auto array_ptr = ros_message->motor_outputs.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trident_msgs
size_t get_serialized_size_trident_msgs__msg__MotorOutputs(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MotorOutputs__ros_msg_type * ros_message = static_cast<const _MotorOutputs__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name motor_outputs
  {
    size_t array_size = ros_message->motor_outputs.size;
    auto array_ptr = ros_message->motor_outputs.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_trident_msgs__msg__MotorOutput(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MotorOutputs__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_trident_msgs__msg__MotorOutputs(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_trident_msgs
size_t max_serialized_size_trident_msgs__msg__MotorOutputs(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: motor_outputs
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_trident_msgs__msg__MotorOutput(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _MotorOutputs__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_trident_msgs__msg__MotorOutputs(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_MotorOutputs = {
  "trident_msgs::msg",
  "MotorOutputs",
  _MotorOutputs__cdr_serialize,
  _MotorOutputs__cdr_deserialize,
  _MotorOutputs__get_serialized_size,
  _MotorOutputs__max_serialized_size
};

static rosidl_message_type_support_t _MotorOutputs__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MotorOutputs,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, trident_msgs, msg, MotorOutputs)() {
  return &_MotorOutputs__type_support;
}

#if defined(__cplusplus)
}
#endif
