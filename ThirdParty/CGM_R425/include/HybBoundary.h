//------------------------------------------------------------------------------
#ifdef _STATIC_SOURCE
#define	ExportedByHybBoundary
#elif defined __HybBoundary
#define ExportedByHybBoundary DSYExport
#else
#define ExportedByHybBoundary DSYImport
#endif
#include "DSYExport.h"
//------------------------------------------------------------------------------
#include "TopologicalOperatorsCommonDec.h"
