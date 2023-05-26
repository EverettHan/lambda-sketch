#ifdef _STATIC_SOURCE
#define	ExportedByFrFOpeSur
#elif defined __FrFOpeSur
#define ExportedByFrFOpeSur DSYExport
#else
#define ExportedByFrFOpeSur DSYImport
#endif
#include "DSYExport.h"
#include <FrFCommonDec.h>
