/* -*-C++-*-*/
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateMixCurve :
// Declaration of global functions used to create and destroy
// an instance of the Mixing Curves operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// November. 97  Creation
//=============================================================================
#ifndef CreateMixCurves_H 
#define CreateMixCurves_H 
//
#include "FrFOpeCrv.h"
#include "CATSkillValue.h"
//
class CATGeoFactory;
class CATNurbsCurve;
class CATMixCurves;
//

ExportedByFrFOpeCrv
CATMixCurves * CreateMixCurves ( CATGeoFactory       *iFactory,
                                 const CATNurbsCurve *iCurve1 ,
                                 const CATNurbsCurve *iCurve2 ,
                                 const double         iAlpha  ,
                                 CATSkillValue  iMode = BASIC);
//
ExportedByFrFOpeCrv
CATMixCurves * CreateMixCurves ( CATGeoFactory       *iFactory,
                                 const CATNurbsCurve *iCurve1 ,
                                 const CATNurbsCurve *iCurve2 ,
                                 const double         iAlpha  ,
                                 const double         iBeta   ,
                                 CATSkillValue  iMode = BASIC);
//
ExportedByFrFOpeCrv
void Remove( CATMixCurves *&iMixCurves );

#endif


