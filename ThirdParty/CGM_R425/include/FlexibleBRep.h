#ifdef _STATIC_SOURCE
#define	ExportedByFlexibleBRep
#elif defined __FlexibleBRep
#define ExportedByFlexibleBRep DSYExport
#else
#define ExportedByFlexibleBRep DSYImport
#endif
#include "DSYExport.h"
