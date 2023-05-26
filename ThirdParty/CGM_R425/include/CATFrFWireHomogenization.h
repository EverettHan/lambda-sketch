// COPYRIGHT DASSAULT SYSTEMES 1998
//==========================================================================
//
// CATFrFWireHomogenization:
// 
//==========================================================================
//
// Usage notes: Cet objet prend en entree de son constructeur
// des wires ; le Run() peut effectuer l une des 2 operations
// suivantes ou les deux suivant l option choisie (SetHomogenizationType)
//
// operation 1 : les wires de sortie sont les wires d entree relimites
// par le domaine maximal du coupling (maximal dans le sens ou il peut 
// s evaluer sur tous les wires)
//
// operation 2 : les wires de sortie sont des copies des wires d entree avec
// en plus les reports de discontinuite de chaque wire sur tous les autres
//
// Les wires resultats sont recuperes par la methode GetWires
//
//==========================================================================
//  May. 98 JBX Creation                                                 JBX
//  Jan. 99 JBX Le suivi
// 25/06/99 NLD Viewing direction
// 29/01/99 NLD _MinW, _MaxW
// 01/04/99 NLD Ajout argument optionnel iSpine à SetListOfIntersectWire()
//              pour gestion du cas à 0 guide
// 07/04/99 NLD SetListOflimitingWires(), _LimitingWires,
//              _NbOfLimitingWires
// 21/05/99 NLD Ajout argument iDefaultBaseOrientations a 
//              SetListOfIntersectWires() pour le cas ou l'absence 
//              de wires intersectant empeche l'orientation automatique
// 27/05/99 NLD Ajout argument oIntersectWiresOrientations a 
//              SetListOfIntersectWires() pour rendre les sens  
//              par rapport aux wires intersectant
// 31/05/99 NLD Ajout _Mapping, IdenticalParameters()
// 04/06/99 NLD Ajout argument oSpineOrientation a 
//              SetListOfIntersectWires() pour rendre le sens  
//              de la spine par rapport aux wires intersectant
// 06/10/99 NLD Ajout _BodyPointMultiple
// 27/10/99 NLD Ajout argument NumOrderOfIntersectWire a AddVertex()
// 20/12/99 NLD Mise en correspondance eventuelle des points de fermeture:
//              - argument iReferenceWireNumberForClosure a 
//                SetHomogenizationType()
//              - _ReferenceWireNumberForClosure
//              - arguments Cutting et Closing a AddVertex
//              - AlignClosurePoints()
//              - On distingue _NbOfCuttingVertices et _NbOfClosingVertices
//                en remplacement de _NbOfVertex
// 20/12/99 NLD DebugWire()
// 14/01/00 NLD Mise en place du coupling automatique
//              CATFrFWireHomogenization_CouplingType,
//              AutomaticCoupling(),SetAutomaticCouplingMode(),
//              _AutomaticCouplingMode,
//              _EndStatus, _CcvContinuity, _CcvDomain
// 27/01/00 NLD Ajout CATFrFWireHomogenization_AutomaticCouplingByVertexNumber
// 09/02/00 ALM Prise en compte, dans l'homogenization : HomogenizationWires
//              des intersections avec les guides (vertex simple a ne pas
//              reporter et vertex multiple a reporter en Multiple).
//              Code active par le define _ALM_HomogenizationWires_PriseEnCompteDe_Multiple_090200.
// 11/02/00 ALM Methode GetGoodProfileNumber et calcul de _GoodProfileNumber
//              pour etre interroge sur le profil ne contenant pas d'edge degeneree.
// 08/03/00 ALM Dans HomogenizationWires on souhaite savoir si on est en
//              homogenization de wire pour le sweep (on le sait via l'appel
//              a SetListOfIntersectWires(). Dans ce cas, on va chercher dans
//              les vertices imposes par HomogenizationWires s'il n'y a pas
//              des vertices candidats au flag Multiple (par un test de
//              comparaison avec le CCvParam precedent). Ceci provient du
//              RI 0250095 ou sur un profil deux vertices sont distincts, et
//              se reporte a moins de la resolution sur un autre profil.
//              Code active par le define _ALM_DebugRI250095_DetectionDeVerticesMultiplesCaches
//              (voir gestion de _ModeSweepHomoDeProfils)
// NLD 16/03/00 _AutomaticCouplingForceError et argument supplementaire
//              dans SetAutomaticCouplingMode pour forcer sortie en erreur
// 20/03/00 ALM Sauvegarde des CCvParams de relimitations, pour ne pas
//              faire de report de points inutiles (hors limites) dans
//              HomogenizationWires. Code active par _ALM_SauvegardeCCvParamsFromRelim_200300
// NLD 29/03/00 SetVersion(), _Version, _ReportInfo
// NLD 13/04/00 _LimitationMode et argument iLimitationMode
//              à SetListOfLimitingWires
// NLD 18/04/00 Ajout oBaseOrientations a SetListOfIntersectWires
// JSX 27/04/00 GetCoupling()
// NLD 02/05/00 oIntersectWiresOrders en argument optionnel de SetListOfIntersectWires
//              pour rendre l'ordre des guides
// NLD 12/05/00 Suppression GetWiresOrientations et ajout ComputeWireOrientations
//              Ajout _ComputedOrientations
// NLD 05/06/00 Ajout _LimitVerticesInheritance, et activation par SetVersion(2)
// NLD 14/06/00 SetListOfIntersectWires recoit une liste optionnelle de 
//              wires servant uniquement au coupling
// NLD 28/09/00 _ResolutionRatioForIdenticalParameters
// NLD 28/09/00 Argument optionnel iSupports au constructeur, pour Blend
// NLD 04/10/00 _AutomaticCouplingFirsts
// NLD 05/10/00 iCoupleFirstVerticesIfDifferentNumbers en argument de SetAutomaticCouplingMode
// NLD 09/10/00 suppression du #define _ALM_MiseEnPlaceDe_GoodProfileNumber_110200 (code actif)
// NLD 10/10/00 suppression du #define _ALM_SauvegardeCCvParamsFromRelim_200300 (code actif)
// NLD 10/10/00 suppression du #define _ALM_HomogenizationWires_PriseEnCompteDe_Multiple_090200 (code actif)
// NLD 18/10/00 _OthersCCVToDelete 
// NLD 19/10/00 _NCVNiv, _NCVDom, _NCVNumWire, _NCVNumCrv, _NCVVertex, GetNonCoupledVertices
// NLD 10/11/00 Init(), _Supports, constructeur avec CATTopData
// NLD 26/02/01 ComputeSnappingInOneDomain()
// NLD 06/03/01 SetSnappingParameters(), _AbsoluteSnapping,
//              _IterativeSnapping, _ActiveSnapping, _MaximumSnappingValue
// NLD 20/03/01 CreateEvalCouplingDiagnosis()
// NLD 21/03/01 documentation SetVersion(10), _ImposedPointsCouplingG0
// NLD 26/03/01 documentation SetVersion(100), _ImposedPointsCouplingPointesG0
// NLD 02/05/01 _UseFactoryResolutionForD1Coupling
// NLD 30/05/01 _PreciseDegeneratedEdgesReport activable par SetVersion(1000)
//              pour suivi precis des pointes et des pointes multiples
// NLD 19/07/01 Mise en place de l'architecture pour le calcul de couplages partiels:
//              - _CCVDeltaDomain
//              - InitializeCouplingLines(), PrepareOneCouplingLine(),
//                ValidateCouplingLines(), SimulateCouplingLines()
// NLD 04/10/01 Ajout DebugInvEvalCouplingParameters()
// NLD 26/10/01 _PreciseCoupling activable par SetVersion(10000)
// NLD 07/11/01 argument iTolOnIntersectWires à SetListOfIntersectWires()
// JSX 12/02/02 _PreciseCouplingByLevel identique a _PreciseCoupling mais activable par la Config.
// NLD 13/02/02 SetListOfLaws(), _NbLaws, _Laws
// NLD 02/07/02 _DefaultMF, InitMovingFrame()
// NLD 04/07/02 Ajout de FirstCCVSeenClosed()
// NLD 06/09/02 Ajout de CompareTangentsOrientations()
// NLD 17/02/03 Ajout de _RecalageIntersectionSurVertex
// NLD 24/03/03 Ajout SetCuttingVertices()
// NLD 25/03/03 Ajout ParentVertex en argument de AddVertex
// NLD 31/03/03 Argument iNumVertexForClosing à SetCuttingVertices()
// NLD 13/06/03 Ajout pour facilité de debug de _MinMinW, _MaxMaxW, ForceMinMax()
// NLD 30/07/03 Ajout de _WLawClosure, _ForceWLawClosure, _ComputedWLawClosure
// NLD 03/01/04 Ajout argument optionnel oNecessaryWireForReport à SetListOfIntersectWires()
//              indiquant les profils necessaires au suivi
// NLD 25/02/04 Ajout AlignClosurePointsBeforeStart()
// NLD 26/02/04 Ajout _WiresWork
// NLD 25/03/04 Ajout argument iForceClosureOnFirstBreak à SetListOfLaws()
// NLD 11/05/04 Ajout Clear()
// NLD 07/06/04 Ajout de _GuideOrderingUsingProfileOrientation
// NLD 10/09/04 Ajout de _AlignClosurePointsBeforeStart
// NLD 10/09/04 _ViewingDir et _NormalPlane deviennent des pointeurs
//              histoire de ne pas utiliser des directions non specifiées
// NLD 14/09/04 Ajout de _InitialInversion
// NLD 10/09/04 Ajout de _AlignClosurePointsBeforeStartV2
//              Ajout de _LimitationOnClosurePointManagement
// NLD 05/01/05 Ajout de _ShiftCuttingVertices
// NLD 10/01/05 Ajout de _UseProfilePositioning
// NLD 21/02/05 Ajout de _RelimitationUsingTangencyTestAtShiftedPoint
// NLD 14/03/05 Ajout de _UseProfilePositioningEvenIfKO
// NLD 14/03/05 Ajout de _NumMasterGuide, de argument iNumMasterGuide à SetListOfLimitingWires()
//              Ajout de _ProfilePositionUsingMasterGuide
// NLD 08/12/05 Arguments iReportVertices, iReportLawCuttings a HomogenizationWires()
//              En type d'homogeneisation different de 0 1 ou 2 on reporte
//              aussi les coupures dues aux lois
// NLD 23/01/06 Ajout de _LawScaling
// NLD 28/04/06 Ajout de ControlAndEliminateExtraneousDegenerateEdges()
// NLD 03/05/06 Pilotage de ControlAndEliminateExtraneousDegenerateEdges()
//              via _ActiveHomogenizationControl et SetVersion(100000) ;
// NLD 11/05/06 Ajout de _TopologicalOperator, _WarningMode et SetWarningMode()
// NLD 17/05/06 Ajout de RemoveEdgeInWire()
// NLD 15/09/06 _Version est renomme en _Version_DoNotUse
//              Ajout de _NoInfoOnNonIntersectedVertex
// NLD 04/12/06 Le proto de relimitation du blend develop est rendu public
//              Ajout de données specifiques au coupling en point imposé: 
//              _ImposedPointsMode, _ImposedPointsRelimMode, _ImposedPointsRelimCCVIndex
//              Ajout de SetImposedPointMode()
// NLD 05/04/07 Ajout de _RelimitationUsingTangencyTestAtShiftedPointV2
// NLD 06/04/07 Ajout de _RelimitationUsingTangencyTestAtShiftedPointV2bis
// NLD 13/07/07 Ajout de ComputeDefaultOrientations
//              Argument optionnel iMF à CompareTangentsOrientations()
// NLD 20/07/07 Ajout argument optionnel iNumOrderedCCV a ComputeDefaultOrientations()
// JSX 06/09/07 Ajout de  GetCouplingLaw() et _CouplingLaws  sur le coupling en points imposés
// NLD 06/04/09 Ajout de MoveClosure() (en fait le 26/02/08 mais jamais livre)
// NLD 06/04/09 Ajout de _ShiftOnStickingClosure
// NLD 30/06/09 Migration sur CATCGMOperator pour aide a la mesure fine de performances,
//              Le Run() devient de type entier
// NLD 09/07/09 Ajout _InfiniteW
// NLD 09/12/09 Deflaggage _ALM_DebugRI250095_DetectionDeVerticesMultiplesCaches
//              Deflaggage MultiDevelop
//              Mise a la nomenclature des #define inactifs
//              SomeBodyNeedsGetWiresOrientation devient CATFrFWireHomogenization_SomeBodyNeedsGetWiresOrientation
//              TestSimulateCouplingLines devient CATFrFWireHomogenization_TestSimulateCouplingLines
// NLD 05/03/10 Ajout _HasBeenRelimited et GetRelimitationStatus()
// NLD 24/05/10 Ajout _NoTrimBeforeClosureShift
// NLD 02/12/10 Reordonnancement logique des arguments de MyInvEvalCouplingParameters()
//              et MyEvalCouplingParameters()
//              Deflaggage #define CATFrFWireHomogenizationIsACATCGMOperator (actif depuis 30/06/09)
// 23/12/10 NLD Ajout de _InitError et InitCheck()
// 24/05/11 NLD Ajout de _FirstOrLastRelimitationOnSingleProfile
// 07/07/11 NLD Ajout _OperatorId, GetOperatorId(), GetDefaultOperatorId()
// 09/01/12 NLD Ajout LimitationByWires(), LimitationComputeTabMinMax()
// 16/07/13 NLD Ajout _TolObject
// 04/12/13 NLD Ajout Segmentation()
// 08/07/14 NLD Ajout DuplicateOrInvertBody()
//              Renommage de _NbCplLaw en _NbCouplingLaws
//              Recensement et marquage <@ToRecord> des donnees d'entree a enregistrer,
//              reordonnancement logique de ces donnees
//              (instrumentation CGMReplay (1/3))
// 09/07/14 NLD Ajout _RmWiresOut
// 09/05/16 NLD Smart indent               (1/2)
// 17/07/17 NLD Smart indent               (2/2)
//              Instrumentation CGMReplay  (2/3)
//              Ajout Dump(), IsRecordable(), WriteInput()
//              Ajout de donnees anciennement non enregistrees et traitees a la volee
//              - _IntersectingWires et _IntersectingSpine
//              Ajout _Recording et _Result, ComputeResult(), DifferentBodies()
//              Ajout WriteOutput()
// 19/07/17 NLD Recensement marquage et regroupement de toutes les variables
//              - deduites de SetVersion()
//              - deduites du versionning CGMLevel
//              Ajout de variables pour stocker les entrees jusqu'ici traitees a la volee
//              - _TolOnIntersectWires     pour iTolOnIntersectWires     de SetListOfIntersectWires()
//              - _DefaultBaseOrientations pour iDefaultBaseOrientations de SetListOfIntersectWires()
//              - _CuttingVertices         pour iCuttingVertices         de SetCuttingVertices()
//              - _NumVertexForClosing     pour iNumVertexForClosing     de SetCuttingVertices()
//              Ajout _LoadedFromReplay
//              Ajout _ForceSensComputation
//              Ajout _BodiesToDelete
//              Ajout GetStreamableBody()
// 21/07/17 NLD Ajout _HasForeign et _ForceSetListOfIntersectWires
//              Ajout _UserCoupling
// 28/07/17 NLD GetDefaultOperatorId() devient static pour respect du protocole general
// 31/07/17 NLD Ajout SetScaleManager(), RemoveScaleManager(), _ScaleManager
//              Ajout _XScaleLoadScalingFactor et _XScaleLoadRecordedScale
// 04/08/17 NLD Ajout _GeometryToDelete
// 20/11/18 NLD Ajout ComputeCcvDomain()
//              Ajout _FakeRunReturn
// 21/11/18 NLD Ajout CATFrFWireHomogenizationBrother pour facilités CGMReplay
//              Ajout InitCoupling()
//              Ajout SpecialMonoCurveClosedWireTreatment() (deport de ce vieux traitement inactif)
//              Ajout ComputeWireContinuities()
//              Reordonnancement des arguments de SetListOfIntersectWires()
//              avec remontée (enfin) de iTolOnIntersectWires
//              Ajout ComputeWiresIntersections()
//              Ajout CATFrFWireHomogenizationBrother pour besoins CGMReplay
// 28/04/20 NLD Ajout GetMinWMaxW()
// 12/03/21 NLD Gestion du scaling des lois
//              Ajout _NoLawScaling
//              Ajout argument iNoLawScaling à SetListOfLaws()
//==========================================================================
//Attention directive utilisee par CATFrFWireHomogenization.cpp
#define CATFrFWireHomogenizationIsACATCGMOperator

//==========================================================================

//==========================================================================
// ALGO OPTIONS
//==========================================================================
// TEST OPTIONS
//#define CATFrFWireHomogenization_TestSimulateCouplingLines
//==========================================================================

//==========================================================================
// DEFINES
#ifndef CATFrFWireHomogenization_H
#define CATFrFWireHomogenization_H

#include <CATCGMOperator.h>
#include <AdvTopoUtil.h>
#include <CATTopData.h>
#include <CATBody.h>
#include <CATGeoFactory.h>
#include <CATFrFCoupling.h>
#include <CATFrFCompositeCurve.h>
#include <CATFrFCompositeCurveMapping.h>
#include <CATFrFMovingFrame.h>

#include <CATMathDef.h>
#include <CATMathDirection.h>
#include <CATEdgeCurve.h>
#include <CATSkillValue.h>
#include <CATListPV.h>
#include <ListPOfCATBody.h>
#include <ListPOfCATVertex.h>
#include <CATListOfDouble.h>

#include <CATHybDef.h>

#include <CATCGMStream.h>

class CATLaw ;

class CATCGMJournalList;
class CATVertex ;

class CATFrFCCvParam;

class CATTopOpInError;

class CATTopOperator;
class CATGeoODTScaleManager;
class CATFrFWireHomogenizationBrother;
//==========================================================================

//
// ATTENTION: ne pas modifier les valeurs, faire seulement des ajouts
//            car valeurs archivees dans el CGMReplay. NLD190717
typedef enum {CATFrFWireHomogenization_AutomaticCouplingNone           = 0,
              CATFrFWireHomogenization_AutomaticCouplingD1             = 1,
              CATFrFWireHomogenization_AutomaticCouplingD1AndThenD2    = 2,
              CATFrFWireHomogenization_AutomaticCouplingByVertexNumber = 3}//,
//             CATFrFWireHomogenization_AutomaticCouplingD1OrD2}
              CATFrFWireHomogenization_AutomaticCouplingType ;
//-----------------------------------------------------------------------------
class ExportedByAdvTopoUtil CATFrFWireHomogenization: public CATCGMOperator

{
    // Public methods
    // --------------
  friend class CATFrFWireHomogenizationBrother;
  public :

  //--  Constructeur --
    CATFrFWireHomogenization(          CATGeoFactory            *  iFactory                       ,
                                       CATTopData               *  iTopData                       ,
                                       CATBody                 **  iWires                         ,
                                       int                         iNbOfWires                     ,
                                       CATBody                 **  iSupports                      = 0
                             );

    //--  Destructeur --
    virtual ~CATFrFWireHomogenization();

  
    //-- Les methodes --

    int       Run                  ();
    int       RunOperator          ();


    // Parametrisation
    // ---------------
    // J'indique pour chacune des options si elle revele plutot (analyse NLD010817)
    // (V) d'un pseudo-versionning 
    // (O) d'une option
    // (?) indetermine
    // notons que dans le Sweep toutes les options sont activees par versionning
    // sauf
    // - les options 1 et 2 qui sont activees par versionning mais ne doivent jouer
    //   1 que pour les profils et 2 que pour les guides
    // - l'option 10  qui est restreinte aux profils (bien sur) et exclue le cas du blend
    // - l'option 100 qui est limitee aux blends
    //
    // version 0                            : base
    // unites                de version >=1 : (O) - decoupe systematique par wires intersectant meme
    //                                              sur des vertex existant
    //                                              cela permet de generer des pointes dans le cas du loft --> c'est une option
    //                                        (?) - report d'info lors des decoupes
    // unites                de version >=2 : (V) - heritage vertex vertex pour les vertex de relimitation
    // dizaines              de version >=1 : (O) - couplage en points imposes G0             dans SetListOfIntersectWires
    // centaines             de version >=1 : (?) - couplage en points imposes G0 aux pointes dans SetListOfIntersectWires
    // milliers              de version >=1 : (V) - suivi fin des pointes 
    // dizaines  de milliers de version >=1 : (V) - l'eventuel coupling en points imposes sera precis (26/10/01)
    // centaines de milliers de version >=1 : (V) - controle de l'homogeneisation et rattrapage eventuel
    //                                              par elimination des edges de longueur inferieure a 100*resolution
    //                                              pour gestion des cas avec degenerescence sur un wire en face d'une petite edge sur un autre
    // N.B en sus du Sweep,
    //     est utilisee par CATTopologicalBlendCx7 (avec 100, 1100, 11100)
    //     (mais qui fait plusieurs appels successifs, or seul le dernier fait foi; je remplace par un seul)
    //     et c'est tout. NLD010817
    void       SetVersion          (   int                         iVersion                       = 0) ;

    // iType = 0 : Les operations    1 (relimitation) et 2 (report de vertex) (voir usage note) sont effectuees
    // iType = 1 : Seule l'operation 1 (relimitation)     est effectuee
    // iType = 2 : Seule l'operation 2 (report de vertex) est effectuee
    // autre     : aucune de ces opérations n'est effectuée (usage provisoire NLD) 
    //             mais les vertex definis par SetCuttingVertices() sont reportés
    //             ainsi que les parametres de coupure issus des lois recues
    // iReferenceWireNumberForClosure
    //            (de 1 a iNbOfWires)
    //            indique le numero du wire qui servira de reference
    //            pour le report des points de fermeture (nul: pas de report)
    void       SetHomogenizationType(  int                         iType,
                                       int                         iReferenceWireNumberForClosure = 0);

    // Definition du mode de couplage automatique;
    // ce mode n'est pris en compte que si l'on travaille avec un couplage en
    // points imposes, et que l'on appelle SetListOfIntersectWires, meme avec une
    // liste vide: les couplages automatiques seront faits à l'intérieur
    // des domaines definis par les wires intersectant
    void       SetAutomaticCouplingMode
              (CATFrFWireHomogenization_AutomaticCouplingType      iCouplingMode                  ,
                                       CATBoolean                  iForceErrorOnInvalidCoupling   = FALSE,
                                       CATBoolean                  iCoupleFirstVerticesIfDifferentNumbers = FALSE) ;

    // Definition des parametres de snapping
    // Comme SetAutomaticCouplingMode(), cette methode n'aura d'effet que
    // si l'on passe aussi par SetListOfIntersectWires
    // On peut faire du snapping meme si l'on est n'est pas en couplage
    // automatique
    // Le snapping maximum peut etre soit une valeur absolue (longueur)
    // soit une valeur relative (longueur relative du snapping par rapport
    // à la longueur du domaine dans lequel on snappe)
    // Le snapping peut etre iteratif: il est alors rappelé sur les sous-domaines
    // issus du snapping
    void       SetSnappingParameters(   double                     iMaximumSnappingValue          = -1.,
                                        CATBoolean                 iAbsoluteSnapping              = TRUE,
                                        CATBoolean                 iIterativeSnapping             = FALSE);
  
    // Il faut donner le coupling entre les wires
    void       SetCoupling       (      CATFrFCoupling           * iCoupling                      ) ;
    
    // ou utiliser la methode suivante qui indique quel est le type
    // de MovingFrame sur le Wire[0], le Moving Frame est alors cree
    // ainsi que le coupling par intersection dans le Run()
    // Par defaut le type de MovingFrame est l orthogonal a la spine
    // Pour les differentes valeurs de CATMovingFrame voir l interface
    // CATFrFMovingFrame.h
    // les 2 directions sont optionnelles
    // pour les types de moving frame ne necessitant pas de normale
    // au plan mais une viewing direction, passer un pointeur nul
    // en 2eme argument
    void       SetMovingFrameType(      CATMovingFrameType          iType                         ,
                                        CATMathDirection         *  iNormalPlane                  = 0,
                                        CATMathDirection         *  iViewingDir                   = 0);
    
    // ou utiliser la methode suivante qui donne des wires qui intersectent
    // tous les wires a homogeneiser ce qui permet de creer un coupling
    // a points imposes
    // A partir du 21 05 99,
    // on peut recevoir eventuellement des orientations par defaut pour
    // les wires a homogeneiser (valant 1 ou -1), pour le cas
    // ou l'absence de wires intersectant rendrait impossible
    // l'orientation automatique
    //    Nicolas
    // A partir du 27 05 99,
    // on peut rendre eventuellement les orientations calculees
    // des wires intersectant, allant du premier au
    // dernier wire a homogeneiser (si le pointeur de liste
    // est non nul en entree)
    // Ainsi qu'à partir du 04 06 99 l'orientation de la spine,
    // allant aussi du premier au dernier wire a homogeneiser
    // ATTENTION: on rend 0 pour cette orientation si, en presence
    // de guide, on ne fait pas le calcul avec la spine et on ne
    // sait donc pas l'orienter
    // Ainsi qu'a partir du 18 04 00 les orientations reelles des bases
    // et a partir du 02 05 00 l'ordre des guides (pour chaque guide
    // on rend un numero d'ordre >=1)
    // A partir du 15 06 00 on admet en entree une liste de wires de
    // coupling, qui servent à coupler les vertex des profils et doivent
    // passer par ceux-ci; ces wires n'interviennent pas dans le suivi
    // A partir du 07 11 01 on admet en entree une tolerance *iTolOnIntersectWires
    // à laquelle les wires intersectant ont ete approchés, qui est utilisee
    // dans les calculs d'intersection et pour les recalages en extremite
    // des wires a intersecter
    // A partir du 03/01/04 on rend eventuellement la liste des wires
    // necessaires au suivi, lorsque des profils intermedaires
    // peuvent etre necessaires pour affiner le suivi
    // (cas d'un couplage de vertex fixe de profil intermediaire avec
    // des points quelconques non vertex des profils extremes)
    //
    // *** for special modes, call SetImposedPointMode() before this method ***

    void       SetListOfIntersectWires(      CATLONG32              iNbOfIntersectWires           ,
                                       const CATBody            **  iListOfIntersectWires         ,
                                       const CATBody             *  iSpine                        = 0,
                                             CATListOfInt        *  iDefaultBaseOrientations      = 0,
                                             CATLONG32              iNbOfCouplingWires            = 0,
                                       const CATBody            **  iListOfCouplingWires          = 0,
                                             double              *  iTolOnIntersectWires          = 0,
                                             CATListOfInt        *  oIntersectWiresOrientations   = 0,
                                             int                 *  oSpineOrientation             = 0,
                                             CATListOfInt        *  oBaseOrientations             = 0,
                                             CATListOfInt        *  oIntersectWiresOrders         = 0,
 //NLD211118 voir avant arguments de sortie  double              * iTolOnIntersectWires           = 0,
                                             CATListOfInt        *  oNecessaryWireForReport       = 0
                                        );
    // methode permettant de definir des wires transversaux qui vont relimiter
    // les wires a homogeneiser: les intersections extremes avec la
    // master guide donnent l'intervalle de travail
    // (voir ces wires comme des profils en sweep multiprofils: l'ensemble
    // des guides est relimite par les profils extremes)
    // ATTENTION: utilisation combinee avec SetCoupling non garantie
    // ATTENTION: utilisation incompatible avec SetListOfIntersectWires
    // (ajout NLD 07 04 99)
    // le 130400: ajout argument iLimitationMode:
    //     0 : limitation des 2 cotés
    //     1 : limitation sur 1er wire limitant recu et pas sur le dernier
    //     2 : limitation sur le dernier wire limitant recu et pas le premier
    // le 140305: ajout argument iNumMasterGuide:
    //  par defaut c'est le 1er des elements a homogeneiser
    //  ce peut etre 2 (ou plus) si le 1er est une spine
    //  ce peut etre 0 si on a seulement une spine
    void       SetListOfLimitingWires (      CATLONG32              iNbOfLimitingWires            ,
                                       const CATBody            **  iListOfLimitingWires          ,
                                             int                    iLimitationMode               = 0,
                                             CATLONG32              iNumMasterGuide               = 1) ;
    // Restricted use; impose cutting vertices
    // if not null iNumVertexForClosing indicates that corresponding cutting
    // vertex will be used as new closure point
    // oParams are computed on initial wires;
    // calling program will have to update them if Run modifies closing point,
    // by substraction of first param 
    //
    // **** Attention utilise par Sweep(CutMasterGuide) et aussi Blend (tentative 22/11/07)
    void        SetCuttingVertices    (      CATLISTP(CATVertex)  & iVertices                     ,
                                             int                    iNumVertexForClosing          ,
                                             CATListOfDouble      & oParams                       ) ;

    // iForceClosureOnFirstBreak à mettre à 1 pour deplacer la fermeture
    // sur le 1er break issu d'une loi
    // Attention:
    // - l'hypothèse ancestrale (et légitime) est que les lois sont définies sur un domaine [0, 1]
    //   en bijection avec la spine (virtuelle) relimitée
    //   c'est à dire qui va etre justement issue de l'homogénéisation
    //   cela a des avantages pratiques et permet de définir sans ambiguité des lois
    //   d'évolution pour un sweep segment ou cercle par exemple
    // - mais il peut etre commode aussi d'avoir des lois définies une fois pour toutes, et partagées,
    //   sur un domaine [0, 1] en bijection avec une spine globale
    //   qui sera relimitée par chaque guide dans une succession de sweeps/lofts
    //   c'est ce que demande les sweeps civils avec solver
    //   il va falloir définir une spécification particulière pour cela
    //   soit loi par loi soit pour l'ensemble des lois; compte tenu du fait
    //   qu'il n'y a jamais mélange de lois de l'opérateur et de lois du solver
    //   (voir s'il y avait detwistage d'un sweep civil qui est en fait un loft?)
    void        SetListOfLaws        (      CATLONG32              iNbLaws                        ,
                                            CATLaw             **  iLaws                          ,
                                            int                    iForceClosureOnFirstBreak      = 0,
                                            int                    iNoLawScaling                  = 0) ;

    // Activation/desactivation du mode warning (1 pour activer, 0 pour desactiver)
    // et definition de l'operateur topologique appelant, auquel il
    // faut passer les warnings
    // N'a jamais ete implementee. NLD080714
    // void       SetWarningMode        (CATTopOperator* TopOperator, int iWarningOn) ;

    // Force une valeur minimum pour le MinW et une valeur
    // maximum pour le MaxW après la relimitation;
    // Ceci permet de restreindre facilement les wires en sortie
    void        ForceMinMax          (      double                 iMinMinW                       ,
                                            double                 iMaxMaxW                       ) ;

    // SetImposedPointMode (only for ImposedPointCoupling hence DevelopCoupling)
    // iImposedPointMode : =0 CouplingPoint classique: =1 CouplingDevelop, =2 NoTwist
    // DO NOT CHANGE VALUES, because:
    //   - transmitted to ImposedPointCoupling
    //   - stored in CGMReplay stream
    // iRelimitationMode[2] && iRelimitingCCVNumber[2] define relimiting options on each extremity
    // iRelimitationMode[i] : On each extremity : =0 : until extremity vertices on all CCVs
    //                                            =1 : Until extremity vertex of ccv number iRelimitingCCVNumber[i]
    //                                            =2 : Best solution (Automatic selection of the limiting ccv)
    // iRelimitingCCVNumber[i] : ccv number whose extremity vertex will relimit coupling
    // (N.B number starting from 1)
    // *** must be called before SetListOfIntersectWires() if necessary ***
    void        SetImposedPointMode (      CATLONG32               iMode                          ,
                                           CATLONG32               iRelimitationMode           [2],
                                           CATLONG32               iRelimitingCCVNumber        [2]);


    // Calcul des parametres de coupure issus des lois
    void        ComputeLawCuttings  (      CATListOfDouble       & oWLaws                         ) ;

    // Recuperation des sorties
    // ------------------------
    // **** N.B le statut des sorties en cas de levee d'exception n'est pas clair a ce jour. NLD080714
    CATBody  ** GetResult           ();
    
    // recuperation du nombre de wires en entree et en sortie
    int         GetNumberOfWires    ();
  
    
    // Retourne les parametres qui ont servis au report des discontinuites
    void        GetReportedParameters(     double               *& oPar                           ,
                                           int                   & oNbParam                       );

    // rend les vertex non couples (en couplage automatique)
    void        GetNonCoupledVertices(     CATListOfInt         *  oLevels                        = 0,
                                           CATListOfInt         *  oDomainNumbers                 = 0,
                                           CATListOfInt         *  oWireNumbers                   = 0,
                                           CATListOfInt         *  oEdgeNumbers                   = 0,
                                           CATLISTP(CATVertex)  *  oVertices                      = 0) ;

    CATLONG32   GetGoodProfileNumber();

    void        GetCoupling         (      CATFrFCoupling       *& oCoupling                      ) ;

    // Dans le cas de l homogeneisation des profiles du sweep, les profiles
    // peuvent etre reorientes dans le coupling interne cree par
    // WireHomogeneisation et l utilisateur peut avoir besoin de cette
    // information (reoriente = 1, non reoriente = 0)
    // ATTENTION : la methode alloue le pointeur en sortie, a desallouer donc
// #define CATFrFWireHomogenization_SomeBodyNeedsGetWiresOrientation
  #ifdef CATFrFWireHomogenization_SomeBodyNeedsGetWiresOrientation
    CATLONG32 * GetWiresOrientation ();
  #endif
    // NLD120500: je remplace cela par ComputeWiresOrientations, plus general,
    // plus robuste, mais qui n'a pas tout à fait le meme usage;
    // reactiver GetWiresOrientations si quelqu'un en a besoin
    // A APPELER APRES LE RUN
    // Calcul des orientations relatives des differents wires; 1 pour le premier
    void        ComputeWiresOrientations(  CATListOfInt          & oOrientations                  ) ;

  
    // JSX060907
    CATLaw**    GetCouplingLaw      (      CATLONG32             & nbCouplingLaw                  );
    
    // Récupération du domaine utile sur alspine après relimitation; NLD280420
    void        GetMinWMaxW         (      double                & oMinW                          ,
                                           double                & oMaxW                          );

    //-----------------------------------------------------------------------------
    // Rend le statut de relimitation des wires (1: pour les wires relimites, 0 sinon)
    void        GetRelimitationStatus(     int                  *& oRelimited                     );

       const CATString* GetOperatorId       ();
static const CATString* GetDefaultOperatorId();

//-----------------------------------------------------------------------------
// CGMReplay (EN COURS)
//-----------------------------------------------------------------------------
     void       Dump                (      CATCGMOutput          & os                             );

     CATExtCGMReplay* IsRecordable  (      short                 & LevelOfRuntime                 ,
                                           short                 & VersionOfStream                );

     void       WriteInput          (      CATCGMStream          & ioStream                       );

     void       WriteOutput         (      CATCGMStream          & ioStream                       );

     void       RequireDefinitionOfInputAndOutputObjects();

     CATBoolean ValidateOutput      (      CATCGMStream          & ioStream                       ,
                                           CATCGMOutput          & os                             ,
                                           int                     VersionNumber                  );

     // Definition du ScaleManager (si chargement de replay)
     void       SetScaleManager     (CATGeoODTScaleManager      *  iScaleManager                  );

//-----------------------------------------------------------------------------
// Data
//-----------------------------------------------------------------------------
// Je definis des macros car CATLISTP perturbe le parser Sniff
#define CATListOfCATVertex_CATFrFWireHomogenization CATLISTP(CATVertex)
#define CATListOfCATBody_CATFrFWireHomogenization   CATLISTP(CATBody)

    // Private data
    // ------------
  protected:
    // NONE

  private :
    static CATString        _OperatorId;
 
    //                                                                                  -------------------------------------------------
    //--------------------------------------------------------------------------------  General data
    //                                                                                  -------------------------------------------------
    const CATTolerance&     _TolObject;
    CATTopData              _TopData;
    CATGeoFactory         * _Factory;

    CATError              * _InitError;

    //                                                                                  -------------------------------------------------
    //--------------------------------------------------------------------------------  InputData: bodies to homogenize
    //                                                                                  -------------------------------------------------
    int                     _NbOfWires;                                              // <@ToRecord> input from constructor
    CATBody              ** _WiresIn;                                                // <@ToRecord> input from constructor
    CATListOfCATBody_CATFrFWireHomogenization     _Supports ;  // supports des wires // <@ToRecord> input from constructor

    //                                                                                  -------------------------------------------------
    //--------------------------------------------------------------------------------  InputData: version and options
    //                                                                                  -------------------------------------------------
    int                     _Version_DoNotUse ;                                      // <@ToRecord> input from SetVersion()
    int                     _ReferenceWireNumberForClosure ;                         // <@ToRecord> input from SetHomogenizationType()
    int                     _HomogenizationType;                                     // <@ToRecord> input from SetHomogenizationType()
    int                     _ModeSweepHomoDeProfils;                                 // <@NotToRecord> deduced from SetListOfIntersectWires() input

    //                                                                                  -------------------------------------------------
    //--------------------------------------------------------------------------------  InputData: geometrical data for moving frame
    //                                                                                  -------------------------------------------------
    CATMovingFrameType      _MvFrType;                                               // <@ToRecord> input from SetMovingFrameType()
    CATMathDirection      * _NormalPlane;                                            // <@ToRecord> input from SetMovingFrameType()
    CATMathDirection      * _ViewingDir ;                                            // <@ToRecord> input from SetMovingFrameType()

    //                                                                                  -------------------------------------------------
    //--------------------------------------------------------------------------------  InputData: limiting data
    //                                                                                  -------------------------------------------------
    int                     _NumMasterGuide ;                                        // <@ToRecord> input from SetListOfLimitingWires()
    CATBody              ** _LimitingWires;                                          // <@ToRecord> input from SetListOfLimitingWires()
    int                     _LimitationMode;                                         // <@ToRecord> input from SetListOfLimitingWires()
    int                     _NbOfLimitingWires;                                      // <@ToRecord> input from SetListOfLimitingWires()

    //                                                                                  -------------------------------------------------
    //--------------------------------------------------------------------------------  InputData: Intersecting data
    //                                                                                  -------------------------------------------------
    //                      Attention _NbIntersectingWires est la somme du nombre de wires intersectant
    //                                                               et du nombre de wires de couplage
    //                                _IntersectingWires   contient les wires intersectant puis les wires de couplage
    CATLONG32               _NbIntersectingWires;                                     // <@ToRecord> input from SetListOfIntersectWires()
    CATLONG32               _NbCouplingWires;                                         // <@ToRecord> input from SetListOfIntersectWires()
    CATBody              ** _IntersectingWires;                                       // <@ToRecord> input from SetListOfIntersectWires()
    CATBody               * _IntersectingSpine;                                       // <@ToRecord> input from SetListOfIntersectWires()
    double                * _TolOnIntersectWires;                                     // <@ToRecord> input from SetListOfIntersectWires()
    int                   * _DefaultBaseOrientations;                                 // <@ToRecord> input from SetListOfIntersectWires()
    // voir aussi _ForceSensComputation

    //                                                                                  -------------------------------------------------
    //--------------------------------------------------------------------------------  InputData: Cutting data
    //                                                                                  -------------------------------------------------
    // autre entree de SetCuttingVertices    () iVertices                             // <@ToRecord> input from SetCuttingVertices()
    // autre entree de SetCuttingVertices    () iNumVertexForClosing                  // <@ToRecord> input from SetCuttingVertices()
    CATLISTP(CATVertex)      _CuttingVertices;
    int                      _NumVertexForClosing;
    //                                                                                  -------------------------------------------------
    //--------------------------------------------------------------------------------  InputData: laws
    //                                                                                  -------------------------------------------------
    int                      _NbLaws ;                                                // <@ToRecord> input from SetListOfLaws()
    CATLaw                ** _Laws ;                                                  // <@ToRecord> input from SetListOfLaws()
    int                      _ForceWLawClosure ;                                      // <@ToRecord> input from SetListOfLaws()
    int                      _NoLawScaling ;                                          // <@ToRecord> input from SetListOfLaws()

    //                                                                                  -------------------------------------------------
    //--------------------------------------------------------------------------------  InputData: Automatic coupling
    //                                                                                  -------------------------------------------------
    CATFrFWireHomogenization_AutomaticCouplingType _AutomaticCouplingMode ;           // <@ToRecord> input from SetAutomaticCouplingMode()
    CATBoolean              _AutomaticCouplingForceError;                             // <@ToRecord> input from SetAutomaticCouplingMode()
    CATBoolean              _AutomaticCouplingFirsts;                                 // <@ToRecord> input from SetAutomaticCouplingMode()

    //                                                                                  -------------------------------------------------
    //--------------------------------------------------------------------------------  InputData: Imposed points coupling data
    //                                                                                  -------------------------------------------------
    // Données relatives au coupling en point imposé
    CATLONG32               _ImposedPointsMode             ;                          // <@ToRecord> input from SetImposedPointMode()
    CATLONG32               _ImposedPointsRelimMode    [2] ;                          // <@ToRecord> input from SetImposedPointMode()
    CATLONG32               _ImposedPointsRelimCCVIndex[2] ;                          // <@ToRecord> input from SetImposedPointMode()

    //                                                                                  -------------------------------------------------
    //--------------------------------------------------------------------------------  InputData: Snapping parameters
    //                                                                                  -------------------------------------------------
    double                  _MaximumSnappingValue ;                                   // <@ToRecord> input from SetSnappingParameters()
    CATBoolean              _IterativeSnapping ;                                      // <@ToRecord> input from SetSnappingParameters()
    CATBoolean              _ActiveSnapping ;                                         // <@ToRecord> input from SetSnappingParameters()
    CATBoolean              _AbsoluteSnapping ;                                       // <@ToRecord> input from SetSnappingParameters()

    CATFrFCoupling        * _Coupling;                        // coupling             // <@ToRecord> input from SetCoupling() si _RmCoupling == 0 
                                                                                      // (QUASI IMPOSSIBLE a enregistrer!)



    CATBody              ** _WiresWork;

    CATBody              ** _WiresOut;
    int                     _RmWiresOut;

    CATBody              ** _BodyPoint;
    CATBody              ** _BodyPointMultiple;
    CATBody              ** _BodyPointClosure;

    int                   * _NbOfCuttingVertices;
    int                   * _NbOfClosingVertices;

    CATFrFCompositeCurveMapping *_Mapping;
    int                     _RmCoupling;
    CATFrFMovingFrame     * _MvFr;
    int                     _RmMvFr;
    int                     _RmCCV;

    CATFrFCompositeCurve ** _MyCCV;

    CATEdgeCurve        *** _MyEdgeCurveList; // dimensionnement en [_NbOfWires][] indicage en _MyEdgeCurveList[IndWire][IndCrv]
    CATEdge             *** _MyEdgeList;      // dimensionnement en [_NbOfWires][] indicage en _MyEdgeCurveList[IndWire][IndCrv]

    int                   * _IsWireInverted;
    double                * _TotOfWOrd;
    CATLONG32               _NbWDif;
    double                  _MinW;            // paramètre début sur la spine de la zone conservée; commentaire NLD280420
    double                  _MaxW;            // paramètre fin   sur la spine de la zone conservée; commentaire NLD280420
    double                  _MinMinW;
    double                  _MaxMaxW;
    double                  _ResolutionRatioForIdenticalParameters ;
    double                  _WLawClosure ;
    CATCGMJournalList     * _Report;
    int                  ** _EndStatus ;
    int                   * _HasBeenRelimited;
    CATLONG32            ** _CcvContinuity ;
    CATLONG32            ** _CcvDomain ;
    int                  ** _CcvDeltaDomain ;


    // tableau des parametres [_NbIntersectingWires, _NbOfWires] sur les wires
    // a homogeneiser des intersections avec les wires intersectant
    CATFrFCCvParam      *  _IntersectionsWithWiresCCvPar;
    int                 *  _IntersectionsWithWiresMultiplicity;


    int                 *  _ThisProfileIsGood;
    CATBoolean             _DefaultMF ;
    CATFrFCCvParam      *  _CCvParamsFromRelim;

    // variables deduites du pesudo-versionning (SetVersion())
    int                    _ActiveHomogenizationControl ;                      // <@DeducedFromSetVersion>
    int                    _LimitVerticesInheritance ;                         // <@DeducedFromSetVersion>
    int                    _NoInfoOnNonIntersectedVertex ;                     // <@DeducedFromSetVersion>
    int                    _ReportInfo ;                                       // <@DeducedFromSetVersion>
    int                    _ImposedPointsCouplingG0 ;                          // <@DeducedFromSetVersion>
    int                    _ImposedPointsCouplingPointesG0 ;                   // <@DeducedFromSetVersion>
    int                    _PreciseDegeneratedEdgesReport ;                    // <@DeducedFromSetVersion>
    int                    _PreciseCoupling ;                                  // <@DeducedFromSetVersion>
    // variables deduites du versionning (CGMLevel)
    int                    _PreciseCouplingByLevel ;                           // <@DeducedFromCGMLevel>
    int                    _LawScaling ;                                       // <@DeducedFromCGMLevel>
    int                    _RecalageIntersectionSurVertex ;                    // <@DeducedFromCGMLevel>
    int                    _GuideOrderingUsingProfileOrientation ;             // <@DeducedFromCGMLevel>
    int                    _UseFactoryResolutionForD1Coupling ;                // <@DeducedFromCGMLevel>
    int                    _AlignClosurePointsBeforeStart ;                    // <@DeducedFromCGMLevel>
    int                    _AlignClosurePointsBeforeStartV2 ;                  // <@DeducedFromCGMLevel>
    int                    _LimitationOnClosurePointManagement ;               // <@DeducedFromCGMLevel>
    int                    _RelimitationUsingTangencyTestAtShiftedPoint ;      // <@DeducedFromCGMLevel>
    int                    _RelimitationUsingTangencyTestAtShiftedPointV2 ;    // <@DeducedFromCGMLevel>
    int                    _RelimitationUsingTangencyTestAtShiftedPointV2bis ; // <@DeducedFromCGMLevel>
    int                    _ShiftCuttingVertices ;                             // <@DeducedFromCGMLevel>
    int                    _ShiftOnStickingClosure ;                           // <@DeducedFromCGMLevel>
    int                    _NoTrimBeforeClosureShift;                          // <@DeducedFromCGMLevel>
    int                    _FirstOrLastRelimitationOnSingleProfile;            // <@DeducedFromCGMLevel>
    int                    _UseProfilePositioning  ;                           // <@DeducedFromCGMLevel>
    int                    _UseProfilePositioningEvenIfKO  ;                   // <@DeducedFromCGMLevel>
    int                    _ProfilePositionUsingMasterGuide ;                  // <@DeducedFromCGMLevel>
    // autres variables de pilotage
    int                    _NonConnexWireSupport ;                             // ni versionning ni SetVersion()
    int                    _WarningMode ; // Indique si on est en mode warning

    // variables d'etat
    int                    _ComputedWLawClosure ;
    int                    _FakeRunReturn;

    int                    _HasForeign;
    int                    _ForceSetListOfIntersectWires;

    CATListOfInt           _ComputedOrientations ;
    CATListOfInt           _InitialInversion ;

    CATListPV              _OthersCCVToDelete ;
    CATLISTP(CATGeometry)  _GeometryToDelete;

    // informations sur les vertex non couples (Non Coupled Vertices)
    CATListOfInt           _NCVNiv ;    // niveau
    CATListOfInt           _NCVDom ;    // domaine dans ce niveau
    CATListOfInt           _NCVNumWire ;// numero de wire (1...)
    CATListOfInt           _NCVNumCrv ; // numero de courbe dans ce wire

    CATTopOperator*        _TopologicalOperator ;

    CATListOfCATVertex_CATFrFWireHomogenization   _NCVVertex ; // vertex
    //

    // JSX 060907
    // Lois de coupling dans certains cas.
    // Permet de reconsruire dans l'opérateur géometrique exactement le meme coupling
    CATLONG32              _NbCouplingLaws;
    CATLaw              ** _CouplingLaws;

    double                 _InfiniteW ;

    // Donnees de gestion du CGMReplay. NLD190717
    CATBody              * _Result;
    int                    _Recording;
    CATListOfCATBody_CATFrFWireHomogenization _BodiesToDelete;
    CATGeoODTScaleManager* _ScaleManager;
 public:
    // RESTRICTED USE FOR THESE PUBLIC VARIABLES: NOT TO BE USED BY CALLING SOFTWARE (reserved for CGMReplay management)
    int                    _LoadedFromReplay;
    double                 _XScaleLoadScalingFactor;
    double                 _XScaleLoadRecordedScale;

    int                    _ForceSensComputation;
    int                    _UserCoupling;


    // Private methods
    // ---------------
  private :

    void        Init                 ();

    void        Clear                ();

    void        InitCheck            ();

    void        InitMovingFrame      ();

    void        InitCoupling         ();

    // -----------------------------------------------------------
    // methode de couplage automatique par niveau de discontinuite
    //------------------------------------------------------------
    void        AutomaticCoupling    () ;

    void        InitializeCouplingLines() ;

    void        ValidateCouplingLines(      int                    iSnappingContinuity            ,
                                            int                  & oNbCouplingLines               );

   #ifdef CATFrFWireHomogenization_TestSimulateCouplingLines
    void      SimulateCouplingLines  (      int                    iNumDomain                     );
   #endif

    void      PrepareOneCouplingLine (      int                    iNumDomain                     ,
                                            int                 *  iNumCrvBeforeCut               ,
                                            int                 *  iNumCrvAfterCut                ,
                                            int                  & oMaxDiag                       ) ;

    void      ComputeCcvDomain       ();

    void      ComputeSnappingInOneDomain
                                     (      int                    iNumDomain                     ,
                                            int                    iSnappingContinuity            ) ;

    void      StoreNonCoupledVertex  (      int                    iLevel                         ,
                                            int                    iNumDomain                     ,
                                            int                    iIndWire                       ,
                                            int                    iIndExt                        ) ;

    void      DebugWire              (      CATBody             *  iBody                          )  ;

    void      AlignClosurePointsBeforeStart();

    void      MoveClosure            (      CATGeoFactory       *  iFactory                       ,
                                            CATCGMJournalList   *  ClosureReport                  ,
                                            int                    iIndWire                       ,
                                            CATBody             *  iOldWire                       ,
                                            CATCrvParam          & iClosureParam                  ,
                                            CATCurve            *  iCurve                         ,
                                            CATBody             *& oNewWire                       ) ;

    void      AlignClosurePoints     ();

    void      SpecialMonoCurveClosedWireTreatment();

    void      ComputeWireContinuities(      CATLONG32          **  WireContinuities              );

    // Calcul des sorties de SetListOfIntersectWires, d'après ses entrées dorenavant stockées en données membres
    void      ComputeWiresIntersections(    // Entrées (TRANSITOIREMENT il reste un argument)
                                        //  CATListOfInt        * iDefaultBaseOrientations       ,
                                            // Sorties
                                            CATListOfInt        * oIntersectWiresOrientations    ,
                                            int                 * oSpineOrientation              ,
                                            CATListOfInt        * oBaseOrientations              ,
                                            CATListOfInt        * oIntersectWiresOrders          ,
                                            CATListOfInt        * oNecessaryWireForReport        );

    // Controle l'homogeneisation des wires et rectifie eventuellement par l'elimination 
    // de petites edges
    void      ControlAndEliminateExtraneousDegenerateEdges();

    // Enleve une edge dans un wire, raccorde en les remplacant les edges voisines,
    // et met à jour la liste d'edges optionnelle
    void      RemoveEdgeInWire       (      CATBody             *  iBody                          ,
                                            CATWire             *  iWire                          ,
                                            CATEdge             *  iEdge                          ,
                                            CATLISTP(CATCell)   *  ioListEdges                    = 0) ;

    void      LimitationOfWires      ();

    // Limitation par les wires relimitant (le cas échéant)
    void      LimitationByWires               (      int                       IndexMaster        ,
                                                     short                     FirstClosed        ,
                                                     CATBoolean                UseMapping         ,
                                                     double                  & ioMinW             ,
                                                     double                  & ioMaxW             ,
                                                     CATBoolean              & ForceMinMax        ,
                                                     CATTopOpInError        *& ErreurDeSortieRapide
                               );
    // Report de MinW et MaxW: calcul des tableaux de MinW et MaxW
    void       LimitationComputeTabMinMax     (      short                     FirstClosed        ,
                                               const CATMathPoint            & PtMin              ,
                                               const CATMathPoint            & PtMax              ,
                                                     double                  & MinW               ,
                                                     double                  & MaxW               ,
                                                     int                    *  AttentionFermeture ,
                                                     int                    *  TabIndCrvMin       ,
                                                     int                    *  TabIndCrvMax       ,
                                                     double                 *  TabMinW            ,
                                                     double                 *  TabMaxW            ,
                                                     CATTopOpInError        *& ErreurDeSortieRapide
                                   );
    void        HomogenizationWires           (      int                       iReportVertices    = 1,
                                                     int                       iReportLawCuttings = 1);

    void        Segmentation                  (      CATBody                *  iBodyIn            ,
                                                     CATHybSegmentationMode    iSegmentMode       ,
                                                     ListPOfCATBody         *  iSegmentingBodies  ,
                                                     CATBody                *  iBodyPoint         ,
                                                     CATBody                *& oBodyOut           ,
                                                     CATError               *& oSegmentationError );

    CATBody   * DuplicateOrInvertBody         (      CATTopData              & iTopData           ,
                                                     CATBody                *  iInitialResult     ,
                                                     CATBoolean                iInversion         );


    // NLD 25/03/03 On peut specifier un vertex parent eventuel
    void        AddVertex                     (      CATVertex              *  ParentVertex       ,
                                                     CATLONG32                 IndWire            ,
                                                     CATLONG32                 CrvIndex           ,
                                               const CATCrvParam             & Param              ,
                                                     CATBoolean                Cutting            = TRUE ,
                                                     CATBoolean                Closing            = FALSE,
                                                     CATBoolean                Multiple           = FALSE,
                   // numero d'ordre eventuel d'un wire intersectant ayant
                   // genere ce vertex (de 1 a N);
                   // 0 si ne vient pas d'un wire intersectant
                                                     int                       NumOrderOfIntersectWire = 0);
    // indique si 2 parametres sont consideres comme confondus
    CATBoolean IdenticalParameters            (      double                    iW1                ,
                                                     double                    iW2                );

    CATBoolean MyInvEvalCouplingParameters    (const CATLONG32                 iCCvIndex          ,
                                               const CATLONG32                 iCurveIndex        ,
                                               const CATCrvParam            *  iCurveParam        ,
                                                     CATBoolean                ThrowError         ,
                                                     double                  & oT                 );

    double     DebugInvEvalCouplingParameters (      CATLONG32                 iCCvIndex          ,
                                                     CATFrFCCvParam          & iCCvParam          ) ;

    CATBoolean MyEvalCouplingParameters       (const double                    iT                 ,
                                                     CATLONG32                 iCCVIndex          ,
                                                     CATBoolean                iThrowError        ,
                                                     CATLONG32               & oCurveIndex        ,
                                                     CATCrvParam             & oCurveParam        );

    void       CreateEvalCouplingDiagnosis    (      CATTopOpInError        *  CreationError      ,
                                                     int                       IndWire            ) ;
    int        FirstCCVSeenClosed             () ;

    // Calcul d'orientations par defaut pour les profils (sans utilisation des guides)
    // iNumOrderedCCV, optionnel, indique les numeros (commencant a 1) des CCVs
    // ordonnees le long de la spine
    void       ComputeDefaultOrientations     (      CATFrFCompositeCurve   *  iSpine             ,
                                                     CATListOfInt           *  iNumOrderedCCV     ,
                                                     CATListOfInt            & oCCVOrientations   ) ;
    // Teste la compatibilité des sens des tangentes en 2 points de 2 CCVs
    // et rend 0 si 
    //         1 si de memes sens
    //        -1 si de sens opposes
    int        CompareTangentsOrientations    (      int                       NumCcv1            ,
                                               const CATFrFCCvParam          & Param1             ,
                                                     int                       NumCcv2            ,
                                               const CATFrFCCvParam          & Param2             ,
                                                     CATFrFMovingFrame      *  iMF                = NULL) ;

    // constitution d'un resultat unique multi-domaines (par commodite)            (pour CGMReplay)
    void       ComputeResult();

    // comparaison de deux bodies                                                  (pour CGMReplay)
    int        DifferentBodies                (CATSoftwareConfiguration     * iConfig             ,
                                               CATBody                      * iReferenceBody      ,
                                               CATBody                      * iResultBody         ,
                                               double                         iTol                );

    // obtention d'un body streamable (a partir d'un wire 3D)
    void       GetStreamableBody              (CATBody                      *  iBody              ,
                                               CATBody                      *  iSupport           ,
                                               CATBody                      *& oBody
                                              );

    // Destruction du ScaleManager
    void        RemoveScaleManager            ();




};
#endif
