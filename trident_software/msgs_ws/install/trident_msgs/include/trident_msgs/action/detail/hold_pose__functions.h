// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from trident_msgs:action/HoldPose.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__ACTION__DETAIL__HOLD_POSE__FUNCTIONS_H_
#define TRIDENT_MSGS__ACTION__DETAIL__HOLD_POSE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "trident_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "trident_msgs/action/detail/hold_pose__struct.h"

/// Initialize action/HoldPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * trident_msgs__action__HoldPose_Goal
 * )) before or use
 * trident_msgs__action__HoldPose_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
bool
trident_msgs__action__HoldPose_Goal__init(trident_msgs__action__HoldPose_Goal * msg);

/// Finalize action/HoldPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_Goal__fini(trident_msgs__action__HoldPose_Goal * msg);

/// Create action/HoldPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * trident_msgs__action__HoldPose_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
trident_msgs__action__HoldPose_Goal *
trident_msgs__action__HoldPose_Goal__create();

/// Destroy action/HoldPose message.
/**
 * It calls
 * trident_msgs__action__HoldPose_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_Goal__destroy(trident_msgs__action__HoldPose_Goal * msg);


/// Initialize array of action/HoldPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * trident_msgs__action__HoldPose_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
bool
trident_msgs__action__HoldPose_Goal__Sequence__init(trident_msgs__action__HoldPose_Goal__Sequence * array, size_t size);

/// Finalize array of action/HoldPose messages.
/**
 * It calls
 * trident_msgs__action__HoldPose_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_Goal__Sequence__fini(trident_msgs__action__HoldPose_Goal__Sequence * array);

/// Create array of action/HoldPose messages.
/**
 * It allocates the memory for the array and calls
 * trident_msgs__action__HoldPose_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
trident_msgs__action__HoldPose_Goal__Sequence *
trident_msgs__action__HoldPose_Goal__Sequence__create(size_t size);

/// Destroy array of action/HoldPose messages.
/**
 * It calls
 * trident_msgs__action__HoldPose_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_Goal__Sequence__destroy(trident_msgs__action__HoldPose_Goal__Sequence * array);

/// Initialize action/HoldPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * trident_msgs__action__HoldPose_Result
 * )) before or use
 * trident_msgs__action__HoldPose_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
bool
trident_msgs__action__HoldPose_Result__init(trident_msgs__action__HoldPose_Result * msg);

/// Finalize action/HoldPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_Result__fini(trident_msgs__action__HoldPose_Result * msg);

/// Create action/HoldPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * trident_msgs__action__HoldPose_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
trident_msgs__action__HoldPose_Result *
trident_msgs__action__HoldPose_Result__create();

/// Destroy action/HoldPose message.
/**
 * It calls
 * trident_msgs__action__HoldPose_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_Result__destroy(trident_msgs__action__HoldPose_Result * msg);


/// Initialize array of action/HoldPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * trident_msgs__action__HoldPose_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
bool
trident_msgs__action__HoldPose_Result__Sequence__init(trident_msgs__action__HoldPose_Result__Sequence * array, size_t size);

/// Finalize array of action/HoldPose messages.
/**
 * It calls
 * trident_msgs__action__HoldPose_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_Result__Sequence__fini(trident_msgs__action__HoldPose_Result__Sequence * array);

/// Create array of action/HoldPose messages.
/**
 * It allocates the memory for the array and calls
 * trident_msgs__action__HoldPose_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
trident_msgs__action__HoldPose_Result__Sequence *
trident_msgs__action__HoldPose_Result__Sequence__create(size_t size);

/// Destroy array of action/HoldPose messages.
/**
 * It calls
 * trident_msgs__action__HoldPose_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_Result__Sequence__destroy(trident_msgs__action__HoldPose_Result__Sequence * array);

/// Initialize action/HoldPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * trident_msgs__action__HoldPose_Feedback
 * )) before or use
 * trident_msgs__action__HoldPose_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
bool
trident_msgs__action__HoldPose_Feedback__init(trident_msgs__action__HoldPose_Feedback * msg);

/// Finalize action/HoldPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_Feedback__fini(trident_msgs__action__HoldPose_Feedback * msg);

/// Create action/HoldPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * trident_msgs__action__HoldPose_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
trident_msgs__action__HoldPose_Feedback *
trident_msgs__action__HoldPose_Feedback__create();

/// Destroy action/HoldPose message.
/**
 * It calls
 * trident_msgs__action__HoldPose_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_Feedback__destroy(trident_msgs__action__HoldPose_Feedback * msg);


/// Initialize array of action/HoldPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * trident_msgs__action__HoldPose_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
bool
trident_msgs__action__HoldPose_Feedback__Sequence__init(trident_msgs__action__HoldPose_Feedback__Sequence * array, size_t size);

/// Finalize array of action/HoldPose messages.
/**
 * It calls
 * trident_msgs__action__HoldPose_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_Feedback__Sequence__fini(trident_msgs__action__HoldPose_Feedback__Sequence * array);

/// Create array of action/HoldPose messages.
/**
 * It allocates the memory for the array and calls
 * trident_msgs__action__HoldPose_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
trident_msgs__action__HoldPose_Feedback__Sequence *
trident_msgs__action__HoldPose_Feedback__Sequence__create(size_t size);

/// Destroy array of action/HoldPose messages.
/**
 * It calls
 * trident_msgs__action__HoldPose_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_Feedback__Sequence__destroy(trident_msgs__action__HoldPose_Feedback__Sequence * array);

/// Initialize action/HoldPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * trident_msgs__action__HoldPose_SendGoal_Request
 * )) before or use
 * trident_msgs__action__HoldPose_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
bool
trident_msgs__action__HoldPose_SendGoal_Request__init(trident_msgs__action__HoldPose_SendGoal_Request * msg);

/// Finalize action/HoldPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_SendGoal_Request__fini(trident_msgs__action__HoldPose_SendGoal_Request * msg);

/// Create action/HoldPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * trident_msgs__action__HoldPose_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
trident_msgs__action__HoldPose_SendGoal_Request *
trident_msgs__action__HoldPose_SendGoal_Request__create();

/// Destroy action/HoldPose message.
/**
 * It calls
 * trident_msgs__action__HoldPose_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_SendGoal_Request__destroy(trident_msgs__action__HoldPose_SendGoal_Request * msg);


/// Initialize array of action/HoldPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * trident_msgs__action__HoldPose_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
bool
trident_msgs__action__HoldPose_SendGoal_Request__Sequence__init(trident_msgs__action__HoldPose_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/HoldPose messages.
/**
 * It calls
 * trident_msgs__action__HoldPose_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_SendGoal_Request__Sequence__fini(trident_msgs__action__HoldPose_SendGoal_Request__Sequence * array);

/// Create array of action/HoldPose messages.
/**
 * It allocates the memory for the array and calls
 * trident_msgs__action__HoldPose_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
trident_msgs__action__HoldPose_SendGoal_Request__Sequence *
trident_msgs__action__HoldPose_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/HoldPose messages.
/**
 * It calls
 * trident_msgs__action__HoldPose_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_SendGoal_Request__Sequence__destroy(trident_msgs__action__HoldPose_SendGoal_Request__Sequence * array);

/// Initialize action/HoldPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * trident_msgs__action__HoldPose_SendGoal_Response
 * )) before or use
 * trident_msgs__action__HoldPose_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
bool
trident_msgs__action__HoldPose_SendGoal_Response__init(trident_msgs__action__HoldPose_SendGoal_Response * msg);

/// Finalize action/HoldPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_SendGoal_Response__fini(trident_msgs__action__HoldPose_SendGoal_Response * msg);

/// Create action/HoldPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * trident_msgs__action__HoldPose_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
trident_msgs__action__HoldPose_SendGoal_Response *
trident_msgs__action__HoldPose_SendGoal_Response__create();

/// Destroy action/HoldPose message.
/**
 * It calls
 * trident_msgs__action__HoldPose_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_SendGoal_Response__destroy(trident_msgs__action__HoldPose_SendGoal_Response * msg);


/// Initialize array of action/HoldPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * trident_msgs__action__HoldPose_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
bool
trident_msgs__action__HoldPose_SendGoal_Response__Sequence__init(trident_msgs__action__HoldPose_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/HoldPose messages.
/**
 * It calls
 * trident_msgs__action__HoldPose_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_SendGoal_Response__Sequence__fini(trident_msgs__action__HoldPose_SendGoal_Response__Sequence * array);

/// Create array of action/HoldPose messages.
/**
 * It allocates the memory for the array and calls
 * trident_msgs__action__HoldPose_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
trident_msgs__action__HoldPose_SendGoal_Response__Sequence *
trident_msgs__action__HoldPose_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/HoldPose messages.
/**
 * It calls
 * trident_msgs__action__HoldPose_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_SendGoal_Response__Sequence__destroy(trident_msgs__action__HoldPose_SendGoal_Response__Sequence * array);

/// Initialize action/HoldPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * trident_msgs__action__HoldPose_GetResult_Request
 * )) before or use
 * trident_msgs__action__HoldPose_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
bool
trident_msgs__action__HoldPose_GetResult_Request__init(trident_msgs__action__HoldPose_GetResult_Request * msg);

/// Finalize action/HoldPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_GetResult_Request__fini(trident_msgs__action__HoldPose_GetResult_Request * msg);

/// Create action/HoldPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * trident_msgs__action__HoldPose_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
trident_msgs__action__HoldPose_GetResult_Request *
trident_msgs__action__HoldPose_GetResult_Request__create();

/// Destroy action/HoldPose message.
/**
 * It calls
 * trident_msgs__action__HoldPose_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_GetResult_Request__destroy(trident_msgs__action__HoldPose_GetResult_Request * msg);


/// Initialize array of action/HoldPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * trident_msgs__action__HoldPose_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
bool
trident_msgs__action__HoldPose_GetResult_Request__Sequence__init(trident_msgs__action__HoldPose_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/HoldPose messages.
/**
 * It calls
 * trident_msgs__action__HoldPose_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_GetResult_Request__Sequence__fini(trident_msgs__action__HoldPose_GetResult_Request__Sequence * array);

/// Create array of action/HoldPose messages.
/**
 * It allocates the memory for the array and calls
 * trident_msgs__action__HoldPose_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
trident_msgs__action__HoldPose_GetResult_Request__Sequence *
trident_msgs__action__HoldPose_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/HoldPose messages.
/**
 * It calls
 * trident_msgs__action__HoldPose_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_GetResult_Request__Sequence__destroy(trident_msgs__action__HoldPose_GetResult_Request__Sequence * array);

/// Initialize action/HoldPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * trident_msgs__action__HoldPose_GetResult_Response
 * )) before or use
 * trident_msgs__action__HoldPose_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
bool
trident_msgs__action__HoldPose_GetResult_Response__init(trident_msgs__action__HoldPose_GetResult_Response * msg);

/// Finalize action/HoldPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_GetResult_Response__fini(trident_msgs__action__HoldPose_GetResult_Response * msg);

/// Create action/HoldPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * trident_msgs__action__HoldPose_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
trident_msgs__action__HoldPose_GetResult_Response *
trident_msgs__action__HoldPose_GetResult_Response__create();

/// Destroy action/HoldPose message.
/**
 * It calls
 * trident_msgs__action__HoldPose_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_GetResult_Response__destroy(trident_msgs__action__HoldPose_GetResult_Response * msg);


/// Initialize array of action/HoldPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * trident_msgs__action__HoldPose_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
bool
trident_msgs__action__HoldPose_GetResult_Response__Sequence__init(trident_msgs__action__HoldPose_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/HoldPose messages.
/**
 * It calls
 * trident_msgs__action__HoldPose_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_GetResult_Response__Sequence__fini(trident_msgs__action__HoldPose_GetResult_Response__Sequence * array);

/// Create array of action/HoldPose messages.
/**
 * It allocates the memory for the array and calls
 * trident_msgs__action__HoldPose_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
trident_msgs__action__HoldPose_GetResult_Response__Sequence *
trident_msgs__action__HoldPose_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/HoldPose messages.
/**
 * It calls
 * trident_msgs__action__HoldPose_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_GetResult_Response__Sequence__destroy(trident_msgs__action__HoldPose_GetResult_Response__Sequence * array);

/// Initialize action/HoldPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * trident_msgs__action__HoldPose_FeedbackMessage
 * )) before or use
 * trident_msgs__action__HoldPose_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
bool
trident_msgs__action__HoldPose_FeedbackMessage__init(trident_msgs__action__HoldPose_FeedbackMessage * msg);

/// Finalize action/HoldPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_FeedbackMessage__fini(trident_msgs__action__HoldPose_FeedbackMessage * msg);

/// Create action/HoldPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * trident_msgs__action__HoldPose_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
trident_msgs__action__HoldPose_FeedbackMessage *
trident_msgs__action__HoldPose_FeedbackMessage__create();

/// Destroy action/HoldPose message.
/**
 * It calls
 * trident_msgs__action__HoldPose_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_FeedbackMessage__destroy(trident_msgs__action__HoldPose_FeedbackMessage * msg);


/// Initialize array of action/HoldPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * trident_msgs__action__HoldPose_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
bool
trident_msgs__action__HoldPose_FeedbackMessage__Sequence__init(trident_msgs__action__HoldPose_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/HoldPose messages.
/**
 * It calls
 * trident_msgs__action__HoldPose_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_FeedbackMessage__Sequence__fini(trident_msgs__action__HoldPose_FeedbackMessage__Sequence * array);

/// Create array of action/HoldPose messages.
/**
 * It allocates the memory for the array and calls
 * trident_msgs__action__HoldPose_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
trident_msgs__action__HoldPose_FeedbackMessage__Sequence *
trident_msgs__action__HoldPose_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/HoldPose messages.
/**
 * It calls
 * trident_msgs__action__HoldPose_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trident_msgs
void
trident_msgs__action__HoldPose_FeedbackMessage__Sequence__destroy(trident_msgs__action__HoldPose_FeedbackMessage__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // TRIDENT_MSGS__ACTION__DETAIL__HOLD_POSE__FUNCTIONS_H_
