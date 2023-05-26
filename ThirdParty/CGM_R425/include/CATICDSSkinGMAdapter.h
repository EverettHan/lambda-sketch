//===================================================================
// COPYRIGHT Dassault Systemes 2016
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
// Dec 2016  Implementation in CATCDSGMInfra                      FCX
// Feb 2018  Use of CATSkinGMImp as implementation                FCX
//===================================================================

#ifndef CATICDSSkinGMAdapter_H
#define CATICDSSkinGMAdapter_H

#include "CATCDSVirtual.h"
#include "SkinWireGM.h"
#include "CATICDSBBoxSkinAdapter.h"
#include "CATCDSInline.h"
#include "SkinWireGMDefines.h"
#include <string.h>

#ifndef CATCDSGMINFRA_IMP
class CATSkinCGMImp;
class CATSkinParamCGMImp;
#endif

class CATBody;
class CATShell;
class CATFace;
class CATSoftwareConfiguration;
class CATSkinGMImp;
class CATSkinParamGMImp;
class CATMathPoint;
class CATMathLine;
class CATCGMStream;
class CATGeoFactory;

class ExportedBySkinWireGM CATICDSSkinGMAdapter : public CATICDSBBoxSkinAdapter
{
public:
  
  // Object management

  CATICDSSkinGMAdapter(CATSoftwareConfiguration * ipSoftwareConfiguration, CATBody * ipBody);
  
  // deprecated : use constructor without CATFace* argument
  CATICDSSkinGMAdapter(CATSoftwareConfiguration * ipSoftwareConfiguration, CATFace * ipFace, CATBody * ipBody);
  
  virtual ~CATICDSSkinGMAdapter();
  
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
  //int ComputeDistanceMin(CATMathLine & iLine, CATICDSSkinParam * oPointOnSkin) const;

  // FCX 09.2010 : for debug only
  void Stream(CATCGMStream & oStream);
  void Stream(char *& oStreamData, size_t & oLength);
  void Stream(const char* iDebugDir, const char* iDebugName, CATGeoFactory * iFactory, CATBody *& oSkinBody, unsigned int & oIndex);
  void StreamSP(CATICDSSkinParam * iPointOnSkin, const char* iDebugDir, const char* iDebugName, unsigned int & oIndex);
  
#ifdef CATCDSGMINFRA_IMP
  virtual CATSkinGMImp* GetImplementation() { return _pImp; }
#else
  virtual CATSkinCGMImp* GetImplementation() { return _pImp; }
#endif

private:
#ifdef CATCDSGMINFRA_IMP
  CATSkinGMImp *_pImp;
  CATCDSInline CATSkinParamGMImp* GetParamImp(const CATICDSSkinParam *ipPointOnSkin) const;
#else
  CATSkinCGMImp *_pImp;
  CATCDSInline CATSkinParamCGMImp* GetParamImp(const CATICDSSkinParam *ipPointOnSkin) const;
#endif
  CATSoftwareConfiguration *_pConfig;
};

#endif
