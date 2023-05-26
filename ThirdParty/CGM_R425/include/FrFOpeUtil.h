#ifdef _STATIC_SOURCE
#define ExportedByFrFOpeUtil
#elif defined __FrFOpeUtil
#define ExportedByFrFOpeUtil DSYExport
#else
#define ExportedByFrFOpeUtil DSYImport
#endif
#include "DSYExport.h"
#include <FrFCommonDec.h>
