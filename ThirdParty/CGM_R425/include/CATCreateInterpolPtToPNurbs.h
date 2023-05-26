// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateInterpolPtToPNurbs:
// Declaration of global functions used to create and destroy
// an instance of the CATInterpolPtToPNurbs  operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// Sept. 97     Creation                   DHN
//=============================================================================
#ifndef CreateInterpolPtToPNurbs_H
#define CreateInterpolPtToPNurbs_H 

class CATGeoFactory;
class CATNurbsCurve;
class CATSurface;
class CATMathSetOfPointsND;
class CATMathPointsND;
class CATInterpolPtToPNurbs;

#include "FrFOpeCrv.h"
#include "CATDataType.h"
#include "CATSkillValue.h"


ExportedByFrFOpeCrv
 CATInterpolPtToPNurbs*  CATCreateInterpolPtToPNurbs(      CATGeoFactory        * iFactory,
                                                     const CATMathSetOfPointsND * iPoints ,
                                                     const CATLONG32            & nvar0   ,
                                                     const CATLONG32            & nvar1   ,
                                                     const CATLONG32            & nvar2   ,
                                                           CATSurface           * iSupport,
                                                           CATSkillValue          iMode   = BASIC);

#endif


