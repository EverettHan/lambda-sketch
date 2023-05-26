#ifndef CATSweepSolverEngineRoadInt_H
#define CATSweepSolverEngineRoadInt_H
//=============================================================================
//
// Utility for producing sweep of Geometric entities. Road design solver specialization
//
// See derived classes for real implementation
//
//=============================================================================
// Historique de AdvancedTopologicalOpe/ProtectedInterfaces/CATFrFTopologicalSweepRoad.h
//-----------------------------------------------------------------------------
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
// 22/03/18 NLD Suppression de CATCreateFrFTopologicalRoadSweep() (d�placement dans CreateFrFTopologicalSweep.h)
// 26/03/18 NLD Suppression de CATSweepSolverEngineRoadInt        (d�placement dans CATSweepSolverEngineRoad.h)
// 15/03/21 NLD Ajout SetLawsDefinedOnFullSpine()
//=============================================================================
// Historique de GMOperatorsInterfaces\ProtectedInterfaces\CATSweepSolverEngineRoadInt.h
//-----------------------------------------------------------------------------
// 26/03/18 NLD Cr�ation par extraction depuis CATFrFTopologicalSweepRoad.h
//              Changement de ExportedByFrFTopologicalOpe en ExportedByCATGMOperatorsInterfaces
// 27/09/18 NLD Ajout RoadDesignLawType_Offset pour rail (offset entre le rail et le ballast)
//              Ajout RoadDesignMode_Rail (pour SetMode())
// 18/09/19 NLD Ajout RoadDesignLawType_ExtraAngle1 et RoadDesignLawType_ExtraAngle2
// 19/09/19 NLD Ajout SetLaw() avec liste de lois
// 28/04/20 NLD Ajout SetMinWLawMaxWLaw()
// 02/11/20 NLD Ajout RoadDesignMode_CentralGuide
// 05/01/21 NLD Ajout nouveaut�s NewCrownRotationModes
//              RoadDesignMode_DoubleCrown
//              RoadDesignLawType_MidCrownAngle1
//              RoadDesignLawType_MidCrownAngle2
//              RoadDesignLawType_MidTravelAngle1
//              RoadDesignLawType_MidTravelAngle2
//              RoadDesignLawType_CrownLength1
//              RoadDesignLawType_CrownLength2
// 15/03/21 NLD Ajout SetLawsDefinedOnFullSpine()
// 23/03/21 NLD Ajout RoadDesignDebugMode
//              et SetDebugValue()
//=============================================================================


//=============================================================================
// Schema
//=============================================================================
//-----------------------------------------------------------------------------
// 1) si rotation autour du centre (copie du schema de CATFrFTopologicalSweepRoad.cpp le 070819)
//-----------------------------------------------------------------------------
// partie lin�aire, le centre de rotation est sur la guide
// conventions d'angle? voir schema;
// par exemple sur un des schemas on a pour une route en chapeau
//    angle1 = -2deg � gauche
// et angle2 = +2deg � droite
// pour faire un chapeau
// on compte donc la tangente de angle2 n�gativement
// A1: angle1, A2: angle2
// L1: longueur 1, X1: extra width1, XL1: X1 + L1
// L2: longueur 2, X2: extra width2, XL2: X2 + L2
// ZL, ZG, ZR: points de cote Z, centres de rotations potentiels (dans le cas RotateCenter c'est ZG)
// (L, M, R): points finaux left, middle, right
//
// ici on tourne de -A1 et de -A2 autour de ZG
//
//  <---------XL1----------|----------XL2--------------------->
//  <-X1-><-----L1---------|-----------L2----------><--X2----->
//.......ZL....(-A1........M=ZG..........A2).......ZR..........    |
//..............x.......................x......................    |
//.......x.........................................x...........    Z
//..L.........................................................R    |
//.............................................................    |
//.........................PG.(point sur guide)................    ^

//-----------------------------------------------------------------------------
// 2) si rotation autour du point droit
//-----------------------------------------------------------------------------
// Schema � faire

//-----------------------------------------------------------------------------
// 3) si rotation autour du point gauche
//-----------------------------------------------------------------------------
// Schema � faire

//-----------------------------------------------------------------------------
// 4) cas rail RoadDesignMode_Rail
//    les longueurs sont mesur�es (et donn�es par les lois)
//    non pas sur la projection horizontale mais dans l'inclinaison
//    (car la voie ferr�e est de largeur dixe mais s'incline)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// prospectives 2019Q3 (voir mails FLR->NLD 060819)
//-----------------------------------------------------------------------------
// - plusieurs voies et donc plusieurs vertex sur chaque pente
//   voir L1 et L2 comme des suites de lois (mais un seul angle A1 ou A2 de chaque cot�)
// - les extensions X1 et X2 peuvent etre inclin�es par rapport aux pentes "centrales"
//   les inclinaisons sont en fait donn�es par des angles par rapport � l'horizontale
//   � titre indicatif 4%
// - au contraire du mode de calcul historique, le profil n'a pas une, ou deux edges (crown)
//   mais un nombre quelconque
// - on doit pouvoir envisager de recevoir
//   - en sus des angles A1 et A2 (RoadDesignLawType_Angle1 et RoadDesignLawType_Angle2)
//     de nouveaux angles pour les parties ExtraWidth
//   - � la place des lois de longueurs simples L1, L2, X1, X2,
//     des listes de lois de longueurs
//     (reutiliser les memes types mais fournir une nouvelle signature de SetLaw() avec liste et non pointeur unique)
//   moyennant quoi ce n'est pas tr�s difficile
// N.B
// - il y aurait des cas de non isotopologie (des voies "disparaissant") mais on convient
//   de les traiter en faisant plusieurs sweeps isotopologiques.
//
// schema
// ...............................G
// ......................PG1...................PD1
// ............... PG2 .......................................PD2
// ...........PGNG..........................................................PGND
//         PGX ....................................................................PDX
// NG et ND peuvent etre differents (nombres de voies � gauche et � droite)
// G, PG1, PG2, ... PGNG sont alignes
// G, PGNG et PGX        ne sont pas forc�ment align�s
// D, PD1, PD2, ... PDND sont alignes
// D, PDND et PDX        ne sont pas forc�ment align�s
//
// Questions:
// 1) y-a-t-il bien un seul segment d'extension PGNG-PGX (et � droite PGND PDX)
//    comme dans schema du mail FLR060819
//    ou bien dans ces zones aussi faut-il prevoir plusieurs voies et donc plusieurs segments align�s?
//    Reponse: on pourra avoir plusieurs parties d'extension et plusieurs angles (r�union LST/FLR/NLD 170919)
//=============================================================================
#include <CATIACGMLevel.h>

#include <CATGMOperatorsInterfaces.h>
#include <CATCGMVirtual.h>

#include <CATSweepSolverEngine.h>

#include <CATCGMStream.h>
#include <CATCGMOutput.h>

#include "CATBoolean.h"
#include <CATString.h>

class CATMathInterval;

class CATKnotVector;
class CATFrFNurbsMultiForm ;

class CATGeoFactory;
class CATICGMObject;
class CATBody;
class CATLaw;

class CATFrFMovingFrame;
class CATFrFCoupling;
class CATFrFCompositeCurve;

class CATSoftwareConfiguration;

#include <CATCGMStream.h>
#include <CATCGMOutput.h>

// ExportedByCATGMOperatorsInterfaces <==> ExportedByFrFTopologicalOpe

//------------------------------------------------------------------
// classe interm�diaire g�n�rale pour RoadDesign
//------------------------------------------------------------------
// la classe peut etre � nouveau deriv�e et la m�thode EvalPoints() red�finie

// #define CATSweepSolverEngineRoadOverrideActivate TestOnlyNePasLivrerActif
#ifdef  CATSweepSolverEngineRoadOverrideActivate
   #define CATSweepSolverEngineRoadOverride    override
#else
   #define CATSweepSolverEngineRoadOverride // override
#endif

//
// CATSweepSolverEngineRoadInt : Int pour interne
//
class ExportedByCATGMOperatorsInterfaces CATSweepSolverEngineRoadInt : public  CATSweepSolverEngine
  {

  public:

                  CATSweepSolverEngineRoadInt
                                           (CATGeoFactory            *  iFactory         ,
                                            CATSoftwareConfiguration *  iConfig          ,
                                            CATBody                  *  iGuide           ,
                                            CATLONG32                   iNbCurves        ); // nombre de courbes du profil

  virtual        ~CATSweepSolverEngineRoadInt();

    //---------------------------------------------------------------------------
    // 1) D�rivation des m�thodes de la classe m�re
    //---------------------------------------------------------------------------
          CATBoolean SetGetInfo            (CATLONG32                   iS1G0            , // ca veut dire 1 pour set 0 pour get. NLD210118
                                            InfoType                    iInfoType        ,
                                            CATLONG32                *& odataLONG32      ,
                                            double                   *& odataDOUBLE      ) CATSweepSolverEngineRoadOverride
    {
     return FALSE;
    }

          void       SetCGMEnv             (CATSoftwareConfiguration *  iConfig          ,
                                            CATGeoFactory            *  iFactory         ) CATSweepSolverEngineRoadOverride
    {}

          void       SetMaxDomain          (CATMathInterval          *  iMaxDom          ) CATSweepSolverEngineRoadOverride;

          void       SetMovingFrame        (CATFrFMovingFrame        *  iSweepMovingFrame,
                                            CATFrFCoupling           *  iCoupling        ,
                                            CATLONG32                   iDCcv            ) CATSweepSolverEngineRoadOverride
    {}
    // 
    // Remplacement des guides
    // 
    // iOldGuides Tableau des guides connues du driver ou de l'application
    // iNewGuides Tableau des guides a utiliser ( apres relimitation, smooth, ..) 
    // appel� une fois par CATFrFTopologicalSweepCx2::ActiveSolverEngine
  virtual void       SetNewGuides          (CATLONG32                   iNbGuides        ,
                                            CATBody                 **  iOldGuide        ,
                                            CATBody                 **  iNewGuide        ) CATSweepSolverEngineRoadOverride
    {}

    //*** GetLaws deplac�e plus bas, n'avait rien � faire ici

    //
    // Solve
    //
    // appel� pr�alablement � toutes les �valuations
    // (a une pertinence en sweep variationnel; peut dans notre cas permettre de lancer
    //  des calculs globaux, par exemple ceux des lois)
    // Appel� une fois par CATFrFSweepCrvCrvCx2::InitiateAbstractProfile_RunBeamSolver
    // via CATFrFSweepCrvCrvCx2SafeBeam::SolverEngineSolve
          void       Solve                 (CATLONG32                 & oResultCode      ) CATSweepSolverEngineRoadOverride;

    // Definition de la transformation du profile en point 
    // 
    // ???
    // Non appel� (je ne trouve pas d'appel au debugger, ni meme d'appel potentiel dans le source)
          void       SetProfileKnotVector  (CATLONG32                   iNbProfileEdges  ,
                                            CATKnotVector           **  iTabKnotVector   ) CATSweepSolverEngineRoadOverride;

    // Non appel�
    // pourrait etre appel� par CATFrFSweepCrvCrvCx2::GetPrecomputedParams()
    // si on �tait en mode 600 (sp�cifique CDS)
          void       GetPrecomputedParams  (CATListOfDouble           & L                ) CATSweepSolverEngineRoadOverride;


    // Info sur les tolerances pour chaque point du profil
    // appel� une fois par CATFrFSweepCrvCrvCx2::InitiateAbstractProfile_RunBeamSolver() via CATFrFSweepCrvCrvCx2::InitCstPts
          CATBoolean GetConstraintArray    (int                      *& ioPointsContinuity,
                                            int                       & ioNbPoints       ) CATSweepSolverEngineRoadOverride;

    // protocole h�rit�; importantissime
    //---------------------------------------------------------------------------
    // appel� n fois par CATFrFSweepCrvCrvCx2::EvalDeformBeam()
   virtual void      EvalCompositeCurve    (double                      iT               ,
                                            CATFrFCompositeCurve     *& oCCV             ) CATSweepSolverEngineRoadOverride
    {}

    // Stream and CGMReplay management
    // -------------------------------
    // le 260318 Deplacement de l'ensemble dans CATSweepSolverEngineRoad


    //---------------------------------------------------------------------------
    // Types sp�cifiques � cette d�rivation
    //---------------------------------------------------------------------------

    // D�finition du centre de rotation (ou plutot du mode)
    // N.B les conventions alg�briques angulaires pour les diff�rents cas de rotation restent � expliciter
    typedef enum    {RoadDesignRotate_Middle         = 1,
                     RoadDesignRotate_Left           = 2,
                     RoadDesignRotate_Right          = 3,
                     // tentative pour faciliter le calcul avec les angles oppos�s � ceux donn�s par les lois
                     RoadDesignRotate_MiddleOpposite = 4,
                     RoadDesignRotate_LeftOpposite   = 5,
                     RoadDesignRotate_RightOpposite  = 6
                    }RoadDesignRotate;

    // D�finition du mode
//  typedef enum    {RoadDesignLengthMode_MeasureAlongXAxis   = 1, // Road: mesure des longueurs suivant l'axe X du movingframe
//                   RoadDesignLengthMode_MeasureAlongSegment = 2  // Rail: mesure des longueurs suivant le segment
//                  }RoadDesignLengthMode;

    // Ici je recopie l'enumeration de CATFrFTopologicalSweepCx2
    // avec les memes noms (c'est commode)
    typedef enum
                    {
                     TopologicalSweepLawTypeEmpty    = 0,
                     TopologicalSweepLawTypeAngle    = 1,
                     TopologicalSweepLawTypeRadius   = 2,
                     TopologicalSweepLawTypeLength   = 3,
                     TopologicalSweepLawTypeRho      = 4,
                     TopologicalSweepLawTypeArea     = 5,
                     TopologicalSweepLawTypeScaling  = 6
                    }
                     TopologicalSweepLawType ;

    //---------------------------------------------------------------------------
    // 2) M�thodes sp�cifiques � cette d�rivation
    //---------------------------------------------------------------------------
    // .2.a) M�thodes fournies
    //       -----------------
    // SUPPRIMEE: seulement dans CATSweepSolverEngineRoad ClearLastEval

    // A garder? a priori la master est d�finie par le constructeur
  virtual void       SetMasterGuide        (CATBody                  *  iMasterGuide     )
    {}

    // Rend la master guide re�ue ou la master guide de travail (apr�s clean/smooth �ventuel)
  virtual CATBody*   GetMasterGuide        ()
    {
     return NULL;
    }

    // Definition de loi
    // (permet � l'application de d�finir chacune des lois utilis�es par le solver)
    // N.B la loi de rotation n'est pas forc�ment continue
    typedef enum    {RoadDesignLawType_Angle1          =  1,
                     RoadDesignLawType_Angle2          =  2,
                     RoadDesignLawType_Length1         =  3, // longueur cot� gauche
                     RoadDesignLawType_Length2         =  4, // longueur cot� droit
                     RoadDesignLawType_MainAngle       =  5, // inclinaison globale
                     RoadDesignLawType_Z               =  6, // cote permettant de passer de la guide � la reference d'altitude de la route
                     RoadDesignLawType_ExtraWidth      =  7,
                     RoadDesignLawType_ExtraWidth1     =  8,
                     RoadDesignLawType_ExtraWidth2     =  9,
                     RoadDesignLawType_Rotation        = 10, // loi non continue prenant des valeurs entieres de type RoadDesignRotate
                     RoadDesignLawType_Offset          = 11, // loi d'offset (en pratique: constante pour le rail)
                     RoadDesignLawType_ExtraAngle1     = 12,
                     RoadDesignLawType_ExtraAngle2     = 13,
                     // Nouveaut�s NewCrownRotationModes R423FD05
                     RoadDesignLawType_MidCrownAngle1  = 14, // pour rotation de la partie gauche rigidifi�e autour du point centre
                     RoadDesignLawType_MidCrownAngle2  = 15, // pour rotation de la partie droite rigidifi�e autour du point centre
                     RoadDesignLawType_MidTravelAngle1 = 16, // pour rotation autour du centre de la voie gauche
                     RoadDesignLawType_MidTravelAngle2 = 17, // pour rotation autour du centre de la voie droite
                     RoadDesignLawType_CrownLength1    = 18, // longueur partie gauche de la couronne centrale
                     RoadDesignLawType_CrownLength2    = 19  // longueur partie droite de la couronne centrale
                     //
                    }RoadDesignLawType;

    // Laws management
  virtual void       SetLaw                (RoadDesignLawType           iLawType         ,
                                            CATLaw                   *  iLaw             )
   {}

          // Enrichissement au cas multi-voies (2019Q3)
          // dans chacune des portions (partie gauche, partie droite)
          // (et peut-etre meme (extension gauche, extension droite))
          // on peut avoir plusieurs voies; donc plusieurs lois de longueurs au lieu d'une.
          // Interface g�n�rale mais destin�e aux lois de longueur
          // Extension en cours aux lois ExtraWidth1,2 et ExtraAngle1,2
  virtual void       SetLaw                (RoadDesignLawType           iLawType         ,
                                            const CATListPV          &  iLaws            )
   {}


  virtual void       GetLaws               (GetLawQuery                 iLawQuery        ,
                                            CATListPV                 & oLaws            )
    {}


    // D�finition des cycles de vie
    typedef enum    {RoadDesignCycleLife_RemoveLawBySolver   = 1 
//                   RoadDesignCycleLife_RemoveSolverBySweep = 2
                    }RoadDesignCycleLife;
  virtual void       SetCycleLife          (RoadDesignCycleLife         iCycleLife       )
    {}


    // D�finition du mode de calcul (pour usage futur)
    // ATTENTION: valeurs archiv�es dans CGMReplay ==> proceder par ajout et non insertion ou modification
    // - dans le mode par defaut les longueurs sont mesur�es suivant l'axe X du repere du moving frame
    // - dans le mode rail       les longueurs sont de vraies longueurs
    // - dans le mode CentralGuide on calcule un point milieu qui est le point milieu
    //   des points des deux guides, sauf le Z (dans le rep�re absolu) qui est celui du point de la premi�re guide
    typedef enum    {RoadDesignMode_Default      = 1,
//                   RoadDesignCycleLife_RemoveSolverBySweep = 2
                     RoadDesignMode_Rail         = 2,
                     RoadDesignMode_CentralGuide = 3,
                     RoadDesignMode_DoubleCrown  = 4
                    }RoadDesignMode;

  virtual void       SetMode               (RoadDesignMode              iMode            )
    {}


          // Par d�faut avec ce solver, les lois sont d�finies 
          // sur un domaine [0, 1] en bijection avec le domaine de la spine initiale compl�te
          // la m�thode qui suit permet d'inhiber cela si les lois sont definies sur la spine relimit�e virtuelle
          // (virtuelle car inconnue de l'application et interne � l'op�rateur sweep)
          // appeler alors cette m�thode avec iLawsDefinedOnFullSpine = 0
  virtual void       SetLawsDefinedOnFullSpine
                                           (int                         iLawsDefinedOnFullSpine)
    {}


    // SUPPRIMEE: seulement dans CATSweepSolverEngineRoad AddCGMObjectToDelete

    // SUPPRIMEE: seulement dans CATSweepSolverEngineRoad GetStreamableLaw

    // Definition d'une valeur de debug
    // - ratio d'angle
    // - ratio de longueur
    // - ratio d'offset
    //   N.B si celui-ci n'est pas d�fini sp�cifiquement le ratio de longueur s'applique aussi � l'offset
    // - echelle de transfert des evaluations sur l'axe xOx
    typedef enum
                    {
                     RoadDesignDebugAngleMagnifier   = 0,
                     RoadDesignDebugLengthMagnifier  = 1,
                     RoadDesignDebugOffsetMagnifier  = 2,
                     RoadDesignDebugSimuOnXAxisScale = 3
                    }
                     RoadDesignDebugMode ;
  virtual void       SetDebugValue         (int                         iRoadDesignDebugMode   ,
                                            double                      iRoadDesignDebugValue  )
    {}


    // .2.b) M�thodes fournies mais d�rivables
    //       ---------------------------------
    // N.B si l'on veut changer le calcul de forme il faut soit deriver EvalForm() soit d�river EvalPoints()

    // Calcul des lois de longueur, pouvant utiliser la spine du moving frame ou _NewMasterGuide
    // - on pourra utiliser CATCreateLawOnWire avec le body dont est issu la guide
    // Cette m�thode est forc�ment appel�e par le moteur du sweep
    // D�rivation indispensable si l'on a besoin de lois et qu'on ne les a pas d�finies par SetLaw()
  virtual void       ComputeLaws           ()
    {}

    // Eval MultiForm
    // oFinalSection est detruite par l'appelant
    // N.B protocole specifique � cette classe et non � la classe m�re
    //     appel�e par le moteur du sweep en chaque param�tre d'�valuation via EvalCompositeCurve()
    //    il faut soit d�river cette m�thode soit
  virtual void       EvalForm              (double                      iT               ,
                                            CATFrFNurbsMultiForm    **  oFinalSection    )
    {}

    // N.B point gauche point milieu et point droit s'entendent dans le sens du movingframe
    //     qui est le sens topologique de la master guide
    //     appel�e par le moteur du sweep en chaque param�tre d'�valuation via EvalCompositeCurve() puis EvalForm()
  virtual void       EvalPoints            (double                      iT               ,
                                            CATMathPoint              & LeftPoint        ,
                                            CATMathPoint              & MiddlePoint      ,
                                            CATMathPoint              & RightPoint       )
    {}


    // .2.c) M�thodes reserv�es 
    //       ------------------
    //      RESTRICTED INTERNAL USE
    // SUPPRIMEE: seulement dans CATSweepSolverEngineRoad  void   * GetManagementData     (int                         iInternalKey     );
          // Red�finition de l'intervalle d'application des lois
          // (post homog�n�isation)
          // pour reparam�trage implicite de lois globales

          // sur le sous-domaine utile
  virtual void       SetMinWLawMaxWLaw     (double                      iMinWLaw         ,
                                            double                      iMaxWLaw         );

  }
;

#endif
