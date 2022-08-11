cmake_minimum_required(VERSION 2.8.3)

project(Urdf_ConfigFiles)

find_package(catkin REQUIRED)

catkin_package()

find_package(roslaunch)

find_package(catkin REQUIRED COMPONENTS
  controller_manager
  gazebo_ros
  gazebo_ros_control
  joint_state_publisher
  robot_state_publisher
  roscpp
  rospy
  rviz
  xacro
  kdl_parser
  tf
  sensor_msgs
  std_msgs
  trac_ik_lib
  serial
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${orocos_kdl_INCLUDE_DIRS}
)

add_executable(Baize_HexapodRobot_Arduino src/Baize_HexapodRobot_Arduino.cpp)
target_link_libraries(Baize_HexapodRobot_Arduino ${catkin_LIBRARIES} ${orocos_kdl_LIBRARIES})

foreach(dir config launch meshes urdf)
	install(DIRECTORY ${dir}/
		DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)
