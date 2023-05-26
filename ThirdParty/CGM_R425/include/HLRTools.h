#ifdef _STATIC_SOURCE
#define	ExportedByHLRTools
#elif defined __HLRTools
#define ExportedByHLRTools DSYExport
#else
#define ExportedByHLRTools DSYImport
#endif
#include "DSYExport.h"
