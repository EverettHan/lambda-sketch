// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVVertex.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Dec 2010  Creation: ZFI
//===================================================================

#ifndef CATCGMUVVertex_H
#define CATCGMUVVertex_H

#include "CATCGMUVCell.h"
#include "CATListPV.h"
#include "CATBoolean.h"

class CATVertex;
class CATCGMUVVertexPoint;
class CATCGMUVTessFace;
class CATCGMUVTessVertex;

class ExportedByTessellateCommon CATCGMUVVertex : public CATCGMUVCell
{
public :
  CATCGMUVVertex(CATVertex* iVertex);
  virtual ~CATCGMUVVertex();

public:
  virtual CATCGMUVTessVertex* CastAsTessVertex();
  virtual const CATCGMUVTessVertex* CastAsTessVertex()const;

  CATCGMUVVertex* CastAsVertex();

public:
  CATVertex* GetVertex(){return _Vertex;}

protected:
  CATVertex* _Vertex;
};

#endif
