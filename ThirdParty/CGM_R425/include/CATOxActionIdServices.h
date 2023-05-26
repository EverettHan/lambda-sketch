#ifndef CATOxActionIdServices_H
#define CATOxActionIdServices_H

/**
 * @level Private
 * @usage U1
 */

#include "ExportedByCATPLMTos.h"
#include "CATPLMID.h"

namespace CATOxActionIdServices
{
  ExportedByCATPLMTos void SetActionId(const CATPLMID & iActionId);
  ExportedByCATPLMTos CATPLMID GetActionId();
};

#endif
