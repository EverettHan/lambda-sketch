#ifndef CATIPLMClientCoreMastering_H
#define CATIPLMClientCoreMastering_H

/**
* @level Private
* @usage U3
*/

#include "ExportedByCATPLMIdentification.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATComponentId.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIdentification IID IID_CATIPLMClientCoreMastering;
#else
extern "C" const IID IID_CATIPLMClientCoreMastering ;
#endif

class ExportedByCATPLMIdentification CATIPLMClientCoreMastering : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  virtual HRESULT RestoreEditabilityFromSettingsAfterOpen(const CATListValCATComponentId & ipOpenedEntities) = 0;
  virtual HRESULT RestoreEditabilityFromSettingsAfterImport(const CATListValCATComponentId & iLoadedComponents, const CATListValCATComponentId& iReplacedComponents) = 0;
};



#endif
