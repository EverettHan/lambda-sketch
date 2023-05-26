#ifdef _STATIC_SOURCE
#define	ExportedByGenHeal
#elif defined __GenHeal
#define ExportedByGenHeal DSYExport
#else
#define ExportedByGenHeal DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
