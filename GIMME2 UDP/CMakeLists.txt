cmake_minimum_required(VERSION 3.0.0)
project(GIMME2UDP VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(GIMME2UDP main.cpp)

find_package(OpenCV 4.2 REQUIRED)

target_link_libraries(GIMME2UDP PRIVATE ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
