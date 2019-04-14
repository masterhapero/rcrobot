


source /opt/ros/kinetic/setup.bash
source /home/ubuntu/catkin_ws/devel/setup.bash
rosrun display tooled
rostopic pub -1 /oled/msg std_msgs/String "Test"
rostopic pub -1 /oled/msg std_msgs/String "TestabcdefghijklmnopqTestabcdefghijklmnopq"


Raw HID implementation from
https://github.com/NicoHood/HID

Triple buffer from
https://github.com/p4checo/triplebuffer-sync