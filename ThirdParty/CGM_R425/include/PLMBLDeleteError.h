/* COPYRIGHT DASSAULT SYSTEMES 2007
===================================================================

===================================================================
May 07. Creation                                              DOV
===================================================================*/

#ifndef PLMBLDeleteError_H
#define PLMBLDeleteError_H

/**
* @level Protected
* @usage U1
*/

// Export
#include "PLMBusinessLogicInterfaces.h"

// System
#include "CATError.h"
#include "CATString.h"

/**
* Class to manage errors for the business logic access @href PLMIBLDelete interface.
* You can just retrieve a pointer to such an error using the error manager static @href CATError#CATGetLastError method.
*/

class ExportedByPLMBusinessLogicInterfaces PLMBLDeleteError : public CATError
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

    /** @nodoc */
    CATDeclareError(PLMBLDeleteError, CATError)

};

#endif
