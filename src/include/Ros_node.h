#ifndef ROS_NODE_H
#define ROS_NODE_H

// #include <local_config.h>
#include "Tcp.h"

#include <Arduino.h>
// To use the TCP version of rosserial_arduino
// #define ROSSERIAL_ARDUINO_TCP
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Int64.h>

class RosNode{

public:
    void connection_selector(int connect_type);
    void init();
    void check_connection();
    void spin();
    void pub_something();
};
#endif
