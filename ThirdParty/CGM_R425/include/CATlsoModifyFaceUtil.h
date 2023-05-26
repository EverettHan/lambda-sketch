#ifndef CATlsoModifyFaceUtil_H
#define CATlsoModifyFaceUtil_H

// ++++ Includes ++++
#include "AdvTrimOpe.h"
#include "ListPOfCATPersistentFaces.h"
#include "ListPOfCATFace.h"
#include "CATBoolean.h"
#include "ListPOfCATBody.h"
#include "ListPOfCATPersistentBodies.h"
#include "ListPOfCATDomain.h"
#include "CATTopDefine.h"
#include "IUnknown.h" // For HRESULT
#include "ListPOfCATCell.h"
#include "ListPOfCATPersistentCells.h"
#include "ListPOfCATEdge.h"
#include "CATHybDef.h"
#include "CATDynOperatorDef.h"
#include "CATMathDef.h"
#include "ListPOfListPOfCATEdge.h"
#include "CATMathAxis.h"
#include "CATListOfCATCGMJournals.h"

#include "CATPGMCreateTopAssemble.h"

// ++++ Predeclarations ++++
class CATLiveBody;
class CATGMBaseInfra;
class CATPersistentCellInfra;
class CATPersistentBody;
class CATCGMJournalList;
class CATVertex;
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATlsoContext;
class CATlsoPersistentContext;
class CATMathVector;
class CATFace;
class CATSurParam;
class CATPersistentFace;
class CATSurface;
class CATCellHashTable;
class CATMathTransformation;
class CATMathPlane;
class CATFaceHashTable;
class CATMathOBB;
class CATMathOBBCloud;


//=============================================================================
// CATlsoModifyFaceUtil
// 
// responsable: LAP
// 
// Classe utilitaire pour l'operateur ModifyFace. Elle ne contient que des methodes
// statiques.
//=============================================================================

class ExportedByAdvTrimOpe CATlsoModifyFaceUtil
{
public:
  //---------------------------------------------------------------------------
  // METHODES STATIC
  //---------------------------------------------------------------------------
  static void CreatedAndAddPersistentFace(CATPersistentCellInfra    & iPersistentInfra,
                                          CATLiveBody               & iLiveBody,
                                          ListPOfCATFace            & iInputFaceList,
                                          ListPOfCATPersistentFaces & oPersistentInputFaceList);
  
  static void CreatedAndAddPersistentFace(CATPersistentCellInfra    & iPersistentInfra,
                                          CATPersistentBody         & iPersistentBody,
                                          ListPOfCATFace            & iInputFaceList,
                                          ListPOfCATPersistentFaces & oPersistentInputFaceList);

  static void ComputePersistentFaceListWithoutRepresentation(CATPersistentCellInfra    & iPersistentInfra,
                                          CATPersistentBody         * iPeristentBody,
                                          ListPOfCATPersistentFaces & iPersistentFaceList,
                                          ListPOfCATPersistentFaces & oPersistentFaceWithoutRepList);

  static void ComputeModifiedInputFaces(CATCGMJournalList & iJournal,
                                        ListPOfCATFace    & oModifiedInputFaceList,
                                        ListPOfCATFace    & oModifiedResultFaceList,  // the second list is parallel to the first one.
                                        CATBoolean          iIgnoreAbsorption=FALSE);

  static CATMathVector ComputeNormalVsShell(CATFace      & iFace, 
                                            CATBody      & iBody,
                                            CATSurParam  * iParam=NULL);

  static CATOrientation ComputeOrientationFaceVsShell(CATFace & iFace,
                                                      CATBody & iBody);

  // if iFace==NULL, takes 1st face from iBody.GetAllCells()
  static CATOrientation ComputeOrientationFaceVsShell(CATBody * iBody,
                                                      CATFace *iFace=NULL);

  static CATOrientation ComputeOrientationSurfaceVsShell(CATFace & iFace,
                                                         CATBody & iBody);

  static CATOrientation ComputeOrientationSurfaceVsShell(CATPersistentFace       * iPersistentFace,
                                                         CATPersistentBody       * iPersistentBody,
                                                         CATlsoPersistentContext & iContext);

  static CATSurface * GetSurfaceFromPersistentFace(CATPersistentFace       * iPersistentFace,
                                                   CATPersistentBody       * iPersistentBody,
                                                   CATlsoPersistentContext & iContext);
  // ------------------
  // Boolean operators
  // ------------------
  // Call DynBoolean operator
  static CATPersistentBody * CallNewBooleanUnion(CATPersistentBody       * iPersistentBody1,
                                                 CATPersistentBody       * iPersistentBody2,
                                                 CATlsoPersistentContext & iContext,
                                                 CATBoolean                iSimplif=TRUE,
                                                 CATCGMJournalList       * oReportJournal=NULL,
                                                 CATBoolean                iLiveBodyAllowed=FALSE);

  // deprecated
  static CATPersistentBody * CallBooleanUnion(CATPersistentBody       * iPersistentBody1,
                                              CATPersistentBody       * iPersistentBody2,
                                              CATlsoPersistentContext & iContext);

  // Remove iPeristentBody2 from iPeristentBody1
  // Call DynBoolean operator
  static CATPersistentBody * CallNewBooleanDiff(CATPersistentBody     * iPersistentBody1,
                                                CATPersistentBody       * iPersistentBody2,
                                                CATlsoPersistentContext & iContext,
                                                CATBoolean                iSimplif=TRUE,
                                                CATCGMJournalList       * oReportJournal=NULL);

  // Remove iBody2 from iBody1 (version w. CATBody as inputs)
  // Call DynBoolean operator
  static CATBody * CallNewBooleanDiff(CATBody						* iBody1,
                                      CATBody						* iBody2,
                                      CATlsoContext		  * iContext,
                                      CATGMBaseInfra		& iBaseInfra,
                                      CATBoolean					iSimplif=FALSE,
                                      CATCGMJournalList * oReportJournal=NULL);

  // deprecated
  static CATPersistentBody * CallBooleanDiff(CATPersistentBody       * iPersistentBody1,
                                             CATPersistentBody       * iPersistentBody2,
                                             CATlsoPersistentContext & iContext,
                                             CATCGMJournalList       * oReportJournal=NULL);

  static CATPersistentBody * CallSplitShell(CATPersistentBody       * iPersistentBodyToSplit,
                                             CATPersistentBody       * iPersistentSplittingBody,
                                             CATHybSelectionMode       iSelectionMode,
                                             CATlsoPersistentContext & iContext,
                                             CATBoolean                iPersistentFaceCreation=FALSE,
                                             CATHybExtrapolationMode   iExtrapolationMode=NO_EXTRAPOLATION,
                                             double                  * iTolerance=NULL,
                                             CATCGMJournalList       * oReportJournal=NULL);

  static CATPersistentBody * CallHybSplit   (CATPersistentBody       * iPersistentBodyToSplit,
                                             CATPersistentBody       * iPersistentSplittingBody,
                                             CATlsoPersistentContext & iContext,
                                             const CATLISTP(CATCell) & iCellsToRemove,
                                             const CATLISTP(CATCell) & iCellsToKeep,                                             
                                             double                  * iTolerance=NULL,
                                             CATCGMJournalList       * oReportJournal=NULL);

  static CATPersistentBody * CallSplitVolume(CATPersistentBody       * iPersistentBodyToSplit,
                                               CATPersistentBody       * iPersistentSplittingBody,
                                               CATDynSplitType           iSplitType,
                                               CATlsoPersistentContext & iContext,
                                               CATBoolean                iPersistentFaceCreation=FALSE);

  static CATBoolean CallIsIntersecting(CATPersistentBody       * iPersistentBody1,
                                       CATPersistentBody       * iPersistentBody2,
                                       CATlsoPersistentContext & iContext);

  static CATBoolean CallIsIntersecting(CATGeoFactory * iFactory,
                                       CATSoftwareConfiguration * iConfig,
                                       CATBody       * iBody1,
                                       CATBody       * iBody2);

  static CATPersistentBody * CallIntersect (CATPersistentBody       * iPersistentBody1,
                                           CATPersistentBody       * iPersistentBody2,
                                           CATlsoPersistentContext & iContext,
                                           CATCGMJournalList * oReportJournal=0,
                                           CATBoolean iCreateManifolds=FALSE);

  static CATPersistentBody * CallLayDown  (CATPersistentBody       * iPersistentBodyToLayDown,
                                           CATPersistentBody       * iPersistentBodySupport,
                                           CATlsoPersistentContext & iPersistentContext,
                                           CATCGMJournalList       * oReportJournal=0,
                                           double                  * iTolerance=NULL);


  static CATPersistentBody * CallSmartProject  (CATPersistentBody       * iPersistentBodyToProject,
                                                CATPersistentBody       * iPersistentBodySupport,
                                                CATlsoPersistentContext & iPersistentContext,
                                                CATMathDirection        * iDirection=0,
                                                CATCGMJournalList       * oReportJournal=0,
                                                double                  * iMaxDistance=NULL,
                                                CATBoolean                iRethrowError=FALSE,
                                                short                     iExtrapolationMode=0);

  static CATPersistentBody * CallHybProject  (CATPersistentBody       * iPersistentBodyToProject,
                                                CATPersistentBody       * iPersistentBodySupport,
                                                CATlsoPersistentContext & iPersistentContext,
                                                CATMathDirection        * iDirection=0,
                                                CATCGMJournalList       * oReportJournal=0,
                                                double                  * iTolerance=NULL);

  static CATPersistentBody * CallDisconnect(CATPersistentBody      * iPBodyToDisconnect,
                                            CATPersistentBody      * iDisconnectingPBody,
                                            CATlsoPersistentContext & iPersistentContext,
                                            CATCGMJournalList       * oReportJournal=0);



  static CATBoolean CallClashFound(CATBody  *iBody1, CATBody  *iBody2, CATlsoPersistentContext & iContext, CATCGMJournalList * oReportJournal=0);

  static CATBoolean CallClashFound(const CATPersistentBody       * iPersistentBody1,
                                   const CATPersistentBody       * iPersistentBody2,
                                   CATlsoPersistentContext & iContext);

  static CATPersistentBody * CallCloseOperator(CATPersistentBody       * iPersistentBodyToClose,
                                               CATlsoPersistentContext & iContext,
                                               CATCGMJournalList       * oReportJournal = NULL);

  static CATPersistentBody * CallRelimitByVolume(CATPersistentBody * iVolumicBody,
                                                 CATPersistentBody * iSurfacicPBody,
                                                 CATLONG32           iSelectionType,
                                                 CATlsoPersistentContext & iContext,
                                                 CATCGMJournalList *oReportJournal=NULL);

  static CATPersistentBody * CallSew(CATPersistentBody       * iSupportPBody,
                                     CATPersistentBody       * iSurfacicPBody,
                                     CATBoolean                iSimplification,
                                     CATlsoPersistentContext & iContext);

  
  static CATPersistentBody * CallAssembleShell ( CATPersistentBody       * iPersistentBody1,
                                                 CATPersistentBody       * iPersistentBody2,
                                                 CATlsoPersistentContext & iContext,
                                                 CATBoolean                iSetSimplify=FALSE,
                                                 double                  * iTolerance=NULL);

  static CATPersistentBody * CallAssembleShell ( const ListPOfCATPersistentBodies & iInputPersistentBodyList,
                                                 CATlsoPersistentContext          & iContext,
                                                 CATBoolean                         iSetSimplify=FALSE,
                                                 double                           * iTolerance=NULL);

  // Note : Call CATHybNewAssemble
  //        Peut n'avoir qu'un body en entrée. Auquel cas, les shells seront simplifiés et un plusieurs volumes créés.
  //        Tres utilile pour fermer des bodies multi-shell non simplifiés.
  static CATBody          * CallAssembleShell  (ListPOfCATBody &iInputBodies, 
                                                CATlsoPersistentContext &iContext, 
                                                CATBoolean iSetSimplify=TRUE, 
                                                CATBoolean iVolumeCreation=TRUE);

  // Calling phase II interface of TopAssemble + Simplify
  static CATPersistentBody * CallNewTopAssemble(CATGeoFactory                    * iFactory,
                                                CATlsoPersistentContext          & iContext,
                                                CATTopData                       * iData,
                                                const ListPOfCATPersistentBodies & iPBodiesToAssemble,
                                                int                                iSimplifyModeForNoChange=2);

  static CATPersistentBody * CallTrimShell ( CATPersistentBody      * iPersistentBody1,
                                            CATPersistentBody       * iPersistentBody2,
                                            CATlsoPersistentContext & iContext,
                                            CATBoolean                iSetSimplify=TRUE,
                                            CATHybSelectionMode       iSelectionMode=BOTH_SIDES);

  // ------------------------------------------------
  // CATThick
  // ------------------------------------------------
  static CATPersistentBody * CallThick(CATPersistentBody        * iPersistentBody,
                                        CATlsoPersistentContext & iPersistentContext,
                                        const ListPOfCATFace    & iFaceList,
                                        const double              iOffsetValue,
                                        CATCGMJournalList       * ioReportJournal = NULL);
                                        

  // ------------------------------------------------
  // RemoveFace
  // ------------------------------------------------
  static CATPersistentBody * CallRemoveFace(CATPersistentBody         * iPersistentBody,
                                            ListPOfCATPersistentFaces & iPersistentFacesToRemove,
                                            CATlsoPersistentContext   & iContext,
                                            ListPOfCATFace            * iFacesToRemove=NULL,
                                            short                       iPartialRemoveFaceAllowed=0);

  static CATPersistentBody* CallRemoveFaceWithTwistDetection (CATPersistentBody*         iPersistentBody,
                                                              ListPOfCATPersistentFaces& iPersistentFacesToRemove,
                                                              CATlsoPersistentContext&   iContext,
                                                              ListPOfCATFace*            iFacesToRemove = NULL,
                                                              short                      iPartialRemoveFaceAllowed = 0);

  static CATPersistentBody * CallRemoveFacesInShell(CATPersistentBody        * iPersistentBody,
                                                   ListPOfCATPersistentFaces & iPersistentFacesToRemove,
                                                   CATlsoPersistentContext   & iContext,
                                                   ListPOfCATFace            * iFacesToRemove=NULL,
                                                   CATBoolean                  iUsingOrientationOFF = FALSE);

  static CATBody           * CallRemoveFacesInShell(CATBody                  * iBody,
                                                    ListPOfCATFace           & iFacesToRemove,
                                                    CATGeoFactory            * iFactory, 
                                                    CATSoftwareConfiguration * iConfig,
                                                    CATBoolean                 iUsingOrientationOFF = FALSE);

  static CATBody * DetectAndRemoveFacesInCaseOfNeighborLoops(CATSoftwareConfiguration *  iConfig,
                                                             CATGeoFactory            *  iFactory,
                                                             CATBody                  *  iInputBody,
                                                             const CATLISTP(CATFace)   & iListOfFacesToModify,
                                                             CATCGMJournalList        ** oResultJournal = NULL);

  static CATPersistentBody * DetectAndRemoveFacesInCaseOfNeighborLoops(CATPersistentBody         * iPersistBodyInputForRemove,
                                                                        ListPOfCATPersistentFaces & iPersistentFacesToModify,
                                                                        CATlsoPersistentContext   & iContext);

  // Can give of partial result
  static CATPersistentBody * CallRemoveEdgePlus(CATPersistentBody       * iPersistentBody,
                                                const ListPOfCATEdge    & iBorderEdges,
                                                CATlsoPersistentContext * iContext,
                                                ListPOfCATEdge          & oEdgesNotRemoved,
                                                CATBoolean                iPartialResult=TRUE,
                                                CATBoolean                iRethrowError =FALSE);

  static CATPersistentBody * CallMultiBodyMerger (const ListPOfCATPersistentBodies  & iInputPersistentBodyList, 
                                                  CATlsoPersistentContext           * iContext,                                                 
                                                  CATCGMJournalList                 * oOutputOperatorJournal = 0,
                                                  CATBoolean                          iVolumeSimplification = FALSE);

  static CATBody * CallMultiBodyMerger (const ListPOfCATBody        & iInputBodiesToMerge, 
                                        CATlsoPersistentContext     & iContext,                  
                                        CATBoolean                    iCreateManifold = FALSE,
                                        CATCGMJournalList           * oOutputOperatorJournal = 0,
                                        CATBoolean                    iVolumeSimplification = FALSE);

  static CATBody * CallMultiBodyMerger (const ListPOfCATBody        & iInputBodiesToMerge, 
                                        CATlsoContext               & iContext);


  // Appel simplifie du TopCompatible
  // Signature 1 : Merge les resultats dans un seul persistentBody 
  static CATPersistentBody * CallCompatible  (CATlsoPersistentContext & iContext,
                                              CATPersistentBody       * iPersitentBody1,
                                              CATPersistentBody       * iPersitentBody2,
                                              CATCGMJournalList       * oResultJournal = 0);

  // Signature 2 : 
  //  - Return le nombre de resultats
  //  - Donne la liste des persistentBody resultats 
  //  - return (-1) si erreur
  static int CallCompatible (CATlsoPersistentContext      & iContext,
                              CATPersistentBody           * iPersitentBody1,
                              CATPersistentBody           * iPersitentBody2,
                              ListPOfCATPersistentBodies  & oOutputPersistentBodies,
                              CATCGMJournalList           * oResultJournal = 0,
                              CATBoolean                    iCreateManifold = FALSE);

   // Signature 3 : sans persistentInfra
  static CATBody * CallCompatible ( CATSoftwareConfiguration * iConfig,
                              CATGeoFactory            * iFactory,
                              CATBody                  * iBody1,
                              CATBody                  * iBody2,                              
                              CATBoolean                 iCreateManifold = FALSE,
                              CATCGMJournalList        * oResultJournal = 0);


     // Signature 4 : multi result
  static int CallCompatible (CATSoftwareConfiguration   * iConfig,
                              CATGeoFactory             * iFactory,
                              const ListPOfCATBody      & iInputBodyList,
                              ListPOfCATBody            & oOutputBodyList,
                              CATLISTP(CATCGMJournal)   * oOutJournalList = 0);

  // Signature 5 : multi result
  static int CallCompatible (CATlsoPersistentContext     & iContext,
                             const ListPOfCATPersistentBodies & iPersistentBodyList,
                             ListPOfCATPersistentBodies  & oOutputPersistentBodies,
                             CATCGMJournalList           * oResultJournal,
                             CATBoolean                    iCreateManifold);

  // Signature 6 : multi result
  static CATPersistentBody * CallCompatible  (CATlsoPersistentContext    & iContext,
                                              const ListPOfCATPersistentBodies & iPersistentBodyList,
                                              CATCGMJournalList          * oResultJournal = 0);


  // -------------
  // SimplifyFace
  // -------------
  static CATPersistentBody * CallSimplify(CATPersistentBody         * iPersistentBody,
                                          ListPOfCATPersistentFaces & iPersistentFacesToSimplify,
                                          CATlsoPersistentContext   & iContext,
                                          ListPOfCATFace            * iFacesToSimplify=NULL);

  static CATPersistentBody * CallSimplify(CATPersistentBody       * iPersistentBody,
                                        ListPOfCATPersistentCells & iPersistentCellsToSimplify,
                                        CATlsoPersistentContext   & iContext,
                                        ListPOfCATCell            * iCellsToSimplify=NULL);

  static CATPersistentBody * CallSimplifyWithCellsToRemove(CATPersistentBody       * iPersistentBody,
                                                           CATlsoPersistentContext   & iContext,
                                                           ListPOfCATCell            & iCellsToRemove);


  /* Change special mode + no specifying cells to simplify */
  static CATPersistentBody * CallSimplify(CATPersistentBody         * iPersistentBody,
                                          CATlsoPersistentContext   & iContext,
                                          int                         iMode = 0,
                                          ListPOfCATPersistentCells * iPersistentCellsToSimplify = NULL,
                                          ListPOfCATCell            * iCellsToSimplify = NULL);

  // -------------
  // Remove Cells with CATTopSimplify
  // -------------
  static CATPersistentBody * CallSimplifyWithRemoveCells (CATPersistentBody         * iPersistentBody,
                                                          ListPOfCATPersistentCells & iPersistentCellsToErase,
                                                          CATlsoPersistentContext   & iContext,
                                                          ListPOfCATCell            * iCellsToErase=NULL,
                                                          ListPOfCATCell            * iReferenceCells=NULL);

  static CATPersistentBody * CallSimplifyWithRemoveCellsAndGetJournal (CATPersistentBody         * iPersistentBody,
                                                          ListPOfCATPersistentCells & iPersistentCellsToErase,
                                                          CATlsoPersistentContext   & iContext,
                                                          CATCGMJournalList        *& oJournalList,
                                                          ListPOfCATCell            * iCellsToErase=NULL,
                                                          ListPOfCATCell            * iReferenceCells=NULL);

  // ----------------------
  // GeoSimplify
  // ----------------------
  static CATPersistentBody * CallGeoSimplify (CATPersistentBody *iPersistentBody, CATlsoPersistentContext   & iContext);

  // FlexiblePlus
  // ----------------------
  static CATPersistentBody * CallFlexiblePlus (CATPersistentBody         * iPersistentBody, 
                                               ListPOfCATPersistentFaces & iPersistentFaces,
                                               CATMathTransformation     & iMathTransfo,
                                               CATlsoPersistentContext   & iContext,
                                               ListPOfCATFace            * iFaceList=NULL);

  // Fuzzy Extrapol 
  // ( Run with SameInfra option)
  // -----------------------------
  static CATPersistentBody* CallFuzzyExtrapol (CATlsoPersistentContext&  iContext,
                                               CATPersistentBody       * iPersistentBodyToExtrapolate,
                                               CATLength                 iDefaultExtrapolationValue,
                                               const ListPOfCATEdge    * iEdgesToExtrapolate=NULL,
                                               CATBody                 * iUpToTargetBody=NULL,
                                               short                     iRemoveHoleMode=0);


  static CATPersistentBody* CallFuzzyExtrapol (CATlsoPersistentContext       & iContext,
                                                CATPersistentBody            * iPersistentBodyToExtrapolate,
                                                const ListPOfListPOfCATEdge  & iEdgeToExtrapolatePerBody,
                                                const ListPOfCATBody         & iUpToTargetBodies, // parallel to iEdgesToExtrapolate
                                                short                          iRemoveHoleMode=0);



  // -----------------------------------------------------------------------
  // Transfo Manager
  // -----------------------------------------------------------------------
  static int CallTransfoManager(const ListPOfCATPersistentBodies & iInputPersistentBodies,
                                const CATMathTransformation      & iTransformation,
                                const CATlsoPersistentContext    & iContext,
                                ListPOfCATPersistentBodies       & oImageResultPersistentBodies,
                                CATBoolean                         iCreationOrder = FALSE,
                                CATCGMJournalList                * oReportJournalList [] = NULL ); // if set, Tab size must be equal to iInputPersistentBodies.Size()

  // -----------------------
  // InvertShellOrientation
  // -----------------------
  static CATPersistentBody * CallInvertShellOrientation(CATPersistentBody        * iPersistentBody,
                                                        CATlsoPersistentContext  & iContext);

  // -----------------------
  // InvertFaceVsShellOrientation
  // -----------------------
  static CATPersistentBody * InvertFaceVsSurfaceOrientation(CATPersistentBody        * iPersistentBody,
                                                          CATlsoPersistentContext  & iContext);

  static CATBody * CallCloseOperator(CATBody                  * iBodyToClose,
                                     CATSoftwareConfiguration * iConfig,
                                     CATGeoFactory            * iFactory);  

  static CATPersistentBody * CallFillWire(CATPersistentBody       * iWirePersistentBody,
                                          CATlsoPersistentContext & iContext,
                                          CATBoolean                iPowerFillOption=TRUE);


  // -----------------------------------------------------------------
  // Healing Topo
  // -----------------------------------------------------------------
  static CATPersistentBody * CallHealingTopo(CATPersistentBody        * iPersistentBody,
                                              CATlsoPersistentContext & iContext,
                                              CATCGMJournalList       * oReportJournal=NULL);

  // -----------
  // AutoCheck
  // -----------
  // Return isValid
  static CATBoolean CheckResultWithAutoCheck(CATPersistentBody       * iResultPersistentBody,
                                             CATPersistentBody       * iInputPersistentBody,
                                             CATlsoPersistentContext & iContext,
                                             ListPOfCATCell          * oInvalidIntersectionCells = NULL,
                                             int                       iMode=0,
                                             ListPOfCATFace          * iResultFaceListFilter = NULL);

  static CATBoolean CheckResultWithAutoCheck(CATPersistentBody       * iResultPersistentBody,
                                             CATPersistentBody       * iInputPersistentBody,
                                             CATCGMJournalList       * iJournal,
                                             CATlsoPersistentContext & iContext,
                                             ListPOfCATCell         *& oInvalidIntersectionCells,
                                             int                       iMode=0,
                                             ListPOfCATFace          * iResultFaceListFilter = NULL);


  static CATBoolean CheckResultWithAutoCheck(CATPersistentBody       * iResultPersistentBody,
                                             CATPersistentBody       * iInputPersistentBody,
                                             CATlsoPersistentContext & iContext,
                                             ListPOfCATCell          & iCellListToCheck,
                                             ListPOfCATCell          * oInvalidIntersectionCells = NULL);


  // Simple Call to BodyCheckerOpe - Carefull, it can rise Exception ! Use Try - Catch
  // *
  // if iPreviousBody is set : check auto-intersection on all body (dominant option)
  // if iJournalReport is set : check auto-intersection only on modified and created cells
  // if oInvalidCells is set : activate exaustive check and return Intersected invalid cells
  // Return TRUE if result body is valid
  static CATBoolean CallBodyChecker(CATGeoFactory *iFactory, 
                                    CATSoftwareConfiguration * iConfig,
                                    CATBody *iBodyResultToCheck, 
                                    CATBody *iPreviousBody=NULL, 
                                    CATCGMJournalList *iJournalReport=NULL, 
                                    ListPOfCATCell *oInvalidCells=NULL); 
  
  static CATPersistentBody * ComputeBoundingWires(CATPersistentBody * iPersistentBody, CATlsoPersistentContext & iContext);

  static CATBody * CreateBodyFromMathPlane(CATGeoFactory *iFactory, CATSoftwareConfiguration *iConfig, CATMathPlane & iMathPlane, CATBody * iLimitingBody, CATBoolean iExtrapol=FALSE);

  static CATBody * CreateBodyFromMathPlane(CATGeoFactory *iFactory, CATSoftwareConfiguration *iConfig, CATMathPlane & iMathPlane);

  static CATBody * CreateBodyCylinder(CATGeoFactory *iFactory, CATSoftwareConfiguration *iConfig, CATMathAxis & iAxis, double iRadius, CATBody * iLimitingBody);
  
  static CATBoolean IsAlmostProtrusion(const CATLiveBody             *iLiveBody,
                                       const ListPOfCATFace           &iSelectedFaces,
                                       const CATMathTransformation    &UserTransformation,
                                       CATFaceHashTable               &iQuasiPortrusionFaces);

  static CATBody * ComputeBodyFromBoundingBox(CATMathBox & iBox, CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig);

  static CATBody * ComputeBodyFromOBBCloud(CATMathOBBCloud & iOBBCloud, CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig);

  static CATBody * ComputeBodyFromOBB(CATMathOBB & iOBB, CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig);

  static HRESULT ComputeOrientedBoxForBody(CATlsoPersistentContext * iContext,
                                       CATBody                 * iBody,
                                       CATMathOBB              & oOrientedBox,
                                       double                    iScale = 1.0,
                                       double                    iMinthick = 0.);

  private :

  static CATBody * DetectAndRemoveFacesInCaseOfNeighborLoops_v1(CATSoftwareConfiguration *  iConfig,
                                                             CATGeoFactory            *  iFactory,
                                                             CATBody                  *  iInputBody,
                                                             const CATLISTP(CATFace)   & iListOfFacesToModify,
                                                             CATCGMJournalList        ** oResultJournal = NULL);

  
};

#endif /* CATlsoModifyFaceUtil_H */
