#!/usr/bin/env python
import rospy
import time
import os

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

class Remote_Embedded():
    def __init__(self,chip_name):
        self.text_color = bcolors()
        self.chip = chip_name
        self.board_ip = "192.168.100.46"
        self.port = "3232"
        self.username = "arduino"
        self.password = "password"
        self.script_path = str(os.path.dirname(os.path.realpath(__file__)))
        self.firmware_path = "/workspace/build/" +self.chip.lower() + "/"

        self.ota_tool_path = "/tools/esp32/hardware/esp32/1.0.4/tools/espota.py"
        self.hex_file = "firmware.hex"
        self.bin_file = "firmware.bin" 
        self.hex_path = self.script_path + self.firmware_path + self.hex_file
        self.bin_path = self.script_path + self.firmware_path + self.bin_file
        
        self.node_name = self.chip + '_firmware_update'
        rospy.init_node(self.node_name, anonymous=False)
    def upload(self):
        try:
            msg = "Starting Firmware Upload to "+self.chip + "!"
            msg = self.text_color.BOLD + self.text_color.OKBLUE + msg + self.text_color.ENDC
            rospy.loginfo(msg)
            time.sleep(1)
            msg = "IP Adress: " + self.board_ip
            msg = self.text_color.BOLD + self.text_color.OKBLUE + msg + self.text_color.ENDC
            rospy.loginfo(msg)
            time.sleep(1)
            msg = "Port: " + self.port
            msg = self.text_color.BOLD + self.text_color.OKBLUE + msg + self.text_color.ENDC
            rospy.loginfo(msg)
            time.sleep(1)
            compile_cmd = "platformio run --environment " + self.chip.lower() +  " -d " + self.script_path
            upload_cmd  = "python " + self.script_path + self.ota_tool_path + " -i " + self.board_ip + " -p " + self.port + " --auth= -f " + self.bin_path
            os.system(compile_cmd)
            time.sleep(2)
            print("\n\n\n")
            os.system(upload_cmd)
        except:
            print("Firmware Upload Failed!")
        

if __name__ == '__main__':
    run = Remote_Embedded('MCU')
    run.upload()
    
