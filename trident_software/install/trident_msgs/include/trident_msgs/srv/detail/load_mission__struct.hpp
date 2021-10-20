// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from trident_msgs:srv/LoadMission.idl
// generated code does not contain a copyright notice

#ifndef TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION__STRUCT_HPP_
#define TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'mission'
#include "trident_msgs/msg/detail/mission__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__trident_msgs__srv__LoadMission_Request __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__srv__LoadMission_Request __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LoadMission_Request_
{
  using Type = LoadMission_Request_<ContainerAllocator>;

  explicit LoadMission_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : mission(_init)
  {
    (void)_init;
  }

  explicit LoadMission_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : mission(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _mission_type =
    trident_msgs::msg::Mission_<ContainerAllocator>;
  _mission_type mission;

  // setters for named parameter idiom
  Type & set__mission(
    const trident_msgs::msg::Mission_<ContainerAllocator> & _arg)
  {
    this->mission = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trident_msgs::srv::LoadMission_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::srv::LoadMission_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::srv::LoadMission_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::srv::LoadMission_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::srv::LoadMission_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::srv::LoadMission_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::srv::LoadMission_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::srv::LoadMission_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::srv::LoadMission_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::srv::LoadMission_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__srv__LoadMission_Request
    std::shared_ptr<trident_msgs::srv::LoadMission_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__srv__LoadMission_Request
    std::shared_ptr<trident_msgs::srv::LoadMission_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadMission_Request_ & other) const
  {
    if (this->mission != other.mission) {
      return false;
    }
    return true;
  }
  bool operator!=(const LoadMission_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadMission_Request_

// alias to use template instance with default allocator
using LoadMission_Request =
  trident_msgs::srv::LoadMission_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace trident_msgs


#ifndef _WIN32
# define DEPRECATED__trident_msgs__srv__LoadMission_Response __attribute__((deprecated))
#else
# define DEPRECATED__trident_msgs__srv__LoadMission_Response __declspec(deprecated)
#endif

namespace trident_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LoadMission_Response_
{
  using Type = LoadMission_Response_<ContainerAllocator>;

  explicit LoadMission_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit LoadMission_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
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
    trident_msgs::srv::LoadMission_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const trident_msgs::srv::LoadMission_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trident_msgs::srv::LoadMission_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trident_msgs::srv::LoadMission_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trident_msgs::srv::LoadMission_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::srv::LoadMission_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trident_msgs::srv::LoadMission_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trident_msgs::srv::LoadMission_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trident_msgs::srv::LoadMission_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trident_msgs::srv::LoadMission_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trident_msgs__srv__LoadMission_Response
    std::shared_ptr<trident_msgs::srv::LoadMission_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trident_msgs__srv__LoadMission_Response
    std::shared_ptr<trident_msgs::srv::LoadMission_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadMission_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const LoadMission_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadMission_Response_

// alias to use template instance with default allocator
using LoadMission_Response =
  trident_msgs::srv::LoadMission_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace trident_msgs

namespace trident_msgs
{

namespace srv
{

struct LoadMission
{
  using Request = trident_msgs::srv::LoadMission_Request;
  using Response = trident_msgs::srv::LoadMission_Response;
};

}  // namespace srv

}  // namespace trident_msgs

#endif  // TRIDENT_MSGS__SRV__DETAIL__LOAD_MISSION__STRUCT_HPP_
