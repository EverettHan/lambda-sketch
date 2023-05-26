// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateFrFSetOfBaseCurves :
// Declaration of global functions used to create and destroy
// an instance of the SetOfBaseCurves operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// December 97  Creation                          CPL
// December 98  Modif                             CPL
// March    99  Modif                             CPL
// 23 05 05 JSX : Ajout de la config
// 31 08 06 JSX : Suppression de 2 constructeurs inutilisés
// 14 03 07 NLD : On recoit un CATFrFObject 
// 02 06 10 JSX : Ajout de iExactSideDerivative
//=============================================================================
#ifndef CreateFrFSetOfBaseCurves_H
#define CreateFrFSetOfBaseCurves_H
//
#include "FrFAdvancedObjects.h"
#include "CATFrFObject.h"
#include "CATMathDef.h"
#include "CATSkillValue.h"
//
//class CATFrFProfile;
class CATFrFSetOfBaseCurves;
class CATGeoFactory;
class CATFrFCompositeCurve;
class CATFrFCoupling;
class CATMathVector;
class CATFrFNurbsMultiForm;
class CATSoftwareConfiguration;
//
ExportedByFrFAdvancedObjects
CATFrFSetOfBaseCurves * CreateSetOfBaseCurves(CATFrFObject& iFrFObject,
                                              CATLONG32 iNumberOfBases,
                                              CATFrFCompositeCurve** iBases,
                                              CATLONG32* iOrientations,
                                              CATLONG32 iComputeFirstTgt= 0,
                                              CATLONG32 iComputeLastTgt= 0,
                                              CATMathVector* iFirstTgt= 0,
                                              CATMathVector* iLastTgt= 0,
                                              CATFrFNurbsMultiForm** iNurbsPeigne1= 0,
                                              CATFrFNurbsMultiForm** iNurbsPeigne2= 0,
                                              CATLONG32 iMasterProfileIndex = -1,
                                              CATLONG32 isClosed= 0,
                                              CATBoolean iMultiFitting= FALSE,
                                              double iTolForApprox= -1.,
                                              CATBoolean iExactSideDerivative= FALSE);
//
ExportedByFrFAdvancedObjects
CATFrFSetOfBaseCurves * CreateSetOfBaseCurves(CATFrFObject& iFrFObject,
                                              CATLONG32 iNumberOfBases,
                                              CATFrFCompositeCurve** iBases, CATLONG32 iMasterProfileIndex = -1);
//
ExportedByFrFAdvancedObjects
void Remove(CATFrFSetOfBaseCurves *&ioSetOfBaseCurves );

#endif


