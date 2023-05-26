#ifdef _STATIC_SOURCE
#define	ExportedByBONEWOPE
#elif defined(__BONEWOPE)
#define ExportedByBONEWOPE DSYExport
#else
#define ExportedByBONEWOPE DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
