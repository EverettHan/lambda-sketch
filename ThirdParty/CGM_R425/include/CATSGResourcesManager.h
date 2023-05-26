#ifndef CATSGResourcesManager_H
#define CATSGResourcesManager_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATCompositeTPtr.h"
#include "CATSGCompositeHost.h"
#include "CATCompSerializationContext.h"
#include "CATIOAtomics.h"
#include <cstdint>
#include <set>

class CATSGMsgLoopJobs;
class CATSupport;

/**
 * CATSGRessourcesManager expose important services use full when dealing with resources
 * life cycle, concurrent access and serialization.
 * CATSGRessourcesManager is meant to handle various type of IOs in asynchronous ways.
 */
class ExportedBySGComposites CATSGResourcesManager : public CATSGComposite
{
public:
    virtual HRESULT ClearForContext(CATSGContext* iContext) = 0;

    virtual HRESULT SetSerializationContextAssociation(CATExContext iExContext, CATCompSerializationContextPtr& iSerializationContext) = 0;
    virtual HRESULT GetSerializationContextAssociation(CATExContext iExContext, CATCompSerializationContextPtr& iSerializationContext) = 0;
    virtual HRESULT UnSetSerializationContextAssociation(CATExContext iExContext) = 0;

    /**
     * Use this method to register a composite ring with OutOfCore composite that you want the resource manager
     * to eventually collect for you when Collect is called.
     */
    virtual HRESULT RegisterForGarbageCollect(CATCompOutOfCore& iOutOfCore) = 0;

    /**
     * If you are deleting a ring that was previously registered for garbage collection you should tell the resource
     * manager so that he doesn't have to worry about it anymore.
     */
    virtual HRESULT Forget(CATCompOutOfCore& iOutOfCore) = 0;

    /**
     * Process the visibility array and try to load (or keep loaded) any rep that is deemed visible in at least the CATSupport.
     */
    virtual HRESULT Load(CATSupport* iSupport, CATSGMsgLoopJobs& oJobs, uint8_t currentFrame, bool& ioIsLDHPathModified) = 0;
    /**
     * Process the visibility array and try to load (or keep loaded) any rep that is deemed visible in at least 1 CATSupport.
     */
    virtual HRESULT Load(std::set<CATSupport*>& iSupportList, CATSGMsgLoopJobs& oJobs, uint8_t currentFrame, bool& ioIsLDHPathModified) = 0;

    /**
     * Process the garbage collect array and try to unload any rep that was not flagged visible by the Load pass.
     */
    virtual HRESULT Collect(CATSGMsgLoopJobs& oJobs) = 0;
    /**
     * Process the visibility array and try to unload any rep that is not deemed visible in any CATSupport.
     */
    virtual HRESULT Collect(std::set<CATSupport*>& iSupportList, CATSGMsgLoopJobs& oJobs, uint8_t currentFrame, bool& ioIsLDHPathModified) = 0;

    /**
     * Ask the resource manager to manage the provided CATCompOutOfCore and force them in core
     * at least once. If you also register these for garbage collection or delete them yourself
     * there is clearly no guarantee that they will remain in code.
     */
    virtual HRESULT ForceInCore(CATCompOutOfCore& iOutOfCore) = 0;

    /**
     * Symmetric method to ForceInCore. If you have registered some components that you don't want
     * to force in core anymore use this method to notify the resource manager.
     */
    virtual HRESULT ForgetForceInCore(CATCompOutOfCore& iOutOfCore) = 0;

    /** @nodoc */
    virtual std::uint64_t GetNbForceInCore() = 0;

    /**
     * This method is called when the system see fit and will process the out of core that
     * were provided through ForceInCore.
     */
    virtual HRESULT Force(CATSGMsgLoopJobs& oJobs) = 0;

    virtual CATIOAtomicReadWriteLock& SGLock() = 0;
};

// {4F0A1E94-A897-4C7E-81F7-363BDA5F1B5F}
const GUID GUID_CATSGRessourcesManagerTrait =
{ 0x4f0a1e94, 0xa897, 0x4c7e, { 0x81, 0xf7, 0x36, 0x3b, 0xda, 0x5f, 0x1b, 0x5f } };



template<>
class CATTraitInfo<CATSGResourcesManager>
{
public:
    static const GUID& 					GetTraitGUID()
    {
        return GUID_CATSGRessourcesManagerTrait;
    }
    static const int					GetTraitTag() { return CATTraitTag(-1); }
    static const CATECompositionMode	GetCompositeMode()
    {
        return CATECompositionModeParticular;
    }
    static const CATTraitRawInfo 		GetRaw()
    {
        DefaultGetRawImplementation;
    }
};

typedef CATCompositeTPtr<CATSGResourcesManager>	CATSGResourcesManagerPtr;

#endif // SG_COMPOSITES_MULTIOS
#endif // CATSGResourcesManager_H
