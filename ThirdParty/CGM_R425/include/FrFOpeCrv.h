#ifdef _STATIC_SOURCE
#define	ExportedByFrFOpeCrv
#elif defined __FrFOpeCrv
#define ExportedByFrFOpeCrv DSYExport
#else
#define ExportedByFrFOpeCrv DSYImport
#endif
#include "DSYExport.h"
#include <FrFCommonDec.h>
