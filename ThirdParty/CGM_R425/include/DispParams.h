#ifndef _DispParams_h
#define _DispParams_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef _WINDOWS_SOURCE

#include "CATVariant.h"

typedef CATVariant VARIANTARG;
typedef LONG DISPID;

typedef struct tagDISPPARAMS {
 VARIANTARG * rgvarg;
 DISPID *rgdispidNamedArgs;
 unsigned int cArgs;
 unsigned int cNamedArgs;
} DISPPARAMS;

#endif /* _WINDOWS_SOURCE */

#endif
