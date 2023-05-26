// COPYRIGHT DASSAULT SYSTEMES 2013

#ifndef CATPLMIdentificationAccessToolbox_H
#define CATPLMIdentificationAccessToolbox_H

/**
* @level Private
* @usage U3
*/

#include "CATPLMIdentificationAccess.h"
#include "CATBoolean.h"

/**
 * OBSOLETE environment variables management pattern
 * please stop using it, please do not add anything new to it
 */
class ExportedByCATPLMIdentificationAccess CATPLMIdentificationAccessToolbox
{
public:

  // Prefix : CoreSession...
  // Antivar : NO_...
  enum ActivationVariable
  {
    VOID_ON = 0,
    REMOVED_SafeCopyIncludingFirstDSTypeForSolvingCompatibilityIssues,
    REMOVED_RelationalDescriptorFix,
    ComponentCheckerExtraCheck,
    ComponentCheckerExtraDump,
    LocalSavePatch,
    REMOVED_FrozenComponentManagement,
    PLMSession_DumpTools,
    InstanceWithSRs,
    UNUSED_ExtentedNavigation_Convergence,
    StatutRemote,
    StatutRemoteTraces,
    StatutRemoteAsyncBlocking,
    LightSROptim,
    // Add a new variable here ...
    END_MARK // MUST BE AT END !
  };

  static CATBoolean IsActivated(const ActivationVariable & iActivationVariable);

private:
  friend class CATOmbLinkToolbox;
  friend class CATOxDevStatus;

  enum Type { CoreSession, OMBLink };
  static void InitOther(const unsigned int &, const Type & type);
  static CATBoolean AddActivationStatus(const unsigned int & iIndex, const CATBoolean & iActivatedByDefault, const char * const ipString, const Type & type, CATBoolean iUsePrefix = TRUE, CATBoolean iOnlyInDSEnvironnement = FALSE);
  static void ForceActivation(const unsigned int &, const Type & type);
  static CATBoolean _IsActivated(const unsigned int &, const Type & type);
  static CATBoolean IsDSEnvironnement();

};

#endif

