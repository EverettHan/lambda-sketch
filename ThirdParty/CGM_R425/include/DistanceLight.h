#ifdef _STATIC_SOURCE
#define	ExportedByDistanceLight
#elif defined __DistanceLight
#define ExportedByDistanceLight DSYExport
#else
#define ExportedByDistanceLight DSYImport
#endif
#include "DSYExport.h"
