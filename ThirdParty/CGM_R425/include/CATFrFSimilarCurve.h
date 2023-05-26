// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
//
// CATFrFSimilarCurve : Creation d'une (liste de) courbe(s) similaire a une autre
//
// Equipement CGMReplay: OK NLD221116
// (mais pas pour les cas complexes d'utilisation dans le loft avec SetMFForSimilar())
//
//=============================================================================
//
// Les Points et Tangentes aux extremites de la BaseCurve doivent etre donnes 
// implicitement dans la BaseCurve, par le constructeur
//  - StartPoint et EndPoint sur la BaseCurve = les points extremes de la BaseCurve
//    dans ses limites.
//  - StartTgt   et EndTgt   sur la BaseCurve = les tangentes extremes de la BaseCurve
//    dans ses limites.
//
// Pour les donnees de la SimilarCurve, les valeurs par defaut sont les suivantes :
//  - StartPoint et EndPoint sur la SimilarCurve sont les
//    StartPoint et EndPoint sur la BaseCurve
//  - StartTgt   et EndTgt   de  la SimilarCurve sont des vecteurs colineaires aux 
//    StartTgt   et EndTgt   de  la BaseCurve
//
//  Remarque : Dans le cas ou toutes les valeurs sont par defaut, l'operateur ne
//             fait rien.
//    
// Le mode 2D est un mode ou toutes les courbes sont des PCurves sur le meme fond.
// (il y a controle et sortie en erreur)                              NLD221116
//
//=============================================================================
//   /01/02 CCK Creation
//   /02/04 MNA Modifications : 
//                  -Nouveau constructeur, je fournis directement 
//                   la multiforme et non pas une liste de curves.
//                  -Je cree la methode SetMFForSimilar()qui permet de fournir
//                   la multiforme de l'exterieur
//                  GetMFForSimilar() : Permet de recuperer directement la Multiforne
//                   dans le cas ou celle-ci est utilisable directement.
//                  -_LevelToExecute : Ajout comme donnee membre de la classe
//                  -_CubicCTRLSetOfPoint : Ajout des points de Controle de la cubique 
//                   en donnee membre
//    02/05 CCK Je fais un similar2D pour DSP
//    05/05 CCK SetAlwaysReNormExtTgt
// 08/01/07 NLD Ajout _GetSimilarCurveDone
// 15/02/07 NLD Init() est renommee InitRun() et _GetSimilarCurveDone est initialisee
//              dans les constructeurs et non dans InitRun()
//              On factorise les initialisations des deux constructeurs dans
//              une nouvelle methode Init()
// 22/05/07 NLD Passage de la multiforme par adresse dans ComputeMatrixOfChangeKnotVector()
// 04/10/07 NLD Ajout de SetCuspControl() et _CuspControl
// 23/03/10 JSX EVOLUTION G2 G3 & ARCHI
//              Ajout de GetSoftwareConfiguration SetCvtsOnSimilarCurve et SetTorsOnSimilarCurve
//              Suppression des matrices inutiles
//              Factorisation et Unification des modes Mono et multi run 
// 08/04/10 JSX Ajout SetCurvilineareTarget (renommee SetCurvilinearTarget() le 300513 NLD)
// 20/08/10 JSX Introduction d'un mode d'imposition par une surface (pour la courbure uniquement)
//              Dans ce mode, on impose pas une courbure 3D mais une courbure suivant la normale
//              de la surface
//              Ajout des arguments start/End Mode et S/E ScalarCurvature a  SetCvtsOnSimilarCurve
//              Dans ce mode, le vecteur courbure pouvant etre nul on decompose en (Dir + Scalar)  
// 03/01/11 JSX _ForceNormalReparametrisationForC1 (optionnel quand la multiforme est donnée par l'appelant)
// 04/04/11 FDS Correction UAPV
// 14/06/13 NLD Renommage de _ComputeDeformation en _DeformComputation pour eviter proximite lexicale avec _ComputedDeformation
//              Remise en forme pour lisibilite et facilite de report dans la classe interface associee
//              Pour plus de clarte, ComputeDeformationOnPol() qui detruit les polynomes recoit leurs pointeurs par adresse
// 17/06/13 NLD Ajout _TolObject pour perfos
// 18/06/13 NLD Renommages hygieniques ou de mise a niveau avec l'implementation actuelle:
//              (en particulier suppression de la notation "Cubic")
//              - _Newnum_points       devient _NewNbPoints
//              - _CubicCTRLSetOfPoint devient _DeformControlPointsSet
//              - _CtlPtCubic          devient _DeformControlPoints
//              - ComputeSpineDegree() devient ComputeDeformSplineDegree()
// 21/06/13 NLD CreateMultiformFromSetOfCurve() devient CreateMultiFormFromSetOfCurve()
//              N.B toutes modifications 06/13 reportees dans CATIPGMFrFSimilarCurve
// 25/06/13 NLD Ajout _StartCvtMode et _EndCvtMode
// 03/07/13 NLD Suppression definitive de _InputCvtMode que remplacent _StartCvtMode et _EndCvtMode
// 09/07/13 NLD Ajout RunDebug()
// 11/05/16 NLD Ajout des deux CATCreateFrFSimilarCurve()
//              Correction des documentations de SetCvtsOnSimilarCurve() et SetTorsOnSimilarCurve()
//              en ce qui concerne l'imposition depuis les base curves
// 17/11/16 NLD Ajout ExpressTgtForm2DSingle() pour factorisation des passages de tangente du 3D au 2D
// 22/11/16 NLD Instrumentation (partielle) CGMReplay
//              Reordonnancement des donnees (donnees d'entree en premier)
// 23/11/16 NLD Distinction des donnees utilisateur et des donnees de travail sur la SimilarCurve:
//              (ajout de _StartPtUS, _EndPtUS, _StartTgtUS, _EndTgtUS)
//              Ajout ComputeSupportSurface()
//              Ajout _XScaleLoadScalingFactor, _XScaleLoadRecordedScale, _LoadedFromReplay
//              Ajout GetCATFrFSimilarCurveDefaultOperatorId()
// 25/11/16 NLD Ajout _StartCvtUS, _EndCvtUS
//              Ajout _StartScalarCvtOnSimilarCurveUS et _EndScalarCvtOnSimilarCurveUS
//              Ajout _InputCvtFixed
//              Ajout VisuSpecs()
// 28/11/16 NLD Ajout _ListGeometriesToDelete
// 29/11/16 NLD Ajout _StartTorUS, _EndTorUS 
// 27/04/17 NLD Ajout _ListOrnSC (anciennement on rendait toujours _ListOrnBC)
// 02/05/17 NLD Deflaggage (actif) de l'implementation CGMReplay
// 04/05/17 NLD Ajout _IsUnderCGMReplayODT
// 05/05/17 NLD Isolation: les constructeurs ne sont plus accessibles que par une classe de creation interne CATFrFSimilarCurveCreator
//              (le passage par CATCreateFrFSimilarCurve)( est obligatoire)
//              phase 1/2: par option de précompilation
// 23/01/18 NLD phase 2/2: deflaggage du masquage des constructeurs
//=============================================================================
// ATTENTION: je crois que CATIPGMFrFSimilarCurve a ete supprime de la liste de headers regeneres
//            y reporter donc manuellement les modifications
//            NLD110516
//            reports dans CATIPGMFrFSimilarCurve.h OK des modifs du 14/06/13 au 11/05/16 17h
//            reports du 11/05/16 au 04/05/17: non necessaires (rien de public)
//=============================================================================
#ifndef CATFrFSimilarCurve_H
#define CATFrFSimilarCurve_H

#include "FrFOpeCrv.h"

#include "CATGeoOperator.h"
#include "CATCGMOperator.h"
#include "CATCGMOperatorDebug.h"

#include "CATTolerance.h"

#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATMathLimits.h"
#include "CATMathInterval.h"

#include "CATListOfCATGeometries.h"
#include "CATListOfCATCurves.h"
#include "CATListOfCATPCurves.h"
#include "CATListOfInt.h"
#include "CATListOfCATCrvLimits.h"
#include "CATSurParam.h"

#include "CATGeoOpTimer.h"
#include "CATCGMOperator.h"
#include "CATCGMOperatorDebug.h"
class CATFrFSimilarCurveBrother;
class CATGeometryPack;

class CATMathMxNMatrix;       //#include "CATMathMxNMatrix.h"
class CATMathNxNBandSymMatrix;//#include "CATMathNxNBandSymMatrix.h"


class CATGeoFactory;
class CATSoftwareConfiguration;
class CATFrFNurbsMultiForm;
class CATKnotVector;
class CATMathSetOfPoints;
class CATSurface;
class CATMathPolynomX;
class CATFrFSimilarCurve;
class CATFrFSimilarCurveBrother;
class CATFrFSimilarCurveCreator;
//-----------------------------------------------------------------------------
//  VOIR INTERFACAGE EVENTUEL. En tous les cas pas de correspondance avec les actuels CATPGMCreateFrFSimilarCurve
//  (argument iSoftwareConfiguration mis ici a la place qui convient, et de caractere obligatoire)
//  NLD110516
//  OK mise a jour des CATPGMCreateSimilarCurve faite
//  NLD231116

    // iSimilar2D=1 dans le cas ou les BasesCurves sont des PCurves
ExportedByFrFOpeCrv
           CATFrFSimilarCurve*        CATCreateFrFSimilarCurve(CATGeoFactory           * iFactory                      ,
                                                               CATSoftwareConfiguration* iSoftwareConfiguration        ,
                                                               CATLISTP(CATCurve)      & iListOfBaseCurves             ,
                                                               CATLISTP(CATCrvLimits)  & iListLimitsOfBaseCurves       ,
                                                               CATListOfInt            & iListOrnOfBaseCurves          ,
                                                               int                       iSimilar2D                    = 0);


    // Nouveau constructeur avec des MF deja orientees dans le bon sens.
    // Attention : mettre toutes les courbes dans une seule MF
ExportedByFrFOpeCrv
           CATFrFSimilarCurve*        CATCreateFrFSimilarCurve(CATGeoFactory           * iFactory                      ,
                                                               CATSoftwareConfiguration* iSoftwareConfiguration        ,
                                                               CATFrFNurbsMultiForm    * iNurbsForSimilar              );

//-----------------------------------------------------------------------------
class ExportedByFrFOpeCrv CATFrFSimilarCurve : public CATGeoOperator
{
  CATCGMVirtualDeclareClass(CATFrFSimilarCurve);
 friend class CATFrFSimilarCurveCreator;
protected:

    // iSimilar2D=1 dans le cas ou les BasesCurves sont des PCurves
                                      CATFrFSimilarCurve      (CATGeoFactory           * iFactory                      ,
                                                               CATLISTP(CATCurve)      & iListOfBaseCurves             ,
                                                               CATLISTP(CATCrvLimits)  & iListLimitsOfBaseCurves       ,
                                                               CATListOfInt            & iListOrnOfBaseCurves          ,
                                                               CATSoftwareConfiguration* iSoftwareConfiguration        = NULL,
                                                               int                       iSimilar2D                    = 0);


    // Nouveau constructeur avec des MF deja orientees dans le bon sens.
    // Attention : mettre toutes les courbes dans une seule MF
                                      CATFrFSimilarCurve      (CATGeoFactory           * iFactory                      ,
                                                               CATFrFNurbsMultiForm    * iNurbsForSimilar              ,
                                                               CATSoftwareConfiguration* iSoftwareConfiguration        = NULL );

public:

    virtual                          ~CATFrFSimilarCurve      ();

    // Pour CATCGMOperator
            CATSoftwareConfiguration* GetSoftwareConfiguration() const;

    // Imposition de points
    // --------------------
    // Ce set est a faire si on veut imposer les points extremites de la SimilarCurve.
    // Sinon, on prend les valeurs par defaut, i.e: les points extremites la BaseCurve.
    // Mettre un seul des deux pointeurs revient a demander la valeur par defaut pour l'autre.
    // Les points sont toujours imposés ou conservés
            void                      SetPointsOnSimilarCurve (const CATMathPoint      * iStartPointOnSimilarCurve     , 
                                                               const CATMathPoint      * iEndPointOnSimilarCurve       );

    // Pour le cas 2D :
            void                      SetPointsOnSimilarCurve (const CATSurParam       * iStartPointOnSimilarCurve     , 
                                                               const CATSurParam       * iEndPointOnSimilarCurve       );

    // Imposition/liberation de tangentes
    // ----------------------------------
    // Ce set est a faire si on veut que la SimilarCurve parte tangentiellement a des courbes.
    // Sinon, par defaut, les tangentes sur la SimilarCurve seront prises colineaires a celles sur la BaseCurve.
    // Mettre un seul des deux pointeurs revient a demander la valeur par defaut pour l'autre (colineaire a la base)
    // Les tangentes sont toujours imposées ou conservées
    // NEW! Pour imposer une tangente en laissant libre l'autre il faut utiliser le mode "NullAreFree"
    //   SetTgtsOnSimilarCurve(NULL, NULL)    Impose les tangentes de la base curve ==> (ne change pas le comportement de l'operateur)
    //   SetTgtsOnSimilarCurve(NULL, NULL, 2) Libere la tangente de la base curve 2 ==> (   change     le comportement de l'operateur)
    //                                       (1 pour la base curve 1, 3 pour les 2 courbes)
    // ATTENTION:
    // dans le cas 2D:
    // - les tangentes doivent etre fournies en 3D, leur traduction en 2D etant a la charge de cet operateur
    // - cependant la gestion des tangentes etait archi-buggee. Activation des corrections en V5R27SP2. NLD221116
           void                       SetTgtsOnSimilarCurve   (const CATMathVector     * iStartTgtOnSimilarCurve       ,
                                                               const CATMathVector     * iEndTgtOnSimilarCurve         ,
                                                                     CATLONG32           NullAreFree                   = 0);

    // Imposition/liberation de courbures
    // ----------------------------------
    // Attention : Par defaut les courbures ne sont pas prises en compte dans la deformation (continuite ignorée dans les premieres versions)
    //             Elles sont libres (comportement inverse des tangences)
    //   SetCvtsOnSimilarCurve(NULL, NULL, 0) impose les courbures de la base curve ==> (   change     le comportement de l'operateur)
    //  (SetCvtsOnSimilarCurve(NULL, NULL) ne les impose pas contrairement a ce qui etait indique avant NLD110516)
    //   SetCvtsOnSimilarCurve(NULL, NULL, 3) libere les courbures                  ==> (ne change pas le comportement de l'operateur)
    // iStartCvtOnSimilarCurve      ,
    //  (iEndCvtOnSimilarCurve)     : Vecteur courbure
    // iStartCvtCrvSurMode          ,
    //  (iEndCvtCrvSurMode          : Mode d'imposition:
    //                                    0 (crv/crv)
    //                                ou  1 (crv/sur)
    //                                ou 10 (??? usage externe interdit, usage interne reserve au Loft)
    //                                      (continuite G2 de la courbe avec une surface sans modifier la courbure dans la direction imposée)
    // iStartScalarCvtOnSimilarCurve,
    //  (iEndScalarCvtOnSimilarCurve: en mode (Crv/Sur), scalaire representant la courbure (peut etre nul),
    //                                la normale est donnée par iStartCvtOnSimilarCurve/iEndCvtOnSimilarCurve
    // iStartFixedG2Dir             ,
    //  (iEndFixedG2Dir             : en mode (Crv/Sur) direction dans laquelle la courbure ne doit pas bouger (par ex plan osculateur de la courbe),
    //                                Permet a une courbe plane de respecter le G2 avec une surface en restant plane.
    //
    // DO NOT USE IN 2D MODE (NLD181116)
    // ---------------------
           void                       SetCvtsOnSimilarCurve   (const CATMathVector     * iStartCvtOnSimilarCurve       , 
                                                               const CATMathVector     * iEndCvtOnSimilarCurve         ,
                                                                     CATLONG32           NullAreFree                   = 3,
                                                                     int                 iStartCvtCrvSurMode           = 0,
                                                                     int                 iEndCvtCrvSurMode             = 0,
                                                                     double              iStartScalarCvtOnSimilarCurve = 0.0,
                                                                     double              iEndScalarCvtOnSimilarCurve   = 0.0,
                                                               const CATMathVector     * iStartFixedG2Dir              = NULL,
                                                               const CATMathVector     * iEndFixedG2Dir                = NULL);

    // Imposition/liberation de torsions
    // ---------------------------------
    // (meme comportement que pour les courbures)
    //   SetTorsOnSimilarCurve(NULL, NULL, 0) impose les torsions de la base curve  ==> (   change     le comportement de l'operateur)
    //  (SetTorsOnSimilarCurve(NULL, NULL) ne les impose pas contrairement a ce qui etait indique avant NLD110516)
    //   SetTorsOnSimilarCurve(NULL, NULL, 3) libere les torsions                   ==> (ne change pas le comportement de l'operateur)
    //
    // DO NOT USE IN 2D MODE (NLD181116)
    // ---------------------
           void                       SetTorsOnSimilarCurve   (const CATMathVector     * iStartCvtOnSimilarCurve       , 
                                                               const CATMathVector     * iEndCvtOnSimilarCurve         ,
                                                                     CATLONG32           NullAreFree                   = 3);

    // iAlwaysReNormTgt = 0 -> est le mode par defaut impose par Toyota.
    //                         A la demande Toyota, donc pour le ConnectCurve en mode Base Curve, on ne renorme
    //                         pas systematiquement les tangentes aux extremites
    // iAlwaysReNormTgt = 1 -> est preferable pour eviter des oscillations

    // Tout ceci n'est pas tres clair (JSX180510)
    // - Lorsque l'utilisateur "impose" une derivée (c'est une direction) sa norme
    //   est modifiée afin de correspondre à la norme de la BaseCurve.
    // - Ensuite le ratio de la distance(PointDeb, Pointfin) mesurée sur la Base Curve et le resultat
    //   est appliqué pour tenir compte du "scaling" de la courbe
    // - Si iAlwaysReNormTgt= 0, le ratio des distances n'est pas appliqué si une tangente n'est pas imposée
    //   (i.e si on deforme un seul coté l'autre cote ne bouge pas en point et derivée premiere)

           void                       SetAlwaysReNormExtTgt   (      int                 iAlwaysReNormTgt              = 1);


    // Imput target derivative are given with curvilinear parametrization
    // ||targtn|| is suppose to be 1 !
    // But data are rescaled to fit BaseCurveParametrization
    // This enable small correction of Direction/Curvature without
    // changing BC parametrization
           void                       SetCurvilinearTarget    (      int                 iCurvilinear                  = 1); 

    // Active le controle de non rebroussement de la similar par rapport a la base curve
           void                       SetCuspControl          (      int                 iActiveCuspControl            = 1);

    // Pour tester je veux pouvoir passer une MultiForm. MNA

           void                       SetMFForSimilar         (const CATFrFNurbsMultiForm* iNurbsForSimilar            ,
                                                                     int                   iNbCurves                   );

           void           SetMatrixChangeKnotVectorComputation(      CATBoolean            iMatrixComputation          = 1);

           void           SetComputeDeformation               (      CATBoolean            iDeformComputation          = 1);

           CATLONG32      SetNormalReparametrisationForC1Mode (      CATLONG32             iForceNormalReparametrisationForC1);

    // Run
    // CODE RETOUR : VOIR INIT()
           CATCGMOperatorDebugDeclareRun(CATFrFSimilarCurve, CATGeoOperator);
    //     int                        Run                     ();


           void                       GetSimilarCurve         (      CATLISTP(CATCurve)     & oListOfSimilarCurves      ,
                                                                     CATLISTP(CATCrvLimits) & oListOfSimilarCurvesLimits,
                                                                     CATListOfInt           & oListOfSimilarCurvesOrns  );

    // Return deformation on last run with deformation
           double                     GetDeformation          ();

    //                                                                // MNA pour tester
           CATFrFNurbsMultiForm     * GetMFForSimilar         ();

  protected:
    // Eventuellement on rendra RunOperator() accessible pour acces rapide depuis CATSectionDeformation::RunSimilar()
    // qui n'a que faire de l'instrumentation CGMReplay. NLD221116
           int                        RunOperator             ();

           void                       Init                    (      CATSoftwareConfiguration* iSoftwareConfiguration) ;

           int                        InitRun                 ();


                                                                      // Dans l'init premiere partie qui consiste a creer la multiforme
                                                                      // de travail a partir des courbes donnees, on ne l'appelle pas si on
                                                                      // a passe la multiforme de l'exterieur.
           int                        CreateMultiFormFromSetOfCurve();

           double                     ComputeMaxGapBetweenCurves();

  private:

    // Methodes privees
    //                                                                                        NLD220507 passage par adresse
           int                        ComputeMatrixOfChangeKnotVector
                                                              (      CATFrFNurbsMultiForm& iDeformMF,
                                                                     CATKnotVector    * ioKV                          );
    
                                                                      // Lorsque j'ai stocke les differentes matrices qui me serviront a resoudre
                                                                      // le systeme, je le resoud intrinsequement au niveau du similar Curve
    
           void                       SolveSystemChangeKnotVector
                                                              (      CATMathPoint     * iDeformControlPoints          ,
                                                                     CATKnotVector    * ioKV                          ,
                                                                     CATMathPoint     * iDeformControlPointsInKV      );

                                                                      // Dans le cas 2D, les tangentes sont donnees sous leur forme 3D. on les re-exprime dans
                                                                      // l'espace parametrique de la surface
                                                                      // Remarque : modification de _StartTgtBC, avec mise a 0 de sa troisieme coordonnee
           void                       ExpressTgtForm2D();

           // N.B ici le passage par valeur de iTgt3D est légitime et volontaire
           //     il permet d'appeler la méthode avec la même variable pour iTgt3D et oTgt2D
           //     Erreur UPVA à ne pas corriger donc
           //     NLD240920
           void                       ExpressTgtForm2DSingle  (      int                 iMode                        ,
                                                               const CATSurParam       & iParam                       ,
                                                                     CATMathVector       iTgt3D                       ,
                                                                     CATMathVector     & oTgt2D
                                                              );




           void                       MultiToCurve            (   CATFrFNurbsMultiForm & SimilarMF                     );

           void                       ComputeDeformationWithDelta (   double             DeltaInit[4][3]               ,
                                                                      double             DeltaEnd [4][3]               ,
                                                                      double             DeltaParam                    );

           void                       ComputeDeformationWithMultiForm
                                                              (  CATFrFNurbsMultiForm  * CorrectionCurve               );

           void                       ComputeDeformationOnPol (const CATMathInterval   & D                             ,
                                                                     CATMathPolynomX  *& p2x                           ,
                                                                     CATMathPolynomX  *& p2y                           ,
                                                                     CATMathPolynomX  *& pzx                           );

           CATLONG32                  LoopControl             (      double              DeltaInit[4][3]               ,
                                                                     double              DeltaEnd [4][3]               ,
                                                                     double            * DeltaCoeffXYZ                 );

           CATLONG32                  ModifyBaseCurve         (      CATLONG32           NbControlPoints               ,
                                                                     CATMathPoint      * BaseControlPoints             ,
                                                                     CATMathPoint      * DeformControlPoints           ,
                                                                     CATMathPoint      * SimilarControlPoints          );

           CATLONG32                  ComputeDeformSplineDegree();

           int                        ComputeSupportSurface   ();

    // Methodes de Debug
        // void                       DebugTgtMultiForm       ();
           void                       RunDebug                ();

           void                       VisuSpecs               ();

public:
     const CATString                * GetOperatorId();

  //-----------------------------------------------------------------------
  //- Gestion timer 
  //-----------------------------------------------------------------------  
  /** @nodoc @nocgmitf */
           CATGeoOpTimer            * GetTimer();

  //-----------------------------------------------------------------------
  //- Gestion Mode Record 
  //-----------------------------------------------------------------------  
  /** @nodoc @nocgmitf */
           CATExtCGMReplay          * IsRecordable  (short        & LevelOfRuntime ,
                                                     short        & VersionOfStream);
  /** @nodoc @nocgmitf */
   virtual void                       WriteInput    (CATCGMStream & os);
  /** @nodoc @nocgmitf */
   virtual void                       WriteOutput   (CATCGMStream & os);
  /** @nodoc @nocgmitf */
   virtual CATBoolean                 ValidateOutput(CATCGMStream & ioStream, CATCGMOutput & os, int VersionNumber=1);
  /** @nodoc @nocgmitf */
   virtual void                       Dump          (CATCGMOutput & os ) ;
  /** @nodoc @nocgmitf */
   virtual void                       DumpOutput    (CATCGMOutput & os);
  /** @nodoc @nocgmitf */
   virtual void                       DumpOutput    (CATCGMStream & ioStream, CATCGMOutput& os, int VersionNumber=1);
  /** @nodoc @nocgmitf */
   virtual CATCGMOperator::CATCheckDiagnostic
                                      CheckOutput   (CATCGMOutput & os);

 private:
          void                        FillOutputPack(CATGeometryPack *   Pack        ,
                                                     CATLONG32        & oNbGeometries);


//===============================================================================
// TYPES
//===============================================================================
    // Ajouts de types pour les impositions aux extremites. NLD251116
    // EN COURS: pas d'utilisation au 090517
    // Imposition de courbure
    // ne depend pas de l'extremite CATLONG32                 _FreeIfNullCvt;          // Idem for Cvt
    // ne depend pas de l'extremite CATLONG32                 _InputCvtSC  ;           // pareil que pour _InputPtSC pour la courbure
    // Donnees pour une extremite
    struct CvtImp
      {
       CATMathVector          _BC             ; // pour _StartCvtBC et _EndCvtBC
       //                                       // donnees correspondantes sur la SC, qui ne sont pas des entrees
       CATMathVector          _SC             ; // pour _StartCvtSC et _EndCvtSC
       CATMathVector          _US             ; // pour _StartCvtUS et _EndCvtUS
       double                 _ScalarCvtOnSCUS; // pour _StartScalarCvtOnSimilarCurveUS et _EndScalarCvtOnSimilarCurveUS;

       // Plan Tangent en cas de courbure Courbe/Surface
       CATMathVector          _TangentPlaneSC ; // pour _StartTangentPlaneSC et _EndTangentPlaneSC  ;
       // Direction selon laquelle la courbure ne doit pas changer (cas Courbe/Surface)
       CATMathVector          _SCDir          ; // pour _StartCvtSCDir et _EndCvtSCDir  ;
      };
    struct ExtImp
      {
       CvtImp                 _Cvt;
      };

//===============================================================================
// DATA
//===============================================================================
    CATSoftwareConfiguration* _SoftwareConfiguration;
    int                       _CGMLevel;
    const CATTolerance&       _TolObject;

    // Donnees d'entree de l'operateur
    // -------------------------------  
    // Donnees pour le 2D
    CATSurface              * _SurfSupport;

    // InOut sour forme de Crv ou de multiform
    int                       _MultiFormGivenByUser;   // = 1 MultiForm USER
    CATFrFNurbsMultiForm    * _MultiFormBC;            // La multiforme a deformer (en input ou indirectement par concatenation des courbes) 

    // Define Pour Sniff et NLD
    #define CATFrFSimilarCurve_ListPOfCATCurve     CATLISTP(CATCurve)
    #define CATFrFSimilarCurve_ListPOfCATCrvLimits CATLISTP(CATCrvLimits)

    // Donnees pour la BaseCurve quand on travail avec des courbes
    CATLONG32                 _NbCurves;

    CATFrFSimilarCurve_ListPOfCATCurve 
                              _ListBC;
    CATFrFSimilarCurve_ListPOfCATCrvLimits
                              _ListLimitsBC;
    CATListOfInt              _ListOrnBC;

    // pour memoire je fais toujours suivre ici les variables qui correspondent pour les SimilarCurves,
    // mais qui ne sont PAS des entrees
    CATFrFSimilarCurve_ListPOfCATCurve 
                              _ListSC;
    CATFrFSimilarCurve_ListPOfCATCrvLimits
                              _ListLimitsSC;
    CATListOfInt              _ListOrnSC;

    // Modes
    int                       _Similar2D;              // =0 dans le cas standard 3D. =1 dans le cas particulier 2D
    int                       _AlwaysReNormTgt;        // 
    int                       _CurvilinearTargetData;  // 1 => _xxxxyyySC are in curvilinear parametrization 
                                                       // ||_StartTgtBC|| == ||_EndTgtBC|| ==1 
                                                       // ||_StartCvtBC|| == ||_EndCvtBC|| == Curvature (et perpendicular to tangent) 
    int                       _ForceNormalReparametrisationForC1; // force la reparametrisation meme si la multiforme a ete donnée en entrée
    int                       _CuspControl;            // verif "à la NLD" que le resultat va dans le meme sens que la ref
    CATBoolean                _DeformComputation;      // Active le calcul de Deformation

    // Valeurs de Reference(BaseCurve: BC)  et Target(SimilarCurve: SC)
 // ExtImp                    _StartImp;
 // ExtImp                    _EndImp;

    // 1) Point
    CATLONG32                 _InputPtSC   ;           // 0 si aucun input sur les points,
                                                       // 1 si seulement StartPoint
                                                       // 2 si seulement EndPoint
                                                       // 3 si StartPoint et EndPoint en input
    CATMathPoint              _StartPtBC   ,
                              _EndPtBC     ;
    //                                                 // donnees correspondantes sur la SC, qui ne sont pas des entrees
    //                                                 // du moins cela depend; je vais distinguer (NLD221116)
    //                                                 // les donnees utilisateur _StartPtUS,     _EndPtUS (US: user)
    //                                                 // des donnees de travail  _StartPtSC,     _EndPtSC
    CATMathPoint              _StartPtUS   ,
                              _EndPtUS     ;
    CATMathPoint              _StartPtSC   ,
                              _EndPtSC     ;
    // SurParam pour le cas 2D
    //                                                 // Ici c'est bien bizarre: il y a historiquement stockage des
    //                                                 // parametres imposes a la similar curve dans des variables BC et non SC
    //                                                 // perso je mettrais plutot SC ou mieux US. NLD090517
    CATSurParam               _StartParamBC,
                              _EndParamBC  ;
//  CATSurParam               _StartParamSC,
//                            _EndParamSC  ;

    // 2) Tangence
    CATLONG32                 _InputTgtSC;             // pareil que pour _InputPtSC
    CATLONG32                 _FreeIfNullTgt;          // 0:(defaut) conserve la valeur de la base courbe 1: First Tgt is Free 2: second is free: 3: All are free
    CATMathVector             _StartTgtBC  ,
                              _EndTgtBC    ;
    //                                                 // donnees correspondantes sur la SC, qui ne sont pas des entrees
    //                                                 // du moins cela depend; je vais distinguer (NLD221116)
    //                                                 // les donnees utilisateur _StartTgtUS,     _EndTgtUS (US: user)
    //                                                 // des donnees de travail  _StartTgtSC,     _EndTgtSC
    CATMathVector             _StartTgtUS  ,
                              _EndTgtUS    ;
    CATMathVector             _StartTgtSC  ,
                              _EndTgtSC    ;
    // 3) Courbure
    CATLONG32                 _InputCvtSC  ;           // pareil que pour _InputPtSC pour la courbure
    CATLONG32                 _FreeIfNullCvt;          // Idem for Cvt

//  voir _Start._Cvt._BC et _End._Cvt._BC
    CATMathVector             _StartCvtBC  ,
                              _EndCvtBC    ;
    //                                                 // donnees correspondantes sur la SC
    CATMathVector             _StartCvtUS  ,
                              _EndCvtUS    ;
    CATMathVector             _StartCvtSC  ,
                              _EndCvtSC    ;
    double                    _StartScalarCvtOnSimilarCurveUS;
    double                    _EndScalarCvtOnSimilarCurveUS;

    // Plan Tangent en cas de courbure Courbe/Surface
    CATMathVector             _StartTangentPlaneSC,
                              _EndTangentPlaneSC  ;
    // Direction selon laquelle la courbure ne doit pas changer (cas Courbe/Surface)
    CATLONG32                 _InputCvtFixed;          // indicateur de reception de direction fixee (1, 2, 1+2)
    CATMathVector             _StartCvtSCDir,
                              _EndCvtSCDir  ;
    // 4) Torsion
    CATLONG32                 _InputTorSC;             // pareil que pour _InputPtSC pour la courbure
    CATLONG32                 _FreeIfNullTor;          // Idem for Tor
    CATMathVector             _StartTorBC   ,
                              _EndTorBC     ;
    //                                                 // donnees correspondantes sur la SC
    CATMathVector             _StartTorUS   ,
                              _EndTorUS     ;
    CATMathVector             _StartTorSC   ,
                              _EndTorSC     ;
    
    CATLONG32                 _StartCvtMode;           // Mode d'imposition de la courbure 0 (crv/crv) ou 1 (crv/Surf) au debut
    CATLONG32                 _EndCvtMode;             // Mode d'imposition de la courbure 0 (crv/crv) ou 1 (crv/Surf) a la fin

    CATLONG32                 _Constraints[2];         // Tableau (debut/fin) calculé avec les données precedentes au debut du run pour une lecture + facile 

    // Données pour le run multiple avec la meme multiforme de base (deformations des profils du loft)
    int                       _ComputingMatrix;        // (0:1)  1: Demande le calcul de la matrice de transformation (multi run)
    int                       _MatrixIsStored;         // (0:1)     Indique si les données pour la transformation sont calculées
    CATMathSetOfPoints      * _DeformControlPointsSet; // [_NumPtInitSpine] Points de controle initiaux de la spine de deformation 
    CATMathMxNMatrix        * _InvMatxSecondMemberMat; // matrice de Changement de vecteur nodal Nouveaux Points de controle en fonction des premiers
    double                  * _Grad;                   // [3*_NewNbPoints] Points de controle de la spine de deformation apres changement de base 
                                                       // (les X, les Y et les Z)
    CATMathPoint            * _DeformControlPoints;    //equivalent a _Grad points de la cubic apres son changement de vecteur nodal (pour optimisation)


    // Donnees internes
    // ----------------
    CATLONG32                 _Degree;                 // degre de la spine initiale
//  CATLONG32                 _NumPtInitSpine;         // Nombre de points de controle initiaux de la spine de deformation (avant changement de base)
    CATLONG32                 _NewNbPoints;            // Nombre de points de controle de la multiforme a deformer.
    
    // Indicateurs 
    int                       _ConstructorKO;          // vaut 1 si le constructeur se passe mal -> le Run renvoie alors -1
    int                       _GetSimilarCurveDone;    // Destruction des courbes créé si le Get n'a pas ete fait par l'appli
    double                    _ComputedDeformation;    // Valeur de la deformation

    CATFrFNurbsMultiForm   ** _TabOfMultiFormBC;       // Tableau des multiforms equivalentes aux courbes
                                                       // cela ne sert a rien de l'avoir en donnée membre
    CATLISTP(CATGeometry)     _ListGeometriesToDelete;

    double                    _XScaleLoadScalingFactor;
    double                    _XScaleLoadRecordedScale;
    int                       _LoadedFromReplay;
    int                       _IsUnderCGMReplayODT;

//========================================================================
// Gestion CGMReplay
//========================================================================
protected:
//friend class CATGeoStreamFactory;
  friend class CATFrFSimilarCurveBrother; // internal use
  // private static data
  static CATString            _OperatorId;
  static CATGeoOpTimer        _Timer;


};

// pour CGMReplay de CATFrFSmoothSpine, defini localement avec cette classe
//NLD021020 non necessaire ici extern "C"
ExportedByFrFOpeCrv CATString *GetCATFrFSimilarCurveDefaultOperatorId();

#endif
