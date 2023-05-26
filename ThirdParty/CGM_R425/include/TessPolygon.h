#ifdef _STATIC_SOURCE
#define	ExportedByTessPolygon
#elif defined __TessPolygon
#define ExportedByTessPolygon DSYExport
#else
#define ExportedByTessPolygon DSYImport
#endif
#include "DSYExport.h"
