#ifndef _ROS_fiducial_msgs_FiducialMapEntry_h
#define _ROS_fiducial_msgs_FiducialMapEntry_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fiducial_msgs
{

  class FiducialMapEntry : public ros::Msg
  {
    public:
      typedef int32_t _fiducial_id_type;
      _fiducial_id_type fiducial_id;
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _z_type;
      _z_type z;
      typedef float _rx_type;
      _rx_type rx;
      typedef float _ry_type;
      _ry_type ry;
      typedef float _rz_type;
      _rz_type rz;

    FiducialMapEntry():
      fiducial_id(0),
      x(0),
      y(0),
      z(0),
      rx(0),
      ry(0),
      rz(0)
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
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->z);
      offset += serializeAvrFloat64(outbuffer + offset, this->rx);
      offset += serializeAvrFloat64(outbuffer + offset, this->ry);
      offset += serializeAvrFloat64(outbuffer + offset, this->rz);
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->z));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rx));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ry));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rz));
     return offset;
    }

    const char * getType(){ return "fiducial_msgs/FiducialMapEntry"; };
    const char * getMD5(){ return "2dc3e2ac5967f3a2c19627a1fc1d7dcc"; };

  };

}
#endif
