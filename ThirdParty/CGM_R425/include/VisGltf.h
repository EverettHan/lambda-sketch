/* COPYRIGHT DASSAULT SYSTEMES 2020 */

#ifndef  INLINE
#if defined(_WINDOWS_SOURCE) && defined(_MSC_VER) && _MSC_VER>1300
#define  INLINE     __forceinline
#else
#define  INLINE     inline
#endif
#endif


#if defined(__VisGltf)
#define ExportedByVisGltf DSYExport
#else
#define ExportedByVisGltf DSYImport
#endif
#include "DSYExport.h"

