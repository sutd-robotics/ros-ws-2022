cmake_minimum_required(VERSION 2.8.3)
project(custom_msg_pub_sub)

find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
  custom_messages # here!
)

catkin_package(CATKIN_DEPENDS
    custom_messages # here!
)
