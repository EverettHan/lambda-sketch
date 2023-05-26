//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2016/11/28
//===================================================================

#ifndef CSINodesLauncherModule_H
#define CSINodesLauncherModule_H

#include "DSYExport.h"

#ifndef CSIMAIN_NO_EXPORTS
#ifdef _STATIC_SOURCE
#define CSIMAIN_NO_EXPORTS
#endif /*_STATIC_SOURCE*/
#endif

#ifdef CSIMAIN_NO_EXPORTS
# define ExportedByCSINodesLauncherSrc DSYLocal
#else
# ifdef __CSINodesLauncherSrc
#  define ExportedByCSINodesLauncherSrc DSYExport
# else
#  define ExportedByCSINodesLauncherSrc DSYImport
# endif
#endif /*CSI_NO_EXPORTS*/

namespace CSI
{
  ExportedByCSINodesLauncherSrc int csiMain(int argc, char** argv);
  ExportedByCSINodesLauncherSrc int csiMain(int argc, char** argv, const char* pool);
}

#endif /*CSINodesLauncherModule_H*/
