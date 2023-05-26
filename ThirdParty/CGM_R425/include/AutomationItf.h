// COPYRIGHT DASSAULT SYSTEMES 2003
#if defined(__CATScriptItfBase) || (__CATScriptReferences)

/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/
#define ExportedByCATAutoItf DSYExport
#else
#define ExportedByCATAutoItf DSYImport
#endif
#include "DSYExport.h"
