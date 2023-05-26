#if defined(__PolyPathPlanning)
#define ExportedByPolyPathPlanning DSYExport
#else
#define ExportedByPolyPathPlanning DSYImport
#endif
#include "DSYExport.h"

#include "CATIAV5Level.h"
#ifdef _WINDOWS_SOURCE
#define ENABLE_PP_MT
#elif defined(_LINUX_SOURCE) && defined(CATIAR419)
#define ENABLE_PP_MT
#endif
