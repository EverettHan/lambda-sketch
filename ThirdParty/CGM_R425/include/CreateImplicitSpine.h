// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CreateImplicitSpine :
// Declaration of global functions used to create and destroy
// an instance of the ImplicitSpine operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// March 99 DHN Creation
// 24/01/03 CCK Ajout de la CATSoftwareConfiguration pour pouvoir appeler
//              la nouvelle spine CATFrFImplicitSpineCx10
// 02/01/14 NLD Menage, mise au propre, renommage, documentation
//=============================================================================

#ifndef CreateImplicitSpine_H 
#define CreateImplicitSpine_H 
//
#include "FrFAdvancedObjects.h"
#include "CATDataType.h"
#include "CATSkillValue.h"
//
class CATFrFImplicitSpine;
class CATFrFCompositeCurve;
class CATGeoFactory;
class CATMathPlane;
class CATSoftwareConfiguration;


// 1) cas mixte: CCVs + plans
//    -----------------------
//    les tableaux iOrdersOfCCVs et iOrdersOfPlanes contiennent les numeros (commencant a 1) des CCVs et des plans
//    parmi l'ensemble des bases (CCVs + plans)                                                        (NLD020114)
//    ex: pour traiter dans l'ordre CCV1, CCV2, Plan1, CCV3, Plan2
//    on cree iOrderOfCCVs[3] = {1, 2, 4} et iOrderOfPlanes[2] = {3, 5}
ExportedByFrFAdvancedObjects
CATFrFImplicitSpine * CreateImplicitSpine(CATGeoFactory           * iFactory       ,
                                          CATSoftwareConfiguration* iSoftwareConfig,
                                          CATLONG32                 iNumberOfCCVs  ,
                                          CATFrFCompositeCurve   ** iCCVs          ,
                                          CATLONG32               * iOrdersOfCCVs  ,
                                          CATLONG32                 iNumberOfPlanes,
                                          CATMathPlane            * iPlanes        ,
                                          CATLONG32               * iOrdersOfPlanes,
                                          CATSkillValue             iMode          = BASIC);
// 2) cas standard: CCVs seulement
//    ----------------------------
ExportedByFrFAdvancedObjects
CATFrFImplicitSpine * CreateImplicitSpine(CATGeoFactory           * iFactory       ,
                                          CATSoftwareConfiguration* iSoftwareConfig,
                                          CATLONG32                 iNumberOfCCVs  ,
                                          CATFrFCompositeCurve   ** iCCVs          ,
                                          CATSkillValue             iMode          = BASIC);

// Destructeur de l'operateur
// --------------------------
ExportedByFrFAdvancedObjects
void Remove(CATFrFImplicitSpine *&iImplicitSpine );


#endif






