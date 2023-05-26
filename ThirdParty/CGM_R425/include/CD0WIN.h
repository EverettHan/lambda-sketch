
// COPYRIGHT DASSAULT SYSTEMES 2000
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

#undef ExportedByCD0WIN
#ifdef __CATAfrWin

//#define ExportedByCD0WIN  ExportedByCATAfrFoundation 
#define ExportedByCD0WIN DSYExport
#else
#define ExportedByCD0WIN DSYImport
#endif
#include "DSYExport.h"
