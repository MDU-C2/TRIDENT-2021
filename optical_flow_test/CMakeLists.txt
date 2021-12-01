cmake_minimum_required(VERSION 3.0.0)
project(opticalFlow VERSION 0.1.0)      # Output: Not searching for unused variables given on the command line.

include(CTest)
enable_testing()

add_executable(opticalFlow opticalFlowMain.cpp)

# set(CMAKE_BINARY_DIR "/usr/share/CMake")
# set(CMAKE_ROOT INTERNAL "/usr/share/CMake")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_package(OpenCV 4.2 REQUIRED)
#include_directories("/usr/local/include/opencv4/opencv2")
include_directories("/usr/include/python3.6m")

include_directories("/home/lisa/Documents/opencv-4.5.4/opencv_contrib/modules/optflow/include")

target_link_libraries(opticalFlow PRIVATE ${OpenCV_LIBS})

#message("7")
# add_subdirectory(matplotlib-cpp)