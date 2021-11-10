// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from trident_msgs:msg/Mission.idl
// generated code does not contain a copyright notice
#include "trident_msgs/msg/detail/mission__rosidl_typesupport_fastrtps_cpp.hpp"
#include "trident_msgs/msg/detail/mission__struct.hpp"

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
  const trident_msgs::msg::Waypoint &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  trident_msgs::msg::Waypoint &);
size_t get_serialized_size(
  const trident_msgs::msg::Waypoint &,
  size_t current_alignment);
size_t
max_serialized_size_Waypoint(
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
  const trident_msgs::msg::Mission & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: waypoints
  {
    size_t size = ros_message.waypoints.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      trident_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.waypoints[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trident_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  trident_msgs::msg::Mission & ros_message)
{
  // Member: waypoints
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.waypoints.resize(size);
    for (size_t i = 0; i < size; i++) {
      trident_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.waypoints[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trident_msgs
get_serialized_size(
  const trident_msgs::msg::Mission & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: waypoints
  {
    size_t array_size = ros_message.waypoints.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        trident_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.waypoints[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_trident_msgs
max_serialized_size_Mission(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: waypoints
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        trident_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Waypoint(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _Mission__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const trident_msgs::msg::Mission *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Mission__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<trident_msgs::msg::Mission *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Mission__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const trident_msgs::msg::Mission *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Mission__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Mission(full_bounded, 0);
}

static message_type_support_callbacks_t _Mission__callbacks = {
  "trident_msgs::msg",
  "Mission",
  _Mission__cdr_serialize,
  _Mission__cdr_deserialize,
  _Mission__get_serialized_size,
  _Mission__max_serialized_size
};

static rosidl_message_type_support_t _Mission__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Mission__callbacks,
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
get_message_type_support_handle<trident_msgs::msg::Mission>()
{
  return &trident_msgs::msg::typesupport_fastrtps_cpp::_Mission__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, trident_msgs, msg, Mission)() {
  return &trident_msgs::msg::typesupport_fastrtps_cpp::_Mission__handle;
}

#ifdef __cplusplus
}
#endif
