#ifndef VISGPGPUTEXTUREINFORMATION_H_
#define VISGPGPUTEXTUREINFORMATION_H_

struct VisGPGPUTextureInformation
{
  unsigned int _textureID;
  unsigned int _textureType; ///< OpenGL texture type

  VisGPGPUTextureInformation()
    :_textureID(0), _textureType(0)
  { }

};


#endif //VISGPGPUTEXTUREINFORMATION_H_
