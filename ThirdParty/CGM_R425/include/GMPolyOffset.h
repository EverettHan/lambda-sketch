#ifdef _STATIC_SOURCE
#define	ExportedByGMPolyOffset
#elif defined __GMPolyOffset
#define ExportedByGMPolyOffset DSYExport
#else
#define ExportedByGMPolyOffset DSYImport
#endif
#include "DSYExport.h"
