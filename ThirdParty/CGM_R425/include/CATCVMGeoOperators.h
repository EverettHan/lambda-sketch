#ifdef _STATIC_SOURCE
#define	ExportedByCATCVMGeoOperators
#elif defined(__CATCVMGeoOperators)
#define ExportedByCATCVMGeoOperators DSYExport
#else
#define ExportedByCATCVMGeoOperators DSYImport
#endif
#include "DSYExport.h"
