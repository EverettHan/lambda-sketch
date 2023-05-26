// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATICGMUVDecoder.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// August 2009  Creation: ZFI
//===================================================================

#ifndef CATICGMUVDecoder_H
#define CATICGMUVDecoder_H

#include "ExportedByTessellateCommon.h"

#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATTopDefine.h"
#include "CATRefCounted.h"

class CATSurface;
class CATSurLimits;
class CATPolyMathQuadSurface;
class CATMathTransformation2D;
class CATEdgeCurve;
class CATPolyMathCurve;
class CATMathTransformation1D;

class  ExportedByTessellateCommon CATICGMUVDecoder : public CATRefCounted
{
public:
  CATICGMUVDecoder();
  virtual ~CATICGMUVDecoder();

public:
  virtual HRESULT ComputeApproxSurfaceFromExact(const CATSurface& iSurface,
                                                const CATSurLimits& iSurLimits,
                                                CATPolyMathQuadSurface*& oSurf,
                                                CATMathTransformation2D* oTransfo=0) =0;


  virtual HRESULT ComputeApproxMathCurveFromExact(const CATEdgeCurve& iEdgeCurve, 
                                                  CATPolyMathCurve*& oCurve,
                                                  CATMathTransformation1D* oTransfo=0)=0;
};

#endif
