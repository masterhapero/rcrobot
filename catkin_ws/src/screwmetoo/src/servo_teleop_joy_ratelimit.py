#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Joy
from std_msgs.msg import UInt16
from std_msgs.msg import Float64

# Author: Sampsa Ranta
# This ROS Node converts Joystick inputs from the joy node to servo
# Throttle rate to 10Hz
#
# Note. Alternative mathod with better response could be to use 
# topic_tools/throttle on output as joystick publish is varied and unknown

def driveservo_callback(data):
    global motorspeed
    global servoaout
    global puba
    global pubb
    outa = Float64()
    outb = UInt16()
    outa.data = motorspeed
    outb.data = servoaout
    puba.publish(outa)
    pubb.publish(outb)

#def joy_callback(data):
#    servoaout = 3000+500*data.axes[1]
#    servobout = 3000-700*data.axes[2]
def joy_callback(data):
    global motorspeed
    global servoaout
#    motorspeed = -5000*data.axes[1]
    motorspeed = -2500*data.axes[1]
    servoaout = 3000+1000*data.axes[0]

    #    global servobout
    #    servobout = 3000-700*data.axes[2]

def start():
    global puba
    global pubb
    global motorspeed
    global servoaout
    motorspeed=0
    servoaout=3000
    puba = rospy.Publisher('/commands/motor/unsmoothed_speed', Float64)
    pubb = rospy.Publisher('/servoa', UInt16)
    rospy.Subscriber("joy", Joy, joy_callback)
    rospy.init_node('servo_teleop_joy_ratelimit')
    rospy.Timer(rospy.Duration(0.04), driveservo_callback)
    rospy.spin()

if __name__ == '__main__':
    start()

