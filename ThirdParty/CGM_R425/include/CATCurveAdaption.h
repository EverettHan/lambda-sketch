
//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1997 
//==========================================================================
//
// CATCurveAdaption:
// Interface class of the Curve Adaption Operator.
//
//==========================================================================
//
// Usage notes:
//
//========================================================================== 
// December 97     Creation
//========================================================================== 
//
#ifndef CATCurveAdaption_H
#define CATCurveAdaption_H
//
#include "FrFOpeCrv.h"
#include "CATMathDef.h"
#include "CreateCurveAdaption.h"
#include "CATCGMVirtual.h"
//
class CATNurbsCurve;
class CATFrFNurbsMultiForm;
class CATMathVector;
//
//-----------------------------------------------------------------------------
class ExportedByFrFOpeCrv CATCurveAdaption : public CATCGMVirtual
{
  public :

    virtual        ~CATCurveAdaption();
//
    virtual void   Run()=0;
//
//  Impose C1/C2 continuity at the ends of the adapted curve
//
    virtual void   SetExternalConditions(CATMathVector * StartFirstDeriv=0,
                                         CATMathVector * StartSecondDeriv=0,
                                         CATMathVector * EndFirstDeriv=0,
                                         CATMathVector * EndSecondDeriv=0)=0;

//
//  Getting the Adaption result
// 
    virtual CATNurbsCurve*  GetAdaptedCurve() =0;

    virtual CATFrFNurbsMultiForm*  GetAdaptedMultiForm() =0;
};
#endif

