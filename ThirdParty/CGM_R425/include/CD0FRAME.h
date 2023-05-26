
// COPYRIGHT DASSAULT SYSTEMES 2000
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

#undef ExportedByCD0FRAME
#ifdef __CATAfrFrame

//#define ExportedByCD0FRAME  ExportedByCATAfrFoundation 
#define ExportedByCD0FRAME DSYExport
#else
#define ExportedByCD0FRAME DSYImport
#endif
#include "DSYExport.h"
