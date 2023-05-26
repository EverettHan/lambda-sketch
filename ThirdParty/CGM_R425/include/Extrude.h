#ifdef _STATIC_SOURCE
#define  ExportedByExtrude
#elif defined __Extrude
#define ExportedByExtrude DSYExport
#else
#define ExportedByExtrude DSYImport
#endif
#include "DSYExport.h"
#include <FrFCommonDec.h>
