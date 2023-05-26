// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateCurveAdaption :
// Declaration of global functions used to create and destroy
// an instance of the Curve Adaption operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// December  97  Creation
//=============================================================================
#ifndef CreateCurveAdaption_H 
#define CreateCurveAdaption_H 
//
#include "FrFOpeCrv.h"
#include "CATSkillValue.h"
//
class CATGeoFactory;
class CATMathSetOfPoints;
class CATNurbsCurve;
class CATCurveAdaption;
class CATFrFNurbsMultiForm;
//
ExportedByFrFOpeCrv
CATCurveAdaption * CreateCurveAdaption    ( CATGeoFactory      *ifactory,
                                     const  CATMathSetOfPoints *iSetOfAdaptionPoints,
                                     const  double             *iParamOfAdaptionPoints,
                                     const  CATNurbsCurve      *iNurbsToBeAdapted,
                                            CATSkillValue       iMode = BASIC);
//
ExportedByFrFOpeCrv
CATCurveAdaption * CreateCurveAdaption    ( CATGeoFactory         *ifactory,
                                     const  CATMathSetOfPoints    *iSetOfAdaptionPoints,
                                     const  double                *iParamOfAdaptionPoints,
                                     const  CATFrFNurbsMultiForm  *iNurbsToBeAdapted,
                                            CATSkillValue          iMode = BASIC);
//
ExportedByFrFOpeCrv
void Remove( CATCurveAdaption *&iAdaptionCurve );

#endif


