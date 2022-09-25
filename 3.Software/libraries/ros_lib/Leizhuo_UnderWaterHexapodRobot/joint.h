#ifndef _ROS_Leizhuo_UnderWaterHexapodRobot_joint_h
#define _ROS_Leizhuo_UnderWaterHexapodRobot_joint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace Leizhuo_UnderWaterHexapodRobot
{

  class joint : public ros::Msg
  {
    public:
      float position[18];

    joint():
      position()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 18; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->position[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 18; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position[i]));
      }
     return offset;
    }

    const char * getType(){ return "Leizhuo_UnderWaterHexapodRobot/joint"; };
    const char * getMD5(){ return "dd483e3ca2831ab7860bfba133ab8717"; };

  };

}
#endif
