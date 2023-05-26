//===================================================================
// COPYRIGHT Dassault Systemes 2019/04/18
//===================================================================
// CATIAfrEndTransaction interface
//===================================================================
//
// Abstraction of System 'CATSubscribeEndTransaction' event and mechanism.
// Goal : emulate the mechanism in a Compute Server where System mechanism does not exist.
// The subscriber doesn't have to know whether the context is a Compute Server or the native fat client, this mechanism works in both contexts.
//   - In the native fat client context, it redirects to the System mechanism.
//   - In the Compute Server context, it emulates the same kind of behavior, based on a Callback.
// Notice that, in the Compute Server context , only one subscriber is supported. The only use case known (and supported) is Mechanical Modeler subscribing and the View Model dispatching.
//
// This interface is implemented on CATSession which is a singleton existing in all the known contextes. Please never implement this interface on any other type without validation from the interface owner.
// Subscription : query the CATSession object on CATIAfrEndTransaction interface and call SubscribeToEndTransaction method on the interface pointer.
// Unsubscription : query the CATSession object on CATIAfrEndTransaction interface and call RemoveSubscriptionToEndTransaction method on the interface pointer.
// Dispatch : query the CATSession object on CATIAfrEndTransaction interface and call DispatchEndTransaction method on the interface pointer.
//
//===================================================================
//  2019/04/18 Creation: ERS
//===================================================================
#ifndef CATIAfrEndTransaction_H
#define CATIAfrEndTransaction_H

#include "UIModelInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATApplication.h"

class CATCommand;

typedef void(*SubCB)();

enum AfrEndTransactionSubscribeMode { CATApplicationMode, AFRMode, SubError };


extern ExportedByUIModelInterfaces  IID IID_CATIAfrEndTransaction ;
class ExportedByUIModelInterfaces CATIAfrEndTransaction : public CATBaseUnknown
{
CATDeclareInterface;

public:

  // Subscribe to EndTransaction event.
  // Returns the context where the subscription was made or 'SubError' if the subscription could not be made.
  // Notice that in 'AFRMode' only one subscriber is supported because of the very special use we want to address.
  virtual AfrEndTransactionSubscribeMode SubscribeToEndTransaction (CATCommand * iToClient, void * iClientData, SubCB iUserStaticMethod, int * oSubscribeCBId = NULL) = 0;

  // Remove subscription to EndTransaction event.
  // Returns S_OK if subscription was removed normally.
  // Returns E_FAIL if subscription could not be removed.
  virtual HRESULT RemoveSubscriptionToEndTransaction (CATCommand * iToClient) = 0;

  // Send EndTransaction event to subscribers.
  // Returns S_OK if dispatch to subscribers ran OK.
  // Returns S_FALSE if there was no dispatch because of no subscriber ('AFRMode' only)
  // Returns E_FAIL if an error occurs while dispatching to subscribers.
  // Does nothing and returns E_FAIL in 'CATApplicationMode'.
  virtual HRESULT DispatchEndTransaction() = 0;
};

//-----------------------------------------------------------------------

#endif
