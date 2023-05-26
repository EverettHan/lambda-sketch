#ifdef _STATIC_SOURCE
#define	ExportedByTopoMatch
#elif defined __TopoMatch
#define ExportedByTopoMatch DSYExport
#else
#define ExportedByTopoMatch DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
