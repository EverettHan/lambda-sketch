// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateFrFCoupling :
// Declaration of global functions used to create and destroy
// an instance of the Coupling operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
//   /12/97 CPL Creation
// 15/03/99 NLD Ajout iPreviousPointMemorization dans les constructeurs
//              (memorisation ou non du point precedent)
//              (ne pas memoriser lorsqu'on interroge en des points isoles
//              et non au sein d'un cheminement)
// 23 03 03 JSX Ajout CreateIndirectCoupling
// 01 01 05 JSX Ajout CreateDevelopCoupling
// 05 10 05 JSX Suppression de CreateIndirectCoupling (coverage : code non utilisé  )
// 28 02 07 NLD Nouvelle signature de Create avec CATFrFObject pour:
//              - CreateIntersectCoupling() (ancien supprime)
//              - CreateImposedPointsCoupling()
// 02 03 07 NLD Suppression du CreateImposedPointsCoupling() sur mapping imprecis
// 09 03 07 NLD Suppression du CreateIntersectCoupling() avec courbes en entree
// 14/05/08 NLD XScale. La tolerance en argument du CreateCCVParametricCoupling devient
//              obligatoire
// 14/11/12 NLD Suppression definitive des constructeurs inactives le 09/03/07
//              Mise au propre
//              Ajout CreateCurvilinearCoupling() avec CATFrFObject
//              Inactivation de certains constructeurs obsolete
//              - CreateCurvilinearCoupling() sans iLevel
// 07/04/16 NLD Ajout de Create avec CATFrFObject pour les couplings particuliers hors Sweep
//              - CreateDevelopCoupling()       (suppression de l'ancien)
//              - CreateCCVParametricCoupling()
//=============================================================================
#ifndef CreateFrFCoupling_H 
#define CreateFrFCoupling_H 
//
#include "FrFAdvancedObjects.h"
#include "CATFrFObject.h"
#include "CATMathDef.h"
#include "CATMathLimits.h"
#include "CATSkillValue.h"
#include "CATListOfCATCurves.h"
#include "CATListOfCATFrFCompositeCurve.h"
//
class CATCurve;
class CATFrFCoupling;
class CATCrvLimits;
class CATFrFCCvLimits;
class CATFrFMovingFrame;
class CATGeoFactory;
class CATFrFCompositeCurve;
class CATFrFCompositeCurveMapping;
class CATSoftwareConfiguration;

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif


#define CreateFrFCoupling_MaintainDeprecated141112
#ifdef CreateFrFCoupling_MaintainDeprecated141112
#endif

//-----------------------------------------------------------------------------
// Intersection coupling
//-----------------------------------------------------------------------------
ExportedByFrFAdvancedObjects
CATFrFCoupling * CreateIntersectCoupling    (CATFrFObject                   & iFrFObject         ,
                                             CATLISTP(CATFrFCompositeCurve)*  iCompCurves        ,
                                             CATFrFMovingFrame             *  iMovingFrame               = 0,
                                             CATBoolean                       iPreviousPointMemorization = TRUE);

//-----------------------------------------------------------------------------
// Curvilinear coupling
//-----------------------------------------------------------------------------
// iLevel = 0 : Constructeur identique  au constructeur sans level
// iLevel = 1 : Utilisation des PreciseCCVMapping
ExportedByFrFAdvancedObjects
CATFrFCoupling * CreateCurvilinearCoupling  (CATFrFObject                   & iFrFObject         ,
                                             CATLONG32                        iLevel             , 
                                             CATLONG32                        iNumberOfCompCurves,
                                             CATFrFCompositeCurve         **  iCompCurves        );
ExportedByFrFAdvancedObjects
CATFrFCoupling * CreateCurvilinearCoupling  (CATLONG32                        iLevel             , 
                                             CATLONG32                        iNumberOfCompCurves,
                                             CATFrFCompositeCurve         **  iCompCurves        );

#ifdef CreateFrFCoupling_MaintainDeprecated141112
ExportedByFrFAdvancedObjects
CATFrFCoupling * CreateCurvilinearCoupling  (CATLONG32                        iNumberOfCompCurves,
                                             CATFrFCompositeCurve         **  iCompCurves        );
#endif

//-----------------------------------------------------------------------------
// Imposed points coupling
//-----------------------------------------------------------------------------
// Dans ce constructeur, recommande, utilisation des PreciseCCVMapping
ExportedByFrFAdvancedObjects
CATFrFCoupling * CreateImposedPointsCoupling(CATFrFObject                   & iFrFObject         ,
                                             CATLONG32                        iNumberOfCompCurves,
                                             CATFrFCompositeCurve         **  iCompCurves        ,
                                             CATFrFCCvLimits               *  iCCvLimits         = NULL,
                                             CATFrFCompositeCurveMapping  **  iCCvMapping        = NULL);

// iLevel = 0 : Utilisation des vieux CCVMapping
// iLevel = 1 : Utilisation des PreciseCCVMapping
ExportedByFrFAdvancedObjects
CATFrFCoupling * CreateImposedPointsCoupling(CATFrFObject                   & iFrFObject         ,
                                             CATLONG32                        iLevel             ,
                                             CATLONG32                        iNumberOfCompCurves,
                                             CATFrFCompositeCurve         **  iCompCurves        ,
                                             CATFrFCCvLimits               *  iCCvLimits         = NULL,
                                             CATFrFCompositeCurveMapping  **  iCCvMapping        = NULL);

// iLevel = 0 : Constructeur identique  au constructeur sans level
// iLevel = 1 : Utilisation des PreciseCCVMapping
// deprecated
ExportedByFrFAdvancedObjects
CATFrFCoupling * CreateImposedPointsCoupling(CATGeoFactory                 *  iFactory           ,
                                             CATLONG32                        iLevel             ,
                                             CATLONG32                        iNumberOfCompCurves,
                                             CATFrFCompositeCurve         **  iCompCurves        ,
                                             CATFrFCCvLimits               *  iCCvLimits         = NULL,
                                             CATFrFCompositeCurveMapping  **  iCCvMapping        = NULL);

// deprecated avec mapping imprecis
ExportedByFrFAdvancedObjects
CATFrFCoupling * CreateDeprecatedImposedPointsCoupling
                                            (CATGeoFactory                 *  iFactory           ,
                                             CATLONG32                        iNumberOfCompCurves,
                                             CATFrFCompositeCurve         **  iCompCurves        ,
                                             CATFrFCCvLimits               *  iCCvLimits         = NULL,
                                             CATFrFCompositeCurveMapping  **  iCCvMapping        = NULL);

//-----------------------------------------------------------------------------
// CCV Parametric coupling
//-----------------------------------------------------------------------------
// la tolerance est une tolerance sur le parametre, dans [0,1]
ExportedByFrFAdvancedObjects
CATFrFCoupling* CreateCCVParametricCoupling (CATFrFObject                   & iFrFObject         ,
                                             CATFrFCompositeCurve         **  CCVs               ,
                                             CATLONG32                        nbCCVs             ,
                                             CATLONG32                        nbOfCurvesOnCCVs   ,
                                             double                        *  iLimitParams       ,
                                             double                           iParamTolerance    );
// deprecated

ExportedByFrFAdvancedObjects
CATFrFCoupling* CreateCCVParametricCoupling (CATFrFCompositeCurve         **  CCVs               ,
                                             CATLONG32                        nbCCVs             ,
                                             CATLONG32                        nbOfCurvesOnCCVs   ,
                                             double                        *  iLimitParams       ,
                                             double                           iParamTolerance    );

//

//-----------------------------------------------------------------------------
// Indirect coupling
//-----------------------------------------------------------------------------
/* JSX 05 10 05 
ExportedByFrFAdvancedObjects
CATFrFCoupling* CreateIndirectCoupling      (CATGeoFactory                 *  iFactory           ,
                                             CATFrFCoupling                *  iCoupling          );
*/

//-----------------------------------------------------------------------------
// Develop coupling
//-----------------------------------------------------------------------------
ExportedByFrFAdvancedObjects
CATFrFCoupling* CreateDevelopCoupling       (CATFrFObject                   & iFrFObject         ,
                                             CATLONG32                        iNumberOfCompCurves,
                                             CATFrFCompositeCurve         **  iCompCurves        ,
                                             CATFrFCompositeCurveMapping  **  iCCvMapping        = NULL);

//-----------------------------------------------------------------------------
// Develop coupling
// deprecated NLD070416 see above
//-----------------------------------------------------------------------------
/*
ExportedByFrFAdvancedObjects
CATFrFCoupling* CreateDevelopCoupling       (CATGeoFactory                 *  iFactory           ,
                                             CATSoftwareConfiguration      *  iConfig            ,
                                             CATLONG32                        iNumberOfCompCurves,
                                             CATFrFCompositeCurve         **  iCompCurves        ,
                                             CATFrFCompositeCurveMapping  **  iCCvMapping        = NULL);
*/
//-----------------------------------------------------------------------------
// Coupling removal (for any coupling type)
//-----------------------------------------------------------------------------
ExportedByFrFAdvancedObjects
void Remove(CATFrFCoupling *&ioCoupling );

#endif


