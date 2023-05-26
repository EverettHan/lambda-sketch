// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCanonicFastRecognizeOptions.h
//
//===================================================================
//
// Usage notes: Recognize cylinders
//
//
//===================================================================
//
// Dec 2009  Creation: ZFI
//===================================================================

#ifndef CATPolyCanonicFastRecognizeOptions_H
#define CATPolyCanonicFastRecognizeOptions_H

#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATPolyCanonicFastRecognizeOptions
{

public:
  /**
  *  Constructor and Destructor
  */
  CATPolyCanonicFastRecognizeOptions();
  virtual ~CATPolyCanonicFastRecognizeOptions();

  /**
  *  Set Tolerances
  */
  HRESULT SetToleranceExact(double iTolExact){_TolExact=iTolExact;return S_OK;}
  HRESULT SetToleranceSag(double iTolSag){_TolSag = iTolSag;return S_OK;}
  HRESULT SetToleranceAlign(double iTolAlign){_TolAlign = iTolAlign; return S_OK;}
  HRESULT SetToleranceAlignExact(double iTolAlignExact){return E_FAIL;}

  /**
  * Get Tolerances
  */
  double GetToleranceExact()const{return _TolExact;}
  double GetToleranceSag()const{return _TolSag;}
  double GetToleranceAlign()const{return _TolAlign;}
  double GetToleranceAlignExact()const{return 0;}

  /**
  /* UV Interpolation
  */
  HRESULT SetUseUVInterpolation(CATBoolean iActivate){_UVInterpolation =  iActivate; return S_OK;}
  CATBoolean GetUseUVInterpolation()const{return _UVInterpolation;}

  /**
  /* Recognized Forms
  */
  HRESULT SetPlaneRecognition(CATBoolean iActivate){_PlaneRecognition = iActivate; return S_OK;}
  HRESULT SetCylinderRecognition(CATBoolean iActivate){_CylinderRecognition = iActivate; return S_OK;}
  HRESULT SetSphereRecognition(CATBoolean iActivate){_SphereRecognition = iActivate; return S_OK;}

private:
  double _TolSag, _TolAlign, _TolExact;
  CATBoolean _UVInterpolation;
  CATBoolean _PlaneRecognition,_CylinderRecognition, _SphereRecognition;

};

#endif
