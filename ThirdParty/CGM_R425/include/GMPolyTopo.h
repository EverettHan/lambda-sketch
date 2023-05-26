#ifdef _STATIC_SOURCE
#define	ExportedByGMPolyTopo
#elif defined __GMPolyTopo
#define ExportedByGMPolyTopo DSYExport
#else
#define ExportedByGMPolyTopo DSYImport
#endif
#include "DSYExport.h"
