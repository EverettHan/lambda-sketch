//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyDecoMeshBarsUtils.h
//
//=============================================================================
// 2009-03-18 ZFI
//=============================================================================

#ifndef CATPolyDecoMeshBarsUtils_H
#define CATPolyDecoMeshBarsUtils_H

#include "PolyBodyBuilders.h"

#include "CATErrorDef.h" 

class CATIPolyMesh;
class CATPolyBars;

class ExportedByPolyBodyBuilders CATPolyDecoMeshBarsUtils
{
public:
	CATPolyDecoMeshBarsUtils () ;
	virtual ~CATPolyDecoMeshBarsUtils () ;

public:
  static HRESULT GetNeighborBars(const int iV,const CATPolyBars& iPolyBars, int& oBar1, int& oBar2);
  static HRESULT GetNeighborVertices(const int iV,const CATPolyBars& iPolyBars, int& oV1, int& oV2);
  
  static HRESULT GetNextVertex(const int iV1, const int iV2, const CATPolyBars& iPolyBars, int& oNewV);
  static HRESULT GetNextBar(const int iV1, const int iV2, const CATPolyBars& iPolyBars, int& oNewBar);

  static HRESULT GetSecondVertex(const int iBar, const int iV1,const CATPolyBars& iPolyBars, int& oV2);
};

#endif 
