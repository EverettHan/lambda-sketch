#ifdef _STATIC_SOURCE
#define	ExportedByGMPolyORMOper
#elif defined __GMPolyORMOper
#define ExportedByGMPolyORMOper DSYExport
#else
#define ExportedByGMPolyORMOper DSYImport
#endif
#include "DSYExport.h"
