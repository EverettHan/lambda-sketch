#ifdef _STATIC_SOURCE
#define	ExportedByGMPolyUtilities
#elif defined __CATGMPolyUtilities
#define ExportedByGMPolyUtilities DSYExport
#else
#define ExportedByGMPolyUtilities DSYImport
#endif
#include "DSYExport.h"
