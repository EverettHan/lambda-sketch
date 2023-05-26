/* -*-C++-*-*/
#ifndef CATHLRInputError_H
#define CATHLRInputError_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRInputError 
//
// DESCRIPTION :
/**
  * Input error for the HLRs' computation.
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
#include "CATCGMInputError.h"

class ExportedByHLRModele CATHLRInputError : public CATCGMInputError
{
public:
  CATDeclareErrorClass(CATHLRInputError, CATCGMInputError)

   	/** @nodoc */
   CATCGMNewClassArrayDeclare;
};

#endif
