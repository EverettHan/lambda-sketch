/* -*-C++-*- */

#ifndef CATlsoTransformFaceResultDomain_H
#define CATlsoTransformFaceResultDomain_H

#include "AdvTrimOpe.h"
#include "CATlsoTransformFaceAlgoElt.h"
#include "CATlsoTransformFaceContext.h"
//#include "CATlsoTransformFaceInputDomain.h"

#include "CATMathTransformation.h"
#include "CATMathInline.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATPersistentVertices.h"
#include "ListPOfCATPersistentEdges.h"
#include "CATlsoRevolPrismData.h"
#include "CATMathVector.h"
#include "CATShell.h"
#include "CATCGMJournalList_sp.h"



class CATlsoTransformFaceInputDomain;
class CATPersistentBody;
class CATTopVManipulate;
class CATCGMJournalList;
class CATBodyInputElementAttribute;
class CATBodyPersistentBodyAttribute;
class CATTopExtrude;

// ------------------
// TopPattern Status
// ------------------
enum CATTopPatternStatus { 
  NOTDEFINED=0,
  FAILED,
  SUCCESSED};

class ExportedByAdvTrimOpe CATlsoTransformFaceResultDomain : public CATlsoTransformFaceAlgoElt
{

public:

  // Constructeur
  CATlsoTransformFaceResultDomain(CATlsoTransformFaceInputDomain * iTFInputDomain,
                                  CATLONG32                        iNumInstance,
                                  CATlsoTransformFaceContext     * iContext);
 
  // Copy-constructeur et affectation (lancent une exception)
  CATlsoTransformFaceResultDomain(CATlsoTransformFaceResultDomain& iOrig);
  CATlsoTransformFaceResultDomain& operator= (const CATlsoTransformFaceResultDomain& iRight);

  //-------------------------------------------------------------------------------------------------------
  // Surcharge du new/delete
  //-------------------------------------------------------------------------------------------------------
  CATCGMNewClassArrayDeclare;
  
  // Destructeur
  ~CATlsoTransformFaceResultDomain();

  // Methode de cast de CATlsoAlgoElt
  CATlsoTransformFaceResultDomain * CastToTransformFaceResultDomain();

  // Balayage de tous les objets de la classe
  static CATlsoTransformFaceResultDomain * Next(CATlsoChainMaster * iAdmin, 
                                        CATlsoTransformFaceResultDomain* iCur, short iKey=0);


  // CleanTransformedResult
  void CleanTransformedResult(CATBoolean iDestructor=FALSE);

  // CreateTransformedPersistentBodyResult
  void CreateNotExtrapolatedTransformedPersistentBodyResult();
  void CreateTransformedPersistentBodyResult();
  void CreateTransformedPersistentBodyResult(CATPersistentBody & iFlexibleInvalidResultPersistentBody);
  void CreateTransformedPersistentBodyResultFromInvalidResult(CATPersistentBody & iTransformedPersistentBody);
  void CreateResultFromInputSurface();
  // Compute both TransformedPersistentBody AND TransformedNotExtrapolatedPBody
  void ComputeTransformedPersistentInputsForXTrim(); 

  // INLINE CATlsoTransformFaceInputDomain * GetTFInputDomain() const;
  const CATlsoTransformFaceInputDomain  & GetTFInputDomain() const;

  // AssembleOneTransformedBody
  CATPersistentBody * AssembleOneTransformedBody(CATPersistentBody * iCurBodyForAssemble);

  // Only for last chance best result : return a surfacic body not solve
  CATPersistentBody * AssembleOneJustTransformedSurfacicBody( CATPersistentBody * iCurBodyForAssemble);

  // -------------
  // Get Methodes
  // -------------
  CATPersistentBody * GetTransformedPersistBody();
  CATPersistentBody * GetNotExtrapolatedTransformedPersistBody();
  void CleanSomePersistentBodiesToReleasePersistentCell();
  void GetNotToExtrapolateEdgeList(CATPersistentBody * iPersistentBody,
                                   ListPOfCATEdge    & oNotToExtrapolateEdgeList);

  INLINE CATBoolean IsParent(CATlsoTransformFaceInputDomain * iInputDomain) const;

  INLINE CATBoolean ParentChangeDimension() const;
  // Run Assemble Status
  //  0 : not computed
  //  1 : run ok
  //  -1 : run failed
  //  -2 : run failed, but try again (after XTrim)
  //  -3 : run failed, but no second flexible, just XTrim
  INLINE void SetRunAssembleStatus(CATLONG32 iStatus);
  INLINE CATLONG32 GetRunAssembleStatus() const;

  // CouldBeBetterWithXTrim
  //  0 : not computed
  //  1 :  could be better ok
  //  2 :  XTrim have failed, try tweaking again
  //  -1 : could not be better
  INLINE void SetCouldBeBetterWithXTrim(CATLONG32 iCouldBeBetter);
  INLINE CATLONG32 GetCouldBeBetterWithXTrim() const;

  // GetConfigurationType : Type from CATlsoTransformFaceInputDomain
  CATlsoRevolPrismData         GetRevolPrismData(CATBoolean iSourceValue=FALSE) const;
  TransformConfigurationType   GetConfigurationType() const;
  CATBoolean                   IsInVolumicBody() const;
  ConnectedInputType           GetInputType() const;

  INLINE void SetLocalTranformation(CATMathTransformation & iLocalTranformation);
  INLINE void GetLocalTranformation(CATMathTransformation & oLocalTranformation) const;
  INLINE CATLONG32 GetNumBrotherInstance() const;
  INLINE CATBoolean GetIsAnOutsideInstance() const;
  void GetInputPersistentFacesList(ListPOfCATPersistentFaces & oInputPersistentFaceList, CATListOfInt *oListOfMandatoryStatus=NULL) const;
  void GetInputFacesListOnPersistentBodyForFlexiblePlus(CATPersistentBody * iPersistentBody,
                                                        ListPOfCATFace    & oInputFaces,
                                                        CATListOfInt      & oMandatoryStatus,
                                                        ListPOfCATEdge    & oInvariantNeighborSmoothEdgeList) const;
  const CATMathTransformation & GetTransformation(CATFace * iFace=NULL,CATPersistentBody *iPersistentBody=NULL) const;

  void GetLocalTransformationForFlexiblePlus(CATPersistentBody * iPersistentBody, CATMathTransformation & oLocalTranformation);


  CATPersistentBody *  RunReverseThickness (CATPersistentBody * iCurBodyForAssemble);
  
  CATBoolean IsCaseForPowerPrism() const;
  CATBoolean IsCaseForXTrim() const;
  CATBoolean IsCaseForSecondFlexible() const;

  INLINE CATPersistentBody * GetSortedRelimitResultPersistentBody();
  void                       CleanSortedRelimitResultPersistentBody();

  // Prototype for help XTrim to find the right extrapolation
  void AddJournalItemToTargetPBody(CATCGMJournalList & ioResultJournal, CATPersistentBody * iTargetPersistentBody);

  //TopPatternStatus
  INLINE CATTopPatternStatus GetTopPatternStatus();
  INLINE void SetTopPatternStatus(CATTopPatternStatus iTopPatternStatus);

  // -------
  // Dump
  // -------
  void DumpObj(CATCGMOutput& s, short iLongDump=0, short iZtrNoDump=0) const;

protected:
  int        GetNbInputFaceListFromConnectedInput() const;
  CATBoolean IsMovingFaceType() const;
  void       GetInputPersistentEdgeListFromConnectedInput(ListPOfCATPersistentEdges & oInputPersistentEdgeList) const;
  void       GetInputPersistentVertexListFromConnectedInput(ListPOfCATPersistentVertices & oInputPersistentVertexList) const;

private: 

  // ----------------
  // Internal methode
  // ----------------
  INLINE void SetTransformedPersistBody(CATPersistentBody * iTransformedPersistBody);
  INLINE void SetNotExtrapolatedTransformedPersistBody(CATPersistentBody * iNotExtrapolatedTransformedPersistBody);
  INLINE void SetIsAnOutsideInstance(CATBoolean iIsAnOutsideInstance);
  INLINE void SetUseInnerBody(CATBoolean iUseInnerBody);
    
  void AddResultDomainPersistentBodyForHybridResult(CATPersistentBody * ResultDomainPBodyForHybridResult);

  void ComputeLocalTranformation();
  CATBoolean IsNumInstanceValid();

  int           ComputeIfCompliantMatterSide(CATPersistentBody          * iSupportPersistentBody,
                                             ListPOfCATPersistentFaces  & iPersistentFacesToModify,
                                             CATPersistentBody          * iSkintoSewPersistentBody);
  CATMathVector ComputeGlobalMatterSideVector(CATPersistentBody * iPersistentBody, ListPOfCATPersistentFaces * ipPersistentFacesToModify=NULL);
  CATMathVector ComputeGlobalMatterSideVector(ListPOfCATFace & iFaceList, CATShell & iShell);

  CATPersistentBody *  AssembleWithDepressionMode(CATPersistentBody * iCurBodyForAssemble);

  CATPersistentBody *  AssembleWithProtrusionMode(CATPersistentBody * iCurBodyForAssemble);

  CATPersistentBody *  AssembleWithMixedDepressionProtrusionMode(CATPersistentBody * iCurBodyForAssemble);

  CATBodyInputElementAttribute * AttachCDMInfoAttribute(CATPersistentBody * iPersistentBody,
                                                        CATBoolean          iHaveToLivifyInternalBody,
                                                        CATBoolean          iHaveToCreateInputElementAttribute);
  void CleanCDMInfoAttribute(CATPersistentBody             * iPersistentBody,
                             CATBodyInputElementAttribute *& iopInputElementAttribute);

  void AttachPBAttribute(CATBodyPersistentBodyAttribute *& ioPBAttribute,
                         CATPersistentBody              *  iPersistentBody);
  void CleanPBAttribute(CATBodyPersistentBodyAttribute *& ioPBAttribute,
                        CATPersistentBody              *  iPersistentBody);

  CATBoolean BoxeSizeIsKept(CATPersistentBody * iResultPersistentBody,
                            CATPersistentBody *  iRefPersistentBody);

  CATPersistentBody *  AssembleWithRevolPrismMode(CATPersistentBody * iCurBodyForAssemble);

  CATPersistentBody *  AssembleWithRevolPrismModeForVolume(CATPersistentBody * iCurBodyForAssemble, const CATlsoRevolPrismData &iRevolPrismData);

  CATPersistentBody *  ComputeRevolPrismForVolume(CATPersistentBody * iCurBodyForAssemble, int &oOrientation, CATCGMJournalList *oPrismJournal=NULL) const;

  CATPersistentBody *  CallPrism(const CATLONG32              iProfilDim, 
                                  ListPOfCATFace            & oInputFaceList, 
                                  ListPOfCATFace            & oOutputFaceSameGeometryList, 
                                  CATCGMJournalList_sp        oPrismJournal=NULL, 
                                  ListPOfCATPersistentFaces * oOutNeutralPFaceList=NULL) const;  

  CATPersistentBody *  RunPrismComputation(const CATlsoRevolPrismData & iRevolPrismData, 
                                           const CATMathDirection     & iPrismDirection, 
                                           const double                 iStartOffset, 
                                           const double                 iEndOffset, 
                                           CATBoolean                   iModifyResultJournal = FALSE,
                                           CATCGMJournalList          * oPrismJournal = NULL,
                                           ListPOfCATPersistentFaces  * oOutNeutralPFaceList=NULL) const;

  CATBoolean           IsLiveExtrudeDraftNeeded(const CATlsoRevolPrismData & iRPData) const;
  
  CATPersistentBody *  ManageExtrudeDraft(CATPersistentBody       * iRevolPrismPBody, 
                                          const ListPOfCATFace    & iInputNeutralFaceList, 
                                          const CATMathDirection  & iPullDir,
                                          CATCGMJournalList       * iRevolPrismJournal, 
                                          ListPOfCATPersistentFaces * oOutNeutralPFaceList=NULL, 
                                          CATCGMJournalList         * oCellDraftJournal=NULL) const;

  CATPersistentBody *  CallExtrudeDraft(CATPersistentBody           * iInputPersistentBody, 
                                         const ListPOfCATFace       & iNeutralFaces, 
                                         const CATlsoRevolPrismData & iRPD, 
                                         const CATMathDirection     & iPullDir,
                                         CATCGMJournalList          * oReportCellJournal=NULL) const;
  
  virtual CATPersistentBody * CallLiveExtrudeDraft(CATPersistentBody            * iRevolPrismPBody, 
                                                    const ListPOfCATFace        & iNeutralFaces, 
                                                    const CATlsoRevolPrismData  & iRPD, 
                                                    const CATMathDirection      & iPullDir,
                                                    CATCGMJournalList           * oReportCMJournal=NULL) const;

  CATPersistentBody *  RunRevolPrismWithModifiedJournal (CATTopExtrude               * iPrismRevolOpe, 
                                                          const CATlsoRevolPrismData & iRevolPrismData,
                                                          CATCGMJournalList          * oRevolPrismJournal,
                                                          ListPOfCATFace             & oInputFaceList,
                                                          ListPOfCATFace             & oOutputFaceSameGeometryList) const; // Old method - to remove

  CATPersistentBody * RunRevolPrismWithModifiedJournal_New(CATTopExtrude              * iPrismRevolOpe, 
                                                           const CATlsoRevolPrismData & iRevolPrismData,
                                                           CATCGMJournalList          & ioRevolPrismJournal,
                                                           CATCGMJournalList          * oModifiedJournal = NULL) const;


  void ModifyJournalForRevoPrismMode(CATCGMJournalList  * iJournal,
                                     CATCGMJournalList  * oModifiedJournal,
                                     ListPOfCATFace     & iInputFaceList,
                                     CATBody            * iInputBody) const;

  void FindReversedNeutralFaces(CATCGMJournalList * iRevolPrismJournal, const ListPOfCATFace & iInputFaceList, ListPOfCATFace & oReversedNeutralFaces) const;
  // new code
  void FindImageFacesWithSameGeometry  (CATCGMJournalList * iModifiedJournal,
                                       ListPOfCATFace     & iInputFaceList,
                                       ListPOfCATFace     & oOutputFaceSameGeometryList) const; // Parallel List to iInputFaceList
  
  CATBoolean HasFaceEqualGeometry (CATFace * iFace,  ListPOfCATFace & iFaceList) const;

  CATBoolean AreSameOrientation(ListPOfCATFace     & iInputFaceList,
                                ListPOfCATFace     & iOutputFaceSameGeometryList,
                                CATPersistentBody  * iInputPersistentBody,       // inputBody
                                CATPersistentBody  * iRevolPrismPersistentBody) const; // outputBody

  CATBoolean  CheckSameInnerBorder(CATPersistentBody * iCurBodyForAssemble);

  CATBoolean          IsSpecialRevolCase360(const CATlsoRevolPrismData & iRevolPrismData, 
                                            const CATMathAxis          & iRotationAxis, 
                                            const CATAngle             & iEndAngle, 
                                            ListPOfCATFace             & oSpecialCaseOutputSameGeoList) const;
  
  CATPersistentBody * CallRevol(const CATLONG32             iProfilDim, 
                                ListPOfCATFace            & oInputFaceList, 
                                ListPOfCATFace            & oOutputFaceSameGeometryList, 
                                CATCGMJournalList_sp        oRevolJournal=NULL,
                                ListPOfCATPersistentFaces * oOutNeutralPFaceList=NULL) const;

  CATPersistentBody * RunRevolComputation(const CATlsoRevolPrismData & iRevolPrismData, 
                                          const CATMathAxis          & iRotationAxis, 
                                          const CATAngle               iStartAngle, 
                                          const CATAngle               iEndAngle, 
                                          CATBoolean                   iModifyResultJournal=FALSE,
                                          CATCGMJournalList          * oRevolJournal=NULL,
                                          ListPOfCATPersistentFaces  * oOutNeutralPFaceList=NULL) const;


  CATPersistentBody * SimplifyAssembleForSurface(CATPersistentBody * iMergeSurfacicPBody, CATPersistentBody * iSurfacicPrism, CATCGMJournalList * iMergeJournal);

  CATPersistentBody * AssembleWithRevolPrismModeForSurface(CATPersistentBody * iCurBodyForAssemble);
  
  HRESULT             AssembleWithRevolPrismModeForSurface_FirstPart(CATPersistentBody   * iCurBodyForAssemble,
                                                                      CATPersistentBody *& oSupportPersistentBody,
                                                                      CATPersistentBody *& oRevolPrismResultForSurface,
                                                                      ListPOfCATPersistentFaces *oOutNeutralPFaceList=NULL);
  
  CATPersistentBody * AssembleWithRevolPrismModeForSurface_SecondPart (CATPersistentBody * iCurBodyForAssemble, 
                                                                       CATPersistentBody * iSupportPersistentBody, 
                                                                       CATPersistentBody * iRevolPrismResultForSurface,
                                                                       const CATlsoRevolPrismData & iRevolPrismData);

  CATPersistentBody * ComputeRevolPrismForSurface(CATPersistentBody           * iCurBodyForAssemble, 
                                                   const CATlsoRevolPrismData & iRevolPrismData, 
                                                   ListPOfCATFace             & oInputFacesList,
                                                   ListPOfCATFace             & oOutputFacesToRemove,
                                                   ListPOfCATPersistentFaces  * oOutNeutralPFaceList=NULL) const;

  // Run compatible between iCurBody and RevolPrism body.
  CATPersistentBody * AssembleReverseExtrudeDraft_ForSurface (CATPersistentBody               * iCurPBodyForAssemble, 
                                                              CATPersistentBody               * iRevolPrismResultPBody, // Volume
                                                              const CATlsoRevolPrismData      & iRevolPrismData,
                                                              const ListPOfCATPersistentFaces & iOutNeutralPFaceList) const;

  CATPersistentBody * AssembleWithRevolPrismModeForSheetMetal(CATPersistentBody * iCurBodyForAssemble);

  CATPersistentBody * AssembleWithRevolPrismModeForLineic(CATPersistentBody * iCurBodyForAssemble);

  CATPersistentBody * ComputeRevolPrismForLineic(CATPersistentBody * iCurBodyForAssemble, const CATlsoRevolPrismData & iRevolPrismData, CATPersistentBody *&oSupportPersistentBody) const;
                                                                                  
  void                RemoveInternalFaces(CATPersistentBody *& ioResultSurfacicPersistBody);

  CATPersistentBody * MyCloseOperatorForSheetMetal(CATPersistentBody * iPersistentBody);
  
  CATPersistentBody *  AssembleWithFullDomainMode(CATPersistentBody * iCurBodyForAssemble);

  virtual CATPersistentBody *  AssembleWithSurfacicCVMMode(CATPersistentBody * iCurBodyForAssemble);

  CATPersistentBody *  AssembleWithSmoothContactMode(CATPersistentBody *  iCurBodyForAssemble,
                                                     CATPersistentBody *& oThickPersistentBodyBeforeTweaking);

  CATPersistentBody *  AssembleWithUnknownMode(CATPersistentBody * iCurBodyForAssemble,
                                               CATBoolean          iNoTangencyPropagation=FALSE,
                                               CATBoolean          iThicknessWithFaceCreationBeforeTweaking=FALSE);
  CATPersistentBody *  AssembleWithUnknownMode2(CATPersistentBody * iCurBodyForAssemble,
                                               CATBoolean          iNoTangencyPropagation=FALSE,
                                               const CATBoolean    iInvertInputSkinOrientation=FALSE,
                                               CATBoolean          iExtrapolatedBodyToSew=TRUE,
                                               CATBoolean          iThicknessWithFaceCreationBeforeTweaking=FALSE);
  CATPersistentBody * AssembleWithUnknownMode2_FlexibleBRep(CATPersistentBody * iCurBodyForAssemble,
                                                            CATPersistentBody * iPBodyToSew,
                                                            const CATBoolean    iInvertInputSkinOrientation,
                                                            ListPOfCATFace    & iCoveredFaceList);

  CATPersistentBody *  AssembleWithUnknownMode3(CATPersistentBody * iCurBodyForAssemble);

  CATPersistentBody *  SimplifAfterTrimSew(CATPersistentBody * iTrimSewResultPBody, ListPOfCATFace & iReplacedFaceList, CATCGMJournalList & iTrimSewJournal);

  CATBoolean           CheckToAllowTrimSewWithoutExtrapolation();

  CATPersistentBody *  AssembleWithDepressionOrProtrusionMode(CATPersistentBody * iCurBodyForAssemble);

  // sous methodes pour la protursion et la depression

  CATPersistentBody *  AssembleWithSelectionTypeForRelim(CATPersistentBody * iCurBodyForAssemble,
                                                         CATLONG32           iSelectionTypeForRelim);

  CATPersistentBody *  RelimitByVolumeBeforeSew(CATPersistentBody * iCurBodyForAssemble,
                                                CATLONG32           iSelectionTypeForRelim,
                                                CATCGMJournalList * oRelimJournal);

  CATPersistentBody *  SortRelimitedDomainBeforeSew(CATPersistentBody *  iRelimitResultPersistBody);

  CATPersistentBody *  SewEachDomains         (CATPersistentBody * iCurBodyForAssemble,
                                               CATPersistentBody * iCurRelimTransformedPersistBody,
                                               CATBoolean          iCheckValidity = FALSE);

  CATPersistentBody *  AssembleWithTrimShell(CATPersistentBody * iCurBodyForAssemble,
                                             CATBoolean          iProtrusionMode);

  CATPersistentBody *  AssembleWithTrimSewRelimitation (CATPersistentBody * iCurBodyForAssemble, CATPersistentBody * iSkinPersistentBody=NULL);

  CATPersistentBody * TopologicalTrim(CATPersistentBody * iCurBodyForAssemble,
                                      CATPersistentBody * iTransformedPersistBody,
                                      CATBoolean          iProtrusionMode,
                                      CATCGMJournalList & oTrimJournal);

  CATPersistentBody *  AssembleWithSplitShell(CATPersistentBody * iCurBodyForAssemble,
                                              CATBoolean          iProtrusionMode);

  CATPersistentBody *  AssembleForPasteOnSurfacic(CATPersistentBody * iCurBodyForAssemble,
                                                  CATBoolean          iProtrusionMode);

  CATPersistentBody *  AssembleClosedTransformedPersistBody(CATPersistentBody * iCurBodyForAssemble, const CATLONG32 iSelectionTypeForRelim=0x0);

  void                 SetPatternFollowersOutsideInstance();

  int                  GetNbDomains(CATPersistentBody * iPersistentBody);

  CATPersistentBody *  FastAssembleBrothers(CATPersistentBody * iCurBodyForAssemble);

  CATPersistentBody *  FastGlobalyAssembleBrothers(CATPersistentBody * iCurBodyForAssemble);

  CATBoolean ComputeIntersectionBetweenInputAndTransformed();

  CATPersistentBody *  CreateThicknessBeforeTweaking(CATPersistentBody * iCurBodyForAssemble,
                                                     double            * iThicknessValue=NULL,
                                                     CATBoolean        * oFaceCreation=NULL);

  CATBoolean           FaceCreationAfterThick(CATCGMJournalList & iJournalThick, CATPersistentBody * iThickResultPBody);

  CATPersistentBody * RemoveConfusedFacesForSurfacicPrism(CATPersistentBody * iMergePersistentBody, ListPOfCATFace & iFaceListToRemove);

  CATPersistentBody * RemoveConfusedFacesForSurfacicPrism2(CATPersistentBody * iMergePersistentBody, CATPersistentBody * iPrismSupportPBody, const ListPOfCATFace & iFaceListToRemove) const;

  CATPersistentBody * CreateTransfromInnerPersistentBody();

  CATPersistentBody * AssembleMovingDraw(CATPersistentBody * iCurBodyForAssemble);

  CATPersistentBody * MergeTwoBodies(CATPersistentBody * iPersistentBody1,
                                     CATPersistentBody * iPersistentBody2,
                                     ListPOfCATFace    * oInputFaceTouchedList=NULL,
                                     CATBoolean          iRemoveConfusedFaces=FALSE,
                                     CATCGMJournalList * oReportJournal=NULL);
  
  CATBoolean IsVolumeCase(CATPersistentBody * iPersistentBody) const;
  CATBoolean IsEmpty(CATPersistentBody * iPersistentBody) const;

  int GetNbFaces(CATPersistentBody & iPersistentBody);
  CATBoolean ComputeIfCouldBeBetterWithXTrim(CATPersistentBody & iCurBodyForAssemble,
                                             CATPersistentBody & iResultPersistentBody,
                                             CATCGMJournalList & iTrimSewJournal);

  CATBoolean NeedWallOnSmoothContact(CATPersistentBody * iCurBodyForAssemble);

  CATBoolean SomeFaceDuplication(CATPersistentBody    * iResultPersistBody,
                                 const ListPOfCATFace & iCoveredFaces);

  CATBoolean MovingFacesAreIntersecting();
  CATBoolean SomeClosableCanonic(CATPersistentBody * iPersistentBody);

  CATPersistentBody *  RunLocalFlexiblePlus(CATPersistentBody * iCurBodyForAssemble);

  double ComputeThicknessValueBeforeTweaking(CATPersistentBody * iCurBodyForAssemble);

  // RemoveFaceIfResultIsConfusedWithNeighbor
  // Test if the all replacing face are identical with a neighbour face, then call RemoveFace
  CATPersistentBody * RemoveFaceIfResultIsConfusedWithNeighbor(CATPersistentBody * iCurBodyForAssemble);

  //VB7
  CATPersistentBody * AssembleWithKeepCellMode(CATPersistentBody * iCurBodyForAssemble);
  void AddToKeepCellList(CATPersistentBody * iTrimmedPBody, CATPersistentBody * iSupportPBody, ListPOfCATCell & oToKeepCellList);

  //VB7 Fillet Scar
  void RematchRelimitedBodyBeforeSewing(CATPersistentBody * iFixedPBody, CATPersistentBody *ioPersistentBodyToModify, CATCGMJournalList * iRelimJournal);

  // ---------------------------------------
  //  ClosedTransformedPersistBody Methodes
  // ---------------------------------------
  void ComputeClosedTransformedPersistBody();
  void ComputeClosedTransformedPersistBodyFromInputSurface();
  CATBoolean IsReallyClosed();
  INLINE CATPersistentBody * GetClosedTransformedPersistBody() const;
  INLINE CATPersistentBody * GetFirstClosedTransformedPersistBody() const;
  INLINE void SetClosedTransformedPersistBody(CATPersistentBody * iClosedTransformedPersistBody);
  INLINE void SetFirstClosedTransformedPersistBody(CATPersistentBody * iClosedTransformedPersistBody);

  //EYL Pour gestion des groupes CDM
  virtual CATBoolean HaveInputsCDMGroups();
  INLINE virtual void AttachCDMInfosToInputElementAttibute(CATBodyInputElementAttribute *InputElementAttribute);


  CATBoolean BelongsToRefPattern(CATPersistentBody * iCurBodyForAssemble);
  void UpdatePatternReference(CATPersistentBody * iNewPersistentReferenceBody);

  //----------------------------------------------------------------------------
  // CheckUnremovableInstance
  //----------------------------------------------------------------------------
  void CheckUnremovableInstanceForPattern();

  CATBoolean CheckResultForAbsorptionOrder(CATCGMJournalList * iJournalFromFirstToSecondBody);
  CATBoolean CheckCreationOfBorderEdges(CATCGMJournalList * iJournalFromFirstToSecondBody);

  CATBoolean CheckResultForNeighbourWithBrotherFaces(CATPersistentBody * iResultPersistentBody);
  CATBoolean CheckResultWithBoundingBox(CATPersistentBody * iFirstPersistentBody,
                                        CATCGMJournalList * iJournalFromFirstToSecondBody);

  CATBoolean CheckLostFacesEdition(CATPersistentBody * iSecondPBody, CATPersistentBody * iFirstPBody);
  CATBoolean CheckLoseUnexpectedFaces(CATPersistentBody * iSecondPBody, CATPersistentBody * iFirstPBody);

  INLINE void SetSortedRelimitResultPersistentBody(CATPersistentBody * iSortedRelimitResultPersistentBody);
  void CheckInstanceClash();
  CATBoolean IsLastResultDomain();

  CATBoolean NeedFastAssembleBrothers(CATPersistentBody * iResultPersistBody);

  void GetTranslationVectorFromSmoothContact(CATBody * iBodyToThick, ListPOfCATFace & iFaceList, const CATMathTransformation & iTransformation, CATMathVector & oTranslateVector);

  // --------------
  // Internal data
  // --------------
  CATlsoTransformFaceInputDomain & _TFInputDomain;
  CATLONG32                        _NumBrotherInstance;
  CATBoolean                       _IsAnOutsideInstance;

  CATMathTransformation            _LocalTranformation;
  CATPersistentBody              * _TransformedPersistBody;
  CATPersistentBody              * _NotExtrapolatedTransformedPersistBody;
  CATPersistentBody              * _ClosedTransformedPersistBody;
  CATPersistentBody              * _FirstClosedTransformedPersistBody;
  CATBoolean                       _SmoothContactComputed;
  double                           _SmoothContactThicknessValue;
  ListPOfCATPersistentFaces        _SmoothContactCoverdedPersistentFaceList;
  CATListOfDouble                  _SmoothContactThicknessValueList; // paralelle to _SmoothContactCoverdedPersistentFaceList

  CATBoolean                       _UseInnerBody;
  CATBoolean                       _ResultStatusIfOk;

  // New : PowerPrism 
  ListPOfCATPersistentBodies       _RevolPrismPersistentBodies;
  // 0 : Different orientation => Union
  // 1 : Same oriantation      => Diff
  CATListOfShort                   _RevolPrismOrientations; // Parallel to _RevolPrismPersistentBodies
  
  // Run Assemble Status
  //  0 : not computed
  //  1 : run ok
  //  -1 : run failed
  CATLONG32                        _RunAssembleStatus;

  //TopPattern Status
  CATTopPatternStatus              _TopPatternStatus;

  // CouldBeBetterWithXTrim
  //  0 : not computed
  //  1 :  could be better ok
  //  2 :  XTrim have failed, try tweaking again
  //  -1 : could not be better
  CATLONG32                       _CouldBeBetterWithXTrim;
  // record for time consuming if CouldBeBetterWithXTrim == 1;
  CATPersistentBody             * _PersistentBodyForAssemble;
  CATPersistentBody             * _PersistentBodyResultAfterAssemble;

  //VB7 - for pattern check W37 2016
  CATPersistentBody * _SortedRelimitResultPersistentBody;
};

//----------------------------------------------------------------------------
// Implementations INLINE
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// TransformedPersistBody Methodes
//----------------------------------------------------------------------------
INLINE void CATlsoTransformFaceResultDomain::SetTransformedPersistBody(CATPersistentBody * iTransformedPersistBody) {
 _TransformedPersistBody = iTransformedPersistBody; }

//----------------------------------------------------------------------------
// NotExtrapolatedTransformedPersistBody Methodes
//----------------------------------------------------------------------------
INLINE void CATlsoTransformFaceResultDomain::SetNotExtrapolatedTransformedPersistBody(CATPersistentBody * iNotExtrapolatedTransformedPersistBody) {
 _NotExtrapolatedTransformedPersistBody = iNotExtrapolatedTransformedPersistBody; }

//----------------------------------------------------------------------------
// ClosedTransformedPersistBody Methodes
//----------------------------------------------------------------------------
INLINE CATPersistentBody * CATlsoTransformFaceResultDomain::GetClosedTransformedPersistBody() const {
  return _ClosedTransformedPersistBody; }

INLINE void CATlsoTransformFaceResultDomain::SetClosedTransformedPersistBody(CATPersistentBody * iClosedTransformedPersistBody) {
  _ClosedTransformedPersistBody = iClosedTransformedPersistBody; }

INLINE CATPersistentBody * CATlsoTransformFaceResultDomain::GetFirstClosedTransformedPersistBody() const {
  return _FirstClosedTransformedPersistBody; }

INLINE void CATlsoTransformFaceResultDomain::SetFirstClosedTransformedPersistBody(CATPersistentBody * iClosedTransformedPersistBody) {
  _FirstClosedTransformedPersistBody = iClosedTransformedPersistBody; }


//----------------------------------------------------------------------------
// RunAssembleStatus Methodes
//----------------------------------------------------------------------------
INLINE void CATlsoTransformFaceResultDomain::SetRunAssembleStatus(CATLONG32 iStatus) {
  _RunAssembleStatus = iStatus;}

INLINE CATLONG32 CATlsoTransformFaceResultDomain::GetRunAssembleStatus() const {
  return _RunAssembleStatus;}


//----------------------------------------------------------------------------
// GetLocalTranformation
//----------------------------------------------------------------------------
INLINE void CATlsoTransformFaceResultDomain::GetLocalTranformation(CATMathTransformation & oLocalTranformation) const {
  oLocalTranformation = _LocalTranformation; }

INLINE void CATlsoTransformFaceResultDomain::SetLocalTranformation(CATMathTransformation & iLocalTranformation) {
  _LocalTranformation = iLocalTranformation; }

//----------------------------------------------------------------------------
// GetNumBrotherInstance
//----------------------------------------------------------------------------
INLINE CATLONG32 CATlsoTransformFaceResultDomain::GetNumBrotherInstance() const {
  return _NumBrotherInstance; }

//----------------------------------------------------------------------------
// Set and Get IsAnOutsideInstance
//----------------------------------------------------------------------------
INLINE void CATlsoTransformFaceResultDomain::SetIsAnOutsideInstance(CATBoolean iIsAnOutsideInstance) {
  _IsAnOutsideInstance = iIsAnOutsideInstance; }

INLINE CATBoolean CATlsoTransformFaceResultDomain::GetIsAnOutsideInstance() const {
  return _IsAnOutsideInstance; }


//----------------------------------------------------------------------------
// CouldBeBetterWithXTrim Methodes
//----------------------------------------------------------------------------
INLINE void CATlsoTransformFaceResultDomain::SetCouldBeBetterWithXTrim(CATLONG32 iCouldBeBetter) {
  _CouldBeBetterWithXTrim = iCouldBeBetter;}

INLINE CATLONG32 CATlsoTransformFaceResultDomain::GetCouldBeBetterWithXTrim() const {
  return _CouldBeBetterWithXTrim;}

INLINE CATBoolean CATlsoTransformFaceResultDomain::IsParent(CATlsoTransformFaceInputDomain * iInputDomain) const {
  return (iInputDomain == &_TFInputDomain); }

//----------------------------------------------------------------------------
// AttachCDMInfosToInputElementAttibute
//----------------------------------------------------------------------------
INLINE void CATlsoTransformFaceResultDomain::AttachCDMInfosToInputElementAttibute(CATBodyInputElementAttribute *InputElementAttribute)
{
}

/*INLINE CATBoolean CATlsoTransformFaceResultDomain::ParentChangeDimension() const {
  return _TFInputDomain.GetChangeDimension(); }*/

//INLINE CATlsoTransformFaceInputDomain * CATlsoTransformFaceResultDomain::GetTFInputDomain() const {
//  return (&_TFInputDomain); }

INLINE void CATlsoTransformFaceResultDomain::SetUseInnerBody(CATBoolean iUseInnerBody) {
 _UseInnerBody = iUseInnerBody; }

INLINE void CATlsoTransformFaceResultDomain::SetSortedRelimitResultPersistentBody(CATPersistentBody * iSortedRelimitResultPersistentBody) {
 _SortedRelimitResultPersistentBody = iSortedRelimitResultPersistentBody; }

INLINE CATPersistentBody * CATlsoTransformFaceResultDomain::GetSortedRelimitResultPersistentBody() {
 return _SortedRelimitResultPersistentBody; }

INLINE CATTopPatternStatus CATlsoTransformFaceResultDomain::GetTopPatternStatus() {
  return _TopPatternStatus; }

INLINE void CATlsoTransformFaceResultDomain::SetTopPatternStatus(CATTopPatternStatus iTopPatternStatus) {
  _TopPatternStatus = iTopPatternStatus; }

#endif

