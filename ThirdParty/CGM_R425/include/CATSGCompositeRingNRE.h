#ifndef CATSGCompositeRingNRE_h_
#define CATSGCompositeRingNRE_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATSGCompositesContainer.h"
#include "CATSGCompositeHost.h"
#include "CATCompDrawInformations.h"
#include "CATSGContext.h"

// XK7 GPU_SKINNING ++
#include "CATCompSkinAnimation.h"
#include "CATCompSkeleton.h"
// XK7 GPU_SKINNING --

#include "CATCompRepIdentifier.h"

class CATRep;

/**
 * Default implementation of the composite Ring. Nothing special to say on that one.
 * There is no special treatments for specific composite that will be used most often,
 * like Renderable, CUllable, Pickable. When this will done performances of GetView
 * using a GUID as parameter need to be measured against an equivalent method using
 * an int type tag instead (only for the reduced list of composite we know will be used most
 * of the time).
 * TODO : See comment above.
 */
class ExportedBySGComposites CATSGCompositeRingNRE : public CATSGCompositeHost1Dedicated<CATSGCompositeRing, CATSGComposite>
{
public:
    CATSGCompositeRingNRE();
    CATSGCompositeRingNRE(CATSGContext &iSGContext);
    virtual ~CATSGCompositeRingNRE();

    virtual CATSGContext *GetContext()
    {
        return &CATSGContext::Get(ECATExContexReservedNRE);
    }
    virtual const CATSGContext *GetContext() const
    {
        return &CATSGContext::Get(ECATExContexReservedNRE);
    }

    /**
     * See CATSGCompositeRing doc.
     */
    virtual HRESULT OnRingEvt(const CATRingEvt &iRingEvt);
    /**
     * See CATSGCompositeRing doc.
     */
    virtual HRESULT OnRepEvt(const CATRepEvt &iRepEvt);

    /**
     * See CATSGCompositeRing doc.
     */
    virtual unsigned int GetSizeInBytes(const int iIncludeStructuralSize = 1);

    /**
     * See CATSGCompositeRing doc.
     */
    HRESULT AddComposite(CATSGCompositePtr iComposite, CATERingOpMode iOpMode = CATERingOpModeSingle);
    /**
     * See CATSGCompositeRing doc.
     */
    HRESULT RemoveComposite(CATSGCompositePtr iComposite, CATERingOpMode iOpMode = CATERingOpModeSingle);

    /**
     * See CATSGCompositeRing doc.
     */
    CATSGCompositePtr GetView(const CATTraitRawInfo &iTraitRawInfo);
    CATSGCompositePtr GetViewFromTag(const CATTraitTag iTraitTag);
    HRESULT BorrowView(const CATTraitRawInfo &iTraitRawInfo, CATOnStackBorrowBasePtr &oBorrowedPtr);
    HRESULT BorrowViewFromTag(const CATTraitTag iTraitTag, CATOnStackBorrowBasePtr &oBorrowedPtr);

    /**
     * See CATSGCompositeRing doc.
     */
    HRESULT TraverseAll(CATSGCompositesTraverse &iTraverse);
    HRESULT TraverseAll(CATSGCompositesConstTraverse &iTraverse) const;

    virtual std::size_t Count() const;

    /**
     * See CATSGCompositeRing doc.
     */
    void Flush();

    /**
     * See CATSGCompositeRing doc.
     */
    CATSGCompositeRing *GetReserved(const CATExContext iExCtx);

protected:
    CATRep *GetRep() const { return nullptr; }
    void SetRep(CATRep *ipRep) {}

    CATSGCompositeRingPtr GetNext() const { return _nextRingPtr; }
    CATSGCompositeRingPtr &GetNextByRef() { return _nextRingPtr; }
    const CATSGCompositeRingPtr &GetNextByRef() const { return _nextRingPtr; }
    void SetNext(CATSGCompositeRingPtr iNextRingPtr) { _nextRingPtr = iNextRingPtr; }

protected:
    // Enable is a container is needed.
    CATSGCompositesContainer2 _container;
    CATSGComposite *_drawInfo;
    // CATSGComposite*           _SkeletonComp;        // XK7 GPU_SKINNING ++
    // CATSGComposite*           _SkinAnimationComp;
    CATSGComposite *_customPassFilterComp;

    // Enable if needed  !
    // CATRep*                _associatedRep;
    CATSGCompositeRingPtr _nextRingPtr;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATSGCompositeRingNRE_h_
