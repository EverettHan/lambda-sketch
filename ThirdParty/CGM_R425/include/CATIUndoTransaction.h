/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIUndoTransaction_h
#define CATIUndoTransaction_h

#include "CATBaseUnknown.h"


#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIUndoTransaction ;

class ExportedByAD0XXBAS CATIUndoTransaction : public CATBaseUnknown
{
  CATDeclareInterface;

public:
    virtual int 	NewTransaction()=0;
    virtual void 	AbortTransaction(int transactionnumber)=0;
    virtual void 	CommitTransaction(int transactionnumber)=0;
    virtual void 	RedoTransaction(int transactionuntil)=0;
    virtual int		IsEmptyTransaction(int transactionnumber)=0;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIUndoTransaction, CATBaseUnknown ) ;


#endif
