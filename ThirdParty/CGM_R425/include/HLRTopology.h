#ifdef _STATIC_SOURCE
#define	ExportedByHLRTopology
#elif defined __HLRTopology
#define ExportedByHLRTopology DSYExport
#else
#define ExportedByHLRTopology DSYImport
#endif
#include "DSYExport.h"
