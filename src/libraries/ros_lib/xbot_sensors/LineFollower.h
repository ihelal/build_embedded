#ifndef _ROS_xbot_sensors_LineFollower_h
#define _ROS_xbot_sensors_LineFollower_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace xbot_sensors
{

  class LineFollower : public ros::Msg
  {
    public:
      typedef bool _left_ir_type;
      _left_ir_type left_ir;
      typedef bool _center_ir_type;
      _center_ir_type center_ir;
      typedef bool _right_ir_type;
      _right_ir_type right_ir;

    LineFollower():
      left_ir(0),
      center_ir(0),
      right_ir(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_left_ir;
      u_left_ir.real = this->left_ir;
      *(outbuffer + offset + 0) = (u_left_ir.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->left_ir);
      union {
        bool real;
        uint8_t base;
      } u_center_ir;
      u_center_ir.real = this->center_ir;
      *(outbuffer + offset + 0) = (u_center_ir.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->center_ir);
      union {
        bool real;
        uint8_t base;
      } u_right_ir;
      u_right_ir.real = this->right_ir;
      *(outbuffer + offset + 0) = (u_right_ir.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->right_ir);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_left_ir;
      u_left_ir.base = 0;
      u_left_ir.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->left_ir = u_left_ir.real;
      offset += sizeof(this->left_ir);
      union {
        bool real;
        uint8_t base;
      } u_center_ir;
      u_center_ir.base = 0;
      u_center_ir.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->center_ir = u_center_ir.real;
      offset += sizeof(this->center_ir);
      union {
        bool real;
        uint8_t base;
      } u_right_ir;
      u_right_ir.base = 0;
      u_right_ir.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->right_ir = u_right_ir.real;
      offset += sizeof(this->right_ir);
     return offset;
    }

    const char * getType(){ return "xbot_sensors/LineFollower"; };
    const char * getMD5(){ return "ee4892cb549b9b5af2ce7aee414944e8"; };

  };

}
#endif