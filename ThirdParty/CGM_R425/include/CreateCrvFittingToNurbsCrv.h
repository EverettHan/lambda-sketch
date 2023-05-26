//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1997 
//==========================================================================
//
// CATCrvFittingToNurbsCrv:
// Interface class of transformation from CATCurve to rational or non rational 
// CATNurbsCurve or CATPNurbs.
//
//
//==========================================================================
//
// Usage notes:
//========================================================================== 
// May 98     Creation                   DHN - NDN
//========================================================================== 

#ifndef CreateCrvFittingToNurbsCrv_H
#define CreateCrvFittingToNurbsCrv_H
/** @CAA2Required */ 
class CATCrvFittingToNurbsCrv;

#include "CATGeoFactory.h"
#include "CATCurve.h"
#include "FrFOpeCrv.h"
#include "CATSkillValue.h"


//DO NOT USE -- USE CATCreateCrvFittingToNurbsCrv
ExportedByFrFOpeCrv
CATCrvFittingToNurbsCrv*  CreateCrvFittingToNurbsCrv(CATGeoFactory  *iFactory         ,
                                                     const CATCurve &iCurve           ,
                                                     double          iMaxDeviation    ,
                                                     CATLONG32       iRationalAllowed = 1,
                                                     CATSkillValue   iMode            = BASIC);

ExportedByFrFOpeCrv
void Remove( CATCrvFittingToNurbsCrv *&iCATCrvFittingToNurbsCrv );



#endif
