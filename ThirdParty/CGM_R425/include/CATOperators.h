#ifdef _STATIC_SOURCE
#define	ExportedByCATOperators
#elif defined(__CATOperators)
#define ExportedByCATOperators DSYExport
#else
#define ExportedByCATOperators DSYImport
#endif
#include "DSYExport.h"
