#ifndef CATICDSBBoxSkinAdapter_H
#define CATICDSBBoxSkinAdapter_H

// COPYRIGHT DASSAULT SYSTEMES  2013

#include "CATCDS.h"

#include "CATCDSInline.h"
#include "CATCDSAdvancedEnums.h"
#include "CATICDSBBoxSkin.h"

class CATICDSSkin;
class CATICDSSkinParam;
class CATICDSFactory;

/**
 * @SKIP
 *
 * Abstract class that specifies a implementation of black box skins.
 * It is guarantied that each call with a skin parameter as input or
 * output is made with a parameter describuing the same skin (thus
 * created by this adapter's CreateParam method).
 */
class ExportedBySolverInterface CATICDSBBoxSkinAdapter
{
public:
  
  /** Destructor. */
  CATCDSInline virtual ~CATICDSBBoxSkinAdapter();
  
  /** Retreive skin. */
  CATCDSInline CATICDSBBoxSkin *GetSkin() const;

  /** @see CATICDSSkin::CreateParam */
  virtual CATICDSSkinParam* CreateParam() const = 0;

  /** @see CATICDSSkin::CreateParam */
  virtual CATICDSSkinParam* CreateParam(double iaPoint[3]) const = 0;

  /** @see CATICDSSkin::CreateParam */
  virtual CATICDSSkinParam* CreateParam(const CATICDSSkinParam *ipPointOnSkin) const = 0;

  /** @see CATICDSSkin::Evaluate */
  virtual CATCDSBoolean Evaluate(
    CATICDSSkinParam *ipPointOnSkin,
    double oaPoint[3],
    double oaDU[3],
    double oaDV[3],
    double oaD2U[3],
    double oaDUDV[3],
    double oaD2V[3]) const = 0;

  /** @see CATICDSSkin::EvaluateOnWire */
  virtual CATCDSBoolean EvaluateOnWire(
    CATICDSSkinParam *ipPointOnSkin,
    double oaPoint[3],
    double oaDW[3],
    double oaD2W[3]) const = 0;

  /** @see CATICDSSkin::GetClosePoint */
  virtual CATCDSBoolean GetClosePoint(
    CATICDSSkinParam *ipPointOnSkin,
    double iDeltaU, double iDeltaV,
    CATCSStopCommand iStopCommand,
    CATICDSSkinParam * opPointOnSkin,
    CATCSClosePointDiagnostics &oDiagnostics,
    double &oAppliedDeltaU, double &oAppliedDeltaV) const = 0;

  /** @see CATICDSSkin::GetClosePointOnWire */
  virtual CATCDSBoolean GetClosePointOnWire(
    CATICDSSkinParam * ipPointOnSkin,
    double iDeltaW,
    CATCSStopCommand iStopCommand,
    CATICDSSkinParam *opPointOnSkin,
    CATCSClosePointDiagnostics & oDiagnostics,
    double & oAppliedDeltaW) const = 0;

private:

  /** Skin container. */
  CATICDSBBoxSkin *_pSkin;
  friend CATICDSBBoxSkin* CATICDSBBoxSkin::Create(CATICDSFactory*, CATICDSBBoxSkinAdapter*);
};

CATCDSInline CATICDSBBoxSkinAdapter::~CATICDSBBoxSkinAdapter() {
  _pSkin = 0;}

CATCDSInline CATICDSBBoxSkin *CATICDSBBoxSkinAdapter::GetSkin() const {
  return _pSkin;}

#endif
