/* COPYRIGHT DASSAULT SYSTEMES 1999 */

#ifndef  INLINE
#if defined(_WINDOWS_SOURCE) && defined(_MSC_VER) && _MSC_VER>1300
#define  INLINE     __forceinline
#else
#define  INLINE     inline
#endif
#endif


#if defined(__CAT3DXM)
#define ExportedByCAT3DXM DSYExport
#else
#define ExportedByCAT3DXM DSYImport
#endif
#include "DSYExport.h"

