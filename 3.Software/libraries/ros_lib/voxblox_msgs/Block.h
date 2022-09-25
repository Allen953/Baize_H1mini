#ifndef _ROS_voxblox_msgs_Block_h
#define _ROS_voxblox_msgs_Block_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace voxblox_msgs
{

  class Block : public ros::Msg
  {
    public:
      typedef int32_t _x_index_type;
      _x_index_type x_index;
      typedef int32_t _y_index_type;
      _y_index_type y_index;
      typedef int32_t _z_index_type;
      _z_index_type z_index;
      uint32_t data_length;
      typedef uint32_t _data_type;
      _data_type st_data;
      _data_type * data;

    Block():
      x_index(0),
      y_index(0),
      z_index(0),
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_x_index;
      u_x_index.real = this->x_index;
      *(outbuffer + offset + 0) = (u_x_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x_index);
      union {
        int32_t real;
        uint32_t base;
      } u_y_index;
      u_y_index.real = this->y_index;
      *(outbuffer + offset + 0) = (u_y_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y_index);
      union {
        int32_t real;
        uint32_t base;
      } u_z_index;
      u_z_index.real = this->z_index;
      *(outbuffer + offset + 0) = (u_z_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z_index);
      *(outbuffer + offset + 0) = (this->data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_length);
      for( uint32_t i = 0; i < data_length; i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_x_index;
      u_x_index.base = 0;
      u_x_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x_index = u_x_index.real;
      offset += sizeof(this->x_index);
      union {
        int32_t real;
        uint32_t base;
      } u_y_index;
      u_y_index.base = 0;
      u_y_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y_index = u_y_index.real;
      offset += sizeof(this->y_index);
      union {
        int32_t real;
        uint32_t base;
      } u_z_index;
      u_z_index.base = 0;
      u_z_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z_index = u_z_index.real;
      offset += sizeof(this->z_index);
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_length);
      if(data_lengthT > data_length)
        this->data = (uint32_t*)realloc(this->data, data_lengthT * sizeof(uint32_t));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++){
      this->st_data =  ((uint32_t) (*(inbuffer + offset)));
      this->st_data |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_data |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_data |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_data);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(uint32_t));
      }
     return offset;
    }

    const char * getType(){ return "voxblox_msgs/Block"; };
    const char * getMD5(){ return "9bcc5caf92de597505633a546c641a94"; };

  };

}
#endif
