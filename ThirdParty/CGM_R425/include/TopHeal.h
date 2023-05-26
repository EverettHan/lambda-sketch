#ifdef _STATIC_SOURCE
#define	ExportedByTopHeal
#elif defined __TopHeal
#define ExportedByTopHeal DSYExport
#else
#define ExportedByTopHeal DSYImport
#endif
#include "DSYExport.h"

