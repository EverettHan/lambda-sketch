#ifdef _STATIC_SOURCE
#define	ExportedByDraft
#elif defined __Draft
#define ExportedByDraft DSYExport
#else
#define ExportedByDraft DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
