#ifndef _ROS_SERVICE_InitializeMap_h
#define _ROS_SERVICE_InitializeMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fiducial_msgs/FiducialMapEntryArray.h"

namespace fiducial_msgs
{

static const char INITIALIZEMAP[] = "fiducial_msgs/InitializeMap";

  class InitializeMapRequest : public ros::Msg
  {
    public:
      typedef fiducial_msgs::FiducialMapEntryArray _fiducials_type;
      _fiducials_type fiducials;

    InitializeMapRequest():
      fiducials()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->fiducials.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->fiducials.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return INITIALIZEMAP; };
    const char * getMD5(){ return "af3be60cc8712d87e234a795a01490e4"; };

  };

  class InitializeMapResponse : public ros::Msg
  {
    public:

    InitializeMapResponse()
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

    const char * getType(){ return INITIALIZEMAP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class InitializeMap {
    public:
    typedef InitializeMapRequest Request;
    typedef InitializeMapResponse Response;
  };

}
#endif
