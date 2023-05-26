/* COPYRIGHT DASSAULT SYSTEMES 2007
===================================================================

===================================================================
May 07. Creation                                              DOV
===================================================================*/

#ifndef PLMBLAttributesPropagationError_H
#define PLMBLAttributesPropagationError_H

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
* Class to manage errors for the business logic access @href PLMIBLAttributesPropagation interface.
* You can just retrieve a pointer to such an error using the error manager static @href CATError#CATGetLastError method.
*/

class ExportedByPLMBusinessLogicInterfaces PLMBLAttributesPropagationError : public CATError
{

public:

    /** Errors messages catalog. */
    static const CATString Catalog;

    /** Errors Id for the RunPropagation method. */
    class ExportedByPLMBusinessLogicInterfaces RunPropagation
    {
    public:
        /** Internal Error Id. */
        static const CATString InternalError;
        /** Execution Error Id. */
        static const CATString ExecutionError;
    };

    /** @nodoc */
    CATDeclareError(PLMBLAttributesPropagationError, CATError)

};

#endif
