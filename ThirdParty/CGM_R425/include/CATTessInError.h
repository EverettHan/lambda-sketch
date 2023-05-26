/* -*-C++-*-*/
#ifndef CATTessInError_H
#define CATTessInError_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATTessInError 
//
// DESCRIPTION :
/**
 * Class for the errors in the input of the tessellation.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// 07/1998   Alain COLLET (ca)    Creation            
// Sep. 2000 TPD modification du nom du fichier d'erreur
//
//=============================================================================

// For Windows NT
#include "TessImpl.h"

// For inheritance
#include "CATErrors.h"
#include "CATCGMInputError.h"

#ifndef TessInFile
#define TessInFile "CATTessellation"
#endif

#define TessInTooLargeLength     "TessInTooLargeLength"
#define TessInTooSmallLength     "TessInTooSmallLength"
#define TessInInvalidSag         "TessInInvalidSag"
#define TessInInvalidStep        "TessInInvalidStep"
#define TessInInvalidAngle       "TessInInvalidAngle"
#define TessInUnableToAllocate   "TessInUnableToAllocate"
#define TessInInternalError      "TessInInternalError"
 

class ExportedByTessImpl CATTessInError : public CATCGMInputError
{
//=============================================================================
// DEFINITION
//=============================================================================

public:
   CATDeclareError(CATTessInError, CATCGMInputError)


   	/** @nodoc */
   CATCGMNewClassArrayDeclare;

};


#endif
