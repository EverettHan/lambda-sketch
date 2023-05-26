#ifdef _STATIC_SOURCE
#define	ExportedByGMPolyBasicOper
#elif defined __GMPolyBasicOper
#define ExportedByGMPolyBasicOper DSYExport
#else
#define ExportedByGMPolyBasicOper DSYImport
#endif
#include "DSYExport.h"
