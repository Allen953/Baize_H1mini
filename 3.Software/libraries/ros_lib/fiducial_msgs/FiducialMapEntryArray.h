#ifndef _ROS_fiducial_msgs_FiducialMapEntryArray_h
#define _ROS_fiducial_msgs_FiducialMapEntryArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fiducial_msgs/FiducialMapEntry.h"

namespace fiducial_msgs
{

  class FiducialMapEntryArray : public ros::Msg
  {
    public:
      uint32_t fiducials_length;
      typedef fiducial_msgs::FiducialMapEntry _fiducials_type;
      _fiducials_type st_fiducials;
      _fiducials_type * fiducials;

    FiducialMapEntryArray():
      fiducials_length(0), fiducials(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->fiducials_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fiducials_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fiducials_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fiducials_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fiducials_length);
      for( uint32_t i = 0; i < fiducials_length; i++){
      offset += this->fiducials[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t fiducials_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fiducials_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fiducials_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fiducials_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->fiducials_length);
      if(fiducials_lengthT > fiducials_length)
        this->fiducials = (fiducial_msgs::FiducialMapEntry*)realloc(this->fiducials, fiducials_lengthT * sizeof(fiducial_msgs::FiducialMapEntry));
      fiducials_length = fiducials_lengthT;
      for( uint32_t i = 0; i < fiducials_length; i++){
      offset += this->st_fiducials.deserialize(inbuffer + offset);
        memcpy( &(this->fiducials[i]), &(this->st_fiducials), sizeof(fiducial_msgs::FiducialMapEntry));
      }
     return offset;
    }

    const char * getType(){ return "fiducial_msgs/FiducialMapEntryArray"; };
    const char * getMD5(){ return "f3d7e1cb2717bda61be54acdb77f4f79"; };

  };

}
#endif
