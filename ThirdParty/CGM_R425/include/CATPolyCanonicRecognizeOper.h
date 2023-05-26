// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCanonicRecognizeOper.h
//
//===================================================================
//
// Usage notes: Recognize canonics (planes, cylinders, cones, sphere, torus)
// in a Mesh, Curve
//
//===================================================================
//
// Jan 2008  Creation: ZFI
//===================================================================

#ifndef CATPolyCanonicRecognizeOper_H
#define CATPolyCanonicRecognizeOper_H

#include "CATPolyCanonicOperators.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"


class CATIPolySurface;
class CATIPolyCurve;

class CATPolyGeometricForm;

class CATPolyCanonicDetectOper;

class ExportedByCATPolyCanonicOperators CATPolyCanonicRecognizeOper
{

public:
  /**
  *  Constructor and Destructor
  */
  CATPolyCanonicRecognizeOper();
  virtual ~CATPolyCanonicRecognizeOper();


  /**
  *  Set Tolerances
  */
  HRESULT SetToleranceExact(float iTolExact);
  HRESULT SetToleranceSag(float iTolSag);
  HRESULT SetToleranceAlign(float iTolAlign);
  HRESULT SetToleranceAlignExact(float iTolAlignExact);
  

  /**
  /* UV Interpolation
  */
  HRESULT SetUseUVInterpolation(int iActivate);

  /**
  * Run
  */
  HRESULT Run(CATIPolySurface &iSurface, CATPolyGeometricForm& oForm) const;


  HRESULT Run(CATIPolyCurve &iCurve, CATPolyGeometricForm& oForm) const;

private:
  CATPolyCanonicDetectOper* _DetectOper;


};

#endif
