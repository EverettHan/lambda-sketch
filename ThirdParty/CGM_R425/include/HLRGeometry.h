#ifdef _STATIC_SOURCE
#define	ExportedByHLRGeometry
#elif defined __HLRGeometry
#define ExportedByHLRGeometry DSYExport
#else
#define ExportedByHLRGeometry DSYImport
#endif
#include "DSYExport.h"
