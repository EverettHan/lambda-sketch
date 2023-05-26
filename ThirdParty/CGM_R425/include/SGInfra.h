/* COPYRIGHT DASSAULT SYSTEMES 1999 */
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

#ifndef  INLINE
#if defined(_WINDOWS_SOURCE) && defined(_MSC_VER) && _MSC_VER>1300
#define  INLINE     __forceinline
#else
#define  INLINE     inline
#endif
#endif


#if defined(__SGInfra)
#define ExportedBySGInfra DSYExport
#else
#define ExportedBySGInfra DSYImport
#endif
#include "DSYExport.h"

#define ADDREFERENCE_MIGRATION
//#define REMOVE_USELESS_INCLUDE
