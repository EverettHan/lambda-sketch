//=======================================================================================
/** WARNING: YWE 17:07:05 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
//=======================================================================================
/* XPDMServices.h : COPYRIGHT DASSAULT SYSTEMES 2001 */

/**
*  @level Protected
*  @usage U1
*/

#ifndef XPDMServices_H
#define XPDMServices_H

#include "CATIAV5Level.h" // YWE/CEV-2017.07-For Single Code support

#ifdef CATIAR420
#if defined (__XPDMServices)
#define ExportedByXPDMServices DSYExport
#else
#define ExportedByXPDMServices DSYImport
#endif
#include "DSYExport.h"
#endif
#endif



