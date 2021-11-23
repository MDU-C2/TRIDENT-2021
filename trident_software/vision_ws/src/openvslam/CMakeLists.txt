cmake_minimum_required(VERSION 3.5)
project(vision LANGUAGES CXX C)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
	set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

if(POLICY CMP0042)
    cmake_policy(SET CMP0042 NEW)
endif()
if(POLICY CMP0072)
    set(OpenGL_GL_PREFERENCE LEGACY)
endif()
if(POLICY CMP0074)
    cmake_policy(SET CMP0074 OLD)
endif()

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

#################
# Find packages #
#################

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# thread library
find_package(Threads REQUIRED)

# OpenVSLAM
find_package(openvslam REQUIRED)

# OpenCV
find_package(OpenCV 3.3.1 QUIET)
if(NOT OpenCV_FOUND)
    find_package(OpenCV 4.0)
    if(NOT OpenCV_FOUND)
        message(FATAL_ERROR "OpenCV >= 3.3.1 not found")
    endif()
endif()
message(STATUS "Use OpenCV ${OpenCV_VERSION}")
include_directories(${OpenCV_INCLUDE_DIRS})

# Eigen
find_package(Eigen3 3.3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

# yaml-cpp
find_package(yaml-cpp REQUIRED)

# popl
set(popl_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/3rd/popl/include)
include_directories(${popl_INCLUDE_DIR})

# socket publisher
set(USE_SOCKET_PUBLISHER ON CACHE BOOL "Enable Socket Publisher")
if(USE_SOCKET_PUBLISHER)
    find_package(sioclient REQUIRED)
    find_package(Protobuf REQUIRED)
    find_library(Socket_Publisher_LIB socket_publisher)
    if(NOT PROTOBUF_PROTOC_EXECUTABLE)
        message(FATAL_ERROR "Could not find protoc executable (PROTOBUF_PROTOC_EXECUTABLE)")
    endif()
    message(STATUS "Found protoc executable: ${PROTOBUF_PROTOC_EXECUTABLE}")
    include_directories(${SIOCLIENT_INCLUDE_DIR} ${PROTOBUF_INCLUDE_DIRS})
endif()

#########
# Build #
#########

add_executable(run_slam src/slam/run_real_slam.cc)
target_compile_definitions(run_slam PRIVATE -DUSE_SOCKET_PUBLISHER)
target_link_libraries(run_slam ${openvslam_LIBS} ${OpenCV_LIBRARIES} ${Socket_Publisher_LIB} ${SIOCLIENT_LIBRARY} ${PROTOBUF_LIBRARIES} socket_publisher yaml-cpp)
ament_target_dependencies(run_slam rclcpp)

add_executable(run_optflow src/optflow/run_optflow.cc)
ament_target_dependencies(run_optflow rclcpp std_msgs)
target_link_libraries(run_optflow ${openvslam_LIBS} ${OpenCV_LIBRARIES} ${PROTOBUF_LIBRARIES})

install(
	TARGETS run_slam run_optflow DESTINATION lib/${PROJECT_NAME}
)

ament_package()
