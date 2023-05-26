//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyDecoMeshBarsWithMergeConcatenator.h
//
//=============================================================================
// 2009-03-18 ZFI
//=============================================================================

#ifndef CATPolyDecoMeshBarsWithMergeConcatenator_H
#define CATPolyDecoMeshBarsWithMergeConcatenator_H

#include "CATErrorDef.h" 


class CATPolyDecoMeshBars;

class CATIPolyMesh;
class CATIPolyCurve;
class CATPolyBarsSpatialPartitionOper;
class CATMapOfFloatsToInt;

class CATMathBox;

class CATPolyDecoMeshBarsWithMergeConcatenator
{
public:
	CATPolyDecoMeshBarsWithMergeConcatenator(CATPolyDecoMeshBars* iDecoMesh) ;
	virtual ~CATPolyDecoMeshBarsWithMergeConcatenator () ;

public:  
  HRESULT Init(const float iTolerance,
               const CATMathBox& iBoundingBox);

  HRESULT Init(const int iApproxNbVertices);

  HRESULT ConcatenateLineStrip(const float* iVertices, 
                               const int iNbVertices,
                               const int iLineStripTag);

  HRESULT ConcatenateMesh(const float* iVertices, const int iNbVertices,
                          const unsigned int* iTriangles, const int iNbTriangles,
                          const float* iNormals,const float* iUVs,
                          const int iMeshTag);  


  HRESULT ConcatenateCurve(const CATIPolyCurve& iCurve, const int iCurveTag);
  HRESULT ConcatenateMesh(const CATIPolyMesh& iMesh, const int iMeshTag);

private:
  HRESULT AddVertex(const float iP[], int& oVertexIndex);
  
  HRESULT UpdateVertexNormal(const int iVrIndex, const float iN[], const int iVrTag);
  HRESULT UpdateVertexUV(const int iVrIndex, const float iUV[], const int iVrTag);

  HRESULT AddBar(const int iVertices[2], int& oBarIndex, const int iBarTag);
  HRESULT AddTriangle(const int iVertices[3], int& oTrIndex, const int iTrTag);

private:
  CATPolyDecoMeshBars* _DecoMesh;
  CATPolyBarsSpatialPartitionOper* _SpatialPartition;
  CATMapOfFloatsToInt* _PositionToVertex;
  float _Tolerance;
};

#endif 
