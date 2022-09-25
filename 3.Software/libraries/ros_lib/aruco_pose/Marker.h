#ifndef _ROS_aruco_pose_Marker_h
#define _ROS_aruco_pose_Marker_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "aruco_pose/Point2D.h"

namespace aruco_pose
{

  class Marker : public ros::Msg
  {
    public:
      typedef uint32_t _id_type;
      _id_type id;
      typedef float _length_type;
      _length_type length;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef aruco_pose::Point2D _c1_type;
      _c1_type c1;
      typedef aruco_pose::Point2D _c2_type;
      _c2_type c2;
      typedef aruco_pose::Point2D _c3_type;
      _c3_type c3;
      typedef aruco_pose::Point2D _c4_type;
      _c4_type c4;

    Marker():
      id(0),
      length(0),
      pose(),
      c1(),
      c2(),
      c3(),
      c4()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      union {
        float real;
        uint32_t base;
      } u_length;
      u_length.real = this->length;
      *(outbuffer + offset + 0) = (u_length.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_length.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_length.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_length.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->length);
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->c1.serialize(outbuffer + offset);
      offset += this->c2.serialize(outbuffer + offset);
      offset += this->c3.serialize(outbuffer + offset);
      offset += this->c4.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      union {
        float real;
        uint32_t base;
      } u_length;
      u_length.base = 0;
      u_length.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_length.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_length.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_length.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->length = u_length.real;
      offset += sizeof(this->length);
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->c1.deserialize(inbuffer + offset);
      offset += this->c2.deserialize(inbuffer + offset);
      offset += this->c3.deserialize(inbuffer + offset);
      offset += this->c4.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "aruco_pose/Marker"; };
    const char * getMD5(){ return "ac210d89096a042287e44f6279b6b76f"; };

  };

}
#endif
