#ifndef CATFrFTopologicalSweepR12Adapter_H
#define CATFrFTopologicalSweepR12Adapter_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2003
//=============================================================================
//
// CATFrFTopologicalSweepR12Adapter
// Adapter for R12 enhancements of Topological Sweep not available on previous levels.
//
//                                                 Nicolas LOCHARD
//=============================================================================
// Usage notes:
//
// - CXR11
//=============================================================================
// 16 01 03 NLD Creation
//              SetProfileScalingOption()
// 17 01 03 NLD Ajout Dump()
// 20 01 03 NLD Ajout SetCGMLevelForImplicitSpine()
// 03 02 03 NLD Ajout SetAssemblyForDiagnosis()
// 14 03 03 NLD Ajout SetWrapDetection()
// 24 03 03 NLD Ajout SetAreasToEliminate()
// 26 03 03 NLD Ajout GetTwistedAreas(), SetUntwistMode()
// 01 07 03 NLD Ajout SetApproximationTolerance()
// 28 07 03 NLD Ajout SetTwistDetection()
// 27 10 03 NLD Ajout SetGeneralizedGuideContinuityCondition() pour le Blend
// 10 11 03 NLD Ajout argument iRecoilDistance à SetUntwistMode()
// 24 11 03 NLD Ajout AddSimuNonC2Parameters()
// 20 01 04 NLD Ajout SetCanonicSurfacesDetection()
// 21 01 04 NLD Ajout SetNoCombDeformationOnC0Vertex()
// 06 04 04 NLD Ajout argument iRecoilSubIntervalsNumber à SetUntwistMode()
// 04 05 04 NLD Ajout SetAreaLaw()
// 01 07 04 NLD Ajout SetLayDownRequest()
// 02 07 04 NLD Ajout de GetProfileArea()
// 14 02 05 NLD Ajout SetMinimumMeshTolerance()
// 14 02 05 NLD Phase 1 de la suppression des vieilles methodes R11 R12 R13 via #define
// 11 04 05 NLD SetNoSpineBlend()
// 18 04 05 NLD Argument iOption à SetNoSpineBlend()
// 19 05 05 NLD Ajout de SetBlendBorderMode()
// 23 05 05 NLD Ajout argument iNumGuide à SetBlendBorderMode()
// 20 09 05 NLD Phase 1 de la suppression des vieilles methodes R14 via #define
// 15 12 05 NLD Ajout SetBlendDevelopOption()
// 19 01 06 NLD Mode 4 de SetUntwistMode() pour activation du post controle de twist
// 02 02 06 NLD Ajout SetNonManifoldUnspecProto()
// 12 07 06 NLD Ajout SetFillTwistProto()
// 29 09 06 NLD Phase 1 de la suppression des vieilles methodes R15 via #define
// 26 10 06 NLD Ajout ForceMultipleViewingDirMode()
// 07 11 06 NLD Ajout GetFilledAreas()
// 29 11 06 NLD Ajout de SetAreasToEliminate() avec argument iFillOptions
// 04 12 06 NLD Ajout des arguments iRelimitationMode et iRelimitingGuideNumber à SetBlendDevelopOption()
// 29 01 07 NLD Ajout ForceGenericNamingPourLesNULs()
// 06 03 07 NLD Ajout SetWarningMode()
// 20 11 07 JSX Ajout de l'argument iActiveRelimitation à SetBlendDevelopOption
// 23 07 08 NLD Ajout SetAdvancedClosureModeWithSurfaces()
// 05/02/10 NLD Ajout ComputePointFromSweepingRatio() et ComputeSweepingRatioFromPoint()
// 28/04/10 NLD Ajout SetExtrudeLimit() (methode R21)
//              ****** Continuer avec autres nouvelles methodes de SweepCx2
//              *** Attention il y a quand meme un gros souk avec la derivation
//              *** depuis CATPGMFrFTopologicalSweepR12Adapter, qui n'est pas de mon fait
//              *** Tout cela se mord mechamment la queue
// 28/05/10 NLD Ajout des autres methodes de booleen:
//              SetThinSolidMode(), SetTrim(),
//              SetOperation(), SetProfileClosure()
// 31/05/10 NLD Ajout de GetSmoothSweepingDir()
// 22/06/10 NLD Ajout de toutes les methodes appelées a ce jour par les applications
//              après GetSweep2Operator():
//              UnsetCheckTopoTwist(), SetBooleanRelimitationMode() (pour SetRelimitationMode()),
//              SetRefPlane()
// 06/07/10 NLD Ajout de methodes pour CATSweep/CATSweep2:
//              SetVirtualBoolean(), SetBothResult(), GetBooleanResult(), SetReversePolarity(),
//              SetBooleanTwistReduction(), SetOldShapeRequested(), IsInvariantResult()
//              A faire?
//                SetFreezeMode(), GetBooleanTopReport()
//                (N.B CATICGMTopExtrude fournit GetBooleanJournal())
// 19/11/10 NLD Ajout argument iFillTwistDefaultOption à SetFillTwistProto()
//              (en fait, ajout d'une deuxieme signature)
// 21/12/10 NLD Ajout SetRecoilParameters() et SetPseudoUntwistModeForC0VerticesInError()
// 12/07/11 NLD Ajout SetAngularLawsInDegree()
// 03/08/11 NLD Documentation de SetExtrudeLimit() (par recopie depuis CATICGMTopPrism)
// 15/12/11 NLD Tableau récapitulatif des disponibilités et documentations
// 19/12/11 NLD Ajout SetUpgradedDefaultSettings() (pour R23)
// 03/01/12 NLD Ajout argument iAutomaticRecoil à SetPseudoUntwistModeForC0VerticesInError()
// 05/10/12 NLD Ajout SetFreezeMode() (pour CATFrFAutoLoftCx2)
// 18/04/13 NLD Ajout ForceVariableViewingDirMode()
// 05/05/14 NLD Ajout SetRidgeOption()
// 18/12/15 NLD Smart indent
// 01/06/17 NLD Ajout SetScalingLaw()
// 08/06/17 NLD Ajout SetRoadWidthOption()
// 15/06/17 NLD Ajout SetRadiusLaws()
// 19/09/17 NLD Ajout ExtractBoundary()
// 28/06/18 NLD Remise en conformité des évolutions souterraines passées du journal de la relimitation
//              - Ajout SetRelimJournalMode()
// 06/11/18 NLD Ajout ExtractMidCurve() pour Rail/Road
// 06/03/19 NLD Ajout ExtractParallel() pour Rail/Road
//=============================================================================
//        **************************************************************************************************
//        ***** Attention les methodes R21 ne sont pas encore dans CATFrFTopologicalSweep.h             ****
//        **************************************************************************************************
//
//        **************************************************************************************************
//        ***** En cas d'ajout/suppression modifier en parallele CATPGMFrFTopologicalSweepR12Adapter.h *****
//        **************************************************************************************************
//=============================================================================
// Liste des méthodes (limitée à la sous-liste des méthodes actives compte tenu des #define actifs)
// ------------------
//                    (mises à jour les 09/10/13, 18/04/13, 05/10/12, 12/09/12, le 15/12/11)
//  /----------------------------------------------- Release de disponibilité (INT pour interne)
//  !             /--------------------------------- Nom de la méthode
//  !             !                                 /---------- Présence      dans CATFrFTopologicalSweep.h
//  !             !                                 !     / --- Documentation dans CATFrFTopologicalSweep.h (i.e pas de @nodoc)
//  !             !                                 !     !
// R24    ForceVariableViewingDirMode              Yes   Yes (ajoutee en R24 le 18/04/13) (flag CATIACGMR215CAA)
//
// R23    SetUpgradedDefaultSettings               Yes   Yes
//
// R22    SetAngularLawsInDegree                   Yes   Yes
//
//                                                           (les methodes ci-dessous sont relatives au booléen)
// R21    SetExtrudeLimit                          No    No
// R21    SetThinSolidMode                         No    No
// R21    SetTrim                                  No    No
// R21    SetOperation                             No    No
// R21    SetProfileClosure                        No    No
// R21    SetRefPlane                              No    No
// R21    UnsetCheckTopoTwist                      No    No
// R21    SetBooleanRelimitationMode               No    No (SetRelimitationMode() on CATSweep2 operator)
// R21    SetVirtualBoolean                        No    No
// R21    SetBothResult                            No    No
// R21    SetReversePolarity                       No    No
// R21    SetBooleanTwistReduction                 No    No (SetTwistReduction() on CATSweep2 operator)
// R21    SetOldShapeRequested                     No    No
// R21    GetBooleanResult                         No    No
// R21    IsInvariantResult                        No    No
//
// R21    GetSmoothSweepingDir                     No    No
//
// R18    GetFilledAreas                           No    No
//
// R12Bis SetUntwistMode                           Yes   Yes (mais sans l'argument iRecoilSubIntervalsNumber)
//
// INT    Dump                                     No    No
// INT    SetCGMLevelForImplicitSpine              No    No
// INT    SetAssemblyForDiagnosis                  No    No
// INT    SetGeneralizedGuideContinuityCondition   No    No  (necessaire pour le G2)
// INT    AddSimuNonC2Parameters                   No    No
// INT    SetNoCombDeformationOnC0Vertex           No    No
// INT    SetMinimumMeshTolerance                  No    No
// INT    SetNoSpineBlend                          No    No
// INT    SetBlendBorderMode                       No    No
// INT    SetBlendDevelopOption                    No    No
// INT    SetNonManifoldUnspecProto                No    No
// INT    SetFillTwistProto(1 argument)            No    No
// INT    SetFillTwistProto(2 arguments)           Yes   Yes (ajoutee en R23 le 12/09/12 sous le nom SetFillTwist())
// INT    ForceMultipleViewingDirMode              No    No
// INT    SetAreasToEliminate                      Yes   Yes (mais sans l'argument iFillOptions)
// INT    ForceGenericNamingPourLesNULs            No    No
// INT    SetWarningMode                           No    No  (en @nodoc et non virtuel dans CATCGMOperator.h, pas dans CATTopOperator)
// INT    SetAdvancedClosureModeWithSurfaces       No    No
// INT    ComputePointFromSweepingRatio            No    No
// INT    ComputeSweepingRatioFromPoint            No    No
// INT    SetRecoilParameters                      No    No
// INT    SetPseudoUntwistModeForC0VerticesInError Yes   Yes (ajoutee en R23 le 12/09/12)
// INT    SetFreezeMode                            No    No  (N.B voir passage de CATBoolean a CATBodyFreezeMode)
// INT    SetRidgeOption                           No    No
// INT    SetRoadWidthOption                       No    No
// INT    ExtractBoundary                          No    No
// INT    SetRelimJournalMode                      No    No
// INT    ExtractMidCurve                          No    No
// INT    ExtractParallel                          No    No
//=============================================================================
// Module definition for Windows
#include <FrFTopologicalOpe.h>
// Base classes
class CATCGMOutput ;
class CATGeometry ;
class CATLaw ;
// General data types
#include <CATDataType.h>
#include <ListPOfCATVertex.h>
#include <CATListOfDouble.h>
#include <CATListOfInt.h>
// Mathematics
#include <CATMathPlane.h>

// Advanced topological operators
#include <CATFrFTopologicalSweep.h>
#include <CATPGMFrFTopologicalSweepR12Adapter.h>

class CATICGMFrFTopologicalSweep;
// #define CATFrFTopologicalSweepR11Adaption
// #define CATFrFTopologicalSweepR12Adaption
// #define CATFrFTopologicalSweepR13Adaption
#define CATFrFTopologicalSweepR12BisAdaption
// #define CATFrFTopologicalSweepR14Adaption
// #define CATFrFTopologicalSweepR15Adaption
#define CATFrFTopologicalSweepR18Adaption
#define CATFrFTopologicalSweepR21Adaption
#define CATFrFTopologicalSweepR22Adaption
#define CATFrFTopologicalSweepR23Adaption
#define CATFrFTopologicalSweepR24Adaption

#ifdef CATFrFTopologicalSweepR21Adaption
#include <CATSweepLimitDef.h>       // pour CATLimit
#include <CATBooleanType.h>         // pour CATBoolType
#include <CATTopBooleanType.h>
#include <CATTopLimit.h>
#include <CATTopLimitType.h>
#include <CATTopPropagationType.h>
#include <ListPOfCATDomain.h>
#endif
//=============================================================================
// A propos de CATFrFTopologicalSweepR12Adapter derivant de CATPGMFrFTopologicalSweepR12Adapter:
// on pourrait revenir en arriere, ceci n'ayant pas grand interet dans ce cas précis,
// puisque CATFrFTopologicalSweepR12Adapter est déjà une classe d'interface,
// et ceci empechant la modification d'une signature (par exemple l'ajout d'un argument)
// sans modification simultanée de CATPGMFrFTopologicalSweepR12Adapter
// a condition de deplacer CATFrFTopologicalSweepR12Adapter.h dans GMOperatorsInterfaces/ProtectedInterfaces
// et a condition d'eradiquer toutes les utilisations de CATPGMFrFTopologicalSweepR12Adapter phase1 et phase2
//
// En attendant on modifie manuellement et de manière synchrone et cohérente les deux
//=============================================================================

class ExportedByFrFTopologicalOpe CATFrFTopologicalSweepR12Adapter: public CATPGMFrFTopologicalSweepR12Adapter
{
 public :
   CATFrFTopologicalSweepR12Adapter(CATFrFTopologicalSweep* iSweepOperator) ;
   ~CATFrFTopologicalSweepR12Adapter() ;

//=============================================================================
// R24 only CAA  Methods adaption
//=============================================================================
#ifdef CATFrFTopologicalSweepR24Adaption
/**
 * (temporary and restricted use).
 * Manages motion axis twist with a variable (local) viewing direction.
 * To be used only with following conditions;
 * <ul>
 * <li>Standard moving frame type (CATFrFTopologicalSweepMF_Ortho).
 * <li>Unspec sweep (with profile)
 * <li>Spine with a complex 3D curve
 * </ul>
 */
           void        ForceVariableViewingDirMode();
#endif

//=============================================================================
// R23 only CAA  Methods adaption
//=============================================================================
#ifdef CATFrFTopologicalSweepR23Adaption
/**
 * Upgrade default operator settings.
 * (for historical and compatibility reasons old fashioned default settings are still active without this call).
 * Must be called immediatly after operator creation.
 * Level 1 default setting changes:
 * <ul>
 * <li>Twist detection is activated.
 * <li>Wrap detection is activated.
 * <li>All angles are defined in degree including int Circular Sweep case.
 * <li>In case of profile or guide support, internal laydown will be done.
 * </ul>
 */
          void         SetUpgradedDefaultSettings(     int                     iSettingsLevel                   = 1);
#endif

//=============================================================================
// R22 only CAA  Methods adaption
//=============================================================================
#ifdef CATFrFTopologicalSweepR22Adaption
   // Angular laws definition
   // Angles must be given in degree, including in circular sweep case)
          void         SetAngularLawsInDegree   (      CATLaw               ** iLaws                            ,
                                                       int                     iNbLaws                          );
#endif

//=============================================================================
// R21 only CAA  Methods adaption
// (**** Not necessarily already published in CATFrFTopologicalSweep.h *****)
//=============================================================================
#ifdef CATFrFTopologicalSweepR21Adaption
 /**
 * Defines the type of limitation of each extremity along the extrusion (center curve) direction.
 * <br>To be called for each extremity, if you do not want to keep
 * the default options of the global creation function.
 * @param iId
 * The first or last extremity.
 * @param iType
 * The type of limit on the extremity.
 * @param iIsAxisReverted
 * The orientation.
 * <br><b>Legal values</b>: <tt>TRUE</tt> for the same orientation as the direction defined at the operator
 * creation, <tt>FALSE</tt> for an opposite orientation. In general, use <tt>TRUE</tt> for the start limit,
 * and <tt>FALSE</tt> for the end limit.
 * @param iOffset
 * The value of the offset if <tt>iType</tt> has the value <tt>CatLimOffsetFromProfile</tt>.
 * @param iLimit
 * The pointer to the geometry or the topology that stops the extrusion.
 * @param iPropagationBody
 * The pointer to the body which contains <tt>iLimit</tt>, thus allowing the
 * propagation of the trimming specification. To use if <tt>iType = CatLimUntil</tt> and
 * <tt>iPropagationFlag = CatPropagClosing</tt>  or if <tt>iType = CatLimNextAlongAxis</tt>
 * or <tt>iType = CatLimLastAlongAxis</tt>
 * @param iPropagationFlag
 * The management of the propagation.
 * @param iThickness
 * defines the value of any thickness which must be applied to the considering relimitation
 */
          void         SetExtrudeLimit          (      CATTopLimit             iId                              ,
                                                       CATTopLimitType         iType                            ,
                                                       CATBoolean              iIsAxisReverted                  ,
                                                       CATLength               iOffset                          ,
                                                       CATGeometry           * iLimit                           ,
                                                       CATBody               * iPropagationBody                 ,
                                                       CATTopPropagationType   iPropagType                      ,
                                                       CATLength               iThickness                       );

  // Thin solid mode definition
          void         SetThinSolidMode         (const CATBoolean              iThinSolidMode                   ,
                                                 const CATBoolean              iIsNeutralFiber                  ,
                                                 const double                  iThinSolidThickness[2]           ,
                                                       CATLISTP(CATDomain)   * iWireListWithReverseThinSolidSide);

  // Trimming body definition
          void         SetTrim                  (      CATBody               * iTrimBody                        );

  // Boolean operation definition
          void         SetOperation             (      CATTopBooleanType       iBooleanType                     );

  // Extrapolation and profile trim on trimming body (defined by SetTrim())
          void         SetProfileClosure        ();

  // Reference plane definition (for extrusion/relimitation)
          void         SetRefPlane              (      CATMathPlane          & iRefPlane                        );

  // Unset topological twist check
          void         UnsetCheckTopoTwist      (      CATBoolean              iUnsetCheckTopoTwist             = CATBoolean(1));

  // Boolean relimitation mode (SetRelimitationMode() on CATSweep2 operator)
          void        SetBooleanRelimitationMode(      short                   iMode                            ,
                                                       short                   iAutomaticDirectionInversion     = 1);

          void         SetVirtualBoolean        ();

          void         SetBothResult            ();

          void         SetReversePolarity       (      CATBoolean              iPolarity                        );

          void         SetBooleanTwistReduction (      CATBoolean              iTwistReduction                  );

          void         SetOldShapeRequested     ()                                                               ;

          CATBody    * GetBooleanResult         ()                                                               ;

  // IsInvariantResult() on CATSweep2 operator
          CATBoolean   IsInvariantResult        ()                                                               ;

  // Direction de balayage, a comportement quasi continu, permettant le franchissement des sommets C0
          void         GetSmoothSweepingDir     (      double                  iLambda                          ,
                                                       CATMathPoint          & oOrigin                          ,
                                                       CATMathDirection      & oDir                             );

#endif

//=============================================================================
// R18 only CAA  Methods adaption
//=============================================================================
#ifdef CATFrFTopologicalSweepR18Adaption
 //-------------------------------------------------------------------------
 // Recuperation des zones remplies et des indicateurs de remplissage
 // (0 pour zones avec echec de remplissage)
 //-------------------------------------------------------------------------
          void         GetFilledAreas           (      CATListOfDouble       & oFillBegin                       ,
                                                       CATListOfDouble       & oFillEnd                         ,
                                                       CATListOfInt          & oFillOk                          );
#endif

//=============================================================================
// R15 only CAA  Methods adaption
//=============================================================================
#ifdef CATFrFTopologicalSweepR15Adaption
//-------------------------------------------------------------------------
// Sets the area law for multiprofile sweep.
//-------------------------------------------------------------------------
          void         SetAreaLaw               (      CATCompositeLaw       * iAreaLaw                         ) ;

//-------------------------------------------------------------------------
// Sets lay down request for guides and profiles with support shell.
// tolerance is optional
//-------------------------------------------------------------------------
 // cette macro permet à l'application d'écrire son code
 // avant la remontée de celui-ci, via un #ifdef
 // NLD010704 pour SLA
 // A supprimer en temps utile
 // phase 1a : codage de l'appli avec #ifdef
 // phase 1b : codage du #define ici
 // phase 2  : suppression du #ifdef dans l'appli
 // phase 3  : suppression du #define ici 
 // #define CATFrFTopologicalSweepR12AdapterInternalLayDown
          void         SetLayDownRequest        (      double                * iLayDownTolerance               = NULL) ;

//-------------------------------------------------------------------------
// Gets the initial area for the profile evaluated in a given parameter,
// and the final area after application of the area law (if any)
//-------------------------------------------------------------------------
          void         GetProfileArea           (      double                  iParam                          ,
                                                       double                & oInitialArea                    ,
                                                       double                & oFinalArea                      ) ;
#endif

//=============================================================================
// R14 only CAA  Methods adaption
//=============================================================================
#ifdef CATFrFTopologicalSweepR14Adaption
//-------------------------------------------------------------------------
// Sets the canonic surfaces detection mode (cones/cylinders/planes).
//-------------------------------------------------------------------------
          void         SetCanonicSurfacesDetection(    CATBoolean              iCanonicSurfacesDetection       = CATBoolean(1)) ;
#endif

//=============================================================================
// R13 only CAA  Methods adaption
//=============================================================================
#ifdef CATFrFTopologicalSweepR13Adaption
//-------------------------------------------------------------------------
// Definition d'une tolerance d'approximation
//-------------------------------------------------------------------------
          void         SetApproximationTolerance  (    double                  iApproximationTolerance         ) ;
//-------------------------------------------------------------------------
// Activation/Desactivation de la detection de twist
//-------------------------------------------------------------------------
          void         SetTwistDetection          (    int                     iTwistDetection                 );
#endif

//=============================================================================
// R12 only CAA  Methods adaption
//=============================================================================
#ifdef CATFrFTopologicalSweepR12Adaption
//-------------------------------------------------------------------------
// Definition des vertex limites de zones à eliminer
//-------------------------------------------------------------------------
// DEPRECATED
          void         SetAreasToEliminate        (    CATLISTP(CATVertex)   & iStartVertices                  ,
                                                       CATLISTP(CATVertex)   & iEndVertices                    ) ;
//-------------------------------------------------------------------------
// Recuperation des zones de twist
//-------------------------------------------------------------------------
          void         GetTwistedAreas            (    CATListOfDouble       & oTwistBegin                     ,
                                                       CATListOfDouble       & oTwistEnd                       ) ;

//-------------------------------------------------------------------------
// Activation/Desactivation de la detection de rebroussement
//-------------------------------------------------------------------------
          void         SetWrapDetection           (    int                     iWrapDetection                  );
#endif

//=============================================================================
// others R12 only CAA  Methods adaption
//=============================================================================
#ifdef CATFrFTopologicalSweepR12BisAdaption
//-------------------------------------------------------------------------
// Activation/Desactivation du detwistage
// Mode 1: Calcul des zones de twist
// Mode 2: Calcul et retrait des zones de twist
// Mode 3: Calcul et conservation des zones de twist seulement
// Mode 4: calcul et retrait des zones twistees avec controle de non twist du residu (19/06/05)
//-------------------------------------------------------------------------
          void         SetUntwistMode           (      int                     iUntwistMode                     ,
                                                       double                  iRecoilDistance                  = 0.0,
                                                       int                     iRecoilSubIntervalsNumber        = 0);
#endif

//=============================================================================
// R11 only CAA Methods adaption
//=============================================================================
#ifdef CATFrFTopologicalSweepR11Adaption
/**
 * Defines the scaling mode to apply to the profile.
 * @param iScalingOption
 * The scaling option
 * <br><b>Legal values:</b>
 * <dl><dt>0</dt><dd> Inactive scaling
 * <dt>1</dt><dd> Active scaling (default mode).
 * </dl>
 */
          void         SetProfileScalingOption  (      CATLONG32               iOption                          );
#endif

//=============================================================================
// Internal methods adaption
//=============================================================================
 //-------------------------------------------------------------------------
 // Operator dump
 //-------------------------------------------------------------------------
          void         Dump                     (      CATCGMOutput          & os                               );

 //-------------------------------------------------------------------------
 // Definition du niveau de modeleur CGM pour le calcul de spine implicite
 //-------------------------------------------------------------------------
          void         SetCGMLevelForImplicitSpine(    int                     iCGMLevelForImplicitSpine        );

 //-------------------------------------------------------------------------
 // Activation/Desactivation du mode assemblage pour l'aide au diagnostic
 //-------------------------------------------------------------------------
          void         SetAssemblyForDiagnosis  (      int                     iActiveAssembly                  = 1);

 //-------------------------------------------------------------------------
 // Imposition de condition de continuite generalisee sur les guides
 // (cas loft et cas sweep conique)
 // Ceci est mis en public pour le blend qui utilise un angle de 180
 // pour jouer sur les orientations
 //-------------------------------------------------------------------------
          void         SetGeneralizedGuideContinuityCondition(
                                                       int                     iGuideNumber                     ,
                                                       CATGeometry           * iReferenceElement                ,
                                                       CATLaw                * iAngleLaw                        ,
                                                       CATFrFTopologicalSweepContinuity_Type
                                                                               iContinuityCondition             );
 //-------------------------------------------------------------------------
 // Simulation de découpe non C2: parametres imposés par l'appelant
 //-------------------------------------------------------------------------
          void         AddSimuNonC2Parameters   (      int                     iNbValues                        ,
                                                       double                * iValues                          );

 //-------------------------------------------------------------------------
 // Desactivation de la deformation des peignes aux vertex C0
 // (seulement pour les sweeps segment)(usage privé, réduit à SweepExtrapol)
 //-------------------------------------------------------------------------
          void         SetNoCombDeformationOnC0Vertex() ;

 //-------------------------------------------------------------------------
 // Definition d'une tolerance de maillage minimum (methode utilisee en test seulement)
 //-------------------------------------------------------------------------
          void         SetMinimumMeshTolerance  (      double                  iMinimumMeshTolerance            ) ;

 //-------------------------------------------------------------------------
 // Cas d'un blend sans spine avec couplage en abscisse curviligne
 //-------------------------------------------------------------------------
          void         SetNoSpineBlend          (      int                     iOption                          = 1);

 //-------------------------------------------------------------------------
 // Definition du mode de calcul des directions en extremite pour le blend
 // 0 : perpendiculaire (à la guide)
 // 1 : tangent (mode par défaut)
 //-------------------------------------------------------------------------
          void         SetBlendBorderMode       (      int                     iNumGuide                        ,
                                                       int                     iStartMode                       ,
                                                       int                     iEndMode                         );

 //-------------------------------------------------------------------------
 // Definition de l'option develop (blend)
 // nouveau mode:
 // iDevelopOption = 0 : inactive
 //                = 1 : Develop
 //                = 2 : NoTwist
 // iActiveRelimitation = 0 : pas de relim
 //                     = 1 : relimitation active
 // ancien mode:
 // iDevelopOption = 0 : inactive
 //                = 1 : active
 //                = 2 : active avec relimitation
//
 // iDevelopClearance  : valeur du parametre Clearance
 // si option develop active avec relimitation:
 // iRelimitationMode[2] & iRelimitingGuideNumber[2]:
 //  On each extremity(0/1):
 //    iRelimitationMode[i]=0 : until extremity vertices on all guides
 //                          =1 : Until extremity vertex of guide number iRelimitingGuideNumber[i]
 //                          =2 : Best solution (Automatic selection of the limiting guide)
 //    iRelimitingGuideNumber[i] : guide number whose extremity vertex will relimit coupling
          void         SetBlendDevelopOption    (      int                     iDevelopOption                   ,
                                                       double                  iDevelopClearance                ,
                                                       int                     iActiveRelimitation              = 0,
                                                       int                   * iRelimitationMode                = 0,
                                                       int                   * iRelimitingGuideNumber           = 0);

 //-------------------------------------------------------------------------
 // Proto Sweep unspec non manifold
 //-------------------------------------------------------------------------
          void         SetNonManifoldUnspecProto(      int                     iOption                          = 1);

 //-------------------------------------------------------------------------
 // Activation/Desactivation du mode remplissage des zones twistees
 // iFillTwistMode
 // 0 : inactif
 // 1 : actif avec tangence
 // 2 : actif sans tangence (a discuter)
 // 3 : actif avec tangence selon guide obligatoire et autres finesses speciales extrapolation de skin
 //      (USAGE STRICTEMENT RESERVE)
 //      N.B liste des modes à enrichir mais sans changement car stream sous CGMReplay
 // iFillTwistDefaultOption: option de remplissage par défaut
 // (memes valeurs possibles que pour l'argument iFillOptions de SetAreasToEliminate)
 //-------------------------------------------------------------------------
          void         SetFillTwistProto        (      int                     iFillTwistMode                   = 1);

 // pour des raisons d'heritage depuis CATPGMFrFTopologicalSweepR12Adapter
 // je dois ajouter une seconde signature au lieu d'ajouter un argument a la premiere
          void         SetFillTwistProto        (      int                     iFillTwistMode                   ,
                                                       int                     iFillTwistDefaultOption          );

 //-------------------------------------------------------------------------
 // Force le mode viewing dir multiple
 //-------------------------------------------------------------------------
          void         ForceMultipleViewingDirMode()                                                             ;

 //-------------------------------------------------------------------------
 // Definition des vertex limites de zones à eliminer
 // en l'absence de liste iFillOptions on remplit chaque zone eliminée si
 // le remplissage a été demandé par SetFillTwistProto()
 // sinon pour chaque zone l'indicateur doit valoir 1 si la zone doit etre remplie
 //-------------------------------------------------------------------------
          void         SetAreasToEliminate      (      CATLISTP(CATVertex)   & iStartVertices                   ,
                                                       CATLISTP(CATVertex)   & iEndVertices                     ,
                                                       CATListOfInt          & iFillOptions                     );

 //-------------------------------------------------------------------------
 // Force suivi reduit du clean/posage pour perfos GenericNaming
 //-------------------------------------------------------------------------
          void         ForceGenericNamingPourLesNULs(  int                     iForceGenericNamingPourLesNULs   = 1);

 //-------------------------------------------------------------------------
 // Force le mode warning
 //-------------------------------------------------------------------------
          void         SetWarningMode           (      CATCGMWarning           iMode                            );

 //-------------------------------------------------------------------------
 // Closure mode with profiles underlying surfaces if any (restricted use)
 //-------------------------------------------------------------------------
          void         SetAdvancedClosureModeWithSurfaces()                                                      ;

 //-------------------------------------------------------------------------
 // Compute point on master guide from sweeping ratio
 // CATMathPoint is the origin of the moving frame computed on the master guide
 // returns 0 if OK
 //-------------------------------------------------------------------------
          int          ComputePointFromSweepingRatio
                                                (      double                  iRatio                           ,
                                                       CATMathPoint          & oPoint                           );

 //-------------------------------------------------------------------------
 // Compute sweeping ratio from point on master guide
 // point can be either on the master guide (edition initialization)
 //                     or in the 3D (manipulation)
 // returns 0 if OK
 //-------------------------------------------------------------------------
          int          ComputeSweepingRatioFromPoint
                                                (const CATMathPoint          & iPoint                           ,
                                                       double                & oRatio                           );

 //-------------------------------------------------------------------------
 // Recoil parameters definition around twisted areas of pseudo-twisted areas
 //-------------------------------------------------------------------------
          void         SetRecoilParameters      (      double                  iRecoilDistance                  ,
                                                       int                     iRecoilSubIntervalsNumber        );

 //-------------------------------------------------------------------------
 // Activate pseudo untwist mode for C0 vertices in error
 //-------------------------------------------------------------------------
         void         SetPseudoUntwistModeForC0VerticesInError
                                               (       int                     iAutomaticRecoil                 = 0);

 //-------------------------------------------------------------------------
 // Define final body freeze mode
 //-------------------------------------------------------------------------
 // Special call for setting freeze mode on CATSweep2 operator
 // CAUTION: inconsistent behaviour for GetFreezeMode(); NLD250918
          void         SetFreezeMode           (       CATBoolean              iFreezeMode                      );

 //-------------------------------------------------------------------------
 // Ridge mode for segment profile sweep
 //-------------------------------------------------------------------------
          void         SetRidgeOption          ();

 //-------------------------------------------------------------------------
 // Scaling law for unspec sweep                                      010617
 //-------------------------------------------------------------------------
          void         SetScalingLaw           (       CATLaw                * iLaw                             );

 //-------------------------------------------------------------------------
 // Radius laws (as a matter of fact, for a second radius law definition)  150617
 //-------------------------------------------------------------------------
          void         SetRadiusLaws           (       CATLaw               ** iLaws                            ,
                                                       int                     iNbLaws                          );

 //-------------------------------------------------------------------------
 // RoadWidth mode for segment profile sweep
 //-------------------------------------------------------------------------
          void         SetRoadWidthOption      ();

 //-------------------------------------------------------------------------
 // Prototype d'extraction de frontiere sur un sweep segment (cote 1 ou 2)
 // (+ generalisation a d'autres types de sweep)
 //-------------------------------------------------------------------------
          CATBody*     ExtractBoundary         (      int                      iSide                            );

 //-------------------------------------------------------------------------
 // Prototype d'extraction de middle curve sur un sweep road crown (à deux segments)
 //-------------------------------------------------------------------------
          CATBody*     ExtractMidCurve         ();

 //-------------------------------------------------------------------------
 // Prototype d'extraction de parallèle, generalisé (usage reservé à CivilEngineering)
 //-------------------------------------------------------------------------
 // Extraction de parallèle depuis un vertex du profil
 // le vertex est imposé soit par ses deux edges adjacentes
 // soit directement
 //-------------------------------------------------------------------------
          CATBody*     ExtractParallel         (      CATCell                * iImposedProfileCell1             ,
                                                      CATCell                * iImposedProfileCell2             ,
                                                      CATCGMJournalList      * OutputReport                     ) ;

 //-------------------------------------------------------------------------
 // Mode de relimitation du journal
 // (voir CATSweep.h sans documentation aucune de la méthode)
 // en revanche on trouve dans CATTopExtrude la documentation de SetJournalMode():
 // @nodoc
 // Sets journal behaviour. If set to 1, the profile face will be added as a parent of faces involved in 
 // contextual limits. Also, CATCGMJournalInfoItem data will be added for faces for the start and end limits.
 // @param iJournalMode
 // New value of the journal mode
 //-------------------------------------------------------------------------
          void         SetRelimJournalMode     (      short                    iRelimJournalMode                );


 private:

 CATFrFTopologicalSweep* _TopologicalSweepOperator ;

} ;
// Access to Sweep R12 Adapter. This object belongs to CATFrFTopologicalSweep operator and must
// neither be deleted by caller, nor used after CATFrFTopologicalSweep operator deletion
ExportedByFrFTopologicalOpe
CATFrFTopologicalSweepR12Adapter* GetTopologicalSweepR12Adapter   (CATFrFTopologicalSweep    * iSweepOperator) ;

// Access to Sweep R12 Adapter. This object belongs to CATFrFTopologicalSweep operator and must
// neither be deleted by caller, nor used after CATFrFTopologicalSweep operator deletion
ExportedByFrFTopologicalOpe
CATFrFTopologicalSweepR12Adapter* CATGetTopologicalSweepR12Adapter(CATICGMFrFTopologicalSweep* iISweepOperator) ;

#endif
