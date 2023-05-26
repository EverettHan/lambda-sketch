#ifdef _STATIC_SOURCE
#define	ExportedByGMPolyGeo
#elif defined __GMPolyGeo
#define ExportedByGMPolyGeo DSYExport
#else
#define ExportedByGMPolyGeo DSYImport
#endif
#include "DSYExport.h"
