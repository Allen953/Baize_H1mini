#ifndef _ROS_voxblox_msgs_Mesh_h
#define _ROS_voxblox_msgs_Mesh_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "voxblox_msgs/MeshBlock.h"

namespace voxblox_msgs
{

  class Mesh : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _block_edge_length_type;
      _block_edge_length_type block_edge_length;
      uint32_t mesh_blocks_length;
      typedef voxblox_msgs::MeshBlock _mesh_blocks_type;
      _mesh_blocks_type st_mesh_blocks;
      _mesh_blocks_type * mesh_blocks;

    Mesh():
      header(),
      block_edge_length(0),
      mesh_blocks_length(0), mesh_blocks(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_block_edge_length;
      u_block_edge_length.real = this->block_edge_length;
      *(outbuffer + offset + 0) = (u_block_edge_length.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_block_edge_length.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_block_edge_length.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_block_edge_length.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->block_edge_length);
      *(outbuffer + offset + 0) = (this->mesh_blocks_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mesh_blocks_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->mesh_blocks_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->mesh_blocks_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mesh_blocks_length);
      for( uint32_t i = 0; i < mesh_blocks_length; i++){
      offset += this->mesh_blocks[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_block_edge_length;
      u_block_edge_length.base = 0;
      u_block_edge_length.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_block_edge_length.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_block_edge_length.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_block_edge_length.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->block_edge_length = u_block_edge_length.real;
      offset += sizeof(this->block_edge_length);
      uint32_t mesh_blocks_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      mesh_blocks_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      mesh_blocks_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      mesh_blocks_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->mesh_blocks_length);
      if(mesh_blocks_lengthT > mesh_blocks_length)
        this->mesh_blocks = (voxblox_msgs::MeshBlock*)realloc(this->mesh_blocks, mesh_blocks_lengthT * sizeof(voxblox_msgs::MeshBlock));
      mesh_blocks_length = mesh_blocks_lengthT;
      for( uint32_t i = 0; i < mesh_blocks_length; i++){
      offset += this->st_mesh_blocks.deserialize(inbuffer + offset);
        memcpy( &(this->mesh_blocks[i]), &(this->st_mesh_blocks), sizeof(voxblox_msgs::MeshBlock));
      }
     return offset;
    }

    const char * getType(){ return "voxblox_msgs/Mesh"; };
    const char * getMD5(){ return "4d589d8b6bcff9e45d11686cdd6227df"; };

  };

}
#endif
