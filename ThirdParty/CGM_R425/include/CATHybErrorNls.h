#ifndef CATHybErrorNls_H
#define CATHybErrorNls_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//------------------------------------------------------------------------------
// CATHybErrorNls : Error Management for Hybrid Operators  
//------------------------------------------------------------------------------
#include "CATErrors.h"
#include "CATTopOpInError.h"
#include "CATTopOpIntError.h"
#include "CATCGMDiagnosis.h"
#include "CATCGMThrow.h"
 
//-----------------------------------------------------------------------------
// CATHybThrowInError / CATHybThrowIntError : 
// macro qui cree un objet d'erreur CATTopOpInError / CATTopOpIntError
//                     et execute un throw de cette erreur
// ErrorId    : id de l'erreur
//-----------------------------------------------------------------------------

#define CATHybThrowInputError(ErrorId) CATCGMThrow(new CATTopOpInError(ErrorId,TopOpInFile))

#define CATHybThrowInternalError(ErrorId) CATCGMThrow(new CATTopOpIntError(ErrorId,TopOpIntFile))

#define CATHybThrowInternalErrorWithDiag(ErrorId,Diag) CATCGMThrow(new CATTopOpIntError(ErrorId,TopOpIntFile,Diag))

#endif
