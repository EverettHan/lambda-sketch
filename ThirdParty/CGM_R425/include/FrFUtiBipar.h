
// #define FrFUtiBiparForceCompilationAllMethods "Test only NLD160115"
// #define FrFUtiBipar_H                         " TEST ONLY le mettre ici permet de detecter les services requis par les appelants"

// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// FrFUtiBipar :
// Declaration of utilities on Bipars used in the FreeFormOperators FW
//
// Situation XScale: "c'est complique". NLD050215.
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
//    09/97 TPG Creation                                       Tuan Phung (tpg)
// 18/04/12 NLD ExtraireIsoPeigne() recoit la configuration
//              Détabulation
// 19/04/12 NLD EstimerPeigne() et EstimerCombMF() recoivent la configuration
// 24/04/12 NLD ComputeCoonsBipar() recoit la configuration 
// 16/01/15 NLD Smart indent
//              Les methodes inutilisees, en shunt pour Coverage sont desormais shuntees par #ifdef
//              Ajout preventif configuration aux methodes en shunt:
//              - MFLoopC11Compatibility()
//              - CoonsFilling()
//              - ApplyEnergyOnMultiForm()
//              - ApplyEnergyOnBipar()
//              Recensement des utilisations internes/externes des methodes et de leurs interfaces CATPGM*
// 19/01/15 NLD XScale: Ajout CATMakeNurbsSurfaceClamped(), XScale compliant
//              N.B interfacage de CATMakeNurbsSurfaceClamped() en CATPGMMakeNurbsSurfaceClamped() le 20/01/15
// 09/02/15 NLD Suppression des interfacages non desires pour ces utilitaires non strategiques
//              - Ajout de @nodoc @nocgmitf pour toutes methodes sauf
//              CATMakeNurbsSurfaceClamped() et MakeNurbsSurfaceClamped()
//              Renommage de MutiplyMultiFormByPolynom() en MultiplyMultiFormByPolynom (avec un l!)
// 12/11/21 NLD Ajout argument iFactory à ComputeCoonsBipar() (pour debug/visu)
//=============================================================================

//=============================================================================
// Revue des interfaces, et compatibilite XScale. NLD190115
// ---------------------------------------------
//    - Ajouter Configuration a
//      (Dans ces methodes la factory n'est pas necessaire car on peut acceder a la tolerance sous les MultiForms)
//       - CATCheckContinuityCrvs
//       - MultiplyMultiFormByPolynom
//       - DeriveMultiForm
//    - Ajouter Factory et Config a
//      (OK) - MakeNurbsSurfaceClamped    ATTENTION: utilisee en externe
//             donc je duplique la signature
//    - Laisser en etat malgre l'absence de factory
//      (Dans ces methodes la factory n'est pas necessaire car on peut acceder a la tolerance sous les MultiForms)
//           - ComputeCoonsBipar
//    - Laisser en etat car presence de factory et configuration, toutes les autres methodes
//
// en cas de modification les impacts sont:
// FreeFormOperators\FreeFormOpeItf.m\LocalInterfaces\CATIPGMFreeFormOpeItfBldr2Impl.h (private).
// FreeFormOperators\FreeFormOpeItf.m\src\CATIPGMFreeFormOpeItfBldr2Impl.cpp (private).
// GMOperatorsInterfaces\CATGMOperatorsInterfaces.m\src\CATPGMFrFUtiBipar.cpp (private).
// GMOperatorsInterfaces\ProtectedInterfaces\CATIPGMFreeFormOpeItfBldr2.h (private).
// GMOperatorsInterfaces\ProtectedInterfaces\CATPGMFrFUtiBipar.h (private).
// GMOperatorsInterfaces/CATGMOperatorsInterfaces.m/src/CATPGMFrFUtiBipar.cpp 
//
// Attention j'ai deja un dephasage entre CATPGMEstimerPeigne et EstimerPeigne (cas des courbes): la configuration n'existe pas dans CATPGMEstimerPeigne
// je la retablis 
//
// Statut des methodes:
// -------------------
// -       EstimerCombMF               utilisee (dans AdvancedTopologicalOpe),
//   CATPGMEstimerCombMF           non utilisee SUPPRIMEE
//
// -       EstimerPeigne               utilisee (dans AdvancedTopologicalOpe, FreeFormOperators),
//   CATPGMEstimerPeigne           non utilisee SUPPRIMEE
//
// -       ExtrapolCombMF              utilisee (dans AdvancedTopologicalOpe, FreeFormOperators),
//   CATPGMExtrapolCombMF          non utilisee SUPPRIMEE
//
// -       ExtrapolPeigne              utilisee (dans AdvancedTopologicalOpe, FreeFormOperators),
//   CATPGMExtrapolPeigne          non utilisee SUPPRIMEE
//
// -       ExtraireCombMF              utilisee (dans AdvancedTopologicalOpe, FreeFormOperators),
//   CATPGMExtraireCombMF          non utilisee SUPPRIMEE
//
// -       ExtrairePeigne              utilisee (dans AdvancedTopologicalOpe, FreeFormOperators),
//   CATPGMExtrairePeigne          non utilisee SUPPRIMEE
//
// -       ExtraireIsoPeigne           utilisee (dans                         FreeFormOperators)
//   CATPGMExtraireIsoPeigne       non utilisee SUPPRIMEE
//
// -       MFLoopC11Compatibility      shuntee
//
// -       ComputeCoonsBipar           utilisee (dans                         FreeFormOperators)
//   CATPGMComputeCoonsBipar       non utilisee SUPPRIMEE
//
// -       CoonsFilling                shuntee  SUPPRIMEE
//
// -       CATCheckContinuityCrvs      utilise dans FreeFormOperators FreeFormOperators.tst
//                                    (au lieu de CATPGMCheckContinuityCrvs anciennement) et GeometricObjects.tst
//      CATPGMCheckContinuityCrvs  non utilisee SUPPRIMEE (je la remplace dans FreeFormOperators.tst)
//
// -       MultiplyMultiFormByPolynom   utilisee dans FreeFormOperators par CATExtractTool (qui est utilise, et meme par un code de debug du Sweep)
//         (N.B on remplace l'ancien nom de merde MutiplyMultiFormByPolynom (sans l) le 09/02/15)
//
//   CATPGMMultiplyMultiFormByPolynom non utilisee SUPPRIMEE (anciennement CATPGMMutiplyMultiFormByPolynom sans l)
//
// -       DeriveMultiForm             utilisee dans FreeFormOperators
//   CATPGMDeriveMultiForm         non utilisee SUPPRIMEE
//
// -       ApplyEnergyOnMultiForm      shuntee  
//
// -       ApplyEnergyOnBipar          shuntee
//
// -       MakeNurbsSurfaceClamped     utilisee EN EXTERNE (en fait non, reference dans historique seulement)
//                                     et tirant sur MakeNurbsCurveClamped. pas du tout XScale
//         -----------------------
//   CATPGMMakeNurbsSurfaceClamped     utilisee EN EXTERNE AUSSI (par  CATXGMOperators et SPAXCGMGeometryKernelUtils qui ne sont pas XScale a ce jour)
//   -----------------------------
//
// ATTENTION toujours reconstruire ces frameworks:
// mkmk FreeFormOperators GMOperatorsInterfaces FreeFormOperators.tst AdvancedTopologicalOpe GeometricObjects.tst
//
// la generation des interfaces est pour ce source entierement automatique
//=============================================================================

#ifndef FrFUtiBipar_H
#define FrFUtiBipar_H

// #define FrFUtiBiparForceCompilationAllMethods "Test only NLD160115"

#ifndef FrFUtiBiparForceCompilationAllMethods
 #define FrFUtiBiparShuntCoverage
#endif

#include "FrFObjects.h"
#include "CATDataType.h"

class CATCurve;
class CATPCurve;
class CATPLine;
class CATCrvLimits;
class CATMathVector;
class CATMathNurbsMultiForm;
class CATFrFNurbsMultiForm;
class CATMathNurbsBipar;
class CATFrFNurbsBipar;
class CATFrFCombMF;
class CATNurbsSurface;
class CATKnotVector;
class CATGeoFactory;
class CATFrFCompositeCurve;
class CATMathPolynomX;
class CATSoftwareConfiguration;

//-----------------------------------------------------------------------------
// Comb extraction 
//-----------------------------------------------------------------------------

// @nodoc @nocgmitf
// Case of 3D curve : control points moving
ExportedByFrFObjects
CATFrFCombMF         * EstimerCombMF            (const CATGeoFactory            *  iFactory         ,
                                                       CATSoftwareConfiguration *  iConfig          ,
                                                 const CATCurve                 *  iCurve           ,
                                                 const CATCrvLimits              & iCurveLimits     ,
                                                 const CATLONG32                   iCurveOrientation,
                                                       CATMathVector            *  iVec             ,
                                                       CATMathVector            *  iNormal          = 0);

// @nodoc @nocgmitf
ExportedByFrFObjects
CATFrFNurbsMultiForm * EstimerPeigne            (const CATGeoFactory            *  iFactory         ,
                                                       CATSoftwareConfiguration *  iConfig          ,
                                                 const CATCurve                 *  iCurve           ,
                                                 const CATCrvLimits              & iCurveLimits     ,
                                                 const CATLONG32                   iCurveOrientation,
                                                       CATMathVector            *  iVec             ,
                                                       CATMathVector            *  iNormal          = 0);

// @nodoc @nocgmitf
// N.B Ici on lit la configuration dans la CCV
ExportedByFrFObjects
CATFrFCombMF         * EstimerCombMF            (const CATGeoFactory            *  iFactory         ,
                                                 const CATFrFCompositeCurve     *  iCcv             ,
                                                 const CATLONG32                   iCcvOrientation  ,
                                                       CATMathVector            *  iVec             ,
                                                       CATMathVector            *  iNormal          = 0);

// @nodoc @nocgmitf
// N.B Ici on lit la configuration dans la CCV
ExportedByFrFObjects
CATFrFNurbsMultiForm * EstimerPeigne            (const CATGeoFactory            *  iFactory         ,
                                                 const CATFrFCompositeCurve     *  iCcv             ,
                                                 const CATLONG32                   iCcvOrientation  ,
                                                       CATMathVector            *  iVec             ,
                                                       CATMathVector            *  iNormal          = 0);

// @nodoc @nocgmitf
// Case of PCurve : extrapolation
ExportedByFrFObjects
CATFrFCombMF         * ExtrapolCombMF            (const CATGeoFactory            *  iFactory         ,
                                                        CATSoftwareConfiguration *  iConfig          ,
                                                  const CATPCurve                *  iPCurve          ,
                                                  const CATCrvLimits              & iPCurveLimits    ,
                                                  const CATLONG32                   iPCurveOrientation,
                                                  const CATLONG32                   iTransition      ,
                                                  const CATLONG32                   iExtractOrder    ,
                                                        CATMathVector            *  iVec             = 0);

// @nodoc @nocgmitf
ExportedByFrFObjects
CATFrFNurbsMultiForm * ExtrapolPeigne            (const CATGeoFactory            *  iFactory         ,
                                                        CATSoftwareConfiguration *  iConfig          ,
                                                  const CATPCurve                *  iPCurve          ,
                                                  const CATCrvLimits              & iPCurveLimits    ,
                                                  const CATLONG32                   iPCurveOrientation,
                                                  const CATLONG32                   iTransition      ,
                                                  const CATLONG32                   iExtractOrder    ,
                                                        CATMathVector            *  iVec             = 0);

// @nodoc @nocgmitf
// Case of isoparametric PLine : analytic extraction
ExportedByFrFObjects
CATFrFCombMF         * ExtraireCombMF            (const CATGeoFactory            *  iFactory         ,
                                                        CATSoftwareConfiguration *  iConfig          ,
                                                  const CATPLine                 *  iPline           ,
                                                  const CATCrvLimits              & iPlineLimits     ,
                                                  const CATLONG32                   iPlineOrientation,
                                                  const CATLONG32                   iTransition      );

// @nodoc @nocgmitf
ExportedByFrFObjects
CATFrFNurbsMultiForm * ExtrairePeigne            (const CATGeoFactory            *  iFactory         ,
                                                        CATSoftwareConfiguration *  iConfig          ,
                                                  const CATPLine                 *  iPline           ,
                                                  const CATCrvLimits              & iPlineLimits     ,
                                                  const CATLONG32                   iPlineOrientation,
                                                  const CATLONG32                   iTransition      ,
                                                  const CATLONG32                   iExtractOrder    );

// @nodoc @nocgmitf
ExportedByFrFObjects
CATFrFNurbsMultiForm * ExtrairePeigne            (const CATGeoFactory            *  iFactory         ,
                                                        CATSoftwareConfiguration *  iConfig          ,
                                                  const CATPLine                 *  iPline           ,
                                                  const CATCrvLimits              & iPlineLimits     ,
                                                  const CATLONG32                   iPlineOrientation,
                                                  const CATLONG32                   iTransition      ,
                                                  const CATLONG32                   iExtractOrder    ,
                                                        CATKnotVector            *& oKnotVector      );

// @nodoc @nocgmitf
ExportedByFrFObjects
CATPLine             * ExtraireIsoPeigne         (      CATGeoFactory            *  iFactory         ,
                                                        CATSoftwareConfiguration *  iConfig          ,
                                                  const CATPLine                 *  iPline           ,
                                                  const CATCrvLimits              & iPlineLimits     ,
                                                  const CATLONG32                   iPlineOrientation,
                                                  const CATLONG32                   iTransition      ,
                                                  const CATLONG32                   iExtractOrder    );

//-----------------------------------------------------------------------------
// C11 compatibility between N CATFrFNurbsMultiForms at their common corner
// The CATFrFNurbsMultiForms form a closed loop and have the same orientation
// 
//  iDegreeModification = 0 : initial degree unchanged
//                        1 : degree may be changed 
//-----------------------------------------------------------------------------
#ifndef FrFUtiBiparShuntCoverage
// @nodoc @nocgmitf
// N.B Ici, factory non necessaire car on lit le bloc de tolerances dans la MultiForm
ExportedByFrFObjects
CATFrFNurbsMultiForm ** MFLoopC11Compatibility
                                                 (      CATSoftwareConfiguration *  iConfig          ,
                                                        CATLONG32                   iNbOfMFs         ,
                                                        CATFrFNurbsMultiForm     *  iListOfInitialMFs,
                                                        CATLONG32                   iDegreeModification);
#endif

// @nodoc @nocgmitf
//-----------------------------------------------------------------------------
//  Compute the Coons bipar
//
//                   (0,3)       3       (3,3)
//                     +---------<---------+
//                     !                   !
//                     !                   !
//                     !    A V            !
//                   4 V    !              A 2
//                     !    !              !
//                     !    +-----> U      !
//                     !                   !
//                     +--------->---------+
//                   (0,0)       1       (3,0)
// 
//-----------------------------------------------------------------------------
// N.B Ici, factory non necessaire car on lit le bloc de tolerances dans une MultiForm
ExportedByFrFObjects
CATFrFNurbsBipar     * ComputeCoonsBipar            (   CATGeoFactory            *  iFactory         , // NLD121121
                                                        CATSoftwareConfiguration *  iConfig          ,
                                                        CATFrFNurbsMultiForm     *  ioMultiForm1     ,
                                                        CATFrFNurbsMultiForm     *  ioMultiForm2     ,
                                                        CATFrFNurbsMultiForm     *  ioMultiForm3     ,
                                                        CATFrFNurbsMultiForm     *  ioMultiForm4     );

#ifndef FrFUtiBiparShuntCoverage // NDNCoverage041005
// @nodoc @nocgmitf
//-----------------------------------------------------------------------------
// Coons Surface - The Degre of the NurbsMultiForms must be 3 and 3
//                 They must describe a closed area . 
//-----------------------------------------------------------------------------
ExportedByFrFObjects
CATNurbsSurface      * CoonsFilling                (    CATGeoFactory            *  iFactory         ,
                                                        CATSoftwareConfiguration *  iConfig          ,
                                                        CATFrFNurbsMultiForm     *  ibound1          ,
                                                        CATFrFNurbsMultiForm     *  ibound2         );
#endif

// @nodoc @nocgmitf
//-----------------------------------------------------------------------------
// Check Continuity entre des multiformes                    03/98   Ritha Loja
// iEpsilon     : tolerance de deformation de points de controle
// iCont        : continuite max recherchee (1 ou 2)
// oDiag[iNbcrv]: tableau de continuites inferieures a iCont
//                Attention : ce tableau doit etre alloue par l'appelant
//-----------------------------------------------------------------------------
// N.B Ici, factory non necessaire car on lit le bloc de tolerances dans une MultiForm
ExportedByFrFObjects
void                   CATCheckContinuityCrvs   (      CATLONG32                 & iNbcrv             ,
                                                       CATFrFNurbsMultiForm    **  iCrv               ,
                                                       CATLONG32                 & iCont              ,
                                                       double                    & iEpsilon           ,
                                                       CATLONG32                *& oDiag              );

// @nodoc @nocgmitf
//-----------------------------------------------------------------------------
// Multiply a NurbsMultiForm with a Polynom. Both should have the same parametric space.
// The new MultiForm will have its degree increased regard to iMult, by the degree of iPol.
// Limitation : doesn't work on rational, and on 2D MultiForm with more than one form.
// These are not strong limitations. For more details NDN.
//-----------------------------------------------------------------------------
// N.B Ici, factory non necessaire car on lit le bloc de tolerances dans la MultiForm
ExportedByFrFObjects
CATFrFNurbsMultiForm * MultiplyMultiFormByPolynom(const CATFrFNurbsMultiForm     *  iMult               ,
                                                  const CATMathPolynomX          *  iPol                ) ;

// @nodoc @nocgmitf
//-----------------------------------------------------------------------------
// Derive a NurbsMultiForm.
// The new MultiForm will have its degree decreased.
// Limitation : doesn't work on rational, and on 2D MultiForm with more than one form.
// This are not strong limitation. For more details NDN.
//-----------------------------------------------------------------------------
// N.B Ici, factory non necessaire car on lit le bloc de tolerances dans la MultiForm
ExportedByFrFObjects
CATFrFNurbsMultiForm * DeriveMultiForm          (const CATFrFNurbsMultiForm     *  iMult               );

#ifndef FrFUtiBiparShuntCoverage

//-----------------------------------------------------------------------------
// @nodoc @nocgmitf
ExportedByFrFObjects
void                   ApplyEnergyOnMultiForm   (      CATSoftwareConfiguration *  iConfig              ,
                                                       CATMathNurbsMultiForm    *  iMult                ,
                                                       CATLONG32                   iKindOfEnergy        ,
                                                       CATLONG32                   iConStart            ,
                                                       CATLONG32                   iConEnd              ,
                                                       CATLONG32                *  iStartEndForm        );

//-----------------------------------------------------------------------------
// @nodoc @nocgmitf
// N.B Ici, factory non necessaire car on lit le bloc de tolerances dans la Bipar
ExportedByFrFObjects
void                   ApplyEnergyOnBipar       (      CATSoftwareConfiguration *  iConfig              ,
                                                       CATMathNurbsBipar        *  iBipar               ,
                                                       CATLONG32                   iKindOfEnergy        ,
                                                       CATLONG32                   iCon             [4]);
#endif

//-----------------------------------------------------------------------------
ExportedByFrFObjects
CATFrFNurbsBipar  * CATMakeNurbsSurfaceClamped  (      CATGeoFactory            *  iFactory             ,
                                                       CATSoftwareConfiguration *  iConfig              ,
                                                 const CATLONG32                   iOrderU              ,
                                                 const CATLONG32                   iKnotSizeU           ,
                                                       double                   *  iExtendedKnotVectorU ,
                                                 const CATLONG32                   iOrderV              ,
                                                 const CATLONG32                   iKnotSizeV           ,
                                                       double                   *  iExtendedKnotVectorV ,
                                                 const CATLONG32                   iIsRational          ,
                                                 const CATLONG32                   iIsPeriodic          ,
                                                       CATLONG32                   iNumberOfPoleU       ,
                                                       CATLONG32                   iNumberOfPoleV       ,
                                                       double                   *  iPole                ,
                                                       double                   *  iWeight              ,
                                                 const double                      iTolEqualKnots       );
//-----------------------------------------------------------------------------
// DEPRECATED, not XScale compliant, will soon disappear, use API with factory and software configuration, above
ExportedByFrFObjects
CATFrFNurbsBipar     * MakeNurbsSurfaceClamped  (const CATLONG32                   iOrderU              ,
                                                 const CATLONG32                   iKnotSizeU           ,
                                                       double                   *  iExtendedKnotVectorU ,
                                                 const CATLONG32                   iOrderV              ,
                                                 const CATLONG32                   iKnotSizeV           ,
                                                       double                   *  iExtendedKnotVectorV ,
                                                 const CATLONG32                   iIsRational          ,
                                                 const CATLONG32                   iIsPeriodic          ,
                                                       CATLONG32                   iNumberOfPoleU       ,
                                                       CATLONG32                   iNumberOfPoleV       ,
                                                       double                   *  iPole                ,
                                                       double                   *  iWeight              ,
                                                 const double                      iTolEqualKnots       );
#endif




