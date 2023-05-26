// COPYRIGHT DASSAULT SYSTEMES 2004 

/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

#ifdef __VisuDialog

#define ExportedByVisuDialog DSYExport
#else
#define ExportedByVisuDialog DSYImport
#endif
#include "DSYExport.h"

#include <VisuDialogDoc.h>
