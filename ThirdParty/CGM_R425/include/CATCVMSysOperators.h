#ifdef _STATIC_SOURCE
#define	ExportedByCATCVMSysOperators
#elif defined(__CATCVMSysOperators)
#define ExportedByCATCVMSysOperators DSYExport
#else
#define ExportedByCATCVMSysOperators DSYImport
#endif
#include "DSYExport.h"
