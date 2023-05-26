#ifndef CATSGResourcesManagerDefaultImpl_h_
#define CATSGResourcesManagerDefaultImpl_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATSGComposite.h"
#include "CATSGResourcesManager.h"
#include "CATSGCompositeHost.h"
#include "CATCompSerializationContext.h"
#include "CATIOAtomics.h"
#include "CATCompOutOfCore.h"

#include <mutex>
#include <unordered_set>
#include <unordered_map>

class ExportedBySGComposites CATSGResourcesManagerDefaultImpl : public CATSGCompositeHost1<CATSGResourcesManager, CATSGComposite>
{
    typedef std::unordered_map<CATExContext, CATCompSerializationContextPtr> CATSGSerializationContextAssociations;
    typedef std::unordered_set<CATCompOutOfCore*> CATCompOutOfCoreSet;

public:
    CATSGResourcesManagerDefaultImpl();
    virtual ~CATSGResourcesManagerDefaultImpl();

    virtual HRESULT ClearForContext(CATSGContext* iContext);

    virtual unsigned int        GetSizeInBytes(const int iIncludeStructuralSize = 1);

    virtual HRESULT SetSerializationContextAssociation(CATExContext iExContext, CATCompSerializationContextPtr& iSerializationContext);
    virtual HRESULT GetSerializationContextAssociation(CATExContext iExContext, CATCompSerializationContextPtr& oSerializationContext);
    virtual HRESULT UnSetSerializationContextAssociation(CATExContext iExContext);

    virtual HRESULT RegisterForGarbageCollect(CATCompOutOfCore& iCompositeRing);
    virtual HRESULT Forget(CATCompOutOfCore& iCompositeRing);

    virtual HRESULT Force(CATSGMsgLoopJobs& oJobs);

    virtual HRESULT Load(CATSupport* iSupport, CATSGMsgLoopJobs& oJobs, uint8_t currentFrame, bool& ioIsLDHPathModified);
    virtual HRESULT Load(std::set<CATSupport*>& iSupportList, CATSGMsgLoopJobs& oJobs, uint8_t currentFrame, bool& ioIsLDHPathModified);

    virtual HRESULT Collect(CATSGMsgLoopJobs& oJobs);
    virtual HRESULT Collect(std::set<CATSupport*>& iSupportList, CATSGMsgLoopJobs& oJobs, uint8_t currentFrame, bool& ioIsLDHPathModified);

    virtual HRESULT ForceInCore(CATCompOutOfCore& iOutOfCore);
    virtual HRESULT ForgetForceInCore(CATCompOutOfCore& iOutOfCore);
    virtual std::uint64_t GetNbForceInCore();

    virtual CATIOAtomicReadWriteLock& SGLock();

private:
    CATIOAtomicReadWriteLock _sgLock;

    CATIOAtomicReadWriteLock                _serializationContextLock;
    CATSGSerializationContextAssociations   _serializationContextAssociations;

    std::mutex          _garbageCollectLock;
    CATCompOutOfCoreSet _garbageCollectable;

    std::mutex          _forceInCoreLock;
    CATCompOutOfCoreSet _forceInCoreQueue;

    unsigned int _loaderThreadCount;

};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATSGResourcesManagerDefaultImpl_h_
