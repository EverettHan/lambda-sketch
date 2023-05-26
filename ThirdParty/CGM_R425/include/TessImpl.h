#ifdef _STATIC_SOURCE
#define	ExportedByTessImpl
#elif defined __CATTessellation

// COPYRIGHT DASSAULT SYSTEMES 1999
/** @CAA2Required */
/*---------------------------------------------------------------------*/
/* DON'T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS  */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPPEAR AT ANY TIME */
/*---------------------------------------------------------------------*/
#define ExportedByTessImpl DSYExport
#else
#define ExportedByTessImpl DSYImport
#endif
#include "DSYExport.h"

