#ifdef _STATIC_SOURCE
#define	ExportedByCATCXTopology
#elif defined __CATCXTopology
#define ExportedByCATCXTopology DSYExport
#else
#define ExportedByCATCXTopology DSYImport
#endif
#include "DSYExport.h"
