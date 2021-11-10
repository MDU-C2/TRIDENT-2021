cmake_minimum_required(VERSION 3.5)
project(naiad_pressure_sensor)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

set (CMAKE_SHARED_LINKER_FLAGS "-fPIC")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/naiad_pressure_sensor)
add_library(i2cdepth SHARED src/i2cdepth.c)

ament_export_targets(i2cdepth HAS_LIBRARY_TARGET)

install(
  DIRECTORY include/naiad_pressure_sensor
  DESTINATION include
)

install(
  TARGETS i2cdepth
  EXPORT i2cdepth
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)
