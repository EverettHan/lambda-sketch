//=======================================================================================
/** WARNING: YWE 17:07:05 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
//=======================================================================================
//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2013 - CATIA V6R216                          
//===========================================================================
// September, 7th 2013 - Creation: YWE
//===========================================================================
//                                 
//===========================================================================

#ifndef ExportedByCATXMLReporter_H
#define ExportedByCATXMLReporter_H

#include "CATIAV5Level.h" // YWE/CEV-2017.07-For Single Code support

//=420-YWE-2017.07-Start New Code for ComputeServer support ===================================
#if defined __CATXMLReporter
#define ExportedByCATXMLReporter DSYExport
#else
#define ExportedByCATXMLReporter DSYImport
#endif
#include "DSYExport.h"
//=420-YWE-2017.07-Final New Code for ComputeServer support ===================================

#endif


