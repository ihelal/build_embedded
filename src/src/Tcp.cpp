#include "Tcp.h"
uint8_t mac[6] = { 0x02, 0xF0, 0x0D, 0xBE, 0xEF, 0x01 };

IPAddress ip(192, 168, 1, 1);
IPAddress server_ip(192, 168, 1, 2);
const uint16_t serverPort = 11411;

//Ethernet
#define RESET_P	26 // Tie the Wiz820io/W5500 reset pin to ESP32 GPIO26 pin.	
EthernetClient ethernet_client;

// Wifi 
const char* ssid = "SHAW-E6D0C0";
const char* password = "25116A152833";
IPAddress ip_address;
int status = WL_IDLE_STATUS;
WiFiClient wifi_client;

void EthernetHardware::init() {
    // do your initialization here. this probably includes TCP server/client setup
    ethernet_client.connect(server_ip, serverPort);
}
  // read a byte from the serial port. -1 = failure
int EthernetHardware::read() {
    // implement this method so that it reads a byte from the TCP connection and returns it
    //  you may return -1 is there is an error; for example if the TCP connection is not open
    return ethernet_client.read();         //will return -1 when it will works
}
  // write data to the connection to ROS
void EthernetHardware::write(uint8_t* data, int length) {
    // implement this so that it takes the arguments and writes or prints them to the TCP connection
    for(int i=0; i<length; i++)
      ethernet_client.write(data[i]);
}
  // returns milliseconds since start of program
unsigned long EthernetHardware::time() {
     return millis(); // easy; did this one for you
}

void WiFiHardware::init() {
    wifi_client.connect(server_ip, serverPort);
}

int WiFiHardware::read() {
    return wifi_client.read();         //will return -1 when it will works
}

void WiFiHardware::write(uint8_t* data, int length) {
    for(int i=0; i<length; i++)
      wifi_client.write(data[i]);
}

unsigned long WiFiHardware::time() {
     return millis(); // easy; did this one for you
}

void WizNet::WizReset(){
  /*
    * Wiz W5500 reset function.  Change this for the specific reset
    * sequence required for your particular board or module.
 */
    Serial.print("Resetting Wiz W5500 Ethernet Board...  ");
    pinMode(RESET_P, OUTPUT);
    digitalWrite(RESET_P, HIGH);
    delay(250);
    digitalWrite(RESET_P, LOW);
    delay(50);
    digitalWrite(RESET_P, HIGH);
    delay(350);
    Serial.println("Done.");
}

void WizNet::check_w5500(){
 /*
     * Sanity checks for W5500 and cable connection.
     */
    Serial.print("Checking connection.");
    bool rdy_flag = false;
    for (uint8_t i = 0; i <= 20; i++) {
        if ((Ethernet.hardwareStatus() == EthernetNoHardware)
            || (Ethernet.linkStatus() == LinkOFF)) {
            Serial.print(".");
            rdy_flag = false;
            delay(80);
        } else {
            rdy_flag = true;
            break;
        }
    }
    if (rdy_flag == false) {
        Serial.println
            ("\n\r\tHardware fault, or cable problem... cannot continue.");
        Serial.print("Hardware Status: ");
        prt_hwval(Ethernet.hardwareStatus());
        Serial.print("   Cable Status: ");
        prt_ethval(Ethernet.linkStatus());
        while (true) {
            delay(10);          // Halt.
        }
    } else {
        Serial.println(" OK");
    }

}

void WizNet::prt_hwval(uint8_t refval) {
    switch (refval) {
    case 0:
        Serial.println("No hardware detected.");
        break;
    case 1:
        Serial.println("WizNet W5100 detected.");
        break;
    case 2:
        Serial.println("WizNet W5200 detected.");
        break;
    case 3:
        Serial.println("WizNet W5500 detected.");
        break;
    default:
        Serial.println
            ("UNKNOWN - Update espnow_gw.ino to match Ethernet.h");
    }
}

void WizNet::prt_ethval(uint8_t refval) {
    /*
    * Print the result of the ethernet connection
    * status enum as a string.
    * Ethernet.h currently contains these values:-
    *
    *  enum EthernetLinkStatus {
    *     Unknown,
    *     LinkON,
    *     LinkOFF
    *  };
    *
    */
    switch (refval) {
    case 0:
        Serial.println("Uknown status.");
        break;
    case 1:
        Serial.println("Link flagged as UP.");
        break;
    case 2:
        Serial.println("Link flagged as DOWN. Check cable connection.");
        break;
    default:
        Serial.println
            ("UNKNOWN - Update espnow_gw.ino to match Ethernet.h");
    }
}

void WizNet::setup(){
    Ethernet.init(5);
    WizReset();
    Serial.println("Starting ETHERNET connection...");
    Ethernet.begin(mac, ip);
    delay(1000);
    Serial.print("Ethernet IP is: ");
    Serial.println(Ethernet.localIP());
}

void Wifi::setup()
{
  WiFi.begin(ssid, password);
  Serial.print("\nConnecting to "); Serial.println(ssid);
  uint8_t i = 0;
  while (WiFi.status() != WL_CONNECTED && i++ < 20) delay(500);
  if(i == 21){
    Serial.print("Could not connect to"); Serial.println(ssid);
    while(1) delay(500);
  }
  Serial.print("Ready! Use ");
  Serial.print(WiFi.localIP());
  Serial.println(" to access client");
  delay(2000);
}