// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVCell.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Dec 2010  Creation: ZFI
//===================================================================

#ifndef CATCGMUVCell_H
#define CATCGMUVCell_H

#include "ExportedByTessellateCommon.h"

#include "CATErrorDef.h"
#include "CATRefCounted.h"

class CATCGMUVFace;
class CATCGMUVEdge;
class CATCGMUVVertex;

class ExportedByTessellateCommon CATCGMUVCell : public CATRefCounted
{
public :
  CATCGMUVCell();
  virtual ~CATCGMUVCell();

public:
  virtual CATCGMUVFace* CastAsFace();
  virtual CATCGMUVEdge* CastAsEdge();
  virtual CATCGMUVVertex* CastAsVertex();
};

#endif
