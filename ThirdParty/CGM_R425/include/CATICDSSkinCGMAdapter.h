//===================================================================
// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// CATICDSSkinCGM.h
//    CGM skin for CDS
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// May 2005  Creation                                             FCX
// Jul 2013  Migration to CDS public interfaces                   D5T
//===================================================================

#ifndef CATICDSSkinCGMAdapter_H
#define CATICDSSkinCGMAdapter_H

#include "CATIAV5Level.h"

// FCX 04.2021 : removed in CXR32/R424
#if !defined(CATIAV5R32) && !defined(CATIAR424)

#include "CATCDSVirtual.h"
#include "SkinWire.h"
#include "CATICDSBBoxSkinAdapter.h"
#include "CATCDSInline.h"

class CATBody;
class CATShell;
class CATFace;
class CATSoftwareConfiguration;
class CATSkinCGMImp;
class CATSkinParamCGMImp;
class CATMathPoint;
class CATGeoFactory;

class ExportedBySkinWire CATICDSSkinCGMAdapter : public CATICDSBBoxSkinAdapter
{
public:
  
  // Object management

  CATICDSSkinCGMAdapter(CATSoftwareConfiguration * ipSoftwareConfiguration, CATBody * ipBody);
  CATICDSSkinCGMAdapter(CATSoftwareConfiguration * ipSoftwareConfiguration, CATFace * ipFace, CATBody * ipBody);
  virtual ~CATICDSSkinCGMAdapter();
  virtual CATSkinCGMImp* GetImplementation();
  
  /** @see CATICDSSkin::CreateParam */
  CATICDSSkinParam* CreateParam() const CATCDSOverride;

  /** @see CATICDSSkin::CreateParam */
  CATICDSSkinParam* CreateParam(double iaPoint[3]) const CATCDSOverride;

  /** @see CATICDSSkin::CreateParam */
  CATICDSSkinParam* CreateParam(const CATICDSSkinParam *ipPointOnSkin) const CATCDSOverride;

  /** @see CATICDSSkin::Evaluate */
  CATCDSBoolean Evaluate(
    CATICDSSkinParam *ipPointOnSkin,
    double oaPoint[3],
    double oaDU[3],
    double oaDV[3],
    double oaD2U[3],
    double oaDUDV[3],
    double oaD2V[3]) const CATCDSOverride;

  /** @see CATICDSSkin::EvaluateOnWire */
  CATCDSBoolean EvaluateOnWire(
    CATICDSSkinParam *ipPointOnSkin,
    double oaPoint[3],
    double oaDW[3],
    double oaD2W[3]) const CATCDSOverride;

  /** @see CATICDSSkin::GetClosePoint */
  CATCDSBoolean GetClosePoint(
    CATICDSSkinParam *ipPointOnSkin,
    double iDeltaU, double iDeltaV,
    CATCSStopCommand iStopCommand,
    CATICDSSkinParam * opPointOnSkin,
    CATCSClosePointDiagnostics &oDiagnostics,
    double &oAppliedDeltaU, double &oAppliedDeltaV) const CATCDSOverride;

  /** @see CATICDSSkin::GetClosePointOnWire */
  CATCDSBoolean GetClosePointOnWire(
    CATICDSSkinParam * ipPointOnSkin,
    double iDeltaW,
    CATCSStopCommand iStopCommand,
    CATICDSSkinParam *opPointOnSkin,
    CATCSClosePointDiagnostics & oDiagnostics,
    double & oAppliedDeltaW) const CATCDSOverride;

  CATCDSBoolean EvaluateOnVertex(CATICDSSkinParam * iPointOnSkin, 
                                 double           * oaPoint) const;
  
  int ComputeDistanceMin(CATMathPoint & iPoint, CATICDSSkinParam * oPointOnSkin) const;

  // FCX 09.2010 : for debug only
  void Stream(const char* iDebugDir, const char* iDebugName, CATGeoFactory * iFactory, CATBody *& oSkinBody, unsigned int & oIndex);
  void StreamSP(CATICDSSkinParam * iPointOnSkin, const char* iDebugDir, const char* iDebugName, unsigned int & oIndex);
  
private:
  CATSkinCGMImp *_pImp;
  CATSoftwareConfiguration *_pConfig;

  CATCDSInline CATSkinParamCGMImp* GetParamImp(const CATICDSSkinParam *ipPointOnSkin) const;
};

#endif
#endif
