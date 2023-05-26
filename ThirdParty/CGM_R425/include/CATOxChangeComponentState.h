#ifndef __CATOxChangeComponentState_H
#define __CATOxChangeComponentState_H

#include "CATBaseUnknown.h"
#include "ExportedByCATPLMTos.h"

/**
 * To be called by PC2 when changing the state of the PC2 entity exposed in TOS.
 */
HRESULT ExportedByCATPLMTos CATOxChangeComponentState(CATBaseUnknown* iPLMComponentExposedInTOS,CATBaseUnknown::ComponentState iFromState,CATBaseUnknown::ComponentState iToState);

#endif
