#ifdef _STATIC_SOURCE
#define ExportedByFreeFormOpeItf
#elif defined __FreeFormOpeItf
#define ExportedByFreeFormOpeItf DSYExport
#else
#define ExportedByFreeFormOpeItf DSYImport
#endif
#include "DSYExport.h"
