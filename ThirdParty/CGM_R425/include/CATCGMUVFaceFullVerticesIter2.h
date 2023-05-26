#ifndef CATCGMUVFaceFullVerticesIter2_H
#define CATCGMUVFaceFullVerticesIter2_H

#include "ExportedByTessellateCommon.h"

#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATCGMUVAbstractTopo.h"

class CATVertex;


/////////////////////////////////////////////////////////////////
// Sample Usage:
//
// CATCGMUVFaceMeshBuffersItf* faceMeshBuffersItf = ...;
//
// CATCGMUVFaceFullVerticesIter *it = faceMeshBuffersItf->GetFullVertices();
// if (it)
// {
//   for (it->Begin(); !it->IsEnd(); ++(*it))
//   {
//     CATVertex* fullVertex = it->Get();
//   }
//   delete it;
//   it = 0;
// }
//
/////////////////////////////////////////////////////////////////

class ExportedByTessellateCommon CATCGMUVFaceFullVerticesIter2
{
public:
  CATCGMUVFaceFullVerticesIter2();
  virtual ~CATCGMUVFaceFullVerticesIter2();

public:

  virtual void Begin() = 0;
  virtual CATBoolean IsEnd() const = 0;

  virtual CATUVVertexHandle Get() const = 0;

  virtual CATCGMUVFaceFullVerticesIter2& operator ++ () = 0;
};

#endif 

