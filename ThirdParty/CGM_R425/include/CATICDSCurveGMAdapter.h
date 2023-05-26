//===================================================================
// COPYRIGHT Dassault Systemes 2015
//===================================================================
//
// CATICDSCurveGMAdapter.h
// GM Driver of CATICDSBBoxCurveAdapter
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// March 2015 Creation                                          FCX
// Feb 2018     Use of CATCSCurveGMImp as implementation         FCX
//===================================================================

#ifndef CATICDSCurveGMAdapter_H
#define CATICDSCurveGMAdapter_H

#include "CATCDSVirtual.h"
#include "SkinWireGM.h"
#include "CATICDSBBoxCurveAdapter.h"
#include "SkinWireGMEnums.h"
#include "SkinWireGMDefines.h"

#ifndef CATCDSGMINFRA_IMP
class CATCSCurveCGMImp; // for adaptive sweep only
#endif

class CATCSPropagationCurveGMImp;
class CATSoftwareConfiguration;
class CATEdge;
class CATBody;
class CATCurve;
class CATCrvLimits;
class CATGeoFactory; // FCX 02.2009
class CATCGMStream;

class ExportedBySkinWireGM CATICDSCurveGMAdapter: public CATICDSBBoxCurveAdapter
{
public:
  // Object management
  CATICDSCurveGMAdapter(CATSoftwareConfiguration * ipSoftwareConfiguration, CATEdge * iEdge, CATBody * iBody, CATCSCurveGMPropagationMode iMode = CSG0G1Propagation);
  //CATICDSCurveGMAdapter(CATSoftwareConfiguration * ipSoftwareConfiguration, int iNbCurves, CATCurve ** iCurves, CATCrvLimits * iCurveLimits, int * iOrientations, double iTolerance);
  //CATICDSCurveGMAdapter();
  
  virtual ~CATICDSCurveGMAdapter();
  
#ifdef CATCDSGMINFRA_IMP
  void  GetImplementation(CATCSPropagationCurveGMImp*& oImp);
#else
  void  GetImplementation(CATCSCurveCGMImp*& oImp);
#endif

  // Adapter implementation
  CATCDSBoolean Regenerate() CATCDSOverride;
  CATCDSParamType GetLimits(double &oLow, double &oUp) const CATCDSOverride;
  void Evaluate(double iT, double* oaPoint, double* oaFirstDeriv, double* oaSecondDeriv, double* oaThirdDeriv = 0) const CATCDSOverride;  
  int GetNbOfDiscontinuities() const CATCDSOverride;
  void GetDiscontinuitiesParams(double *oaValues) const CATCDSOverride;
  void EvaluateAtDiscontinuity(int iIdx, CATCDSDiscontinuitySide iSide, double iT, double* oaPoint, double* oaFirstDeriv, double* oaSecondDeriv, double* oaThirdDeriv = 0) const CATCDSOverride;
  CATCDSBoolean EvaluateLength(double iStart, double iEnd, double &oLength) const CATCDSOverride;

  virtual CATCDSBoolean IsClosed(CATCSCurveGMContinuity & oClosureContinuity);

  // Stream/Unstream
  void Stream(CATCGMStream & oStream);
  CATCDSBoolean Unstream(CATCGMStream & iStream, CATGeoFactory *& iopFactory);

private:
#ifdef CATCDSGMINFRA_IMP
  CATCSPropagationCurveGMImp *_pImp;
#else
  CATCSCurveCGMImp *_pImp;
#endif
};

#endif
