#ifndef _ROS_xbot_sensors_Ultrasonic_h
#define _ROS_xbot_sensors_Ultrasonic_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace xbot_sensors
{

  class Ultrasonic : public ros::Msg
  {
    public:
      typedef float _front_us_type;
      _front_us_type front_us;
      typedef float _back_us_type;
      _back_us_type back_us;
      typedef float _left_us_type;
      _left_us_type left_us;
      typedef float _right_us_type;
      _right_us_type right_us;

    Ultrasonic():
      front_us(0),
      back_us(0),
      left_us(0),
      right_us(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_front_us;
      u_front_us.real = this->front_us;
      *(outbuffer + offset + 0) = (u_front_us.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_front_us.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_front_us.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_front_us.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->front_us);
      union {
        float real;
        uint32_t base;
      } u_back_us;
      u_back_us.real = this->back_us;
      *(outbuffer + offset + 0) = (u_back_us.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_back_us.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_back_us.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_back_us.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->back_us);
      union {
        float real;
        uint32_t base;
      } u_left_us;
      u_left_us.real = this->left_us;
      *(outbuffer + offset + 0) = (u_left_us.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_us.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_us.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_us.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_us);
      union {
        float real;
        uint32_t base;
      } u_right_us;
      u_right_us.real = this->right_us;
      *(outbuffer + offset + 0) = (u_right_us.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_us.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_us.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_us.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_us);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_front_us;
      u_front_us.base = 0;
      u_front_us.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_front_us.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_front_us.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_front_us.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->front_us = u_front_us.real;
      offset += sizeof(this->front_us);
      union {
        float real;
        uint32_t base;
      } u_back_us;
      u_back_us.base = 0;
      u_back_us.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_back_us.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_back_us.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_back_us.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->back_us = u_back_us.real;
      offset += sizeof(this->back_us);
      union {
        float real;
        uint32_t base;
      } u_left_us;
      u_left_us.base = 0;
      u_left_us.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_us.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_us.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_us.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_us = u_left_us.real;
      offset += sizeof(this->left_us);
      union {
        float real;
        uint32_t base;
      } u_right_us;
      u_right_us.base = 0;
      u_right_us.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_us.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_us.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_us.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_us = u_right_us.real;
      offset += sizeof(this->right_us);
     return offset;
    }

    const char * getType(){ return "xbot_sensors/Ultrasonic"; };
    const char * getMD5(){ return "3af30e16cf3057e5f50f5f818eac7465"; };

  };

}
#endif