/**
@file

This file defines the vkEventsListener class.

@COPYRIGHT

@author Gerald Guyomard
*/

#if !defined(__vkEventsListener_h)
#define __vkEventsListener_h


#include "vkKernelLib.h"
#include "vkRTTI.h"
#include "vkRefPtrObject.h"
#include "vkContext.h"


namespace VKernel
{
	class vkEvent;

	/**
	An events listener is an abstract interface used to handle
	events.
	*/
	class VKKERNEL_API vkEventsListener : public vkRefPtrObject
	{
	public:
		VK_DECLARE_RTTI_ABSTRACTTYPE(vkEventsListener, vkRefPtrObject);

		/**
		Events are received and handled by this method.

		The returned bool value is often important to know if the event needs
		to be still propagated or stopped here (see vkuiEventsChannel).
		If you only want to be notified by an event but do not want to stop
		propagation, simply return false.

		@param ioEvent the event to handle.
		@return True if handled, false otherwise.
		*/
		virtual bool	HandleEvent(vkEvent& ioEvent) = 0;

		/**
		Dispatch an event to the entire chain of responsibility where the start object
		is this listener.
		Derives classes with complex graph of event delegation should override this
		method to properly other listeners contained in the chain.
		Default implementation simply calls HandleEvent.
		@return true if handled
		*/
		virtual bool	DispatchEvent(vkEvent& ioEvent);

	protected:
		VK_DECLARE_CTXCONSTRUCTOR(vkEventsListener);
		vkEventsListener(vkCtx iCtx, bool iIsValid);
	};

	/**
	 Pointer on a ref counted listener
	*/
	typedef vkRefPtr<vkEventsListener> vkEventsListenerPtr;
}


#endif // __vkEventsListener_h

