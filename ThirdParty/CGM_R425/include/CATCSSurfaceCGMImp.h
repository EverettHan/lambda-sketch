#ifndef CATCSSurfaceCGMImp_H
#define CATCSSurfaceCGMImp_H

#include "CATIAV5Level.h"

// FCX 04.2021 : removed in CXR32/R424
#if !defined(CATIAV5R32) && !defined(CATIAR424)

#include "SkinWireImp.h"
#include "CATBoolean.h"

class CATBody;
class CATFace;
class CATSurface;
class CATGeoFactory;
class CATMathPoint;

//-----------------------------------------------------------------------

class ExportedBySkinWireImp CATCSSurfaceCGMImp
{
public:
  CATCSSurfaceCGMImp(CATBody * iBody, CATFace * iFace, int iTestMode = 0);
  virtual ~CATCSSurfaceCGMImp();

  void GetFirstLimits(double &oLow, double &oUp);

  void GetSecondLimits(double &oLow, double &oUp);

  void Evaluate(double  iFirst,
                double  iSecond,
                double* oaPoint,
                double* oaDerivWithFirstParam,
                double* oaDerivWithSecondParam,
                double* oaSecondDeriv_du_du,
                double* oaSecondDeriv_du_dv,
                double* oaSecondDeriv_dv_dv);

  // iMode  0 : inclusion
  //        1 : distmin
  CATBoolean ComputeHelpParam(CATMathPoint & iPoint, int iMode, double * oParamUV);

private:
  CATFace       * _Face;
  CATSurface    * _Surf;
  CATGeoFactory * _Factory;
  double _ULow, _UHigh, _VLow, _VHigh;

  int _TestMode;
};

//-----------------------------------------------------------------------

#endif
#endif
