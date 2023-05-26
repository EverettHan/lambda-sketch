#pragma once

#include "CATRmaLog.h"

#define AC_CHECK_RETV_MSG(iCond, iValue, iMsg)                                                                         \
	if (!(iCond))                                                                                                      \
	{                                                                                                                  \
		AC_LOG_ERROR(iMsg);                                                                                            \
		return iValue;                                                                                                 \
	}
