#ifndef VISGPGPUVBOINFORMATION_H_
#define VISGPGPUVBOINFORMATION_H_

#include "VisVertexComponent.h"

struct VisGPGPUVboInformation
{
  unsigned int             _vboID;          ///< The OpenGL VBO ID 
  VisVertexComponent       _componentType;  ///< The component type : @see VisVerticesDescription
  unsigned int             _rawBufferID;    ///< The ID of the rawBuffer

  VisGPGPUVboInformation(const unsigned int & iVboID, const VisVertexComponent & iComponentType, 
    const unsigned int & iRawBufferID)
    :_vboID(iVboID), _componentType(iComponentType), _rawBufferID(iRawBufferID)
  { }
};


#endif /* VISGPGPUVBOINFORMATION_H_ */
