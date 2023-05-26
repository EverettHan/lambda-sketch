//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyDecoMeshBarsConcatenator.h
//
//=============================================================================
// 2009-03-18 ZFI
//=============================================================================

#ifndef CATPolyDecoMeshBarsConcatenator_H
#define CATPolyDecoMeshBarsConcatenator_H

#include "CATErrorDef.h" 


class CATPolyDecoMeshBars;
class CATIPolyMesh;
class CATIPolySurfaceVertexLine;
class CATMapOfNFloatsToInt;
class CATMapOfIntToInt;
class CATMathTransformation;
class CATMathPoint;
class CATIPolyCurve;

class CATPolyDecoMeshBarsConcatenator
{
public:
	CATPolyDecoMeshBarsConcatenator (CATPolyDecoMeshBars* iDecoMesh) ;
	virtual ~CATPolyDecoMeshBarsConcatenator () ;

public:  
  HRESULT ConcatenateCurve(const CATIPolySurfaceVertexLine& iCurve,
                           const CATMathTransformation * iTransfo,
                           const int iCurveTag,
                           CATMapOfIntToInt* ioMapToNewVertices=0);

  HRESULT ConcatenateMesh(const CATIPolyMesh& iMesh, 
                          const CATMathTransformation * iTransfo,
                          const int iMeshTag,
                          CATMapOfIntToInt* ioMapToNewVertices=0,
                          CATMapOfIntToInt* ioMapToNewTriangles=0);

  HRESULT ConcatenateWire(const CATIPolyCurve& iWire, 
                          const CATMathTransformation * iTransfo);

private:
  HRESULT SetTag(const CATIPolyMesh& iMesh,
                 const CATMapOfIntToInt& mapToNewTrIndices,
                 const int iMeshTag);

  HRESULT ApplyTransformation(const CATIPolyMesh& iMesh,
                              const CATMathTransformation& iTransfo,
                              const CATMapOfIntToInt& iMapToNewVrIndices,
                              const CATMapOfIntToInt& iMapToNewTrIndices);

private:
  CATPolyDecoMeshBars* _DecoMesh;
};

#endif 
