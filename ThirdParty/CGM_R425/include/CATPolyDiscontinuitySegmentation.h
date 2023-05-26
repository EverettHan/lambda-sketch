//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyDiscontinuitySegmentation.h
//
//=============================================================================
// 2009-02-12 ZFI
//=============================================================================

#ifndef CATPolyDiscontinuitySegmentation_H
#define CATPolyDiscontinuitySegmentation_H

#include "PolyBodyBuilders.h"

#include "CATErrorDef.h" 

class CATIPolyMesh;
class CATPolyDecoMeshBars;

class ExportedByPolyBodyBuilders CATPolyDiscontinuitySegmentation
{
public:

	CATPolyDiscontinuitySegmentation ();
	~CATPolyDiscontinuitySegmentation ();

public:

  HRESULT Run(CATIPolyMesh& iMesh,
              CATPolyDecoMeshBars*& oDecoMesh, 
              const float iTolerance=0) const;
  
};

#endif 
