#ifndef _ROS_arbotix_msgs_Analog_h
#define _ROS_arbotix_msgs_Analog_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace arbotix_msgs
{

  class Analog : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _value_type;
      _value_type value;

    Analog():
      header(),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->value >> (8 * 0)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->value =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->value);
     return offset;
    }

    const char * getType(){ return "arbotix_msgs/Analog"; };
    const char * getMD5(){ return "90539346f3c3c8fc47f159ab9a6ff208"; };

  };

}
#endif
