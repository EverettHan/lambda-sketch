#ifndef CATIOFuture_H
#define CATIOFuture_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
// SystemTS (PublicInterfaces)
#include "CATConstantsForThreads.h"

// SGInfra (ProtectedInterfaces)
#include "CATIOJob.h"
#include "CATIOAtomics.h"

class CATRep;

/**
 * This is a template class for yet to come stuff.
 * You can basically have future on anything. Future can then
 * be queried to see if the result is available or not or to
 * gmet status information about the associated job.
 * Futures are mainly interesting in the context of asynchronous
 * of multi threaded work. They provide a mechanism for passing
 * yet to come data in a thread safe manner that you can use safely
 * without having to worry about synchronization issues.
 */
template<typename T>
class CATIOFuture
{
public:
    CATIOFuture()
        : _mutex()
        , _associatedJob(nullptr)
        , _value(NAT<T>::value())
    {
    }

    CATIOFuture(const T& iT)
        : _mutex()
        , _associatedJob(nullptr)
        , _value(iT)
    {
    }

    CATIOFuture(CATIOJob* iJob)
        : _mutex()
        , _associatedJob(iJob)
        , _value(NAT<T>::value())
    {
        if (iJob) {
            iJob->AddRef();
        }
    }

    CATIOFuture(const CATIOFuture<T>& iOther)
    {
        // This is a little ugly. Facilitate work with containers,
        // only ref count of associated job is changed (which would
        // not be needed if we had other ways to track ownership count of some objects).
        CATIOFuture<T>* other = const_cast<CATIOFuture<T>*>(&iOther);
        other->Lock();
        _associatedJob = other->_associatedJob;
        if (_associatedJob) {
            _associatedJob->AddRef();
        } else {
            other->TryGet(_value);
        }
        other->Unlock();
    }

    ~CATIOFuture()
    {
        Lock();
        if (_associatedJob) {
            _associatedJob->Release();
            _associatedJob = nullptr;
        }
        Unlock();
    }

    CATIOFuture& operator=(const CATIOFuture<T>& iOther)
    {
        // Ok this is a little ugly.
        CATIOFuture<T>* other = const_cast<CATIOFuture<T>*>(&iOther);
        Lock();
        other->Lock();
        _associatedJob = other->_associatedJob;
        if (_associatedJob) {
            _associatedJob->AddRef();
        } else {
            other->TryGet(_value);
        }
        other->Unlock();
        Unlock();
        return *this;
    }

    CATIOFuture& operator=(const T& iOther)
    {
        Lock();
        if (_associatedJob) {
            _associatedJob->Release();
            _associatedJob = nullptr;
        }
        _value = iOther;
        Unlock();
        return *this;
    }

    bool operator==(const CATIOFuture<T>& iOtherT)
    {
        bool res = false;
        CATIOFuture<T>* other = const_cast<CATIOFuture<T>*>(&iOtherT);
        Unlock();
        other->Lock();

        T t0, t1;
        if ((_associatedJob == other->_associatedJob) && (_associatedJob != nullptr))
        {
            res = true;
        }
        else if (TryGet(t0) && other->TryGet(t1))
        {
            res = ((t0 == t1) != 0);
        }

        other->Unlock();
        Unlock();
        return res;
    }

    bool operator!=(const CATIOFuture<T>& iOtherT)
    {
        return !(*this == iOtherT);
    }

    /**
    * Futures are most of the time associated with the CATIOJob
    * that need be processed so that the result is in fact produced.
    * You might want to get at the associated job to query it's status
    * or to build a new similar job with a different priority or anything
    * that might cross your mind. In any case you can use the below method
    * to get at the associated job if there is any.
    */
    CATIOJob* GetAssociatedJob()
    {
        Lock();
        CATIOJob* const job = _associatedJob;
        if (job) {
            job->AddRef();
        }
        Unlock();
        return job;
    }

    /**
    * This method will try to get the associated result for you.
    * If you get 0 job is not done yet.
    * If you get 1 the job is done and you have got a result.
    * If you get -1 then your job is not done and not even scheduled. In
    * that specific situation you will have to do something special to
    * get some result out of it. Either you schedule it again or
    * you decide to execute the associated job on your own on your
    * own thread!
    */
    bool TryGet(T& oT)
    {
        bool res = false;
        if (TryLock())
        {
            if (_associatedJob == nullptr)
            {
                oT = _value;
                res = true;
            }
            else if (_associatedJob->GetState() == CATEIOJobStateDone)
            {
                int resSize;
                _value = *((T*)(_associatedJob->GetResult(resSize)));
                oT = _value;
                res = true;
                _associatedJob->Release();
                _associatedJob = nullptr;
            }
            Unlock();
        }
        return res;
    }

    /**
    * A non blocking get. Might disrupt things a little if you really
    * wanted your job to be executed on a specific thread. Thus this
    * is a rather risky get but it won't block you.
    */
    T GetOrDoInPlaceAndGet()
    {
        T res;
        while (!TryGet(res)) {
            ExecuteInPlace();
        }
        return res;
    }

    /**
    * This is a blocking Get, use with care :). Use it only if at some point
    * you decide that you really need to get the value whatever the cost and
    * even if it does imply blocking the current thread until the job associated
    * with the current future is done somewhere else.
    *
    * In fact as you will be blocking current thread you should really
    * check that at least the job you are going to wait on is scheduled
    * else where... see IsNotScheduled method.
    *
    * One might think that it would be much better to call ExecuteInPlace
    * in this method if the job is not done yet but it is not so. Sometime
    * we really need things to get executed where they have been scheduled
    * for example in some situation we only want specific threads to interact
    * with scarse IO ressources or ressources that perform better when
    * accessed through specific threads. Thus we really need the granularity
    * to do that at API level, if in your case you could have run ExecuteInPlace
    * without negative impact then you still have the option to TryGet and call
    * ExecuteInPlace yourself or consider using DoGet which might do what
    * you want.
    */
    T Get()
    {
        T res;
        while (!TryGet(res)) {
        }
        return res;
    }

    /**
    * This method will return true if the associated job is not scheduled.
    * This means that if you want to get the value that the future sustend
    * you have either to execute on the current thread the associated job
    * (see the ExecuteInPlace method) or you have to ensure that it
    * get scheduled somewhere (for example check the TrySchedule method
    * of the CATIOManager).
    */
    bool IsNotScheduled()
    {
        bool res = false;
        if (TryLock())
        {
            if (_associatedJob && (_associatedJob->GetState() == CATEIOJobStateNotScheduled))
            {
                res = true;
            }
            Unlock();
        }
        return res;
    }

    /**
    * This method will ensure the associated job is executed on the calling thread.
    * This might appear has something that defeat the whole purpose of running
    * stuff asynchronously and schedule them but sometime either you need the
    * result now and you are ready to execute on the current thread for it.
    * This method will still handle everything in thread safe way so that the
    * job state is correctly modified so that it won't be executed a second time
    * even if it is still scheduled somewhere.
    */
    HRESULT ExecuteInPlace()
    {
        HRESULT hr = E_FAIL;
        Lock();
        if (_associatedJob)
            hr = _associatedJob->Execute();
        Unlock();
        return hr;
    }

    static CATIOFuture<T> NaTValue()
    {
        return CATIOFuture<T>();
    }

private:
    void Lock()
    {
        _mutex.Lock();
    }

    bool TryLock()
    {
        return (_mutex.TryLock() == CATMutexSuccessful);
    }

    void Unlock()
    {
        _mutex.Unlock();
    }

private:
    CATIOAtomicLock         _mutex;
    CATIOJob*               _associatedJob;
    T                       _value;
};

//The copy constructor of this class is a move
//DO NOT inherit: non virtual destructor, no virtual method
class CATIOMovableRepPtr
{
public:
    CATIOMovableRepPtr(const CATIOMovableRepPtr& ioOther)
        : _rep(nullptr)
    {
        CATIOMovableRepPtr& other = const_cast<CATIOMovableRepPtr&>(ioOther);
        _rep = other._rep;
        other._rep = nullptr;
    }

    CATIOMovableRepPtr(CATRep* iRep)
        : _rep(iRep)
    {
    }

    CATIOMovableRepPtr()
        : _rep(nullptr)
    {

    }

    CATRep* MoveRep()
    {
        CATRep* oRep = (CATRep*)_rep;
        _rep = nullptr;
        return oRep;
    }

    ~CATIOMovableRepPtr()
    {
        if(_rep != nullptr)
        {
            _rep->Destroy();
            _rep = nullptr;
        }
    }

    void operator=(const CATIOMovableRepPtr& ioOther)
    {
        CATIOMovableRepPtr& other = const_cast<CATIOMovableRepPtr&>(ioOther);
        _rep = other._rep;
        other._rep = nullptr;
    }

private:
    CATRep* _rep;
};

template<>
struct NAT<CATIOMovableRepPtr>
{
    static CATIOMovableRepPtr value()
    {
        CATIOMovableRepPtr nat;
        return nat;
    }
};

typedef CATIOFuture<CATIOMovableRepPtr>     CATIOFutureRep;
typedef CATIOFuture<HRESULT>    CATIOFutureHr;

#endif // SG_COMPOSITES_MULTIOS
#endif // CATIOFuture_H
