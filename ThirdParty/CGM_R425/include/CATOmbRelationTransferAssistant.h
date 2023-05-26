#ifndef CATOmbRelationTransferAssistant_H
#define CATOmbRelationTransferAssistant_H

// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @level Protected
 * @usage U3
 */
#include "CATOmbRelationTransfer.h"
#include "CATBaseUnknown.h"
#include "CATPLMID.h"
#include "CATOmxSR.h"

class CATOmbRelationTransferSubRelationship;
class CATOmbRelationTransferListener;
class CATOmbRelationTransferAssistantImpl;

/**
 * Class that defines an assistant for Transition engine to prevent PLMIntegrity violation.
 */
class ExportedByCATOmbRelationTransfer CATOmbRelationTransferAssistant
{
public:

  enum AssistantStatus { AssistantWaitingInit, AssistantRunning, AssistantComplete, AssistantCompleteWithViolations, AssistantError };

  /**
  * Returns running status
  */
  AssistantStatus GetStatus();

  /**
  * constructor
  * @param iPLMID
  *        Identifier of the owner
  * @param iErrorReporter
  *        For error reporting
  */
  CATOmbRelationTransferAssistant(CATPLMID & iPLMID, CATOmbRelationTransferListener * iTransferListener = 0);
  CATOmbRelationTransferAssistant() = default;

  /**
  * Initialized assistant
  */
  HRESULT Init();

  /**
  * Append a sub relationship
  *
  * @param iSRDictionaryName
  *        Name of the sub relationalship
  */
  HRESULT SetSubRelationship(CATOmbRelationTransferSubRelationship & iSubRelationship);

  /**
  * Finalyse relational description
  */
  HRESULT Complete();

  /**
  * Returns FALSE if assistant is valuated
  */
  explicit operator bool() const { return GetUsage() != nullptr; }
  CATOmbRelationTransferAssistantImpl* GetUsage() const { return _ImplUsage; }
private:
  CATOmxSR<CATOmbRelationTransferAssistantImpl> _ImplUsage;
};

#endif

