#ifndef JS03TRA_H
#define JS03TRA_H

/* COPYRIGHT DASSAULT SYSTEMES 2000 */
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

/************************************************************************/
/* Defines                                                              */
/************************************************************************/
#if defined(__JS03TRA)
# define ExportedByJS03TRA  DSYExport
#else  /* __JS03TRA */
# define ExportedByJS03TRA  DSYImport
#endif /* __JS03TRA */

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "DSYExport.h"

#endif  /* JS03TRA_H */
