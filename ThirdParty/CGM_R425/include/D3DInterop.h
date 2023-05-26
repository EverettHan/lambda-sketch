#if defined(__Direct3DInteropItf)

#define ExportedByD3DInterop DSYExport
#else
#define ExportedByD3DInterop DSYImport
#endif
#include "DSYExport.h"
