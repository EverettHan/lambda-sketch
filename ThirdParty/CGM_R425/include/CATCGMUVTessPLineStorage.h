// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVTessPLineStorage.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Jan 2012  Creation: ZFI
//===================================================================

#ifndef CATCGMUVTessPLineStorage_H
#define CATCGMUVTessPLineStorage_H

#include "ExportedByTessellateCommon.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATEdge;
class CATCGMUVTessMeshStorage;
class CATPolyMathCurve;
class CATMathTransformation1D;

class ExportedByTessellateCommon CATCGMUVTessPLineStorage
{
public :
  CATCGMUVTessPLineStorage();
  virtual ~CATCGMUVTessPLineStorage();

public:
  //Face Edge Curve Storage
  virtual HRESULT BeginPLineStorage(int iNbCrvVertices)=0;
  virtual HRESULT StoreCurveVertex(int iNumCrvVertex, const double iCoords[3])=0;
  virtual HRESULT StoreCurveVertexTangent(int iNumCrvVertex, const double iTangent[3])=0;
  virtual HRESULT StoreCurveVertexW(int iNumCrvVertex, double iW)=0;

  //Bufer
  virtual HRESULT UpdateCurveVertices(unsigned int iFirstNumCrvVertex, unsigned int iNbCrvVertices, 
                                      const double* iPositions, const double* iTangents, const double* iWs)=0;
  
  //canonic
  virtual HRESULT StoreMathCurve(const CATPolyMathCurve* iMathCurve, const CATMathTransformation1D& iWTransfo){return 0;} //to be virtualized //math surface released by caller

  //Config
  virtual CATBoolean NeedTangents()const=0;
  virtual CATBoolean NeedWs()const=0;
  virtual CATBoolean NeedMathCurve()const{return 0;}//to be virtualized
};

#endif
