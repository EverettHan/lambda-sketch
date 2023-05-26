#ifdef _STATIC_SOURCE
#define	ExportedByGMPolyImportExport
#elif defined __GMPolyImportExport
#define ExportedByGMPolyImportExport DSYExport
#else
#define ExportedByGMPolyImportExport DSYImport
#endif
#include "DSYExport.h"
