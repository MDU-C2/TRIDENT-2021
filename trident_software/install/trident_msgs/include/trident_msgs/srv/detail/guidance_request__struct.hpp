// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from trident_msgs:srv/GuidanceRequest.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__SRV__DETAIL__GUIDANCE_REQUEST__STRUCT_HPP_
#define TRIDENT_MSGS__SRV__DETAIL__GUIDANCE_REQUEST__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__trident_msgs__srv__GuidanceRequest_Request __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__srv__GuidanceRequest_Request __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GuidanceRequest_Request_
{
  using Type = GuidanceRequest_Request_<ContainerAllocator>;

  explicit GuidanceRequest_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->duration = 0ll;
    }
  }

  explicit GuidanceRequest_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->duration = 0ll;
    }
  }

  // field types and members
  using _duration_type =
    int64_t;
  _duration_type duration;

  // setters for named parameter idiom
  Type & set__duration(
    const int64_t & _arg)
  {
    this->duration = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::srv::GuidanceRequest_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::srv::GuidanceRequest_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::srv::GuidanceRequest_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::srv::GuidanceRequest_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::srv::GuidanceRequest_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::srv::GuidanceRequest_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::srv::GuidanceRequest_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::srv::GuidanceRequest_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::srv::GuidanceRequest_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::srv::GuidanceRequest_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__srv__GuidanceRequest_Request
    std::shared_ptr<trident_msgs::srv::GuidanceRequest_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__srv__GuidanceRequest_Request
    std::shared_ptr<trident_msgs::srv::GuidanceRequest_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GuidanceRequest_Request_ & other) const
  {
    if (this->duration != other.duration) {
      return false;
    }
    return true;
  }
  bool operator!=(const GuidanceRequest_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GuidanceRequest_Request_

// alias to use template instance with default allocator
using GuidanceRequest_Request =
  trident_msgs::srv::GuidanceRequest_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace trident_msgs


// Include directives for member types
// Member 'reference_position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__trident_msgs__srv__GuidanceRequest_Response __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__srv__GuidanceRequest_Response __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GuidanceRequest_Response_
{
  using Type = GuidanceRequest_Response_<ContainerAllocator>;

  explicit GuidanceRequest_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reference_position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
      this->message = "";
    }
  }

  explicit GuidanceRequest_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : reference_position(_alloc, _init),
    message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
      this->message = "";
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _reference_position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _reference_position_type reference_position;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__reference_position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->reference_position = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::srv::GuidanceRequest_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::srv::GuidanceRequest_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::srv::GuidanceRequest_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::srv::GuidanceRequest_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::srv::GuidanceRequest_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::srv::GuidanceRequest_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::srv::GuidanceRequest_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::srv::GuidanceRequest_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::srv::GuidanceRequest_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::srv::GuidanceRequest_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__srv__GuidanceRequest_Response
    std::shared_ptr<trident_msgs::srv::GuidanceRequest_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__srv__GuidanceRequest_Response
    std::shared_ptr<trident_msgs::srv::GuidanceRequest_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GuidanceRequest_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->reference_position != other.reference_position) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const GuidanceRequest_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GuidanceRequest_Response_

// alias to use template instance with default allocator
using GuidanceRequest_Response =
  trident_msgs::srv::GuidanceRequest_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace trident_msgs

namespace trident_msgs
{

namespace srv
{

struct GuidanceRequest
{
  using Request = trident_msgs::srv::GuidanceRequest_Request;
  using Response = trident_msgs::srv::GuidanceRequest_Response;
};

}  // namespace srv

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__SRV__DETAIL__GUIDANCE_REQUEST__STRUCT_HPP_
