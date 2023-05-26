#ifndef CATCGMUVFaceEdgesIter2_H
#define CATCGMUVFaceEdgesIter2_H

#include "ExportedByTessellateCommon.h"

#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATCGMUVAbstractTopo.h"


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


class ExportedByTessellateCommon CATCGMUVFaceEdgesIter2
{
public:
  CATCGMUVFaceEdgesIter2();
  virtual ~CATCGMUVFaceEdgesIter2();

public:

  virtual void Begin() = 0;
  virtual CATBoolean IsEnd() const = 0;

  virtual CATUVEdgeHandle Get() const = 0;

  virtual CATCGMUVFaceEdgesIter2& operator ++ () = 0;
  virtual int Size()=0;
};

#endif 

