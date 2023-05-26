#ifdef _STATIC_SOURCE
#define	ExportedByHLREngine
#elif defined __HLREngine
#define ExportedByHLREngine DSYExport
#else
#define ExportedByHLREngine DSYImport
#endif
#include "DSYExport.h"
