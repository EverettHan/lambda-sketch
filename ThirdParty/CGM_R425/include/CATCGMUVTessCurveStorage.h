// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVTessCurveStorage.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Jan 2012  Creation: ZFI
//===================================================================

#ifndef CATCGMUVTessCurveStorage_H
#define CATCGMUVTessCurveStorage_H

#include "ExportedByTessellateCommon.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATEdge;
class CATCGMUVTessMeshStorage;
class CATPolyMathCurve;
class CATMathTransformation1D;
class CATMathPolyBuffers;

class ExportedByTessellateCommon CATCGMUVTessCurveStorage
{
public :
  CATCGMUVTessCurveStorage();
  virtual ~CATCGMUVTessCurveStorage();

public:
  //Face Edge Curve Storage
  virtual HRESULT BeginFaceEdgeCurveStorage(int iNbCrvVertices)=0;
  virtual HRESULT StoreCurveMeshVertex(int iNumCrvVertex, int iNumMeshVertex)=0;
  virtual HRESULT StoreCurveVertexTangent(int iNumCrvVertex, const double iTangent[3])=0;
  virtual HRESULT StoreCurveVertexW(int iNumCrvVertex, double iW)=0;

  //Bufer
  virtual HRESULT AddMeshVertices(unsigned int iFirstNumCrvVertex, unsigned int iNbCrvVertices, const CATULONG32* iMeshVertices)=0;
  virtual HRESULT UpdateCurveVertices(unsigned int iFirstNumCrvVertex, unsigned int iNbCrvVertices, 
                                      const double* iPositions, const double* iTangents, const double* iWs)=0;
  virtual HRESULT UpdateCurveVertices(const CATMathPolyBuffers* iCrvBuffers, unsigned int iFirstNumCrvVertex=0);

  //canonic
  virtual HRESULT StoreMathCurve(const CATPolyMathCurve* iMathCurve, const CATMathTransformation1D& iWTransfo)=0;

  //Config
  virtual CATBoolean NeedTangents()const=0;
  virtual CATBoolean NeedWs()const=0;
  virtual CATBoolean NeedMathCurve()const=0;
};

#endif
