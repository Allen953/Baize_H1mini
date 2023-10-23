#ifndef _ROS_voxblox_msgs_Layer_h
#define _ROS_voxblox_msgs_Layer_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "voxblox_msgs/Block.h"

namespace voxblox_msgs
{

  class Layer : public ros::Msg
  {
    public:
      typedef float _voxel_size_type;
      _voxel_size_type voxel_size;
      typedef uint32_t _voxels_per_side_type;
      _voxels_per_side_type voxels_per_side;
      typedef const char* _layer_type_type;
      _layer_type_type layer_type;
      typedef uint8_t _action_type;
      _action_type action;
      uint32_t blocks_length;
      typedef voxblox_msgs::Block _blocks_type;
      _blocks_type st_blocks;
      _blocks_type * blocks;
      enum { ACTION_UPDATE =  0 };
      enum { ACTION_MERGE =  1 };
      enum { ACTION_RESET =  2 };

    Layer():
      voxel_size(0),
      voxels_per_side(0),
      layer_type(""),
      action(0),
      blocks_length(0), blocks(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->voxel_size);
      *(outbuffer + offset + 0) = (this->voxels_per_side >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->voxels_per_side >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->voxels_per_side >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->voxels_per_side >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voxels_per_side);
      uint32_t length_layer_type = strlen(this->layer_type);
      varToArr(outbuffer + offset, length_layer_type);
      offset += 4;
      memcpy(outbuffer + offset, this->layer_type, length_layer_type);
      offset += length_layer_type;
      *(outbuffer + offset + 0) = (this->action >> (8 * 0)) & 0xFF;
      offset += sizeof(this->action);
      *(outbuffer + offset + 0) = (this->blocks_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->blocks_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->blocks_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->blocks_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->blocks_length);
      for( uint32_t i = 0; i < blocks_length; i++){
      offset += this->blocks[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->voxel_size));
      this->voxels_per_side =  ((uint32_t) (*(inbuffer + offset)));
      this->voxels_per_side |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->voxels_per_side |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->voxels_per_side |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->voxels_per_side);
      uint32_t length_layer_type;
      arrToVar(length_layer_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_layer_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_layer_type-1]=0;
      this->layer_type = (char *)(inbuffer + offset-1);
      offset += length_layer_type;
      this->action =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->action);
      uint32_t blocks_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      blocks_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      blocks_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      blocks_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->blocks_length);
      if(blocks_lengthT > blocks_length)
        this->blocks = (voxblox_msgs::Block*)realloc(this->blocks, blocks_lengthT * sizeof(voxblox_msgs::Block));
      blocks_length = blocks_lengthT;
      for( uint32_t i = 0; i < blocks_length; i++){
      offset += this->st_blocks.deserialize(inbuffer + offset);
        memcpy( &(this->blocks[i]), &(this->st_blocks), sizeof(voxblox_msgs::Block));
      }
     return offset;
    }

    const char * getType(){ return "voxblox_msgs/Layer"; };
    const char * getMD5(){ return "97e0cb7d60607d9bc02f977d9f620620"; };

  };

}
#endif
