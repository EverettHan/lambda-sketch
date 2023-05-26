#ifndef CATCGMUVEdgeMeshRichItf_H
#define CATCGMUVEdgeMeshRichItf_H

#include "ExportedByTessellateCommon.h"
#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATCGMUVEdgeMeshBasicItf.h"


class CATEdge;
class CATCGMUVParamSubdivision1D;

class ExportedByTessellateCommon CATCGMUVEdgeMeshRichItf : public CATCGMUVEdgeMeshBasicItf
{
public:
  virtual ~CATCGMUVEdgeMeshRichItf();

public:
  // currently there no extra methods in this class
  // but, this is the place if extra methods are needed
  // in adding to cache (say for compression), which cannot 
  // be implemented on decompressed mesh.

};

#endif 

