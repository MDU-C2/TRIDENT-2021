// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from trident_msgs:msg/NaiadState.idl
// generated code does not contain a copyright notice
#include "trident_msgs/msg/detail/naiad_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
trident_msgs__msg__NaiadState__init(trident_msgs__msg__NaiadState * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  // roll
  // pitch
  // heading
  // velx
  // vely
  // velz
  // velroll
  // velpitch
  // velheading
  return true;
}

void
trident_msgs__msg__NaiadState__fini(trident_msgs__msg__NaiadState * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
  // roll
  // pitch
  // heading
  // velx
  // vely
  // velz
  // velroll
  // velpitch
  // velheading
}

trident_msgs__msg__NaiadState *
trident_msgs__msg__NaiadState__create()
{
  trident_msgs__msg__NaiadState * msg = (trident_msgs__msg__NaiadState *)malloc(sizeof(trident_msgs__msg__NaiadState));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trident_msgs__msg__NaiadState));
  bool success = trident_msgs__msg__NaiadState__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
trident_msgs__msg__NaiadState__destroy(trident_msgs__msg__NaiadState * msg)
{
  if (msg) {
    trident_msgs__msg__NaiadState__fini(msg);
  }
  free(msg);
}


bool
trident_msgs__msg__NaiadState__Sequence__init(trident_msgs__msg__NaiadState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  trident_msgs__msg__NaiadState * data = NULL;
  if (size) {
    data = (trident_msgs__msg__NaiadState *)calloc(size, sizeof(trident_msgs__msg__NaiadState));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trident_msgs__msg__NaiadState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trident_msgs__msg__NaiadState__fini(&data[i - 1]);
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
trident_msgs__msg__NaiadState__Sequence__fini(trident_msgs__msg__NaiadState__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trident_msgs__msg__NaiadState__fini(&array->data[i]);
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

trident_msgs__msg__NaiadState__Sequence *
trident_msgs__msg__NaiadState__Sequence__create(size_t size)
{
  trident_msgs__msg__NaiadState__Sequence * array = (trident_msgs__msg__NaiadState__Sequence *)malloc(sizeof(trident_msgs__msg__NaiadState__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = trident_msgs__msg__NaiadState__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
trident_msgs__msg__NaiadState__Sequence__destroy(trident_msgs__msg__NaiadState__Sequence * array)
{
  if (array) {
    trident_msgs__msg__NaiadState__Sequence__fini(array);
  }
  free(array);
}
