
// COPYRIGHT DASSAULT SYSTEMES 2000
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/*********************************************************************/
#undef ExportedByApplicationFrame
#ifdef __CATAfrFoundation

//#define ExportedByApplicationFrame  ExportedByCATAfrFoundation 
#define ExportedByApplicationFrame DSYExport
#else
#define ExportedByApplicationFrame DSYImport
#endif
#include "DSYExport.h"
