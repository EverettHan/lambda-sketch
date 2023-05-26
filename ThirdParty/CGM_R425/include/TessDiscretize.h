#ifdef _STATIC_SOURCE
#define	ExportedByTessDiscretize
#elif defined __TessDiscretize
#define ExportedByTessDiscretize DSYExport
#else
#define ExportedByTessDiscretize DSYImport
#endif
#include "DSYExport.h"
