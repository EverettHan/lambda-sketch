#ifdef _STATIC_SOURCE
#define	ExportedByGMPolyProject
#elif defined __GMPolyProject
#define ExportedByGMPolyProject DSYExport
#else
#define ExportedByGMPolyProject DSYImport
#endif
#include "DSYExport.h"
