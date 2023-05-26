// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// PLMBLImportExportAttributesValuationError.h
// Header definition of PLMBLImportExportAttributesValuationError
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// 
//  Apr 2021  Creation: SKN14 HQQ 
//@fullreview SKN14 HQQ 21:04:15 TSK6968437 CheckAccessBL
//===================================================================
#ifndef PLMBLImportExportPnOValuationsError_H
#define PLMBLImportExportPnOValuationsError_H

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

class ExportedByPLMBusinessLogicInterfaces PLMBLImportExportPnOValuationsError : public CATError
{

public:

    /** Errors messages catalog. */
    static const CATString Catalog;

    /** Errors Id for the RunPnOValuation method. */
    class ExportedByPLMBusinessLogicInterfaces RunPnOValuation
    {
    public:
        /** Internal Error Id. */
        static const CATString InternalError;
        /** Execution Error Id. */
        static const CATString ExecutionError;
    };

    /** @nodoc */
    CATDeclareError(PLMBLImportExportPnOValuationsError, CATError)

};

//-----------------------------------------------------------------------

#endif
