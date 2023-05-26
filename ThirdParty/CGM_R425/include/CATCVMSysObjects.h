#ifdef _STATIC_SOURCE
#define	ExportedByCATCVMSysObjects
#elif defined(__CATCVMSysObjects)
#define ExportedByCATCVMSysObjects DSYExport
#else
#define ExportedByCATCVMSysObjects DSYImport
#endif
#include "DSYExport.h"
