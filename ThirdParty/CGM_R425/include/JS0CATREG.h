#ifndef JS0CATREG_INCLUDE
#define JS0CATREG_INCLUDE

/************************************************************************/
/* Defines                                                              */
/************************************************************************/
#if defined(__JS0CATREG)
# define ExportedByJS0CATREG  DSYExport
#else  // __JS0CATREG
# define ExportedByJS0CATREG  DSYImport
#endif // __JS0CATREG

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "DSYExport.h"

#endif
