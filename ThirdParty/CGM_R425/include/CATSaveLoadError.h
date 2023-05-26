/**
 * @level Protected
 * @usage U1
 */
/* -*-c++-*- */
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES  1998
//=============================================================================
//
// CATSaveLoadError:
//    Base class for errors raised during save or load operations
//
//=============================================================================
// Usage Notes:
//    
// 
//=============================================================================
// dec. 98   Creation                                   B. Paget
//=============================================================================
#ifndef CATSaveLoadError_H
#define CATSaveLoadError_H
#include "AD0XXBAS.h"
#include "CATErrors.h"


class ExportedByAD0XXBAS CATSaveLoadError : public CATInternalError
{ 

  public:
  CATDeclareErrorClass (CATSaveLoadError, CATInternalError)  
} ;   
    

#endif      

