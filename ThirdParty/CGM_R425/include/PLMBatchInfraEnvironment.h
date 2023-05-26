/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2013
//===========================================================================
// Usage Notes:   
//===========================================================================
// January 2013   Creation                  UHE 
// 
//===========================================================================
/** 
* @level Protected 
* @usage U1
*/
#ifndef PLMBatchInfraEnvironment_h
#define PLMBatchInfraEnvironment_h

#include "ExportedByPLMBatchInfraServices.h"
#include "CATUnicodeString.h"

class ExportedByPLMBatchInfraServices PLMBatchInfraEnvironment 
{
	
public:

	static CATUnicodeString IsDbContextEnvironmentActivated();
	static int _RecordLevel(const int RecordLevel, const char *RecordLevelName);
};



#endif
