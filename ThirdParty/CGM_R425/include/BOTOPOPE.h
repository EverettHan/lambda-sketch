#ifdef _STATIC_SOURCE
#define	ExportedByBOTOPOPE
#elif defined __BOTOPOPE


// COPYRIGHT DASSAULT SYSTEMES 1999

/** @CAA2Required */

/*---------------------------------------------------------------------*/

/* DON'T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS  */

/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPPEAR AT ANY TIME */

/*---------------------------------------------------------------------*/
#define ExportedByBOTOPOPE DSYExport
#else
#define ExportedByBOTOPOPE DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
