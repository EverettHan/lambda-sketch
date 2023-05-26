#ifdef _STATIC_SOURCE
#define	ExportedByMultiWireCoupling
#elif defined(__MultiWireCoupling)
#define ExportedByMultiWireCoupling DSYExport
#else
#define ExportedByMultiWireCoupling DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
