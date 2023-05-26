//===================================================================
// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSPointCurveJointCGM.h
// Driver of CATCSPointCurveJoint
// (implementation : CATCSPointCurveJointCGMImp)
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// July 2005  Creation                                          FCX
//===================================================================

#ifndef CATCSPointCurveJointCGM_H
#define CATCSPointCurveJointCGM_H

#include "CATIAV5Level.h"

// FCX 04.2021 : removed in CXR32/R424
#if !defined(CATIAV5R32) && !defined(CATIAR424)

#include "CATCDSVirtual.h"
#include "SkinWire.h"
#include "CATCSPointCurveJoint.h"
#include "CATCDSDeprecated.h"

class CATCSPointCurveJointCGMImp;
class CATCSPoint;
class CATCSCurve;

//-----------------------------------------------------------------------

class ExportedBySkinWire CATCSPointCurveJointCGM : public CATCSPointCurveJoint
{
public:

  // Object management

  CATCSPointCurveJointCGM(int iTestMode = 0);
  CATCDS_DEPRECATED("28/10/2016", "Remove useless rigid sets arguments", CATCSPointCurveJointCGM(CATCSRigidSet *ipRigidSet1, CATCSRigidSet *ipRigidSet2, int iTestMode = 0);)
  virtual ~CATCSPointCurveJointCGM();

  // Methods of CATCSPointCurveJoint

  virtual int SetGeometries(CATCSPoint * iPoint, CATCSCurve * iCurve) CATCDSOverride;
  virtual int ComputeHelpParameter();

private:
  CATCSPointCurveJointCGMImp *_pImp;
};

//-----------------------------------------------------------------------

#endif // #if !defined(CATIAV5R32) && !defined(CATIAR424)
#endif
