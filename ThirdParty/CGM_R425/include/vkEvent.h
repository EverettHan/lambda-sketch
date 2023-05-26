/**
@file

This file defines the class vkEvent.

@COPYRIGHT

@author Gerald Guyomard
*/

#if !defined(__vkEvent_h)
#define __vkEvent_h


#include "vkRTTI.h"
#include "vkEventsListener.h"
#include "vkEventsChannel.h"
#include "vkCtxObject.h"
#include "vkArray.h"


namespace VKernel
{
	/**
	vkRTTI class used for events. An events channel was added.
	*/
	class VKKERNEL_API vkEventRTTI : public vkRTTI
	{
	public:
#if defined(VK_MULTIPLE_CONTEXTS)
		explicit vkEventRTTI(vkRTTI* iSuperClassRTTI, const vkString& iClassID, vkNewFunctionPtr iCreateFunction = 0, vkCtxObjectBase*& ioCtxObjectList = s_LocalCtxObjectList, vkRTTI*& ioLocalRTTIList = s_LocalRTTIList);
#else
		explicit vkEventRTTI(vkRTTI* iSuperClassRTTI, const vkString& iClassID, vkNewFunctionPtr iCreateFunction = 0, vkRTTI*& ioLocalRTTIList = s_LocalRTTIList);
#endif
		/**
		Destructor
		*/
		~vkEventRTTI();

		/**
		Events channel for broadcast
		*/
		vkCtxObject<vkEventsChannel>	m_BroadcastChannel;

		static	vkEventRTTI*		GetRTTIByClassID(const vkString& iClassID);
	};

	/**
	Some default listener priorities.
	*/
	enum EDefaultListenerPriorities
	{
		/**
		Default value for post listeners.
		*/
		kDefaultPostListenerPriority	= 0,

		/**
		Default value for pre listeners.
		*/
		kDefaultPreListenerPriority		= -10000,

		/**
		Minimum priority value.
		Actually it could be -(2^31) - 1 but standard (and then gcc) says so...
		*/
		kMinPreListenerPriority			= -2147483647-1,

		/**
		Maximum priority value.
		Actually it could be -(2^31) - 1 but standard (and then gcc) says so...
		*/
		kMaxPostListenerPriority		= 2147483647
	};

	/**
	Base class for an event.

	vkuiEvent is a structure used to encode a particular event aimed to
	be broadcast and handled by listeners.
	@see vkEventsListener
	*/
	class VKKERNEL_API vkEvent : public vkRTTIObject
	{
	public:
		typedef vkEventRTTI RTTIClass;

		/**
		Defines a collection of Event RTTIs.
		*/
		typedef vkArray<RTTIClass*> TRTTICollection;


		VK_DECLARE_RTTI_RTTIOBJECT(vkEvent, vkRTTIObject);
		VK_DECLARE_STDCLONE(vkEvent, vkEvent);

		enum
		{
			/**
			This defines an invalid event.
			No member eventID is defined in the base class vkEvent
			to force client to properly downcast the event in the proper
			type and then test this kind of member.
			*/
			kInvalidEventID				= 0x7FFFFFFF
		};

		/**
		Constructor
		@param iTarget the target of this event
		*/
		vkEvent(vkEventsListener* iTarget = 0);

		/**
		Copy Constructor
		@param iOther the event to copy
		*/
		vkEvent(const vkEvent& iOther);

		/**
		Gets the type of this event.
		@param iCtx the context for which the type is queried
		@return the event type
		*/
		virtual vkType* GetEventType(vkCtx iCtx) const;

		/**
		Tells if this event was already broadcast.
		*/
		bool WasBroadcast() const;

		enum FBroadcastFlags
		{
			/** if set then the event is first dispatched to m_Target if any */
			fTryPrimaryTarget = 1 << 0,

			/** if set then pre listeners registered to this event are called */
			fPreBroadcast	  = 1 << 1,

			/** if set then post listeners registered to this event are called */
			fPostBroadcast	  = 1 << 2,

			/** if set then all (both pre & post) listeners registered to this event are called */
			fBroadcastAll	  = fPreBroadcast | fPostBroadcast,

			/** default broadcast configuration if not explicitly specified by the caller */
			fDefaultBroadcastFlags = fTryPrimaryTarget | fBroadcastAll
		};

		/**
		Tells if event dispatching must be stopped once handled.
		@return true if dispatching is stopped after 1st handling.
		@see SetStopWhenHandled
		@see ResetStopWhenHandled
		*/
		bool StopWhenHandled() const;

		/**
		Sets the flags StopWhenHandled.
		After this call, StopWhenHandled returns true
		*/
		void SetStopWhenHandled();

		/**
		Resets the flags StopWhenHandled.
		After this call, StopWhenHandled returns true
		*/
		void ResetStopWhenHandled();

		/**
		Tells if event dispatching must be stopped once handled by the
		chain of responsibility.
		Chain of responsibility is a concept that is context dependent.
		In the GUI Framework, it may be the chain described by the main UI Element
		target and its ancestors.
		@return true if dispatching is stopped when chain of responsibility handled it.
		@see SetStopWhenHandledByChainOfResponsibility
		@see ResetStopWhenHandledByChainOfResponsibility
		*/
		bool StopWhenHandledByChainOfResponsibility() const;

		/**
		Sets the flags StopWhenHandledByChainOfResponsibility.
		After this call, StopWhenHandledByChainOfResponsibility returns true
		*/
		void SetStopWhenHandledByChainOfResponsibility();

		/**
		Resets the flags StopWhenHandledByChainOfResponsibility.
		After this call, StopWhenHandledByChainOfResponsibility returns true
		*/
		void ResetStopWhenHandledByChainOfResponsibility();

		/**
		Tells if this event, when dispatched on a document, must be also dispatched
		on its master document.
		This is a MP GUI related flag. By default, this flag is false to a huge speed penalty.
		@see vkuiDocument
		@see SetMustBeDispatchedOnMasterDocument
		@see ResetMustBeDispatchedOnMasterDocument
		*/
		bool MustBeDispatchedOnMasterDocument() const;

		/**
		Sets the internal flag to be dispatched on master document.
		@see MustBeDispatchedOnMasterDocument
		*/
		void SetMustBeDispatchedOnMasterDocument();

		/**
		Resets the internal flag to be dispatched on master document.
		@see MustBeDispatchedOnMasterDocument
		*/
		void ResetMustBeDispatchedOnMasterDocument();

		/**
		Broadcast an event.
		All registered listeners to this event RTTI and its 
		parent RTTI will be notified.

		@param iCtx the context in which the event must be broadcast
		@param iBroadcastFlags a combo of FBroadcastFlags to configure broadcast
		@return true if the event was handled at least one time
		@see vkEventsManager::RegisterEventsListener
		*/
		virtual bool Broadcast(vkCtx iCtx, uint32 iBroadcastFlags);
		virtual bool Broadcast(vkCtx iCtx, bool iStopIfHandled = false);

		/**
		Broadcasts an event only for the pre listeners registered to this event.
		Stops broadcast if a listener handles the event.
		@param iCtx the context in which the event must be broadcast
		@return true if the event was handled at least one time
		@see vkEventsManager::RegisterEventsListener
		@see Broadcast
		*/
		bool PreBroadcast(vkCtx iCtx);

		/**
		Broadcasts an event only for the post listeners registered to this event.
		Stops broadcast if a listener handles the event.
		@param iCtx the context in which the event must be broadcast
		@return true if the event was handled at least one time
		@see vkEventsManager::RegisterEventsListener
		@see Broadcast
		*/
		bool PostBroadcast(vkCtx iCtx);

		/**
		Checks if the event has registred broadcast listeners
		for a given RTTI.
		@param iCtx the context in which search is done
		@param iRTTI the rtti for which broadcast listeners are looked for
		@return true if there are listeners.
		
		@see Broadcast
		*/
		static bool HasBroadcastListeners(vkCtx iCtx, const vkEventRTTI& iRTTI);

		/**
		Main target of the event.

		The target is the main receiver of the event.
		This notion is closely linked to derived classes and there's no
		particular rule at vkEvent class Level.
		An event can have no particular target, in which case the target is 0.
		*/
		vkEventsListenerPtr	m_Target;

	private:
		vkEvent* m_Next;

	protected:
		enum FEventFlags
		{
			fWasBroadcast								= 1 << 0,
			fStopWhenHandled							= 1 << 1,
			fStopWhenHandledByChainOfResponsibility		= 1 << 2,
			fMustBeDispatchedOnMasterDocument			= 1 << 3,

			fDefaultEventFlags = 0
		};

		uint32 m_EventFlags;
	};

	/**
	Macro to use in declaration of new classes of event.
	@param className the name of the new event class
	@param superClassName the name of the super class.
	*/

#define VK_DECLARE_EVENT(className, superClassName) \
	VK_DECLARE_RTTI(className, superClassName); \
	VK_DECLARE_STDCLONE(className, vkEvent); \

#define VK_DECLARE_EVENT_CREATE(className, superClassName) \
	VK_DECLARE_RTTI_CREATE(className, superClassName); \
	VK_DECLARE_STDCLONE(className, vkEvent); \


	/**
	Macro to use in declaration of new classes of event for which a vkType is available.
	@param className the name of the new event class
	@param superClassName the name of the super class.
	*/
#define VK_DECLARE_EVENTTYPE(className, superClassName) \
	VK_DECLARE_RTTI_RTTIOBJECT(className, superClassName); \
	VK_DECLARE_STDCLONE(className, vkEvent); \


	/**
	 Macro to use in implementation of new classes of event.
	@param className the name of the new event class
	*/
#define VK_IMPLEMENT_EVENT(className) \
	VK_IMPLEMENT_RTTI(className); \


#define VK_IMPLEMENT_EVENT_CREATE(className) \
	VK_IMPLEMENT_RTTI_EX(className, CREATE, NOTYPE, NOCOMP); \

	/**
	 Macro to use in implementation of new classes of event
	 using a type, a class::RegisterMember method must be provided.
	 And the type must be registered at startup though a call to className::RegisterType
	@param className the name of the new event class
	*/
#define VK_IMPLEMENT_EVENTTYPE(className) \
	VK_IMPLEMENT_RTTI_RTTIOBJECT(className); \


	/************************************************************************/
	/* Inline implementations                                               */
	/************************************************************************/
	VK_INLINE bool
	vkEvent::WasBroadcast() const
	{
		return (m_EventFlags & fWasBroadcast) != 0;
	}

	VK_INLINE bool
	vkEvent::PreBroadcast(vkCtx iCtx)
	{
		return Broadcast(iCtx, uint32(fPreBroadcast));
	}

	VK_INLINE bool
	vkEvent::PostBroadcast(vkCtx iCtx)
	{
		return Broadcast(iCtx, uint32(fPostBroadcast));
	}

	VK_INLINE bool
	vkEvent::StopWhenHandled() const
	{
		return (m_EventFlags & fStopWhenHandled) != 0;
	}

	VK_INLINE void
	vkEvent::SetStopWhenHandled()
	{
		m_EventFlags |= fStopWhenHandled;
	}

	VK_INLINE void
	vkEvent::ResetStopWhenHandled()
	{
		m_EventFlags &= ~fStopWhenHandled;
	}

	VK_INLINE bool
	vkEvent::StopWhenHandledByChainOfResponsibility() const
	{
		return (m_EventFlags & fStopWhenHandledByChainOfResponsibility) != 0;
	}

	VK_INLINE void
	vkEvent::SetStopWhenHandledByChainOfResponsibility()
	{
		m_EventFlags |= fStopWhenHandledByChainOfResponsibility;
	}

	VK_INLINE void
	vkEvent::ResetStopWhenHandledByChainOfResponsibility()
	{
		m_EventFlags &= ~fStopWhenHandledByChainOfResponsibility;
	}

	VK_INLINE bool
	vkEvent::MustBeDispatchedOnMasterDocument() const
	{
		return (m_EventFlags & fMustBeDispatchedOnMasterDocument) != 0;
	}

	VK_INLINE void
	vkEvent::SetMustBeDispatchedOnMasterDocument()
	{
		m_EventFlags |= fMustBeDispatchedOnMasterDocument;
	}

	VK_INLINE void
	vkEvent::ResetMustBeDispatchedOnMasterDocument()
	{
		m_EventFlags &= ~fMustBeDispatchedOnMasterDocument;
	}

} // namespace VKernel

#endif // __vkEvent_h

