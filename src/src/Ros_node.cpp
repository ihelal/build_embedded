#include "Ros_node.h"

ros::NodeHandle_<EthernetHardware> DCU;
// ros::NodeHandle_<WiFiHardware> DCU;

char warn[] = "Connected!";
std_msgs::Int64 FR_msg; //Front Right top wheel
ros::Publisher FR_debug("/base/fr_wheel/encoder", &FR_msg);

void RosNode::connection_selector(int connect_type){
    
}

void RosNode::init(){
DCU.initNode();
Serial.print("ROS = ");
DCU.advertise(FR_debug);
}

void RosNode::check_connection(){
    if(!DCU.connected()){
      Serial.println("Lost ROS Connection");
    }
}

void RosNode::spin(){
    DCU.logwarn(warn);
    DCU.spinOnce();
}

void RosNode::pub_something(){
    FR_msg.data = 1;
    FR_debug.publish(&FR_msg);

}