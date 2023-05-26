//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2015/05/01
//===================================================================

#ifndef CSICommandBinderModule_H
#define CSICommandBinderModule_H

#include "DSYExport.h"

#ifndef CSI_NO_EXPORTS
#ifdef _STATIC_SOURCE
#define CSI_NO_EXPORTS
#endif /*_STATIC_SOURCE*/
#endif

#ifdef CSI_NO_EXPORTS
# define ExportedByCSIBinderModule DSYLocal
#else
# ifdef __CSICommandBinder
#  define ExportedByCSIBinderModule DSYExport
# else
#  define ExportedByCSIBinderModule DSYImport
# endif
#endif /*CSI_NO_EXPORTS*/

#endif /*CSICommandBinderModule_H*/
