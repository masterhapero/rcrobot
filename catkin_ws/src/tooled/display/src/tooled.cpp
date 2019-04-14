#include <ros/ros.h>

#include "tooled_hidraw.h"

/**
 * source /opt/ros/kinetic/setup.bash
 * source /home/ubuntu/catkin_ws/devel/setup.bash
 * rosrun display tooled
 * rostopic pub -1 /oled/msg std_msgs/String "Test"
 *
 */


int main(int argc, char** argv)
{
  ros::init(argc, argv, "tooled_node");
  ros::NodeHandle nh;

  tooled::TooledHIDRaw TooledHIDRaw(nh);

  ros::spin();

  return 0;
}


