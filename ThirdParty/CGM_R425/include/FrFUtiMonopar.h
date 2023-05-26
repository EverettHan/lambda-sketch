// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// FrFUtiMonopar :
// Declaration of utilities on Monopars used in the FreeFormOperators FW
//
// Situation XScale: OK 
//                   (sauf MakeNurbsCurveClamped(), mais les appelants doivent migrer 
//                    vers CATMakeNurbsCurveClamped) NLD090215.
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
//    09/97 TPG Creation                                       Tuan Phung (tpg)
// 03/11/03 CCK Ajout de la SoftwareConfig dans RelativeCurveOrientation, 
//              RelativeCCvOrientation et AnalyseCurveOrientation
// 16/01/15 NLD Detabulation
//              Smart indent
//              Recensement des utilisations internes/externes des methodes et de leurs interfaces CATPGM*
// 19/01/15 NLD Revue
//              - ajout nouvelle signature de CATMakeNurbsCurveClamped() avec factory et configuration
//                a utiliser en remplacement de  MakeNurbsCurveClamped()
//                pour creation de CATKnotVector et CATFrFNurbsMultiForm avec objet CATTolerance
//                N.B interfacage de CATMakeNurbsCurveClamped() en CATPGMMakeNurbsCurveClamped() le 20/01/15
//                N.B on aurait pu recevoir l'objet CATTolerance et non la factory
//                    mais les programmes appelants, mis a part celui de test unitaire,
//                    disposeront d'une factory
// 09/02/15 NLD Suppression des interfacages non desires pour ces utilitaires non strategiques
//              - Ajout de @nodoc @nocgmitf pour toutes methodes sauf
//              CATMakeNurbsCurveClamped() et MakeNurbsCurveClamped()
// 16/06/20 NLD AnalyseCurveOrientation() n'est plus visible de manière externe
//=============================================================================

//=============================================================================
// Revue des interfaces, et compatibilite XScale. NLD190115
// ---------------------------------------------
// Statut des methodes
// -------------------

//    - Ajouter Configuration a
//      (Dans ces methodes la factory n'est pas necessaire car on peut acceder a la tolerance sous les MultiForms)
//           - IsIsoPLineInverted
//    - Ajouter Factory et Config a
//      (OK) - MakeNurbsCurveClamped    ATTENTION: utilisee en externe
//             donc je duplique la signature
//           - MakeClampedData (en fait peut s'en sortir sans la factory car recoit une tolerance)
//    - Laisser en etat malgre l'absence de factory
//      (Dans ces methodes la factory n'est pas necessaire car on peut acceder a la tolerance sous les MultiForms
//       ou des elements geometriques)
//    - Laisser en etat car presence de factory et configuration, toutes les autres methodes
//    - Reordonner les arguments de
//      - RelativeCurveOrientation
//      - RelativeCCvOrientation
//      - AnalyseCurveOrientation

// -       RelativeCurveOrientation     utilisee (dans FreeFormOperators: 4 appelants synchrones chez moi),
//                                      dupliquee dans CATCltGeometricUtilities.et dans CATFrFFSGeometricUtilities
//   CATPGMRelativeCurveOrientation non utilisee SUPPRIMEE
//
// -       RelativeCCvOrientation       utilisee (dans AdvancedTopologicalOpe, FreeFormOperators), 1 appelant synchrone
//   CATPGMRelativeCCvOrientation   non utilisee SUPPRIMEE
// -       AnalyseCurveOrientation  non exportee
//                                      dupliquee dans CATCltGeometricUtilities.
//   CATPGMAnalyseCurveOrientation  non utilisee
//
// -    CATMakeNurbsCurveClamped        utilisee (dans FreeFormOperators par FrFUtiBipar) (N.B remplace MakeNurbsCurveClamped)
//   CATPGMMakeNurbsCurveClamped        utilisee EN EXTERNE et par FreeFormOperators.tst mais je reviens sur MakeNurbsCurveClamped
//   ---------------------------
//
// -       MakeClampedData          non utilisee sauf FreeFormOperators.tst
//   CATPGMMakeClampedData              utilisee par FreeFormOperators.tst mais je reviens sur MakeClampedData
//
// -       CheckKnotVectorData      non utilisee
//   CATPGMCheckKnotVectorData          utilisee par FreeFormOperators.tst mais je reviens sur CheckKnotVectorData
//                                         
// -       IsIsoPLineInverted           utilisee par FreeFormOperators
//   CATPGMIsIsoPLineInverted       non utilisee
//
// ATTENTION toujours reconstruire ces frameworks:
// mkmk FreeFormOperators GMOperatorsInterfaces FreeFormOperators.tst AdvancedTopologicalOpe GeometricObjects.tst
//
// la generation des interfaces est pour ce source entierement automatique
//
//=============================================================================

#ifndef FrFUtiMonopar_H 
#define FrFUtiMonopar_H 

#include "FrFOpeUtil.h"
#include "CATDataType.h"

class CATCurve;
class CATCrvLimits;
class CATPLine;
class CATMathPoint; 
class CATFrFCompositeCurve;
class CATGeoFactory;
class CATMathDirection;
class CATFrFCCvLimits;
class CATFrFNurbsMultiForm;
class CATSoftwareConfiguration;



// @nodoc @nocgmitf
//-----------------------------------------------------------------------------
// Relative Orientation between 2 curves
//-----------------------------------------------------------------------------
ExportedByFrFOpeUtil
CATLONG32              RelativeCurveOrientation (const CATCurve                 *  iCurve1          ,
                                                 const CATCrvLimits              & iCrvLimits1      ,
                                                 const CATCurve                 *  iCurve2          ,
                                                 const CATCrvLimits              & iCrvLimits2      ,
                                                       CATSoftwareConfiguration *  iConfig          =0);

// @nodoc @nocgmitf
ExportedByFrFOpeUtil
CATLONG32              RelativeCCvOrientation   (const CATFrFCompositeCurve     *  iCCV1            ,
                                                 const CATFrFCCvLimits           & iCCvLimits1      ,
                                                 const CATFrFCompositeCurve     *  iCCV2            ,
                                                 const CATFrFCCvLimits           & iCCvLimits2      ,
                                                       CATSoftwareConfiguration *  iConfig          = 0);

/* methode devenant strictement interne NLD160620
// @nodoc @nocgmitf
CATLONG32              AnalyseCurveOrientation  (      CATGeoFactory            *  iFactory         ,
                                                       CATMathPoint              & PointStart1      ,
                                                       CATMathPoint              & PointEnd1        ,
                                                 const CATMathDirection          & TgMid1           ,
                                                       CATMathPoint              & PointStart2      ,
                                                       CATMathPoint              & PointEnd2        ,
                                                 const CATMathDirection          & TgMid2           ,
                                                       CATSoftwareConfiguration *  iConfig          = 0);
*/
//-----------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------
ExportedByFrFOpeUtil
CATFrFNurbsMultiForm * CATMakeNurbsCurveClamped (      CATGeoFactory            *  iFactory         ,
                                                       CATSoftwareConfiguration *  iConfig          ,
                                                 const CATLONG32                   iOrder           ,
                                                 const CATLONG32                   iKnotSize        ,
                                                       double                   *  iExtendedKnotVector,
                                                 const CATLONG32                   iDim             ,
                                                 const CATLONG32                   iIsRational      ,
                                                 const CATLONG32                   IsPeriodic       ,
                                                 const CATLONG32                   iNumberOfForm    ,
                                                 const CATLONG32                   iNumberOfPole    ,
                                                       double                   *  iPole            ,
                                                       double                   *  iWeight          ,
                                                 const double                      iTolEqualKnots   );

// DEPRECATED, not XScale compliant, will soon disappear, use API with factory and software configuration, above
ExportedByFrFOpeUtil
CATFrFNurbsMultiForm * MakeNurbsCurveClamped    (const CATLONG32                   iOrder           ,
                                                 const CATLONG32                   iKnotSize        ,
                                                       double                   *  iExtendedKnotVector,
                                                 const CATLONG32                   iDim             ,
                                                 const CATLONG32                   iIsRational      ,
                                                 const CATLONG32                   IsPeriodic       ,
                                                 const CATLONG32                   iNumberOfForm    ,
                                                 const CATLONG32                   iNumberOfPole    ,
                                                       double                   *  iPole            ,
                                                       double                   *  iWeight          ,
                                                 const double                      iTolEqualKnots   );

// @nodoc @nocgmitf
ExportedByFrFOpeUtil
CATLONG32              MakeClampedData          (      CATLONG32                   iOrder           ,
                                                       CATLONG32                   iKnotSize        ,
                                                       double                   *  iExtendedKnotVector,
                                                       CATLONG32                   iDim             ,
                                                       CATLONG32                   iIsRational      ,
                                                       CATLONG32                   iIsPeriodic      ,
                                                       CATLONG32                   iNumberOfForm    ,
                                                       CATLONG32                   iNumberOfPole    ,
                                                       double                   *  iPole            ,
                                                       double                   *  iWeight          ,
                                                       double                      iTolEqualKnots   ,
                                                       CATLONG32                 & oNbKnots         ,
                                                       double                   *& oKnots           ,
                                                       CATLONG32                *& oMult            ,
                                                       CATLONG32                 & oNewNumberOfPole ,
                                                       CATMathPoint             *& oTabPol          ,
                                                       double                   *& oTabweight       ,
                                                       double                   *  oParmSplit       ); // N.B double oParmSplit[2]
// @nodoc @nocgmitf
ExportedByFrFOpeUtil
CATLONG32              CheckKnotVectorData      (      CATLONG32                   iOrder           ,
                                                       CATLONG32                   iKnotSize        ,
                                                       double                   *  iExtendedKnotVector,
                                                       CATLONG32                   iNumberOfPole    ,
                                                       double                      iTolEqualKnots   );

// @nodoc @nocgmitf
//-----------------------------------------------------------------------------
// The return is 1 if iCrv is inverted with its support, else return 0
//----------------------------------------------------------------------------
ExportedByFrFOpeUtil
int                    IsIsoPLineInverted       (const CATPLine                 *  iCrv             );
#endif


