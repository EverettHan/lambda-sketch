//====================================================================
// Copyright Dassault Systemes Provence 2005, all rights reserved 
//====================================================================
//
// CATFrFCreateCurveAdaptation :
// Declaration of global functions used to create and destroy
// an instance of the Curve Adaption operator
//
//=============================================================================
// Usage notes:
//  Je laisse la version sans configuration, le temps que le reverse migre.
//    Cf. le fichier : CATCldEdgeFaceServices.cpp
// sample of use :
// to provide
//
//==========================================================================
// April,   2005 : ANR/FZA : Creation     (D'apres  CreateCurveAdaptation) 
//==========================================================================

#ifndef CATFrFCreateCurveAdaptation_H 
#define CATFrFCreateCurveAdaptation_H 
//
#include "CATFrFNetSurface.h"
#include "CATSkillValue.h"
//
class CATGeoFactory;
class CATMathSetOfPoints;
class CATNurbsCurve;
class CATFrFCurveAdaptation;
class CATFrFNurbsMultiForm;
class CATSoftwareConfiguration;

//
/* Coverage
ExportedByFrFLoft
CATFrFCurveAdaptation * CATFrFCreateCurveAdaptation    ( CATGeoFactory      *ifactory,
                                                  const  CATMathSetOfPoints *iSetOfAdaptionPoints,
                                                  const  double             *iParamOfAdaptionPoints,
                                                  const  CATNurbsCurve      *iNurbsToBeAdapted,
                                                         CATSkillValue       iMode = BASIC,
                                                         CATBoolean          iComputeDeform = FALSE);
*/
//
ExportedByCATFrFNetSurface
CATFrFCurveAdaptation * CATFrFCreateCurveAdaptation    ( CATGeoFactory               * ifactory,
                                                         CATSoftwareConfiguration    * iSoftwareConfiguration,
                                                         const  CATMathSetOfPoints   * iSetOfAdaptionPoints,
                                                         const  double               * iParamOfAdaptionPoints,
                                                         const  CATFrFNurbsMultiForm * iNurbsToBeAdapted,
                                                         CATSkillValue                 iMode = BASIC,
                                                         CATBoolean                    iComputeDeform = FALSE);

ExportedByCATFrFNetSurface
CATFrFCurveAdaptation * CATFrFCreateCurveAdaptation    ( CATGeoFactory               * ifactory,
                                                         const  CATMathSetOfPoints   * iSetOfAdaptionPoints,
                                                         const  double               * iParamOfAdaptionPoints,
                                                         const  CATFrFNurbsMultiForm * iNurbsToBeAdapted,
                                                         CATSkillValue                 iMode = BASIC,
                                                         CATBoolean                    iComputeDeform = FALSE);
//
ExportedByCATFrFNetSurface
void Remove( CATFrFCurveAdaptation *&iAdaptionCurve );

#endif
