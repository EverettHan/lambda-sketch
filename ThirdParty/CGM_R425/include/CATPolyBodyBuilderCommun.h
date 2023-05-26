//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyBodyBuilderCommun.h
//
//=============================================================================
// 2009-02-12 ZFI
//=============================================================================

#ifndef CATPolyBodyBuilderCommun_H
#define CATPolyBodyBuilderCommun_H

#include "PolyBodyBuilders.h"
#include "CATErrorDef.h" 
#include "CATBoolean.h"


class CATPolyDecoMeshBars;
class CATPolyIntegerSetPartition;
class CATPolyBarsSpatialPartitionOper;
class CATMapOfIntToInt;

class ExportedByPolyBodyBuilders CATPolyBodyBuilderCommun
{
public:

	CATPolyBodyBuilderCommun (CATPolyDecoMeshBars* iDecoMesh);
	~CATPolyBodyBuilderCommun ();

public:
  HRESULT Heal(const float iTolerance);
  HRESULT FlagBarsUniform();
  HRESULT RemoveRedondantBars() ;
  HRESULT MergeIdenticalTriangles();
  HRESULT RemoveHoleBars() ;
  HRESULT RemoveNonManiolfdBars() ;
  HRESULT RemoveFullBars() ;
  HRESULT OrientAllBars() ;
  HRESULT MergeIdenticalVertices();
  HRESULT MergeIdenticalVertices(CATBoolean iSameFace, CATBoolean iSameNormal, CATBoolean iSameTextureCoordinates);
  HRESULT FlagConnectedFaces(CATMapOfIntToInt* ioNew2OldTag=0);
  HRESULT FillPolyBarsFromEdgeVertices();
  HRESULT FillPolyBarsFromTriangleSupport();
  HRESULT FillNNormalsLayerDefault();
  HRESULT FillTriangleSupportFromPartition(const CATPolyIntegerSetPartition& iPartition);
  HRESULT IdentifyPolyVertices();
  HRESULT AttachWires();
  HRESULT ComputeToleranceUsingBoundingBox(const int iGridSize, float& oTolerance);

private:
  CATPolyDecoMeshBars* _DecoMesh;

};

#endif 
