#ifndef _CATOxSessionTraceManager_H
#define _CATOxSessionTraceManager_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
* @level Private
* @usage U1
*/
#include "CATBoolean.h"
#include "CATOxRelationalEvents.h"
#include "CATUnicodeString.h"
#include "ExportedByCATPLMIdentification.h"
#include "CATAdpMetaData.h"
#include "CATLISTV_CATComponentId.h"
#include "CATComponentIdStatus.h"
#include "CATOmxTextStream.h"
#include "CATPLMSemanticRelationLogStatus.h"
#include "CATPLMID.h"

class CATOxJanus;
class CATListValCATPLMID;
class CATPLMID;
class CATComponentId;
class CATOxEntity;
class CATRelationId;
class CATOxRelation;
class CATOxSessionUpgrade;
class CATIPLMComponent;
class CATIAdpPLMIdentificator;
class CATError;
class CATOxEntityUnstreamedInformation;
class CATPLMCEStamp;
class CATOxStreamer;
class CATOxSpace;
class CATOxSessionDuplicateUpgrade;

class CATBinary;
class CATPLMCEStamp;

class ExportedByCATPLMIdentification CATOxSessionTraceManager
{
public:
  /**
  * Get dumper singleton
  * @return the singleton dumper
  */
  static CATOxSessionTraceManager * GetDumper();

  /**
  * Activate the dumper singleton
  * For UI command only.
  * @return the singleton dumper
  */
  static CATOxSessionTraceManager *  ActivateDumper();

  /**
  * Dump relation event
  * @param iTag : the tag of the component
  * @param iPLMID : the PLMID of the component
  * @param iEvent : the nature of the event
  * @param iIDRel : relation ID
  * @param iMainLogStatusBefore : the main log status before the event
  * @param iMainLogStatusAfter : the main log status after the event
  * @param iDiffLogStatusBefore : the differential log status before the event
  * @param iDiffLogStatusAfter : the differential log status after the event
  */
  virtual void DumpRelationEvent(CATOxEntity * ipEntity, CATOxRelationalEvent iEvent, unsigned int iIDRel,
    unsigned int iMainLogStatusBefore, unsigned int iMainLogStatusAfter, unsigned int iDiffLogStatusBefore,
    unsigned int iDiffLogStatusAfter) = 0;

  virtual void DumpRelation_IncrementalExport(const CATComponentId & iComponent, unsigned int iIDRel, CATPLMSemanticRelationLogStatus iStatus, CATOxRelation * iRelation) = 0;

  virtual void DumpRelation_SingleExport(CATOxRelation & iRelation) = 0;

  virtual void DumpRelation_SingleImport(const CATComponentId & iPointingCID, CATOxRelation & iRelation) = 0;

  /**
  * Declare a save transaction has begun
  */
  virtual void DeclareBeginningSave(const CATComponentId & iCID) = 0;

  /**
  * Declare a save transaction has ended
  */
  virtual void DeclareEndingSave(const CATComponentId & iCID) = 0;

  /**
  * Log component creation
  */
  virtual void DumpComponentCreation(CATOxEntity * ipEntity) = 0;

  /**
  * Log component destruction
  */
  virtual void DumpComponentDeletion(CATOxEntity * ipEntity) = 0;

  /**
  * Log component modification
  */
  virtual void DumpComponentModification(CATOxEntity * ipEntity, CATPLMLogModified iLogModified, const CATUnicodeString & iAppData) = 0;

  /**
  * Log touches of update stamps
  */
  virtual void UpdateStampTouched(CATOxEntity * ipEntity) = 0;

  /**
  * Log UFO logging operations
  */
  virtual void DumpUFOOperation(const CATUnicodeString & iOperationName, const CATListValCATPLMID & iListOfOriginOccurrences, const CATListValCATPLMID & iListOfNewOccurrences) = 0;
  virtual void DumpUFOIndexes(const char pContext[]) = 0;
  virtual void DumpUFOSplitMessageForSave(const char pContext[]) = 0;
  virtual void DumpBeginCheckValidity(const CATUnicodeString & iActionName, unsigned int iSizeOp) = 0;
  virtual void DumpUFOEntryInvalidation(const CATUnicodeString & iActionName, unsigned int iKey) = 0;
  virtual void DumpUFORemoveLastEntry(const CATUnicodeString & iActionName, unsigned int iKey) = 0;
  virtual void DumpUFORemoveEntry(const CATUnicodeString & iActionName, unsigned int iKey) = 0;
  virtual void DumpUFORestoreLastEntryForRedo(const CATUnicodeString & iActionName, unsigned int iKey) = 0;
  virtual void DumpUFORestoreLastEntryForRedoInvalidation(const CATUnicodeString & iActionName, unsigned int iKey) = 0;
  virtual void DumpUFOReconcileInvalidation(const CATUnicodeString & iActionName, unsigned int iKey) = 0;
  virtual void DumpUFOApplyAlternative(CATBoolean success) = 0;
  virtual void DumpUFOGetSubsitutionSuccess(const CATPLMID & iOld, const CATPLMID & iNew) = 0;
  virtual void DumpUFOGetSubsitutionFailure(const CATPLMID & iOld) = 0;
  virtual void DumpUFOApplyAlternativeEquivalence(const CATPLMID & current, const CATPLMID & oldId, const CATPLMID & newId) = 0;
  virtual void DumpUFOApplyAlternativeLogical(const CATPLMID & Current, const CATPLMID & newLogicalId) = 0;
  virtual void DumpUFOApplyAlternativeLogical(const CATPLMID & Current) = 0;
  virtual void DumpUFOCheckOccurrenceCoherencyFailure(const CATPLMID & iPLMID, const CATUnicodeString & failure) = 0;
  virtual void DumpUFOCheckOccurrenceCoherencySuccess(const CATPLMID & iPLMID) = 0;
  virtual void DumpUFOSubsituteFailure(const CATPLMID & iOld, const CATPLMID & iNew) = 0;
  virtual void DumpUFOSubsituteSuccess(const CATPLMID & iOld, const  CATPLMID & iNew) = 0;
  virtual void DumpUFOApplyPortMapping(CATBoolean success) = 0;
  virtual void DumpPLMIDForUFOLAlgo(const char * iContext, const CATPLMID & iPLMID) = 0;


  /**
  *	Log for relational integrity:
  */
  virtual void DumpBeginComponentCheckingOfValidation(CATComponentId & iComponent,
    CATUnicodeString &iRole,
    CATUnicodeString &iCategory,
    CATComponentId &iPointedCID) = 0;
  virtual void DumpEndComponentCheckingOfValidation(CATComponentId & iComponent,
    CATUnicodeString &iRole,
    CATUnicodeString &iCategory,
    CATComponentId &iPointedCID,
    CATBoolean iSuccess) = 0;
  virtual void DumpBeginCheckingRelation(CATUnicodeString & iRole, CATUnicodeString &iCategory) = 0;
  virtual void DumpEndCheckingRelation(CATUnicodeString & iRole, CATUnicodeString &iCategory) = 0;
  virtual void DumpSizeConstraint(CATString & iAllowedPath, HRESULT iSuccess) = 0;
  virtual void DumpCheckingPatternValidity(CATString & iIdCode, CATBoolean iValidityConditionOK) = 0;
  virtual void DumpCheckingPattern(CATString & idCode, HRESULT iSuccess, CATUnicodeString & iFailure) = 0;
  virtual void DumpCheckingExplicitContext(HRESULT iSuccess) = 0;
  virtual void DumpCheckingImplicitContext(HRESULT iSuccess) = 0;
  virtual void DumpBeginCheckingPatterns(unsigned int iNbPatterns) = 0;
  virtual void DumpBeginCheckingClassPatterns(unsigned int iNbPatterns) = 0;
  virtual void DumpEndCheckingPatterns(HRESULT iSuccess, CATString iIdCode) = 0;
  virtual void DumpCheckingExpressionBelongsTo(CATUnicodeString & iType, HRESULT iSuccess) = 0;
  virtual void DumpCheckingExpressionFollowPattern(CATUnicodeString & iPatternName, CATBoolean iSyntaxOK, CATBoolean iPatternFoundInDico, HRESULT iSuccess) = 0;
  virtual void DumpBeginClassCheckingOfRule(CATComponentId & iComponent) = 0;
  virtual void DumpEndClassCheckingOfRule(CATComponentId & iComponent, CATBoolean iSuccess) = 0;
  virtual void DumpBeginCheckingClassPatternConstraint() = 0;
  virtual void DumpEndCheckingClassPatternConstraint(HRESULT iSuccess) = 0;
  virtual void DumpAddScope(CATUnicodeString & iType) = 0;
  virtual void DumpSetValidScope(CATUnicodeString & iType, CATString & iIdCode) = 0;
  virtual void DumpAreAllScopesValid(CATBoolean iSuccess) = 0;
  virtual void ResetScope() = 0;
  virtual void DumpCheckTypeCompliant(CATUnicodeString & iTypeToCheck, CATUnicodeString & iPackage, CATUnicodeString & iType, CATBoolean iSuccess) = 0;


  virtual void DumpOptions() = 0;

 //-----------------------------------------------------------------------------
 // _ECATracing
 //-----------------------------------------------------------------------------
  virtual void ECA_Dump(const CATUnicodeString &iStr, const CATComponentId &iCID = CATComponentId_Null, const CATPLMID & iECA = CATPLMID_Null) = 0;


  /**
  * activity status
  * @return activity status
  */
  virtual CATBoolean IsActive() = 0;

  virtual CATBoolean IsErrorEventTracingActive() = 0;
  virtual CATBoolean IsLocalSaveEventTracingActive() = 0;
  virtual CATBoolean IsRefreshEventTracingActive() = 0;
  virtual CATBoolean IsSessionManagerEventTracingActive() = 0;
  virtual CATBoolean IsReidentifyInSessionEventTracingActive() = 0;
  virtual CATBoolean IsRelationEventTracingActive() = 0;
  virtual CATBoolean IsLogEventTracingActive() = 0;
  virtual CATBoolean IsTouchUpdateStampTracingActive() = 0;
  virtual CATBoolean IsTracingOnConsoleActive() = 0;
  virtual CATBoolean IsRelationIntegrityTracing() = 0;
  virtual CATBoolean IsECATracing() = 0;
  virtual unsigned int GetTracedTag() = 0;

  //static void ForceDumpActivation(CATUnicodeString & iPathString) {_TracingActivated = TRUE;}
  virtual void ActivateDumps(unsigned int iTag = 0) = 0;
  virtual void DeactivateDumps() = 0;

  virtual void ActivateErrorEventTracing() = 0;
  virtual void DeactivateErrorEventTracing() = 0;
  virtual void ActivateLocalSaveEventTracing() = 0;
  virtual void DeactivateLocalSaveEventTracing() = 0;
  virtual void ActivateRefreshEventTracing() = 0;
  virtual void DeactivateRefreshEventTracing() = 0;
  virtual void ActivateSessionManagerEventTracing() = 0;
  virtual void DeactivateSessionManagerEventTracing() = 0;
  virtual void ActivateReidentifyInSessionEventTracing() = 0;
  virtual void DeactivateReidentifyInSessionEventTracing() = 0;
  virtual void ActivateRelationEventTracing() = 0;
  virtual void DeactivateRelationEventTracing() = 0;

  virtual void ActivateLogEventTracing() = 0;
  virtual void DeactivateLogEventTracing() = 0;

  virtual void ActivateTouchUpdateStampTracing() = 0;
  virtual void DeactivateTouchUpdateStampTracing() = 0;

  virtual void SetTag(unsigned int iTag) = 0;
  virtual void UnsetTag() = 0;

  virtual void SetTracingOnConsole() = 0;
  virtual void UnsetTracingOnConsole() = 0;

  virtual void ActivateRelationalIntegrityTracing() = 0;
  virtual void DeactivateRelationalIntegrityTracing() = 0;

  virtual void ActivateECATracing() = 0;
  virtual void DeactivateECATracing() = 0;

protected:
  static CATOxSessionTraceManager* _Dumper;
};

#endif
