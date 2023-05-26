/* COPYRIGHT DASSAULT SYSTEMES 2008
===================================================================

===================================================================
Nov 08. Creation                                              EAP
===================================================================*/

#ifndef PLMBLValidationForReusableError_H
#define PLMBLValidationForReusableError_H

/**
* @level Protected
* @usage U1
*/

// Export
#include "PLMBusinessLogicInterfaces.h"

// System
#include "CATError.h"
#include "CATString.h"
#include "CATListOfCATString.h"
#include "CATListOfCATUnicodeString.h"

/**
* Class to manage errors for the business logic access @href PLMIBLDelete interface.
* You can just retrieve a pointer to such an error using the error manager static @href CATError#CATGetLastError method.
*/

class ExportedByPLMBusinessLogicInterfaces PLMBLValidationForReusableError : public CATError
{

public:

    /** Errors messages catalog. */
    static const CATString Catalog;

    /** Errors Id for the RunCheck method. */
    class ExportedByPLMBusinessLogicInterfaces RunValidationForReusable
    {
    public:
        /** Internal Error Id. */
        static const CATString InternalError;
        /** Validation Error Id. */
        static const CATString ValidationError;
        /** Execution Error Id. */
        static const CATString ExecutionError;
    };

    /** Get the PLM attributes Id whose valuations do not comply (error) with the business logic definition. */
    HRESULT GetErrorAttributes(CATListValCATString & iospErrorAttributes);

    /** Set the PLM attributes Id whose valuations do not comply (error) with the business logic definition. */
    HRESULT SetErrorAttributes(CATListValCATString & ispErrorAttributes);

    /** Get Error Messages related to Warning Attributes */
    HRESULT GetErrorMessages(CATListValCATUnicodeString & iospErrorMessages);

    /** Set Error Messages related to Warning Attributes */
    HRESULT SetErrorMessages(CATListValCATUnicodeString & ispErrorMessages);

	/** @nodoc */
	CATDeclareError(PLMBLValidationForReusableError, CATError)

private:

    /** Internal Error Attributes */
    CATListValCATString _ErrorAttributes;

    /** Internal Error Messages */
    CATListValCATUnicodeString _ErrorMessages;
};

#endif
