//===================================================================
// COPYRIGHT DS SolidWorks 2010/09/03
//===================================================================
// SWXUtOperationContext.cpp
// Header definition of class SWXUtOperationEventManager
//===================================================================
//
// Usage notes:
// Manages rsubscription and dispatch of events of Operatiosn
//
//===================================================================
//  2010/09/03 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef SWXUtOperationEventManager_H
#define SWXUtOperationEventManager_H

#include "SWXUtBasePacket.h"
#include "SWXUtMap.h"
#include "SWXUtSet.h"
#include "SWXUtVector.h"

class SWXUtBaseOperation;
class CATNotification;
class CATBaseUnknown_var;
class SWXUiTestCommandHelper;

//-----------------------------------------------------------------------

class ExportedBySWXUtBasePacket SWXUtOperationEventManager
{

public:

	class Dispatcher
	{
	public:
		virtual ~Dispatcher()
		{
		}
		
		virtual void Dispatch(CATNotification *iNotification) = 0;
		virtual SWXUtBaseOperation *GetOperation() = 0;
		virtual const char *GetNotificationName() = 0;
	};

	template <class T, class V> class DispatchNotification : public Dispatcher
	{
	public:
		DispatchNotification(T *iOperation, V *iNotification) :
		  mOperation(NULL), mNotificationName(NULL)

		{
			// Delibrately not using AddRef
			
			if (iOperation != NULL)
			{
				mOperation = iOperation;
			}

			if (iNotification != NULL)
			{
				mNotificationName = iNotification->GetNotificationName();
			}	
		}

		virtual ~DispatchNotification()
		{
			// Delibrately not using Release, we will be called when object dies

			if (mOperation != NULL)
			{
				mOperation = NULL;
			}

			mNotificationName = NULL;
		}

		virtual void Dispatch(CATNotification *iNotification) 
		{
			mOperation->ReceiveNotification(static_cast<V*>(iNotification));
		}

		virtual const char* GetNotificationName()
		{
			return mNotificationName;
		}

		virtual SWXUtBaseOperation* GetOperation()
		{
			return mOperation;
		}

	private:

		T			*mOperation;
		const char	*mNotificationName;
	};

	static SWXUtOperationEventManager* GetEventManager();
	static SWXUtOperationEventManager* GetEventManagerIfExisting() { return mSingleton; }

	template <class T, class V> static void Subscribe(T *iOperation, V *iNotification)
	{
		GetEventManager()->InternalSubscribe(new DispatchNotification<T,V>(iOperation, iNotification));
	}

	static void DeSubscribe(SWXUtBaseOperation* iOperation)
	{
		GetEventManager()->InternalDeSubscribe(iOperation);
	}

	static void Notify(CATNotification* iNotif, SWXUtBaseOperation* iSource = NULL)
	{
		GetEventManager()->InternalNotify(iNotif, iSource);
	}

	static void DispatchNotifications(SWXUtBaseOperation* iOperation)
	{
		GetEventManager()->InternalDispatchNotifications(iOperation);
	}

	static bool IsEmpty()
	{
		SWXUtOperationEventManager *eventManager = GetEventManager();

		return (eventManager->mEventSubscribedOperations.Size() + eventManager->mOperationSubscribedEvents.Size() + eventManager->mPendingEvents.Size()) == 0;
	}

	typedef SWXUtSet<CATBaseUnknown_var> OperationSet_t;

	static void GetOperationsWithPendingNotifications(OperationSet_t &iPendingOperations)
	{
		GetEventManager()->InternalGetOperationsWithPendingNotifications(iPendingOperations);
	}

	~SWXUtOperationEventManager();

private:
	static SWXUtOperationEventManager* mSingleton;

	SWXUtOperationEventManager();

	void InternalSubscribe(Dispatcher *iDispatch);
	void InternalDeSubscribe(SWXUtBaseOperation* iOperation);

	void InternalNotify(CATNotification* iNotif, SWXUtBaseOperation* iSource = NULL);
	void InternalDispatchNotifications(SWXUtBaseOperation* iOperation);

	void ClearPendingEvents(SWXUtBaseOperation* iOperation);

	void InternalGetOperationsWithPendingNotifications(OperationSet_t &iPendingOperations);

	SWXUtMap<const char*, SWXUtMap<SWXUtBaseOperation*, Dispatcher*> > mEventSubscribedOperations;
	SWXUtMap<SWXUtBaseOperation*, SWXUtVector<Dispatcher*> > mOperationSubscribedEvents;
	SWXUtMap<SWXUtBaseOperation*, SWXUtVector<CATNotification *> > mPendingEvents;

};

#endif