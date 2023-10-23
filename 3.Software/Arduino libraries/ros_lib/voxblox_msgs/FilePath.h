#ifndef _ROS_SERVICE_FilePath_h
#define _ROS_SERVICE_FilePath_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace voxblox_msgs
{

static const char FILEPATH[] = "voxblox_msgs/FilePath";

  class FilePathRequest : public ros::Msg
  {
    public:
      typedef const char* _file_path_type;
      _file_path_type file_path;

    FilePathRequest():
      file_path("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_file_path = strlen(this->file_path);
      varToArr(outbuffer + offset, length_file_path);
      offset += 4;
      memcpy(outbuffer + offset, this->file_path, length_file_path);
      offset += length_file_path;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_file_path;
      arrToVar(length_file_path, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file_path-1]=0;
      this->file_path = (char *)(inbuffer + offset-1);
      offset += length_file_path;
     return offset;
    }

    const char * getType(){ return FILEPATH; };
    const char * getMD5(){ return "a1f82596372c52a517e1fe32d1e998e8"; };

  };

  class FilePathResponse : public ros::Msg
  {
    public:

    FilePathResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return FILEPATH; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class FilePath {
    public:
    typedef FilePathRequest Request;
    typedef FilePathResponse Response;
  };

}
#endif
