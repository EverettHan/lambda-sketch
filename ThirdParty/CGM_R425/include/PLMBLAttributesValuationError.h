/* COPYRIGHT DASSAULT SYSTEMES 2007
===================================================================

===================================================================
May 07. Creation                                              DOV
===================================================================*/

#ifndef PLMBLAttributesValuationError_H
#define PLMBLAttributesValuationError_H

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
* Class to manage errors for the business logic access @href PLMIBLAttributesValuation interface.
* You can just retrieve a pointer to such an error using the error manager static @href CATError#CATGetLastError method.
*/

class ExportedByPLMBusinessLogicInterfaces PLMBLAttributesValuationError : public CATError
{

public:

    /** Errors messages catalog. */
    static const CATString Catalog;

    /** Errors Id for the RunCheck method. */
    class ExportedByPLMBusinessLogicInterfaces RunCheck
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
    HRESULT GetWarningAttributes(CATListValCATString & iospWarningAttributes);

    /** Set the PLM attributes Id whose valuations do not comply (error) with the business logic definition. */
    HRESULT SetWarningAttributes(CATListValCATString & ispWarningAttributes);

    /** Get the PLM attributes Id whose valuations do not comply (error) with the business logic definition. */
    HRESULT GetErrorAttributes(CATListValCATString & iospErrorAttributes);

    /** Set the PLM attributes Id whose valuations do not comply (error) with the business logic definition. */
    HRESULT SetErrorAttributes(CATListValCATString & ispErrorAttributes);

    /** Get Warning Messages related to Warning Attributes */
    HRESULT GetWarningMessages(CATListValCATUnicodeString & iospWarningMessages);

    /** Set Warning Messages related to Warning Attributes */
    HRESULT SetWarningMessages(CATListValCATUnicodeString & ispWarningMessages);

    /** Get Error Messages related to Warning Attributes */
    HRESULT GetErrorMessages(CATListValCATUnicodeString & iospErrorMessages);

    /** Set Error Messages related to Warning Attributes */
    HRESULT SetErrorMessages(CATListValCATUnicodeString & ispErrorMessages);

    /** @nodoc */
    CATDeclareError(PLMBLAttributesValuationError, CATError)

private:

    /** Internal Warning Attributes */
    CATListValCATString _WarningAttributes;

    /** Internal Error Attributes */
    CATListValCATString _ErrorAttributes;

    /** Internal Warning Messages */
    CATListValCATUnicodeString _WarningMessages;

    /** Internal Error Messages */
    CATListValCATUnicodeString _ErrorMessages;

};

#endif
