/* COPYRIGHT DASSAULT SYSTEMES 2007
===================================================================

===================================================================
May 07. Creation                                              DOV
===================================================================*/

#ifndef PLMBLIdentificationInitializationError_H
#define PLMBLIdentificationInitializationError_H

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
* Class to manage errors for the business logic access @href PLMIBLIdentificationInitialization interface.
* You can just retrieve a pointer to such an error using the error manager static @href CATError#CATGetLastError method.
*/

class ExportedByPLMBusinessLogicInterfaces PLMBLIdentificationInitializationError : public CATError
{

public:

    /** Errors messages catalog. */
    static const CATString Catalog;

    /** Errors Id for the RunInitialization method. */
    class ExportedByPLMBusinessLogicInterfaces RunInitialization
    {
    public:
        /** Internal Error Id. */
        static const CATString InternalError;
        /** Execution Error Id. */
        static const CATString ExecutionError;
    };

    /** @nodoc */
    CATDeclareError(PLMBLIdentificationInitializationError, CATError)

};

#endif
