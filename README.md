# README #

This is ros package for embedded systems compatible with optiboot capable boards.

### On the Developer's Computer ###

### Tools Needed ###
* 1. Arduino Uno or any arduino to act as an ISP Programmer.
* 2. Arduino Mega based board which we will upload the new bootloader "Optiboot" to. 
* 3. Jumper Wires
* 4. USB Cable for Arduino Uno 

### First Time Bootloader Flash ###
1. Install Arduino IDE
2. Change sketchbook directory to ../build_embedded/src - refere to img1 in instructions 
3. Close the Arduino IDE and reopen it, then check Tools -> Boards -> Arduino Mega 2560 (Optiboot). Make sure the board exists
4. Connect the USB Cable to the Arduino Uno (ISP Programmer)
5. Connect the Arduino Mega to the Arduino Uno using the jumper wires - refere to img2 in the instructions
6. Open the Arduino IDE and open the example ArduinoISP sketch. File -> Examples -> ArduinoISP -. ArduinoISP
7. Choose the Arduino Uno as the Board and select the Port. Tools -> Board -> Arduino Uno
8. Make Arduino Uno act as the ISP Programmer. Tools -> Programmer -> Arduino as ISP
9. Burn the new optiboot Bootloader. Tools -> BurnBootloader
10. Unplug the USB cable from the arduino Uno and plug into the arduino mega
11. Select the new Arduino Mega 2560 Optiboot board. Tools -> Arduino Mega 2560 (Optiboot). Select Port.
12. Open the arduino sketch under in ../build_embedded/src/init_ota/init_ota.ino
13. Do not change the IP address or mac address as it is not supported for now.
14. Upload the sketch to the Arduino Mega based board

Now the board is ready to recieve updates over the air.


### How to use? ###

1. Burn Optiboot bootloader to arduino mega chip
2. Install pip -> sudo apt install python-pip
2. install platformio using pip install -U platformio
3. build ros package