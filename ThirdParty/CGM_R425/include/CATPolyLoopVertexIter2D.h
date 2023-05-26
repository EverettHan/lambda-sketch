// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyLoopVertexIter2D.h
//
//===================================================================
// October 2006 Creation: ndo
//===================================================================
#ifndef CATPolyLoopVertexIter2D_H
#define CATPolyLoopVertexIter2D_H

#include "PolygonalModel.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)

class CATPolyLoop2D;
class CATPolyCoBar2D;
class CATPolyVertex2D;


/**
* @Deprecated
* @see CATPolyLoopBarIter2D
*/
class ExportedByPolygonalModel CATPolyLoopVertexIter2D
{
public :
  CATPolyLoopVertexIter2D(const CATPolyLoop2D& iLoop);
  CATPolyLoopVertexIter2D (const CATPolyLoop2D* iLoop);

  HRESULT Reset(const CATPolyLoop2D* iLoop);
  HRESULT Reset (const CATPolyLoop2D& iLoop);

  CATPolyVertex2D* Next ();

private :
  CATPolyCoBar2D* _CoBar;
};

inline HRESULT CATPolyLoopVertexIter2D::Reset(const CATPolyLoop2D* iLoop)
{
  if (!iLoop)
    return E_FAIL;
  return Reset(*iLoop);
}

#endif
