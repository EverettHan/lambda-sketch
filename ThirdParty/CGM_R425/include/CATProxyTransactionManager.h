#ifndef CATProxyTransactionManager_H
#define CATProxyTransactionManager_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005
/**
 * @level Protected
 * @usage U1
 */

#include "ExportedByCATPLMTos.h"
#include "CATProxyTransaction.h"
#include "CATPLMTosInternalError.h"

 // -----------------------------------------------------------------------------
//  Exceptions management
// -----------------------------------------------------------------------------
//  You can use the following errors to CATCatch specific exceptions.
//  They all inherit from CATError.
//  NB1: information related to the errors are set in the error collector,
//  to enable you to do specific treatement by inheritance.
//  NB2: the first error detected will be raised, which means that if more than
//  one kind of error is present in the network only the first kind will be raised.
//  The others will be unknown until a new transaction is launched.
//  NB3: if more than one error of a kind is seen by the Session Manager, 
//  only one error will be raised, and the error collector will be called once
//  with all impacted components.
// -----------------------------------------------------------------------------
class ExportedByCATPLMTos CATMinorConflictError : public CATPLMTosInternalError
{
public:
  CATDeclareError(CATMinorConflictError, CATPLMTosInternalError)
};

class ExportedByCATPLMTos CATStrongRelationalError : public CATPLMTosInternalError
{
public:
  CATDeclareError(CATStrongRelationalError, CATPLMTosInternalError)
};

class ExportedByCATPLMTos CATCyclicityError : public CATPLMTosInternalError
{
public:
  CATDeclareError(CATCyclicityError, CATPLMTosInternalError)
};


#endif
