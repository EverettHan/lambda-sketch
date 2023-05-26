//===================================================================
// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSPointCurveJointCGMImp.h
// Implementation of CATCSPointCurveJointCGM
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// July 2005  Creation                                          FCX
//===================================================================

#ifndef CATCSPointCurveJointCGMImp_H
#define CATCSPointCurveJointCGMImp_H

#include "CATIAV5Level.h"

// FCX 04.2021 : removed in CXR32/R424
#if !defined(CATIAV5R32) && !defined(CATIAR424)

#include "SkinWireImp.h"

class CATCSCurveCGMCurvilinearImp; 
class CATMathPoint;

//-----------------------------------------------------------------------

class ExportedBySkinWireImp CATCSPointCurveJointCGMImp
{
public:

  // Object management

  CATCSPointCurveJointCGMImp();
  virtual ~CATCSPointCurveJointCGMImp();
 
  virtual void SetCurveImp(CATCSCurveCGMCurvilinearImp * iCurveImp);
 
  // Implementation methods

  virtual int ComputeHelpParameter(CATMathPoint * iPoint, double & oHelpParam);

private:
  CATCSCurveCGMCurvilinearImp *_Crv;
};

//-----------------------------------------------------------------------

#endif
#endif
