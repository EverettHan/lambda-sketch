#ifdef _STATIC_SOURCE
#define	ExportedByTopExtLight
#elif defined __TopExtLight
#define ExportedByTopExtLight DSYExport
#else
#define ExportedByTopExtLight DSYImport
#endif
#include "DSYExport.h"

