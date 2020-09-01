#include <Arduino.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Int64.h>
// #include <String.h>

// To use the TCP version of rosserial_arduino
#define ROSSERIAL_ARDUINO_TCP

const char* ssid = "AutoBot1_2G";
const char* password = "mse2021cap";

// Set the rosserial socket server IP address
IPAddress server_ip(192, 168, 100, 52);

// Set the rosserial socket server port
const uint16_t serverPort = 11411;

//variabls for blinking an LED with Millis
const int led = 2; // ESP32 Pin to which onboard LED is connected
unsigned long previousMillis = 0;  // will store last time LED was updated
const long interval = 1000;  // interval at which to blink (milliseconds)
int ledState = LOW;  // ledState used to set the LED
char warn[] = "Connected!";

int i;

void chatterCallback(const std_msgs::String& msg) {
  i = atoi(msg.data);
}

ros::Subscriber<std_msgs::String> sub("message", &chatterCallback);
ros::NodeHandle nh;
std_msgs::String str_msg;
ros::Publisher pub("foo", &str_msg);

// std_msgs::Int64 FR_msg; //Front Right top wheel
// ros::Publisher FR_debug("/base/fr_wheel/encoder", &FR_msg);

void setup() {
  Serial.begin(9600);
  Serial.println("Booting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  ArduinoOTA
    .onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else // U_SPIFFS
        type = "filesystem";

      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      Serial.println("Start updating " + type);
    })
    .onEnd([]() {
      Serial.println("\nEnd");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR) Serial.println("End Failed");
    });

  ArduinoOTA.begin();

  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Set the connection to rosserial socket server
  nh.getHardware()->setConnection(server_ip, serverPort);
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(pub);
}

void loop() {
  while(true){
    if(!nh.connected()){
      Serial.println("Not Connected");
    }
    str_msg.data = "WALAAA";
    pub.publish( &str_msg );
    nh.logwarn(warn);
    ArduinoOTA.handle();
    nh.spinOnce();
    // ArduinoOTA.poll();
    delay(10);
  }
}