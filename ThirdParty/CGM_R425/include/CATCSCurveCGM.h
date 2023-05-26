//===================================================================
// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSCurveCGM.h
// Driver of CATCSCurve (implementation : CATCSCurveCGMImp)
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// June 2005  Creation                                          FCX
// April 2008 Add of CATCSCurveCGMCurvilinearImp                KJD
//===================================================================

#ifndef CATCSCurveCGM_H
#define CATCSCurveCGM_H

#include "CATIAV5Level.h"

// FCX 04.2021 : removed in CXR32/R424
#if !defined(CATIAV5R32) && !defined(CATIAR424)

#include "CATCDSVirtual.h"
#include "SkinWire.h"
#include "CATCSCurve.h"

class CATCSCurveCGMImp;
class CATCSCurveCGMCurvilinearImp;
class CATSoftwareConfiguration;
class CATEdge;
class CATBody;
class CATCurve;
class CATCrvLimits;
class CATGeoFactory; // FCX 02.2009
class CATCGMStream;

enum CATCSPropagationMode
{
  CSG0Propagation,
  CSG1Propagation,
  CSG2Propagation,
  CSG0G1Propagation
};

enum CATCSCurveCGMContinuity
{
  CSUnknownContinuity = 0,
  CSG0Continuity,
  CSG1Continuity,
  CSG2Continuity
};



//-----------------------------------------------------------------------

class ExportedBySkinWire CATCSCurveCGM: public CATCSCurve
{
public:

  // Object management
  CATCSCurveCGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATEdge * iEdge, CATBody * iBody, CATCSPropagationMode iMode = CSG0G1Propagation, int iTestMode = 0);
  CATCSCurveCGM(CATSoftwareConfiguration * ipSoftwareConfiguration, int iNbCurves, CATCurve ** iCurves, CATCrvLimits * iCurveLimits, int * iOrientations, double iTolerance);
  CATCSCurveCGM();

  virtual ~CATCSCurveCGM();
  virtual void GetImplementation(CATCSCurveCGMImp*& oImp);
  virtual void GetImplementation(CATCSCurveCGMCurvilinearImp*& oImp);
  // Methods of CATCSCurve

  virtual CATCSCurve* Clone() const CATCDSOverride;

  virtual  void SetPeriodic();

  virtual  CATParamType GetLimits(double &oLow, double &oUp) CATCDSOverride;

  virtual CATCDSBoolean IsPlanar(double oPlaneCoords[6], double iLinearTolerance = CATCDSDefaultLinearTolerance) CATCDSOverride;

  virtual CATCDSBoolean ComputeDistanceMinParameter(double iPointCoords[3], double & oParameter) CATCDSOverride;

  virtual CATCDSBoolean ComputeDistanceMinParameter(CATCSCurve * iOtherCurve, double & oParamOnThisCurve, double & oParamOnTheOtherCurve);

  /**
  * Deprecated: do not use
  */
  virtual void Evaluate(double iT,
                        double* oaPoint,
                        double* oaFirstDeriv,
                        double* oaSecondDeriv) CATCDSOverride;

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

  virtual CATCDSBoolean IsClosed(CATCSCurveCGMContinuity & oClosureContinuity);

  // Stream/Unstream
  void Stream(CATCGMStream & oStream);
  void Stream(char *& oStreamData, size_t & oLength) CATCDSOverride;
  CATCDSBoolean Unstream(CATCGMStream & iStream, CATGeoFactory *& iopFactory);

  // Stream (old version)
  void Stream(const char* iDebugDir, const char* iDebugName, CATGeoFactory * iFactory, int & oNbCurves, CATCurve **& oCurveTable, unsigned int & oIndex, unsigned int *oType = 0);

private:
  CATCSCurveCGM(const CATCSCurveCGM & iCurveCGM);
  CATCDSBoolean _IsCurvilinear ;
  CATCSCurveCGMImp *_pImp;
  CATCSCurveCGMCurvilinearImp *_pCurvilinearImp;
 
  // tmp : used for CATCDSReplayStreamEK mode
  void GenerateDataFileName(const char* iDebugDir, const char* iDebugName, const char* iExtension, CATCDSString & oFileName, unsigned int & oIndex);
};

//-----------------------------------------------------------------------

#endif
#endif
