#ifndef _ROS_driving_signals_Signals_h
#define _ROS_driving_signals_Signals_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace driving_signals
{

  class Signals : public ros::Msg
  {
    public:
      typedef uint8_t _turn_right_type;
      _turn_right_type turn_right;
      typedef uint8_t _turn_left_type;
      _turn_left_type turn_left;
      typedef uint8_t _backward_type;
      _backward_type backward;
      typedef uint8_t _forward_type;
      _forward_type forward;

    Signals():
      turn_right(0),
      turn_left(0),
      backward(0),
      forward(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->turn_right >> (8 * 0)) & 0xFF;
      offset += sizeof(this->turn_right);
      *(outbuffer + offset + 0) = (this->turn_left >> (8 * 0)) & 0xFF;
      offset += sizeof(this->turn_left);
      *(outbuffer + offset + 0) = (this->backward >> (8 * 0)) & 0xFF;
      offset += sizeof(this->backward);
      *(outbuffer + offset + 0) = (this->forward >> (8 * 0)) & 0xFF;
      offset += sizeof(this->forward);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->turn_right =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->turn_right);
      this->turn_left =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->turn_left);
      this->backward =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->backward);
      this->forward =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->forward);
     return offset;
    }

    const char * getType(){ return "driving_signals/Signals"; };
    const char * getMD5(){ return "89468382761d3c0b80356b7c399cac83"; };

  };

}
#endif
