cmake_minimum_required(VERSION 2.8.3)
project(simple_ros_package)

## Add support for C++11, supported in ROS Kinetic and newer
add_definitions(-std=c++11)

set(CATKIN_DEPS roscpp geometry_msgs tf)

find_package(catkin REQUIRED COMPONENTS
    ${CATKIN_DEPS}
)

catkin_package(
    INCLUDE_DIRS include
#   LIBRARIES test
    CATKIN_DEPENDS ${CATKIN_DEPS}
#   DEPENDS system_lib
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)


add_executable(simple_node src/simple_node.cpp)

target_link_libraries(simple_node
    ${catkin_LIBRARIES})

