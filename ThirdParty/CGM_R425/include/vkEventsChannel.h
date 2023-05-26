/**
@file

This file defines the vkEventsChannel class.

@COPYRIGHT

@author Gerald Guyomard
*/

#if !defined(__vkEventsChannel_h)
#define __vkEventsChannel_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif
#if !defined(__vkHeapObject_h)
	#include "vkHeapObject.h"
#endif
#if !defined(__vkArray_h)
	#include "vkArray.h"
#endif

namespace VKernel
{
	class vkEvent;
	class vkRTTI;
	class vkEventsListener;
	class vkEventsChannelCell;

	/**
	An events channel is used to broadcast events on some registered
	listeners.
	*/
	class VKKERNEL_API vkEventsChannel : public vkHeapObject
	{
	public:

		/**
		Some default listener priorities.
		*/
		enum
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
		Constructor
		*/
		vkEventsChannel();

		/**
		Copy Constructor

		@param iOther the channel to copy.
		*/
		vkEventsChannel(const vkEventsChannel& iOther);

		/**
		Destructor
		*/
		~vkEventsChannel();

		/**
		Tells if the channel is empty.
		 An empty channel is a channel with no registered listeners.
		@return 
		True if the channel is empty.
		*/
		bool IsEmpty() const;

		/**
		Gets the number of registered listeners.
		@return 
		The number of listeners.
		@see AddListener
		*/
		uint32		GetListenersCount() const;

		/**
		Gets the position of the listener iListener.

		@param iListener the listener to find its position.

		@return The index or 0 if listener is not registered.
		*/
		int32		GetListenerIndex(vkEventsListener* iListener) const;

		/**
		Gets the first registered listener.
		@return 
		The first listener or 0 if channel empty.
		*/
		vkEventsListener*	Front() const;

		/**
		Tells if this channel is being iterated.
		@return if iteration is currently done.
		*/
		bool IsIterationInProgress() const;

		/**
		Base class for iterators.\ Used to scan the channel.
		*/
		struct VKKERNEL_API Iterator
		{
		public :
			/**
			Destructor
			*/
			virtual ~Iterator();

			/**
			Method called on any scanned listener.

			@param iListener the current listener.
			@param iPriority the priority of the listener.

			@return True to stop iteration, false to continue.
			*/
			virtual bool OnListener(vkEventsListener* iListener, int32 iPriority) = 0;
		};

		/**
		Iterates the registered listeners.

		@param iIterator an external iterator handling the listeners.

		@return True if the iterator decided to stop iteration.
		*/
		bool		Iterate(Iterator& iIterator) const;

		/**
		Tells if the listener iListener is registered.

		@param iListener the listener to test.

		@return True if the listener is registered.
		*/
		bool		HasListener(const vkEventsListener* iListener) const;

		/**
		Registers a new listener.

		@param iListener the listener to register.
		@param iPriority the priority of the listener.

		No check for single occurrence is made on iListener.
		The priority determines the order of insertion in the internal list
		and then the priority of event handling.
		Pre-Listeners are listeners with priority < 0
		Post-Listeners are priority with priority >= 0.
		This classification can be used to separate listeners in 2 categories:
		- The high-priority listeners (pre listeners)
		- The low priority ones (post listeners).
		*/
		void		RegisterListener(vkEventsListener* iListener, const int32 iPriority = 0);

		/**
		Registers a new listener making sure it's only registered once in the channel.

		@param iListener the listener to register.
		@param iPriority the priority of the listener.
		*/
		void		RegisterListenerUnique(vkEventsListener* iListener, const int32 iPriority = 0);


		/**
		Unregisters the listener iListener.

		@param iListener the listener to unregister.

		@return True if succeeded, false if the listener was not registered.
		*/
		bool		UnregisterListener(vkEventsListener* iListener);

		/**
		Removes all the listeners.
		*/
		void		Clear();

		/**
		Unregisters all the listeners that are kind of iRTTI.

		@param iRTTI the rtti of the listeners to unregister.
		*/
		void		UnregisterListeners(const vkRTTI& iRTTI);

		/**
		Gets the first listener which is kind of iRTTI.

		@param iRTTI the rtti of the listener to get.

		@return the listener or 0 if not found.
		*/
		vkEventsListener* GetListener(const vkRTTI& iRTTI) const;

		/**
		Gets all the listeners or only those which are kind of iRTTI.

		@param oListeners in output, the desired listeners.
		@param iRTTI if not null, then the rtti of the listeners to get, else all listeners are returned.
		*/
		//@{
		void		GetListeners(vkArray<vkEventsListener*>& oListeners, const vkRTTI* iRTTI = 0) const;
		template <class TListener> void GetListeners(vkArray<TListener*>& oListeners) const;
		//@}

		/**
		Notifies the listeners with the event ioEvent.
		Notifies the listeners starting from the one with the lowest priority (pre listeners) and goes on until the end
		of channel.
		The dispatching ends if one listener handles the event and ioEvent.StopWhenHandled() is true

		@param ioEvent the event to broadcast.
		@param iListenerToExclude if not null, this listener is excluded.
		@param iExcludeEventTarget if true then the event target (provided by ioEvent.GetTarget()) is excluded.

		@return true if a listener handled the event.
		*/
		bool		NotifyListeners(vkEvent& ioEvent, vkEventsListener* iListenerToExclude = 0, bool iExcludeEventTarget = true);

		/**
		Notifies the pre listeners with the event ioEvent.

		@param ioEvent the event to broadcast.
		@param iListenerToExclude if not null, this listener is excluded.
		@param iExcludeEventTarget if true then the event target (provided by ioEvent.GetTarget()) is excluded.

		Pre listeners are listeners with priority < 0.
		Notifies the listeners starting from the one with the lowest priority and goes on until the end
		of the pre listeners group (post listeners are not handled).
		The dispatching ends if one listener handles the event and ioEvent.StopWhenHandled() is true

		@return True if a listener handled the event.
		*/
		bool		NotifyPreListeners(vkEvent& ioEvent, vkEventsListener* iListenerToExclude = 0, bool iExcludeEventTarget = true);

		/**
		Notifies the post listeners with the event ioEvent.

		@param ioEvent the event to broadcast.
		@param iListenerToExclude if not null, this listener is excluded.
		@param iExcludeEventTarget if true then the event target (provided by ioEvent.GetTarget()) is excluded.

		Post listeners are listeners with priority >= 0.
		Notifies the listeners starting from the one with the lowest priority and goes on until the end.
		
		The dispatching ends if one listener handles the event and ioEvent.StopWhenHandled() is true

		@return True if a listener handled the event.
		*/
		bool		NotifyPostListeners(vkEvent& ioEvent, vkEventsListener* iListenerToExclude = 0, bool iExcludeEventTarget = true);

		/**
		Notifies the listeners with the event ioEvent.
		The target of the event is set to each of the listeners.
		The dispatching ends if one listener handles the event and ioEvent.StopWhenHandled() is true

		@param ioEvent the event to broadcast.
		The listeners are notified, from the lowest ones (pre listeners) to the highest ones (post listeners).
		@return true if a listener handled the event.
		*/
		bool		NotifyListenersWithSelfTarget(vkEvent& ioEvent);

	private :

		friend class vkKernelModule;
		static error _Initialize();
		static error _Terminate();
		static error _PurgeStaticChannels(vkCtx iCtx);

		vkEventsChannelCell*	_GetPostListenerHead() const;
		bool	_NotifyListeners(vkEventsChannelCell* iHandle, vkEvent& ioEvent, vkEventsListener* iListenerToExclude, bool iExcludeEventTarget);
		bool	_NotifyPreListeners(vkEvent& ioEvent, vkEventsListener* iListenerToExclude, bool iExcludeEventTarget);

		void _RemoveInvalidCells();
		
		class ReentranceHolder
		{
		public:
			ReentranceHolder(const vkEventsChannel& ioChannel); // Actually it can be modified...
			~ReentranceHolder();
		private:
			ReentranceHolder(const ReentranceHolder&);
			ReentranceHolder& operator=(const ReentranceHolder&);
		private:
			const vkEventsChannel& m_Channel;
		};

		vkEventsChannelCell*	m_Head;

		uint16					m_ReentranceCount;
		mutable uint16			m_HasInvalidCells;
	};

	// Inlined implementations
	VK_INLINE bool vkEventsChannel::IsEmpty() const
	{
		return m_Head == 0;
	}

	VK_INLINE bool
	vkEventsChannel::IsIterationInProgress() const
	{
		return m_ReentranceCount != 0;
	}

	template <class TListener>
	VK_INLINE void
	vkEventsChannel::GetListeners(vkArray<TListener*>& oListeners) const
	{
		GetListeners((vkArray<vkEventsListener*>&) oListeners, &TListener::kRTTI);
	}

	VK_INLINE bool
	vkEventsChannel::NotifyListeners(vkEvent& ioEvent, vkEventsListener* iListenerToExclude, bool iExcludeEventTarget)
	{
		if (m_Head == 0)
		{
			return false;
		}

		return _NotifyListeners(m_Head, ioEvent, iListenerToExclude, iExcludeEventTarget);
	}

	VK_INLINE bool
	vkEventsChannel::NotifyPostListeners(vkEvent& ioEvent, vkEventsListener* iListenerToExclude, bool iExcludeEventTarget)
	{
		vkEventsChannelCell* head = _GetPostListenerHead();
		if (head == 0)
		{
			return false;
		}

		return _NotifyListeners(head, ioEvent, iListenerToExclude, iExcludeEventTarget);
	}

	VK_INLINE bool
	vkEventsChannel::NotifyPreListeners(vkEvent& ioEvent, vkEventsListener* iListenerToExclude, bool iExcludeEventTarget)
	{
		if (m_Head == 0)
		{
			return false;
		}

		return _NotifyPreListeners(ioEvent, iListenerToExclude, iExcludeEventTarget);
	}
}

#endif // __vkEventsChannel_h



