// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATCreateSurParametricExtend :
// Declaration of global functions used to create and destroy
// an instance of the Parametric Surface Extension operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// August 98  Creation                          DHN
//=============================================================================
#ifndef CATCreateSurParametricExtend_H 
#define CATCreateSurParametricExtend_H 
//
#include "PowerFrFOperators.h"
#include "CATSkillValue.h"
//
class CATSurParam;
class CATSurParametricExtend;
class CATNurbsSurface;
class CATSoftwareConfiguration;


ExportedByPowerFrFOperators
CATSurParametricExtend * CATCreateSurParametricExtend(CATSoftwareConfiguration *iSoft,
                                                   CATNurbsSurface *iNurbsSur,
                                                   const CATSurParam &iSurParam,
                                                   const double &iExtendRatio,
                                                   CATSkillValue iMode = BASIC);


//DO NOT USE ANYMORE. USE PREVIOUS CREATE INSTEAD.
ExportedByPowerFrFOperators
CATSurParametricExtend * CATCreateSurParametricExtend(CATNurbsSurface *iNurbsSur,
                                                   const CATSurParam &iSurParam,
                                                   const double &iExtendRatio,
                                                   CATSkillValue iMode = BASIC);

#endif


