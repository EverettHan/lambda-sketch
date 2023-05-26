//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyBodyFromTrianglesLinesBuilder.h
//
//=============================================================================
// 2009-02-17 ZFI
//=============================================================================

#ifndef CATPolyBodyFromTrianglesLinesBuilder_H
#define CATPolyBodyFromTrianglesLinesBuilder_H

#include "PolyBodyBuilders.h"
#include "CATErrorDef.h" 
#include "CATBoolean.h"


class CATPolyBody;
class CATPolyDecoMeshBars;
class CATPolyDecoMeshBarsWithMergeConcatenator;

class CATIPolyCurve;
class CATIPolyMesh;

class CATMathBox;

class CATMapOfPtrToInt;
class ExportedByPolyBodyBuilders CATPolyBodyFromTrianglesLinesBuilder
{
public:

	CATPolyBodyFromTrianglesLinesBuilder ();
	~CATPolyBodyFromTrianglesLinesBuilder () ;

public:
  HRESULT Init(const float iTolerance,const CATMathBox& iBox);
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

public:
  HRESULT BuildPolyBody(CATPolyBody*& oPolyBody,
                        CATBoolean iCreateTopology,
                        CATMapOfPtrToInt* ioMapCellToSupportId=0);

private:
  CATPolyDecoMeshBars* _DecoMesh ;
  CATPolyDecoMeshBarsWithMergeConcatenator* _Concatenator;

};

#endif 
