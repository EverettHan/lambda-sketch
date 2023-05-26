#ifdef _STATIC_SOURCE
#define ExportedByFrFEquation
#elif defined __FrFEquation
#define ExportedByFrFEquation DSYExport
#else
#define ExportedByFrFEquation DSYImport
#endif
#include "DSYExport.h"
#include <FrFCommonDec.h>
