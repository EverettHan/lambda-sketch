
// COPYRIGHT DASSAULT SYSTEMES 2000
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

#undef ExportedByCD0APPLI
#ifdef __CATAfrAppli

//#define ExportedByCD0APPLI  ExportedByCATAfrFoundation 
#define ExportedByCD0APPLI DSYExport
#else
#define ExportedByCD0APPLI DSYImport
#endif
#include "DSYExport.h"
