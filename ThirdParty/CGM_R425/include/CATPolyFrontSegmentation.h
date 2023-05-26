//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyFrontSegmentation.h
//
//=============================================================================
// 2009-02-12 ZFI
//=============================================================================

#ifndef CATPolyFrontSegmentation_H
#define CATPolyFrontSegmentation_H

#include "PolyBodyBuilders.h"

#include "CATErrorDef.h" 
#include "CATListOfInt.h"

class CATIPolyMesh;
class CATPolyBody;
class CATIPolySurfaceVertexNormalLayer;
class CATIPolySurfaceVertexTextureCoordLayer;
class CATPolyBitSet;
class CATPolyBars;
class CATPolySurfaceFacetSupportLayer;
class CATPolyMeshVertexNNormalsLayer;
class CATPolyMeshVertexNTexCoordsLayer;
class CATPolyBarsBarSupportLayer;
class CATPolyMeshVertexNNormalsLayer;
class CATPolyMeshVertexNTexCoordsLayer;
class CATPolySegmentLayer;

class CATPolyIntegerSetPartition;

class CATPolyDecoMeshBars;

class ExportedByPolyBodyBuilders CATPolyFrontSegmentation
{
public:

	CATPolyFrontSegmentation ();
	~CATPolyFrontSegmentation ();

public:

  HRESULT Run(CATIPolyMesh& iMesh,
              CATPolyDecoMeshBars*& oDecoMesh,
              CATPolySegmentLayer* ioSegmentLayer=NULL) const;

private:  
  HRESULT FillTriangleSupportFromPartition(const CATIPolyMesh& iMesh,
                                           const CATPolyIntegerSetPartition& iPartition,
                                           CATPolySurfaceFacetSupportLayer& oSupport)const;
  
  HRESULT FillNNormalsLayer(const CATIPolyMesh& iMesh,
                            const CATIPolySurfaceVertexNormalLayer& iNormalLayer,
                            const CATPolySurfaceFacetSupportLayer& iTriangleSupport,
                            CATPolyMeshVertexNNormalsLayer& oNNormalsLayer) const;

  HRESULT FillPolyBars(const CATIPolyMesh& iMesh,
                       const CATPolySurfaceFacetSupportLayer& iTriangleSupport,
                       CATPolyBars& oPolyBars) const;  


};

#endif 
