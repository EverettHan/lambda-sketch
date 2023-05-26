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
// Jul 2013 Creation                                              D5T
//===================================================================

#ifndef CATICDSCurveCGMAdapter_H
#define CATICDSCurveCGMAdapter_H

#include "CATIAV5Level.h"

// FCX 04.2021 : removed in CXR32/R424
#if !defined(CATIAV5R32) && !defined(CATIAR424)

#include "CATCDSVirtual.h"
#include "SkinWire.h"

#include "CATICDSBBoxCurveAdapter.h"

class CATCSCurveCGMImp;
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

class CATICDSCurveCGMAdapter: public CATICDSBBoxCurveAdapter
{
public:
  // Object management
  CATICDSCurveCGMAdapter(CATSoftwareConfiguration * ipSoftwareConfiguration, CATEdge * iEdge, CATBody * iBody, CATCSPropagationMode iMode = CSG0G1Propagation, int iTestMode = 0);
  CATICDSCurveCGMAdapter();
  
  virtual ~CATICDSCurveCGMAdapter();
  virtual void  GetImplementation(CATCSCurveCGMImp*& oImp);
  
  // Methods of CATCSCurve

  // Adapter implementation
  CATCDSBoolean Regenerate() CATCDSOverride;
  CATCDSParamType GetLimits(double &oLow, double &oUp) const CATCDSOverride;
  void Evaluate(double iT, double* oaPoint, double* oaFirstDeriv, double* oaSecondDeriv, double* oaThirdDeriv = 0) const CATCDSOverride;  
  int GetNbOfDiscontinuities() const CATCDSOverride;
  void GetDiscontinuitiesParams(double *oaValues) const CATCDSOverride;
  void EvaluateAtDiscontinuity(int iIdx, CATCDSDiscontinuitySide iSide, double iT, double* oaPoint, double* oaFirstDeriv, double* oaSecondDeriv, double* oaThirdDeriv = 0) const CATCDSOverride;
  CATCDSBoolean EvaluateLength(double iStart, double iEnd, double &oLength) const CATCDSOverride;

  virtual CATCDSBoolean IsClosed(CATCSCurveCGMContinuity & oClosureContinuity);

  // Stream/Unstream
  void Stream(CATCGMStream & oStream);
  CATCDSBoolean Unstream(CATCGMStream & iStream, CATGeoFactory *& iopFactory);

  // Stream (old version)
  void Stream(const char* iDebugDir, const char* iDebugName, CATGeoFactory * iFactory, int & oNbCurves, CATCurve **& oCurveTable, unsigned int & oIndex);

private:
  CATCSCurveCGMImp *_pImp;
};

#endif
#endif
