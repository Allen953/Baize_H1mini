#ifndef _ROS_fiducial_msgs_FiducialArray_h
#define _ROS_fiducial_msgs_FiducialArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "fiducial_msgs/Fiducial.h"

namespace fiducial_msgs
{

  class FiducialArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _image_seq_type;
      _image_seq_type image_seq;
      uint32_t fiducials_length;
      typedef fiducial_msgs::Fiducial _fiducials_type;
      _fiducials_type st_fiducials;
      _fiducials_type * fiducials;

    FiducialArray():
      header(),
      image_seq(0),
      fiducials_length(0), fiducials(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_image_seq;
      u_image_seq.real = this->image_seq;
      *(outbuffer + offset + 0) = (u_image_seq.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_image_seq.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_image_seq.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_image_seq.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->image_seq);
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
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_image_seq;
      u_image_seq.base = 0;
      u_image_seq.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_image_seq.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_image_seq.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_image_seq.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->image_seq = u_image_seq.real;
      offset += sizeof(this->image_seq);
      uint32_t fiducials_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fiducials_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fiducials_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fiducials_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->fiducials_length);
      if(fiducials_lengthT > fiducials_length)
        this->fiducials = (fiducial_msgs::Fiducial*)realloc(this->fiducials, fiducials_lengthT * sizeof(fiducial_msgs::Fiducial));
      fiducials_length = fiducials_lengthT;
      for( uint32_t i = 0; i < fiducials_length; i++){
      offset += this->st_fiducials.deserialize(inbuffer + offset);
        memcpy( &(this->fiducials[i]), &(this->st_fiducials), sizeof(fiducial_msgs::Fiducial));
      }
     return offset;
    }

    const char * getType(){ return "fiducial_msgs/FiducialArray"; };
    const char * getMD5(){ return "fd851a0658e8a35a4d4f80b76d9f17a0"; };

  };

}
#endif
