#ifndef _ROS_graph_msgs_GeometryGraph_h
#define _ROS_graph_msgs_GeometryGraph_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"
#include "graph_msgs/Edges.h"

namespace graph_msgs
{

  class GeometryGraph : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t nodes_length;
      typedef geometry_msgs::Point _nodes_type;
      _nodes_type st_nodes;
      _nodes_type * nodes;
      uint32_t edges_length;
      typedef graph_msgs::Edges _edges_type;
      _edges_type st_edges;
      _edges_type * edges;

    GeometryGraph():
      header(),
      nodes_length(0), nodes(NULL),
      edges_length(0), edges(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->nodes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->nodes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->nodes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->nodes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nodes_length);
      for( uint32_t i = 0; i < nodes_length; i++){
      offset += this->nodes[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->edges_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->edges_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->edges_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->edges_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->edges_length);
      for( uint32_t i = 0; i < edges_length; i++){
      offset += this->edges[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t nodes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->nodes_length);
      if(nodes_lengthT > nodes_length)
        this->nodes = (geometry_msgs::Point*)realloc(this->nodes, nodes_lengthT * sizeof(geometry_msgs::Point));
      nodes_length = nodes_lengthT;
      for( uint32_t i = 0; i < nodes_length; i++){
      offset += this->st_nodes.deserialize(inbuffer + offset);
        memcpy( &(this->nodes[i]), &(this->st_nodes), sizeof(geometry_msgs::Point));
      }
      uint32_t edges_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      edges_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      edges_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      edges_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->edges_length);
      if(edges_lengthT > edges_length)
        this->edges = (graph_msgs::Edges*)realloc(this->edges, edges_lengthT * sizeof(graph_msgs::Edges));
      edges_length = edges_lengthT;
      for( uint32_t i = 0; i < edges_length; i++){
      offset += this->st_edges.deserialize(inbuffer + offset);
        memcpy( &(this->edges[i]), &(this->st_edges), sizeof(graph_msgs::Edges));
      }
     return offset;
    }

    const char * getType(){ return "graph_msgs/GeometryGraph"; };
    const char * getMD5(){ return "78739617daca94d38915923795eada2d"; };

  };

}
#endif
