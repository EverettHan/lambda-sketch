#ifdef _STATIC_SOURCE
#define	ExportedByTopPersistentLight
#elif defined __TopPersistentLight
#define ExportedByTopPersistentLight DSYExport
#else
#define ExportedByTopPersistentLight DSYImport
#endif
#include "DSYExport.h"

