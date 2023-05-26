#ifdef _STATIC_SOURCE
#define	ExportedByTessGeom
#elif defined __TessGeom
#define ExportedByTessGeom DSYExport
#else
#define ExportedByTessGeom DSYImport
#endif
#include "DSYExport.h"
