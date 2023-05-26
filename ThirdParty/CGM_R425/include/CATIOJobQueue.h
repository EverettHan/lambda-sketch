#ifndef CATIOJobQueue_H
#define CATIOJobQueue_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATIOContainers.h"
#include "CATIOJob.h"

#include "CATSGContext.h"

#include <condition_variable>


class ExportedBySGComposites CATIOJobQueue
{
public:
    CATIOJobQueue(const int iSize);

    virtual ~CATIOJobQueue();

    HRESULT TryPopAndExecute(int& ioDoneThisFrame);

    virtual HRESULT PushBack(CATIOJob*& ipJob, CATIOJob*& opDropped);

    virtual HRESULT Merge(CATIOJobQueue& iOtherJobs, int* oNbJobsInserted = nullptr, int* oNbJobsDropped = nullptr);

    virtual HRESULT TryPop(CATIOJob*& opJob);

    virtual HRESULT Remove(CATIOJob* ipJob);

    virtual HRESULT Sort();

    virtual HRESULT Clear();

    virtual int GetSizeLimit() const;

    virtual HRESULT SetSizeLimit(const int iSizeLimit);

    virtual int Size();

    virtual float GetThreshold();

protected:

    HRESULT Execute(CATIOJob* ipJob, int& oDone);

    std::vector<CATIOJob*> _priorityQueue;
    int _sizeLimit;
private:
    void _InsertSorted(CATIOJob*& ipJob);

};

class CATIOJobThreadSafeQueue : private CATIOJobQueue
{
public:
    CATIOJobThreadSafeQueue(const int iSize);

    HRESULT TryPopAndExecute(int& ioDoneThisFrame);

    HRESULT PushBack(CATIOJob*& ipJob, CATIOJob*& opDropped);

    HRESULT Merge(CATIOJobQueue& iOtherJobs, int* oNbJobsInserted = nullptr, int* oNbJobsDropped = nullptr);

    HRESULT TryPop(CATIOJob*& opJob);

    HRESULT Remove(CATIOJob* ipJob);

    HRESULT Sort();

    HRESULT Clear();

    int GetSizeLimit();

    HRESULT SetSizeLimit(const int iSizeLimit);

    int Size();

    float GetThreshold();

    void Abort(bool iAbort);

private:
    std::mutex _mutex;
    bool _abort;
    std::condition_variable _semaphore;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // CATIOJobQueue_H
