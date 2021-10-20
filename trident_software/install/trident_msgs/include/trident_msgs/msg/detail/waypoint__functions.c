// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from trident_msgs:msg/Waypoint.idl
// generated code does not contain a copyright notice
#include "trident_msgs/msg/detail/waypoint__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `action`
#include "trident_msgs/msg/detail/waypoint_action__functions.h"

bool
trident_msgs__msg__Waypoint__init(trident_msgs__msg__Waypoint * msg)
{
  if (!msg) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    trident_msgs__msg__Waypoint__fini(msg);
    return false;
  }
  // action
  if (!trident_msgs__msg__WaypointAction__init(&msg->action)) {
    trident_msgs__msg__Waypoint__fini(msg);
    return false;
  }
  return true;
}

void
trident_msgs__msg__Waypoint__fini(trident_msgs__msg__Waypoint * msg)
{
  if (!msg) {
    return;
  }
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
  // action
  trident_msgs__msg__WaypointAction__fini(&msg->action);
}

trident_msgs__msg__Waypoint *
trident_msgs__msg__Waypoint__create()
{
  trident_msgs__msg__Waypoint * msg = (trident_msgs__msg__Waypoint *)malloc(sizeof(trident_msgs__msg__Waypoint));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trident_msgs__msg__Waypoint));
  bool success = trident_msgs__msg__Waypoint__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
trident_msgs__msg__Waypoint__destroy(trident_msgs__msg__Waypoint * msg)
{
  if (msg) {
    trident_msgs__msg__Waypoint__fini(msg);
  }
  free(msg);
}


bool
trident_msgs__msg__Waypoint__Sequence__init(trident_msgs__msg__Waypoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  trident_msgs__msg__Waypoint * data = NULL;
  if (size) {
    data = (trident_msgs__msg__Waypoint *)calloc(size, sizeof(trident_msgs__msg__Waypoint));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trident_msgs__msg__Waypoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trident_msgs__msg__Waypoint__fini(&data[i - 1]);
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
trident_msgs__msg__Waypoint__Sequence__fini(trident_msgs__msg__Waypoint__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trident_msgs__msg__Waypoint__fini(&array->data[i]);
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

trident_msgs__msg__Waypoint__Sequence *
trident_msgs__msg__Waypoint__Sequence__create(size_t size)
{
  trident_msgs__msg__Waypoint__Sequence * array = (trident_msgs__msg__Waypoint__Sequence *)malloc(sizeof(trident_msgs__msg__Waypoint__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = trident_msgs__msg__Waypoint__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
trident_msgs__msg__Waypoint__Sequence__destroy(trident_msgs__msg__Waypoint__Sequence * array)
{
  if (array) {
    trident_msgs__msg__Waypoint__Sequence__fini(array);
  }
  free(array);
}
