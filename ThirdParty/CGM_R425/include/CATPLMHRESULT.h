#ifndef __CATPLMHRESULT_h__
#define __CATPLMHRESULT_h__

/**
* @level Private
* @usage U1
*/

#include "CATErrorDef.h"
// These are the specific HRESULT returned
// in addition to generic HRESULT such E_INVALIDARG, E_FAIL, E_NOTIMPL etc 
// Go to the relevant .h / API to know the possible specific return code of an API

// Same definition found in CATOmyErrorDef.h with S_OMY_ATTR_NOT_SET

#define CATPLM_ERR_BASE 0x0B00

#define S_ATTR_NOT_SET MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_ITF, CATPLM_ERR_BASE + 0x0040)

#endif
