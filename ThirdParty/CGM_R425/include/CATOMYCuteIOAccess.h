#if defined(__CATOMYCuteIOAccess)
#define ExportedByCATOMYCuteIOAccess DSYExport
#else
#define ExportedByCATOMYCuteIOAccess DSYImport
#endif
#include "DSYExport.h"


#include "CATIAV5Level.h"
#if defined(CATIAR424) & !defined(__CATOMYCuteIOAccess)
#define CuteIOAccessIterCompileError 1
#endif
