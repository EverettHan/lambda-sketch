//------------------------------------------------------------------------------
#ifdef _STATIC_SOURCE
#define	ExportedByAssembler
#elif defined __Assembler
#define ExportedByAssembler DSYExport
#else
#define ExportedByAssembler DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
//------------------------------------------------------------------------------
