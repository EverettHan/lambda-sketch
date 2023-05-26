/**
 * @level Private
 * @usage U1
 */
#ifndef __CATOmp_h__
#define __CATOmp_h__
#include "CATOmxExport.h"
#ifdef	__CATOmp
#define	ExportedByCATOmp	DSYExport
#else
#define	ExportedByCATOmp	DSYImport
#endif
#endif
