// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
//
// CATSweep2:
// Private operator for sweep with interfering discontinuities
//
//=============================================================================
// Usage notes : Private use
//=============================================================================
// XX/XX/XX ALM Creation
// 12/01/06 NLD Ajout SetTwistReduction() GetTwistReduction() pour eviter
//              aux appelants de passer directement par CATSweep
// 08/12/09 NLD Definition d'une nomenclature pour les classes utilitaires du sweep, la plupart exportees
//              SpecCell  devient CATSweepSpecCell
//              Tableau   devient CATSweepArrayOfSpecCell
//              Spec      devient CATSweepSpec
//              Brep      devient CATSweepBRep
//              BrepCell  devient CATSweepBRepCell
//              Journal   devient CATSweepJournal
// 04/02/11 ky1 Ajout RunOperator()
// 24/06/11 NLD Reformatage
// 18/07/11 NLD SmartHeaderEdition: Reformatage complet
// 08/01/13 G5S Remove arguments that set the side and intersection number from SetLimit for compatibility
//              with the same change to CATSweep.
// 01/10/14 NLD New output argument oError for MLK management in ReportImpact()
// 31/07/17 NLD Reformatage V2
// 06/11/18 NLD Ajout GetRibbon()
// 16/03/20 NLD Ajout RunOperatorDisc()
//=============================================================================

#ifndef CATSWEEP2_H
#define CATSWEEP2_H
//=============================================================================
// ALGO OPTIONS
//=============================================================================

//=============================================================================
// DEBUG OPTIONS
//=============================================================================

//=============================================================================
// INCLUDES
#include "BO0SWEEP.h"
// Lists
#include "CATListOfCATSurfaces.h"
#include "CATListOfCATSurParams.h" 
#include "ListPOfCATVertex.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATCell.h"
#include "ListPOfCATDomain.h"
#include "CATListPV.h"
#include "CATListOfInt.h"
// Mathematics
#include "CATBoolean.h"
// Geometry
// Topology
#include "CATTopData.h"
#include "CATTopOperator.h"
#include "CATSweepLimit.h"
//=============================================================================

//=============================================================================
// CLASSES
class CATMathPlane;
class CATGeoFactory;
class CATGeometry;
class CATBody;
class CATDomain;
class CATShell;
class CATWire;
class CATEdge;
class CATCGMJournalList;
class CATCurve;
class CATPCurve;
class CATSurLimits;
class CATCrvLimits;
class CATCrvParam;
class CATTopologicalOperator;
class CATTopBooleanOperator;
class CATPGMExtruder;
class CATSweep;
class CATSweepBRep;
class CATSweepSpec;
class CATSweep2Body;
class CATSweep2Shell;
class CATSweep2Parallel;
class CATSweep2Ribbon;
class CATSweep2MarchingInit;
class CATSweep2EdgeInfo;
class CATSweep2FaceInfo;
class CATSweep2FaceFaceInterResult;
class CATSweep2MarchingEdge;
class CATSweep2TransferInfo;
class CATSweep2TransferOnEdgeInfo;
class CATError;
//=============================================================================


class ExportedByBO0SWEEP CATSweep2 : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATSweep2);
public:
//=============================================================================
// Methods
//=============================================================================

                              CATSweep2                        (      CATGeoFactory        *  iGeoFactory          ,
                                                                      CATTopData           *  iTopData             ,
                                                                      CATBody              *  iProfBody            ,
                                                                      CATBody              *  iCntBody             ,
                                                                      CATPGMExtruder       *  iExtruder            );

                             ~CATSweep2                        ();

          int                Run                               ();

          CATSweep         * GetSweepOperator                  ();

          CATBody          * GetResult                         ();

          void               SetDiscontinuityTreatment         (      CATLONG32               iMode                = 0);

          void               SetCuspTreatment                  (      CATLONG32               iMode                = 0);

          //----------------------------------------------------------------------
          // >>> METHODES SPECIFIQUES DE CATSWEEP, TRANSMISES DIRECTEMENT A _SWEEP
          //  CATBody      * GetProfile();
          //  CATBody      * GetCenter();

          CATBoolean         InvariantResult                   ();

          CATBody          * GetBooleanResult                  ();

          CATCGMJournalList* GetBooleanTopReport               ();

          void               UnsetCheckTopoTwist               (      CATBoolean              iUnsetCheckTopoTwist = CATBoolean(1));

          void               SetOldShapeRequested              ();

          void               SetRelimitationMode               (      short                   iMode                ,
                                                                      short                   iAutomaticDirectionInversion = 1);

          void               SetReversePolarity                (      CATBoolean              iPolarity            );

          void               GetReversePolarity                (      CATBoolean            & oPolarity            );

          void               SetSimplification                 (      CATBoolean              iSimplify            );

          void               SetFreezeMode                     (      CATBoolean              iFreezeMode          );

          void               SetLimit                          (      CATLimit                iId                  ,
                                                                      CATLimitType            iType                ,
                                                                      CATBoolean              iIsAxisReverted      ,
                                                                      CATLength               iOffset              ,
                                                                      CATGeometry          *  iLimit               ,
                                                                      CATBody              *  iPropagationBody     ,
                                                                      CATPropagationType      iPropagationFlag     ,
                                                                      CATBoolean              iIsThickness         );

          void               SetLimit                          (      CATLimit                iId                  ,
                                                                      CATLimitType            iType                ,
                                                                      CATBoolean              iIsAxisReverted      ,
                                                                      CATLength               iOffset              ,
                                                                      ListPOfCATCell        & iLimit               ,
                                                                      CATBody              *  iPropagationBody     ,
                                                                      CATPropagationType      iPropagationFlag     ,
                                                                      CATBoolean              iIsThickness         );

          void               SetVirtualBoolean                 ();

          void               SetBothResult                     ();

          void               SetBoolean                        (      CATBoolType             iBoolType            ,
                                                                      CATBody              *  iTrimBody            );

          void               SetProfileClosure                 (      CATBoolean              iToClose             ,
                                                                      CATBody              *  iTrimBody            );

          void               SetThinSolidMode                  (const CATBoolean              iThinSolidMode       ,
                                                                const CATBoolean              iIsNeutralFiber      ,
                                                                const double                  iThinSolidThickness[2],
                                                                      ListPOfCATDomain     *  iWireListWithReverseThinSolidSide);

          void               SetRefPlane                       (      CATMathPlane          & iRefPlane            );

          CATBoolean         IsBothResult                      ();

          void               SetTwistReduction                 (      CATBoolean              iTwistReduction      = 0);

          void               GetTwistReduction                 (      CATBoolean            & oTwistReduction      ) ;

  // <<< METHODES SPECIFIQUES DE CATSWEEP, TRANSMISES DIRECTEMENT A _SWEEP
  //----------------------------------------------------------------------


  //KY1 : 04-02-2011
  /**  @nodoc @nocgmitf*/
  static const  CATString  * GetDefaultOperatorId              ();

protected:

//=============================================================================
// CGMReplay Services
//=============================================================================
  //KY1 : 04-02-2011
  /**  @nodoc*/
          int                RunOperator                       ();

  /**  @nodoc @nocgmitf */
  const   CATString        * GetOperatorId                     ();

  /**  @nodoc @nocgmitf */
          void               RequireDefinitionOfInputAndOutputObjects();

//=============================================================================
// Methods
//=============================================================================

          //=======
          // Data
          //=======
          void               ConstructorInit                   (      CATGeoFactory        *  iGeoFactory          ,
                                                                      CATBody              *  iProfBody            ,
                                                                      CATBody              *  iCntBody             ,
                                                                      CATPGMExtruder       *  iExtruder            );

          void               PointersInit                      ();

          //=====================
          // Assembly preparing
          //=====================
          void               ComputeDataForAssembly            ();

          void               InitDataForAssembly               ();

          void               DegeneratedCellsManagement        ();

          void               LoopsClosure                      ();

          void               ReportOnEdge                      (      CATLONG32               iEdgeIndex           ,
                                                                      CATEdge              *  iEdge                ,
                                                                      CATShell             *  iShell               );

          void               InitDataForReport                 ();

          void               ParallelsCreation                 (      CATShell             *& oShellFromSweep      );

          void               RibbonsCreation                   (      CATShell             *  iShellFromSweep      ,
                                                                      CATShell             *  ioNewShell           );

          void               SurfaceSharing                    ();

          void               Sweep2ShellsCreation              ();

          //===========
          // Assembly 
          //===========
          void               Assembly                          ();

          void               RunOperatorDisc                   (      CATError             *& oError               );

          // New edges computing
          //--------------------
          // - init
          CATBoolean         TestForComputationOnClosureAddition(     CATLONG32               iSide                ,
                                                                      CATSweep2Ribbon      *  iRibbon1             ,
                                                                      CATSweep2Ribbon      *  iRibbon2             );

          void               ComputeBodiesIndicesForClosureAddition(  CATLONG32               iSide                ,
                                                                      CATLONG32             & oIndex1              ,
                                                                      CATLONG32             & oIndex2              );

          CATLONG32          ComputeInitBodyIndexForAddition   (      CATSweep2Ribbon      *  iRibbon              ,
                                                                      CATLONG32               iParallelIndex       ,
                                                                      CATLONG32             & oMatterOnInit        );

          CATSweep2MarchingInit * ComputeInitForAddition       (      CATSweep2Ribbon      *  iRibbon1             ,
                                                                      CATSweep2Ribbon      *  iRibbon2             ,
                                                                      CATLONG32               iParallelIndex       ,
                                                                      CATLONG32               iMatterOnInit        );
          // - edge computing
          void               AppendNewEdgeAndFollowingEdges    (      CATSweep2FaceFaceInterResult *  iResults     ,
                                                                      CATLONG32               iIndex               ,
                                                                      CATPCurve            *  iPCurve1             ,
                                                                      CATPCurve            *  iPCurve2             ,
                                                                      CATSweep2MarchingInit*& ioRealInit           ,
                                                                      CATEdge              *  iEdge                ,
                                                                      CATLONG32               iEdgeOrientation     ,
                                                                      CATVertex            *  iInitVertex          ,
                                                                      CATVertex            *  iExitVertex          );

          int                CheckNewEdge                      (      CATMathPoint         *  iInitPoint           ,
                                                                      CATEdge              *  iEdge                ,
                                                                      CATLONG32               iOrientation         ,
                                                                      CATVertex            *& oInitVertex          ,
                                                                      CATVertex            *& oExitVertex          );

          void               ComputeRescueSurParamFromMeridianIntersection
                                                               (      CATSweep2MarchingInit*  iVirtualInit         ,
                                                                      CATPCurve            *  iMeridian1           ,
                                                                      CATCrvLimits         *  iMeridianLimits1     ,
                                                                      CATPCurve            *  iMeridian2           ,
                                                                      CATCrvLimits         *  iMeridianLimits2     ,
                                                                      CATLONG32             & oRescueParallelNumber,
                                                                      CATSurParam          *& oRescueLocalSurParam ,
                                                                      CATSurParam          *& oRescueOtherSurParam );

          void               ComputeRescueSurParam             (      CATSweep2MarchingInit*  iVirtualInit         ,
                                                                      CATLONG32             & oRescueParallelNumber,
                                                                      CATSurParam          *& oRescueLocalSurParam ,
                                                                      CATSurParam          *& oRescueOtherSurParam );

          void               ComputeEdgesAndRealInits          (      CATSweep2MarchingInit*  iVirtualInit         ,
                                                                      CATEdge              *& oEdge                ,
                                                                      CATVertex            *& oExitVertex          ,
                                                                      CATSweep2MarchingInit*& oRealInit            );
          // - exit analysis and init computing
          // --- exit vertex analysis
          void               GettingEdgesForVertexCuttingOnVertex(    CATVertex            *  iVertex              ,
                                                                      CATSweep2Ribbon      *  iRibbon              );

          CATBoolean         BestReportStatusForVertexCuttingOnVertex(CATLONG32               iSide                ,
                                                                      CATSweep2Ribbon      *  iRibbon              ,
                                                                      CATLISTP(CATEdge)    *  iShellEdges          ,
                                                                      CATListPV            *  iShellEdgeInfos      ,
                                                                      CATBoolean            & oUTurnPossible       ,
                                                                      CATLONG32             & oBestStatus          );

          void               UpdateOtherFacesListForVertexCuttingOnVertex(CATLONG32           iSide                ,
                                                                      CATVertex            *  iVertex              ,
                                                                      CATFace              *  iFace                ,
                                                                      CATSweep2Ribbon      *  iRibbon              ,
                                                                      CATBoolean              iCuspDetected        );

          void               UpdateLocalFacesListForVertexCuttingOnVertex(CATLONG32           iSide                ,
                                                                      CATVertex            *  iVertex              ,
                                                                      CATFace              *  iFace                ,
                                                                      CATSweep2Ribbon      *  iRibbon              ,
                                                                      CATBoolean              iCuspDetected        );

          CATBoolean         VertexCuttingOnVertexAnalysis     (      CATLONG32               iSide                ,
                                                                      CATVertex            *  iVertex              ,
                                                                      CATFace              *  iFace                ,
                                                                      CATSweep2Ribbon      *  iRibbon              ,
                                                                      CATBoolean              iCuspDetected        );

          CATBoolean         VertexCuttingOnEdgeAnalysis       (      CATLONG32               iSide                ,
                                                                      CATVertex            *  iVertex              ,
                                                                      CATEdge              *  iEdge                ,
                                                                      CATFace              *  iFace                ,
                                                                      CATSweep2Ribbon      *  iRibbon              ,
                                                                      CATBoolean              iCuspDetected        );

          void               VertexLyingOnFaceAnalysis         (      CATLONG32               iSide                ,
                                                                      CATVertex            *  iExitVertex          ,
                                                                      CATSweep2FaceInfo    *  iFaceInfo            ,
                                                                      CATSweep2Ribbon      *  iRibbon              );

          // --- new init computing
          CATBoolean         ReconvergeCurveCurveSolution      (      CATSurface           *  iSurface1            ,
                                                                      CATSurface           *  iSurface2            ,
                                                                const CATSurLimits         *  iSurLimits1          ,
                                                                const CATSurLimits         *  iSurLimits2          ,
                                                                      CATPCurve            *  iPCurve1             ,
                                                                      CATPCurve            *  iPCurve2             ,
                                                                const CATCrvParam           & iCrvParam1           ,
                                                                const CATCrvParam           & iCrvParam2           ,
                                                                      CATSurParam           & oSurParam1           ,
                                                                      CATSurParam           & oSurParam2           );

          CATBoolean         ReconvergeCurveSurfaceSolution    (      CATSurface           *  iSurface             ,
                                                                const CATSurLimits         *  iSurLimits           ,
                                                                      CATCurve             *  iCurve               ,
                                                                      CATSurParam           & ioSurParam           ,
                                                                      CATCrvParam           & ioCrvParam           );

          void               ComputeSurParamsForInit           (      CATSweep2TransferInfo*  iTransferInfo1       ,
                                                                      CATSweep2TransferInfo*  iTransferInfo2       ,
                                                                      CATSurParam           & oSurParam1           ,
                                                                      CATSurParam           & oSurParam2           );

          void               NewInitComputing                  (      CATSweep2MarchingInit*  iInit                ,
                                                                      CATLONG32               iExitStatus          ,
                                                                      CATBoolean            & oRecomputeExitStatus ,
                                                                      CATSweep2MarchingInit*& oNewInit);

          // --- global method
          void               ExitAnalysisAndNewInitComputing   (      CATSweep2MarchingInit*  iInit                ,
                                                                      CATVertex            *  iExitVertex          ,
                                                                      CATLONG32             & oExitStatuts         ,
                                                                      CATSweep2MarchingInit*& oNewInit             );

          // - Global Marching Method
          void               ComputeMarchingInfo();

          // Report 
          //-------
          void               ComputeLyingOn                    (      CATFace              *  iFace                ,
                                                                      CATSweep2MarchingEdge*  iMarchingEdge        ,
                                                                      CATEdge              *& oEdgeUnderMarchingEdge,
                                                                      CATCell              *& oCellUnderInitVertex ,
                                                                      CATCell              *& oCellUnderExitVertex );

          void               AddEdgeToReport                   (      CATSweep2FaceInfo    *  iFaceInfo            ,
                                                                      CATSweep2MarchingEdge*  iMarchingEdge        ,
                                                                      int                     iMarchingEdgeFlag    ,
                                                                      CATEdge              *& ioLastEdgeToReport   ,
                                                                      CATEdge              *  iEdgeToReport        ,
                                                                      CATLISTP(CATEdge)     & ioEdgesToReport      ,
                                                                      CATListPV             & ioTransferOnEdgeInfos,
                                                                      CATLISTP(CATVertex)   & ioVerticesToReport   ,
                                                                      CATLISTP(CATVertex)   & ioVerticesFromEdgesToReport);

          void               AddImpactedCells                  (      CATSweep2FaceInfo    *  iFaceInfo            ,
                                                                      CATSweep2MarchingEdge*  iMarchingEdge        ,
                                                                      CATEdge              *& ioLastEdgeToReport   ,
                                                                      CATEdge              *  iEdgeUnderMarchingEdge,
                                                                      CATCell              *  iCellUnderInitVertex ,
                                                                      CATCell              *  iCellUnderExitVertex ,
                                                                      CATLISTP(CATEdge)     & ioEdgesToReport      ,
                                                                      CATListPV             & ioTransferOnEdgeInfos,
                                                                      CATLISTP(CATVertex)   & ioVerticesToReport   ,
                                                                      CATLISTP(CATVertex)   & ioVerticesFromEdgesToReport);

          void               ComputeCellsListsToReport         (      CATLONG32               iSide                ,
                                                                      CATLISTP(CATVertex)   & ioVerticesToReport   ,
                                                                      CATListPV             & ioTransferOnEdgeInfos);

          void               ReportOnEdge                      (      CATLONG32               iSide                ,
                                                                      CATSweep2TransferOnEdgeInfo *  iTransferOnEdgeInfo,
                                                                      CATLISTP(CATEdge)     & ioOrphanCreatedEdges );

          void               Report                            ();

          void               ReportImpact                      (      CATError             *& oError);

          // Duplication
          //------------
          void               UpdateEdgesListAndJournal         (      CATLISTP(CATEdge)     & iEdgesList           ,
                                                                      CATCGMJournalList    *  iEdgesReport         ,
                                                                      CATCGMJournalList    *  iLocalReport         );

          void               Duplication                       ();

          // Disconnection 
          //--------------
          void               Disconnection                     ();

          void               DisconnectionImpact               ();

          // Selection
          //----------
          void               FacesSelectionAlongDisconnectionForClosure();

          void               FacesSelectionAlongDisconnection  ();

          void               FacesSelectionPropagation         ();

          // Updates
          //--------
          void               UpdateFaceInfoNewStatus           ();

          void               UpdateParallelLimits              ();

          void               UpdateWorkingBody                 ();

          // Cleaning
          //---------
          void               FirstMarchingInfoCleaning         ();

          void               SecondMarchingInfoCleaning        ();

          // Assembly Result
          //----------------
          void               NoDiscontinuityManagement         ();

          void               AssemblyResultComputing           ();

          void               AssemblyResultReportComputing     ();

          void               AssemblyResultSimplification      ();

          void               EndOfAssemblyResult               ();

          //===============
          // Relimitation
          //===============
          void               Relimitation                      ();

          //===========
          // Checking
          //===========
          void               CheckMarchingResult               ();

          //===============
          // Visual Debug
          //===============
          void               VisualDebugC0Bodies               ();

          void               VisualDebugDisconnectingWire      ();

          void               VisualDebugTemporaryBody          ();

          //===============
          // Access
          //===============
          CATSweep2Ribbon *  GetRibbon                         (      CATLONG32               iBodyIndex           ,
                                                                      CATLONG32               iShellIndex          ,
                                                                      CATLONG32               iRibbonIndex         );

//=============================================================================
// Data
//=============================================================================
  // Static data
  // -----------
  // CGMReplay Services
  //KY1 : 04-02-2011
  /**  @nodoc @nocgmitf */
  static  CATString          _OperatorId;

  // Member data
  // -----------
  CATGeoFactory            * _Factory;
  CATGeoFactory            * _IFactory;
  CATTopData                 _Sweep2TopData;
  CATSoftwareConfiguration * _SoftwareConfiguration;

  CATSweep                 * _Sweep;

  CATBody                  * _WorkingBody;
  CATBody                  * _WorkingBodyForDisconnect;
  CATBody                  * _WorkingBodyForVisu;
  CATBody                  * _AssemblyResult;

  CATCGMJournalList        * _GlobalReport;
  int                        _GlobalReportToBeDeleted;
  CATCGMJournalList        * _ReportForSweep;
  CATCGMJournalList        * _InternalReport;
  CATCGMJournalList        * _InputFacesReport;
  CATCGMJournalList        * _FirstParallelEdgesReport;
  CATCGMJournalList        * _LastParallelEdgesReport;
  CATCGMJournalList        * _GlobalFirstMeridianEdgesReport;
  CATCGMJournalList        * _GlobalLastMeridianEdgesReport;
  CATCGMJournalList        * _LocalFirstMeridianEdgesReport;
  CATCGMJournalList        * _LocalLastMeridianEdgesReport;

  CATLISTP(CATFace)          _ExtremityFacesToReport;
  CATLISTP(CATEdge)          _FirstParallelEdges;
  CATLISTP(CATEdge)          _LastParallelEdges;
  CATLISTP(CATEdge)          _GlobalFirstMeridianEdges;
  CATLISTP(CATEdge)          _GlobalLastMeridianEdges;
  CATLISTP(CATEdge)          _LocalFirstMeridianEdges;
  CATLISTP(CATEdge)          _LocalLastMeridianEdges;

  CATTopBooleanOperator    * _BooOpe;

  double                     _Resolution;

  CATLISTP(CATFace)          _ResultLumpsInitFaces;
  CATListPV                  _ResultLumpsShellIndices;
  CATListOfInt               _ResultShellsIndices;
  CATLONG32                  _NbBodies;
  CATLONG32                  _NbSweep2Shells;

  short                    * _ShellOrientation;
  CATLONG32                * _NbRibbons;
  CATLONG32                  _NbParallelsMax;
  CATLONG32                * _NbParallels;
  CATBoolean               * _ProfileIsClosed;
  CATBoolean                 _CenterIsClosed;

  CATBoolean                 _RunFailed;

  CATLONG32               ** _VertexSpecCellIndex;
  CATLONG32               ** _EdgeSpecCellIndex;
  CATSweep2Body           ** _Sweep2Bodies;
  CATSweep2Shell          ** _Sweep2Shells;
  // - to compute data for assembly
  CATBody                 ** _LocalBodiesFromSweep;
  CATSweepBRep            ** _BrepFromSweep;
  CATSweepSpec             * _ProfileSpec;
  CATSweepSpec             * _WorkingCenterSpec;
  CATWire                  * _WorkingCenterWire;
  CATLONG32                  _NbCenterEdges;
  CATLISTP(CATCell)          _RemovedCells;
  CATLISTP(CATCell)          _ReplacingCells;
  CATSweep2Parallel       ** _Parallels;
  CATSweep2Ribbon         ** _Ribbons;
  CATLISTP(CATEdge)        * _EdgeLists;
  CATListPV                * _EdgeInfosLists;
  CATLISTP(CATSurface)       _Surfaces;
  CATListPV                  _ShellIndicesLists;
  CATListPV                  _RibbonIndicesLists;
  // - for assembly
  CATLONG32                  _BodyIndex;
  CATLONG32                  _NewBodyIndex;
  CATLONG32                  _Sweep2ShellIndex;
  CATLONG32                  _RibbonIndex;
  CATBoolean                 _SweepClosure;
  CATLISTP(CATEdge)        * _OrphanCreatedEdges             [2];
  CATListPV                * _OrphanCreatedEdgeInits         [2];
  CATListOfInt             * _OrphanCreatedEdgeOrientations  [2];
  CATListPV                * _AfterReportMarchingEdges;
  CATListOfInt             * _AfterReportMarchingEdgesStatus;
  CATListPV                * _AfterReportMarchingVirtualInits;
  CATListPV                * _AllMarchingInits;
  CATListPV                * _AllMarchingEdges;
  CATListPV                * _SelectedMarchingInits;
  CATListPV                * _SelectedMarchingEdges;
  CATLISTP(CATFace)          _DisconnectedFaces;
  CATListPV                  _DisconnectedFaceInfos;
  CATLISTP(CATEdge)        * _NewEdges;
  CATListPV                * _NewEdgeInfos;
  CATListPV                  _InputFaceInfosImpacted;
  CATLISTP(CATFace)          _DestroyedFaces;
  CATListPV                  _DestroyedFaceInfos;
  CATLISTP(CATFace)          _ImpactedFaces;
  CATListPV                  _ImpactedFaceInfos;
  CATLISTP(CATEdge)          _DestroyedEdges;
  CATListPV                  _DestroyedEdgeInfos;
  CATLISTP(CATEdge)          _ImpactedEdges;
  CATListPV                  _ImpactedEdgeInfos;
  CATLISTP(CATVertex)        _NewEdgesVertices;
  CATListOfInt               _NewEdgesVerticesStatus;
  // --- Exit study
  CATLISTP(CATEdge)          _LocalShellEdges;
  CATLISTP(CATEdge)          _OtherShellsEdges;
  CATListPV                  _LocalShellEdgeInfos;
  CATListPV                  _OtherShellsEdgeInfos;
  CATListPV                  _NewFaceInfos[2];
  CATListPV                  _SecondNewFaceInfos;
  CATListPV                  _NewTransferInfos[2];
  CATListPV                  _SecondNewTransferInfos;
  /**
   * Valeurs possibles pour _NewReportType
   *
   *   1 : report sur Face,
   *   2 : report sur Edge,
   *   3 : report sur Vertex.
   */
  // --- Disconnection
  CATListOfInt              _ImpactedShellsAlongDisconnection[2];
  CATListPV                 _NewFaceInfosAlongDisconnection  [2];
  CATLONG32               * _BodyIndexMin;
  /**
   * Valeurs possibles pour _ReportStatus :
   *
   * -10 - n : on change de ruban en traversant le n ieme parallele - en
   *           changeant de shell.
   *      -2 : on change de shell en plein ruban (nouvel init multiple),
   *       0 : fin de la decoupe. 
   *       1 : on reste sur la meme face : pas de report via une edge,
   *       2 : on change de face a l'interieur du meme ruban,
   *  10 + n : on change de ruban en traversant le n ieme parallele - sans
   *           changer de shell.
   */
  CATLONG32                _ReportStatus[2];
  // - for the macros
  CATLONG32                _CallLevel;
  CATLONG32                _Count;
};

#endif
