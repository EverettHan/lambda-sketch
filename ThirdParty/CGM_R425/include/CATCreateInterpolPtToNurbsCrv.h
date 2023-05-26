// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateCATInterpolPtToNurbsCrv:
// Declaration of global functions used to create and destroy
// an instance of theCATInterpolPtToNurbs  operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// Sept. 97     Creation                   DHN
// 27/04/12 NLD Ajout argument iSoftwareConfiguration
//=============================================================================
#ifndef CreateInterpolPtToNurbsCrv_H
#define CreateInterpolPtToNurbsCrv_H 

class CATGeoFactory;
class CATNurbsCurve;
class CATMathSetOfPointsND;
class CATMathPointsND;
class CATInterpolPtToNurbsCrv;
class CATSoftwareConfiguration;

#include "FrFOpeCrv.h"
#include "CATDataType.h"
#include "CATSkillValue.h"


ExportedByFrFOpeCrv
CATInterpolPtToNurbsCrv *CATCreateInterpolPtToNurbsCrv(      CATGeoFactory            * iFactory,
                                                             CATSoftwareConfiguration * iSoftwareConfiguration,
                                                       const CATMathSetOfPointsND     * iPoints,
                                                       const CATLONG32                & nvar0,
                                                       const CATLONG32                & nvar1,
                                                       const CATLONG32                & nvar2,
                                                             CATSkillValue              iMode);


#endif


