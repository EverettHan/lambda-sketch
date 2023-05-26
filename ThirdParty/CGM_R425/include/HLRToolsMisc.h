#ifdef _STATIC_SOURCE
#define	ExportedByHLRToolsMisc
#elif defined __HLRToolsMisc
#define ExportedByHLRToolsMisc DSYExport
#else
#define ExportedByHLRToolsMisc DSYImport
#endif
#include "DSYExport.h"
