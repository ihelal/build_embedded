#ifndef _ROS_SERVICE_Pair_h
#define _ROS_SERVICE_Pair_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace xbot_control
{

static const char PAIR[] = "xbot_control/Pair";

  class PairRequest : public ros::Msg
  {
    public:
      typedef const char* _pair_type;
      _pair_type pair;

    PairRequest():
      pair("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_pair = strlen(this->pair);
      varToArr(outbuffer + offset, length_pair);
      offset += 4;
      memcpy(outbuffer + offset, this->pair, length_pair);
      offset += length_pair;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_pair;
      arrToVar(length_pair, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_pair; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_pair-1]=0;
      this->pair = (char *)(inbuffer + offset-1);
      offset += length_pair;
     return offset;
    }

    const char * getType(){ return PAIR; };
    const char * getMD5(){ return "dd034dc618037894bbf4c7bed37cacc3"; };

  };

  class PairResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;

    PairResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return PAIR; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class Pair {
    public:
    typedef PairRequest Request;
    typedef PairResponse Response;
  };

}
#endif
