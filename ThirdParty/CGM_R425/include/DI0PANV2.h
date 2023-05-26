
// COPYRIGHT DASSAULT SYSTEMES 2000
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

#ifndef DI0PANV2_H
#define DI0PANV2_H

#ifdef DRIVER_DYNAMIC

#elif defined (_WINDOWS_SOURCE)
#define DRIVER_WINDOWS

#elif defined (_COCOA_SOURCE)
#define DRIVER_COCOA

#elif defined (_ANDROID_SOURCE)
#define DRIVER_ANDROID

#elif defined (_LINUX_SOURCE) || defined (_AIX_SOURCE) || defined (_DARWIN_SOURCE) || defined(_IRIX_SOURCE) || defined(_SUNOS_SOURCE) || defined(_HPUX_SOURCE)
#define DRIVER_MOTIF

#else
#error "Unsupported OS detected in DI0PANV2.h"

#endif

#if defined __DI0PANV2
#define ExportedByDI0PANV2 DSYExport
#else
#define ExportedByDI0PANV2 DSYImport
#endif
#include "DSYExport.h"
#endif

