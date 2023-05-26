#ifdef _STATIC_SOURCE
#define	ExportedByGMPolyOperItf
#elif defined __GMPolyOperItf
#define ExportedByGMPolyOperItf DSYExport
#else
#define ExportedByGMPolyOperItf DSYImport
#endif
#include "DSYExport.h"
