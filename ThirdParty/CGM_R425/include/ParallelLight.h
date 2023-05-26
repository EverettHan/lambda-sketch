#ifdef _STATIC_SOURCE
#define	ExportedByParallelLight
#elif defined __ParallelLight


// COPYRIGHT DASSAULT SYSTEMES 2010

/** @CAA2Required */

/*---------------------------------------------------------------------*/

/* DON'T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS  */

/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPPEAR AT ANY TIME */

/*---------------------------------------------------------------------*/
#define ExportedByParallelLight DSYExport
#else
#define ExportedByParallelLight DSYImport
#endif
#include "DSYExport.h"
//#include "TopologicalOperatorsLightCommonDec.h"
