//====================================================================
// Copyright Dassault Systemes Provence 2005, all rights reserved 
//====================================================================
//
// CATFrFCurveAdaptation:
// Interface class of the Curve Adaption Operator.
//
//==========================================================================
//
// Usage notes:
//
//==========================================================================
// April,   2005 : ANR/FZA : Creation       (D'apres  CATCurveAdaptation)   
//==========================================================================

#ifndef CATFrFCurveAdaptation_H
#define CATFrFCurveAdaptation_H
//
#include "CATFrFNetSurface.h"
#include "CATMathDef.h"
#include "CATFrFCreateCurveAdaptation.h"
//
class CATNurbsCurve;
class CATFrFNurbsMultiForm;
class CATMathVector;
//
//-----------------------------------------------------------------------------
class ExportedByCATFrFNetSurface CATFrFCurveAdaptation
{
  public :

    virtual        ~CATFrFCurveAdaptation();
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
    virtual CATNurbsCurve       *  GetAdaptedCurve() =0;

    virtual CATFrFNurbsMultiForm*  GetAdaptedMultiForm() =0;

    virtual double                 GetMaxDeformation() =0 ;
};
#endif

