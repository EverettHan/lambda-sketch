#ifndef JS0SMT_INCLUDE
#define JS0SMT_INCLUDE

/************************************************************************/
/* Defines                                                              */
/************************************************************************/
#if defined(__JS0SMT)
# define ExportedByJS0SMT   DSYExport
#else  // __JS0SMT
# define ExportedByJS0SMT   DSYImport
#endif // __JS0SMT

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "DSYExport.h"

#endif
