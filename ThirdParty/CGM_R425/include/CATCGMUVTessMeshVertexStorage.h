// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVTessMeshVertexStorage.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Jan 2012  Creation: ZFI
//===================================================================

#ifndef CATCGMUVTessMeshVertexStorage_H
#define CATCGMUVTessMeshVertexStorage_H

#include "ExportedByTessellateCommon.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATMathPoint;

class ExportedByTessellateCommon CATCGMUVTessMeshVertexStorage
{
public :
  CATCGMUVTessMeshVertexStorage();
  virtual ~CATCGMUVTessMeshVertexStorage();

public:
  //classic
  virtual HRESULT StoreMeshVertex(const unsigned int iMeshVertex)=0;

  //for some cases were index in mesh is not availabe, example, full vertex
  virtual HRESULT StorePoint(const CATMathPoint& iPosition)=0;
};

#endif
