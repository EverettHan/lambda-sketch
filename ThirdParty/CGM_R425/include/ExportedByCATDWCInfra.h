//=======================================================================================
/** WARNING: YWE 17:07:05 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
//=======================================================================================
/* CATDWCInfra.h : COPYRIGHT DASSAULT SYSTEMES 2001 */

/**
*  @level Protected
*  @usage U1
*/

#ifndef CATDWCInfra_H
#define CATDWCInfra_H

#include "CATIAV5Level.h" // YWE/CEV-2017.07-For Single Code support

//=420-YWE-2017.07-Start New Code for ComputeServer support ===================================
#if defined (__CATDWCInfra)
#define ExportedByCATDWCInfra DSYExport
#else
#define ExportedByCATDWCInfra DSYImport
#endif
#include "DSYExport.h"
//=420-YWE-2017.07-Final New Code for ComputeServer support ===================================

#endif


