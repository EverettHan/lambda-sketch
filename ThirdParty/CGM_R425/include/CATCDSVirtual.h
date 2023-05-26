#ifndef CATCDSVirtual_h
#define CATCDSVirtual_h

#include "CATCDSCPlusPlusVersions.h"

#ifdef CPP11_AVAILABLE
#define CATCDSOverride override
#define CATCDSFinal final
#else
#define CATCDSOverride 
#define CATCDSFinal 
#endif

#endif
