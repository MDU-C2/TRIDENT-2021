// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from trident_msgs:msg/MotorOutput.idl
// generated code does not contain a copyright notice
#include "trident_msgs/msg/detail/motor_output__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
trident_msgs__msg__MotorOutput__init(trident_msgs__msg__MotorOutput * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // value
  return true;
}

void
trident_msgs__msg__MotorOutput__fini(trident_msgs__msg__MotorOutput * msg)
{
  if (!msg) {
    return;
  }
  // id
  // value
}

trident_msgs__msg__MotorOutput *
trident_msgs__msg__MotorOutput__create()
{
  trident_msgs__msg__MotorOutput * msg = (trident_msgs__msg__MotorOutput *)malloc(sizeof(trident_msgs__msg__MotorOutput));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trident_msgs__msg__MotorOutput));
  bool success = trident_msgs__msg__MotorOutput__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
trident_msgs__msg__MotorOutput__destroy(trident_msgs__msg__MotorOutput * msg)
{
  if (msg) {
    trident_msgs__msg__MotorOutput__fini(msg);
  }
  free(msg);
}


bool
trident_msgs__msg__MotorOutput__Sequence__init(trident_msgs__msg__MotorOutput__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  trident_msgs__msg__MotorOutput * data = NULL;
  if (size) {
    data = (trident_msgs__msg__MotorOutput *)calloc(size, sizeof(trident_msgs__msg__MotorOutput));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trident_msgs__msg__MotorOutput__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trident_msgs__msg__MotorOutput__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
trident_msgs__msg__MotorOutput__Sequence__fini(trident_msgs__msg__MotorOutput__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trident_msgs__msg__MotorOutput__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

trident_msgs__msg__MotorOutput__Sequence *
trident_msgs__msg__MotorOutput__Sequence__create(size_t size)
{
  trident_msgs__msg__MotorOutput__Sequence * array = (trident_msgs__msg__MotorOutput__Sequence *)malloc(sizeof(trident_msgs__msg__MotorOutput__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = trident_msgs__msg__MotorOutput__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
trident_msgs__msg__MotorOutput__Sequence__destroy(trident_msgs__msg__MotorOutput__Sequence * array)
{
  if (array) {
    trident_msgs__msg__MotorOutput__Sequence__fini(array);
  }
  free(array);
}
