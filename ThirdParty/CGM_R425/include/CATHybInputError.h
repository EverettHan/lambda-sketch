#ifndef CATHybInputError_H
#define CATHybInputError_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//------------------------------------------------------------------------------
// CATHybInternalError :  Not Supported Anymore  
//------------------------------------------------------------------------------
#include "HybOper.h"
//------------------------------------------------------------------------------
#include "CATErrors.h"
#include "CATHybErrors.h"
#include "CATHybBlockThrow.h"
#include "CATCGMInputError.h"

//-----------------------------------------------------------------------------
class ExportedByHybOper CATHybInputError : public CATCGMInputError
{
  public:
    //------
    // Constructors
    //------
    CATDeclareErrorClass(CATHybInputError, CATCGMInputError)

   	/** @nodoc */
   CATCGMNewClassArrayDeclare;
};

#endif
