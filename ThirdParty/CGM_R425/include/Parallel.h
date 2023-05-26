#ifdef _STATIC_SOURCE
#define	ExportedByParallel
#elif defined __Parallel


// COPYRIGHT DASSAULT SYSTEMES 1999

/** @CAA2Required */
#define ExportedByParallel DSYExport
#else
#define ExportedByParallel DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
