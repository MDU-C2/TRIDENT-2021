// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from trident_msgs:srv/KalmanSensorService.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__SRV__DETAIL__KALMAN_SENSOR_SERVICE__STRUCT_HPP_
#define TRIDENT_MSGS__SRV__DETAIL__KALMAN_SENSOR_SERVICE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__trident_msgs__srv__KalmanSensorService_Request __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__srv__KalmanSensorService_Request __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct KalmanSensorService_Request_
{
  using Type = KalmanSensorService_Request_<ContainerAllocator>;

  explicit KalmanSensorService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit KalmanSensorService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _state_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _state_type state;
  using _covar_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _covar_type covar;

  // setters for named parameter idiom
  Type & set__state(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__covar(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->covar = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::srv::KalmanSensorService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::srv::KalmanSensorService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::srv::KalmanSensorService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::srv::KalmanSensorService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::srv::KalmanSensorService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::srv::KalmanSensorService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::srv::KalmanSensorService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::srv::KalmanSensorService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::srv::KalmanSensorService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::srv::KalmanSensorService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__srv__KalmanSensorService_Request
    std::shared_ptr<trident_msgs::srv::KalmanSensorService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__srv__KalmanSensorService_Request
    std::shared_ptr<trident_msgs::srv::KalmanSensorService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const KalmanSensorService_Request_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    if (this->covar != other.covar) {
      return false;
    }
    return true;
  }
  bool operator!=(const KalmanSensorService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct KalmanSensorService_Request_

// alias to use template instance with default allocator
using KalmanSensorService_Request =
  trident_msgs::srv::KalmanSensorService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace trident_msgs


#ifndef _WIN32
# define DEPRECATED__trident_msgs__srv__KalmanSensorService_Response __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__srv__KalmanSensorService_Response __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct KalmanSensorService_Response_
{
  using Type = KalmanSensorService_Response_<ContainerAllocator>;

  explicit KalmanSensorService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit KalmanSensorService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _residual_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _residual_type residual;
  using _gain_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _gain_type gain;
  using _observationmatrix_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _observationmatrix_type observationmatrix;

  // setters for named parameter idiom
  Type & set__residual(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->residual = _arg;
    return *this;
  }
  Type & set__gain(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->gain = _arg;
    return *this;
  }
  Type & set__observationmatrix(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->observationmatrix = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::srv::KalmanSensorService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::srv::KalmanSensorService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::srv::KalmanSensorService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::srv::KalmanSensorService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::srv::KalmanSensorService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::srv::KalmanSensorService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::srv::KalmanSensorService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::srv::KalmanSensorService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::srv::KalmanSensorService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::srv::KalmanSensorService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__srv__KalmanSensorService_Response
    std::shared_ptr<trident_msgs::srv::KalmanSensorService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__srv__KalmanSensorService_Response
    std::shared_ptr<trident_msgs::srv::KalmanSensorService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const KalmanSensorService_Response_ & other) const
  {
    if (this->residual != other.residual) {
      return false;
    }
    if (this->gain != other.gain) {
      return false;
    }
    if (this->observationmatrix != other.observationmatrix) {
      return false;
    }
    return true;
  }
  bool operator!=(const KalmanSensorService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct KalmanSensorService_Response_

// alias to use template instance with default allocator
using KalmanSensorService_Response =
  trident_msgs::srv::KalmanSensorService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace trident_msgs

namespace trident_msgs
{

namespace srv
{

struct KalmanSensorService
{
  using Request = trident_msgs::srv::KalmanSensorService_Request;
  using Response = trident_msgs::srv::KalmanSensorService_Response;
};

}  // namespace srv

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__SRV__DETAIL__KALMAN_SENSOR_SERVICE__STRUCT_HPP_
