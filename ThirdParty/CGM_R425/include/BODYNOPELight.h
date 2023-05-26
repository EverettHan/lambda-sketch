#ifdef _STATIC_SOURCE
#define	ExportedByBODYNOPELight
#elif defined __BODYNOPELight
#define ExportedByBODYNOPELight DSYExport
#else
#define ExportedByBODYNOPELight DSYImport
#endif
#include "DSYExport.h"
//#include "TopologicalOperatorsLightCommonDec.h"

