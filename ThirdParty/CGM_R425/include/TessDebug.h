#ifdef _STATIC_SOURCE
#define	ExportedByTessDebug
#elif defined __TessDebug
#define ExportedByTessDebug DSYExport
#else
#define ExportedByTessDebug DSYImport
#endif
#include "DSYExport.h"
