// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATPLMEKLBindingToolbox.h
// Header definition of CATPLMEKLBindingToolbox
//
//===================================================================
//

#ifndef CATPLMEKLBindingToolbox_H
#define CATPLMEKLBindingToolbox_H

#include "CATPLMAdapterEKLBinding.h"
#include "CATListOfCATString.h"
#include "CATErrors.h"

class CATUnicodeString;
class CATICkeExpression_var;

class ExportedByCATPLMAdapterEKLBinding CATPLMEKLBindingToolbox
{
public:

  static HRESULT GetFunctionExpression(const CATString & iPackageName, const CATString & iFunctionName, CATUnicodeString & oFunctionExpression);
  static HRESULT GetProcedureExpression(const CATString & iProcedureName, CATICkeExpression_var & oProcedureExpression);
  static HRESULT SetProcedureExpression(const CATString & iProcedureName, CATICkeExpression_var & iProcedureExpression);
  // return S_FALSE if procedure repository is read only
  static HRESULT GetListOfProcedureNames(CATListOfCATString & oProcedureNamesList);
  static HRESULT CreateEmptyProcedure(const CATString & iProcedureName);

  static CATUnicodeString GetProcedureLocalRepository();
  static CATUnicodeString GetFunctionLocalRepository();
  static HRESULT GetFunctionFilePathLocal(const CATString & iFunctionName, CATUnicodeString & oFunctionFilePath);
  static HRESULT GetFunctionFilePathDico(const CATString & iPackageName, const CATString & iFunctionName, CATUnicodeString & oFunctionFilePath);
  static HRESULT GetProcedureFilePathLocal(const CATString & iProcedureName, CATUnicodeString & oProcedureFilePath);
  static HRESULT GetProcedureFilePathDico(const CATString & iProcedureName, CATUnicodeString & oProcedureFilePath);
  static HRESULT ComputeProcedureFilePathLocal(const CATString & iProcedureName, CATUnicodeString & oProcedureFilePath);

private:
  static HRESULT WriteBuffer_to_File( CATUnicodeString iFilename, CATUnicodeString &iMsg);
  static HRESULT ReadFile_to_Buffer(CATUnicodeString _Filename, CATUnicodeString &ioMsg);
};

//-----------------------------------------------------------------------

#endif
