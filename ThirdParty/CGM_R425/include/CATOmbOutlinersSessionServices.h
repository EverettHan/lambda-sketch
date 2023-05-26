#ifndef CATOmbOutlinersSessionServices_H
#define CATOmbOutlinersSessionServices_H

#include "CATOmbSessionService.h"
#include "IUnknown.h"
#include "CATPLMStreamDescriptorForAll.h"

class CATComponentId;
class CATBaseUnknown;
class CATOmxKeyValueBlock;
class CATIPLMIntegRecordWrite;
class CATOmbSessionContext;

class ExportedByCATPLMStreamDescriptor CATOmbOutlinersSessionServices : public CATOmbSessionService
{
public : 
  CATOmbOutlinersSessionServices(CATOmbSessionContext *ipSessionContext):CATOmbSessionService(ipSessionContext){}

  /*
  * Perform all outlining operation registered for this kind of component (see XDefinition declarations)
  * @param
  *   iCID : the component id of the RepRef to outline
  *   iBlock : the key value block where the outlining will be stored
  * @return
  *   S_OK : Outlining well done
  *   S_FALSE : Nothing to do
  *   E_XXX : an error occured, see OMB_XML_TRACE for details
  */
  HRESULT PerformOutlinings(const CATComponentId& iCID, CATOmxKeyValueBlock& oBlock);
  
  /* Same as above taking a pointer to the repRef instead of CATComponentId
  */
  HRESULT PerformOutlinings(const CATBaseUnknown* iRepRef, CATOmxKeyValueBlock& oBlock);

  /* 
  * Add content of iBlock to the recordWrite
  */
  HRESULT AddingOutlinedDataToRecord(const CATOmxKeyValueBlock& iBlock, CATIPLMIntegRecordWrite& ioRecordWrite);
};

#endif // CATOmbOutlinersSessionServices_H

