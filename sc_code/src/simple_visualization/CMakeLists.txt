cmake_minimum_required(VERSION 3.1)
project(simple_visualization)

set(CMAKE_CXX_STANDARD 11)

#############################
#Dependencies
#############################
find_package(catkin REQUIRED COMPONENTS
        roscpp
        nav_msgs
        visualization_msgs
        simple_msgs
        )
catkin_package()

include_directories(${catkin_INCLUDE_DIRS})

add_executable(simple_visualizer
        visualizer.cpp)
target_link_libraries(simple_visualizer
        ${catkin_LIBRARIES})
add_dependencies( simple_visualizer simple_msgs_generate_messages)
