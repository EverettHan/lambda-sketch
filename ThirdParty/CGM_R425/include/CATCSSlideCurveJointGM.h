//===================================================================
// COPYRIGHT Dassault Systemes 2021
//===================================================================
//
// CATCSSlideCurveJointGM.h
// GM implementation of CATCSSlideCurveJoint
//
//===================================================================
//
// Usage notes:
// DEPRECATED OBJECT (use a CATCSTangency instead)
//
//===================================================================
// July 2005  Creation                                          FCX
// March 2021 Replacement of CATCSSlideCurveJointCGM            FCX
//===================================================================

#ifndef CATCSSlideCurveJointGM_H
#define CATCSSlideCurveJointGM_H

#include "CATCDSVirtual.h"
#include "SkinWireGM.h"
#include "CATCSSlideCurveJoint.h"
#include "SkinWireGMDefines.h"

#ifndef CATCDSGMINFRA_IMP
class CATCSSlideCurveJointCGMImp;
#endif

class CATCSSlideCurveJointGMImp;
class CATCSCurve;

//-----------------------------------------------------------------------

class ExportedBySkinWireGM CATCSSlideCurveJointGM : public CATCSSlideCurveJoint
{
public:

  // Object management

  CATCSSlideCurveJointGM();
  virtual ~CATCSSlideCurveJointGM();

  // Methods of CATCSSlideCurveJoint

  int SetGeometries(CATCSCurve * iCurve1, CATCSCurve * iCurve2) CATCDSOverride;
  int ComputeHelpParameters();

private:
#ifdef CATCDSGMINFRA_IMP
  CATCSSlideCurveJointGMImp *_pImp;
#else
  CATCSSlideCurveJointCGMImp *_pImp;
#endif
};

//-----------------------------------------------------------------------

#endif
