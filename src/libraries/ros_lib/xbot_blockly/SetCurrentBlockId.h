#ifndef _ROS_SERVICE_SetCurrentBlockId_h
#define _ROS_SERVICE_SetCurrentBlockId_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace xbot_blockly
{

static const char SETCURRENTBLOCKID[] = "xbot_blockly/SetCurrentBlockId";

  class SetCurrentBlockIdRequest : public ros::Msg
  {
    public:
      typedef const char* _block_id_type;
      _block_id_type block_id;

    SetCurrentBlockIdRequest():
      block_id("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_block_id = strlen(this->block_id);
      varToArr(outbuffer + offset, length_block_id);
      offset += 4;
      memcpy(outbuffer + offset, this->block_id, length_block_id);
      offset += length_block_id;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_block_id;
      arrToVar(length_block_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_block_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_block_id-1]=0;
      this->block_id = (char *)(inbuffer + offset-1);
      offset += length_block_id;
     return offset;
    }

    const char * getType(){ return SETCURRENTBLOCKID; };
    const char * getMD5(){ return "cc6173f3373290b79e4146d870748ea6"; };

  };

  class SetCurrentBlockIdResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;

    SetCurrentBlockIdResponse():
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

    const char * getType(){ return SETCURRENTBLOCKID; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class SetCurrentBlockId {
    public:
    typedef SetCurrentBlockIdRequest Request;
    typedef SetCurrentBlockIdResponse Response;
  };

}
#endif
