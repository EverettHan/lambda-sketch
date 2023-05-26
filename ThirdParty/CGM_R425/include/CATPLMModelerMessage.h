#ifndef CATPLMModelerMessage_H
#define CATPLMModelerMessage_H

#include "CATPLMModelerBaseInterfaces.h"
#include "CATBaseUnknown.h"

/**
 * This class must be inherited to define "modeler messages"
 * Derived classes must use CATDeclareClass/CATImplementClass macros
 *
 * This class does not provide any functionality.
 * It is meant to help enforcing that modeler messages should be implemented through dedicated classes
 *
 * @see CATPLMCommonPrivateEventServices::LogModelerMessage CATIPLMModelerEventAccess::GetModelerMessage
 */
class ExportedByCATPLMModelerBaseInterfaces CATPLMModelerMessage : public CATBaseUnknown
{
  CATDeclareClass;
protected:
  CATPLMModelerMessage() = default; // make this class "abstract"
};

#endif
