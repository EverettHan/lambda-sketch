#ifndef JS0LICS_INCLUDE
#define JS0LICS_INCLUDE

#if defined(__CATLICSERVER)
#define ExportedByJS0LICS DSYExport
#else
#define ExportedByJS0LICS DSYImport
#endif
#include "DSYExport.h"

#endif /* JS0LICS_INCLUDE */
