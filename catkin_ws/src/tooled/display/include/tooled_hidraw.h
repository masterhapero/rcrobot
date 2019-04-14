
#include <ros/ros.h>
#include <std_msgs/String.h>
#include "vesc_msgs/VescStateStamped.h"
#include <sstream>

namespace tooled
{

  class TooledHIDRaw
  {
  public:
    TooledHIDRaw(ros::NodeHandle nh);

  private:
    ros::NodeHandle m_nh;
    ros::Subscriber oled_msg_sub;
    ros::Subscriber vesc_state_sub;
    int state;
    
    void vescStateCallback(vesc_msgs::VescStateStamped vescState);
    void oledMsgCallback(std_msgs::String msg);
  };
  
  
}

