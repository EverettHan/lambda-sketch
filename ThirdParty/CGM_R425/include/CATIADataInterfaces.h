/**
 * @level Private
 * @usage U1
 */
#ifndef CATIADataInterfaces_h
#define CATIADataInterfaces_h

   /*---------------------------------------------------------------*/
   /*  Framework temporaire pour les anciens usagers de CATV4Model  */
   /*---------------------------------------------------------------*/

#if defined (__CATIAEntity)
#define ExportedByCATIAEntity DSYExport
#else
#define ExportedByCATIAEntity DSYImport
#endif

#if defined (__CATGEOBasic)
#define ExportedByCATGEOBasic DSYExport
#else
#define ExportedByCATGEOBasic DSYImport
#endif

#if defined (__CATIAErase)
#define ExportedByCATIAErase DSYExport
#else
#define ExportedByCATIAErase DSYImport
#endif


#define ExportedByCATIAStorage  DSYImport

   /*-----------------------------------------------------------------*/
   /*  Frameworks temporaires pour les anciens usagers de CATV4Model  */
   /*-----------------------------------------------------------------*/

#if defined (__CATV4delta)
#define ExportedByCATV4delta DSYExport
#else
#define ExportedByCATV4delta DSYImport
#endif

#if defined (__CATV4epsilon)
#define ExportedByCATV4epsilon DSYExport
#else
#define ExportedByCATV4epsilon DSYImport
#endif
#include "DSYExport.h"

#endif
/* 10.03.97 */
