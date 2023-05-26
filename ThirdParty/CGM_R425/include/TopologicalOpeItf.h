#ifdef _STATIC_SOURCE
#define	ExportedByTopologicalOpeItf
#elif defined __TopologicalOpeItf
#define ExportedByTopologicalOpeItf DSYExport
#else
#define ExportedByTopologicalOpeItf DSYImport
#endif
#include "DSYExport.h"
