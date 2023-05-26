//------------------------------------------------------------------------------
#ifdef _STATIC_SOURCE
#define	ExportedByHybBoolean
#elif defined __HybBoolean
#define ExportedByHybBoolean DSYExport
#else
#define ExportedByHybBoolean DSYImport
#endif
#include "DSYExport.h"
//------------------------------------------------------------------------------
#include "TopologicalOperatorsCommonDec.h"
