#ifndef CATIKweVolatileSheetFactory_h
#define CATIKweVolatileSheetFactory_h

// COPYRIGHT Dassault Systemes 2008

// KnowledgeInterfaces framework
#include "CATLifSpecs.h"

// System framework
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATListOfCATString.h"

class CATICkeSheet_var;
class CATIPLMDmtDocument_var;
class CATIPsiRepresentationReference_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATIKweVolatileSheetFactory;
#else
extern "C" const IID IID_CATIKweVolatileSheetFactory;
#endif

/**
* Interface used to create volatile sheets.
* @see CATICkeSheet
*/
class ExportedByCATLifSpecs CATIKweVolatileSheetFactory : public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/**
	* Creates a volatile sheet.
	* @param iInputString
	*   Could be:
	*    - text sheet file path. Example: e:\tmp\toto.txt
	*    - excel sheet file path using the first "excel worksheet". Example: e:\tmp\toto.xls
	*    - excel sheet using the syntax: [filePath]excelWorkSheetIndex. Example: [e:\tmp\toto.xls]3
	* @param ospSheet
	*   The volatile sheet created
	* @param oErrorsKey
	*   The list of error keys allowing you to generate your own NLS error messages.
	*/
	virtual HRESULT CreateVolatileSheet(
		const CATUnicodeString & iInputString, 
		CATICkeSheet_var & ospSheet, 
		CATListOfCATString & oErrorsKey,
		int iExcelSheetIndex = 1) = 0;

	virtual HRESULT CreateVolatileSheet(const CATIPLMDmtDocument_var & ispPLMDmtDoc, 
		CATICkeSheet_var & ospSheet, 
		CATListOfCATString & oErrorsKey,
		int iExcelSheetIndex) = 0;

	virtual HRESULT CreateVolatileSheet(const CATIPsiRepresentationReference_var & ispRepRefDoc, 
		CATICkeSheet_var & ospSheet, 
		CATListOfCATString & oErrorsKey,
		int iExcelSheetIndex) = 0;
};

CATDeclareHandler(CATIKweVolatileSheetFactory, CATBaseUnknown);

#endif // CATIKweVolatileSheetFactory_h

