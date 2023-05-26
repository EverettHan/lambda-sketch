#ifdef _STATIC_SOURCE
#define  ExportedByCATFrFNetSurface
#elif defined(__CATFrFNetSurface)
#define ExportedByCATFrFNetSurface DSYExport
#else
#define ExportedByCATFrFNetSurface DSYImport
#endif
#include "DSYExport.h"
#include <FrFCommonDec.h>
