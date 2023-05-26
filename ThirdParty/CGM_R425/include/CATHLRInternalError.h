/* -*-C++-*-*/
#ifndef CATHLRInternalError_H
#define CATHLRInternalError_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRInternalError 
//
// DESCRIPTION :
/**
 * Internal error for the HLRs' computation.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Feb. 98   Jose CHILLAN (jch)    Creation            
//
//=============================================================================

// For Windows NT
#include "HLRModele.h"

// For inheritance
// MODIF LAT pour composant HLR 
// #include "CATErrors.h"
#include "CATCGMInternalError.h"

class ExportedByHLRModele CATHLRInternalError : public CATCGMInternalError
{
public:
  
  CATDeclareErrorClass(CATHLRInternalError, CATCGMInternalError)

   	/** @nodoc */
   CATCGMNewClassArrayDeclare;
};


#endif
