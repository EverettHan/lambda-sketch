#ifdef _STATIC_SOURCE
#define	ExportedByHLRCompute
#elif defined __HLRCompute
#define ExportedByHLRCompute DSYExport
#else
#define ExportedByHLRCompute DSYImport
#endif
#include "DSYExport.h"
