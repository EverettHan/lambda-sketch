#ifndef CATISetupDataFormatChecker_h
#define CATISetupDataFormatChecker_h

// COPYRIGHT Dassault Systemes 2007

// System framework
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

// KnowledgeInterfaces framework
#include "CATLifSpecs.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATISetupDataFormatChecker;
#else
extern "C" const IID IID_CATISetupDataFormatChecker;
#endif

class CATIKweAppResourceSubItem_var;

/**
 * Interface used to validate the format of setup data.
 * @see CATIKweAppResourceSubItem
 */
class ExportedByCATLifSpecs CATISetupDataFormatChecker : public CATBaseUnknown
{
	CATDeclareInterface;

public:

	enum ErrorType
	{
		FormatError,
		FormatWarning
	};

	/**
	 * Checks whether the given resource is valid for the given setup data Id.
	 * @param iSetupDataUsageID
	 *   The setup data Id for which the resource must be validated.
	 * @param iFoundResource
	 *   The resource to validate.
	 * @param oErrorMessage
	 *   The returned NLS error message in case of validation failure.
	 * @param oErrorType
	 *   The returned error type : 
	 *     - if equals to FormatError, the resource will not be assigned
	 *     - if equals to FormatWarning, the resource will be assigned and the 
	 *       warning message will be displayed
	 * @return
	 *   S_OK if the format is OK, E_FAIL otherwise.
	 *   In the case the check fails, a NLS error message is also returned.
	 */
	virtual HRESULT Check(
		const CATUnicodeString& iSetupDataUsageID, 
		const CATIKweAppResourceSubItem_var& iFoundResource,
		CATUnicodeString& oErrorMessage,
		CATISetupDataFormatChecker::ErrorType &oErrorType) = 0;

};

CATDeclareHandler(CATISetupDataFormatChecker, CATBaseUnknown);

#endif // CATISetupDataFormatChecker_h

