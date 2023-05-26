#ifdef _STATIC_SOURCE
#define	ExportedByCATGMPolyObjects
#elif defined __CATGMPolyObjects
#define ExportedByCATGMPolyObjects DSYExport
#else
#define ExportedByCATGMPolyObjects DSYImport
#endif
#include "DSYExport.h"
