#ifdef _STATIC_SOURCE
#define	ExportedByRibbon
#elif defined __Ribbon


// COPYRIGHT DASSAULT SYSTEMES 1999

/** @CAA2Required */

/*---------------------------------------------------------------------*/

/* DON'T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS  */

/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPPEAR AT ANY TIME */

/*---------------------------------------------------------------------*/
#define ExportedByRibbon DSYExport
#else
#define ExportedByRibbon DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
