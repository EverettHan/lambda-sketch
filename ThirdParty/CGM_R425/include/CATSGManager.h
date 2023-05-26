#ifndef CATSGManager_H
#define CATSGManager_H

#include "CATSGUtil.h"

#include "CATMathPointf.h"
#ifdef SG_COMPOSITES_MULTIOS
#include "CATCompositeTPtr.h"
#include "CATSGComposite.h"
#include "CATSGCompositeRing.h"
#include "CATCompModelIdentification.h"

#ifndef _EMSCRIPTEN_TESTS
    #include "CATCompAnim.h"
#endif//!_EMSCRIPTEN_TESTS

#include "CATCompactingLODRender.h"

#include <set>

class CATIOJob;
class CATRep;
class CAT3DRep;
class CAT2DRep;
class CAT3DLDHBagRep;
class CATSurfacicRep;
class CATRepRender;
class CATSupport;
struct CATCGRInfo;
class CATSGMsgLoopJobs;

namespace CATSG{
    class CATSphericalOcclusionTree;
}

enum ECATIOMsgLoopJobCategory {
    ECATIOMsgLoopJobCategoryUndef = 0,
    ECATIOMsgLoopJobCategoryDownload = 1,
    ECATIOMsgLoopJobCategoryLoadCGR = 2,
    ECATIOMsgLoopJobCategoryLoadRep = 3,
    ECATIOMsgLoopJobCategoryUnloadRep = 4,
    ECATIOMsgLoopJobCategoryUnstream = 5,
    ECATIOMsgLoopJobCategoryUnloadCGR = 6
};

/**
 * Some situations do require scene management, for example in specific context
 * you might want reps annotated or you want an external manager independant
 * of VisuManager or SG itself to maintain information regarding the various
 * nodes of the graph to perform some preparation for the traversal. For all
 * these situation you can set a CATSGManager on the CATSGContext.
 *
 * Public interfaces needed for a class to act that way are related to streaming
 * so that the manager has some entry pôint to start working on things.
 * Below methods will be called automatically by DmuStreaming code if such a
 * manager is registered with the global SGManager. Interestingly this is only
 * the beginning as esquivalent insertion point would have to be provided for
 * Rep creation/destruction independantly of streaming.
 * TODO : See last comment above.
 * TODO2 : Way to many Reviver methods. Need to perform some cleanup when the solution
 * for model integration stabilize.
 */
class ExportedBySGComposites CATSGManager : public CATSGComposite
{
public:
    #ifndef _EMSCRIPTEN_TESTS
    static HRESULT ConvertBE(const CATMathPointf& iBBoxMin, const CATMathPointf& iBBoxMax, CAT3DBoundingSphere& oBV, CATBoolean iApprox = FALSE);
    static HRESULT ConvertBE(const CATMathPoint& iBBoxMin, const CATMathPoint& iBBoxMax, CAT3DBoundingSphere& oBV, CATBoolean iApprox = FALSE);
    static HRESULT ConvertBE(const CAT3DBoundingSphere& iBV, CATMathPointf& oBBoxMin, CATMathPointf& oBBoxMax, CATBoolean iApprox = FALSE);
    static HRESULT ConvertBE(const CAT3DBoundingSphere& iBV, CATMathPoint& oBBoxMin, CATMathPoint& oBBoxMax, CATBoolean iApprox = FALSE);

    /**
     * Symmetric method to RepUnstreamReviver, SG manager might want to know
     * when a specific rep is streamed somewhere, for example to stream
     * additional informations...
     */
    virtual HRESULT RepPreStream(CATRep& iRep, CATRep*& oRep) = 0;

    /**
     * Symmetric method to RepUnstreamReviver, SG manager might want to know
     * when a specific rep is streamed somewhere, for example to stream
     * additional informations...
     */
    virtual HRESULT RepPreStream(const char* iFile, CATRep*& oRep) = 0;

    /**
     * Sometime the sg manager need to be aware of the attach.
     */
    virtual HRESULT AttachReviver(CATRep& iRep, CATRep*& oRep) = 0;

    /**
     * A SG Manager need to know about reps. He should be called back on this
     * method when a rep is unstreamed (or created (NOT IMPL YET - TODO)). In
     * the implementation the manager is free to perform any treatment he see
     * fit: annotate the rep, store associated information in private storage....
     */
    virtual HRESULT RepUnstreamReviver(CATRep& iRep, CATRep*& oRep) = 0;

    /**
     * A SG Manager need to know about reps. He should be called back on this
     * method when a rep is unstreamed (or created (NOT IMPL YET - TODO)). In
     * the implementation the manager is free to perform any treatment he see
     * fit: annotate the rep, store associated information in private storage....
     */
    virtual HRESULT RepUnstreamReviver(const char* iFile, CATRep*& oRep) = 0;

    /**
     * A SG Manager need to know about reps. He should be called back on this
     * method when a rep is unstreamed (or created (NOT IMPL YET - TODO)). In
     * the implementation the manager is free to perform any treatment he see
     * fit: annotate the rep, store associated information in private storage....
     * TODO RF: Would be good to move this one else where ?
     */
    virtual HRESULT RepUnstreamReviver(CATCompModelIdentificationPtr& iModelIdentification, CATRep*& oRep) = 0;

    virtual HRESULT ReviverCallback(CATCompModelIdentificationPtr& iModelId, CAT3DBoundingSphere& iBV, CAT3DRep* iRep, CATCGRInfo* iCGRInfo = NULL) = 0;
    virtual HRESULT ReviverCallback(CATCompModelIdentificationPtr& iModelId, const CATMathPoint& iBBoxMin, const CATMathPoint& iBBoxMax, CAT3DRep* iRep, CATCGRInfo* iCGRInfo = NULL) = 0;

    virtual HRESULT OnUrlReady(const CATIOUri& iUri, CATILockBytes2* iLB2) = 0;

    /**
    * This method will dump the BV dictionary in a predefined fixed location that
    * you should not need to know about.
    */
    virtual HRESULT DumpBVDictionary() = 0;
    /**
    * This method will load the BV dictionary from the predefined fixed location that
    * you should not need to know about.
    */
    virtual HRESULT LoadBVDictionary() = 0;

    /**
    * @deprecated: Use LoadBVDictionary instead.
    * Let's you associate a cgr filepath (or fcs url) with some bounding information.
    * The entry has the following format:
    *       { "<path_or_url>" (<center_x>, <center_y>, <center_z>) <radius> <tick> }
    */
    virtual HRESULT AddToBVDictionnary(const CATUnicodeString& iEntry) = 0;
    /**
    * Let's you associate a cgr filepath (or fcs url) with some bounding information.
    */
    virtual HRESULT UpdateBVInfo(const CATIOUri& iUri, const CAT3DBoundingSphere& iSphere, const CATSGTickTime iTick = 0) = 0;
    virtual HRESULT UpdateBVInfo(const CATIOUri& iUri, const CATMathPoint& iBBoxMin, const CATMathPoint& iBBoxMax, const CATSGTickTime iTick = 0) = 0;
    virtual HRESULT UpdateRepInfo(const CATIOUri& iUri, CATRep* iRep, const CATSGTickTime iTick = 0) = 0;
    virtual HRESULT GetBVInfo(const CATIOUri& iUri, CATMathPoint& oBBoxMin, CATMathPoint& oBBoxMax) = 0;
    virtual HRESULT GetRepInfo(const CATIOUri& iUri, CATRep*& oRep) = 0;
    #endif

    /**
     * A SG Manager need to know about reps. He should be called back on this
     * method when a rep is unstreamed (or created (NOT IMPL YET - TODO)). In
     * the implementation the manager is free to perform any treatment he see
     * fit: annotate the rep, store associated information in private storage....
     * TODO RF: Would be good to move this one else where ?
     */
    virtual HRESULT RepUnstreamReviver(CATILockBytes2* iLB2, CATRep*& oRep) = 0;

    /**
     * Symmetric method to RepUnstreamReviver, SG manager might want to know
     * when a specific rep is streamed somewhere, for example to stream
     * additional informations...
     * TODO RF: Like for above method check if these can be moved else where.
     */
    virtual HRESULT RepPreStream(CATILockBytes2* iLB2, CATRep*& oRep) = 0;

    /**
     * Symmetric method to RepUnstreamReviver, SG manager might want to know
     * when a specific rep is streamed somewhere, for example to stream
     * additional informations...
     * TODO RF: Like for above method check if these can be moved else where.
     */
    virtual HRESULT RepPreStream(CATCompModelIdentificationPtr& iModelIdentification, CATRep*& oRep) = 0;

#ifndef _EMSCRIPTEN_TESTS
    /**
     * Well some scene managers will want to perform stuff on the main classic
     * CATIA thread. For example if you have some processing that involves
     * V6 library that need to be executed only on that thread you could
     * push them to the manager through AddMsgLoopJob, any implementation
     * of a scene manager should then execute these jobs when called back
     * on below method.
     */
    virtual HRESULT OnClassicMsgLoopThread(CATSupport* iSupport) = 0;
    virtual HRESULT OnClassicMsgLoopThread(std::set<CATSupport*>& iSupportList) = 0;
#endif//!_EMSCRIPTEN_TESTS

    /**
     * See also description of OnClassicMsgLoopThread.
     * Basically you might want to get stuff executed on the specific thread
     * handling the main CATIA message loop in which case you should
     * package the operations to be executed as CATIOJob and submit them
     * here.
     */
    virtual HRESULT AddMsgLoopJob(CATIOJob& iJob, const ECATIOMsgLoopJobCategory iCategory) = 0;

    /**
     * Jobs might have changing priorities. When want to be able to notify
     * the scene manager when a fair amount of such changes have happened.
     * TODO : Check when everything is in place if this approach is more
     * efficient than notifying single updates or not.
     */
    virtual HRESULT MsgLoopJobPriorityUpdate() = 0;

    virtual HRESULT GetMsgLoopJobs(const CATSGMsgLoopJobs*& oMsgLoopJobs) const = 0;
    virtual HRESULT MergeMsgLoopJobs(CATSGMsgLoopJobs& iMsgLoopJobs) = 0;

    /**
     * These methods are somewhat related to the out of core support of portion of the geometries.
     * It is not too nice to have these methods there unless you assume any scene graph should have
     * those notions of in core / out of core.
     * The discard limit is the priority level above which an element should be loaded or discarded
     * as not yet important.
     * This value might be continuously adjusted based on several metrics among which FPS...
     */
    virtual float GetDiscardLimit() = 0;

    /**
     * Use this method to set the value that will be retrieved by GetDiscardLimit above.
     */
    virtual HRESULT SetDiscardLimit(const float iDiscardLimit) = 0;

    /**
     * This method returns the maximum number of jobs that can be executed in one frame.
     */
    virtual int GetMaxNbJobs(const ECATIOMsgLoopJobCategory iCategory) = 0;

    /**
     * This method controls the maximum number of jobs that can be executed in one frame.
     */
    virtual HRESULT SetMaxNbJobs(const ECATIOMsgLoopJobCategory iCategory, const int iNewSizeLimit) = 0;

/**
 * Determines whether surfacic reps should be processed by RepUnstreamReviver or not (false by default).
 */
    virtual void SkipReviver(bool iSkip) = 0;

#ifndef _EMSCRIPTEN_TESTS
    virtual HRESULT SetAnimationHandler(CATCompAnimPtr &iAnimPtr) = 0;

    virtual CATCompAnimPtr& GetAnimationHandler() = 0;
#endif//!_EMSCRIPTEN_TESTS

    virtual void SetCompactingRender(CATCompactingLODRender* iCompactingRender) = 0;
    virtual CATCompactingLODRender* GetCompactingRender() = 0;

    virtual void RemoveCubeImpostor( const CATRep& iRep ) = 0;
    virtual HRESULT AddCubeImpostor(CATSGCompositeRingPtr& iRing) = 0;

    virtual HRESULT ClearForContext(CATSGContext* iContext) = 0;

    struct SceneStats
    {
        // public:
        float loadedPercentOfTotalCGRs = 0.f;
        float loadedPercentOfVisibleObjects = 0.f;
        std::uint64_t numberOfUnknownBoundingElements = 0;
        std::uint8_t memoryUsage = 0;
        std::uint8_t memoryUsageThreshold = 0;

        // private:
        std::uint64_t total_numerator = 0;
        std::uint64_t total_denominator = 0;
        std::uint64_t visible_numerator = 0;
        std::uint64_t visible_denominator = 0;
    };
    virtual HRESULT GetSceneStats(SceneStats& oSceneStats) = 0;

    virtual CAT2DRep* GetIndicatorRepAndStartUpdate() = 0;
    virtual HRESULT StopUpdateIndicator() = 0;

};

// {6BD0009E-9622-4CC3-A7A0-45AEEA152392}
const GUID GUID_CATSGManagerTrait =
{ 0x6bd0009e, 0x9622, 0x4cc3, { 0xa7, 0xa0, 0x45, 0xae, 0xea, 0x15, 0x23, 0x92 } };

/**
 * See documentation of unspecialized CATTraitInfo template class for more information
 * on why this specialization is needed / useful.
 */
template<>
class CATTraitInfo<CATSGManager>
{
public:
    static const GUID&                     GetTraitGUID()
    {
        return GUID_CATSGManagerTrait;
    }
    static const int                    GetTraitTag() { return CATTraitTag(-1); }
    static const CATECompositionMode    GetCompositeMode()
    {
        return CATECompositionModeParticular;
    }
    static const CATTraitRawInfo         GetRaw()
    {
        DefaultGetRawImplementation;
    }
};

typedef CATCompositeTPtr<CATSGManager>    CATSGManagerPtr;
#endif // SG_COMPOSITES_MULTIOS
#endif // CATSGManager_H

