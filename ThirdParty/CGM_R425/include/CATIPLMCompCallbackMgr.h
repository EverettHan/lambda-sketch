
/**
* @level Private
* @usage U3
*/

#ifndef __CATIPLMCompCallbackMgr_H__
#define __CATIPLMCompCallbackMgr_H__

#include "CATWTypes.h"
#include "CATBaseUnknown.h"
#include "CATPLMCallbackLimitedAccess.h"
#include "CATPLMAdapterEvents.h"
#include "CATEventSubscriber.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMCallbackLimitedAccess IID IID_CATIPLMCompCallbackMgr;
#else
extern "C" const IID IID_CATIPLMCompCallbackMgr ;
#endif

class CATPLMAdapterNotification;

class ExportedByCATPLMCallbackLimitedAccess CATIPLMCompCallbackMgr: public CATBaseUnknown
{
  CATDeclareInterface;

public:
	/**
	* Adds a callback for a given event published.
	* <br><b>Role</b>:
	* The given event subscriber subscribes to a given event that is published
	* by PLMAdapter (CATPLMAdapterNotification) or by PLM Provider (CATPLMProviderNotification).
	* Whenever this event is published by this event publisher,
	* the method declared when subscribing is called, along with possible useful data.
	* @param iEventSubscriber
	*   A pointer to the object that subscribes to the event
	* @param iAdapterEvents
	*   Events that is expected by <tt>iEventSubscriber</tt>. Either CATPLMAdapterNotification or CATPLMProviderNotification
	* @param iMethodToCall
	*   The subscriber's method to call whenever the publisher
	*   publishes <tt>iPublishedEvent</tt>
	*	  @return
	*   <dl>
	*     <dt>S_OK</dt>
	*     <dd>if the callback has been added succesfully</dd>
	*     <dt>E_FAIL </dt>
	*     <dd>A problem occurs</dd>
	*   </dl>
	*/    
  virtual HRESULT AddCallback(CATBaseUnknown *iEventSubscriber,
		CATPLMAdapterEvents     iAdapterEvents,
		CATSubscriberMethod iMethodToCall) = 0;

	/**
	* Removes all events subscriptions for a subscriber.
	* <br><b>Role</b>:
	* The current event subscriber resigns its subscription to all the callbacks
	* set for  given events published by  a given event publisher, and
	* with a given client data pointer.
	* @param iEventPublisher
	*   A pointer to the object from which the callbacks <tt>iCallback</tt>
	*   is to be removed
	* @param iAdapterEvents
	*   Events published by <tt>iEventPublisher</tt>
	*/
  virtual HRESULT RemoveCallbacksOn(CATBaseUnknown *iEventSubscriber) = 0;

  /**
   *  Provides the current notification  for providers.
   */
  virtual HRESULT GetCurrentAdpNotification(CATPLMAdapterNotification*& oAdpNotif) = 0;
};

#endif // __CATIPLMCompCallbackMgr_H__

