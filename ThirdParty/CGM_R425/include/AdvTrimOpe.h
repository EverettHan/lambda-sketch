#ifdef _STATIC_SOURCE
#define	ExportedByAdvTrimOpe
#elif defined(__AdvTrimOpe)
#define ExportedByAdvTrimOpe DSYExport
#else
#define ExportedByAdvTrimOpe DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
