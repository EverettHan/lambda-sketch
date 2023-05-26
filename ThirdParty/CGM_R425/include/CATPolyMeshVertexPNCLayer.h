// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshVertexPNCLayer.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// Feb 2010  Creation: ZFI
//===================================================================

#ifndef CATPolyMeshVertexPNCLayer_H
#define CATPolyMeshVertexPNCLayer_H

#include "CATErrorDef.h"
#include "PolyBodyStream.h"
#include "CATMapOfIntToPtr.h"

class ExportedByPolyBodyStream CATPolyMeshVertexPNCLayer
{
public:
  CATPolyMeshVertexPNCLayer();
  virtual ~CATPolyMeshVertexPNCLayer();

  unsigned int GetVertexScheme(const unsigned int iVertex)const;

  //scheme 1
  HRESULT Set(const unsigned int iVertex, const unsigned int iPrevVertex);
  HRESULT Get(const unsigned int iVertex, unsigned int& oPrevVertex)const;

  //scheme 2
  HRESULT Set(const unsigned int iVertex, const unsigned int iPrevVertex, const unsigned int iNextVertex);
  HRESULT Get(const unsigned int iVertex, unsigned int& oPrevVertex, unsigned int& oNextVertex)const;

  //scheme 3
  HRESULT Set(const unsigned int iVertex, const unsigned int iPrevVertex, const unsigned int iNextVertex, const unsigned int iCornerVertex);
  HRESULT Get(const unsigned int iVertex, unsigned int& oPrevVertex, unsigned int& oNextVertex, unsigned int& oCornerVertex)const;

public:
  HRESULT Clean();

private:
  CATMapOfIntToPtr _Index2PNC;
};

#endif
