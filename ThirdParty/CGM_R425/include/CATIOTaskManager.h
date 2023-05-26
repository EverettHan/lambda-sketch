#ifndef CATIOTaskManager_H
#define CATIOTaskManager_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "SGComposites.h"
#include <vector>

class CATIOJobQueue;
class CATIOJob;

class ExportedBySGComposites CATIOTaskManager
{
public:
    CATIOTaskManager();
     virtual ~CATIOTaskManager();

    static CATIOTaskManager& Get();

    HRESULT RemoveJobFromQueues(CATIOJob* iJob);
    HRESULT RecordQueue(CATIOJobQueue* iQueue);
    HRESULT RemoveQueue(CATIOJobQueue* iQueue);

private:
    static CATIOTaskManager* s_default;
    std::vector<CATIOJobQueue*> _queues;
    CATIOAtomicLock _lock;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // CATIOTaskManager_H
