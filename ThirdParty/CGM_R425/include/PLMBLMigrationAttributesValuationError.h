// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// PLMBLMigrationAttributesValuationError.h
// Header definition of PLMBLMigrationAttributesValuationError
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  21 Avril 2010  Creation: JJ1, modified from the class PLMBLImportExportAttributesValuationError
//===================================================================
#ifndef PLMBLMigrationAttributesValuationError_H
#define PLMBLMigrationAttributesValuationError_H

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
* Class to manage errors for the business logic access @href PLMIBLMigrationAttributesValuation interface.
* You can just retrieve a pointer to such an error using the error manager static @href CATError#CATGetLastError method.
*/

class ExportedByPLMBusinessLogicInterfaces PLMBLMigrationAttributesValuationError : public CATError
{

public:

    /** Errors messages catalog. */
    static const CATString Catalog;

    /** Errors Id for the RunValuation method. */
    class ExportedByPLMBusinessLogicInterfaces RunValuation
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
    CATDeclareError(PLMBLMigrationAttributesValuationError, CATError)

};

//-----------------------------------------------------------------------

#endif
