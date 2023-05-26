//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
#ifndef PLMExchangeBackboneServices_H
#define PLMExchangeBackboneServices_H

// COPYRIGHT DASSAULT SYSTEMES 2016

#include "PLMExchangeGlobalServices.h"

// System Framework
#include "CATUnicodeString.h"
#include "CATMessageClass.h"
#include "PLMExchangeBBMessage.h"

#include "CATIPLMCompConnectionInstance.h"

class CATIMessageReceiver;
class CATBinary;

//-----------------------------------------------------------------------

class ExportedByPLMExchangeGlobalServices PLMExchangeBackboneServices
{

public:
   static HRESULT Connect(const CATString &iAlias);
   static HRESULT Wait(const int iTimeoutInMs, int *iEndLoopCondition = NULL);
   static HRESULT Listen(const CATString &iAlias, CATIMessageReceiver *iHandler);
   static HRESULT ListenClientDeath(CATIMessageReceiver *iHandler);
   static HRESULT StopListening(CATIMessageReceiver *iHandler);
   static HRESULT Disconnect();
   static HRESULT SendMsg(PLMExchangeBBMessage *ipiMsg, const CATString &iReceiver, CATBoolean bSynchronous);


   // Service for the messages.
   static HRESULT SendStartExecutionMessage(const CATString &iReceiverAlias);
   static HRESULT SendProgressionMessage(const CATString &iReceiverAlias, int & iPurcentProgress);
   static HRESULT SendExecutionFinishedMessage(const CATString &iReceiverAlias, PLMExchangeBBMessage::ExecutionStatus& iStatus);

private:
   PLMExchangeBackboneServices();
   virtual ~PLMExchangeBackboneServices();

   // Copy constructor, not implemented
   // Set as private to prevent from compiler automatic creation as public.
   PLMExchangeBackboneServices (PLMExchangeBackboneServices &);

   // Assignment operator, not implemented
   // Set as private to prevent from compiler automatic creation as public.
   PLMExchangeBackboneServices& operator=(PLMExchangeBackboneServices&);

};

//-----------------------------------------------------------------------

#endif
 
