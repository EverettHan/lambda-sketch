/**
@file

This file defines the vkEventsManager class.

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__vkEventsManager_h)
#define __vkEventsManager_h

#include "vkEvent.h"
#include "vkArray.h"

namespace VKernel
{
	class vkEvent;
	class vkEventRTTI;
	class vkEventsListener;

	/**
	An events listener is an abstract interface used to handle
	events.
	*/
	class VKKERNEL_API vkEventsManager : public vkHeapObject, public vkContextedObject
	{
	public:
		VK_DECLARE_CTXSINGLETONCONCRETE(vkEventsManager);

		/**
		Registers an event listener for the broadcasting of a precise 
		event.
		The listener will be notified by the inherited events too, so try 
		to be as narrow as possible in your registration.

		@param iEventRTTI the RTTI of the event to listen
		@param iListener the listener to register
		@param iPriority the priority of the listener
		@see UnregisterEventsListener
		@see EDefaultListenerPriorities
		*/
		void RegisterEventsListener(vkType* iEventType, vkEventsListener* iListener, int32 iPriority = 0);
		void RegisterEventsListener(const vkString& iClassID, vkEventsListener* iListener, int32 iPriority = 0);
		void RegisterEventsListener(vkEventRTTI& iRTTI, vkEventsListener* iListener, int32 iPriority = 0);
		void RegisterEventsListener(vkEventRTTI& iRTTI, vkEventsListener* iListener, int32 iPriority, vkEvent::TRTTICollection& oRTTIs);
		
		/**
		Unregister an event listeners.
		*/
		void UnregisterEventsListener(vkType* iEventType, vkEventsListener* iListener);
		void UnregisterEventsListener(const vkString& iClassID, vkEventsListener* iListener);
		void UnregisterEventsListener(vkEventRTTI& iRTTI, vkEventsListener* iListener);
		void UnregisterEventsListener(const vkEvent::TRTTICollection& iRTTIs, vkEventsListener* iListener);

	private:

		vkEventsManager(vkCtx iCtx);
		vkEventsChannel*			_GetEventsChannel(const vkString& iClassID) const;
	};

}


#endif // __vkEventsManager_h



