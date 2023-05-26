// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATCreateCrvParametricExtend :
// Declaration of global functions used to create and destroy
// an instance of the Parametric Curve Extension operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// August 98  Creation                          DHN
//=============================================================================
#ifndef CATCreateCrvParametricExtend_H 
#define CATCreateCrvParametricExtend_H 
//
#include "PowerFrFOperators.h"
#include "CATSkillValue.h"
//
class CATCrvParam;
class CATCrvParametricExtend;
class CATNurbsCurve;
class CATSoftwareConfiguration;


ExportedByPowerFrFOperators
CATCrvParametricExtend * CATCreateCrvParametricExtend(CATSoftwareConfiguration * iSoft,
                                                   CATNurbsCurve  *iNurbsCrv,
                                                   const CATCrvParam &iCrvParam,
                                                   const double &iExtendRatio,
                                                   CATSkillValue iMode = BASIC);

//DO NOT USE ANYMORE. USE PREVIOUS CREATE INSTEAD.
ExportedByPowerFrFOperators
CATCrvParametricExtend * CATCreateCrvParametricExtend(CATNurbsCurve  *iNurbsCrv,
                                                   const CATCrvParam &iCrvParam,
                                                   const double &iExtendRatio,
                                                   CATSkillValue iMode = BASIC);

#endif


