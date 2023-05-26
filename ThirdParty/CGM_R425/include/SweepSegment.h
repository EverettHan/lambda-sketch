#ifdef _STATIC_SOURCE
#define	ExportedBySweepSegment
#elif defined __SweepSegment
#define ExportedBySweepSegment DSYExport
#else
#define ExportedBySweepSegment DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
