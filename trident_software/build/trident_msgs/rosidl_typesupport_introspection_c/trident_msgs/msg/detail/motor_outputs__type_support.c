// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from trident_msgs:msg/MotorOutputs.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "trident_msgs/msg/detail/motor_outputs__rosidl_typesupport_introspection_c.h"
#include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "trident_msgs/msg/detail/motor_outputs__functions.h"
#include "trident_msgs/msg/detail/motor_outputs__struct.h"


// Include directives for member types
// Member `motor_outputs`
#include "trident_msgs/msg/motor_output.h"
// Member `motor_outputs`
#include "trident_msgs/msg/detail/motor_output__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MotorOutputs__rosidl_typesupport_introspection_c__MotorOutputs_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__msg__MotorOutputs__init(message_memory);
}

void MotorOutputs__rosidl_typesupport_introspection_c__MotorOutputs_fini_function(void * message_memory)
{
  trident_msgs__msg__MotorOutputs__fini(message_memory);
}

size_t MotorOutputs__rosidl_typesupport_introspection_c__size_function__MotorOutput__motor_outputs(
  const void * untyped_member)
{
  const trident_msgs__msg__MotorOutput__Sequence * member =
    (const trident_msgs__msg__MotorOutput__Sequence *)(untyped_member);
  return member->size;
}

const void * MotorOutputs__rosidl_typesupport_introspection_c__get_const_function__MotorOutput__motor_outputs(
  const void * untyped_member, size_t index)
{
  const trident_msgs__msg__MotorOutput__Sequence * member =
    (const trident_msgs__msg__MotorOutput__Sequence *)(untyped_member);
  return &member->data[index];
}

void * MotorOutputs__rosidl_typesupport_introspection_c__get_function__MotorOutput__motor_outputs(
  void * untyped_member, size_t index)
{
  trident_msgs__msg__MotorOutput__Sequence * member =
    (trident_msgs__msg__MotorOutput__Sequence *)(untyped_member);
  return &member->data[index];
}

bool MotorOutputs__rosidl_typesupport_introspection_c__resize_function__MotorOutput__motor_outputs(
  void * untyped_member, size_t size)
{
  trident_msgs__msg__MotorOutput__Sequence * member =
    (trident_msgs__msg__MotorOutput__Sequence *)(untyped_member);
  trident_msgs__msg__MotorOutput__Sequence__fini(member);
  return trident_msgs__msg__MotorOutput__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember MotorOutputs__rosidl_typesupport_introspection_c__MotorOutputs_message_member_array[1] = {
  {
    "motor_outputs",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__msg__MotorOutputs, motor_outputs),  // bytes offset in struct
    NULL,  // default value
    MotorOutputs__rosidl_typesupport_introspection_c__size_function__MotorOutput__motor_outputs,  // size() function pointer
    MotorOutputs__rosidl_typesupport_introspection_c__get_const_function__MotorOutput__motor_outputs,  // get_const(index) function pointer
    MotorOutputs__rosidl_typesupport_introspection_c__get_function__MotorOutput__motor_outputs,  // get(index) function pointer
    MotorOutputs__rosidl_typesupport_introspection_c__resize_function__MotorOutput__motor_outputs  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MotorOutputs__rosidl_typesupport_introspection_c__MotorOutputs_message_members = {
  "trident_msgs__msg",  // message namespace
  "MotorOutputs",  // message name
  1,  // number of fields
  sizeof(trident_msgs__msg__MotorOutputs),
  MotorOutputs__rosidl_typesupport_introspection_c__MotorOutputs_message_member_array,  // message members
  MotorOutputs__rosidl_typesupport_introspection_c__MotorOutputs_init_function,  // function to initialize message memory (memory has to be allocated)
  MotorOutputs__rosidl_typesupport_introspection_c__MotorOutputs_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MotorOutputs__rosidl_typesupport_introspection_c__MotorOutputs_message_type_support_handle = {
  0,
  &MotorOutputs__rosidl_typesupport_introspection_c__MotorOutputs_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, msg, MotorOutputs)() {
  MotorOutputs__rosidl_typesupport_introspection_c__MotorOutputs_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, msg, MotorOutput)();
  if (!MotorOutputs__rosidl_typesupport_introspection_c__MotorOutputs_message_type_support_handle.typesupport_identifier) {
    MotorOutputs__rosidl_typesupport_introspection_c__MotorOutputs_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MotorOutputs__rosidl_typesupport_introspection_c__MotorOutputs_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
