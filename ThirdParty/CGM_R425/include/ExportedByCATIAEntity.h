/**
 * @level Private
 * @usage U1
 */
/* ExportedByCATIAEntity.h : COPYRIGHT DASSAULT SYSTEMES 1996 */
#ifndef  ExportedByCATIAEntity_h
#define  ExportedByCATIAEntity_h

#if defined (__CATIAEntity)
#define ExportedByCATIAEntity DSYExport
#else
#define ExportedByCATIAEntity DSYImport
#endif
#include "DSYExport.h"

#endif   /* ExportedByCATIAEntity_h */
