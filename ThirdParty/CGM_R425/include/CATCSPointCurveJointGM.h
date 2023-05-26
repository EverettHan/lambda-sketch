//===================================================================
// COPYRIGHT Dassault Systemes 2021
//===================================================================
//
// CATCSPointCurveJointGM.h
// GM implementation of CATCSPointCurveJoint
//
//===================================================================
//
// Usage notes:
// DEPRECATED OBJECT (use a CATCSCoincidence instead)
//
//===================================================================
// July 2005  Creation                                          FCX
// March 2021 Replacement of CATCSPointCurveJointCGM            FCX
//===================================================================

#ifndef CATCSPointCurveJointGM_H
#define CATCSPointCurveJointGM_H

#include "CATCDSVirtual.h"
#include "SkinWireGM.h"
#include "CATCSPointCurveJoint.h"
#include "SkinWireGMDefines.h"

#ifndef CATCDSGMINFRA_IMP
class CATCSPointCurveJointCGMImp;
#endif

class CATCSPointCurveJointGMImp;
class CATCSPoint;
class CATCSCurve;

//-----------------------------------------------------------------------

class ExportedBySkinWireGM CATCSPointCurveJointGM : public CATCSPointCurveJoint
{
public:

  // Object management

  CATCSPointCurveJointGM();
  virtual ~CATCSPointCurveJointGM();

  // Methods of CATCSPointCurveJoint

  virtual int SetGeometries(CATCSPoint * iPoint, CATCSCurve * iCurve) CATCDSOverride;
  virtual int ComputeHelpParameter();

private:
#ifdef CATCDSGMINFRA_IMP
  CATCSPointCurveJointGMImp *_pImp;
#else
  CATCSPointCurveJointCGMImp *_pImp;
#endif
};

//-----------------------------------------------------------------------

#endif
