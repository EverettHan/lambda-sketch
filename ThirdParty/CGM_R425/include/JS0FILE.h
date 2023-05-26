#ifndef _JS0FILE_INCLUDE
#define _JS0FILE_INCLUDE

/************************************************************************/
/* Defines                                                              */
/************************************************************************/
#if defined(__JS0FILE)
# define ExportedByJS0FILE  DSYExport
#else  // __JS0FILE
# define ExportedByJS0FILE  DSYImport
#endif // __JS0FILE

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "DSYExport.h"

#endif
