//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2014x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2013/02/18
//===================================================================
// Header definition of class PLMExchangeInterfaces
//===================================================================
//
// Usage notes: Declaration of the interface module.
//
/**
  * @quickreview	C3O		22:03:11	R424AssessedForLinux
  */
#include "CATIAV5Level.h" // YWE/CEV-2018.11-For Single Code support

#ifdef CATIAR420
//=420-YWE-2018.11-Start New Code for ComputeServer support ===================================
#if defined(__PLMExchangeInterfaces)
#define ExportedByPLMExchangeInterfaces DSYExport
#else
#define ExportedByPLMExchangeInterfaces DSYImport
#endif
#include "DSYExport.h"
//=420-YWE-2018.11-Final New Code for ComputeServer support ===================================
#else
//=419-YWE-2018.11-Start Old Code before ComputeServer support ================================
#ifdef  _WINDOWS_SOURCE
#ifdef  __PLMExchangeInterfaces
#define ExportedByPLMExchangeInterfaces     __declspec(dllexport)
#else
#define ExportedByPLMExchangeInterfaces     __declspec(dllimport)
#endif
#else
#define ExportedByPLMExchangeInterfaces
#endif
//=419-YWE-2018.11-Final Old Code before ComputeServer support ================================
#endif
 
