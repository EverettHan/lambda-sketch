#ifdef _STATIC_SOURCE
#define	ExportedByTopUtilLight
#elif defined __TopUtilLight
#define ExportedByTopUtilLight DSYExport
#else
#define ExportedByTopUtilLight DSYImport
#endif
#include "DSYExport.h"

