/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2004
#ifndef CATIPLMAuxiliaryOpenFactory_H
#define CATIPLMAuxiliaryOpenFactory_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATOmxDeprecated.h"
class CATPLMTypeId;
class CATIPLMOpenEngineMediator;
class CATIPLMAttrRead;
class CATOmxKeyValueBlock;
class CATIPLMEngineErrorReporter;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMAuxiliaryOpenFactory;
#else
extern "C" const IID IID_CATIPLMAuxiliaryOpenFactory;
#endif

/**
* @level Protected
* @usage U4 CATPLMAuxiliaryOpenFactoryAdaptor
*/


/** obsolete */
class ExportedByCATPLMIntegrationInterfaces OMX_DEPRECATED("obsolete protocol") CATIPLMAuxiliaryOpenFactory : public CATBaseUnknown
{
  CATDeclareInterface;
};
#endif
