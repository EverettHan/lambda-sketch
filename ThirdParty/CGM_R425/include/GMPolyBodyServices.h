#ifdef _STATIC_SOURCE
#define	ExportedByGMPolyBodyServices
#elif defined __GMPolyBodyServices
#define ExportedByGMPolyBodyServices DSYExport
#else
#define ExportedByGMPolyBodyServices DSYImport
#endif
#include "DSYExport.h"
