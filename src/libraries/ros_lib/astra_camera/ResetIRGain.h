#ifndef _ROS_SERVICE_ResetIRGain_h
#define _ROS_SERVICE_ResetIRGain_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace astra_camera
{

static const char RESETIRGAIN[] = "astra_camera/ResetIRGain";

  class ResetIRGainRequest : public ros::Msg
  {
    public:

    ResetIRGainRequest()
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

    const char * getType(){ return RESETIRGAIN; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ResetIRGainResponse : public ros::Msg
  {
    public:

    ResetIRGainResponse()
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

    const char * getType(){ return RESETIRGAIN; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ResetIRGain {
    public:
    typedef ResetIRGainRequest Request;
    typedef ResetIRGainResponse Response;
  };

}
#endif
