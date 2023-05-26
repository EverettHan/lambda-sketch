/**
@file

This file defines the vkTypeEvent.

@COPYRIGHT

@author Romain Sididris
*/

#if !defined(__vkTypeEvent_h)
#define __vkTypeEvent_h

#if !defined(__vkEvent_h)
	#include  "vkEvent.h"
#endif

#if !defined(__vkEventsListener_h)
	#include  "vkEventsListener.h"
#endif

namespace VKernel
{

/**
This class defines the base class for events sent by types.
*/
class VKKERNEL_API vkTypeEvent : public vkEvent
{
public:
	VK_DECLARE_EVENT(vkTypeEvent, vkEvent);

	/**
	Defines the different IDs determining the kind of event.
	*/
	enum ETypeEventID
	{
		/**
		Defines an invalid event ID.
		*/
		eInvalidEventID = 0,

		/**
		Defines an event sent when a new type has just been registered.
		*/
		eTypeRegisteredEventID,

		/**
		Defines an event sent when a type is about to be unregistered, and
		then destroyed.
		*/
		eTypeUnregisteredEventID,
		
		/** 
		Defines an event sent when an not registered type is destroyed
		*/

		eNotRegisteredTypeDestroyEventID
	};
	vkTypeEvent(ETypeEventID iEventID, vkType* iType);

	/**
	Defines the type of the event.
	*/
	ETypeEventID	m_EventID;

	/**
	Defines the type which is the target of this event.
	The pointer is weak to prevent from adding a reference to the type while
	it's being deleted.
	*/
	vkType*	m_Type;

	/**
	In output, if set to true, then the caller is responsible for destroying these listeners.
	*/
	//vkArray<vkEventsListenerPtr> m_OListenersToDestroy;
};


} // Namespace VKernel

#endif // __vkTypeEvent_h



