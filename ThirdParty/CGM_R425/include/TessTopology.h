#ifdef _STATIC_SOURCE
#define	ExportedByTessTopology
#elif defined __TessTopology
#define ExportedByTessTopology DSYExport
#else
#define ExportedByTessTopology DSYImport
#endif
#include "DSYExport.h"
