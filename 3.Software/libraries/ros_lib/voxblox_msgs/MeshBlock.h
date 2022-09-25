#ifndef _ROS_voxblox_msgs_MeshBlock_h
#define _ROS_voxblox_msgs_MeshBlock_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace voxblox_msgs
{

  class MeshBlock : public ros::Msg
  {
    public:
      int64_t index[3];
      uint32_t x_length;
      typedef uint16_t _x_type;
      _x_type st_x;
      _x_type * x;
      uint32_t y_length;
      typedef uint16_t _y_type;
      _y_type st_y;
      _y_type * y;
      uint32_t z_length;
      typedef uint16_t _z_type;
      _z_type st_z;
      _z_type * z;
      uint32_t r_length;
      typedef uint8_t _r_type;
      _r_type st_r;
      _r_type * r;
      uint32_t g_length;
      typedef uint8_t _g_type;
      _g_type st_g;
      _g_type * g;
      uint32_t b_length;
      typedef uint8_t _b_type;
      _b_type st_b;
      _b_type * b;

    MeshBlock():
      index(),
      x_length(0), x(NULL),
      y_length(0), y(NULL),
      z_length(0), z(NULL),
      r_length(0), r(NULL),
      g_length(0), g(NULL),
      b_length(0), b(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 3; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_indexi;
      u_indexi.real = this->index[i];
      *(outbuffer + offset + 0) = (u_indexi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_indexi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_indexi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_indexi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_indexi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_indexi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_indexi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_indexi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->index[i]);
      }
      *(outbuffer + offset + 0) = (this->x_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->x_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->x_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->x_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x_length);
      for( uint32_t i = 0; i < x_length; i++){
      *(outbuffer + offset + 0) = (this->x[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->x[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->x[i]);
      }
      *(outbuffer + offset + 0) = (this->y_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->y_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->y_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->y_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y_length);
      for( uint32_t i = 0; i < y_length; i++){
      *(outbuffer + offset + 0) = (this->y[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->y[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->y[i]);
      }
      *(outbuffer + offset + 0) = (this->z_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->z_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->z_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->z_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z_length);
      for( uint32_t i = 0; i < z_length; i++){
      *(outbuffer + offset + 0) = (this->z[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->z[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->z[i]);
      }
      *(outbuffer + offset + 0) = (this->r_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->r_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->r_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->r_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->r_length);
      for( uint32_t i = 0; i < r_length; i++){
      *(outbuffer + offset + 0) = (this->r[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->r[i]);
      }
      *(outbuffer + offset + 0) = (this->g_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->g_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->g_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->g_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->g_length);
      for( uint32_t i = 0; i < g_length; i++){
      *(outbuffer + offset + 0) = (this->g[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->g[i]);
      }
      *(outbuffer + offset + 0) = (this->b_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->b_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->b_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->b_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->b_length);
      for( uint32_t i = 0; i < b_length; i++){
      *(outbuffer + offset + 0) = (this->b[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->b[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 3; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_indexi;
      u_indexi.base = 0;
      u_indexi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_indexi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_indexi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_indexi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_indexi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_indexi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_indexi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_indexi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->index[i] = u_indexi.real;
      offset += sizeof(this->index[i]);
      }
      uint32_t x_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      x_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      x_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      x_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->x_length);
      if(x_lengthT > x_length)
        this->x = (uint16_t*)realloc(this->x, x_lengthT * sizeof(uint16_t));
      x_length = x_lengthT;
      for( uint32_t i = 0; i < x_length; i++){
      this->st_x =  ((uint16_t) (*(inbuffer + offset)));
      this->st_x |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->st_x);
        memcpy( &(this->x[i]), &(this->st_x), sizeof(uint16_t));
      }
      uint32_t y_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      y_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      y_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      y_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->y_length);
      if(y_lengthT > y_length)
        this->y = (uint16_t*)realloc(this->y, y_lengthT * sizeof(uint16_t));
      y_length = y_lengthT;
      for( uint32_t i = 0; i < y_length; i++){
      this->st_y =  ((uint16_t) (*(inbuffer + offset)));
      this->st_y |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->st_y);
        memcpy( &(this->y[i]), &(this->st_y), sizeof(uint16_t));
      }
      uint32_t z_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      z_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      z_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      z_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->z_length);
      if(z_lengthT > z_length)
        this->z = (uint16_t*)realloc(this->z, z_lengthT * sizeof(uint16_t));
      z_length = z_lengthT;
      for( uint32_t i = 0; i < z_length; i++){
      this->st_z =  ((uint16_t) (*(inbuffer + offset)));
      this->st_z |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->st_z);
        memcpy( &(this->z[i]), &(this->st_z), sizeof(uint16_t));
      }
      uint32_t r_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      r_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      r_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      r_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->r_length);
      if(r_lengthT > r_length)
        this->r = (uint8_t*)realloc(this->r, r_lengthT * sizeof(uint8_t));
      r_length = r_lengthT;
      for( uint32_t i = 0; i < r_length; i++){
      this->st_r =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_r);
        memcpy( &(this->r[i]), &(this->st_r), sizeof(uint8_t));
      }
      uint32_t g_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      g_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      g_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      g_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->g_length);
      if(g_lengthT > g_length)
        this->g = (uint8_t*)realloc(this->g, g_lengthT * sizeof(uint8_t));
      g_length = g_lengthT;
      for( uint32_t i = 0; i < g_length; i++){
      this->st_g =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_g);
        memcpy( &(this->g[i]), &(this->st_g), sizeof(uint8_t));
      }
      uint32_t b_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      b_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      b_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      b_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->b_length);
      if(b_lengthT > b_length)
        this->b = (uint8_t*)realloc(this->b, b_lengthT * sizeof(uint8_t));
      b_length = b_lengthT;
      for( uint32_t i = 0; i < b_length; i++){
      this->st_b =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_b);
        memcpy( &(this->b[i]), &(this->st_b), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return "voxblox_msgs/MeshBlock"; };
    const char * getMD5(){ return "a2921da2fac1fa36ed1e9d85b1e1b29c"; };

  };

}
#endif
