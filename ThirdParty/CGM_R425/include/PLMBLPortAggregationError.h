/* COPYRIGHT DASSAULT SYSTEMES 2008
===================================================================

===================================================================
Dec 08. Creation                                              ADZ
===================================================================*/

#ifndef PLMBLPortAggregationError_H
#define PLMBLPortAggregationError_H

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
* Class to manage errors for the business logic access @href PLMIBLPortAggregation interface.
* You can just retrieve a pointer to such an error using the error manager static @href CATError#CATGetLastError method.
*/

class ExportedByPLMBusinessLogicInterfaces PLMBLPortAggregationError : public CATError
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
    CATDeclareError(PLMBLPortAggregationError, CATError)

};

#endif
