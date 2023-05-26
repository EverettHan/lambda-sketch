//===================================================================
// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSSlideCurveJointCGM.h
// Driver of CATCSSlideCurveJoint
// (implementation : CATCSSlideCurveJointCGMImp)
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// July 2005  Creation                                          FCX
//===================================================================

#ifndef CATCSSlideCurveJointCGM_H
#define CATCSSlideCurveJointCGM_H

#include "CATIAV5Level.h"

// FCX 04.2021 : removed in CXR32/R424
#if !defined(CATIAV5R32) && !defined(CATIAR424)

#include "CATCDSVirtual.h"
#include "SkinWire.h"
#include "CATCSSlideCurveJoint.h"
#include "CATCDSDeprecated.h"

class CATCSSlideCurveJointCGMImp;
class CATCSCurve;

//-----------------------------------------------------------------------

class ExportedBySkinWire CATCSSlideCurveJointCGM : public CATCSSlideCurveJoint
{
public:

  // Object management

  CATCSSlideCurveJointCGM(int iTestMode = 0);
  CATCDS_DEPRECATED("28/10/2016", "Remove useless rigid sets arguments", CATCSSlideCurveJointCGM(CATCSRigidSet *ipRigidSet1, CATCSRigidSet *ipRigidSet2, int iTestMode = 0);)
  virtual ~CATCSSlideCurveJointCGM();

  // Methods of CATCSSlideCurveJoint

  int SetGeometries(CATCSCurve * iCurve1, CATCSCurve * iCurve2) CATCDSOverride;
  int ComputeHelpParameters();

private:
  CATCSSlideCurveJointCGMImp *_pImp;
};

//-----------------------------------------------------------------------

#endif // #if !defined(CATIAV5R32) && !defined(CATIAR424)
#endif
