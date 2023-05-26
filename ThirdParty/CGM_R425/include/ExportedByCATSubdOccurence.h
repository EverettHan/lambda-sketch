#ifdef _STATIC_SOURCE
#define	ExportedByCATSubdOccurence
#elif defined __CATSubdOccurence
#define ExportedByCATSubdOccurence DSYExport
#else
#define ExportedByCATSubdOccurence DSYImport
#endif
#include "DSYExport.h"
