#ifndef CATOmyErrorDef_H
#define CATOmyErrorDef_H

#include "CATErrorDef.h"

#define CATOMY_ERR_BASE 0x0B00

#define S_OMY_ATTR_NOT_SET MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_ITF, CATOMY_ERR_BASE + 0x0040)

#endif
