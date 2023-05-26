//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyDecoMeshBarsUnZipper.h
//
//=============================================================================
// June 2009 ZFI
//=============================================================================

#ifndef CATPolyDecoMeshBarsUnZipper_H
#define CATPolyDecoMeshBarsUnZipper_H

#include "PolyBodyBuilders.h"

#include "CATErrorDef.h" 
#include "CATListPV.h"
#include "CATMapOfIntToInt.h"

class CATPolyDecoMeshBars;
class CATPolyBarsSpatialPartitionOper;

class ExportedByPolyBodyBuilders CATPolyDecoMeshBarsUnZipper
{
public:
	CATPolyDecoMeshBarsUnZipper (CATPolyDecoMeshBars* iDecoMesh) ;
	virtual ~CATPolyDecoMeshBarsUnZipper () ;

public:
  HRESULT Open();

private:
  HRESULT UpdateVertexInfo(const int iIdxOldVertex, const int iIdxNewVertex);

private:
  CATPolyDecoMeshBars* _DecoMesh;  
};

#endif 
