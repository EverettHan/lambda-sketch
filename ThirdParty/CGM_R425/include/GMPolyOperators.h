#ifdef _STATIC_SOURCE
#define	ExportedByGMPolyOperators
#elif defined __GMPolyOperators
#define ExportedByGMPolyOperators DSYExport
#else
#define ExportedByGMPolyOperators DSYImport
#endif
#include "DSYExport.h"
