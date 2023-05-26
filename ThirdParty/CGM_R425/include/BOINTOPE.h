#ifdef _STATIC_SOURCE
#define	ExportedByBOINTOPE
#elif defined __BOINTOPE
#define ExportedByBOINTOPE DSYExport
#else
#define ExportedByBOINTOPE DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
