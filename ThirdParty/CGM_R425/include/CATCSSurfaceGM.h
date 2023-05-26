//===================================================================
// COPYRIGHT Dassault Systemes 2018
//===================================================================
//
// CATCSSurfaceGM.h
// GM CATCSSurface object
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// Nov 2018    Creation                                         KUB
//===================================================================

#ifndef CATCSSurfaceGM_H
#define CATCSSurfaceGM_H

#include "CATCDSVirtual.h"
#include "CATCSSurface.h"
#include "StreamGM.h"

class CATCSSurfaceGMImp;
class CATSoftwareConfiguration;
class CATSurface;
class CATCrvLimits;
class CATGeoFactory;
class CATCGMStream;
class CATMathTransformation;

//-----------------------------------------------------------------------

class ExportedByStreamGM CATCSSurfaceGM: public CATCSSurface
{
public:

  // Object management

  CATCSSurfaceGM();
  //CATCSSurfaceGM(CATSoftwareConfiguration * ipSoftwareConfiguration, int iNbSurfaces, CATSurface ** iSurface, CATSurLimits * iCurveLimits, int * iOrientations);
  CATCSSurfaceGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATSurface *pSurface);
  virtual ~CATCSSurfaceGM();
  
  virtual void ApplyTransformation(const double iMatrix[3][3], const double iTranslation[3]);

  virtual void ResetTransformation();

  virtual void GetTransformation(CATMathTransformation& oTransfo);

  // Get the limits for first parameter of the curve
  virtual CATParamType GetFirstLimits(double &oLow, double &oUp) CATCDSOverride;

  // Get the limits for second parameter of the curve
  virtual CATParamType GetSecondLimits(double &oLow, double &oUp) CATCDSOverride;

  // Evaluate the surface point or/and derivative at given parameter's value
  virtual void Evaluate(double  iFirst,
    double  iSecond,
    double* oaPoint,
    double* oaDerivWithFirstParam,
    double* oaDerivWithSecondParam,
    double* oaSecondDeriv_du_du,
    double* oaSecondDeriv_du_dv,
    double* oaSecondDeriv_dv_dv) CATCDSOverride;


  // Stream/Unstream
  void Stream(CATCGMStream & oStream) ;
  void Stream(char *& oStreamData, size_t & oLength) ;
  CATCDSBoolean Unstream(CATCGMStream & iStream, CATGeoFactory *& iopFactory);


private:
  CATCSSurfaceGM(const CATCSSurfaceGM & iSurfGM);

  CATCSSurfaceGMImp *_pImp;

};

//-----------------------------------------------------------------------

#endif
