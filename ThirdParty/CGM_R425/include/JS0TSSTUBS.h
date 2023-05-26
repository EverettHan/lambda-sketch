#ifndef _JS0TSSTUBS_H
#define _JS0TSSTUBS_H
/* COPYRIGHT DASSAULT SYSTEMES 2011 */
/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "DSYExport.h"

/************************************************************************/
/* Defines                                                              */
/************************************************************************/
#if defined(__JS0TSSTUBS)
# define ExportedByJS0TSSTUBS   DSYExport
#else // __JS0TSSTUBS
# define ExportedByJS0TSSTUBS   DSYImport
#endif  // __JS0TSSTUBS



#endif
