// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCanonicFastRecognizeOper.h
//
//===================================================================
//
// Usage notes: Recognize canonics (planes, cylinders, cones, sphere, torus)
// in a Mesh, Curve
//
//===================================================================
//
// Dec 2009  Creation: ZFI
//===================================================================

#ifndef CATPolyCanonicFastRecognizeOper_H
#define CATPolyCanonicFastRecognizeOper_H

#include "CATPolyCanonicOperators.h"

#include "CATErrorDef.h"
#include "CATBoolean.h"

#include "CATPolyCanonicFastRecognizeOptions.h"


class CATIPolySurface;
class CATIPolyCurve;

class CATPolyGeometricForm;

class CATPolyCanonicDetectOper;

class CATIPolyMesh;
class CATMathVector;

class ExportedByCATPolyCanonicOperators CATPolyCanonicFastRecognizeOper
{

public:
  /**
  *  Constructor and Destructor
  */
  CATPolyCanonicFastRecognizeOper();
  virtual ~CATPolyCanonicFastRecognizeOper();


  /**
  *  Set Tolerances
  */
  inline HRESULT SetToleranceExact(double iTolExact);
  inline HRESULT SetToleranceSag(double iTolSag);
  inline HRESULT SetToleranceAlign(double iTolAlign);
  inline HRESULT SetToleranceAlignExact(double iTolAlignExact);
  

  /**
  /* UV Interpolation
  */
  inline HRESULT SetUseUVInterpolation(CATBoolean iActivate);

  /**
  /* Recognized Forms
  */
  inline HRESULT SetPlaneRecognition(CATBoolean iActivate);
  inline HRESULT SetCylinderRecognition(CATBoolean iActivate);
  inline HRESULT SetSphereRecognition(CATBoolean iActivate);
  inline HRESULT SetConeRecognition(CATBoolean iActivate);
  inline HRESULT SetTorusRecognition(CATBoolean iActivate);
  inline HRESULT SetLineRecognition(CATBoolean iActivate);
  inline HRESULT SetCircleRecognition(CATBoolean iActivate);


  /**
  * Run
  */
  HRESULT Run(CATIPolySurface &iSurface, CATPolyGeometricForm& oForm) const;


  HRESULT Run(CATIPolyCurve &iCurve, CATPolyGeometricForm& oForm) const;


private:
  CATBoolean _PlaneRecognition,_CylinderRecognition, _SphereRecognition, _ConeRecognition,_TorusRecognition;
  CATBoolean _LineRecognition,_CircleRecognition;

  CATPolyCanonicFastRecognizeOptions _Options;
};


//INLINE

inline HRESULT CATPolyCanonicFastRecognizeOper::SetToleranceExact(double iTolExact)
{
  return _Options.SetToleranceExact(iTolExact);
}

inline HRESULT CATPolyCanonicFastRecognizeOper::SetToleranceSag(double iTolSag)
{
  return _Options.SetToleranceSag(iTolSag);
}

inline HRESULT CATPolyCanonicFastRecognizeOper::SetToleranceAlign(double iTolAlign)
{
  return _Options.SetToleranceAlign(iTolAlign);
}

HRESULT CATPolyCanonicFastRecognizeOper::SetToleranceAlignExact(double iTolAlignExact)
{
  return _Options.SetToleranceAlignExact(iTolAlignExact);
}

inline HRESULT CATPolyCanonicFastRecognizeOper::SetUseUVInterpolation(CATBoolean iActivate)
{
  return _Options.SetUseUVInterpolation(iActivate);
}

inline HRESULT CATPolyCanonicFastRecognizeOper::SetPlaneRecognition(CATBoolean iActivate)
{
  _PlaneRecognition = iActivate;
  return S_OK;
}

inline HRESULT CATPolyCanonicFastRecognizeOper::SetCylinderRecognition(CATBoolean iActivate)
{
  _CylinderRecognition = iActivate;
  return S_OK;
}

inline HRESULT CATPolyCanonicFastRecognizeOper::SetSphereRecognition(CATBoolean iActivate)
{
  _SphereRecognition = iActivate;
  return S_OK;
}

inline HRESULT CATPolyCanonicFastRecognizeOper::SetConeRecognition(CATBoolean iActivate)
{
  _ConeRecognition = iActivate;
  return S_OK;
}

inline HRESULT CATPolyCanonicFastRecognizeOper::SetTorusRecognition(CATBoolean iActivate)
{
  _TorusRecognition = iActivate;
  return S_OK;
}
inline HRESULT CATPolyCanonicFastRecognizeOper::SetLineRecognition(CATBoolean iActivate)
{
  _LineRecognition = iActivate;
  return S_OK;
}
inline HRESULT CATPolyCanonicFastRecognizeOper::SetCircleRecognition(CATBoolean iActivate)
{
  _CircleRecognition = iActivate;
  return S_OK;
}

#endif
