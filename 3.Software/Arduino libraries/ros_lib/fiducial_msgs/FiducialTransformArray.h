#ifndef _ROS_fiducial_msgs_FiducialTransformArray_h
#define _ROS_fiducial_msgs_FiducialTransformArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "fiducial_msgs/FiducialTransform.h"

namespace fiducial_msgs
{

  class FiducialTransformArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _image_seq_type;
      _image_seq_type image_seq;
      uint32_t transforms_length;
      typedef fiducial_msgs::FiducialTransform _transforms_type;
      _transforms_type st_transforms;
      _transforms_type * transforms;

    FiducialTransformArray():
      header(),
      image_seq(0),
      transforms_length(0), transforms(NULL)
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
      *(outbuffer + offset + 0) = (this->transforms_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->transforms_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->transforms_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->transforms_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->transforms_length);
      for( uint32_t i = 0; i < transforms_length; i++){
      offset += this->transforms[i].serialize(outbuffer + offset);
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
      uint32_t transforms_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->transforms_length);
      if(transforms_lengthT > transforms_length)
        this->transforms = (fiducial_msgs::FiducialTransform*)realloc(this->transforms, transforms_lengthT * sizeof(fiducial_msgs::FiducialTransform));
      transforms_length = transforms_lengthT;
      for( uint32_t i = 0; i < transforms_length; i++){
      offset += this->st_transforms.deserialize(inbuffer + offset);
        memcpy( &(this->transforms[i]), &(this->st_transforms), sizeof(fiducial_msgs::FiducialTransform));
      }
     return offset;
    }

    const char * getType(){ return "fiducial_msgs/FiducialTransformArray"; };
    const char * getMD5(){ return "a9391b25df2859cb1ae6fa6ee45ef075"; };

  };

}
#endif
