// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVCommon.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// June 2010  Creation: ZFI
//===================================================================

#ifndef CATCGMUVCommon_H
#define CATCGMUVCommon_H

#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATMathPoint;
class CATMathVector;

class  CATCGMUVCommon
{
public:
  CATCGMUVCommon();
  virtual ~CATCGMUVCommon();

public:

  static HRESULT SetCubicBezierOptimalTangentNorm(const CATMathPoint& iP1, const CATMathPoint& iP2, const CATMathPoint& iPMid,
                                                  CATMathVector& ioTg1,CATMathVector& ioTg2);
};

#endif
