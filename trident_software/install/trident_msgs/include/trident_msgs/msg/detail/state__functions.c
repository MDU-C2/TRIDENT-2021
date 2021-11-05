// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from trident_msgs:msg/State.idl
// generated code does not contain a copyright notice
#include "trident_msgs/msg/detail/state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `twist`
#include "geometry_msgs/msg/detail/twist__functions.h"

bool
trident_msgs__msg__State__init(trident_msgs__msg__State * msg)
{
  if (!msg) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    trident_msgs__msg__State__fini(msg);
    return false;
  }
  // twist
  if (!geometry_msgs__msg__Twist__init(&msg->twist)) {
    trident_msgs__msg__State__fini(msg);
    return false;
  }
  return true;
}

void
trident_msgs__msg__State__fini(trident_msgs__msg__State * msg)
{
  if (!msg) {
    return;
  }
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
  // twist
  geometry_msgs__msg__Twist__fini(&msg->twist);
}

trident_msgs__msg__State *
trident_msgs__msg__State__create()
{
  trident_msgs__msg__State * msg = (trident_msgs__msg__State *)malloc(sizeof(trident_msgs__msg__State));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trident_msgs__msg__State));
  bool success = trident_msgs__msg__State__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
trident_msgs__msg__State__destroy(trident_msgs__msg__State * msg)
{
  if (msg) {
    trident_msgs__msg__State__fini(msg);
  }
  free(msg);
}


bool
trident_msgs__msg__State__Sequence__init(trident_msgs__msg__State__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  trident_msgs__msg__State * data = NULL;
  if (size) {
    data = (trident_msgs__msg__State *)calloc(size, sizeof(trident_msgs__msg__State));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trident_msgs__msg__State__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trident_msgs__msg__State__fini(&data[i - 1]);
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
trident_msgs__msg__State__Sequence__fini(trident_msgs__msg__State__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trident_msgs__msg__State__fini(&array->data[i]);
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

trident_msgs__msg__State__Sequence *
trident_msgs__msg__State__Sequence__create(size_t size)
{
  trident_msgs__msg__State__Sequence * array = (trident_msgs__msg__State__Sequence *)malloc(sizeof(trident_msgs__msg__State__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = trident_msgs__msg__State__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
trident_msgs__msg__State__Sequence__destroy(trident_msgs__msg__State__Sequence * array)
{
  if (array) {
    trident_msgs__msg__State__Sequence__fini(array);
  }
  free(array);
}
