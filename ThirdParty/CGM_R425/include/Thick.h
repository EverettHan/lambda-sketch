#ifdef _STATIC_SOURCE
#define	ExportedByThick
#elif defined __Thick


// COPYRIGHT DASSAULT SYSTEMES 1999

/** @CAA2Required */

/*---------------------------------------------------------------------*/

/* DON'T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS  */

/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPPEAR AT ANY TIME */

/*---------------------------------------------------------------------*/
#define ExportedByThick DSYExport
#else
#define ExportedByThick DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
