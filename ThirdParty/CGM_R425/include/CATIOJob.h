#ifndef CATIOJob_H
#define CATIOJob_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATIOAtomics.h"

#include <limits>
#include <atomic>

enum CATEIOJobState {
    CATEIOJobStateUnset = 0,
    CATEIOJobStateToBeProcessed = 1,
    CATEIOJobStateRunning = 2,
    CATEIOJobStateIdle = 3,
    CATEIOJobStateDone = 4,
    CATEIOJobStateToBeInterrupted = 7,
    CATEIOJobStateInterrupted = 8,
    CATEIOJobStateInError = 9,
    CATEIOJobStateDeleted = 10,
    CATEIOJobStateNotScheduled = 11,
    CATEIOJobStateToBeScheduled = 12,
    CATEIOJobStateToBePaused = 13,
    CATEIOJobStatePaused = 14,
    CATEIOJobStatePending = 15,
    CATEIOJobStateDelayed = 16
};

/**
* CATIOJob contain all the mechanic so that you can execute
* safely stuff in parallel. If you want to do so
* you ony have to derive from CATIOJob and provide your
* own implementation of the private _Execute method.
*
* You can also check CATIOBinder and CATIOBinder job as they
* can provide you with a simple way of automatically creating
* a job class by providing only the class and method you want
* to call and creating instances of these jobs by providing
* only the this and call parameters and having back a future
* of the type you would usually get back from the method call.
*
* Sample below:
* typedef CATIOBinder2Arg<CATIOManagerDefaultImpl, CATIOBufferPtr, CATUri, CATUri> 	CATIOSaveMethodBinder;
* typedef CATIOBinderJob<CATIOSaveMethodBinder> 										CATIOSaveJob;
*
* CATIOFutureUri
* CATIOManagerDefaultImpl::AsyncSave(CATIOBufferPtr iIOBuffer, CATUri iUri)
* {
*	CATIOSaveMethodBinder 	binder(&CATIOManagerDefaultImpl::Save, this, iIOBuffer, iUri);
*	CATIOSaveJob* 			job = new CATIOSaveJob(binder);
*
*	HRESULT hr = AddJob(job);
*	if(hr!=S_OK) {
*		job->ForceState(CATEIOJobStateNotScheduled);
*	}
*
*	CATIOFuture<CATUri> 	furtureUri(job);
*
*	return furtureUri;
* }
*/
class ExportedBySGComposites CATIOJob
{
public:
    CATIOJob()
        : _refCount(1)
        , _state(CATEIOJobStateNotScheduled)
        , _priority(0.0f)
    {
    }

    CATIOJob(float iPriority)
        : _refCount(1)
        , _state(CATEIOJobStateNotScheduled)
        , _priority(iPriority)
    {
    }

    virtual ~CATIOJob()
    {
    }

    inline std::int32_t AddRef()
    {
        return _refCount.fetch_add(1) + 1;
    }

    inline std::int32_t Release()
    {
        const std::int32_t rc = _refCount.fetch_sub(1) - 1;
        if (rc <= 0)
        {
            delete this;
        }
        return rc;
    }

    HRESULT Execute(CATIOJob* iParentJob = nullptr)
    {
        // ToBeProcessed -> Running
        CATEIOJobState expectedState = CATEIOJobStateToBeProcessed;
        if (!_state.compare_exchange_strong(expectedState, CATEIOJobStateRunning))
        {
            // NotScheduled -> Running
            expectedState = CATEIOJobStateNotScheduled;
            if (!_state.compare_exchange_strong(expectedState, CATEIOJobStateRunning))
            {
                // Pending -> Running
                expectedState = CATEIOJobStatePending;
                if (!_state.compare_exchange_strong(expectedState, CATEIOJobStateRunning))
                {
                    // ToBeInterrupted -> Interrupted
                    expectedState = CATEIOJobStateToBeInterrupted;
                    if (!_state.compare_exchange_strong(expectedState, CATEIOJobStateInterrupted))
                    {
                        // Error: Job is in none of the expected states
                        return E_INVALIDSTATE;
                    }
                    else
                    {
                        // Job has been successfully interrupted
                        return S_OK;
                    }
                }
            }
        }

        // EXECUTE JOB
        _Execute(iParentJob);

        // Running -> Done
        expectedState = CATEIOJobStateRunning;
        if (_state.compare_exchange_strong(expectedState, CATEIOJobStateDone))
            return S_OK;
        // ToBeScheduled -> NotScheduled
        expectedState = CATEIOJobStateToBeScheduled;
        if (_state.compare_exchange_strong(expectedState, CATEIOJobStateNotScheduled))
            return S_OK;
        // Pending -> NotScheduled
        expectedState = CATEIOJobStatePending;
        if (_state.compare_exchange_strong(expectedState, CATEIOJobStateNotScheduled))
            return S_OK;
        // ToBeInterrupted -> Interrupted
        expectedState = CATEIOJobStateToBeInterrupted;
        if (_state.compare_exchange_strong(expectedState, CATEIOJobStateInterrupted))
            return S_OK;
        // Idle -> Idle
        if (_state.load() == CATEIOJobStateIdle)
            return S_OK;

        return E_UNKNOWNTERMINATION;
    }

    virtual CATIOJob* GetContinuation() { return nullptr; }
    virtual CATIOJob* GetDeleter() { return nullptr; }
    virtual void* GetResult(int& oBufferSize) { oBufferSize = -1; return nullptr; }

    /**
    * This method will schedule or (re) schedule this job. If the job
    * implementation does not support this feature it should return E_NOTIMPL. If the job is
    * not in unscheduled state it is expected that this method will have no effect and will return E_INVALIDSTATE!
    */
    HRESULT Schedule(CATIOJob* iParentJob = nullptr)
    {
        // NotScheduled -> ToBeProcessed
        CATEIOJobState expectedState = CATEIOJobStateNotScheduled;
        if (!_state.compare_exchange_strong(expectedState, CATEIOJobStateToBeProcessed))
        {
            return E_INVALIDSTATE;
        }

        // SCHEDULE JOB
        HRESULT hr = _Schedule(iParentJob);
        if (FAILED(hr))
        {
            CATIOJob* schedulerJob = _GetScheduler();
            if (schedulerJob)
                hr = schedulerJob->Execute(iParentJob);
        }

        if (FAILED(hr))
        {
            // ToBeProcessed -> NotScheduled (because scheduling failed)
            expectedState = CATEIOJobStateToBeProcessed;
            _state.compare_exchange_strong(expectedState, CATEIOJobStateNotScheduled);
        }
        return hr;
    }

    void ForceState(const CATEIOJobState iState)
    {
        _state.store(iState);
    }

    bool TrySetState(const CATEIOJobState iNewState, const CATEIOJobState iOldState)
    {
        CATEIOJobState expectedState = iOldState;
        return _state.compare_exchange_strong(expectedState, iNewState);
    }

    const CATEIOJobState GetState() const
    {
        return _state.load();
    }

    bool TrySetPriority(const float iPriority)
    {
        _priority.store(iPriority);
        return true;
    }

    /**
    * You can query a job priority through this method. You can not change job priority afterward! The proper
    * way to handle that type of situations is to put the previous job in CATEIOJobStateToBeInterrupted
    * so it won't ever execute and to submit a new one !
    */
    const float GetPriority() const
    {
        return _priority.load();
    }

    bool WaitForState(const CATEIOJobState iState, int iTestCount = 0)
    {
        if (iTestCount <= 0)
            iTestCount = CATSG::CATSGNumericLimits<int>::GetMax();
        int tryCount = 0;
        while ((tryCount++ < iTestCount) && (iState != GetState())) {
        }
        return (tryCount < iTestCount);
    }

protected:
    virtual HRESULT _SetContinuation(CATIOJob* iJob) = 0;
    virtual HRESULT _SetDeleter(CATIOJob* iJob) = 0;
    virtual void _Execute(CATIOJob* iParentJob) = 0;

    /**
    * This method will allow you to set a job that can be executed anywhere and that can schedule this
    * job in the right place. If this job is set then the Schedule method will use it. If it is not
    * set it will call the _Schedule that you can also override in derived classes if you prefer to
    * use that mechanism instead to get your jobs scheduled where they should be.
    */
    virtual HRESULT _SetScheduler(CATIOJob* iJob) = 0;

    /**
    * This method will return a job that can be executed in place (basically anywhere in any execution domain)
    * to schedule this job appropriately (in the right execution domain). It is assumed that jobs that do return
    * NULL can be executed anywhere if they need to (for example if we are trying to run a job that depends on them).
    */
    virtual CATIOJob* _GetScheduler() { return nullptr; }

    /**
    * By default this feature is not supported.
    */
    virtual HRESULT _Schedule(CATIOJob* iParentJob = nullptr) { return E_NOTIMPL; }

private:
    std::atomic<std::int32_t>   _refCount;
    std::atomic<CATEIOJobState> _state;
    std::atomic<float>          _priority;

    CATIOJob(const CATIOJob&);
    CATIOJob& operator=(const CATIOJob&);
};

template <>
struct NAT<CATIOJob*>
{
    static CATIOJob* value() { return nullptr; }
};

inline bool operator< (const CATIOJob& iJob0, const CATIOJob& iJob1) {
    // Let's compare the priority !
    return iJob0.GetPriority() < iJob1.GetPriority();
}

inline bool operator> (const CATIOJob& iJob0, const CATIOJob& iJob1) {
    return iJob1 < iJob0;
}

inline bool operator<= (const CATIOJob& iJob0, const CATIOJob& iJob1) {
    return !(iJob0 > iJob1);
}

inline bool operator>= (const CATIOJob& iJob0, const CATIOJob& iJob1) {
    return !(iJob0 < iJob1);
}

class ExportedBySGComposites CATIOJobNoContinuationPolicy
{
public:
    HRESULT SetContinuation(CATIOJob* iJob) { return E_NOTIMPL; }
    CATIOJob* GetContinuation() { return nullptr; }
};

class ExportedBySGComposites CATIOJobContinuationPolicy
{
public:
    CATIOJobContinuationPolicy()
        : _continuationJob(nullptr)
    {
    }
    HRESULT SetContinuation(CATIOJob* iNewContinuationJob)
    {
        CATIOJob* expectedValue = nullptr;
        if (_continuationJob.compare_exchange_strong(expectedValue, iNewContinuationJob)) {
            return S_OK;
        } else {
            return E_INVALIDSTATE; // already set, set again was refused!
        }
    }
    CATIOJob* GetContinuation()
    {
        return _continuationJob.load();
    }

private:
    std::atomic<CATIOJob*> _continuationJob;
};

class ExportedBySGComposites CATIOJobNODeleterPolicy
{
public:
    HRESULT SetDeleter(CATIOJob* iJob) { return E_NOTIMPL; }
    CATIOJob* GetDeleter() { return nullptr; }
};

class ExportedBySGComposites CATIOJobDeleterPolicy
{
public:
    CATIOJobDeleterPolicy()
        : _deleterJob(nullptr)
    {
    }
    HRESULT SetDeleter(CATIOJob* iNewDeleterJob)
    {
        CATIOJob* expectedValue = nullptr;
        if (_deleterJob.compare_exchange_strong(expectedValue, iNewDeleterJob)) {
            return S_OK;
        } else {
            return E_INVALIDSTATE; // already set, set again was refused!
        }
    }
    CATIOJob* GetDeleter()
    {
        return _deleterJob.load();
    }

private:
    std::atomic<CATIOJob*> _deleterJob;
};

class ExportedBySGComposites CATIOJobNOSchedulerPolicy
{
public:
    HRESULT SetScheduler(CATIOJob* iJob) { return E_NOTIMPL; }
    CATIOJob* GetScheduler() { return nullptr; }
    HRESULT Schedule(CATIOJob* iParentJob) { return E_NOTIMPL; }
};

class ExportedBySGComposites CATIOJobSchedulerPolicy
{
public:
    CATIOJobSchedulerPolicy()
        : _schedulerJob(nullptr)
    {
    }
    HRESULT SetScheduler(CATIOJob* iNewSchedulerJob)
    {
        CATIOJob* expectedValue = nullptr;
        if (_schedulerJob.compare_exchange_strong(expectedValue, iNewSchedulerJob)) {
            return S_OK;
        } else {
            return E_INVALIDSTATE; // already set, set again was refused!
        }
    }
    CATIOJob* GetScheduler()
    {
        return _schedulerJob.load();
    }
    HRESULT Schedule(CATIOJob* iParentJob) { return E_NOTIMPL; }

private:
    std::atomic<CATIOJob*> _schedulerJob;
};

template<typename Functor, typename CATIOContinuationPolicy = CATIOJobNoContinuationPolicy,
    typename CATIODeleterPolicy = CATIOJobNODeleterPolicy, typename CATIOSchedulerPolicy = CATIOJobNOSchedulerPolicy>
    class CATIOBinderJob : public CATIOJob
{
public:
    CATIOBinderJob()
        : CATIOJob()
    {
    }
    CATIOBinderJob(const float iPriority)
        : CATIOJob(iPriority)
    {
    }
    CATIOBinderJob(Functor& iFunctor)
        : CATIOJob()
        , _functor(iFunctor)
    {
    }
    CATIOBinderJob(const float iPriority, Functor& iFunctor)
        : CATIOJob(iPriority)
        , _functor(iFunctor)
    {
    }
    CATIOBinderJob(Functor& iFunctor, CATIOJob* iDeleter, CATIOJob* iContinuation = nullptr)
        : CATIOJob()
        , _functor(iFunctor)
    {
        _SetDeleter(iDeleter);
        _SetContinuation(iContinuation);
    }
    CATIOBinderJob(const float iPriority, Functor& iFunctor, CATIOJob* iDeleter, CATIOJob* iContinuation = nullptr)
        : CATIOJob(iPriority)
        , _functor(iFunctor)
    {
        _SetDeleter(iDeleter);
        _SetContinuation(iContinuation);
    }

    virtual ~CATIOBinderJob()
    {
        CATIOJob* deleter = GetDeleter();
        if (deleter) {
            deleter->Execute(this);
        }
    }

    void Init(Functor& iFunctor)
    {
        CATIOAtomicStackLock lck(_functorLock);
        _functor = iFunctor;
    }

    void Init(Functor& iFunctor, CATIOJob* iDeleter, CATIOJob* iContinuation = nullptr)
    {
        CATIOAtomicStackLock lck(_functorLock);
        _functor = iFunctor;
        _SetDeleter(iDeleter);
        _SetContinuation(iContinuation);
    }

    virtual CATIOJob* GetContinuation()
    {
        return _continuation.GetContinuation();
    }

    virtual CATIOJob* GetDeleter()
    {
        return _deleter.GetDeleter();
    }

    virtual CATIOJob* _GetScheduler()
    {
        return _scheduler.GetScheduler();
    }

    virtual void* GetResult(int& oBufferSize)
    {
        CATIOAtomicStackLock lck(_functorLock);
        return (void*)&_functor.GetResult(oBufferSize);
    }

protected:
    virtual void _Execute(CATIOJob* iParentJob)
    {
        CATIOAtomicStackLock lck(_functorLock);
        if (_functor.ReadyDependencies() == E_INVALIDSTATE) {
            // Then it means that the functor can not resolve all it's dependencies yet
            // thus if it does support (re) scheduling then we should clearly use that option
            // leave some time to the rest of the system and try to run this at a later point in time!
            ForceState(CATEIOJobStateToBeScheduled);
        } else {
            _functor();
        }
    }

    virtual HRESULT _SetContinuation(CATIOJob* iNewContinuationJob)
    {
        return _continuation.SetContinuation(iNewContinuationJob);
    }

    virtual HRESULT _SetDeleter(CATIOJob* iNewDeleterJob)
    {
        return _deleter.SetDeleter(iNewDeleterJob);
    }

    virtual HRESULT _SetScheduler(CATIOJob* iNewSchedulerJob)
    {
        return _scheduler.SetScheduler(iNewSchedulerJob);
    }

    virtual HRESULT _Schedule(CATIOJob* iParentJob)
    {
        return _scheduler.Schedule(iParentJob);
    }

protected:
    Functor                 _functor;

private:
    CATIOAtomicLock         _functorLock;

    CATIOContinuationPolicy _continuation;
    CATIODeleterPolicy      _deleter;
    CATIOSchedulerPolicy    _scheduler;

    CATIOBinderJob(const CATIOBinderJob&);
    CATIOBinderJob& operator=(const CATIOBinderJob&);
};

#endif // SG_COMPOSITES_MULTIOS
#endif // CATIOJob_H
