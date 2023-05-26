#ifdef _STATIC_SOURCE
#define	ExportedByCATCVMGeoObjects
#elif defined(__CATCVMGeoObjects)
#define ExportedByCATCVMGeoObjects DSYExport
#else
#define ExportedByCATCVMGeoObjects DSYImport
#endif
#include "DSYExport.h"
