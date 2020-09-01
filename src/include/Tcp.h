#ifndef TCP_H
#define TCP_H
// #include "local_config.h"

#include<Arduino.h>
#include <Ethernet.h>
#include <WiFi.h>
#include <ArduinoOTA.h>

class RobotConfig{
public:
uint8_t maca[6] = { 0x02, 0xF0, 0x0D, 0xBE, 0xEF, 0x01 };
int g = 1;

};

class WizNet{
  public:
  WizNet() {};
  void WizReset();
  void check_w5500();
  void prt_hwval(uint8_t refval);
  void prt_ethval(uint8_t refval);
  void setup();
};

class Wifi{
  public:
  void setup();
};

class EthernetHardware {
  public:
  EthernetHardware() {};
  void init();
  // read a byte from the serial port. -1 = failure
  int read();
  // write data to the connection to ROS
  void write(uint8_t* data, int length);
  // returns milliseconds since start of program
  unsigned long time();
};

class WiFiHardware {
  public:
  WiFiHardware() {};
  void init();
  // read a byte from the serial port. -1 = failure
  int read();
  // write data to the connection to ROS
  void write(uint8_t* data, int length);
  // returns milliseconds since start of program
  unsigned long time();
};

#endif