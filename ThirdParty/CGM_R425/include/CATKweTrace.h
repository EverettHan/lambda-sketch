//===================================================================
// CATCATKweTrace
// Header definition of class CATKweTrace
//===================================================================
//
// Usage notes: Trace objects repository
//
//===================================================================
//  24.11.20 Creation KJD
//===================================================================/**

#ifndef CATKweTrace_h
#define CATKweTrace_h

#include "CATLifSpecs.h"
#include "CATKweConvertClass.h"

// FW SystemTS
#include "CATUnicodeString.h"
#include "CATUnicodeChar.h"
#include "DSYSysTSLib.h"

class CATUnicodeString;

//----------------------------------------------------------------------
// CATKweTrace
//----------------------------------------------------------------------
class ExportedByCATLifSpecs CATKweTrace
{

public:
  CATKweTrace(const CATUnicodeString& iName, CATKweConvertClass* iConverter);
  virtual ~CATKweTrace();

  // Enter / Exit method services
  void EnterMethod(const CATUnicodeString& iMethodName);
  void ExitMethod(const CATUnicodeString& iMethodName);
  void ExitMethodWithHRESULT(const CATUnicodeString& iMethodName, HRESULT iHR);

  // Trace Services
  void DumpTrace();
  bool IsConfigured();

  // Converter class  
  CATKweConvertClass* _pConverter;

private:
  void* _pTraceHandle;
  int _dIndent;
  CATUnicodeString _usIndent;
};

//----------------------------------------------------------------------
// Macros are defined in CATKweTraceMacros.h
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Exposed Trace declarations
//----------------------------------------------------------------------
extern ExportedByCATLifSpecs CATKweTrace CATKweModelerTrace;
extern ExportedByCATLifSpecs CATKweTrace CATEKLPythonTrace;
extern ExportedByCATLifSpecs CATKweTrace CATPyBindingsTrace;
extern ExportedByCATLifSpecs CATKweTrace CATKACBatchTrace;
extern ExportedByCATLifSpecs CATKweTrace CATProxyParamTrace;
extern ExportedByCATLifSpecs CATKweTrace CATKnowlFederatedSearchTrace;
extern ExportedByCATLifSpecs CATKweTrace CATEvalContextTrace;
extern ExportedByCATLifSpecs CATKweTrace CATPowerCopyReorderInputTrace;
extern ExportedByCATLifSpecs CATKweTrace CATPEOSolverTrace;
extern ExportedByCATLifSpecs CATKweTrace CATKweEvalTrace;
extern ExportedByCATLifSpecs CATKweTrace CATKweSelectionAgentTrace;
extern ExportedByCATLifSpecs CATKweTrace CATKweResourceMgtTrace;
extern ExportedByCATLifSpecs CATKweTrace CATLinkManagerTrace;
extern ExportedByCATLifSpecs CATKweTrace CATKBABuildtimeTrace;
#endif

