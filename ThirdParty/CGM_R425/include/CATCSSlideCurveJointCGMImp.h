//===================================================================
// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSSlideCurveJointCGMImp.h
// Implementation of CATCSSlideCurveJointCGM
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// July 2005  Creation                                          FCX
//===================================================================

#ifndef CATCSSlideCurveJointCGMImp_H
#define CATCSSlideCurveJointCGMImp_H

#include "CATIAV5Level.h"

// FCX 04.2021 : removed in CXR32/R424
#if !defined(CATIAV5R32) && !defined(CATIAR424)

#include "SkinWireImp.h"

class CATCSCurveCGMCurvilinearImp; 

//-----------------------------------------------------------------------

class ExportedBySkinWireImp CATCSSlideCurveJointCGMImp
{
public:

  // Object management

  CATCSSlideCurveJointCGMImp();
  virtual ~CATCSSlideCurveJointCGMImp();

  void SetGeometries(CATCSCurveCGMCurvilinearImp * iCurveImp1, CATCSCurveCGMCurvilinearImp * iCurveImp2);

  // Implementation methods

  virtual int ComputeHelpParameters(double & oHelpParam1, double & oHelpParam2);

private:
  CATCSCurveCGMCurvilinearImp *_Crv1;
  CATCSCurveCGMCurvilinearImp *_Crv2;
};

//-----------------------------------------------------------------------

#endif
#endif
