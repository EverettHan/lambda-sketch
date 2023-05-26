#ifdef _STATIC_SOURCE
#define	ExportedByFacRepSur
#elif defined __FacRepSur
#define ExportedByFacRepSur DSYExport
#else
#define ExportedByFacRepSur DSYImport
#endif
#include "DSYExport.h"
