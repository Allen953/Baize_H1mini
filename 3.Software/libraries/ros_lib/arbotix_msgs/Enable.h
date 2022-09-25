#ifndef _ROS_SERVICE_Enable_h
#define _ROS_SERVICE_Enable_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arbotix_msgs
{

static const char ENABLE[] = "arbotix_msgs/Enable";

  class EnableRequest : public ros::Msg
  {
    public:
      typedef bool _enable_type;
      _enable_type enable;

    EnableRequest():
      enable(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enable;
      u_enable.real = this->enable;
      *(outbuffer + offset + 0) = (u_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enable;
      u_enable.base = 0;
      u_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable = u_enable.real;
      offset += sizeof(this->enable);
     return offset;
    }

    const char * getType(){ return ENABLE; };
    const char * getMD5(){ return "8c1211af706069c994c06e00eb59ac9e"; };

  };

  class EnableResponse : public ros::Msg
  {
    public:
      typedef bool _state_type;
      _state_type state;

    EnableResponse():
      state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_state;
      u_state.real = this->state;
      *(outbuffer + offset + 0) = (u_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_state;
      u_state.base = 0;
      u_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->state = u_state.real;
      offset += sizeof(this->state);
     return offset;
    }

    const char * getType(){ return ENABLE; };
    const char * getMD5(){ return "001fde3cab9e313a150416ff09c08ee4"; };

  };

  class Enable {
    public:
    typedef EnableRequest Request;
    typedef EnableResponse Response;
  };

}
#endif
