// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from trident_msgs:msg/WaypointAction.idl
// generated code does not contain a copyright notice
#include "trident_msgs/msg/detail/waypoint_action__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
trident_msgs__msg__WaypointAction__init(trident_msgs__msg__WaypointAction * msg)
{
  if (!msg) {
    return false;
  }
  // action_type
  msg->action_type = 0;
  // action_param
  msg->action_param = 0;
  return true;
}

void
trident_msgs__msg__WaypointAction__fini(trident_msgs__msg__WaypointAction * msg)
{
  if (!msg) {
    return;
  }
  // action_type
  // action_param
}

trident_msgs__msg__WaypointAction *
trident_msgs__msg__WaypointAction__create()
{
  trident_msgs__msg__WaypointAction * msg = (trident_msgs__msg__WaypointAction *)malloc(sizeof(trident_msgs__msg__WaypointAction));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trident_msgs__msg__WaypointAction));
  bool success = trident_msgs__msg__WaypointAction__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
trident_msgs__msg__WaypointAction__destroy(trident_msgs__msg__WaypointAction * msg)
{
  if (msg) {
    trident_msgs__msg__WaypointAction__fini(msg);
  }
  free(msg);
}


bool
trident_msgs__msg__WaypointAction__Sequence__init(trident_msgs__msg__WaypointAction__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  trident_msgs__msg__WaypointAction * data = NULL;
  if (size) {
    data = (trident_msgs__msg__WaypointAction *)calloc(size, sizeof(trident_msgs__msg__WaypointAction));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trident_msgs__msg__WaypointAction__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trident_msgs__msg__WaypointAction__fini(&data[i - 1]);
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
trident_msgs__msg__WaypointAction__Sequence__fini(trident_msgs__msg__WaypointAction__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trident_msgs__msg__WaypointAction__fini(&array->data[i]);
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

trident_msgs__msg__WaypointAction__Sequence *
trident_msgs__msg__WaypointAction__Sequence__create(size_t size)
{
  trident_msgs__msg__WaypointAction__Sequence * array = (trident_msgs__msg__WaypointAction__Sequence *)malloc(sizeof(trident_msgs__msg__WaypointAction__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = trident_msgs__msg__WaypointAction__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
trident_msgs__msg__WaypointAction__Sequence__destroy(trident_msgs__msg__WaypointAction__Sequence * array)
{
  if (array) {
    trident_msgs__msg__WaypointAction__Sequence__fini(array);
  }
  free(array);
}
