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
        self.script_path = str(os.path.dirname(os.path.realpath(__file__)))
        self.node_name = self.chip + '_serial_firmware_update'
        rospy.init_node(self.node_name, anonymous=False)
    def upload(self):
        try:
            msg = "Starting Upload to "+self.chip + "!\n\n"
            msg = self.text_color.BOLD + self.text_color.OKBLUE + msg + self.text_color.ENDC
            rospy.loginfo(msg)
            upload_cmd = "platformio run --target upload --environment " + self.chip.lower() +  " -d " + self.script_path
            os.system(upload_cmd)
        except:
            print("Serial Upload Failed!")
        

if __name__ == '__main__':
    run = Remote_Embedded('MCU')
    run.upload()
    
