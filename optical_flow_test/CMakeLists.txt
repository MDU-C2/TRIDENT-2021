cmake_minimum_required(VERSION 3.0.0)
project(opticalFlow VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(opticalFlow opticalFlowMain.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_package(OpenCV 4.2 REQUIRED)
include_directories("/usr/include/opencv2")
include_directories("/usr/include/python3.6m")

target_link_libraries(opticalFlow PRIVATE ${OpenCV_LIBS})

add_subdirectory(matplotlib-cpp)