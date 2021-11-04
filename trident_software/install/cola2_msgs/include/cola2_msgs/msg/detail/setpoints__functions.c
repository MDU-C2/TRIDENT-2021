// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cola2_msgs:msg/Setpoints.idl
// generated code does not contain a copyright notice
#include "cola2_msgs/msg/detail/setpoints__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `setpoints`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
cola2_msgs__msg__Setpoints__init(cola2_msgs__msg__Setpoints * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    cola2_msgs__msg__Setpoints__fini(msg);
    return false;
  }
  // setpoints
  if (!rosidl_runtime_c__double__Sequence__init(&msg->setpoints, 0)) {
    cola2_msgs__msg__Setpoints__fini(msg);
    return false;
  }
  return true;
}

void
cola2_msgs__msg__Setpoints__fini(cola2_msgs__msg__Setpoints * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // setpoints
  rosidl_runtime_c__double__Sequence__fini(&msg->setpoints);
}

cola2_msgs__msg__Setpoints *
cola2_msgs__msg__Setpoints__create()
{
  cola2_msgs__msg__Setpoints * msg = (cola2_msgs__msg__Setpoints *)malloc(sizeof(cola2_msgs__msg__Setpoints));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cola2_msgs__msg__Setpoints));
  bool success = cola2_msgs__msg__Setpoints__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
cola2_msgs__msg__Setpoints__destroy(cola2_msgs__msg__Setpoints * msg)
{
  if (msg) {
    cola2_msgs__msg__Setpoints__fini(msg);
  }
  free(msg);
}


bool
cola2_msgs__msg__Setpoints__Sequence__init(cola2_msgs__msg__Setpoints__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  cola2_msgs__msg__Setpoints * data = NULL;
  if (size) {
    data = (cola2_msgs__msg__Setpoints *)calloc(size, sizeof(cola2_msgs__msg__Setpoints));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cola2_msgs__msg__Setpoints__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cola2_msgs__msg__Setpoints__fini(&data[i - 1]);
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
cola2_msgs__msg__Setpoints__Sequence__fini(cola2_msgs__msg__Setpoints__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cola2_msgs__msg__Setpoints__fini(&array->data[i]);
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

cola2_msgs__msg__Setpoints__Sequence *
cola2_msgs__msg__Setpoints__Sequence__create(size_t size)
{
  cola2_msgs__msg__Setpoints__Sequence * array = (cola2_msgs__msg__Setpoints__Sequence *)malloc(sizeof(cola2_msgs__msg__Setpoints__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = cola2_msgs__msg__Setpoints__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
cola2_msgs__msg__Setpoints__Sequence__destroy(cola2_msgs__msg__Setpoints__Sequence * array)
{
  if (array) {
    cola2_msgs__msg__Setpoints__Sequence__fini(array);
  }
  free(array);
}
