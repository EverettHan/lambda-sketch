#ifdef _STATIC_SOURCE
#define	ExportedByGMPolyTessBody
#elif defined __GMPolyTessBody
#define ExportedByGMPolyTessBody DSYExport
#else
#define ExportedByGMPolyTessBody DSYImport
#endif
#include "DSYExport.h"
