#ifndef CATFrFTopologicalRoadSweep_H 
#define CATFrFTopologicalRoadSweep_H

// ----------------------------------------------------------
// Echanges
// A envoyer desormais avec AdvancedTopologicalOpe\PublicInterfaces\CreateFrFTopologicalSweep.h
// ----------------------------------------------------------
//

// COPYRIGHT DASSAULT SYSTEMES  2018
//=============================================================================
//
// Utility for producing sweep of Geometric entities. Road design specialization
//
// Specific solver
//
// Specific creator for topological sweep operator
//
// Usage notes:
// - use CATCreateFrFTopologicalRoadSweep() for automatic sweep operator and solver creation
//  (see CreateFrFTopologicalSweep.h or CATPGMCreateFrFTopologicalSweep.h)
//
// - see SetLaw() for solver parameterization
//
// - Derive solver for advanced use, and implement 
//   - ComputeLaws()
//   - EvalPoints()
//   - EvalForm() if EvalPoints() not sufficient for specific parameterization
//
//=============================================================================
//(18/01/18)NLD Prototypage sous le cas de test Sweep Case1478*
// 25/01/18 NLD Creation prototype
//              - CATCreateFrFTopologicalRoadSweep()
//              - CATSweepSolverEngineRoadInt: classe de base du solver
//              - CATSweepSolverEngineRoad   : classe applicative du solver
//              Ajout pr�ventif d'une loi de Z avant demande applicative
// 30/01/18 NLD Ajout de l'architecture de Stream
//              - WriteAllInput()
//              - GetListOfInputObjects()
//              - GetOperatorId()
//              - GetSharedlib()
//              - Dump()
//              - _SweepSolverEngineRoadIntOperatorId
//              - CATLoadInFactoryCATSweepSolverEngineRoadInt
// 31/01/18 NLD Ajout pr�ventif de _Mode et SetMode() dans le solver
// 02/02/18 NLD Ajout _ManagementData et GetManagementData()
// 05/02/18 NLD G�n�ralisation
//              - ajout _ExtraWidthLaw
// 06/02/18 NLD Ajout _RotateLaw
// 08/02/18 NLD Ajout _ExtraWidthLaw1 et _ExtraWidthLaw2 devant g�n�raliser et remplacer � terme _ExtraWidthLaw
// 05/03/18 NLD Ajout de _LawsToStream, _StreamableLaws, GetStreamableLaw()
//              Ajout _CGMObjectToDelete et AddCGMObjectToDelete()
// 20/03/18 NLD Modes RoadDesignRotate_MiddleOpposite, RoadDesignRotate_LeftOpposite, RoadDesignRotate_RightOpposite
// 21/03/18 NLD Ajout GetLaws()
// 22/03/18 NLD Suppression de CATCreateFrFTopologicalRoadSweep()                   (d�placement dans CreateFrFTopologicalSweep.h)
// 26/03/18 NLD Revue du d�coupage CATSweepSolverEngineRoadInt/CATSweepSolverEngineRoad
//              - CATSweepSolverEngineRoadInt ne contient plus de donn�es
//              - _SweepSolverEngineRoadOperatorId remplace _SweepSolverEngineRoadIntOperatorId

// 26/03/18 NLD Suppression de CATSweepSolverEngineRoadInt/CATSweepSolverEngineRoad (d�placement dans CATSweepSolverEngineRoad.h)
// 29/05/18 NLD Renommage de _CCV en _EvalCCV
//              Ajout de _NewMasterGuideCCV
//              Ajout de _Coupling
// 27/09/18 NLD De la route au rail, du rail au ballast
//              Ajout _OffsetLaw
// 08/08/19 NLD Etude RoadDesign2019Q3 voies multiples
//              Ajout SetLaw() avec liste de lois
//              Ajout _LengthListLaw1 et _LengthListLaw2
// 18/09/19 NLD Ajout _ExtraAngleLaw1 et _ExtraAngleLaw2
//              Nouvelle signature pour EvalPoints() avec limites de la partie centrale
// 07/10/19 NLD Ajouts pr�visionnels
//              _ExtraWidthListLaw1 et _ExtraWidthListLaw2
//              _ExtraAngleListLaw1 et _ExtraAngleListLaw2
//              RemoveListLaw()
// 05/11/19 NLD Ajout EvalListOfLength()
//              Ajout EvalAllPoints()
// 27/04/20 NLD Ajout EvalLaw()
// 28/04/20 NLD Ajout _MinWLaw, _MaxWLaw, _UseMinWLawMaxWLaw
//              et SetMinWLawMaxWLaw() (ATTENTION: modification CATSweepSolverEngineRoadInt)
// 29/10/20 NLD Ajout SetFunctionalGuides() pour tentative solver � deux guides
//              Ajout _FuncGuide et _NewFuncGuide
// 14/12/20 NLD Ajout structure EvalData
//              Ajout EvalLaws     (): �valuation toutes lois
//              Ajout EvalRotateLaw(): �valuation sp�ciale loi de rotation
//              Ajout EvalGuidePoints()
// 17/12/20 NLD EvalPoints() passe de 5 � 9 points
//              Ajout AddInnerPoints()
//              Ajout AppendListOrLaw()
//              EvalInnerPoints() remplace EvalAllPoints()
// 05/01/21 NLD Nouveaut�s NewCrownRotationModes
//              Ajout _CrownLength1
//              Ajout _CrownLength2
//              Ajout _MidCrownAngle1
//              Ajout _MidCrownAngle2
//              Ajout _MidTravelAngle1
//              Ajout _MidTravelAngle2
//              Ajout _CrownLengthLaw1
//              Ajout _CrownLengthLaw2
//              Ajout _MidCrownAngleLaw1
//              Ajout _MidCrownAngleLaw2
//              Ajout _MidTravelAngleLaw1
//              Ajout _MidTravelAngleLaw2
// 19/01/21 NLD Extensions multi-angles
//              Ajout EvalMultiPoint()
//              Ajout EvalInnerPoints() (deuxieme signature EvalInnerPoints_2)
// 15/03/21 NLD Gestion du scaling des lois lors de l'homog�n�isation
//              et l'�valuation post appel � SetMinWLawMaxWLaw()
//              - ajout de _LawsDefinedOnFullSpine
//              - ajout de SetLawsDefinedOnFullSpine()
//              - ajout argument oLawsDefinedOnFullSpine � GetLaws()
// 19/03/21 NLD Ajout GetSectionPlane()
//              Ajout d'un type en argument de EvalLaw()
// 23/03/21 NLD Ajout _SweepOperatorDebugOnly
//              Ajout SetSweepOperator()
//              Ajout _Debug
//              Ajout SetDebugValue()
// 24/03/21 NLD Ajout _OffsetMagnifier
//              Ajout _DebugDefault
// 31/03/21 NLD Ajout ComputeMiddlePoints()
// 04/08/21 NLD Ajout EvalDoubleCrown() et EvalCentralGuide()
// 15/07/22 NLD Ajout _NbEval provisoirement dans DebugData
//=============================================================================
#include <CATIACGMLevel.h>

#include <FrFTopologicalOpe.h>
// #include <CATSkillValue.h>
#include <CATFrFTopologicalSweep.h>
#include <CreateFrFTopologicalSweep.h>

#include <CATSweepSolverEngine.h>

#include <CATLISTV_CATMathPoint.h>

#include <CATMathPoint.h>

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATCGMJournalList;

#ifndef NULL
/** 
 * Defines the null pointer.
 */
#define NULL 0
#endif

//------------------------------------------------------------------
class CATSweepSolverEngineRoadInt; // see forward
//------------------------------------------------------------------

//------------------------------------------------------------------
// Createur de sweep specialis� RoadDesign
// (la sp�cialisation est faite via le solver de type CATSweepSolverEngineRoadInt)
//------------------------------------------------------------------
// CATCreateFrFTopologicalRoadSweep(): DEPLACEMENT DANS AdvancedTopologicalOpe\PublicInterfaces\CreateFrFTopologicalSweep.h
// le solver est soit cr�� en amont par l'application, soit cr�� et rendu en sortie
// pour que l'application puisse l'enrichir; dans ce cas il n'est pas propriet� de l'application
// le profil d�crit la topologie du profil de balayage,
// comme dans tout loft il doit cependant etre au contact de la guide

//------------------------------------------------------------------
// Solver road g�n�rique
//------------------------------------------------------------------
// DEPLACEMENT le 260318 DANS GMOperatorsInterfaces\ProtectedInterfaces\CATSweepSolverEngineRoadInt.h
#include <CATSweepSolverEngineRoadInt.h>


//------------------------------------------------------------------
// Chargement de solver engine depuis le stream. (Signature impos�e)
//------------------------------------------------------------------
// Ici extern "C" necessaire pour cette fonction � vocation de chargement dynamique; commentaire NLD021020
extern "C" ExportedByFrFTopologicalOpe CATSweepSolverEngine*
 CATLoadInFactoryCATSweepSolverEngineRoadInt(CATGeoFactory* iFactory, CATCGMStream &Str, const short VersionOfStream);

//------------------------------------------------------------------
// Classe applicative pour solver RoadDesign (si necessit� de d�rivation)
//------------------------------------------------------------------
// on pourra par exemple d�river
// - ComputeLaws()
// - EvalPoints()
class ExportedByFrFTopologicalOpe CATSweepSolverEngineRoad : public  CATSweepSolverEngineRoadInt
{
 public:
                  CATSweepSolverEngineRoad (CATGeoFactory            *  iFactory         ,
                                            CATSoftwareConfiguration *  iConfig          ,
                                            CATBody                  *  iGuide           ,
                                            CATLONG32                   iNbCurves        ); // nombre de courbes du profil

 virtual         ~CATSweepSolverEngineRoad ();

  public:
    // 1) D�rivation des m�thodes de la classe CATSweepSolverEngine
          CATBoolean SetGetInfo            (CATLONG32                   iS1G0            , // ca veut dire 1 pour set 0 pour get. NLD210118
                                            InfoType                    iInfoType        ,
                                            CATLONG32                *& odataLONG32      ,
                                            double                   *& odataDOUBLE      ) CATSweepSolverEngineRoadOverride;

          void       SetCGMEnv             (CATSoftwareConfiguration *  iConfig          ,
                                            CATGeoFactory            *  iFactory         ) CATSweepSolverEngineRoadOverride;

          void       SetMovingFrame        (CATFrFMovingFrame        *  iSweepMovingFrame,
                                            CATFrFCoupling           *  iCoupling        ,
                                            CATLONG32                   iDCcv            ) CATSweepSolverEngineRoadOverride;

          void       SetNewGuides          (CATLONG32                   iNbGuides        ,
                                            CATBody                 **  iOldGuide        ,
                                            CATBody                 **  iNewGuide        ) CATSweepSolverEngineRoadOverride;

          void       EvalCompositeCurve    (double                      iT               ,
                                            CATFrFCompositeCurve     *& oCCV             ) CATSweepSolverEngineRoadOverride;

    // Stream and CGMReplay management
    // -------------------------------
          void       WriteAllInput         (CATCGMStream              & Str              );

          CATSweepSolverEngine_ListPOfCATICGMObject
                     GetListOfInputObjects ();

    const CATString * GetOperatorId        () ;

    // Donne le nom de la sharedlib dans laquelle il faut charger cet objet
          void        GetSharedlib         (char                      *& sharedlib       );

          void        Dump                 (CATCGMOutput               & os              );

    // 2) M�thodes sp�cifiques � cette d�rivation
    // .2.a) M�thodes fournies
          void       SetMasterGuide        (CATBody                  *  iMasterGuide     );

          CATBody  * GetMasterGuide        ();

    // Destruction des donn�es de l'it�ration precedente (m�thode sp�cifique)
          void       ClearLastEval         ();

          void       SetLaw                (RoadDesignLawType           iLawType         ,
                                            CATLaw                   *  iLaw             );

          void       GetLaws               (GetLawQuery                 iLawQuery        ,
                                            CATListPV                 & oLaws            ,
                                            int                       & oLawsDefinedOnFullSpine);

          // Enrichissement au cas multi-voies (2019Q3)
          // dans chacune des portions (partie gauche, partie droite)
          // (et peut-etre meme (extension gauche, extension droite))
          // on peut avoir plusieurs voies; donc plusieurs lois de longueurs au lieu d'une.
          // Interface g�n�rale mais destin�e aux lois de longueur
          void       SetLaw                (RoadDesignLawType           iLawType         ,
                                      const CATListPV                &  iLaws            );

          // Red�finition de l'intervalle d'application des lois
          // (post homog�n�isation)
          // pour reparam�trage implicite de lois globales
          // sur le sous-domaine utile
          void       SetMinWLawMaxWLaw     (double                      iMinWLaw         ,
                                            double                      iMaxWLaw         );

          // Par d�faut avec ce solver, les lois sont d�finies 
          // sur un domaine [0, 1] en bijection avec le domaine de la spine initiale compl�te
          // la m�thode qui suit permet d'inhiber cela si les lois sont definies sur la spine relimit�e virtuelle
          // (virtuelle car inconnue de l'application et interne � l'op�rateur sweep)
          // appeler alors cette m�thode avec iLawsDefinedOnFullSpine = 0
          void       SetLawsDefinedOnFullSpine
                                           (int                         iLawsDefinedOnFullSpine);


          void       SetCycleLife          (RoadDesignCycleLife         iCycleLife       );

          void       SetMode               (RoadDesignMode              iMode            );

          void       AddCGMObjectToDelete  (CATICGMObject            *  iObject          );

          // A definir dans classe m�re CATSweepSolverEngineRoadInt NLD291020
          // N.B on pr�voit une interface g�n�rale mais le besoin au 291020 est une seule guide fonctionnelle
          void       SetFunctionalGuides   (CATLISTP(CATBody)        *  iFunctionalGuides);

    // .2.b) M�thodes fournies mais d�rivables
  virtual void       ComputeLaws           () ;

  virtual void       EvalForm              (double                      iT               ,
                                            CATFrFNurbsMultiForm    **  oFinalSection    ) ;

  virtual void       EvalPoints            (double                      iT               ,
                                            CATMathPoint              & LeftPoint        ,
                                            CATMathPoint              & MiddlePoint      ,
                                            CATMathPoint              & RightPoint       );

  // signature enrichie � 5 points NLD180919,
  //           enrichie � 9 points NLD171220
  // voir interfacage �ventuel dans CATSweepSolverEngineRoadInt
  // En attendant je supprime sa declaration virtual qui ne nous am�ne rien; NLD171220
  // N.B les points sont ordonn�s de gauche � droite
          void       EvalPoints            (double                      iT               ,
                                            CATMathPoint              & LeftPoint        ,  // L
                                            CATMathPoint              & LeftTrackPoint   ,  // LT Ailier gauche
                                            CATMathPoint              & LTM              ,  //    Milieu gauche
                                            CATMathPoint              & ML               ,  //    Inter  gauche
                                            CATMathPoint              & MiddlePoint      ,  // M  Avant  centre
                                            CATMathPoint              & MR               ,  //    Inter  droit
                                            CATMathPoint              & RTM              ,  //    Milieu droit
                                            CATMathPoint              & RightTrackPoint  ,  // RT Ailier droit
                                            CATMathPoint              & RightPoint       ); // R

  // Pr�voir une m�thode EvalPoints() plus g�n�rale

          CATLaw   * GetStreamableLaw      (CATLaw                   *  iLaw             ,
                                            TopologicalSweepLawType     iLawType         ,
                                            CATCGMStream             *  iStream          = NULL);

    // .2.c) M�thodes reserv�es 
    //       ------------------
    //      RESTRICTED INTERNAL USE
          void     * GetManagementData     (int                         iInternalKey     );
 
          void       SetSweepOperator      (CATFrFTopologicalSweep   *  iSweepOperator   );

  private: 
          void       RemoveListLaw         (CATListPV                &  ioListLaw        );

  // Evaluation d'une loi
          double     EvalLaw               (double                      iT               ,
                                            CATLaw                   *  iLaw             ,
                                            int                         iEvalLawType     );

  // Evaluation d'une �ventuelle liste de lois de longueurs et calcul
  // seulement dans ce cas de la longueur totale
          void       EvalListOfLength      (double                      iT               ,
                                      const CATListPV                & iListLaw          ,
                                            CATListOfDouble          & oListLength       ,
                                            double                   & oTotalLength      );

          int        EvalGuidePoints (       double                     iT               ,
                                      const int                         MaxNbGuidePoints ,
                                            CATMathPoint            *   GuidePoints      );

  // Calcul des points interm�diaires entre deux points par ratios de longueurs
  //                 EvalInnerPoints_1
          void       EvalInnerPoints (const CATMathPoint             & iFirstPoint       ,
                                      const CATMathPoint             & iLastPoint        ,
                                      const CATListOfDouble          & iListLength       ,
                                            CATLISTV(CATMathPoint)   & oAllPoints        );

  //                 EvalInnerPoints_2
          void       EvalInnerPoints (      double                     iT                ,
                                            double                     iZ                ,
                                      const CATMathPoint             & iFirstPoint       ,
                                      const CATMathPoint             & iLastPoint        ,
                                      const CATListPV                & iListLengthLaw    ,
                                      const CATListPV                & iListAngleLaw     ,
                                            CATLISTV(CATMathPoint)   & oAllPoints        );

    struct EvalData
    {
     double          _Length1      ;
     double          _Length2      ;
     double          _ExtraWidth   ;
     double          _LengthExt1   ;
     double          _LengthExt2   ;
     double          _CrownLength1 ;
     double          _CrownLength2 ;

     double          _Angle1       ;
     double          _Angle2       ;
     double          _ExtraAngle1  ;
     double          _ExtraAngle2  ;
     double          _MidCrownAngle1;
     double          _MidCrownAngle2;
     double          _MidTravelAngle1;
     double          _MidTravelAngle2;

     double          _Z            ;
     double          _Angle        ;
     double          _Offset       ;

     CATListOfDouble _ListLength1   ;
     CATListOfDouble _ListLength2   ;
     CATListOfDouble _ListLengthExt1;
     CATListOfDouble _ListLengthExt2;

    };

          // Sous-programme d'�valuation des points, cas Central Guide
          void       EvalCentralGuide(      double                      iT               ,
                                            CATMathPoint              * GuidePoints      ,
                                            CATMathPoint              & LeftPoint        ,
                                            CATMathPoint              & LeftTrackPoint   ,
                                            CATMathPoint              & LTM              ,
                                            CATMathPoint              & ML               ,
                                            CATMathPoint              & MiddlePoint      ,
                                            CATMathPoint              & MR               ,
                                            CATMathPoint              & RTM              ,
                                            CATMathPoint              & RightTrackPoint  ,
                                            CATMathPoint              & RightPoint       );

          // Sous-programme d'�valuation des points, cas Double Crown
          void       EvalDoubleCrown (      double                      iT               ,
                                            // de gauche � droite
                                            void*                       iADExt1          ,
                                            void*                       iAD1             ,
                                            void*                       iAD2             ,
                                            void*                       iADExt2          ,
                                            void*                       iPlaneEvaluator  ,
                                      const EvalData                  & ED               ,
                                            CATMathPoint              & LeftPoint        ,  // L
                                            CATMathPoint              & LeftTrackPoint   ,  // LT Ailier gauche
                                            CATMathPoint              & LTM              ,  //    Milieu gauche
                                            CATMathPoint              & ML               ,  //    Inter  gauche
                                            CATMathPoint              & MiddlePoint      ,  // M  Avant  centre
                                            CATMathPoint              & MR               ,  //    Inter  droit
                                            CATMathPoint              & RTM              ,  //    Milieu droit
                                            CATMathPoint              & RightTrackPoint  ,  // RT Ailier droit
                                            CATMathPoint              & RightPoint       ); // R

  // Calcul des points milieux LTM, ML, MR, RTM
  // N.B je ne respecte pas l'ordre de EvalPoints() mais
  //     - les entr�es sont les 5 points principaux historiques  de gauche � droite
  //     - les sorties sont les 4 points milieux supplementaires de gauche � droite
          void       ComputeMiddlePoints(
                                      const CATMathPoint              & LeftPoint        ,
                                      const CATMathPoint              & LeftTrackPoint   ,
                                      const CATMathPoint              & MiddlePoint      ,
                                      const CATMathPoint              & RightTrackPoint  ,
                                      const CATMathPoint              & RightPoint       ,
                                            // sorties
                                            CATMathPoint              & LTM              ,
                                            CATMathPoint              & ML               ,
                                            CATMathPoint              & MR               ,
                                            CATMathPoint              & RTM              );


  // Ajout d'une loi ou d'une liste de lois � une liste de lois
          void       AppendListOrLaw (      CATLaw                  *  Law               ,
                                      const CATListPV                & ListLaw           ,
                                            CATListPV                & ioAllListLaw      );
  // Ajout � ioAllPoints des points internes de iAddPoints
  // (tous sauf le premier et le dernier)
          void       AddInnerPoints  (const CATLISTV(CATMathPoint)   & iAddPoints        ,
                                            CATLISTV(CATMathPoint)   & ioAllPoints       );

  // Evaluation � angles multiples
  // rend les angles equivalents
          void       EvalMultiPoint  (      double                     iT                ,
                                      const CATListPV                & iListLengthLaw    ,
                                      const CATListPV                & iListAngleLaw     ,
                                            CATListOfDouble          & oListLength       ,
                                            CATListOfDouble          & oListAngle        ,
                                            CATListOfDouble          & oListX            ,
                                            CATListOfDouble          & oListY            ,
                                            double                   & oTotalLength      ,
                                            double                   & oTotalAngle       );



    struct DebugData
    {
     int             _DebugSet;
     int             _NbEval;         // ajout NLD150722; sa bonne place? A VOIR
     double          _AngleMagnifier;
     double          _LengthMagnifier;
     double          _OffsetMagnifier;
     double          _SimuOnXAxisScale;
    };
    
  // Definition d'une valeur de debug
          void       SetDebugValue   (      int                         iRoadDesignDebugMode ,
                                            double                      iRoadDesignDebugValue);

  // Evaluation de toutes les lois simples
          void       EvalLaws        (      double                      iT               ,
                                            EvalData                  & EvalValues       );

  // Evaluation sp�ciale pour la loi de rotation (avec d�calage � l'int�rieur des domaines)
          void       EvalRotateLaw   (      double                      iT               ,
                                            RoadDesignRotate          & oRotate          );

       CATMathPlane* GetSectionPlane (      double                      iT               );

  protected:

static CATString _SweepSolverEngineRoadOperatorId;

    CATGeoFactory            * _Factory;
    CATSoftwareConfiguration * _Config;
    CATFrFTopologicalSweep   * _SweepOperatorDebugOnly;

    int                        _Mode;
    int                        _NbCurves;       // Nombre de segments du profil (a priori 2)

    CATFrFMovingFrame        * _MovingFrame;
    CATFrFCoupling           * _Coupling;

    CATFrFNurbsMultiForm    ** _MultiForm;      // les multiforms pour les (deux) segments

    CATFrFCompositeCurve     * _EvalCCV;        // anciennement _CCV
    CATFrFCompositeCurve     * _NewMasterGuideCCV;

    double                     _Scale;

    // Lois. 1) Entr�es du solver
    CATLaw                   * _LengthLaw1;     // Right length
    CATLaw                   * _LengthLaw2;     // Left  length
    // Generalisation � une liste de lois � la place de _LengthLaw1 et _LengthLaw2)
    // N.B � terme on pourra m�me n'utiliser que ces listes (une fois le stream/unstream correctement fait)
    CATListPV                  _LengthListLaw1;
    CATListPV                  _LengthListLaw2;

    CATLaw                   * _CrownLengthLaw1;
    CATLaw                   * _CrownLengthLaw2;

    CATLaw                   * _AngleLaw1;
    CATLaw                   * _AngleLaw2;

    CATLaw                   * _ExtraAngleLaw1;
    CATLaw                   * _ExtraAngleLaw2;
    // Generalisation � une liste de lois � la place de _ExtraAngleLaw1 et _ExtraAngleLaw2)
    // N.B pr�visionnnel; pas encore prises en compte au 141220
    CATListPV                  _ExtraAngleListLaw1;
    CATListPV                  _ExtraAngleListLaw2;

    CATLaw                   * _MidCrownAngleLaw1;
    CATLaw                   * _MidCrownAngleLaw2;
    CATLaw                   * _MidTravelAngleLaw1;
    CATLaw                   * _MidTravelAngleLaw2;

    CATLaw                   * _MainAngleLaw;

    CATLaw                   * _ZLaw;
                                                // loi de longueur suppl�mentaire
                                                // pr�vue pour s'appliquer � l'int�rieur de la corde du virage
                                                // cependant on ne saurait par exemple recevoir une valeur constante
                                                // que l'on aurait en charge d'appliquer � bon escient � droite ou � gauche et dans les
                                                // virages seulement; en effet la longueur suppl�mentaire sera forc�ment nulle
                                                // aux bornes du virage (� moins qu'ils n'aient commenc� � extrapoler
                                                // avant le virage et que l'exra soit constant dans le virage? improbable)
    // definir aussi une loi de Z pour elever la route depuis une Master qui serait en fait � la cote 0
    CATLaw                   * _ExtraWidthLaw;  // ajout�e � gauche ou a droite selon le centre de rotation?
    CATLaw                   * _ExtraWidthLaw1;
    CATLaw                   * _ExtraWidthLaw2;
    // Generalisation � une liste de lois � la place de _ExtraWidthLaw1 et _ExtraWidthLaw2)
    CATListPV                  _ExtraWidthListLaw1;
    CATListPV                  _ExtraWidthListLaw2;

    CATLaw                   * _RotateLaw;      // loi de d�finition du centre de rotation

    CATLaw                   * _OffsetLaw;      // loi d'offset (pour passage du rail au ballast par exemple)

    // Lois. 2) Donn�es internes
    CATListPV                  _LawsToStream;
    CATListPV                  _StreamableLaws ;
    int                        _RemoveLaw;
    int                        _UseMinWLawMaxWLaw;
    int                        _LawsDefinedOnFullSpine;
    double                     _MinWLaw;
    double                     _MaxWLaw;

    CATLISTP(CATICGMObject)    _CGMObjectToDelete;

    CATBody                  * _MasterGuide;    // master     guide initiale
    CATBody                  * _NewMasterGuide; // master     guide de travail �ventuellement diff�rente (si clean)

    // tentative de functional guide pour mode sp�cial d�sign� temporairement par FLR100720 (implementation NLD291020)
    // permettant de calculer une guide centrale avec meme elevation que la master et distance m�diane de
    // la distance (Master, Functional) en projection horizontale
    CATBody                  * _FuncGuide;      // functional guide initiale
    CATBody                  * _NewFuncGuide;   // functional guide de travail �ventuellement diff�rente (si clean)

    void                     * _ManagementData; // management data see implementation

    DebugData                  _DebugDefault;
    DebugData                  _Debug;

};


#endif
