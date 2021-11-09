// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from trident_msgs:msg/MotorOutputs.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "trident_msgs/msg/detail/motor_outputs__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace trident_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MotorOutputs_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) trident_msgs::msg::MotorOutputs(_init);
}

void MotorOutputs_fini_function(void * message_memory)
{
  auto typed_message = static_cast<trident_msgs::msg::MotorOutputs *>(message_memory);
  typed_message->~MotorOutputs();
}

size_t size_function__MotorOutputs__motor_outputs(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<trident_msgs::msg::MotorOutput> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MotorOutputs__motor_outputs(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<trident_msgs::msg::MotorOutput> *>(untyped_member);
  return &member[index];
}

void * get_function__MotorOutputs__motor_outputs(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<trident_msgs::msg::MotorOutput> *>(untyped_member);
  return &member[index];
}

void resize_function__MotorOutputs__motor_outputs(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<trident_msgs::msg::MotorOutput> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MotorOutputs_message_member_array[1] = {
  {
    "motor_outputs",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<trident_msgs::msg::MotorOutput>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs::msg::MotorOutputs, motor_outputs),  // bytes offset in struct
    nullptr,  // default value
    size_function__MotorOutputs__motor_outputs,  // size() function pointer
    get_const_function__MotorOutputs__motor_outputs,  // get_const(index) function pointer
    get_function__MotorOutputs__motor_outputs,  // get(index) function pointer
    resize_function__MotorOutputs__motor_outputs  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MotorOutputs_message_members = {
  "trident_msgs::msg",  // message namespace
  "MotorOutputs",  // message name
  1,  // number of fields
  sizeof(trident_msgs::msg::MotorOutputs),
  MotorOutputs_message_member_array,  // message members
  MotorOutputs_init_function,  // function to initialize message memory (memory has to be allocated)
  MotorOutputs_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MotorOutputs_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MotorOutputs_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace trident_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<trident_msgs::msg::MotorOutputs>()
{
  return &::trident_msgs::msg::rosidl_typesupport_introspection_cpp::MotorOutputs_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, trident_msgs, msg, MotorOutputs)() {
  return &::trident_msgs::msg::rosidl_typesupport_introspection_cpp::MotorOutputs_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
