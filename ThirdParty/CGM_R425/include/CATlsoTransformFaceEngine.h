// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : L. Marini
//
// DESCRIPTION  : BRep Modeling Operator for CATIA Live Shape.
//                Single Operator for monoVolume Body.
//                It use draft value to define the modification.
//
//=============================================================================
// Creation LAP April 2008
//
//=============================================================================
#ifndef CATlsoTransformFaceEngine_H
#define CATlsoTransformFaceEngine_H

#include "AdvTrimOpe.h"
#include "CATCGMVirtual.h" 
#include "CATlsoTransformFaceContext.h"

#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATDomain.h"
#include "ListPOfCATPersistentBodies.h"
#include "CATDataType.h"
#include "ListPOfCATVertex.h"

class CATShell;
class CATTopVManipulate;
class CATlsoTransformFaceConnectedInputCells;
class CATTopFlexibleBRep;
class CATTopOpInError;
class CATlsoPowerRevolPrismOpe;
class CATTopFlexiblePlus;

#define RetStatus             CATlsoTransformFaceEngine::ReturnStatus
#define RetCompleteResult     CATlsoTransformFaceEngine::COMPLETE_RESULT
#define RetNothingDoneOrError CATlsoTransformFaceEngine::NOTHINGDONE_OR_ERROR
#define RetPartialResult      CATlsoTransformFaceEngine::PARTIAL_RESULT

class ExportedByAdvTrimOpe CATlsoTransformFaceEngine : public CATCGMVirtual
{
public:

  // Constructor
  CATlsoTransformFaceEngine(CATlsoTransformFaceContext & iContext);

  //-------------------------------------------------------------------------------------------------------
  // Surcharge du new/delete
  //-------------------------------------------------------------------------------------------------------
  CATCGMNewClassArrayDeclare;

  // Destructor
  ~CATlsoTransformFaceEngine();

  //
  enum ReturnStatus { COMPLETE_RESULT=0,
                      NOTHINGDONE_OR_ERROR,
                      PARTIAL_RESULT};

  // ------------
  // Get Methodes
  // ------------ 
  void ComputeTransformedDomainList(ListPOfCATDomain & oTranformedDomainList,
                                    CATPersistentBody * iResultPersistentBody);

  void FillInNoPatternCreationFaceList(ListPOfCATFace    & oNoPatternCreationFaceList,
    CATPersistentBody * iResultPersistentBody);

 

  // ---------------------------------------------
  // Run specifique de l'operateur de modification
  // appelé par le RunOperator de la  classe mere
  // ---------------------------------------------
  int RunFirstPassSpecificPart();
  int RunAllPassCATGMLiveShapeOperator(CATPersistentBody *& oResultPersistentBody);
  int RunOnlyMovingFacesForBestResult(CATPersistentBody *& oResultPersistentBody,
                                      CATCGMJournalList *& oJournalFromOnlyMovingFaces);

  // --------------------
  // Get Methodes
  // --------------------
  void GetInputDomainPersistentBodyList(ListPOfCATPersistentBodies & oInputDomainPersistentBodyList) const;
  void GetInputDomainTransformationList(CATLISTP(CATMathTransformation) & oInputDomainTransformationList);
  void GetInputDomainNbInstanceList(CATListOfShort & oInputDomainNbInstanceList) const;
  void GetInputDomainConfigurationTypeList(CATListOfInt & oInputDomainConfigurationTypeList) const;
  CATPersistentBody * GetSelectionExtractPersistentLiveBody();

  // Method to call for result from internal operator (FlexibleBRep).
  void GetModifiedEdgeFromFlexibleBrep(CATEdge*   iOldEdge,
                                       CATEdge*&  oNewEdge);

  INLINE void GetInvalidRibbons(ListPOfCATPersistentFaces & oInvalidRibbonsPFaceList);

  void CleanRemovableConfigurationType();
  TransformConfigurationType GetConfigurationType();


  CATBoolean FullDomainMoveWithSameTransfo(CATMathTransformation & oGlobalTransformation) const;

  // For time consuming
  // deprecated. Use FullDomainMoveWithSameTransfo
  CATBoolean IsFullDomainMove(CATMathTransformation & oGlobalTransformation);

  virtual void GetPersistentBodiesNecessaryForNextRun(ListPOfCATPersistentBodies &oPersistentBodiesNecessaryForNextRun) const;

  //For CreateManifold of result before Redo Feature
  CATBoolean AlwayUsedRemoveFeatureResult() const;
protected:
  // --------------------
  // Internal Input Data
  // --------------------
  CATlsoTransformFaceContext & _TFContext;

private:

  // --------------------
  // Internal Methodes
  // --------------------
  virtual void CreateOnInputDomain(CATPersistentBody                      * iPersistBodyToTransform,
                                   ListPOfCATPersistentFaces              & iInputPersistentFaceList,
                                   CATlsoTransformFaceConnectedInputCells & iTFConnectedInput,
                                   CATBoolean                               iFullDomainMove=FALSE);

  // GetFirstConfigurationType Methode a supprimer par la suite
  TransformConfigurationType GetFirstConfigurationType() const;

  CATBoolean IsOnlyIsoTopologicRebuild() const;

  void SplitHybridInputBody(CATPersistentBody * &ioPersistentBody);

  INLINE void       SetBorderEdgeVertexMove(CATBoolean iBorderEdgeVertexMove);
  INLINE CATBoolean GetBorderEdgeVertexMove() const;

  INLINE void       SetSecondXTrimNeed(CATBoolean iSecondXTrimNeed);
  INLINE CATBoolean GetSecondXTrimNeed() const;

  INLINE void                SetThickResultPersistentBody(CATPersistentBody * iThickResultPersistentBody);
  INLINE CATPersistentBody * GetThickResultPersistentBody();

  void       SetInvalidRibbons(ListPOfCATPersistentFaces & iInvalidRibbonsPFaceList);

  INLINE void       SetStopAfterThick(CATBoolean iStopAfterThick);
  INLINE CATBoolean GetStopAfterThick() const;

  INLINE void       SetXTrimWasRun(CATBoolean iVal=TRUE);
  INLINE CATBoolean GetXTrimWasRun() const;

  CATBoolean        IsAllSurfacicBorderCase() const;

  // ---------------------------
  // Internal AllPast Methodes
  // ---------------------------
  void FirstPassForInputDomains();
  void CreateAllTranformFaceResultDomains();
  void CreateTransformedBodies();
  void CleanAllTransformedResult();
  void CreateAllInputDomains();
  void ExtendToFilletLimitingFaces(ListPOfCATPersistentFaces & ioPersistentFacesToModify);
  void CreateAllInputDomains_New();

  void UpdateInputDomainsForAllPass();

  void CutPersistBodyToTransformInOneDomainBodies(CATPersistentBody                      * iPersistBodyToTransform,
                                                  ListPOfCATPersistentFaces              & iPersistentFacesToModify,
                                                  CATlsoTransformFaceConnectedInputCells & iTFConnectedInput);
  
  // return 0 if result Ok
  // return 1 if nothing done / error
  // return 2 if partial result
  RetStatus RunFastPatternCreation(CATPersistentBody *& ioResultPersitentBody);
  RetStatus CheckDomainCreation(CATPersistentBody *& ioResultPersistentBody);
  RetStatus RunClassicalSewMethode(CATPersistentBody *& ioResultPersistentBody);

  HRESULT   SetFlexiblePlusForSewMethode(CATPersistentBody *& ioResultPersistentBody, CATTopFlexiblePlus *& iFlexiblePlusOpe,
                                      CATBoolean           iSecondFlexible, CATBoolean &oFlexibleAccessError);
  void FindInputEdgeRepresentationWithEdgeCurve (const ListPOfCATEdge& iInputEdgeList, CATBody* ipResultBody, ListPOfCATEdge& oEdgeList);
  CATBoolean IsValidEdgeForFlexible(CATBody * iInputBody, CATEdge * iEdge, CATMathTransformation & iMathTransfo);
  RetStatus RunFlexiblePlusSewMethode(CATPersistentBody *& ioResultPersistentBody,
                                      CATBoolean           iSecondFlexible = FALSE,
                                      CATBoolean           iForceFlexibleOnGlobalBody = FALSE);
  void      ReverseThicknessAfterFlexible(CATPersistentBody *& ioFlexibleResultPBody, CATBoolean iSecondFlexible = FALSE);

  RetStatus RunFastTransformFaceMethode(CATPersistentBody *& ioResultPersistentBody);
  int       RunXTrimSewMethode(CATPersistentBody *& ioResultPersistentBody );
  RetStatus RunFlexibleBRepSewMethode(CATPersistentBody *& ioResultPersistentBody);
  RetStatus RunFlexibleBRepSewMethode2(CATPersistentBody *& ioResultPersistentBody,const CATBoolean iInvertInputSkinOrientation=FALSE);

  //VB7 W45 2019 - For Local Build
  CATPersistentBody * TreatmentAfterFlexibleToAvoidIntersection(CATPersistentBody * iInputPBody, CATPersistentBody * iFlexibleResultPersistentBody, CATCGMJournalList * iFlexibleJournal);
  CATPersistentBody * FastAssembleAfterFlexibleTreatment(CATPersistentBody * iFlexibleResultPersistentBody, ListPOfCATCell & iNonImpactedCellList, CATPersistentBody * iTrimmedPBody);
  CATBoolean          ComputeBodyChecker(CATPersistentBody * iInputPBody, CATBody * iToCheckBody, CATCGMJournalList * iJournal, ListPOfCATCell & iCellToCheckList, ListPOfCATCell & oInvalidCellList);
  CATBoolean          ComputeAutoIntersectionChecker(CATBody * iBody, ListPOfCATCell & iCellToCheckList, ListPOfCATFace & oInvalidFaceList);
  CATBoolean          IsAutoIntersected(CATBody * iBody, CATFace * iFace);
  CATPersistentBody * ExtractAndFixAutoIntersectionIssues(CATPersistentBody * iPBody, ListPOfCATFace & iToCheckFaceList, CATEdgeHashTable & oNonSmartEdgeBorderHT);
  CATBoolean          CheckResultAfterFlexibleForLocalBuild(CATPersistentBody * iBeforeFlexiblePBody, CATPersistentBody * iFlexibleResultPersistentBody, CATCGMJournalList * iFlexibleJournal);
  void                UpdateVolumeCase();

  // for surfacic case only
  CATPersistentBody * SolveIntersectionAfterFlexible_Surfacic(CATPersistentBody *iInputPersistentBody, CATPersistentBody *iFlexibleResultPersistentBody, CATCGMJournalList *iFlexJournal) const;
  CATPersistentBody * SolveIntersectionAfterFlexible_Surfacic2(CATPersistentBody *iInputPersistentBody, const ListPOfCATPersistentFaces &iInputPFaceList, CATPersistentBody *iFlexibleResultPersistentBody) const;
  void                RematchAfterSewSkin(CATPersistentBody & iTrimSewResultPBody, CATCGMJournalList & iTrimSewJournal, ListPOfCATPersistentBodies & iInputPBodyList) const;

  int       RunPowerRevolPrismMethode(CATPersistentBody *& ioResultPersistentBody);

  RetStatus CheckRunStatus();
  char *    RunStatusToText(RetStatus iRet);

  int NbCasesForXTrim();
  int NbCasesCouldBeBetterWithXTrim();
  int NbResultDomain();

  // return nb TFResultDomain done
  int AssembleTransformedBodyForType(TransformConfigurationType iConfigurationTypeFilter,CATPersistentBody *& ioResultPersistentBody);
  int AssembleTransformedBodyForPlanThickness(CATPersistentBody *& ioResultPersistentBody, CATBoolean & oIsValidResultBody);
  CATBoolean GetG2ContinuityOnVerticesBetweenInputEdgesAndContext(CATPersistentBody * iPBody, CATLISTP(CATFace) & iFaces, ListPOfCATVertex & oG2ContactVertexList);
  CATPersistentBody * TryToRemoveCreatedFacesAfterThick(CATPersistentBody * thickResultPersistentBody, CATCGMJournalList * journalThick, ListPOfCATVertex &iG2ContactVertexList);
  CATPersistentBody * SimplifyExtrapolatedSmoothEdges(CATPersistentBody *ibeforeThickPBody, CATPersistentBody * iAfterThickPersistentBody, ListPOfCATFace &iInputFaces, CATCGMJournalList *iThickJournal);
  
  CATPersistentBody * DerivationForFullDomainMove(const CATMathTransformation &iMathTransformation) const;
  CATPersistentBody * DerivationForCloningMode() const;

  void UpdateStatusAfterThick(int iStatus);
  void ComputeInvalidRibbonsAfterThick(CATLISTP(CATFace) & iNotInverseRazorBladeFaces, CATPersistentBody * iPBody);
  CATBoolean AreMovingFacesHalfRemoved(CATPersistentBody * inputPersistentBody, ListPOfCATFace & inputFaceList,CATPersistentBody *iPersistentCurrentBody);

  CATPersistentBody * RunThickForAssemble(CATPersistentBody *iInputPersistentBody, 
                                           ListPOfCATFace &iThicknessFaceList, 
                                           CATListOfDouble &iThicknessValueList, 
                                           CATBoolean       iIsFirstThickness,
                                           CATBoolean       &oProtrusionDeleted,
                                           CATBoolean       &oIsValidResultBody,
                                           CATCGMJournalList *ReportJournal=NULL);
  CATPersistentBody * PrepareAndCallThickness(CATPersistentBody *iInputPersistentBody, 
                                              ListPOfCATFace &iThicknessFaceList, 
                                              CATListOfDouble &iThicknessValueList,
                                              CATCGMJournalList &oThicknessJournal, //need empty journal
                                              CATLISTP(CATFace) &ioNotInverseRazorBladeFaces,
                                              short iManageCollision, //cout perfo supp
                                              CATBoolean & oNeedAnotherThickness,
                                              CATTopOpInError   ** ioThickOpeError = NULL); 
  CATPersistentBody * ComputeSimplifAfterThick(CATPersistentBody * iPBody, CATCGMJournalList & iJournal, ListPOfCATFace & iInputFaceList);

  // sub methode from RunFlexibleBRepSewMethode
  void ExtractSubResultFromFlexible(CATPersistentBody & flexibleInvalidResultPersistentBody);
  void CreateResultFromInputSurface();

  void CheckForBorderEdgeVertexMove();

  void BooleanUnionSurfacicWithVolumic(CATPersistentBody * iSurfacicPersistentBody, CATPersistentBody *& ioResultPersistentBody);
  void FinalAutocheck(CATPersistentBody * iResultPersistentBody);
  void SimplifyResult(CATPersistentBody *& ioResultPersistentBody);

  void CheckFullDomainPatternCreation();
  void CheckAreIntersectingInstances();

  CATBoolean SHMTangencyCheckForFlexible(CATBody *iInputBody, ListPOfCATFace &iInputFacesForTangencyCheck, ListPOfCATEdge &inputEdgesForTangencyCheck) const;

  // Error Management 
  // --------------------------
  HRESULT CreateLastErrorAfterRun() const;
  void    ManageWarningAndErrorAfterRun(CATPersistentBody * iResultPersistentBody) const;

  // ---------------------------
  // Internal FirstPast Methodes
  // ---------------------------
  void ComputeAllConfigurationType();
  void CreateAllExtrapolatedPersistentBody();
  void CreateAllPersistentEdges();
  
  // ---------------------------
  // Internal Tooll for Pattern
  // Compute average direction of matteer for a given edge on a given face, using extremity points
  // ---------------------------
  CATMathDirection ComputeAverageEnteringDirection( CATFace *iFace, CATEdge *iEdge);

  //VB7 FilletScar
  void RematchPersistentEdgesAfterXTrim(CATPersistentBody & iInputPersistentBody, CATPersistentBody & iXTrimResultPersistentBody, CATCGMJournalList & iXTrimJournal);
  void RematchAfterThick(CATPersistentBody & iInputPersistentBody, CATPersistentBody & iThickResultPersistentBody, ListPOfCATFace & iThicknessFaceList, CATCGMJournalList & iThickJournal);

  // --------------------
  // Internal Input Data
  // --------------------
  CATBoolean            _FirstPassForInputDomainsDone;
  CATBoolean            _BorderEdgeVertexMove;
  CATBoolean            _SecondXTrimNeed;
  CATBoolean            _StopAfterThick;
  CATBoolean            _TranformFaceResultDomainsAlreadyDone;
  ListPOfCATPersistentFaces _InvalidRibbonsPFaceList;

  // Internal Computed Data
  // --------------------------------
  CATBoolean            _XTrimWasRun;

  // Temporary body from first pass
  // ------------------------------
  CATPersistentBody   * _PersistFixedBodyForPasteMode;

  CATPersistentBody   * _SelectionExtractPersistentLiveBody;

  CATPersistentBody   * _ThickResultPersistentBody;

  CATTopFlexibleBRep  * _FlexibleBrepOpe; // for methode GetModifiedEdgeFromFlexibleBrep(CATEdge*   iOldEdge,CATEdge*&  oNewEdge);

  CATlsoPowerRevolPrismOpe * _PowerRevolPrismOpe;

};

#endif

INLINE void CATlsoTransformFaceEngine::SetBorderEdgeVertexMove(CATBoolean iBorderEdgeVertexMove) {
  _BorderEdgeVertexMove = iBorderEdgeVertexMove; }

INLINE CATBoolean CATlsoTransformFaceEngine::GetBorderEdgeVertexMove() const {
 return _BorderEdgeVertexMove; }

INLINE void CATlsoTransformFaceEngine::SetSecondXTrimNeed(CATBoolean iSecondXTrimNeed) {
  _SecondXTrimNeed = iSecondXTrimNeed; }

INLINE void CATlsoTransformFaceEngine::SetThickResultPersistentBody(CATPersistentBody * iThickResultPersistentBody) {
  _ThickResultPersistentBody = iThickResultPersistentBody; }

INLINE CATPersistentBody * CATlsoTransformFaceEngine::GetThickResultPersistentBody() {
  return _ThickResultPersistentBody; }

INLINE CATBoolean CATlsoTransformFaceEngine::GetSecondXTrimNeed() const {
 return _SecondXTrimNeed; }

INLINE void CATlsoTransformFaceEngine::GetInvalidRibbons(ListPOfCATPersistentFaces & oInvalidRibbonsPFaceList) {
  oInvalidRibbonsPFaceList.Append(_InvalidRibbonsPFaceList);
}

INLINE void       CATlsoTransformFaceEngine::SetStopAfterThick(CATBoolean iStopAfterThick) {
  _StopAfterThick = iStopAfterThick;
}

INLINE CATBoolean CATlsoTransformFaceEngine::GetStopAfterThick() const {
  return _StopAfterThick;
}

INLINE void CATlsoTransformFaceEngine::SetXTrimWasRun(CATBoolean iVal) { 
  _XTrimWasRun = iVal; }

INLINE CATBoolean CATlsoTransformFaceEngine::GetXTrimWasRun() const {
  return _XTrimWasRun;}

