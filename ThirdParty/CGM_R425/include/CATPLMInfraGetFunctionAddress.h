#ifndef CATPLMInfraGetFunctionAddress_H
#define CATPLMInfraGetFunctionAddress_H

#include "CATPLMIdentificationAccess.h"

enum CATPLMInfraLibrary
{
  CATPLMIdentification,

  CATObjectModelerBase,
  CATObjectModelerCATIA,

  CATPLMIntegrationAccess,
  CATPLMIntegrationBase,
  CATPLMIntegration,

  CATPLMClientCoreModel,
  PLMModelerBase,
  PLMOccurrenceBase,

  CATPLMImplAdapterBase,
  CATPLMImplAdapterQLBase,

  CATObjectSpecsModeler,
  CATPLMSpecsModeler,

  CATOmbLinkAccess,

  ObjectModelerBaseUI
};

/**
 * Try to avoid using CATGetFunctionAddress
 * However if you need it, use the following in order to avoid duplicating for the N-th time the same library name
 */
ExportedByCATPLMIdentificationAccess void* CATPLMInfraGetFunctionAddress(CATPLMInfraLibrary library, const char* function);

/**
 * Same as above but considers that factoryFunction is a function located in given library.
 * This function must be a "factory" which signature is
 *  XXX* function() {return new XXX();}
 * and after loading this function, function is called and the result of its invocation is returned
 */
ExportedByCATPLMIdentificationAccess void* CATPLMInfraInstanciateObject(CATPLMInfraLibrary library, const char* factoryFunction);

#endif
