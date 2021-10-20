// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from trident_msgs:action/GotoWaypoint.idl
// generated code does not contain a copyright notice
#include "trident_msgs/action/detail/goto_waypoint__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `waypoint`
#include "trident_msgs/msg/detail/waypoint__functions.h"

bool
trident_msgs__action__GotoWaypoint_Goal__init(trident_msgs__action__GotoWaypoint_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // waypoint
  if (!trident_msgs__msg__Waypoint__init(&msg->waypoint)) {
    trident_msgs__action__GotoWaypoint_Goal__fini(msg);
    return false;
  }
  return true;
}

void
trident_msgs__action__GotoWaypoint_Goal__fini(trident_msgs__action__GotoWaypoint_Goal * msg)
{
  if (!msg) {
    return;
  }
  // waypoint
  trident_msgs__msg__Waypoint__fini(&msg->waypoint);
}

trident_msgs__action__GotoWaypoint_Goal *
trident_msgs__action__GotoWaypoint_Goal__create()
{
  trident_msgs__action__GotoWaypoint_Goal * msg = (trident_msgs__action__GotoWaypoint_Goal *)malloc(sizeof(trident_msgs__action__GotoWaypoint_Goal));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trident_msgs__action__GotoWaypoint_Goal));
  bool success = trident_msgs__action__GotoWaypoint_Goal__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
trident_msgs__action__GotoWaypoint_Goal__destroy(trident_msgs__action__GotoWaypoint_Goal * msg)
{
  if (msg) {
    trident_msgs__action__GotoWaypoint_Goal__fini(msg);
  }
  free(msg);
}


bool
trident_msgs__action__GotoWaypoint_Goal__Sequence__init(trident_msgs__action__GotoWaypoint_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  trident_msgs__action__GotoWaypoint_Goal * data = NULL;
  if (size) {
    data = (trident_msgs__action__GotoWaypoint_Goal *)calloc(size, sizeof(trident_msgs__action__GotoWaypoint_Goal));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trident_msgs__action__GotoWaypoint_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trident_msgs__action__GotoWaypoint_Goal__fini(&data[i - 1]);
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
trident_msgs__action__GotoWaypoint_Goal__Sequence__fini(trident_msgs__action__GotoWaypoint_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trident_msgs__action__GotoWaypoint_Goal__fini(&array->data[i]);
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

trident_msgs__action__GotoWaypoint_Goal__Sequence *
trident_msgs__action__GotoWaypoint_Goal__Sequence__create(size_t size)
{
  trident_msgs__action__GotoWaypoint_Goal__Sequence * array = (trident_msgs__action__GotoWaypoint_Goal__Sequence *)malloc(sizeof(trident_msgs__action__GotoWaypoint_Goal__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = trident_msgs__action__GotoWaypoint_Goal__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
trident_msgs__action__GotoWaypoint_Goal__Sequence__destroy(trident_msgs__action__GotoWaypoint_Goal__Sequence * array)
{
  if (array) {
    trident_msgs__action__GotoWaypoint_Goal__Sequence__fini(array);
  }
  free(array);
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
trident_msgs__action__GotoWaypoint_Result__init(trident_msgs__action__GotoWaypoint_Result * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    trident_msgs__action__GotoWaypoint_Result__fini(msg);
    return false;
  }
  // distance_to_goal
  return true;
}

void
trident_msgs__action__GotoWaypoint_Result__fini(trident_msgs__action__GotoWaypoint_Result * msg)
{
  if (!msg) {
    return;
  }
  // status
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // distance_to_goal
}

trident_msgs__action__GotoWaypoint_Result *
trident_msgs__action__GotoWaypoint_Result__create()
{
  trident_msgs__action__GotoWaypoint_Result * msg = (trident_msgs__action__GotoWaypoint_Result *)malloc(sizeof(trident_msgs__action__GotoWaypoint_Result));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trident_msgs__action__GotoWaypoint_Result));
  bool success = trident_msgs__action__GotoWaypoint_Result__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
trident_msgs__action__GotoWaypoint_Result__destroy(trident_msgs__action__GotoWaypoint_Result * msg)
{
  if (msg) {
    trident_msgs__action__GotoWaypoint_Result__fini(msg);
  }
  free(msg);
}


bool
trident_msgs__action__GotoWaypoint_Result__Sequence__init(trident_msgs__action__GotoWaypoint_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  trident_msgs__action__GotoWaypoint_Result * data = NULL;
  if (size) {
    data = (trident_msgs__action__GotoWaypoint_Result *)calloc(size, sizeof(trident_msgs__action__GotoWaypoint_Result));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trident_msgs__action__GotoWaypoint_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trident_msgs__action__GotoWaypoint_Result__fini(&data[i - 1]);
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
trident_msgs__action__GotoWaypoint_Result__Sequence__fini(trident_msgs__action__GotoWaypoint_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trident_msgs__action__GotoWaypoint_Result__fini(&array->data[i]);
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

trident_msgs__action__GotoWaypoint_Result__Sequence *
trident_msgs__action__GotoWaypoint_Result__Sequence__create(size_t size)
{
  trident_msgs__action__GotoWaypoint_Result__Sequence * array = (trident_msgs__action__GotoWaypoint_Result__Sequence *)malloc(sizeof(trident_msgs__action__GotoWaypoint_Result__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = trident_msgs__action__GotoWaypoint_Result__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
trident_msgs__action__GotoWaypoint_Result__Sequence__destroy(trident_msgs__action__GotoWaypoint_Result__Sequence * array)
{
  if (array) {
    trident_msgs__action__GotoWaypoint_Result__Sequence__fini(array);
  }
  free(array);
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
trident_msgs__action__GotoWaypoint_Feedback__init(trident_msgs__action__GotoWaypoint_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    trident_msgs__action__GotoWaypoint_Feedback__fini(msg);
    return false;
  }
  // distance_to_goal
  return true;
}

void
trident_msgs__action__GotoWaypoint_Feedback__fini(trident_msgs__action__GotoWaypoint_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // status
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // distance_to_goal
}

trident_msgs__action__GotoWaypoint_Feedback *
trident_msgs__action__GotoWaypoint_Feedback__create()
{
  trident_msgs__action__GotoWaypoint_Feedback * msg = (trident_msgs__action__GotoWaypoint_Feedback *)malloc(sizeof(trident_msgs__action__GotoWaypoint_Feedback));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trident_msgs__action__GotoWaypoint_Feedback));
  bool success = trident_msgs__action__GotoWaypoint_Feedback__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
trident_msgs__action__GotoWaypoint_Feedback__destroy(trident_msgs__action__GotoWaypoint_Feedback * msg)
{
  if (msg) {
    trident_msgs__action__GotoWaypoint_Feedback__fini(msg);
  }
  free(msg);
}


bool
trident_msgs__action__GotoWaypoint_Feedback__Sequence__init(trident_msgs__action__GotoWaypoint_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  trident_msgs__action__GotoWaypoint_Feedback * data = NULL;
  if (size) {
    data = (trident_msgs__action__GotoWaypoint_Feedback *)calloc(size, sizeof(trident_msgs__action__GotoWaypoint_Feedback));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trident_msgs__action__GotoWaypoint_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trident_msgs__action__GotoWaypoint_Feedback__fini(&data[i - 1]);
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
trident_msgs__action__GotoWaypoint_Feedback__Sequence__fini(trident_msgs__action__GotoWaypoint_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trident_msgs__action__GotoWaypoint_Feedback__fini(&array->data[i]);
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

trident_msgs__action__GotoWaypoint_Feedback__Sequence *
trident_msgs__action__GotoWaypoint_Feedback__Sequence__create(size_t size)
{
  trident_msgs__action__GotoWaypoint_Feedback__Sequence * array = (trident_msgs__action__GotoWaypoint_Feedback__Sequence *)malloc(sizeof(trident_msgs__action__GotoWaypoint_Feedback__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = trident_msgs__action__GotoWaypoint_Feedback__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
trident_msgs__action__GotoWaypoint_Feedback__Sequence__destroy(trident_msgs__action__GotoWaypoint_Feedback__Sequence * array)
{
  if (array) {
    trident_msgs__action__GotoWaypoint_Feedback__Sequence__fini(array);
  }
  free(array);
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__functions.h"

bool
trident_msgs__action__GotoWaypoint_SendGoal_Request__init(trident_msgs__action__GotoWaypoint_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    trident_msgs__action__GotoWaypoint_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!trident_msgs__action__GotoWaypoint_Goal__init(&msg->goal)) {
    trident_msgs__action__GotoWaypoint_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
trident_msgs__action__GotoWaypoint_SendGoal_Request__fini(trident_msgs__action__GotoWaypoint_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  trident_msgs__action__GotoWaypoint_Goal__fini(&msg->goal);
}

trident_msgs__action__GotoWaypoint_SendGoal_Request *
trident_msgs__action__GotoWaypoint_SendGoal_Request__create()
{
  trident_msgs__action__GotoWaypoint_SendGoal_Request * msg = (trident_msgs__action__GotoWaypoint_SendGoal_Request *)malloc(sizeof(trident_msgs__action__GotoWaypoint_SendGoal_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trident_msgs__action__GotoWaypoint_SendGoal_Request));
  bool success = trident_msgs__action__GotoWaypoint_SendGoal_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
trident_msgs__action__GotoWaypoint_SendGoal_Request__destroy(trident_msgs__action__GotoWaypoint_SendGoal_Request * msg)
{
  if (msg) {
    trident_msgs__action__GotoWaypoint_SendGoal_Request__fini(msg);
  }
  free(msg);
}


bool
trident_msgs__action__GotoWaypoint_SendGoal_Request__Sequence__init(trident_msgs__action__GotoWaypoint_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  trident_msgs__action__GotoWaypoint_SendGoal_Request * data = NULL;
  if (size) {
    data = (trident_msgs__action__GotoWaypoint_SendGoal_Request *)calloc(size, sizeof(trident_msgs__action__GotoWaypoint_SendGoal_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trident_msgs__action__GotoWaypoint_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trident_msgs__action__GotoWaypoint_SendGoal_Request__fini(&data[i - 1]);
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
trident_msgs__action__GotoWaypoint_SendGoal_Request__Sequence__fini(trident_msgs__action__GotoWaypoint_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trident_msgs__action__GotoWaypoint_SendGoal_Request__fini(&array->data[i]);
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

trident_msgs__action__GotoWaypoint_SendGoal_Request__Sequence *
trident_msgs__action__GotoWaypoint_SendGoal_Request__Sequence__create(size_t size)
{
  trident_msgs__action__GotoWaypoint_SendGoal_Request__Sequence * array = (trident_msgs__action__GotoWaypoint_SendGoal_Request__Sequence *)malloc(sizeof(trident_msgs__action__GotoWaypoint_SendGoal_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = trident_msgs__action__GotoWaypoint_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
trident_msgs__action__GotoWaypoint_SendGoal_Request__Sequence__destroy(trident_msgs__action__GotoWaypoint_SendGoal_Request__Sequence * array)
{
  if (array) {
    trident_msgs__action__GotoWaypoint_SendGoal_Request__Sequence__fini(array);
  }
  free(array);
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
trident_msgs__action__GotoWaypoint_SendGoal_Response__init(trident_msgs__action__GotoWaypoint_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    trident_msgs__action__GotoWaypoint_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
trident_msgs__action__GotoWaypoint_SendGoal_Response__fini(trident_msgs__action__GotoWaypoint_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

trident_msgs__action__GotoWaypoint_SendGoal_Response *
trident_msgs__action__GotoWaypoint_SendGoal_Response__create()
{
  trident_msgs__action__GotoWaypoint_SendGoal_Response * msg = (trident_msgs__action__GotoWaypoint_SendGoal_Response *)malloc(sizeof(trident_msgs__action__GotoWaypoint_SendGoal_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trident_msgs__action__GotoWaypoint_SendGoal_Response));
  bool success = trident_msgs__action__GotoWaypoint_SendGoal_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
trident_msgs__action__GotoWaypoint_SendGoal_Response__destroy(trident_msgs__action__GotoWaypoint_SendGoal_Response * msg)
{
  if (msg) {
    trident_msgs__action__GotoWaypoint_SendGoal_Response__fini(msg);
  }
  free(msg);
}


bool
trident_msgs__action__GotoWaypoint_SendGoal_Response__Sequence__init(trident_msgs__action__GotoWaypoint_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  trident_msgs__action__GotoWaypoint_SendGoal_Response * data = NULL;
  if (size) {
    data = (trident_msgs__action__GotoWaypoint_SendGoal_Response *)calloc(size, sizeof(trident_msgs__action__GotoWaypoint_SendGoal_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trident_msgs__action__GotoWaypoint_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trident_msgs__action__GotoWaypoint_SendGoal_Response__fini(&data[i - 1]);
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
trident_msgs__action__GotoWaypoint_SendGoal_Response__Sequence__fini(trident_msgs__action__GotoWaypoint_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trident_msgs__action__GotoWaypoint_SendGoal_Response__fini(&array->data[i]);
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

trident_msgs__action__GotoWaypoint_SendGoal_Response__Sequence *
trident_msgs__action__GotoWaypoint_SendGoal_Response__Sequence__create(size_t size)
{
  trident_msgs__action__GotoWaypoint_SendGoal_Response__Sequence * array = (trident_msgs__action__GotoWaypoint_SendGoal_Response__Sequence *)malloc(sizeof(trident_msgs__action__GotoWaypoint_SendGoal_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = trident_msgs__action__GotoWaypoint_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
trident_msgs__action__GotoWaypoint_SendGoal_Response__Sequence__destroy(trident_msgs__action__GotoWaypoint_SendGoal_Response__Sequence * array)
{
  if (array) {
    trident_msgs__action__GotoWaypoint_SendGoal_Response__Sequence__fini(array);
  }
  free(array);
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
trident_msgs__action__GotoWaypoint_GetResult_Request__init(trident_msgs__action__GotoWaypoint_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    trident_msgs__action__GotoWaypoint_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
trident_msgs__action__GotoWaypoint_GetResult_Request__fini(trident_msgs__action__GotoWaypoint_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

trident_msgs__action__GotoWaypoint_GetResult_Request *
trident_msgs__action__GotoWaypoint_GetResult_Request__create()
{
  trident_msgs__action__GotoWaypoint_GetResult_Request * msg = (trident_msgs__action__GotoWaypoint_GetResult_Request *)malloc(sizeof(trident_msgs__action__GotoWaypoint_GetResult_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trident_msgs__action__GotoWaypoint_GetResult_Request));
  bool success = trident_msgs__action__GotoWaypoint_GetResult_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
trident_msgs__action__GotoWaypoint_GetResult_Request__destroy(trident_msgs__action__GotoWaypoint_GetResult_Request * msg)
{
  if (msg) {
    trident_msgs__action__GotoWaypoint_GetResult_Request__fini(msg);
  }
  free(msg);
}


bool
trident_msgs__action__GotoWaypoint_GetResult_Request__Sequence__init(trident_msgs__action__GotoWaypoint_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  trident_msgs__action__GotoWaypoint_GetResult_Request * data = NULL;
  if (size) {
    data = (trident_msgs__action__GotoWaypoint_GetResult_Request *)calloc(size, sizeof(trident_msgs__action__GotoWaypoint_GetResult_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trident_msgs__action__GotoWaypoint_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trident_msgs__action__GotoWaypoint_GetResult_Request__fini(&data[i - 1]);
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
trident_msgs__action__GotoWaypoint_GetResult_Request__Sequence__fini(trident_msgs__action__GotoWaypoint_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trident_msgs__action__GotoWaypoint_GetResult_Request__fini(&array->data[i]);
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

trident_msgs__action__GotoWaypoint_GetResult_Request__Sequence *
trident_msgs__action__GotoWaypoint_GetResult_Request__Sequence__create(size_t size)
{
  trident_msgs__action__GotoWaypoint_GetResult_Request__Sequence * array = (trident_msgs__action__GotoWaypoint_GetResult_Request__Sequence *)malloc(sizeof(trident_msgs__action__GotoWaypoint_GetResult_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = trident_msgs__action__GotoWaypoint_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
trident_msgs__action__GotoWaypoint_GetResult_Request__Sequence__destroy(trident_msgs__action__GotoWaypoint_GetResult_Request__Sequence * array)
{
  if (array) {
    trident_msgs__action__GotoWaypoint_GetResult_Request__Sequence__fini(array);
  }
  free(array);
}


// Include directives for member types
// Member `result`
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__functions.h"

bool
trident_msgs__action__GotoWaypoint_GetResult_Response__init(trident_msgs__action__GotoWaypoint_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!trident_msgs__action__GotoWaypoint_Result__init(&msg->result)) {
    trident_msgs__action__GotoWaypoint_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
trident_msgs__action__GotoWaypoint_GetResult_Response__fini(trident_msgs__action__GotoWaypoint_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  trident_msgs__action__GotoWaypoint_Result__fini(&msg->result);
}

trident_msgs__action__GotoWaypoint_GetResult_Response *
trident_msgs__action__GotoWaypoint_GetResult_Response__create()
{
  trident_msgs__action__GotoWaypoint_GetResult_Response * msg = (trident_msgs__action__GotoWaypoint_GetResult_Response *)malloc(sizeof(trident_msgs__action__GotoWaypoint_GetResult_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trident_msgs__action__GotoWaypoint_GetResult_Response));
  bool success = trident_msgs__action__GotoWaypoint_GetResult_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
trident_msgs__action__GotoWaypoint_GetResult_Response__destroy(trident_msgs__action__GotoWaypoint_GetResult_Response * msg)
{
  if (msg) {
    trident_msgs__action__GotoWaypoint_GetResult_Response__fini(msg);
  }
  free(msg);
}


bool
trident_msgs__action__GotoWaypoint_GetResult_Response__Sequence__init(trident_msgs__action__GotoWaypoint_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  trident_msgs__action__GotoWaypoint_GetResult_Response * data = NULL;
  if (size) {
    data = (trident_msgs__action__GotoWaypoint_GetResult_Response *)calloc(size, sizeof(trident_msgs__action__GotoWaypoint_GetResult_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trident_msgs__action__GotoWaypoint_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trident_msgs__action__GotoWaypoint_GetResult_Response__fini(&data[i - 1]);
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
trident_msgs__action__GotoWaypoint_GetResult_Response__Sequence__fini(trident_msgs__action__GotoWaypoint_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trident_msgs__action__GotoWaypoint_GetResult_Response__fini(&array->data[i]);
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

trident_msgs__action__GotoWaypoint_GetResult_Response__Sequence *
trident_msgs__action__GotoWaypoint_GetResult_Response__Sequence__create(size_t size)
{
  trident_msgs__action__GotoWaypoint_GetResult_Response__Sequence * array = (trident_msgs__action__GotoWaypoint_GetResult_Response__Sequence *)malloc(sizeof(trident_msgs__action__GotoWaypoint_GetResult_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = trident_msgs__action__GotoWaypoint_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
trident_msgs__action__GotoWaypoint_GetResult_Response__Sequence__destroy(trident_msgs__action__GotoWaypoint_GetResult_Response__Sequence * array)
{
  if (array) {
    trident_msgs__action__GotoWaypoint_GetResult_Response__Sequence__fini(array);
  }
  free(array);
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "trident_msgs/action/detail/goto_waypoint__functions.h"

bool
trident_msgs__action__GotoWaypoint_FeedbackMessage__init(trident_msgs__action__GotoWaypoint_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    trident_msgs__action__GotoWaypoint_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!trident_msgs__action__GotoWaypoint_Feedback__init(&msg->feedback)) {
    trident_msgs__action__GotoWaypoint_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
trident_msgs__action__GotoWaypoint_FeedbackMessage__fini(trident_msgs__action__GotoWaypoint_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  trident_msgs__action__GotoWaypoint_Feedback__fini(&msg->feedback);
}

trident_msgs__action__GotoWaypoint_FeedbackMessage *
trident_msgs__action__GotoWaypoint_FeedbackMessage__create()
{
  trident_msgs__action__GotoWaypoint_FeedbackMessage * msg = (trident_msgs__action__GotoWaypoint_FeedbackMessage *)malloc(sizeof(trident_msgs__action__GotoWaypoint_FeedbackMessage));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trident_msgs__action__GotoWaypoint_FeedbackMessage));
  bool success = trident_msgs__action__GotoWaypoint_FeedbackMessage__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
trident_msgs__action__GotoWaypoint_FeedbackMessage__destroy(trident_msgs__action__GotoWaypoint_FeedbackMessage * msg)
{
  if (msg) {
    trident_msgs__action__GotoWaypoint_FeedbackMessage__fini(msg);
  }
  free(msg);
}


bool
trident_msgs__action__GotoWaypoint_FeedbackMessage__Sequence__init(trident_msgs__action__GotoWaypoint_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  trident_msgs__action__GotoWaypoint_FeedbackMessage * data = NULL;
  if (size) {
    data = (trident_msgs__action__GotoWaypoint_FeedbackMessage *)calloc(size, sizeof(trident_msgs__action__GotoWaypoint_FeedbackMessage));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trident_msgs__action__GotoWaypoint_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trident_msgs__action__GotoWaypoint_FeedbackMessage__fini(&data[i - 1]);
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
trident_msgs__action__GotoWaypoint_FeedbackMessage__Sequence__fini(trident_msgs__action__GotoWaypoint_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trident_msgs__action__GotoWaypoint_FeedbackMessage__fini(&array->data[i]);
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

trident_msgs__action__GotoWaypoint_FeedbackMessage__Sequence *
trident_msgs__action__GotoWaypoint_FeedbackMessage__Sequence__create(size_t size)
{
  trident_msgs__action__GotoWaypoint_FeedbackMessage__Sequence * array = (trident_msgs__action__GotoWaypoint_FeedbackMessage__Sequence *)malloc(sizeof(trident_msgs__action__GotoWaypoint_FeedbackMessage__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = trident_msgs__action__GotoWaypoint_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
trident_msgs__action__GotoWaypoint_FeedbackMessage__Sequence__destroy(trident_msgs__action__GotoWaypoint_FeedbackMessage__Sequence * array)
{
  if (array) {
    trident_msgs__action__GotoWaypoint_FeedbackMessage__Sequence__fini(array);
  }
  free(array);
}
