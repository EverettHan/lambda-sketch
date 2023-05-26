#ifdef _STATIC_SOURCE
#define	ExportedByTopoTransfo
#elif defined __TopoTransfo
#define ExportedByTopoTransfo DSYExport
#else
#define ExportedByTopoTransfo DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
