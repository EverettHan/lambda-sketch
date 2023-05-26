#ifndef V4SysANL_INCLUDE
#define V4SysANL_INCLUDE

#if defined __V4SysANL
#define ExportedByV4SysANL DSYExport
#else
#define ExportedByV4SysANL DSYImport
#endif
#include "DSYExport.h"

#endif /* V4SysANL_INCLUDE */
