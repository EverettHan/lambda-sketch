//------------------------------------------------------------------------------
#ifdef _STATIC_SOURCE
#define	ExportedByHybOper
#elif defined __HybOper


// COPYRIGHT DASSAULT SYSTEMES 2010

/** @CAA2Required */

/*---------------------------------------------------------------------*/

/* DON'T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS  */

/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPPEAR AT ANY TIME */

/*---------------------------------------------------------------------*/
#define ExportedByHybOper DSYExport
#else
#define ExportedByHybOper DSYImport
#endif
#include "DSYExport.h"
//#include "TopologicalOperatorsLightCommonDec.h"
//------------------------------------------------------------------------------
