
#include "tooled_hidraw.h"

extern "C"
{
#include "hid.h"
}

#define SCREENSIZE 168

namespace tooled
{

  TooledHIDRaw::TooledHIDRaw(ros::NodeHandle nh)
    : m_nh(nh)
  {
    int r;
    r = rawhid_open(1, 0x2341, 0x8036, 0xFFC0, 0x0C00);
    if (r <= 0) {
      printf("no rawhid device found\n");
      state = -1;
    } else {
      printf("found rawhid device\n");
      state = 0;
    }

    oled_msg_sub = nh.subscribe("oled/msg", 1, &TooledHIDRaw::oledMsgCallback, this);
    vesc_state_sub = nh.subscribe("sensors/core", 1, &TooledHIDRaw::vescStateCallback, this);
  }


  void TooledHIDRaw::vescStateCallback(vesc_msgs::VescStateStamped vescState)
  {
    // To be implemented
  }

  void TooledHIDRaw::oledMsgCallback(std_msgs::String msg)
  {
    char buf[200];
    int len; 

    // Received message
    ROS_INFO("%s %ld", msg.data.c_str(),strlen(msg.data.c_str()));
    len = strlen(msg.data.c_str());
    if(len > SCREENSIZE)
      len = SCREENSIZE;
    memset(buf,' ',SCREENSIZE);
    memcpy(buf,msg.data.c_str(),len);
    rawhid_send(0, buf, SCREENSIZE, 100);

  }
  
}

