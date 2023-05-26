/* -*-C++-*- */

#ifndef CATRedefineError_H
#define CATRedefineError_H
 
// COPYRIGHT DASSAULT SYSTEMES 1997

//------------------------------------------------------------------------------
//
// CATRedefineError
// Redefine error for Draft
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Usage notes:
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// November 98    Creation                         A. State
//------------------------------------------------------------------------------

#include "CATError.h"
//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"
#include "CATDataType.h"

class CATGeoFactory;
class CATEdge;
class CATBody;
#include "ListPOfCATBody.h"  //  SOU : 2004:3:9
#include "ListPOfCATFace.h" //  SOU : 2004:3:9

//------------------------------------------------------------------------------
// Redefine non-explicit errors
// Please note: ioError may be flushed
//------------------------------------------------------------------------------
ExportedByRIBLight CATError * CATRedefineError (CATError   *iError,
                                           CATErrorId  iErrorId,
                                           char       *iErrorMessage);

//
//------------------------------------------------------------------------------
// Define TwistError 
//------------------------------------------------------------------------------
ExportedByRIBLight CATError * CATDraftDefineError (CATLONG32 iNumberError, CATBody *iBody = NULL);
//
//------------------------------------------------------------------------------
// Update DraftError 
//------------------------------------------------------------------------------
ExportedByRIBLight CATError * CATDraftUpdateError (CATError *iError, CATBody *iBody);
//
//------------------------------------------------------------------------------
// Check if a given error is non explicit
//------------------------------------------------------------------------------
ExportedByRIBLight CATBoolean CheckIfErrorIsNonExplicit(CATError *iError);

// Start : SOU : 2004:3:8
//
//------------------------------------------------------------------------------
// Define TwistError 
//------------------------------------------------------------------------------
ExportedByRIBLight CATError * CATDraftDefineError (CATLONG32 iNumberError
                                             ,CATLISTP(CATBody) &iErrorBodies
                                             ,CATLISTP(CATBody) &iContextBodies);

//------------------------------------------------------------------------------
// Define TwistError 
//------------------------------------------------------------------------------
ExportedByRIBLight CATError * CATDraftDefineError(CATLONG32 iNumberError,CATGeoFactory* iGeoFactory, CATBody* iBody
                                             ,CATLISTP(CATFace) &iErrorFaces,CATLISTP(CATFace) &iContextFaces);

// End : SOU : 2004:3:8
#endif
