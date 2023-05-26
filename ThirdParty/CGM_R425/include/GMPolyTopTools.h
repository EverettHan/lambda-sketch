#ifdef _STATIC_SOURCE
#define	ExportedByGMPolyTopTools
#elif defined __GMPolyTopTools
#define ExportedByGMPolyTopTools DSYExport
#else
#define ExportedByGMPolyTopTools DSYImport
#endif
#include "DSYExport.h"
