//===================================================================
// COPYRIGHT Dassault Systemes 2016
//===================================================================
//
// CATICDSCurve2DGMAdapter.h
// GM Driver of CATICDSBBoxCurve2DAdapter
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// March 2016 Creation                                          FCX
// Feb 2018     Use of CATCSCurve2DGMImp as implementation      FCX
//===================================================================

#ifndef CATICDSCurve2DGMAdapter_H
#define CATICDSCurve2DGMAdapter_H

#include "CATCDSVirtual.h"
#include "SkinWireGM.h"
#include "CATICDSBBoxCurve2DAdapter.h"
#include "SkinWireGMEnums.h"
#include "SkinWireGMDefines.h"

#ifndef CATCDSGMINFRA_IMP
class CATCSCurve2DCGMImp;
#endif

class CATCSCurve2DGMImp;
class CATSoftwareConfiguration;
class CATPCurve;
class CATCrvLimits;
class CATGeoFactory;
class CATCGMStream;
class CATMathPlane;

class ExportedBySkinWireGM CATICDSCurve2DGMAdapter: public CATICDSBBoxCurve2DAdapter
{
public:
  // Object management
  CATICDSCurve2DGMAdapter(CATSoftwareConfiguration * ipSoftwareConfiguration, int iNbCurves, CATPCurve ** iCurves, CATCrvLimits * iCurveLimits, int * iOrientations, double iTolerance);
  CATICDSCurve2DGMAdapter();
  virtual ~CATICDSCurve2DGMAdapter();
  
  // Methods of CATCSCurve

  virtual void SetPeriodic();

  // Adapter implementation
  CATCDSBoolean Regenerate() CATCDSOverride;
  CATCDSParamType GetLimits(double &oLow, double &oUp) const CATCDSOverride;
  void Evaluate2D(double iT, double* oaPoint, double* oaFirstDeriv, double* oaSecondDeriv, double* oaThirdDeriv = 0) const CATCDSOverride;  
  int GetNbOfDiscontinuities() const CATCDSOverride;
  void GetDiscontinuitiesParams(double *oaValues) const CATCDSOverride;
  void EvaluateAtDiscontinuity2D(int iIdx, CATCDSDiscontinuitySide iSide, double iT, double* oaPoint, double* oaFirstDeriv, double* oaSecondDeriv, double* oaThirdDeriv = 0) const CATCDSOverride;
  CATCDSBoolean EvaluateLength(double iStart, double iEnd, double &oLength) const CATCDSOverride;
  void GetDirection2D(double &oX, double &oY) const CATCDSOverride;
  CATCDSBoolean IsClosed(CATCSCurveGMContinuity & oClosureContinuity) const;

  // Stream/Unstream
  //void Stream(CATCGMStream & oStream);
  //CATCDSBoolean Unstream(CATCGMStream & iStream, CATGeoFactory *& iopFactory);

private:
#ifdef CATCDSGMINFRA_IMP
  CATCSCurve2DGMImp *_pImp;
#else
  CATCSCurve2DCGMImp *_pImp;
#endif
};

#endif
