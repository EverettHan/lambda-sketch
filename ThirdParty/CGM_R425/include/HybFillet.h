//------------------------------------------------------------------------------
#ifdef _STATIC_SOURCE
#define	ExportedByHybFillet
#elif defined __HybFillet
#define ExportedByHybFillet DSYExport
#else
#define ExportedByHybFillet DSYImport
#endif
#include "DSYExport.h"
//------------------------------------------------------------------------------
#include "TopologicalOperatorsCommonDec.h"
