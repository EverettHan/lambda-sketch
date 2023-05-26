/*-*-C++-*-*/
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATFairingCrvCx2 :
// Implementation class for Fairing.
//
//=============================================================================
// Usage notes: Curve Smoothing for curve and pcurve
// Note : 
// sample of use :   
// to provide
//
//=============================================================================
// Mar. 99  Creation
//=============================================================================
#ifndef CATFairingCrv_H
#define CATFairingCrv_H

#include "FrFOpeCrv.h"
#include "CATSkillValue.h"
#include "CATCGMVirtual.h"

class CATNurbsCurve;
class CATPNurbs;

//-----------------------------------------------------------------------------
class ExportedByFrFOpeCrv  CATFairingCrv : public CATCGMVirtual
{
 public:
  
  virtual ~CATFairingCrv() {};

  virtual void SetSmoothingFactor(double iSmooth) =0;
  
//  virtual void SetConvexMode(CATLONG32 iYesNo) =0; //1=Yes , 0=No

  virtual void Run() =0;
  
};



//-----------------------------------------------------------------------------
ExportedByFrFOpeCrv
CATFairingCrv * CreateFairingCrv(CATGeoFactory * iFactory,
                                 CATNurbsCurve * ioNurbsCurve,
                                 double iSmoothing=1.,
                                 CATSkillValue iMode = BASIC);


ExportedByFrFOpeCrv
CATFairingCrv * CreateFairingCrv(CATGeoFactory * iFactory,
                                 CATPNurbs     * ioPNurbs,
                                 double iSmoothing=1.,
                                 CATSkillValue iMode = BASIC);


ExportedByFrFOpeCrv void Remove(CATFairingCrv *&iFair);

#endif
  
