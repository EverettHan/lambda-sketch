#ifdef _STATIC_SOURCE
#define	ExportedByTessAPI
#elif defined __TessAPI


// COPYRIGHT DASSAULT SYSTEMES 1999

/** @required */

/*---------------------------------------------------------------------*/

/* DON'T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS  */

/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPPEAR AT ANY TIME */

/*---------------------------------------------------------------------*/
#define ExportedByTessAPI DSYExport
#else
#define ExportedByTessAPI DSYImport
#endif
#include "DSYExport.h"
