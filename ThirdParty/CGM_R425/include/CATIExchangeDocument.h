/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
//  CATIExchangeDocument :
//  Class for specific operations on exchange documents
//            
//
//==================================================================
//  Usage notes :
//   This class is used to manage specific operations on exchange 
//   documents (non Dassault-Systemes documents)
//
//==================================================================
#ifndef CATIExchangeDocument_H
#define CATIExchangeDocument_H

/**
 * @level Private
 * @usage U3
 */

#include "AD0XXBAS.h"
#include "CATBaseUnknown.h"


extern ExportedByAD0XXBAS IID IID_CATIExchangeDocument ;

class ExportedByAD0XXBAS CATIExchangeDocument : public CATBaseUnknown
{
  CATDeclareInterface;

    public:

    virtual HRESULT DoRemovingOperations ()  = 0 ;

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIExchangeDocument , CATBaseUnknown ) ;


#endif
