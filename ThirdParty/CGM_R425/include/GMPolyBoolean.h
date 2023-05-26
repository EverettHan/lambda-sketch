#ifdef _STATIC_SOURCE
#define	ExportedByGMPolyBoolean
#elif defined __GMPolyBoolean
#define ExportedByGMPolyBoolean DSYExport
#else
#define ExportedByGMPolyBoolean DSYImport
#endif
#include "DSYExport.h"
