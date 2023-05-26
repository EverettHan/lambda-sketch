#ifndef CATCGMUVFaceFullVerticesIter_H
#define CATCGMUVFaceFullVerticesIter_H

#include "ExportedByTessellateCommon.h"

#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

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

class ExportedByTessellateCommon CATCGMUVFaceFullVerticesIter
{
public:
  CATCGMUVFaceFullVerticesIter();
  virtual ~CATCGMUVFaceFullVerticesIter();

public:

  virtual void Begin() = 0;
  virtual CATBoolean IsEnd() const = 0;

  virtual CATVertex* Get() const = 0;

  virtual CATCGMUVFaceFullVerticesIter& operator ++ () = 0;
};

#endif 

