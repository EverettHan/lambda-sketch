#ifdef _STATIC_SOURCE
#define	ExportedByAdvOpeInfra
#elif defined(__AdvOpeInfra)
#define ExportedByAdvOpeInfra DSYExport
#else
#define ExportedByAdvOpeInfra DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
