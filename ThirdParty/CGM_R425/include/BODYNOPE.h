#ifdef _STATIC_SOURCE
#define	ExportedByBODYNOPE
#elif defined __BODYNOPE


// COPYRIGHT DASSAULT SYSTEMES 1999

/** @CAA2Required */
#define ExportedByBODYNOPE DSYExport
#else
#define ExportedByBODYNOPE DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
