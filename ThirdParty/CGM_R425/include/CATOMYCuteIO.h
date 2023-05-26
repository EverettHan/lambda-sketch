#if defined(__CATOMYCuteIO)
#define ExportedByCATOMYCuteIO DSYExport
#else
#define ExportedByCATOMYCuteIO DSYImport
#endif
#include "DSYExport.h"

#include "CATIAV5Level.h"
#if defined(CATIAR424) & !defined(__CATOMYCuteIO)
#define CuteIOIterCompileError 1
#endif
