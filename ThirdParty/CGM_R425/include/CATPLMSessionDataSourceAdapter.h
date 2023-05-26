// COPYRIGHT Dassault Systemes 2009
//===================================================================
// This is the adaptor that implementor of itf CATIPLMSessionDataSource should C++ derived from

/**
 * @level Protected
 * @usage U2
 */

#ifndef CATPLMSessionDataSourceAdapter_H
#define CATPLMSessionDataSourceAdapter_H

#include "CATIPLMSessionDataSource.h"
#include "ExportedByCATPLMTos.h"

class ExportedByCATPLMTos CATPLMSessionDataSourceAdapter : public CATIPLMSessionDataSource
{
public:
  HRESULT GetCompletionLevel(CATPLMCompletionLevel & oCompletionLevel);
  HRESULT GetAssociatedObject(const CATString & iRelType, CATPLMID & oAssObjId);
  HRESULT GetSRList(CATOmxArray<CATPLMSemanticRelation> & oSRList);
  HRESULT GetSDList(CATLISTV(CATPLMStreamDefinition) & oSDList);
  HRESULT GetPathList(CATOmxList<CATPLMPath>& oPathList);
  HRESULT ListExtensionTypes(CATLISTV(CATPLMTypeId) & oLExtensionType);
  HRESULT GetAttributeBlock(const CATPLMTypeId & iExtensionType, CATOmxKeyValueBlock &oAttrBlock);
  HRESULT GetCEStamp(CATPLMCEStamp & oCEStamp);
  HRESULT GetSystemAttributesBlock(CATOmxKeyValueBlock & oAttrBlock);
  HRESULT GetMemoryState(CATBinary & oSessionMemoryState);
  CATOxSessionCoarseMemoryState* GetCoarseMemoryState();
  CATBoolean IsBasedOnRecordRead(CATIPLMRecordRead *& oRecord);
};

#endif // CATPLMSessionDataSourceAdapter_H
