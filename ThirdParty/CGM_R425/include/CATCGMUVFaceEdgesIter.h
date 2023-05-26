#ifndef CATCGMUVFaceEdgesIter_H
#define CATCGMUVFaceEdgesIter_H

#include "ExportedByTessellateCommon.h"

#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATEdge;

/////////////////////////////////////////////////////////////////
// Sample Usage:
//
// CATCGMUVFaceMeshBuffersItf* faceMeshBuffersItf = ...;
//
// CATCGMUVFaceEdgesIter *it = faceMeshBuffersItf->GetEdges();
// if (it)
// {
//   for (it->Begin(); !it->IsEnd(); ++(*it))
//   {
//     CATEdge* edge = it->Get();
//   }
//   delete it;
//   it = 0;
// }
//
/////////////////////////////////////////////////////////////////


class ExportedByTessellateCommon CATCGMUVFaceEdgesIter
{
public:
  CATCGMUVFaceEdgesIter();
  virtual ~CATCGMUVFaceEdgesIter();

public:

  virtual void Begin() = 0;
  virtual CATBoolean IsEnd() const = 0;

  virtual CATEdge* Get() const = 0;

  virtual CATCGMUVFaceEdgesIter& operator ++ () = 0;
  virtual int Size()=0;
};

#endif 

