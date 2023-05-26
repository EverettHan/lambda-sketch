#ifdef _STATIC_SOURCE
#define	ExportedByBOIMPOPE
#elif defined __BOIMPOPE
#define ExportedByBOIMPOPE DSYExport
#else
#define ExportedByBOIMPOPE DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
