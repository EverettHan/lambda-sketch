// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVTessPolyCurveStorage.h
//
//===================================================================
// Jan 2012  Creation: ZFI
//===================================================================

#ifndef CATCGMUVTessPolyCurveStorage_H
#define CATCGMUVTessPolyCurveStorage_H

#include "ExportedByTessellateCommon.h"
#include "CATCGMUVTessCurveStorage.h"

class CATCGMUVTessPolyMeshStorage;
class CATIPolySurfaceVertexLine;
class CATIPolyCurveVertexTangentLayer;
class CATIPolyCurveVertexWLayer;
class CATMathPolyBuffers;

class ExportedByTessellateCommon CATCGMUVTessPolyCurveStorage: public CATCGMUVTessCurveStorage
{
public :
  CATCGMUVTessPolyCurveStorage(CATEdge& iEdge,  CATCGMUVTessPolyMeshStorage& iTessMeshStorage, int iNbCrvVertices, CATBoolean iStoreWs, CATBoolean iStoreTangents);
  virtual ~CATCGMUVTessPolyCurveStorage();

public:
  CATIPolySurfaceVertexLine* GetMeshVertexLine() ;

private:
  //Face Edge Curve Storage
  HRESULT BeginFaceEdgeCurveStorage(int iNbCrvVertices);
  HRESULT StoreCurveMeshVertex(int iNumCrvVertex, int iNumMeshVertex);
  HRESULT StoreCurveVertexTangent(int iNumCrvVertex, const double iTangent[3]);
  HRESULT StoreCurveVertexW(int iNumCrvVertex, double iW);
 
  //Buffer
  HRESULT AddMeshVertices(unsigned int iFirstNumCrvVertex, unsigned int iNbCrvVertices, const CATULONG32* iMeshVertices);
  HRESULT UpdateCurveVertices(unsigned int iFirstNumCrvVertex, unsigned int iNbCrvVertices, 
                              const double* iPositions, const double* iTangents, const double* iWs);
	HRESULT UpdateCurveVertices(const CATMathPolyBuffers* iCrvBuffers, unsigned int iFirstNumCrvVertex=0);
    
  //canonic
  HRESULT StoreMathCurve(const CATPolyMathCurve* iMathCurve, const CATMathTransformation1D& iWTransfo);
  
  //Config
  CATBoolean NeedTangents()const;
  CATBoolean NeedWs()const;
  CATBoolean NeedMathCurve()const;

private:

  // Surface Vertex Line.
  CATIPolySurfaceVertexLine* _MeshVertexLine;
  CATIPolyCurveVertexTangentLayer* _TangentLayer;
  CATIPolyCurveVertexWLayer* _WLayer;
};

#endif
