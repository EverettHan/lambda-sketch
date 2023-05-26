#ifdef _STATIC_SOURCE
#define	ExportedByCATSubdOperator
#elif defined __CATSubdOperator
#define ExportedByCATSubdOperator DSYExport
#else
#define ExportedByCATSubdOperator DSYImport
#endif
#include "DSYExport.h"
