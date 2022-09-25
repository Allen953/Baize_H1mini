#ifndef _ROS_arbotix_msgs_Digital_h
#define _ROS_arbotix_msgs_Digital_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace arbotix_msgs
{

  class Digital : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _value_type;
      _value_type value;
      typedef uint8_t _direction_type;
      _direction_type direction;
      enum { LOW = 0 };
      enum { HIGH = 255 };
      enum { INPUT = 0 };
      enum { OUTPUT = 255 };

    Digital():
      header(),
      value(0),
      direction(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->value >> (8 * 0)) & 0xFF;
      offset += sizeof(this->value);
      *(outbuffer + offset + 0) = (this->direction >> (8 * 0)) & 0xFF;
      offset += sizeof(this->direction);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->value =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->value);
      this->direction =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->direction);
     return offset;
    }

    const char * getType(){ return "arbotix_msgs/Digital"; };
    const char * getMD5(){ return "84d79480c76268c7cdf109dc588e00c4"; };

  };

}
#endif
