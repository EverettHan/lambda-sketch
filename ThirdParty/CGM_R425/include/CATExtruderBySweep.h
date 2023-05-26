// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATExtruderBySweep:
// Utility for producing sweep of Geometric entities.
// (inherits from CATExtruderByMatrix)
//=============================================================================
// Usage notes:
//
// - CXR2.
// - reserve (Protected) a l operateur topologique de Sweep.
//=============================================================================
// 07 07 98 NLD Creation. (voir generation precedente: CATExtrudeDefFrFSweep)
// 10 09 98 NLD changement de masterguide :
//              InitRun, _ReadyForRun, _NewMasterGuide, ChangeMasterGuide,
//              _CenterBody, SetCenterBody
// 19 10 98 NLD _CanonicProfileSweepType
// 21 10 98 NLD _FrFProfile devient CATFrFGeneralizedProfile
// 21 10 98 NLD _CallLevel pour traces de debug
// 03 11 98 NLD changement de profile :
//              _NewMasterProfile, ChangeMasterProfile
//              _ProfileBody, SetProfileBody
// 14 01 99 CPL Deplacement de l'objet de FreeFormOperators vers le module
//              AdvancedTopologicalOpe
// 18 01 99 NLD StoreGeomSpec et NumSpecCrvInGeom disparaissent et 
//              sont desormais prises dans CATExtruderUtilities
// 24 02 99 NLD Ajout GetDiscontinuityVerticesOnCenter
//              et ComputeExtrapolationOnDiscontinuity
//              pour extrapolation des sweeps unspec a guide C0 sans spine
// 25 02 99 NLD Ajout _SpineContinuityToCheck
// 26 02 99 NLD ComputeExtrapolationOnDiscontinuity rend les 
//              longueurs d'extrapolation par rapport aux points de 
//              de discontinuite, mais aussi les longueurs 
//              d'extrapolation a appliquer reellement aux limites
//              naturelles des courbes
// 26 02 99 NLD Ajout CurveExtrapolation()
// 01 03 99 NLD Ajout GeomRun()
// 02 04 99 SRO CATPlane => CATSurface dans CreateParallelPCurves
//              et CreateMeridianPCurves
// 31 05 99 NLD ajout UpdateGeometricOperator(),
//              _MasterProfileToChange, _MasterGuideToChange, _ProfileAxis
// 21 09 99 NLD SetMasterGuideSupport(), _MasterGuideSupport
// 14 10 99 NLD UpdateGeometricOperator() passe en public pour aide au 
//              debug 
// 29 10 99 NLD _SpineContinuityErrorNotToRaise, _SpineContinuityIsOk
//              SpineContinuityDifferError(),SpineContinuityRaiseError()
// 24 11 99 NLD Ajout argument oMaxDistSNCF a ComputeExtrapolationOnDiscontinuity()
// 14 12 99 NLD _NewMovingFrame pour gestion re-creation d'un movingframe
// 11 01 00 ALM __Modification_ALM_CheckOperands : detection et
//              stockage de guide non plane et discontinue C0 : RI 224955
// 07 06 00 ALM __SortieDesLongueursDExtrapolation_070600 : on sort les longueurs
//              d'extrapolation estimees par GetDiscontinuityVertices, pour le 
//              nouveau code de calcul de skin de CATSweep : variable activee
//              dans CATExtruder.h
// 20 07 00 NLD SetInitialCenterBody(), SetInitialProfileBody()
//              _InitialMasterGuide, _InitialMasterProfile
//              SetInitialMasterGuide(), SetInitialMasterProfile()
// 03 08 00 ALM Suppression de __SortieDesLongueursDExtrapolation_070600 et 
//              livraison de ComputeDiscontinuities qui gere le non manifold,
//              les extrapolations sur voisinage, et ne met pas a jour les 
//              CATCrvLimits dans la CCv apres extrapolation. Ce code est 
//              appelle par CATSweep, via un set au runtime :
//              set DEV__ALM_Sweep2.
// 03 08 00 ALM On a derive Locate pour avoir un traitement particulier dans 
//              CATExtruderBySweep (ici) lorsqu'il y a eu un set 
//              DEV__ALM_Sweep2.
// 08 11 00 NLD ajout _CCVToDelete
// 14 11 00 NLD iTopData, _TopData
// 17 01 01 NLD GeomRun() privé renommé en RunGeometricOperator() public
// 18 01 01 NLD _UseCenterBody
// 18 01 01 NLD _CCVForDiagnosisAid  
// 05 03 01 ALM Ajout de oCuspVertices dans ComputeDiscontinuities.
// 21 03 01 ALM Ajout de CrvIndicesLists, CrvParamsLists, ParamsLists, 
//              et LimitTypesLists dans ComputeDiscontinuities.
// 13 09 01 NLD GetLambda rend le CCVParam
// 26 10 01 NLD ChangeMasterGuide() et ChangeMasterProfile() rendent oChange
// 16 05 02 NLD Ajout _MasterGuideSupportManagementCode
//              Ajout argument iSupportManagementCode a SetMasterGuideSupport
// 28 05 02 NLD Mecanisme de sauvegarde de bodies intermediaires:
//              l'appelant fournit une methode de sauvegarde que l'on appelle;
//              ajout SetSaveIntermediateBodyMethod(), _SaveIoData, _SaveIntermediateBodyMethod
// 13 06 02 NLD Gestion de master guide hybride 2D/3D
// 17 06 02 NLD Ajout _MasterGuideSupportIgnoreOutsideEdges,
//             _MasterGuideSupportHybridMode2D3D
// 07 11 02 NLD _InactiveTwistError, InactiveTwistError()
// 12 12 02 NLD Ajout de _ImposedExtrapolation et_UseImposedExtrapolation
// 28 01 03 NLD Ajout argument iCcvMasterGuide à ComputeExtrapolationOnDiscontinuity()
// 29 01 03 NLD Ajout _NumPtComputeExtrapolation, _NumPtComputeExtrapolationForBreak,
//              et BreakPoint()
// 18 04 03 NLD Ajout AddTwistedSurfaceBodyForDiagnosis(),
//              _UsedExtrudedSweepSurfaces
//              _UsedExtrudedSweepSurfacesNumGuide,
//              _UsedExtrudedSweepSurfacesNumProfile
//              AddAllTwistedSurfaceBodiesForDiagnosis()
// 09 05 03 NLD Pour gestion du untwist dans les cas C0
//              Ajout _ImposedExtrapolatedMasterGuide,
//              SetImposedExtrapolation(), SetImposedExtrapolatedMasterGuide(),
//              GetNewMasterGuide()
// 22 05 03 NLD Ajout _NonConnexGuideSupport
//              Ajout CreateCCVGuide()
// 05 06 03 NLD Ajout _ExtrapolatedConnexions
// 30 10 03 NLD _WarningMode, SetWarningMode()
//              AddSurfaceBodyForDiagnosis()
//              AddAllSharpSurfaceBodiesForDiagnosis()
//              _TopologicalOperator
// 19 12 03 NLD Emission de warning pour spine 3D C0
//              Ajout de SpineContinuityRaiseErrorOrWarning() SpineContinuityRaiseWarning()
//              et _SpineContinuityWarningRaised
// 01 04 03 NLD Ajout DumpWireByCCV() CreateCCV()
//              Ajout _InstableCenterBody, SetInstableCenterBody()
// 30 06 04 NLD Ajout ProfileParameterC0RaiseWarning(), CloneGeometry()
// 20 12 04 NLD Ajout de _AssumeCenterEqualToSpine
//              Ajout argument iAssumeCenterEqualToSpine à SetInitialCenterBody
// 01 02 05 NLD Ajout de RemoveCCV()
// 31 03 05 NLD Argument iPtProfile à ProfileParameterC0RaiseWarning()
// 05 04 05 NLD Ajout _InconsistentCenterBody, SetInconsistentCenterBody()
// 24 05 05 NLD Parametre iSigne a CurveExtrapolation()
// 27 05 05 NLD Arguments oDeltaW1 oDeltaW2 à ComputeExtrapolationOnDiscontinuity()
// 28 03 06 NLD Ajout de _NonPlanarAndNonC1SpineDifferedWarning
// 18 05 06 NLD Ajout SetNumberOfGuides() et _NbGuides
// 21 06 06 NLD Ajout _SaveIsActive et argument iSaveIsActive à SetSaveIntermediateBodyMethod()
//              la methode etant appelee a la fois pour la sauvegarde et pour la securisation
//              des donnees intermediaires
// 05 10 06 NLD Ajout de FinalRaiseWarning()
//              Ajout de _KOCheckMFPlaneParameters
// 11 01 07 NLD Ajout de ConvertWrapErrorInWarning() et _ActiveWrapErrorConversionInWarning
// 17 01 07 NLD Ajout de _OptimNoTwistedSurfaceDiagnosis et SetOptimNoTwistedSurfaceDiagnosis()
// 05 03 07 NLD Pour le warning wrap lorsque la detection de twist n'est pas active,
//              ajout de _IgnoreTwistDiag et argument iIgnoreTwistDiagOnly à InactiveTwistError()
// 02/07/07 NLD Ajout SameCCVInMFAndOperator()
// 24/10/07 NLD Ajout SnapOnExistingSurfaceShunt()
// 13/06/08 NLD Ajout SetResult() _LockedSurfaces
//              _CreatingParallelSurfaces et _CreatingTopSurfaces
// 10/03/09 NLD Evolution pour cas particuliers de sweeps C0:
//              (l'extrapolation peut avoir a remplacer des courbes non extrapolables)
//              - CurveExtrapolation rend un argument oExtrapolatedCurve qui dans le cas
//              - GetDiscontinuityVerticesOnCenter() possede desormais deux signatures:
//                - la signature standard repondant au protocole d'extrusion
//                - une signature rendant sur demande l'eventuel body oSwappedBody
//                  avec eventuels swaps de courbe
// 29/06/09 NLD Optimisation de GetDeriv() par memorisation
//              Ajout de _GetDerivLastAvailable, _GetDerivLastSupport, _GetDerivLastLocationOnSupport;
//              et _GetDerivLastDirection;
// 09/12/09 NLD Deflaggage __Modification_ALM_CheckOperands
// 01/02/10 NLD Ajout _InconsistentCenterBodyWithLaws, et argument iWithLaws a SetInconsistentCenterBody()
// 12/02/10 NLD Solution definitive: On supprime _InconsistentCenterBodyWithLaws et on introduit dans
//              _InconsistentCenterBody qui devient entier, un niveau, fixé par l'appelant
//              le niveau 2 est non negociable: la non coherence doit etre maintenue
// 26/02/10 NLD ComputeExtrapolationOnDiscontinuity() recoit les derivees secondes
// 01/03/10 NLD Ajout ComputeExtrapolationForOnePoint()
// 04/03/10 NLD Ajout _RunKO et GetRunStatus()
// 31/03/10 NLD Ajout IsInstanceResultRemovable()
// 02/04/10 NLD Reordonnancement des arguments de GetLambda() et argument supplementaire
//              oSpecialC0ChoiceDone;
// 16/04/10 NLD Ajout ComputeCenterBodyPlaneity() pour isoler le code de calcul de planeite
// 25/06/10 NLD Ajout CreateExtrapolatedCCVGuide()
// 29/06/10 NLD Ajout arguments iOld3DSpine et iOldGuideBody a CreateExtrapolatedCCVGuide()
//              Ajout _InitialCenterBody
//              Ajout argument iInstableCenterBody a SetInitialCenterBody()
//              Ajout _Initial3DMasterFromInitalCenterBody
// 05/08/10 NLD Ajout CATExtruderBySweepSubClass
// 18/10/10 NLD Ajout classe CATExtruderGeomSpecManager pour encapsulation des données
//              de gestion et switch perfos
//              Ajout de _GuidesSpecManager et _ProfilesSpecManager de type CATExtruderGeomSpecManager
//              remplacant _GeomGuides,   _SpecGuides,   _SpecGuideReps
//              et         _GeomProfiles, _SpecProfiles, _SpecProfileReps
// 15/12/10 NLD Ajout IncreaseDomains()
// 13/01/11 NLD Gestion de la mémorisation des extrapolations
//              Ajout argument iSaveExtrapolationResults à GetDiscontinuityVerticesOnCenter() (interface privée)
//              Ajout _ComputedC0Vertices, _ComputedC0EdgesToExtrapolate, _ComputedC0EdgesLimits,
//              _SavedExtrapolationResults;
// 18/01/11 NLD Réordonnancement complet des données pour debug
//              Ajout ____________________MileStone_*
//              Ajout _CGMLevel
// 01/02/11 NLD Ajout _DebugForceAllC0VerticesOnCenter et _DebugForceNoC0VerticesOnCenter
// 09/02/11 NLD Changement d'interface de ComputeExtrapolationForOnePoint():
//              Passage des derivées non normées afin de permettre le calcul en courbure
//              Passage des courbures et des points sur la guide
// 20/05/11 NLD ComputeExtrapolationOnDiscontinuity() calcule aussi des distances de recul
//              et l'interface non générique de GetDiscontinuityVerticesOnCenter() les rend
// 10/01/12 NLD Ajout AppendAndReleaseWarning()
//              _WarningMode renommée _WarningModeActive
// 21/02/12 NLD Ajout SetGeomSweep(), ComputeRecoilOnTwistedArea()
// 03/08/12 NLD Ajout _TolObject
// 12/09/12 NLD Ajout classe CATExtruderBySweepComputeExtrapolationTuning (voir implementation)
//              pour regroupement des reglages de ComputeExtrapolationForOnePoint() et ComputeExtrapolationForOneDiscontinuity()
// 05/06/13 NLD Ajout _SweepOperator
//              L'operateur sweep, que l'on utilise pour differents services, est recu non plus via SetWarningMode()
//              mais des le constructeur
// 06/06/13 NLD Ajout CATExtruderBySweep_C0ExtrapolationCandidate()
// 24/04/14 NLD Ajout _ExtrapolatedConnexionsNbMax pour controle de coherence
// 26/09/16 NLD Calcul de la distance AirFrance dans ComputeExtrapolationForOnePoint() et ComputeExtrapolationOnDiscontinuity()
//              (distance a vol d'oiseau entre les deux droites d'extrapolation)
// 12/05/17 NLD Ajout GetProfileAxis()
// 13 04 20 NLD Ajout _IsClosedOldMode SetIsClosedOldMode()
//=============================================================================
#ifndef CATExtruderBySweep_H
#define CATExtruderBySweep_H

//=============================================================================
// ALGO OPTIONS
//=============================================================================

//=============================================================================
// INCLUDES
// syntaxe #include <> pour lisibilite sous Sniff
#include <FrFTopologicalOpe.h>                // For Windows

#include <CATExtruder.h>                      // For inheritance
#include <CATExtruderByMatrix.h>              // For inheritance

#include <CATListPV.h>                        // Pour listes
#include <CATListOfDouble.h>

#include <CATMathDef.h>                       // Pour typedef CATBoolean
#include <CATMathAxis.h>
#include <CATTolerance.h>

#include <ListPOfCATVertex.h>
#include <ListPOfCATEdge.h>
#include <ListPOfCATBody.h>
#include <CATListOfCATSurfaces.h>

#include <CATSurParam.h>
//=============================================================================
// Pour faciliter l'analyse de syntaxe dans Sniff
#define CATExtruderBySweep_CATListOfCATCurve     CATLISTP(CATCurve)
#define CATExtruderBySweep_CATListOfCATEdgeCurve CATLISTP(CATEdgeCurve)
#define CATExtruderBySweep_CATListOfCATSurface   CATLISTP(CATSurface)
#define CATExtruderBySweep_CATListOfCATCrvLimits CATLISTP(CATCrvLimits)
//=============================================================================
// CLASSES
class CATMathPoint ;
class CATMathVector ;
class CATCrvLimits ;
class CATFrFCompositeCurve ;
class CATFrFGeneralizedProfile;
class CATGeneralizedSweepSurface ;
class CATBiRailSweep ;
class CATExtrudedSweepSurface ;
//class CATExtrudedInstance ;
class CATFrFMovingFrame ;
// Objets topologiques
class CATBody ;
class CATVertex ;
class CATEdge ;
class CATFrFCCvParam ;
class CATTopOperator ;

class CATExtruderBySweepSubClass;
class CATExtruderBySweepGetDiscSecuredExceptionTreatment;
class CATExtruderBySweepComputeExtrapolationTuning;

class CATFrFTopologicalSweepCx2;
class CATCGMDiagnosis;
#include <CATTopData.h>
#include <CATExtruderUtilities.h>
//=============================================================================
//-----------------------------------------------------------------------------
class ExportedByFrFTopologicalOpe
 CATExtruderBySweep: public CATExtruderByMatrix
{
 friend class CATExtruderBySweepSubClass;
 friend class CATExtruderBySweepGetDiscSecuredExceptionTreatment;

 public :

 //-------------------------------------------------------------------------
 // Constructor from CATGeneralizedSweepSurface
 //-------------------------------------------------------------------------
 CATExtruderBySweep ( CATGeoFactory             * iFactory   ,
                      CATTopData                * iTopData   ,
                      CATFrFTopologicalSweepCx2 * iSweepCx2  ,
                      CATGeneralizedSweepSurface* iGeomSweep ) ;

 //-----------------------------------------------------------------------------
 //- Destructeur
 //-----------------------------------------------------------------------------
 ~CATExtruderBySweep() ;

 // *********************************
 // * Methods needed by CATExtruder *
 // *********************************
 virtual void          SetCenterBody  (const CATBody* iCenterBody) ;
 virtual void          SetProfileBody (const CATBody* iProfileBody) ;
 //-------------------------------------------------------------------------
 // Create geometry
 //-------------------------------------------------------------------------
 virtual void          CreateParallelSurfaces
                            ( CATLISTP(CATEdgeCurve)  & iProfiles,
                              CATLISTP(CATCrvLimits)  & iProfileLimits,
                              CATLISTP(CATEdgeCurve)  & iCenters,
                              CATLISTP(CATCrvLimits)  & iCenterLimits )  ;


 //Non necessaire: on utilise celle de CATExtruderByMatrix
 virtual void          CreateTopSurfaces
                            ( CATLISTP(CATSurface)    & iProfileSurfaces,
                              CATLISTP(CATMacroPoint) & iCenters         ) ;


 //Non necessaire: on utilise celle de CATExtruderByMatrix
 virtual void          CreatePCurvesOnTop
                            ( CATLISTP(CATPCurve)     & iProfilePCurves,
                              CATLISTP(CATCrvLimits)  & iProfileLimits,
                              CATLISTP(CATSurface)    & iProfileSupports,
                              CATLISTP(CATMacroPoint) & iCenters         );

 //Non necessaire: on utilise celle de CATExtruderByMatrix
 virtual void          SetResult
                      ( const int                             iProfileIndex,
                        const int                             iCenterIndex ,
                        CATGeometry                        *  iResult      )  ; 

 //-------------------------------------------------------------------------
 // The following methods have to be provided only whenever CreateParallelSurfaces
 // may return Plane whose isopars are not parallel to Profile and Center
 // (SetParametrizationToNotRegular).
 //-------------------------------------------------------------------------
 virtual void          CreateParallelPCurves
                            ( CATLISTP(CATPointOnEdgeCurve) & iProfiles,
                              CATEdgeCurve                 *  iCenter,
                              CATCrvLimits                 *  iCenterLimits,
                              CATSurface                   *  iSupport  )  ;

 virtual void          CreateMeridianPCurves
                            ( CATEdgeCurve                 *  iProfile      ,
                              CATCrvLimits                 *  iProfileLimits,
                              CATLISTP(CATPointOnEdgeCurve) & iCenters      ,
                              CATSurface                   *  iSupport      )  ;

 //-------------------------------------------------------------------------
 // Parametrization mapping to be provided by child classes whenever Surface
 // parametrization has been set to not linear.
 //-------------------------------------------------------------------------
 virtual void          GetEquivalentPoints
                      ( const CATEdgeCurve*             iProfile,
                        const CATEdgeCurve*             iCenter,
                        const CATSurface*               iProduct,
                        const CATLONG32                 iParamsCount,
                        const CATCrvParam               iProfileParams[],
                        const CATCrvParam               iCenterParams [],
                              CATSurParam               oProductParams[] );

 //-------------------------------------------------------------------------
 // Mandatory method to be provided in order to orient volumic results.
 //-------------------------------------------------------------------------
 // Etant donnes un point (CATSurParam) trace sur le support du profil
 // (un plan n est-ce-pas?), et la courbe guide, trouver quelle est
 // la direction du sweep de ce point.
 virtual void          GetDeriv
                      ( const CATSurface              * iSupport,
                        const CATSurParam             & iLocation,
                        const CATEdgeCurve            * iCenter,
                             CATMathDirection        & oDirectionOfMove );

 // *****************************************
 // * Methods needed by CATExtruderByMatrix * (methods derivation)
 // *****************************************
 //-------------------------------------------------------------------------
 // Get geometric parameters of the extrusion as a transformation Matrix.
 //-------------------------------------------------------------------------
 virtual void          GetTransformation
                      (      CATPoint                * iCenter,
                             CATMathTransformation   & oMove   ) ;

 //-------------------------------------------------------------------------
 // Aggregate
 //-------------------------------------------------------------------------
 virtual CATEdgeCurve* CreateEdgeCurve
                      ( CATLISTP(CATCurve)     & iCurves,
                        CATLISTP(CATCrvLimits) & iLimits,
                        CATListOfInt           & iOrns   ) ;
 //-------------------------------------------------------------------------
 // Indicates whether several Lim on same geometry is supported
 //-------------------------------------------------------------------------
 virtual CATBoolean    ShareCenterGeometry() const;
 //-------------------------------------------------------------------------
 // Indicates whether snap on existing surfaces is shunted
 //-------------------------------------------------------------------------
 virtual int           SnapOnExistingSurfaceShunt() ;
 //-------------------------------------------------------------------------
 // Remove from list the unnecessary surfaces.
 //-------------------------------------------------------------------------
 virtual void          FilterExistingSurfaces();

 //-------------------------------------------------------------------------
 // Parallel Curves creation 
 //-------------------------------------------------------------------------
 virtual void          CreateParallelCurves
                          (CATLISTP(CATPoint)     & iProfiles,
                           CATLISTP(CATEdgeCurve) & iCenters,
                           CATLISTP(CATCrvLimits) & iCenterLimits );

 //-------------------------------------------------------------------------
 // 15/02/99 Informations on discontinuity vertices for extrapolation
 // On rend la liste des Vertex presentant des discontinuites
 // ainsi que les listes (couplees par indice) des Edges a extrapoler
 // et des nouvelles limites des courbes sous-jacentes
 //-------------------------------------------------------------------------
 virtual void          GetDiscontinuityVerticesOnCenter
                          (CATListPV              & oDiscontinuityVertices,
                           CATListPV              & oEdgesToExtrapolate,
                           CATLISTP(CATCrvLimits) & oNewEdgesLimits);

 //-----------------------------------------------------------------------------
 //- Calcul des Vertex de discontinuite  (interface supplementaire privee) (donc non virtuelle)
 //-----------------------------------------------------------------------------
         void          GetDiscontinuityVerticesOnCenter
                          (int                      iSaveExtrapolationResults,
                           CATListPV              & oDiscontinuityVertices  ,
                           CATListPV              & oEdgesToExtrapolate     ,
                           CATLISTP(CATCrvLimits) & oNewEdgesLimits         ,
                           CATListOfDouble        & oRecoils                ,       // 2 reculs, à gauche et à droite, par vertex de discontinuité
                           CATBody              **  oSwappedBody            = NULL  // body non extrapole mais avec eventuels remplacements de courbes
                          );

 virtual void ComputeDiscontinuities(CATListPV       & oNMVertices,
                                     CATListPV       & oC0Vertices,
                                     CATListPV       & oEdgesToExtrapolate,
                                     CATListOfDouble & oExtrapolationLengthOnStart,
                                     CATListOfDouble & oExtrapolationLengthOnEnd,
                                     CATListPV       & oCuspVertices,
                                     CATListPV       & oCrvIndicesLists,
                                     CATListPV       & oCrvParamsLists,
                                     CATListPV       & oParamsLists,
                                     CATListPV       & oLimitTypesLists);

 //-------------------------------------------------------------------------
 // Extruded Management
 //-------------------------------------------------------------------------
 virtual CATPGMExtruded* Locate(CATGeometry* iProfile,
                                CATGeometry* iCenter);

 // Indicates whether the geometric result of the instance is to be removed
 // at instance destruction
 // returns 1 if result to be removed, else returns 0
 // Default implementation returns 0
 virtual int             IsInstanceResultRemovable(CATGeometry* iResult/*CATExtrudedInstance* iInstance*/);

 // *****************************************
 // * Methods needed by topological sweep   * (CATFrFTopologicalSweepCx2)
 // *****************************************
 //- Redefinition de l'opérateur géométrique
 // (sert essentiellement en cas de destruction de celui-ci)
         void            SetGeomSweep           (      CATGeneralizedSweepSurface* iGeomSweep);

 // Definition du body centre initial de reference; 
 // cela permet de renseigner cet objet sur le body ayant servi à la definition
 // de l'operateur geometrique, et a eviter des reinitialisations intempestives
 // lors d'un SetCenterBody ulterieur avec le meme body
         void            SetInitialCenterBody   (const CATBody             * iCenterBody               ,
                                                       int                   iAssumeCenterEqualToSpine = 0,
                                                       int                   iInstableCenterBody       = 0) ;
         void            SetInitialMasterGuide  (const CATFrFCompositeCurve* iMasterGuide) ;
 // idem pour profile body
         void            SetInitialProfileBody  (const CATBody             * iProfileBody) ;
         void            SetInitialMasterProfile(const CATFrFCompositeCurve* iMasterProfile) ;

 //- Definition du nombre de guides (nombre de CCVs ou de bodies)
         void            SetNumberOfGuides      (      int                   iNumberOfGuides) ;

 // Indique que le centerbody peut etre instable sous un meme pointeur
         void            SetInstableCenterBody() ;

 // Indique que le centerbody est incoherent avec ce que connait l'operateur geometrique
 // niveau 1: standard; peut eventuellement etre ignore dans certains traitements
 // niveau 2: fort; l'incoherence doit absolument etre preservee
         void            SetInconsistentCenterBody(int iInconsistentCenterBodyLevel=1) ;

 // Active l'optimisation visant a eviter l'aide au diagnostic avec les surfaces twistees
         void            SetOptimNoTwistedSurfaceDiagnosis() ;

 // Definition d'une methode externe de securisation et de sauvegarde des bodies intermediaires
         void            SetSaveIntermediateBodyMethod (int iSaveIsActive,
                                     void(*SaveMethod)(void* ioData,
                                                       CATBody* iBodyToSave,
                                                       CATBoolean iClone),
                                     void* ioDataForCall) ;

 // Imposition d'une valeur forfaitaire d'extrapolation
         void            SetImposedExtrapolation(double iImposedExtrapolation) ;

 // Imposition d'une ccv master guide extrapolée
         void            SetImposedExtrapolatedMasterGuide(CATFrFCompositeCurve* iMasterGuide) ;

 // Recupération de la nouvelle master guide
   CATFrFCompositeCurve* GetNewMasterGuide() ;

 // Desactivation de la sortie en erreur de twist
 // ou seulement la prise en compte de l'erreur de twist
 // (et pas l'ensemble de la gestion, en particulier celle des rebroussements)
         void            InactiveTwistError(int iIgnoreTwistDiagOnly=0) ;

 // Activation de la conversion d'erreur de rebroussement en warning
         void            ConvertWrapErrorInWarning() ;

 // Activation/desactivation du mode warning (1 pour activer, 0 pour desactiver)
 // et definition de l'operateur topologique appelant, auquel il
 // faut passer les warnings
         void            SetWarningMode (CATTopOperator* TopOperator, int iWarningOn) ;

 //-----------------------------------------------------------------------------
 //- Definition du support de la master guide
 //- possibilite de definir un code de management de ce support
 //  ce code est une combinaison des valeurs suivantes
 //  -  0 : standard
 //  - 01 : la master guide peut deborder du support
 //  - 10 : la master guide est hybride 2D/3D
 //-----------------------------------------------------------------------------
         void            SetMasterGuideSupport (const CATGeometry* iSupport               ,
                                                      int          iSupportManagementCode = 0) ;

 //-----------------------------------------------------------------------------
 // Desactivation du nouveau mode de propagation réduite sur les cas fermés
 //-----------------------------------------------------------------------------
         void            SetIsClosedOldMode         () ;

 //-----------------------------------------------------------------------------
 //- Update operateur geometrique
 //-----------------------------------------------------------------------------
         void            UpdateGeometricOperator    () ;

 //-----------------------------------------------------------------------------
 // Tentative de calcul de recul sur une zone twistée
 //-----------------------------------------------------------------------------
         void            ComputeRecoilOnTwistedArea (double          iStartArea,
                                                     double          iEndArea,
                                                     double        & oStartRecoil,
                                                     double        & oEndRecoil);


 //-----------------------------------------------------------------------------
 //- Run operateur geometrique
 //-----------------------------------------------------------------------------
         void            RunGeometricOperator       () ; // Run sur l'objet geometrique
 //-----------------------------------------------------------------------------
 //- Demande que l'erreur eventuelle de continuite de spine soit differee
 //-----------------------------------------------------------------------------
         void            SpineContinuityDifferError () ;
 //-----------------------------------------------------------------------------
 //- Demande de lever l'erreur eventuelle de continuite de spine
 //-----------------------------------------------------------------------------
         void            SpineContinuityRaiseError  () ;
 //-----------------------------------------------------------------------------
 //- Demande de lever un warning pour l'erreur eventuelle de continuite de spine 
 //-----------------------------------------------------------------------------
         void            SpineContinuityRaiseWarning() ;
 //-----------------------------------------------------------------------------
 // Declenchement et libération d'un warning
 //-----------------------------------------------------------------------------
         void            AppendAndReleaseWarning(CATCGMDiagnosis*& ioDiag);
 //-----------------------------------------------------------------------------
 //- Demande de lever les warnings eventuels en fin de traitement
 // (continuité de spine, tracé en limite de twist, ...)
 //-----------------------------------------------------------------------------
         void            FinalRaiseWarning() ;
 //-----------------------------------------------------------------------------
 // Add for diagnostic all twisted surfaces
 // that have been used
 //-----------------------------------------------------------------------------
         void            AddAllTwistedSurfaceBodiesForDiagnosis(CATLISTP(CATBody)& ioLocationList) ;
 //-----------------------------------------------------------------------------
 // Add for diagnostic all sharp surfaces
 // that have been used
 //-------------------------------------------------------------------------
         void            AddAllSharpSurfaceBodiesForDiagnosis  (CATLISTP(CATBody)& ioLocationList) ;
 //-----------------------------------------------------------------------------
 //- Rend le status du Run operateur geometrique
 //-----------------------------------------------------------------------------
         void            GetRunStatus(int& oRunDone, int& oRunKO);


  private :

 //-------------------------------------------------------------------------
 // Analyse de la planeite du center body
 // Attention, prend aussi en compte des donnees globales
 // N.B l'operateur geometrique doit imperativement etre a jour
 //-------------------------------------------------------------------------
         void            ComputeCenterBodyPlaneity(CATFrFCompositeCurve* iMasterGuide);

 //-----------------------------------------------------------------------------
 //- Demande de lever un warning ou une erreur pour l'erreur eventuelle de continuite de spine
 //-----------------------------------------------------------------------------
         void            SpineContinuityRaiseErrorOrWarning(int iWarningMode) ;
 //-----------------------------------------------------------------------------
 //- Demande de lever un warning pour le positionnement du profil sur un vertex C0
 // on recoit le point de la guide ou est positionne le profil
 //-----------------------------------------------------------------------------
         void            ProfileParameterC0RaiseWarning(CATMathPoint& iPtProfile) ;
 //-----------------------------------------------------------------------------
 //- Clonage de geometry
 //-----------------------------------------------------------------------------
         void            CloneGeometry(CATGeometry*  iGeomIn,
                                       CATGeometry*& oGeomOut) ;
 // types enumeratifs locaux
 typedef enum {
               ExtruderBySweepInternalDiagTwist = 0,
               ExtruderBySweepInternalDiagSharp
              } ExtruderBySweepInternalDiag ;


 //-------------------------------------------------------------------------
 // Creation d'une CCV
 //-------------------------------------------------------------------------
 CATFrFCompositeCurve* CreateCCV(CATBody*   iWireBody, 
                                 CATBody*   iSupportBody,
                                 CATBoolean iNonConnexWireSupport,
                                 CATBoolean iIgnoreOutsideEdgeParts,
                                 CATBoolean iHybridMode2D3D) ;
 //-------------------------------------------------------------------------
 // Destruction d'une CCV (immediate ou differee)
 //-------------------------------------------------------------------------
         void            RemoveCCV(CATFrFCompositeCurve* iCCV, int iImmediate) ;

 //-------------------------------------------------------------------------
 // Dump d'un body wire via une CCV (avec protection sur type du body)
 //-------------------------------------------------------------------------
         void            DumpWireByCCV(CATBody         * iBody        ,
                                       CATBody         * iBodySupport = NULL,
                                       char            * texte        = NULL) ;

         void            StartExtrude () ; // debut de l'extrude
         void            InitExtrude  () ; // initialisation de l'extrude
         void            InitRun      () ; // initialisation pour le run
         void            CreateCCVGuide(CATBody             *  iGuideBody,
                                        CATFrFCompositeCurve*& oCCVGuide ) ;
 // Création d'une CCV guide sur support dans le cas de body guide extrapolé
         void            CreateExtrapolatedCCVGuide(
                                        CATFrFCompositeCurve*  iOldSpine,
                                        CATFrFCompositeCurve*  iOld3DSpine,
                                        CATBody             *  iOldGuideBody, // center body optionnel coherent avec iOldSpine
                                        CATBody             *  iGuideBody,
                                        CATBody             *  iSupportBody,
                                        CATBoolean             iNonConnexWireSupport,
                                        CATFrFCompositeCurve*& oCCVGuide);

         int             SameCCVInMFAndOperator() ;
         void            ChangeMasterGuide   (CATBoolean& oChanged) ; // changement de master guide
         void            ChangeMasterProfile (CATBoolean& oChanged) ; // changement de master profile
         void            Clear               () ; // liberation de la memoire
         void            ChangeSweep         (int         NumSweep) ; // Changement de sweep en cours
 //-----------------------------------------------------------------------------
 // mode= 0 standard mode=1 le point est sur la topologie et non sur le guide
 // GetLambda recursif bouclant sur plusieurs sweeps geometriques
 // on conserve cette version recursive au cas ou. Cela ne penalise
 // pas les performances dans le cas ou la recursivite n'est pas
 // necessaire
 // iNumMem est utilise lors de la recursivite pour les accès
 // aux section memorisees suivantes. pour un appel depuis
 // l'exterieur, mettre cet argument a 0
 // oBestCcvParam est le parametre sur le moving frame (ou la spine)
 //-----------------------------------------------------------------------------
 double GetLambda                       ( CATPoint      *  iGuide,
                                          int              mode,
                                          int              iNumMem,
                                          CATLength      & oDistBest,
                                          void          *& oBestSection ,
                                          CATFrFCCvParam & oBestCcvParam,
                                          int            & oSpecialC0ChoiceDone
                                          ) ;

 // Rend le systeme d'axes du profil et NULL dans les cas invalides (ex: sweep canonique)
 CATMathAxis  * GetProfileAxis          ();

 //-----------------------------------------------------------------------------
 // donne le numero d'un profil dans l'objet geometrique
 //-----------------------------------------------------------------------------
 int NumProfileInGeom (const CATCurve    * iProfile) ;
 int NumProfileInGeom (const CATEdgeCurve* iProfile) ;
 //-----------------------------------------------------------------------------
 // donne le numero d'une courbe centre dans l'objet geometrique
 //-----------------------------------------------------------------------------
 int NumGuideInGeom  (const CATCurve     * iCenter) ;
 int NumGuideInGeom  (const CATEdgeCurve * iCenter) ;

 //-----------------------------------------------------------------------------
 // Acces a une surface d'extrusion
 // par defaut: pour le sweep en cours, positionne auparavant
 // par ChangeSweep
 // Les numeros sont des numeros pour le sweep geometrique
 //-----------------------------------------------------------------------------
 CATExtrudedSweepSurface* GetOneExtrudedSweepSurface
                    (const int NumProfile,
                     const int NumGuide = 0 ) ;

 //-----------------------------------------------------------------------------
 // Stocke un resultat surfacique avec la description de sa parametrisation
 //-----------------------------------------------------------------------------
         void            SetExtrudedSurfaceResult
                   (const int                      iNumProfile   , // ancienne notation IndProfile
                    const int                      iNumGuide     , // ancienne notation IndGuide
                          CATExtrudedSweepSurface* iSweepSurface);

 //-------------------------------------------------------------------------
 // Add surfaces for diagnostic
 //-------------------------------------------------------------------------
         void            AddSurfaceBodyForDiagnosis
                                       (ExtruderBySweepInternalDiag iDiag,
                                        int                         iNumGuide,
                                        int                         iNumProfile,
                                        CATSurface                * iSurface,
                                        CATLISTP(CATSurface)      & iLocationSurfaces,
                                        CATLISTP(CATBody)         & ioLocationList) ;

 //-------------------------------------------------------------------------
 // Add twisted surfaces for diagnostic
 //-------------------------------------------------------------------------
         void            AddTwistedSurfaceBodyForDiagnosis
                                       (int                         iNumGuide,
                                        int                         iNumProfile,
                                        CATSurface                * iSurface, 
                                        CATLISTP(CATSurface)      & iTwistedSurfaces,
                                        CATLISTP(CATBody)         & ioLocationList) ;

 //-----------------------------------------------------------------------------
 //- Calcul de l'extrapolation en une discontinuite
 //-----------------------------------------------------------------------------
 // recevoir les tangentes non normees et dans leur sens naturel
 // - on rend des longueurs d'extrapolation positives ou nulles
 //   (oL1 et oL2) (par rapport aux points iPt1 et iPt2)
 // - on rend aussi les longueurs eventuelles d'extension des
 //   courbes au dela de leurs limites naturelles (oLExtLim1, oLExtLim2)
 // ainsi que les nouveaux parametres oW1 et oW2 et les deltas algebriques oDeltaW1 oDeltaW2
 // oMaxDistSNCF indique la distance SNCF maximum entre points de part
 // et d'autre de la discontinuite
         void            ComputeExtrapolationOnDiscontinuity
                    (      CATFrFCompositeCurve*  iCcvMasterGuide,
                     const CATMathPoint         & iPt1,
                           int                    iSign1,
                     const CATMathVector        & iTg1, // tangente
                     const CATMathVector        & iD21, // derivee seconde au point 1
                           CATCurve            *  iCv1,
                           int                    iNumCrv1inCcv, // 1..n
                     const CATCrvParam          & iW1,
                     const CATMathPoint         & iPt2,
                           int                    iSign2,
                     const CATMathVector        & iTg2, // tangente
                     const CATMathVector        & iD22, // derivee seconde au point 2
                           CATCurve            *  iCv2,
                           int                    iNumCrv2inCcv, // 1..n
                     const CATCrvParam          & iW2,
                           double               & oL1,
                           double               & oLExtLim1,
                           double               & oDeltaW1,
                           CATCrvParam          & oW1,
                           double               & oRecoil1,
                           double               & oL2,
                           double               & oLExtLim2,
                           double               & oDeltaW2,
                           CATCrvParam          & oW2,
                           double               & oRecoil2,
                           double               & oMaxDistSNCF,
                           double               & oMaxDistAirFrance
                    ) ;

 //-----------------------------------------------------------------------------
 //- Calcul de l'extrapolation en un point de profil pour une discontinuite
 //-----------------------------------------------------------------------------
         void            ComputeExtrapolationForOnePoint
    (
     CATExtruderBySweepComputeExtrapolationTuning* iTuning,
     //                                      // Donnees pour point a gauche de la discontinuite (point 1)
     //                                      // ---------------------------------------------------------
     const CATMathPoint & iP1,
     const CATMathPoint & iPG1,              // point sur la guide
           int            iSign1,
     const CATMathVector& iT1,
     const CATMathVector& iD11,
     const CATMathVector& iD21,
           double         iC1,               // courbure sur la guide si calculée
     const CATMathPoint & iP1Delta,
           double         iDeltaLOnCrv1,
     //                                      // Donnees pour point a droite de la discontinuite (point 2)
     //                                      // ---------------------------------------------------------
     const CATMathPoint & iP2,
     const CATMathPoint & iPG2,              // point sur la guide
           int            iSign2,
     const CATMathVector& iT2,
     const CATMathVector& iD12,
     const CATMathVector& iD22,
           double         iC2,               // courbure sur la guide si calculée
     const CATMathPoint & iP2Delta,
           double         iDeltaLOnCrv2,
     //                                      // Sorties
           double       & oL1,
           double       & oL2,
           double       & oDistSNCF,
           double       & oDistAirFrance,
           CATMathPoint & oQ                // point objectif entre les droites d'extrapolation
    );

 //-----------------------------------------------------------------------------
 // Increment des numéros de domaines dans une CCV à partir d'un numéro de courbe
 //-----------------------------------------------------------------------------
         void            IncreaseDomains(CATFrFCompositeCurve* iCCV, int NumCrv);

 //-----------------------------------------------------------------------------
 //- Extrapolation d'une courbe en un parametre limite
 //-----------------------------------------------------------------------------
         void            CurveExtrapolation
                    (      CATCurve   *  iCurveToExtrapolate  ,
                     const CATCrvParam & iExtremityParam      ,
                           int           iSigne               ,
                           double&       ioExtrapolationLength,
                           CATCurve   *& oExtrapolatedCurve   ) ;

 //-----------------------------------------------------------------------------
 // check + trace (debug)
 //-----------------------------------------------------------------------------
         void            CheckAll();

 //-----------------------------------------------------------------------------
 // break point
 //-----------------------------------------------------------------------------
         void            BreakPoint(int   iNumPtComputeExtrapolation,
                                    int& ioNumPtComputeExtrapolationForBreak) ;

//-------------------------------------------------------------------------
// Data
//-------------------------------------------------------------------------
 int                         _CallLevel ;                               // Niveau d'appel (traces debug)

 CATTopData                  _TopData ;
 int                         _CGMLevel;
 CATGeoFactory             * _Factory ;
 CATGeoFactory             * _GeomFactory;                              // Factory geometrique associee
 const CATTolerance&         _TolObject;

 // Opérateurs
 // ----------
 int                         ____________________MileStone_Operators;
 CATTopOperator            * _TopologicalOperator ;
 CATFrFTopologicalSweepCx2 * _SweepOperator;
 CATGeneralizedSweepSurface* _GeomSweep ;
 CATExtruderGeomSpecManager  _ProfilesSpecManager;                 // remplace _GeomProfiles _SpecProfiles et _SpecProfileReps
 CATExtruderGeomSpecManager  _GuidesSpecManager;                   // remplace _GeomGuides   _SpecGuides   et _SpecGuideReps
 CATFrFGeneralizedProfile  * _FrFProfile ;
 CATFrFMovingFrame         * _NewMovingFrame ;

 // Specifications
 // --------------
 int                         ____________________MileStone_Spec;
 int                         _NbGuides ;                                // nombre de ccv ou bodys guides
 int                         _InactiveTwistError ;
 int                         _IgnoreTwistDiag ;
 int                         _ActiveWrapErrorConversionInWarning ;
 int                         _WarningModeActive ;                       // Indique si on est en mode warning
 CATBoolean                  _NonConnexGuideSupport ;
 int                         _InstableCenterBody ;                      // indique que le centerbody peut etre instable sous un meme pointeur
 int                         _InconsistentCenterBody ;                  // indique que le centerbody est incoherent avec la ccv de l'operateur geometrique
 //int                         _InconsistentCenterBodyWithLaws;         // idem, cas avec lois
 int                         _AssumeCenterEqualToSpine ;                //
 const CATGeometry         * _MasterGuideSupport ;                      // support de la master guide
 int                         _MasterGuideSupportManagementCode;         // spec de management du support
 int                         _MasterGuideSupportIgnoreOutsideEdgeParts;
 int                         _MasterGuideSupportHybridMode2D3D;
 int                         _OptimNoTwistedSurfaceDiagnosis ;
 int                         _SaveIsActive ;
 void                      * _SaveIoData ;
 void                      (*_SaveIntermediateBodyMethod)(void*      ioData,
                                                          CATBody*   iBodyToSave,
                                                          CATBoolean iClone) ;
 CATFrFCompositeCurve      * _InitialMasterGuide ;                      // master guide initiale eventuelle
 CATFrFCompositeCurve      * _InitialMasterProfile ;                    // master profile initial eventuel

 const CATBody             * _CenterBody ;                              // Body courbe centre definitif
 const CATBody             * _InitialCenterBody ;                       // body centre initial
 CATBoolean                  _UseCenterBody ;
 int                         _IsClosedOldMode;

 // Analyse
 // -------
 int                         ____________________MileStone_Analysis;
 CATBoolean                  _UnspecSweepType ;
 CATBoolean                  _BiRailSweepType ;
 CATBoolean                  _CanonicProfileSweepType ;
 int                         _NbGeomProfiles ;
 int                         _NbGeomSurfaces ;                          // Nb Surfaces dans section geometrique
 CATBoolean                  _NonPlanarAndNonC1Spine;                   // Pour le sweep unspec
 CATBoolean                  _NonPlanarAndNonC1SpineDifferedWarning;    // Pour le sweep unspec
 int                         _SpineContinuityToCheck ;
 int                         _SpineContinuityErrorNotToRaise ;
 int                         _SpineContinuityIsOk ;
 int                         _SpineContinuityWarningRaised ;
 CATListOfDouble             _KOCheckMFPlaneParameters ;


 // Gestion de données
 // ------------------
 int                         ____________________MileStone_DataManagement;
 CATExtruderBySweep_CATListOfCATSurface
                             _LockedSurfaces ;
 CATListPV                   _CCVToDelete ;                             // CCVs a detruire
 CATListPV                   _UsedExtrudedSweepSurfaces ;               // ExtrudedSweepSurfaces utilisees dans topologie finale
 CATListOfInt                _UsedExtrudedSweepSurfacesNumGuide ;
 CATListOfInt                _UsedExtrudedSweepSurfacesNumProfile ;

 // Etat
 // ----
 int                         ____________________MileStone_State;
 int                         _CurrentSweep ;                            // Numero du Sweep courant
 CATBoolean                  _ReadyForRun ;
 CATBoolean                  _RunDone ;                                 // Indique si run du sweep fait
 CATBoolean                  _RunKO ;                                   // Indique si run du sweep fait mais KO
 CATBoolean                  _MasterProfileToChange ;
 CATBoolean                  _MasterGuideToChange ;
 int                         _CreatingTopSurfaces ;
 int                         _CreatingParallelSurfaces ;


 int                         ____________________MileStone_Others;
 CATFrFCompositeCurve      * _NewMasterGuide ;                          // nouvelle master guide eventuelle
 CATFrFCompositeCurve      * _NewMasterProfile ;                        // nouveau master profile eventuel
 CATFrFCompositeCurve      * _Initial3DMasterFromInitalCenterBody ;     // master guide d'apres _InitialCenterBody
 CATFrFCompositeCurve      * _ImposedExtrapolatedMasterGuide ;          // ccv extrapolée imposée

 CATFrFCompositeCurve      * _CCVForDiagnosisAid ;                      // ccv a utiliser pour aide au diagnostic

 const CATBody             * _ProfileBody ;                             // Body profil definitif

 CATMathAxis                 _ProfileAxis ;                             // triedre de positionnement du profil

 // Données et résultats d'extrapolation
 // ------------------------------------
 int                         ____________________MileStone_C0;
 double                      _ImposedExtrapolation ;                    // extrapolation imposée (pour debug)
 int                         _UseImposedExtrapolation ;                 // indique si on utilise l'extrapolation imposée
 CATListPV                   _ComputedC0Vertices;
 CATListPV                   _ComputedC0EdgesToExtrapolate;
 CATExtruderBySweep_CATListOfCATCrvLimits
                             _ComputedC0EdgesLimits;
 int                         _SavedExtrapolationResults;
 CATListOfInt                _ExtrapolatedConnexions;
 int                         _ExtrapolatedConnexionsNbMax;              // nombre max de connexions dans la CCV au moment du calcul
 int                         _DebugForceAllC0VerticesOnCenter;
 int                         _DebugForceNoC0VerticesOnCenter;

 int                         ____________________MileStone_Debug;
 int                         _NumPtComputeExtrapolation ;               // (pour facilites de debug)
 int                         _NumPtComputeExtrapolationForBreak ;       // (pour facilites de debug)

 // --------------------------------------------------------------------------------------------------
 int                         ____________________MileStone_Mem;
 // Variables de mémorisation/optimisation de GetDeriv()
 // ----------------------------------------------------
 int                         _GetDerivLastAvailable;
 CATSurface                * _GetDerivLastSupport;
 CATSurParam                 _GetDerivLastLocationOnSupport;
 CATMathDirection            _GetDerivLastDirection;

 // Variables de memorisation de differents Sweeps.
 // ----------------------------------------------
 // pour maintien du GetLambda recursif au cas ou il devrait resservir
 // mais au 10 07 98, pas de memorisation necessaire
 int                         _NbGuideMem ;                              // Nombre de guides memorises
 CATExtruderBySweep_CATListOfCATCurve
                             _GuideMem   ;                              // Guides memorises
 // (CATListPV: liste de pointeurs void*: pointeurs quelconques)
 CATListPV                   _GeomSweepMem ;                            // Sweeps memorises

} ;

  //-------------------------------------------------------------------------
  // methode statique externe indiquant si on est logiquement dans un cas d'extrapolation C0 potentiel
  // (independamment de la nature C0 de la spine)
  //-------------------------------------------------------------------------
  // NLD021020 inutile ici  extern "C" 
             int  CATExtruderBySweep_C0ExtrapolationCandidate(int                         iCGMLevel,
                                                              CATGeneralizedSweepSurface* iGeomSweep,
                                                              int                         iNbGuides
                                                             );

#endif
