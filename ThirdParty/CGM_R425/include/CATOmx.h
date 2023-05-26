// COPYRIGHT DASSAULT SYSTEMES 2013
/**
* @CAA2Required
*/

#ifndef __CATOmx_h__
#define __CATOmx_h__
#include "DSYExport.h"
#ifdef  __CATOmxKernel
#define ExportedByCATOmxKernel  DSYExport
#else
#define ExportedByCATOmxKernel  DSYImport
#endif
#endif
