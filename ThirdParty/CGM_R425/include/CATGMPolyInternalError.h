#ifndef CATGMPolyInternalError_H
#define CATGMPolyInternalError_H

/** @CAA2Required */

//=============================================================================
//
// COPYRIGHT   : DASSAULT SYSTEMES 2016
//
// DESCRIPTION : CATGMPolyInternalError class declaration
//
//=============================================================================


#include "CATErrors.h"
#include "GMPolyTopTools.h"   // ExportedBy

#include "CATCGMInternalError.h"

#ifndef GMPolyInFile
#define GMPolyInFile "GMPolyOperators"
#endif

class ExportedByGMPolyTopTools CATGMPolyInternalError : public CATCGMInternalError
{
public:
  /** @nodoc */
  CATCGMNewClassArrayDeclare;

  /**
  * Declares that the class CATGMPolyInternalError is an error class which derives
  * from CATCGMInternalError
  */
  CATDeclareErrorClass(CATGMPolyInternalError, CATCGMInternalError);

  // WARNING : CATDeclareErrorClass only declares constructors for CATErrorId and CATErrorId, msgId, catalog=NULL
  // We need to handle msgId, catalog ourselves.

  CATGMPolyInternalError(const char* msgId, const char* catalog);
};

#endif
