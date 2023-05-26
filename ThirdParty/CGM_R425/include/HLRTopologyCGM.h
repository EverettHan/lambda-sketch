#ifdef _STATIC_SOURCE
#define	ExportedByHLRTopologyCGM
#elif defined __HLRTopologyCGM
#define ExportedByHLRTopologyCGM DSYExport
#else
#define ExportedByHLRTopologyCGM DSYImport
#endif
#include "DSYExport.h"
