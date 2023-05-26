#ifdef _STATIC_SOURCE
#define	ExportedByTessBodyAdapters
#elif defined(__TessBodyAdapters)
#define ExportedByTessBodyAdapters DSYExport
#else
#define ExportedByTessBodyAdapters DSYImport
#endif
#include "DSYExport.h"
