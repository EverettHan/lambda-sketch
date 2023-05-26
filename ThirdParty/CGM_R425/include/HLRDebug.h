#ifdef _STATIC_SOURCE
#define	ExportedByHLRDebug
#elif defined __HLRDebug
#define ExportedByHLRDebug DSYExport
#else
#define ExportedByHLRDebug DSYImport
#endif
#include "DSYExport.h"
