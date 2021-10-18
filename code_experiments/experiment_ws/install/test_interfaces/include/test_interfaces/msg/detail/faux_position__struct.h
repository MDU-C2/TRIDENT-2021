// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from test_interfaces:msg/FauxPosition.idl
// generated code does not contain a copyright notice

#ifndef TEST_INTERFACES__MSG__DETAIL__FAUX_POSITION__STRUCT_H_
#define TEST_INTERFACES__MSG__DETAIL__FAUX_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/FauxPosition in the package test_interfaces.
typedef struct test_interfaces__msg__FauxPosition
{
  double x;
  double y;
  double theta;
  double dx;
  double dy;
  double dtheta;
} test_interfaces__msg__FauxPosition;

// Struct for a sequence of test_interfaces__msg__FauxPosition.
typedef struct test_interfaces__msg__FauxPosition__Sequence
{
  test_interfaces__msg__FauxPosition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} test_interfaces__msg__FauxPosition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEST_INTERFACES__MSG__DETAIL__FAUX_POSITION__STRUCT_H_
