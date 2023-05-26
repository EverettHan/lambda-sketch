#ifndef CATIOManagerDefaultImpl_H
#define CATIOManagerDefaultImpl_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATIOManager.h"

#include "CATCompositeTPtr.h"
#include "CATSGCompositeHost.h"

#include "CATMutex.h"

#include "CATIOAtomics.h"
#include "CATIOJob.h"
#include "CATIOBinders.h"
#include "CATIOFuture.h"
#include "CATIOThread.h"
#include "CATIOContainers.h"
#include "CATILockBytes2.h"
#include "CATCompModelIdentification.h"
#include "CAT3DBagRep.h"

#include "CATIOJobQueue.h"

#include <vector>

class ExportedBySGComposites CATIOManagerDefaultImpl : public CATSGCompositeHost1<CATIOManager, CATSGComposite>
{
public:
    CATIOManagerDefaultImpl();
    virtual ~CATIOManagerDefaultImpl();


    virtual unsigned int GetSizeInBytes(const int iIncludeStructuralSize = 1);

    virtual HRESULT RegisterHandler(CATIOProtocolHandlerPtr protocolHandler);
    virtual HRESULT UnregisterHandler(CATIOProtocolHandlerPtr protocolHandler);

    virtual CATIOProtocolHandlerPtr& GetHandler(CATIOUri iBaseProtocolUri);

    virtual CATIOUri       Save(CATIOBufferPtr iIOBuffer, CATIOUri iUri);
    virtual CATIOUri       Append(CATIOBufferPtr iIOBuffer, CATIOUri iUri);
    virtual CATIOBufferPtr Load(const CATIOUri iCacheUri);
    virtual CATIOBufferPtr Open(CATILockBytes2* iLB2);
    virtual CATIOBufferPtr Open(CATUnicodeString iURI);

    virtual CATIOFutureUri    AsyncSave(CATIOBufferPtr iIOBuffer, CATIOUri iUri, const CATLoadPriority iPriority = 1.f);
    virtual CATIOFutureBuffer AsyncLoad(const CATIOUri& iCacheUri, const CATLoadPriority iPriority = 1.f);
    virtual CATIOFutureBuffer AsyncOpen(CATILockBytes2* iLB2, const CATLoadPriority iPriority = 1.f);
    virtual CATIOFutureBuffer AsyncOpen(const CATUnicodeString& iURI, const CATLoadPriority iPriority = 1.f);

    virtual HRESULT        TrySchedule(CATIOJob& iJob, const ECATIOJobCategory iJobCategory);

    virtual CATIOBufferPtr GetIOBuffer() const;

    virtual HRESULT        InitDefaultHandlers();

    virtual HRESULT        AddJob(CATIOJob& iJob, const ECATIOJobCategory iJobCategory);
    virtual HRESULT        AddJobs(CATIOJobQueue& iJobs, const ECATIOJobCategory iJobCategory, int* oNbJobsInserted, int* oNbJobsDropped);
    virtual HRESULT        SetMaxNbJobs(const ECATIOJobCategory iJobCategory, const int iNewSizeLimit);
    virtual HRESULT        GetMaxNbJobs(const ECATIOJobCategory iJobCategory, int& oSizeLimit, int& oActualSize);
    virtual HRESULT        PriorityUpdate();

    virtual HRESULT        LaunchAsyncProcessing();
    virtual HRESULT        StopAsyncProcessing();
    virtual HRESULT        ManageThreadCount();

public:

    struct IOThread {

        IOThread(CATIOJobThreadSafeQueue& iJobQueue);

        HRESULT LaunchAsyncProcessing();
        HRESULT Process();
        HRESULT StopAsyncProcessing(bool iWaitAndJoin = true);
        HRESULT TryJoin();
        HRESULT WaitAndJoin();

        CATIOJobThreadSafeQueue& _jobs;

        CATIOJob* _pJob;
        CATIOThread* _pThread;
    };

private:

    CATIOJobThreadSafeQueue _streamJobs;
    CATIOJobThreadSafeQueue _unstreamJobs;
    std::vector<IOThread*>  _streamThreads;
    std::vector<IOThread*>  _unstreamThreads;
    std::vector<IOThread*>  _dyingThreads;

    CATIOProtocolHandlerPtr _dummyHandler;
    CATIOAtomicLock         _handlerMgtLock;

    struct HandlerInfo
    {
        CATIOUri 		        _uri;
        CATIOProtocolHandlerPtr	_protocolHandler;

        static HandlerInfo NaTValue()
        {
            HandlerInfo info;
            info._uri = "";
            info._protocolHandler = NULL;

            return info;
        }
    };

    std::vector<HandlerInfo> _handlers;
};

#endif// SG_COMPOSITES_MULTIOS
#endif// CATIOManagerDefaultImpl_H
