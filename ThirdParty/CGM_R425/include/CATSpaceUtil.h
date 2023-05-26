// COPYRIGHT DASSAULT SYSTEMES 1999

#ifndef CATSpaceUtil_H
#define CATSpaceUtil_H

#include "CATVisFoundation.h"

#if !defined (_NO_X11_SOURCE) && (defined (_LINUX_SOURCE) || defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE))
#include <Xm/Xm.h>
#endif

extern ExportedByCATVisFoundation int CATSpaceIsDriverInstalled(void *display);

#if defined (_WINDOWS_SOURCE)
extern ExportedByCATVisFoundation HWND CATSpaceGetDriverWindow(void);
extern ExportedByCATVisFoundation int CATSpaceIs3DMouseAttached();
#endif

#if !defined (_NO_X11_SOURCE) && (defined (_LINUX_SOURCE) || defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE))
extern ExportedByCATVisFoundation Window CATSpaceGetDriverWindow(Display *display);
#endif

#endif
