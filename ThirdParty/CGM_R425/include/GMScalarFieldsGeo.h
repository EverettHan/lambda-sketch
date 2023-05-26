#ifdef _STATIC_SOURCE
#define	ExportedByGMScalarFieldsGeo
#elif defined __GMScalarFieldsGeo
#define ExportedByGMScalarFieldsGeo DSYExport
#else
#define ExportedByGMScalarFieldsGeo DSYImport
#endif
#include "DSYExport.h"
