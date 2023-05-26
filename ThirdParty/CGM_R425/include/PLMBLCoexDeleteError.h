// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// PLMBLCoexDeleteError.h
// Header definition of PLMBLCoexDeleteError
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2012  Creation:  EBD
//===================================================================
#ifndef PLMBLCoexDeleteError_H
#define PLMBLCoexDeleteError_H

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
* Class to manage errors for the business logic access @href PLMIBLCoexDelete interface.
* You can just retrieve a pointer to such an error using the error manager static @href CATError#CATGetLastError method.
*/

class ExportedByPLMBusinessLogicInterfaces PLMBLCoexDeleteError : public CATError
{

public:

    /** Errors messages catalog. */
    static const CATString Catalog;

    /** Errors Id for the RunValuation method. */
    class ExportedByPLMBusinessLogicInterfaces IsObjectToDelete
    {
    public:
        /** Internal Error Id. */
        static const CATString InternalError;
        /** Execution Error Id. */
        static const CATString ExecutionError;
		/** Initialization Error Id. */
        static const CATString InitializationError;
    };

    /** @nodoc */
    CATDeclareError(PLMBLCoexDeleteError, CATError)

};

//-----------------------------------------------------------------------

#endif
