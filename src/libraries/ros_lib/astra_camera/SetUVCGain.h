#ifndef _ROS_SERVICE_SetUVCGain_h
#define _ROS_SERVICE_SetUVCGain_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace astra_camera
{

static const char SETUVCGAIN[] = "astra_camera/SetUVCGain";

  class SetUVCGainRequest : public ros::Msg
  {
    public:
      typedef int32_t _gain_type;
      _gain_type gain;

    SetUVCGainRequest():
      gain(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_gain;
      u_gain.real = this->gain;
      *(outbuffer + offset + 0) = (u_gain.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gain.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gain.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gain.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gain);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_gain;
      u_gain.base = 0;
      u_gain.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gain.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gain.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gain.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gain = u_gain.real;
      offset += sizeof(this->gain);
     return offset;
    }

    const char * getType(){ return SETUVCGAIN; };
    const char * getMD5(){ return "164d2201bda8580473ff7023ba27f703"; };

  };

  class SetUVCGainResponse : public ros::Msg
  {
    public:

    SetUVCGainResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SETUVCGAIN; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetUVCGain {
    public:
    typedef SetUVCGainRequest Request;
    typedef SetUVCGainResponse Response;
  };

}
#endif
