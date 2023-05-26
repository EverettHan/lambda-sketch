/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2003
#ifndef CATIPLMAuxiliarySaveFactory_H
#define CATIPLMAuxiliarySaveFactory_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATOmxDeprecated.h"
class CATPLMTypeId;
class CATComponentId;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMAuxiliarySaveFactory;
#else
extern "C" const IID IID_CATIPLMAuxiliarySaveFactory;
#endif

class CATIPLMEngineErrorReporter;
class CATIPLMAttrWrite;
class CATIPLMLogState;
class CATIPLMIntegRecordRead;

/**
* @level Protected
* @usage U4 CATPLMAuxiliarySaveFactoryAdaptor
*/

/**
 * Interface to declare and describe an auxiliary PLM extension in the save message.
 */
class OMX_DEPRECATED("obsolete and unused") ExportedByCATPLMIntegrationInterfaces CATIPLMAuxiliarySaveFactory : public CATBaseUnknown
{
  CATDeclareInterface;
public:
};

#endif
