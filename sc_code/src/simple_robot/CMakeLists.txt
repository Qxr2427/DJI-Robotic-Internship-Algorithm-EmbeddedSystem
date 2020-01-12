cmake_minimum_required(VERSION 3.1)
project(simple_robot)

set(CMAKE_CXX_STANDARD 11)

#############################
#Dependencies
#############################
find_package(Threads)
find_package(catkin REQUIRED COMPONENTS
    roscpp
    tf
    nav_msgs
    geometry_msgs
    simple_msgs
    )
catkin_package()

include_directories(${catkin_INCLUDE_DIRS})

add_executable(simple_robot
    robot_node.cpp
    crc.cpp
    serial_device.cpp)
target_link_libraries(simple_robot
    ${CMAKE_THREAD_LIBS_INIT}
    ${catkin_LIBRARIES})
add_dependencies(simple_robot simple_msgs_generate_messages)
