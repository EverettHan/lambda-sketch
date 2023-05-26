//===================================================================
// COPYRIGHT Dassault Systemes 2014
//===================================================================
//
// CATCSCurveGM.h
// GM CATCSCurve object
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// July 2014    Creation                                         FCX
// Feb 2018     Use of CATCSCurveGMImp as implementation         FCX
//===================================================================

#ifndef CATCSCurveGM_H
#define CATCSCurveGM_H

#include "CATCDSVirtual.h"
#include "SkinWireGM.h"
#include "CATCSCurve.h"
#include "SkinWireGMEnums.h"
#include "SkinWireGMDefines.h"

#ifndef CATCDSGMINFRA_IMP
class CATCSCurveCGMCurvilinearImp;
#endif

class CATCSCurveGMImp;
class CATSoftwareConfiguration;
class CATCurve;
class CATCrvLimits;
class CATGeoFactory;
class CATCGMStream;

//-----------------------------------------------------------------------

class ExportedBySkinWireGM CATCSCurveGM: public CATCSCurve
{
public:

  // Object management

  CATCSCurveGM();
  CATCSCurveGM(CATSoftwareConfiguration * ipSoftwareConfiguration, int iNbCurves, CATCurve ** iCurves, CATCrvLimits * iCurveLimits, int * iOrientations, double iApproxTolerance, CATCDSBoolean iNoReparameterization = FALSE);
  CATCSCurveGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATCurve * ipCurve);
  virtual ~CATCSCurveGM();
  
  virtual CATCSCurve* Clone() const CATCDSOverride;

  virtual void SetPeriodic();

  virtual CATParamType GetLimits(double &oLow, double &oUp) CATCDSOverride;

  virtual CATCDSBoolean IsPlanar(double oPlaneCoords[6], double iLinearTolerance = CATCDSDefaultLinearTolerance) CATCDSOverride;

  virtual CATCDSBoolean ComputeDistanceMinParameter(double iPointCoords[3], double & oParameter) CATCDSOverride;

  virtual CATCDSBoolean ComputeDistanceMinParameter(CATCSCurve * iOtherCurve, double & oParamOnThisCurve, double & oParamOnTheOtherCurve);

  virtual void Evaluate(double iT,
                        double* oaPoint,
                        double* oaFirstDeriv,
                        double* oaSecondDeriv,
                        double* oaThirdDeriv) CATCDSOverride;

  virtual int GetNbOfDiscontinuities() CATCDSOverride;

  virtual void GetDiscontinuitiesParams(double *oaValues) CATCDSOverride;

  virtual void EvaluateAtDiscontinuity(int iIdx,
                                       CATDiscontinuitySide iSide,
                                       double iT,
                                       double* oaPoint,
                                       double* oaFirstDeriv,
                                       double* oaSecondDeriv,
                                       double* oaThirdDeriv) CATCDSOverride;

  virtual void ApplyTransformation(const double iMatrix[3][3], const double iTranslation[3]) CATCDSOverride;

  virtual CATCDSBoolean IsClosed(CATCSCurveGMContinuity & oClosureContinuity);

  // Stream/Unstream
  void Stream(CATCGMStream & oStream);
  void Stream(char *& oStreamData, size_t & oLength) CATCDSOverride;
  void StreamNCGM(const char* iaOutputDir, const char* iaOutputName, CATGeoFactory * ipFactory, int & oNbCurves, CATCurve **& oCurveTable, unsigned int & ioIndex, CATCDSBoolean iForceIndex = FALSE);
  CATCDSBoolean Unstream(CATCGMStream & iStream, CATGeoFactory *& iopFactory);

  // internal use
#ifdef CATCDSGMINFRA_IMP
  inline CATCSCurveGMImp* GetImplementation() {return _pImp;}
#else
  inline CATCSCurveCGMCurvilinearImp* GetImplementation() { return _pImp; }
#endif

private:
  CATCSCurveGM(const CATCSCurveGM & iCurveGM);
#ifdef CATCDSGMINFRA_IMP
  CATCSCurveGMImp *_pImp;
#else
  CATCSCurveCGMCurvilinearImp *_pImp;
#endif
};

//-----------------------------------------------------------------------

#endif
