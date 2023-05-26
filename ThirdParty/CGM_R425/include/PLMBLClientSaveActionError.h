/* COPYRIGHT DASSAULT SYSTEMES 2015
===================================================================

===================================================================
Sept 15. Creation                                              ECN
===================================================================*/

#ifndef PLMBLClientSaveActionError_H
#define PLMBLClientSaveActionError_H

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
* Class to manage errors for the business logic access @href PLMIBLClientSaveActionError interface.
* You can just retrieve a pointer to such an error using the error manager static @href CATError#CATGetLastError method.
*/

class ExportedByPLMBusinessLogicInterfaces PLMBLClientSaveActionError : public CATError
{

public:

    /** Errors messages catalog. */
    static const CATString Catalog;

    /** Errors Id for the RunInitialization method. */
    class ExportedByPLMBusinessLogicInterfaces RunSaveAction
    {
    public:
        /** Internal Error Id. */
        static const CATString InternalError;
        /** Execution Error Id. */
        static const CATString ExecutionError;
    };

    /** @nodoc */
    CATDeclareError(PLMBLClientSaveActionError, CATError)

};

#endif
