//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2014 => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
//===================================================================
// COPYRIGHT Dassault Systemes 2013
//===================================================================
/**
  * @quickreview	C3O		22:03:11	R424AssessedForLinux
  */
#include "CATIAV5Level.h" // YWE/CEV-2018.11-For Single Code support

#ifdef CATIAR420
//=420-YWE-2018.11-Start New Code for ComputeServer support ===================================
#if defined(__PLMExchangeGlobalServices)
#define ExportedByPLMExchangeGlobalServices DSYExport
#else
#define ExportedByPLMExchangeGlobalServices DSYImport
#endif
#include "DSYExport.h"
//=420-YWE-2018.11-Final New Code for ComputeServer support ===================================
#else
//=419-YWE-2018.11-Start Old Code before ComputeServer support ================================
#ifdef  _WINDOWS_SOURCE
#ifdef  __PLMExchangeGlobalServices
#define ExportedByPLMExchangeGlobalServices     __declspec(dllexport)
#else
#define ExportedByPLMExchangeGlobalServices     __declspec(dllimport)
#endif
#else
#define ExportedByPLMExchangeGlobalServices
#endif
//=419-YWE-2018.11-Final Old Code before ComputeServer support ================================
#endif
 
