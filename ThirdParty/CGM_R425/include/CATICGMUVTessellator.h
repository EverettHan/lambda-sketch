// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATICGMUVTessellator.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// May 2010  Creation: ZFI, TPG, PUC
//===================================================================

#ifndef CATICGMUVTessellator_H
#define CATICGMUVTessellator_H

#include "ExportedByTessellateCommon.h"
#include "CATErrorDef.h"

class CATBody;
class CATFace;
class CATEdge;


//tessellator main class

class ExportedByTessellateCommon CATICGMUVTessellator
{
  public :
 
  CATICGMUVTessellator();
  virtual ~CATICGMUVTessellator();

public:
  /**
  * Updates the Cache, Body
  * iMode: 
  * 0: local; 1: global
  */
  virtual HRESULT UpdateCache(CATBody& iBody, int iMode=0)=0;

  /**
  * Updates the Cache, Face(+Countour Edges)
  */
  virtual HRESULT UpdateFaceCache(CATFace& iFace)=0;
    
  /**
  * Updates the Cache, Edge(Wire)
  */
  virtual HRESULT UpdateWireEdgeCache(CATEdge& iWireEdge)=0;
};

#endif
