// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVTessPolyLineStorage.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Jan 2012  Creation: ZFI
//===================================================================

#ifndef CATCGMUVTessPolyLineStorage_H
#define CATCGMUVTessPolyLineStorage_H

#include "CATCGMUVTessPLineStorage.h"

class CATPolyLine;
class CATIPolyCurveVertexTangentLayer;
class CATIPolyCurveVertexWLayer;
class CATMathPolyBuffers;

class ExportedByTessellateCommon CATCGMUVTessPolyLineStorage: public CATCGMUVTessPLineStorage
{
public :
  CATCGMUVTessPolyLineStorage(CATEdge& iEdge,  int iNbCrvVertices, CATBoolean iStoreWs, CATBoolean iStoreTangents, int iCacheFormat=0); // 0: float, 1: double
  virtual ~CATCGMUVTessPolyLineStorage();

public:
  CATPolyLine* GetPolyLine();

private:
  //Face Edge Curve Storage
  HRESULT BeginPLineStorage(int iNbCrvVertices);
  HRESULT StoreCurveVertex(int iNumCrvVertex, const double iCoords[3]);
  HRESULT StoreCurveVertexTangent(int iNumCrvVertex, const double iTangent[3]);
  HRESULT StoreCurveVertexW(int iNumCrvVertex, double iW);

  //Buffer
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
  //Mesh Curve
  CATPolyLine* _PolyLine;
  CATIPolyCurveVertexTangentLayer* _TangentLayer;
  CATIPolyCurveVertexWLayer* _WLayer;
};

#endif
