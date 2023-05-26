#ifndef CATIOManager_H
#define CATIOManager_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATIOBuffer.h"
#include "CATIOProtocolHandler.h"

#include "CATCompositeTPtr.h"
#include "CATSGCompositeHost.h"

#include "CATILockBytes2.h"
#include "CATCompModelIdentification.h"

enum ECATIOJobCategory {
    ECATIOJobCategoryUndef = 0,
    ECATIOJobCategoryUnstream = 1,
    ECATIOJobCategoryStream = 2
};

class CATIOJob;
class CATIOJobQueue;

/**
 * CATIOManager is meant to handle various type of IOs in asynchroneous ways.
 */
class ExportedBySGComposites CATIOManager : public CATSGComposite
{
public:
	/**
	 * Use this method to register your own protocol handler that will be used for specific
	 * prefix within the URI provided to Save/Load (or AsyncSave/AsyncLoad) methods. The provided
	 * protocol handler should clearly abide to the CATIOProtocolHandler interfaces.
	 */
	virtual HRESULT RegisterHandler(CATIOProtocolHandlerPtr protocolHandler) = 0;

	/**
	 * Use this method to unregister a previously registered protocol handler. You should use
	 * this one with care as protocol handlers are used both for loading and saving and when it
	 * it will be unregistered there won't be anymore handlers for the specific URI.
	 */
	virtual HRESULT UnregisterHandler(CATIOProtocolHandlerPtr protocolHandler) = 0;

	/**
	 * Method to retrieve the protocol handler that will be used to handle stuff associated
	 * with the specific URI. The URI can be partial and might contain only the 'prefix'. Only
	 * that part will be used to select the protocol handler.
	 */
	virtual CATIOProtocolHandlerPtr& GetHandler(CATIOUri iBaseProtocolUri) = 0;

	/**
	 * This method will save the provided buffer at the specified URI. THe Uri doesn't
	 * need to be complete but it needs to contain at least the desired protocol prefix.
	 * This method will return the exact/complete uri that might be used to retrieve
	 * the save buffer in the future. In case the the operation could not be completed
	 * the returned uri like string will start with error://... some human readable details
	 * about the exact error.
	 */
	virtual CATIOUri Save(CATIOBufferPtr iIOBuffer, CATIOUri iUri) = 0;
    /**
     * This method will append the provided buffer at the end of the ressource. The ressource
     * is identified by the protocol prefix in the input uri.
     */
    virtual CATIOUri Append(CATIOBufferPtr iIOBuffer, CATIOUri iUri) = 0;

	/**
	 * Load back a previously saved buffer.
	 */
	virtual CATIOBufferPtr Load(const CATIOUri iCacheUri) = 0;

    virtual CATIOBufferPtr Open(CATILockBytes2* iLB2) = 0;

    virtual CATIOBufferPtr Open(CATUnicodeString iURI) = 0;

	/**
	 * Asynchronous variant of the save method. Will return a future URI that you can use to
	 * query if the operation is completed or not. If it is you can also retrieve the final
	 * value of the URI if you provided an indicative one.
	 */
	virtual CATIOFutureUri AsyncSave(CATIOBufferPtr iIOBuffer, CATIOUri iUri, const CATLoadPriority iPriority = 1.f) = 0;

	/**
	 * Asynchronous variant of the load operation. As for the save the future that is returned
	 * allows one to query about the status of the operation. Is it completed still pending, not
	 * scheduled (the system might have refused to scheduled it because there was already
	 * too much to do to queue it in an interesting way). If the operation is completed
	 * you can retrieve the content of the buffer. If it is not scheduled you might use
	 * the TrySchedule to try to push it back to the pending queue. Check
	 * TrySchedule method documentation for details.
	 */
	virtual CATIOFutureBuffer AsyncLoad(const CATIOUri& iCacheUri, const CATLoadPriority iPriority = 1.f) = 0;

    virtual CATIOFutureBuffer AsyncOpen(CATILockBytes2* iLB2, const CATLoadPriority iPriority = 1.f) = 0;

    virtual CATIOFutureBuffer AsyncOpen(const CATUnicodeString& iURI, const CATLoadPriority iPriority = 1.f) = 0;

	/**
	 * Use this method if you want to schedule in the main IO job queue a job that you
	 * might have built on your own (not through the async method provided by this manager)
	 * of that has failed to be scheduled.
	 * Basically if the system is too busy and the priority of your job is too low the async
	 * mehtod will return to you a future with an associated with has the status CATEIOJobStateNotScheduled.
	 * You query the future for that situation through the convenience method IsNotScheduled. Things
	 * are done this way so that you have the option to decide to not do the operation, do something
	 * else or insist that you want the thing be done. In that last situation you have two different strategies
	 * either you wait for a time where there is less today (you basically try to rescheduled the job on
	 * a regular basis while retaining the current furture) or you try to increase the priority of the job to
	 * get it scheduled in the end.
	 */
	virtual HRESULT TrySchedule(CATIOJob& iJob, const ECATIOJobCategory iJobCategory) = 0;

	/**
	 * Asynchroneous IO processing can be stoped and resumed. To start it or resume it you can call
	 * below method.
	 */
	virtual HRESULT LaunchAsyncProcessing() = 0;

	/**
	 * If for some reason you want to stop or pause the asychroneous treatments of the IOManager you
	 * can call this method. I don't expect this method to be used much. You should be aware that you
	 * might create a lot of disruption by doing so as quite a lot of code can depend on IO.
	 */
	virtual HRESULT StopAsyncProcessing() = 0;

	/**
     * Add or remove threads depending on the number of unprocessed jobs.
     */
    virtual HRESULT ManageThreadCount() = 0;

	/**
	 * As you can see above most of the interfaces of the IOManaged dealing with data use CATIOBuffer
	 * as a simple abstraction over a raw memory buffer. Clearly at some point you might need such a
	 * buffer to set information that you want to pass to the save methods. To get one you should clearly
	 * use this method, this will ensure that the IO manager provides you with the exact thing that it does
	 * expect to get in those methods. Although the code should use only the public interface of the CATIOBuffer
	 * and thus all of them should be equal it is still good to support some optimization that most of the buffers
	 * comes from the exact same implementation of IOManager that you will use to save and load stuff even though
	 * any sane implementation of CATIOManager should be ready to deal with any type of implementation of CATIOBuffer
	 * by providing at least a code path handling them relying only on the public interface of it.
	 */
	virtual CATIOBufferPtr GetIOBuffer() const = 0;

	/**
	 * You might be interested in submitting IO job that you have build on your own
	 * (not through AsyncSave AsyncLoad) in which case you should use below method
	 * to get them handled as part of the usual flow of IO jobs!
	 * If you choose to provide you new implementation of IOManager different from
	 * the default one and choose not to offer this option then just return E_NOTIMPL.
	 */
	virtual HRESULT AddJob(CATIOJob& iJob, const ECATIOJobCategory iJobCategory) = 0;

    virtual HRESULT AddJobs(CATIOJobQueue& iJobs, const ECATIOJobCategory iJobCategory, int* oNbJobsInserted, int* oNbJobsDropped) = 0;

    /**
     * Change the maximum number of jobs that can be in the same priority queue at the same time.
     * A lower number of jobs means that jobs need a higher priority in order to be processed.
     */
    virtual HRESULT SetMaxNbJobs(const ECATIOJobCategory iJobCategory, const int iNewSizeLimit) = 0;
    virtual HRESULT GetMaxNbJobs(const ECATIOJobCategory iJobCategory, int& oSizeLimit, int& oActualSize) = 0;

	/**
	 * IOJob priorities are bound to change. For optimization reasons
	 * at the moment we prefer to trigger a full reordering of all the jobs
	 * at key point in time.
	 * TODO: Check when everything is in place if this is indeed better
	 * than performing repositionning per job when a precise job get
	 * a change in priority.
	 */
	virtual HRESULT PriorityUpdate() = 0;
};

// {CD36F8CA-15C0-4E97-9793-34920B694613}
const GUID GUID_CATIOManagerTrait =
{ 0xcd36f8ca, 0x15c0, 0x4e97, { 0x97, 0x93, 0x34, 0x92, 0xb, 0x69, 0x46, 0x13 } };


template<>
class CATTraitInfo<CATIOManager>
{
public:
	static const GUID& GetTraitGUID()
	{
		return GUID_CATIOManagerTrait;
	}
	static const int GetTraitTag() { return CATTraitTag(-1); }
	static const CATECompositionMode GetCompositeMode()
	{
		return CATECompositionModeParticular;
	}
	static const CATTraitRawInfo GetRaw()
	{
        DefaultGetRawImplementation;
	}

    static HRESULT GetBindableMethod(const CATUnicodeString& iID, CATIOBufferPtr (CATIOManager::*&opMethod)(const CATIOUri))
    {
        CATIOBufferPtr (CATIOManager::*pLoad)(const CATIOUri) = &CATIOManager::Load;
        if(iID == "CATIOManager::Load") {
            opMethod = pLoad;
            return S_OK;
        } else {
            return E_FAIL;
        }
    }

    static HRESULT GetBindableMethodID(CATIOBufferPtr (CATIOManager::*ipMethod)(const CATIOUri), CATUnicodeString& oID)
    {
        CATIOBufferPtr (CATIOManager::*pLoad)(const CATIOUri) = &CATIOManager::Load;
        if(ipMethod == pLoad) {
            oID = "CATIOManager::Load";
            return S_OK;
        } else {
            return E_FAIL;
        }
    }
};

template <>
struct NAT<CATILockBytes2*>
{
	static CATILockBytes2* value()
	{
		return NULL;
	}
};

typedef CATCompositeTPtr<CATIOManager>	   CATIOManagerPtr;
typedef CATCompositeTWeakPtr<CATIOManager> CATIOManagerWeakPtr;

#endif // SG_COMPOSITES_MULTIOS
#endif // CATIOManager_H
