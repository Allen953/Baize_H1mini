#ifndef _ROS_fiducial_msgs_Fiducial_h
#define _ROS_fiducial_msgs_Fiducial_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fiducial_msgs
{

  class Fiducial : public ros::Msg
  {
    public:
      typedef int32_t _fiducial_id_type;
      _fiducial_id_type fiducial_id;
      typedef int32_t _direction_type;
      _direction_type direction;
      typedef float _x0_type;
      _x0_type x0;
      typedef float _y0_type;
      _y0_type y0;
      typedef float _x1_type;
      _x1_type x1;
      typedef float _y1_type;
      _y1_type y1;
      typedef float _x2_type;
      _x2_type x2;
      typedef float _y2_type;
      _y2_type y2;
      typedef float _x3_type;
      _x3_type x3;
      typedef float _y3_type;
      _y3_type y3;

    Fiducial():
      fiducial_id(0),
      direction(0),
      x0(0),
      y0(0),
      x1(0),
      y1(0),
      x2(0),
      y2(0),
      x3(0),
      y3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_fiducial_id;
      u_fiducial_id.real = this->fiducial_id;
      *(outbuffer + offset + 0) = (u_fiducial_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fiducial_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fiducial_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fiducial_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fiducial_id);
      union {
        int32_t real;
        uint32_t base;
      } u_direction;
      u_direction.real = this->direction;
      *(outbuffer + offset + 0) = (u_direction.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_direction.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_direction.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_direction.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->direction);
      offset += serializeAvrFloat64(outbuffer + offset, this->x0);
      offset += serializeAvrFloat64(outbuffer + offset, this->y0);
      offset += serializeAvrFloat64(outbuffer + offset, this->x1);
      offset += serializeAvrFloat64(outbuffer + offset, this->y1);
      offset += serializeAvrFloat64(outbuffer + offset, this->x2);
      offset += serializeAvrFloat64(outbuffer + offset, this->y2);
      offset += serializeAvrFloat64(outbuffer + offset, this->x3);
      offset += serializeAvrFloat64(outbuffer + offset, this->y3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_fiducial_id;
      u_fiducial_id.base = 0;
      u_fiducial_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fiducial_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fiducial_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fiducial_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fiducial_id = u_fiducial_id.real;
      offset += sizeof(this->fiducial_id);
      union {
        int32_t real;
        uint32_t base;
      } u_direction;
      u_direction.base = 0;
      u_direction.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_direction.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_direction.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_direction.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->direction = u_direction.real;
      offset += sizeof(this->direction);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x0));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y0));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x3));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y3));
     return offset;
    }

    const char * getType(){ return "fiducial_msgs/Fiducial"; };
    const char * getMD5(){ return "a0094064db6c7772c6b638a2dab17f42"; };

  };

}
#endif
