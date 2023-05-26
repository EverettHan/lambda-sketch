#ifndef CATPLMTransactionQueryResultWrapper_H
#define CATPLMTransactionQueryResultWrapper_H

/**
* @level Private
* @usage U1
*/

// System
#include "CATBaseUnknown.h"
// SystemTS
#include "CATBoolean.h"
// ObjectModelerCollection
#include "CATOmxSR.h"
// CATPLMIdentificationAccess
#include "CATLISTV_CATPLMTypeId.h"
// CATPLMIdentification
#include "CATPLMMergeMode.h"
#include "CATProxySpace.h"
#include "ExportedByCATPLMIdentification.h"

class CATProxyTransaction;
class CATComponentId;
class CATPLMID;
class CATOxTransaction;
class CATOxSpace;
class CATIPLMRecordRead;
class CATOmxKeyValueBlock;
class CATPLMTypeId;
class CATIPLMErrorCollector;

class ExportedByCATPLMIdentification CATPLMTransactionQueryResultWrapper
{
public:
  CATPLMTransactionQueryResultWrapper(const CATProxyTransaction & iTransaction);
  ~CATPLMTransactionQueryResultWrapper();

  /**
  * Enregistrement du record
  */
  HRESULT RegisterComponent(CATIPLMRecordRead* iRecordRead, CATComponentId& oComponent, CATBoolean iSynchronizeRelations = TRUE, CATBoolean iSynchronizeAttributes = TRUE);

  HRESULT RegisterComponent(const CATPLMID & iPLMID, CATComponentId & oComponent);

  HRESULT RegisterComponent(const CATPLMID & iPLMID, const CATPLMID & iPLMIDOwner, const CATPLMID & iPLMIDInstanceOf, CATComponentId& oComponent);

  HRESULT SynchronizeAttributes(CATIPLMRecordRead * iRecordRead, CATPLMMergeMode iMode);

  HRESULT SynchronizeAttributes(CATComponentId & iCID, const CATPLMTypeId & iExtensionId, const CATOmxKeyValueBlock & iAttrBlock, CATPLMMergeMode iMode);

  HRESULT SynchronizeStrongRelational(CATIPLMRecordRead * iRecordRead);

private:

  HRESULT RegisterComponent(CATIComponent* ipComponent, const CATPLMID & iPLMID, const CATPLMID & iPLMIDOwner, const CATPLMID & iPLMIDInstanceOf, CATComponentId & oComponent);
  friend class CATPLMCompleteGraphFromEmulatedSessionContents;
  friend class CATPLMMinorVersionOverloadingEngine;
  HRESULT RegisterComponent(const CATComponentId & iSourceComponentHandle, CATComponentId & oComponent, CATBoolean iRegisterDependencies = FALSE);

  CATOmxSR<CATOxSpace> _pSpace;
};

#endif
