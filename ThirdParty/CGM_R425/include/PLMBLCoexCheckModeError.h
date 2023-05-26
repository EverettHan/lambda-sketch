// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// PLMBLCoexCheckModeError.h
// Header definition of PLMBLCoexCheckModeError
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  April 2013 :  Creation -  EBD
//===================================================================
#ifndef PLMBLCoexCheckModeError_H
#define PLMBLCoexCheckModeError_H

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

class ExportedByPLMBusinessLogicInterfaces PLMBLCoexCheckModeError : public CATError
{

public:

    /** Errors messages catalog. */
    static const CATString Catalog;

    /** Errors Id for the RunValuation method. */
    class ExportedByPLMBusinessLogicInterfaces ValidateTransfer
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
    CATDeclareError(PLMBLCoexCheckModeError, CATError)

};

//-----------------------------------------------------------------------

#endif
