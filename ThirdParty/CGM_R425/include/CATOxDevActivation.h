#ifndef CATOxDevActivation_H
#define CATOxDevActivation_H

/**
* @level Protected
* @usage U1
*/

#include "CATPLMIdentificationAccess.h"
#include "CATBoolean.h"

class CATPLMRepositoryName;

class ExportedByCATPLMIdentificationAccess CATOxDevActivation
{
  friend class CATPCTOpen;// Need to use CATOxDevActivation::mod()
  friend class ContextTSTCATPLMxFilterConditionOperandCountLimit;// Need to use CATOxDevActivation::mod()
  friend class ContextTSTCATPLMWMTimeout;// Need to use CATOxDevActivation::mod()
public:

  // ---------------------
  // ACTIVATION DES TRACES
  // ---------------------

  // ------------------------------------------------------------------
  // Dump de la transaction de refresh. 
  // Le BSFTST est nécessaire pour generation des traces dans CATTemp.
  // ------------------------------------------------------------------
  static CATBoolean IsSynchronizationDebugActivated();

  // ------------------------------------------------------------------
  // Dump du session manager.
  // Le BSFTST est nécessaire pour generation des traces dans CATTemp.
  // ------------------------------------------------------------------
  static CATBoolean IsSessionManagerDebugActivated();

  // ------------------------------------------------------------------
  // Dump du restore.
  // Le BSFTST est nécessaire pour generation des traces dans CATTemp.
  // ------------------------------------------------------------------
  static CATBoolean IsRestoreDebugActivated();

  /**
  * Minor-Major Project
  */
  static CATBoolean IsMasterStampsOnUUID() { return TRUE; }
  static CATBoolean IsMINMAJWithFamilyRemoteStatus() { return TRUE; }
  static CATBoolean IsMINMAJReplaceActivated();                         // *** EXTRA ACTIVATION ****
  static CATBoolean IsMINMAJActivated() { return TRUE; }
  static CATBoolean IsPLMIDWithMajorIdActivated() { return TRUE; }
  static CATBoolean IsMajorIdSessionUsageActivated() { return TRUE; }
  static CATBoolean IsPLMIDWithMajorIdNotEqualToPhysicalIdAuthorized() { return TRUE; }

  /**
   * Change log management
   */
  static CATBoolean IsCCMActivated();                                   // *** CCM GLOBAL ACTIVATION ***

  static CATBoolean IsMultiEcaActivated();                              // Activation Multi-ECa

  static CATBoolean AlwaysSendChangeLog();                              // Always send change log


  // A pour prereq : IsPLMIDWithMajorIdNotEqualToPhysicalIdAuthorized
  static CATBoolean UFOWithMinorMajor();                                // UFO WITH MINOR MAJOR

  // LOG - AFO
  static CATBoolean IsAFOLogCouplingActivated();

  // LOG - 3DPart(Bell)
  static CATBoolean Is3DPartLogCouplingActivated();

  static CATBoolean IsDEAIdentification();

  static CATBoolean IsSessionManagerMVCDeactivated();

  static CATBoolean CompletionQueryOnVPMCfgConfiguration();

  static CATBoolean UFOReplace();

  static CATBoolean OpenOnEntityForCATOxiODT();

  static CATBoolean IsPatchForERSessionQueryActivated();

  static CATBoolean IsUserFactAlwaysSend();

  static CATBoolean IsCCMPerfosActivated_OnlyNecessaryUsersFacts();

  // New Typing
  static CATBoolean IsNewTypingActivated() { return TRUE; }
  static CATBoolean NewTypingInTOS() { return TRUE; }
  static CATBoolean AssertInDeprecatedAPIForNewTyping() { return FALSE; }
  static CATBoolean DisableV2TypeForV1PLMID();

  static CATBoolean IsLogingSplitEffectivityActivated();

  static CATBoolean IsCCMForSaveEngineActivated() { return TRUE; }

  static CATBoolean IsUnderUFOODT();

  static CATBoolean NotifyDirtyficationForMecMod();

  static CATBoolean IsV_VersionIDRemoved();

  static CATBoolean IsQueryOnXMQLOn();
  static CATBoolean IsSROnExtOn();
  static CATBoolean IsAttrWithoutDfltOfDfltSupported();
  static CATBoolean IsReplaceOnReplaceOperator();

  static CATBoolean IsDSEnvironnement();

private:
  CATOxDevActivation();
  static const CATOxDevActivation & env();

  static CATOxDevActivation & mod();


  CATBoolean _bSynchronizationDebug : 1;
  CATBoolean _bSessionManagerDebug : 1;
  CATBoolean _bRestoreDebug : 1;
  CATBoolean _bIsCCM : 1;
  CATBoolean _bAlwaysSendChangeLog : 1;
  CATBoolean _bIsMultiEcaActivated : 1;
  CATBoolean _bIsMINMAJReplace : 1;
  CATBoolean _b3DPartLogCoupling : 1;
  CATBoolean _bUFOWithMinorMajor : 1;
  CATBoolean _bDEAIdentification : 1;
  CATBoolean _bCompletionQueryOnVPMCfgConfiguration : 1;
  CATBoolean _bPatchForERSessionQuery : 1;
  CATBoolean _bUFOLogDuplicateOnSessionDeleted : 1;
  CATBoolean _bOpenOnEntityForCATOxiODT : 1;
  CATBoolean _bIsUserFactAlwaysSend : 1;
  CATBoolean _bIsCCMPerfosActivated_OnlyNecessaryUsersFacts : 1;
  CATBoolean _bDisableV2TypeForV1PLMID : 1;
  CATBoolean _bIsLogingSplitEffectivityActivated : 1;
  CATBoolean _bIsUnderUFOODT : 1;

  CATBoolean _QueryOnXMQL : 1;
  CATBoolean _PLM_IS_SR_ON_EXT_ON : 1;
};

#endif
