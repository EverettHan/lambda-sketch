#ifdef _STATIC_SOURCE
#define	ExportedByThickLight
#elif defined __ThickLight

// COPYRIGHT DASSAULT SYSTEMES 2008
/*---------------------------------------------------------------------*/
/* DON'T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS  */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPPEAR AT ANY TIME */
/*---------------------------------------------------------------------*/
#define ExportedByThickLight DSYExport
#else
#define ExportedByThickLight DSYImport
#endif
#include "DSYExport.h"
//#include "TopologicalOperatorsLightCommonDec.h"
