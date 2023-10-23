#ifndef _ROS_voxblox_msgs_VoxelEvaluationDetails_h
#define _ROS_voxblox_msgs_VoxelEvaluationDetails_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace voxblox_msgs
{

  class VoxelEvaluationDetails : public ros::Msg
  {
    public:
      typedef float _max_error_type;
      _max_error_type max_error;
      typedef float _min_error_type;
      _min_error_type min_error;
      typedef uint32_t _num_evaluated_voxels_type;
      _num_evaluated_voxels_type num_evaluated_voxels;
      typedef uint32_t _num_ignored_voxels_type;
      _num_ignored_voxels_type num_ignored_voxels;
      typedef uint32_t _num_overlapping_voxels_type;
      _num_overlapping_voxels_type num_overlapping_voxels;
      typedef uint32_t _num_non_overlapping_voxels_type;
      _num_non_overlapping_voxels_type num_non_overlapping_voxels;

    VoxelEvaluationDetails():
      max_error(0),
      min_error(0),
      num_evaluated_voxels(0),
      num_ignored_voxels(0),
      num_overlapping_voxels(0),
      num_non_overlapping_voxels(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->max_error);
      offset += serializeAvrFloat64(outbuffer + offset, this->min_error);
      *(outbuffer + offset + 0) = (this->num_evaluated_voxels >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_evaluated_voxels >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->num_evaluated_voxels >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->num_evaluated_voxels >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_evaluated_voxels);
      *(outbuffer + offset + 0) = (this->num_ignored_voxels >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_ignored_voxels >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->num_ignored_voxels >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->num_ignored_voxels >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_ignored_voxels);
      *(outbuffer + offset + 0) = (this->num_overlapping_voxels >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_overlapping_voxels >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->num_overlapping_voxels >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->num_overlapping_voxels >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_overlapping_voxels);
      *(outbuffer + offset + 0) = (this->num_non_overlapping_voxels >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_non_overlapping_voxels >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->num_non_overlapping_voxels >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->num_non_overlapping_voxels >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_non_overlapping_voxels);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_error));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min_error));
      this->num_evaluated_voxels =  ((uint32_t) (*(inbuffer + offset)));
      this->num_evaluated_voxels |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->num_evaluated_voxels |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->num_evaluated_voxels |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->num_evaluated_voxels);
      this->num_ignored_voxels =  ((uint32_t) (*(inbuffer + offset)));
      this->num_ignored_voxels |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->num_ignored_voxels |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->num_ignored_voxels |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->num_ignored_voxels);
      this->num_overlapping_voxels =  ((uint32_t) (*(inbuffer + offset)));
      this->num_overlapping_voxels |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->num_overlapping_voxels |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->num_overlapping_voxels |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->num_overlapping_voxels);
      this->num_non_overlapping_voxels =  ((uint32_t) (*(inbuffer + offset)));
      this->num_non_overlapping_voxels |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->num_non_overlapping_voxels |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->num_non_overlapping_voxels |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->num_non_overlapping_voxels);
     return offset;
    }

    const char * getType(){ return "voxblox_msgs/VoxelEvaluationDetails"; };
    const char * getMD5(){ return "ae63ff7a8fed6761c7b2408516d56b79"; };

  };

}
#endif
