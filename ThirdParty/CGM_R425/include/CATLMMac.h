#ifndef CATLMMAC_INCLUDE
#define CATLMMAC_INCLUDE

// COPYRIGHT DASSAULT SYSTEMES 1998
//-----------------------------------------------------------------------------
// Abstract:    CATIA License Manager Macros for embedded checks
//-----------------------------------------------------------------------------

#include "CATLM.h"

inline int CATLMIsFrameworkAuthorized (const char *name, int level, unsigned int *ioid) {
	CATLM::AuthorizationStatus sts;
	sts = CATLM::IsFrameworkAuthorized (name, level, ioid);
	CATLM::PrintDbg(CATLM::isxaType,"CATLMIsFrameworkAuthorized (%s) = %s\n", name == NULL ? "NULL" : name, sts == CATLM::Authorized ? "Authorized":"NotAuthorized");
	return (sts == CATLM::Authorized);
}

//
// Internal macros
//
#define CATSTRINGIFY(x)                 #x
#define CATLMFWID(fw)                   CATLMFrameworkId
#define CATLMFWNM(fw)                   CATSTRINGIFY(fw)

//
// Declaration to be made at file level
//
#define CATLMDeclareFramework           \
    static unsigned int CATLMFWID(_MK_FWNAME_) = 0xffffffff;

//
// Check to be made in framework code
//
// NOTE: this returns a boolean unlike CATLM::IsFrameworkAuthorized
//       which returns an enumerated status!
//
// Example:
//
//    if (CATLMIsAuthorized (2)) {
//        //
//        // authorized at level 2
//        ...
//    } else if (CATLMIsAuthorized (1)) {
//        // 
//        // authorized at level 1
//        ...
//    }
//    ...
//
#define CATLMIsAuthorized(level)        \
    (CATLMIsFrameworkAuthorized (CATLMFWNM(_MK_FWNAME_), level,\
                                 &CATLMFWID(_MK_FWNAME_)))

#endif
