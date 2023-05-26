// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMPolyMathDecoder.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// August 2009  Creation: ZFI
//===================================================================

#ifndef CATCGMPolyMathDecoder_H
#define CATCGMPolyMathDecoder_H

#include "ExportedByTessellateCommon.h"

#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATTopDefine.h"

#include "CATICGMUVDecoder.h"

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATMathCurve;

class ExportedByTessellateCommon CATCGMPolyMathDecoder : public CATICGMUVDecoder
{
public:
  CATCGMPolyMathDecoder(CATGeoFactory* iGeoFactory, CATSoftwareConfiguration * iSoftwareConfiguration);
  virtual ~CATCGMPolyMathDecoder();

public:
  HRESULT ComputeApproxSurfaceFromExact(const CATSurface& iSurface,
                                        const CATSurLimits& iSurLimits,
                                        CATPolyMathQuadSurface*& oSurf,
                                        CATMathTransformation2D* oTransfo=0);


  HRESULT ComputeApproxMathCurveFromExact(const CATEdgeCurve& iEdgeCurve, 
                                          CATPolyMathCurve*& oCurve,
                                          CATMathTransformation1D* oTransfo=0);

  //canonic
public:
  static HRESULT ComputeCanonicMathSurfaceFromExact(const CATSurface& iGeomSurface,
                                                    CATPolyMathQuadSurface*& oSurf,
                                                    CATMathTransformation2D* oTransfo=0);


  static HRESULT ComputeCanonicMathCurveFromExact(const CATMathCurve& iMathCurve, 
                                                  CATPolyMathCurve*& oCurve,
                                                  CATMathTransformation1D* oTransfo=0);

private:
  CATGeoFactory* _GeoFactory;
  CATSoftwareConfiguration * _SoftwareConfiguration;
};

#endif
