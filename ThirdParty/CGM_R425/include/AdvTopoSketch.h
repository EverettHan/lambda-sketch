#ifdef _STATIC_SOURCE
#define	ExportedByAdvTopoSketch
#elif defined __AdvTopoSketch


// COPYRIGHT DASSAULT SYSTEMES 1999

/** @CAA2Required */

/*---------------------------------------------------------------------*/

/* DON'T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS  */

/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPPEAR AT ANY TIME */

/*---------------------------------------------------------------------*/
#define ExportedByAdvTopoSketch DSYExport
#else
#define ExportedByAdvTopoSketch DSYImport
#endif
#include "DSYExport.h"
#include <TopologicalOperatorsCommonDec.h>
