#ifdef _STATIC_SOURCE
#define	ExportedByRibbonLight
#elif defined __RibbonLight

// COPYRIGHT DASSAULT SYSTEMES 2008
/*---------------------------------------------------------------------*/
/* DON'T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS  */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPPEAR AT ANY TIME */
/*---------------------------------------------------------------------*/
#define ExportedByRibbonLight DSYExport
#else
#define ExportedByRibbonLight DSYImport
#endif
#include "DSYExport.h"
//#include "TopologicalOperatorsLightCommonDec.h"
