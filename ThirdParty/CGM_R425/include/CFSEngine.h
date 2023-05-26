//------------------------------------------------------------------------------
#ifdef _STATIC_SOURCE
#define	ExportedByCFSEngine
#elif defined __CFSEngine
#define ExportedByCFSEngine DSYExport
#else
#define ExportedByCFSEngine DSYImport
#endif
#include "DSYExport.h"
//------------------------------------------------------------------------------
#include "TopologicalOperatorsCommonDec.h"
