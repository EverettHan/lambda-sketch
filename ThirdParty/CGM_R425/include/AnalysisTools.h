//------------------------------------------------------------------------------
#ifdef _STATIC_SOURCE
#define	ExportedByAnalysisTools
#elif defined __AnalysisTools


// COPYRIGHT DASSAULT SYSTEMES 1999

/** @CAA2Required */

/*---------------------------------------------------------------------*/

/* DON'T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS  */

/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPPEAR AT ANY TIME */

/*---------------------------------------------------------------------*/
#define ExportedByAnalysisTools DSYExport
#else
#define ExportedByAnalysisTools DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
//------------------------------------------------------------------------------
