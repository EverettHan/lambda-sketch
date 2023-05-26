//=======================================================================================
/** WARNING: YWE 17:07:05 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
//=======================================================================================
/* CATDbProvider.h : COPYRIGHT DASSAULT SYSTEMES 2011 */

/**
*  @level Protected
*  @usage U1
*/

#ifndef CATDbProvider_H
#define CATDbProvider_H


#include "CATIAV5Level.h" // YWE/CEV-2017.07-For Single Code support

//=420-YWE-2017.07-Start New Code for ComputeServer support ===================================
#if defined (__CATDbProvider)
#define ExportedByCATDbProvider DSYExport
#else
#define ExportedByCATDbProvider DSYImport
#endif
#include "DSYExport.h"
//=420-YWE-2017.07-Final New Code for ComputeServer support ===================================

#endif


