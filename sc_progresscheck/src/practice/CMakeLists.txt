cmake_minimum_required(VERSION 2.8.3)
project(practice)

set(CMAKE_CXX_STANDARD 11)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  tf
  simple_robot
  simple_msgs
)


catkin_package()


include_directories( include ${catkin_INCLUDE_DIRS})


add_executable(practice make_a_move.cpp)
target_link_libraries(practice ${catkin_LIBRARIES})

