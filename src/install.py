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
    def __init__(self):
        self.text_color = bcolors()
        self.script_path = str(os.path.dirname(os.path.realpath(__file__)))
        self.node_name = 'install_firmware'
        rospy.init_node(self.node_name, anonymous=False)
    def upload(self):
        try:
            msg = "Installing Platformio!\n\n"
            msg = self.text_color.BOLD + self.text_color.OKBLUE + msg + self.text_color.ENDC
            rospy.loginfo(msg)
            
            install_cmd = "pip install -U platformio"

            os.system(install_cmd)
            print("\n\n\n")
        except:
            print("Installation Failed!")
        
        msg = "Platformio Succefully Installed!"
        msg = self.text_color.BOLD + self.text_color.OKGREEN + msg + self.text_color.ENDC
        rospy.loginfo(msg)
if __name__ == '__main__':
    run = Remote_Embedded()
    run.upload()
    
