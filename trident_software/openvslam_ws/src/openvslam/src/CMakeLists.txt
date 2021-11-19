if(USE_PANGOLIN_VIEWER)
    message(STATUS "Viewer for examples: pangolin viewer")
elseif(USE_SOCKET_PUBLISHER)
    message(STATUS "Viewer for examples: socket publisher")
else()
    message(STATUS "Viewer for examples: none")
endif()

set(EXECUTABLE_TARGETS "")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
add_executable(run_slam run_real_slam.cc)
list(APPEND EXECUTABLE_TARGETS run_slam)

foreach(EXECUTABLE_TARGET IN LISTS EXECUTABLE_TARGETS)
    # pangolin_viewer is used on a priority basis
    # set macro flag
    #target_compile_definitions(${EXECUTABLE_TARGET}
    #	    PRIVATE -DUSE_SOCKET_PUBLISHER)
    # link viewer
    target_link_libraries(${EXECUTABLE_TARGET} PRIVATE
	    #${Socket_Publisher_LIB} 
	    ${SIOCLIENT_LIBRARY} ${PROTOBUF_LIBRARIES} socket_publisher)

    # setup yaml-cpp
    target_link_libraries(${EXECUTABLE_TARGET} PRIVATE
        yaml-cpp)

    # build
    target_include_directories(${EXECUTABLE_TARGET}
                               PRIVATE ${OpenCV_INCLUDE_DIRS}
                               $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/3rd/popl/include>
                               $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/3rd/spdlog/include>)
    target_link_libraries(${EXECUTABLE_TARGET}
	    PRIVATE ${openvslam_LIBS} ${OpenCV_LIBRARIES} ${Socket_Publisher_LIB} ${SIOCLIENT_LIBRARY} ${PROTOBUF_LIBRARIES})

endforeach()
