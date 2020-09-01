#include "local_config.h"

RosNode node;//DO NOT REMOVE
// node.connection_selector(1);
WizNet W5500;

// Wifi wifi_module;

void setup() {
    Serial.begin(9600);
    W5500.setup();//DO NOT REMOVE
    // wifi_module.setup();
    node.init();//DO NOT REMOVE
}

void loop() {
  while(true){
    node.check_connection(); //DO NOT REMOVE
    Serial.println("Looping...");
    node.pub_something();
    node.spin();//DO NOT REMOVE
    delay(40);
  }
}