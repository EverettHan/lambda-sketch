#ifdef _STATIC_SOURCE
#define	ExportedByFillet
#elif	__Fillet
// COPYRIGHT DASSAULT SYSTEMES 1999
/** @CAA2Required */
#define ExportedByFillet DSYExport
#else
#define	ExportedByFillet	DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
