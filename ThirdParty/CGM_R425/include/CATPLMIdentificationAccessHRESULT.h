#ifndef CATPLMIdentificationAccessHRESULT_H
#define CATPLMIdentificationAccessHRESULT_H

/**
* @level Private
* @usage U1
*/

#include "CATErrorDef.h"

#define CATPLMIdentificationAccess_ERR_BASE 0xA554
#define E_PARTIAL_SR MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, CATPLMIdentificationAccess_ERR_BASE + 0x000)
#define E_TOS_UNSET MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, CATPLMIdentificationAccess_ERR_BASE + 0x001)


#endif
