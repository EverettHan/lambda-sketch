#ifndef CATHybInternalError_H
#define CATHybInternalError_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//------------------------------------------------------------------------------
// CATHybInternalError :  Not Supported Anymore   
//------------------------------------------------------------------------------
//
#include "HybOper.h"
//------------------------------------------------------------------------------
#include "CATErrors.h"
#include "CATHybErrors.h"
#include "CATHybBlockThrow.h"
#include "CATCGMInternalError.h"

//-----------------------------------------------------------------------------
class ExportedByHybOper CATHybInternalError : public CATCGMInternalError
{
  public:
    //------
    // Constructors
    //------
    CATDeclareErrorClass(CATHybInternalError, CATCGMInternalError)

   	/** @nodoc */
   CATCGMNewClassArrayDeclare;
};

#endif
