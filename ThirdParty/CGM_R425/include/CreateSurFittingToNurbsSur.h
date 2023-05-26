//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1997 
//==========================================================================
//
// CATSurFittingToNurbsSur:
// Interface class of transformation from CATSurface to rational or non rational 
// CATNurbsSurface.
//
//
//==========================================================================
//
// Usage notes:
//========================================================================== 
// June 98     Creation                   DHN - NDN
//========================================================================== 

#ifndef CreateSurFittingToNurbsSur_H
#define CreateSurFittingToNurbsSur_H
/** @CAA2Required */ 
class CATSurFittingToNurbsSur;

#include "CATGeoFactory.h"
#include "CATSurface.h"
#include "FrFOpeSur.h"
#include "CATSkillValue.h"


//DO NOT USE -- USE CATCreateSurFittingToNurbsSur
ExportedByFrFOpeSur
CATSurFittingToNurbsSur*  CreateSurFittingToNurbsSur(CATGeoFactory   * iFactory         ,
                                                     const CATSurface &iSurface         ,
                                                     double            iMaxDeviation    ,
                                                     CATLONG32         iRationalAllowed = 1,
                                                     CATSkillValue     iMode            = BASIC);

ExportedByFrFOpeSur
void Remove( CATSurFittingToNurbsSur *&ioCATSurFittingToNurbsSur );



#endif
