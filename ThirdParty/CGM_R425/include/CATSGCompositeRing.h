#ifndef CATCompositeRing_H
#define CATCompositeRing_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "SGComposites.h"
#include "CATSGComposite.h"
#include "CATIOAtomics.h"
//#include "CATSGLinkedList.h"

#include <cstddef>

class CATRep;
class CATSGCompositeRing;

typedef CATCompositeTPtr<CATSGCompositeRing>        CATSGCompositeRingPtr;
typedef CATCompositeTWeakPtr<CATSGCompositeRing>    CATSGCompositeRingWeakPtr;
typedef std::vector<CATSGCompositeRingPtr>          CATSGCompositeRings;
typedef std::vector<CATSGCompositeRingWeakPtr>      CATSGCompositeWRings;
typedef CATSGTraverse<CATSGCompositeRingPtr>        CATSGCompositeRingsTraverse;
typedef CATSGConstTraverse<CATSGCompositeRingPtr>   CATSGCompositeRingsConstTraverse;

enum CATSGCompositeRingState {
    CATSGCompositeRingStateUndef = 0,
    CATSGCompositeRingStateCreated = 1,
    CATSGCompositeRingStateDeleting = 2
};

enum CATERingOpMode {
    CATERingOpModeSingle = 0, // default !
    CATERingOpModeMultiple = 1, // means you are going to add multiple, you should end this one with flush.
};

enum CATEAssociationPropagationMode {
    CATEAssociationPropagationModeNoPropagate = 0,
    CATEAssociationPropagationModePropagate = 1,
};

/**
 * Composites are meant to be aspects, facet or traits of SG Rep. They are associated with them
 * through a CompositeRing which is itself a composite. CATSGCompositeRing is the base abstract class
 * which defines the ring interface.
 */
class ExportedBySGComposites CATSGCompositeRing : public CATSGComposite
{
    friend class CATRep;

public:
    /**
     * A composite ring is associated with a SG Rep. You can specify to which one through
     * this method. Calling this passing NULL effectively results in detaching the ring
     * from any Rep it might have been attached to.
     *
     * We don't want to authorize this operation while the graph might be traversed or
     * 'in use'. Thus any implementation of this method should ensure that it return
     * E_INVALIDSTATE if it is not the proper time to perform or destroy an association.
     *
     * In practice in the current default implementation of the ring, the operation is
     * just not allowed while we have pass going through the scene graph. For example
     * while we are doing a Culling traverse we just block the operation through a
     * global SG lock maintained by the CATSGResourcesManager.
     *
     * Also we don't expect that composite addition / removal will be taken into account
     * while the ring is attached to a Rep. We expect ring modifications to be possible
     * only when detached from any Rep! See AddComposite / RemoveComposite for more information on this.
     */
    virtual HRESULT SetAssociation(CATRep* iAssociation, const CATEAssociationPropagationMode iAssociationPropagationMode = CATEAssociationPropagationModePropagate);

    /**
     * This method allows you to get back the Rep to which the ring is associated.
     */
    virtual CATRep* GetAssociation();

    /**
     * Use this method to add a specific composite to the ring. This method should
     * check the composition mode of the provided composite. If it is a composite
     * of a family that works in exclusive mode then the method will refuse to do
     * anything and will return an error if there is already such a composite in the ring.
     *
     * We do expect from implementation to not update the ring while it is
     * attached to a rep and certainly not while a pass is traversing the SG (again
     * this information is available through the CATSGresourceManager, see the SetAssocation
     * method for more information on this).
     *
     */
    virtual HRESULT AddComposite(CATSGCompositePtr iComposite, CATERingOpMode iOpMode = CATERingOpModeSingle) = 0;
    /**
     * Use this method to remove the specified composite from the ring.
     * See AddComposite method comments for all the constraints that apply to this method
     * (no Add / Remove while attached the graph and certainly not while it is traversed !)
     */
    virtual HRESULT RemoveComposite(CATSGCompositePtr iComposite, CATERingOpMode iOpMode = CATERingOpModeSingle) = 0;

    /**
     * This method allows you to retrieve a specific composite from the ring
     * by specifying it's GUID. Independently of how composite are stored
     * checking GUID equality might be less efficient than int tag switch or
     * vtable dispatch.
     *
     * WARNING: Calling this method will result in modification of associated
     * composite ref count. If you don't need to reclaim shared ownership of the composite
     * you don't need to use that method. In fact you should use one of the two following
     * Borrow... methods.
     */
    virtual CATSGCompositePtr GetView(const CATTraitRawInfo& iTraitRawInfo) = 0;

    /**
     * See comments of GetView method. Only difference is that if the trait you are interested in
     * is associated with a CATTraitTag you might use it here for even faster queries (well it obviously
     * depends on the implementation behind but at least from an API point of view using a trait tag
     * is lighter and potentially faster.
     */
    virtual CATSGCompositePtr GetViewFromTag(const CATTraitTag iTraitTag) = 0;

    /**
     * If you need to access internals only from your current stacked execution scope and
     * know already you don't want to mess with the composite life cycle more than that you
     * can use a borrow ptr and the following methods. Even though the borrow ptr doesn't do
     * much for now at least you should not be able to create it on the heap which is already
     * some form of protection against incorrect use after the actual object has been deleted.
     * In the future borrowed ptr might be tracked better, relying on them leaves quite a lot
     * of possible different implementation of the below methods.
     */
    virtual HRESULT BorrowView(const CATTraitRawInfo& iTraitRawInfo, CATOnStackBorrowBasePtr& oBorrowedPtr) = 0;

    /**
     * See comments of BorrowView method. Only difference is that if the trait you are interested in
     * is associated with a CATTraitTag you might use it here for even faster queries (well it obviously
     * depends on the implementation behind but at least from an API point of view using a trait tag
     * is lighter and potentially faster.
     */
    virtual HRESULT BorrowViewFromTag(const CATTraitTag iTraitTag, CATOnStackBorrowBasePtr& oBorrowedPtr) = 0;

    /**
     * Will traverse the list of composite associated with the ring. We don't offer
     * iterators yet because we are still not completely sure of the form we would
     * want to give them to be 100% to be able to make them behave nicely in a context
     * in which the composite ring would receive several concurrent hits.
     */
    virtual HRESULT TraverseAll(CATSGCompositesTraverse& iTraverse) = 0;

    /**
     * See above.
     */
    virtual HRESULT TraverseAll(CATSGCompositesConstTraverse& iTraverse) const = 0;

    /**
     * Count all composites inside the ring.
     */
    virtual std::size_t Count() const;

    /**
    * Use this to correctly terminate a sequence of ring operations in Multiple mode (see CATERingOpMode).
    */
    virtual void Flush() = 0;

    virtual HRESULT OnRingEvt(const CATRingEvt& iRingEvt) = 0;
    virtual HRESULT OnRepEvt(const CATRepEvt& iRepEvt) = 0;

    /**
     * By construction the current scene graph and the visualization manager do not disallow use of reps
     * for several viewpoint visualization. For that reason we need to support at the ring level the possibility
     * to have several composite ring for several different sg context. This is not expected to happen very often
     * though. Thus in quite a few places, once you have got the rep ring, if it doesn't match the sg context
     * you are expecting then you should use below method to get the right one.
     */
    virtual CATSGCompositeRing* GetChainedRingForContext(const CATSGContext& iCtx);
    virtual const CATSGCompositeRing* GetChainedRingForContext(const CATSGContext& iCtx) const;

    /**
     * Sometime overrides need to be cross viewpoint and cross workbench or app. NRE is an example of this
     * for that reason they might need to get their own specific rings in quite a lot of situations in specific
     * code parts. Below method is to allow quick lookup on those rings independently of the current
     * execution context or viewpoint. Basically you are allowed to used a special CATExContext to query
     * exactly what you need if you are part of the enumeration for special cases.
     */
    virtual CATSGCompositeRing* GetReserved(const CATExContext iExCtx) = 0;

    /**
     * Will traverse the chain of rings associated with the rep.
     * BEWARE !! It is assumed this method will always be called while holding the global SGLock maintained by
     * the resource manager associated with your context. Thus for good performance reason this method is not acquiring the
     * lock internally, this remain the responsibility of the caller. It your code is triggered by a CATRepRender going through
     * CATSupport everything will be done for you but if you are using these methods in another situation you have to take
     * care of this yourself.
     */
    virtual HRESULT TraverseChain(CATSGCompositeRingsTraverse& iTraverse);

    /**
     * See above.
     * BEWARE !! See above.
     */
    virtual HRESULT TraverseChain(CATSGCompositeRingsConstTraverse& iTraverse) const;

    /**
     * Deprecated method. Use SetAssociation instead.
     */
    virtual void RemoveFromChain(CATSGCompositeRing*);

protected:

    virtual void AddToChain(CATSGCompositeRingPtr iRing);
    virtual void RemoveFromChain();
    virtual void DetachRepFromChain();

    virtual CATRep* GetRep() const = 0;
    virtual void SetRep(CATRep* ipRep) = 0;

    virtual CATSGCompositeRingPtr GetNext() const = 0;
    virtual CATSGCompositeRingPtr& GetNextByRef() = 0;
    virtual const CATSGCompositeRingPtr& GetNextByRef() const = 0;
    virtual void SetNext(CATSGCompositeRingPtr iNextRingPtr) = 0;

protected:

    struct CATSGApplyAssociation : public CATSGCompositeRingsTraverse
    {
        CATRep* _pRep;
        HRESULT _hr;

        CATSGApplyAssociation(CATRep* iRep) : _pRep(iRep), _hr(S_OK) {}

        bool operator()(CATSGCompositeRingPtr& iRingPtr);
    };

    struct CATSGDetachRep : public CATSGCompositeRingsTraverse
    {
        bool operator()(CATSGCompositeRingPtr& iRingPtr);
    };

private:

    virtual CATSGCompositeRing* _GetChainedRingForContext(const CATSGContext& iSearchedCtx, CATSGCompositeRing* iFirstInChain);
    virtual const CATSGCompositeRing* _GetChainedRingForContext(const CATSGContext& iSearchedCtx, const CATSGCompositeRing* iFirstInChain) const;
};

// {F4B214CE-52CB-4FF1-950F-33DE7D25F9E9}
const IID GUID_CATSGCompositeRingTrait = { 0xf4b214ce, 0x52cb, 0x4ff1, { 0x95, 0xf, 0x33, 0xde, 0x7d, 0x25, 0xf9, 0xe9 } };

/**
 * As explained in CATSGomposite documentation each time you introduce a new composite family (or
 * said differently any new Rep trait) you need to specialize CATTraitInfo. This is a way to
 * have a minimally introspect able type system without making intrusive additions to the composite
 * implementations and without too much run time mechanics. Check the unspecialized template
 * class for more details.
 */
template<>
class CATTraitInfo<CATSGCompositeRing>
{
public:
    static const GUID&         GetTraitGUID()
    {
        return GUID_CATSGCompositeRingTrait;
    }
    static const int                 GetTraitTag() { return CATTraitTag(-1); }
    static const CATECompositionMode GetCompositeMode()
    {
        return CATECompositionModeNOWAY;
    }
    static const CATTraitRawInfo     GetRaw()
    {
        DefaultGetRawImplementation;
    }
};

/**
* Count all composites inside a ring.
* Usage:
*     CountSGComposites countComposites;
*     ring->TraverseAll(countComposites);
*     if (countComposites.count > 0)
*     { ... }
*/
struct CountSGComposites : public CATSGCompositesConstTraverse
{
public:
    CountSGComposites() : count(0) {}
    virtual ~CountSGComposites() {}
    virtual bool operator()(const CATSGCompositePtr& /*iComposite*/)
    {
        ++count;
        return true;
    }
public:
    std::size_t count;
};

/**
 * The composite ring can be traverse by any CATSGCompositesTraverse.
 * Here we provide a basic example implementation to find a specific composite
 * in the ring.
 */
struct FindTrait : public CATSGCompositesTraverse
{
    const GUID          _traitGUID;
    bool                _foundOne;
    CATSGCompositePtr   _composite;

    FindTrait(const GUID& iTraitGUID) : _traitGUID(iTraitGUID), _foundOne(false), _composite(NULL)
    {}

    ~FindTrait()
    {
    }

    virtual bool operator()(CATSGCompositePtr& iComposite) {
        if (iComposite->IsTraitSupported(_traitGUID)) {
            _foundOne = true;
            _composite = iComposite;
            return false; // we can stop the traverse so put keepRolling at false!
        }
        return true;
    }
};

CATBoolean ExportedBySGComposites IsRenderableRing(CATSGCompositeRing* iCompositeRing);

struct ExportedBySGComposites FindRenderable : public CATSGCompositesTraverse
{
    CATBoolean _foundOne;
    FindRenderable() : _foundOne(FALSE) { }
    virtual bool operator()(CATSGCompositePtr& iComposite)
    {
        CATSGCompositeRing* ring = StaticCast<CATSGCompositeRing>(iComposite);
        _foundOne = IsRenderableRing(ring);
        return !_foundOne;
    }
};

struct ExportedBySGComposites RingDeletingTraverse : public CATSGCompositesTraverse
{
    CATSGCompositeWeakPtr _nullRing;
    RingDeletingTraverse() : _nullRing(NULL) { }
    virtual ~RingDeletingTraverse() { }
    virtual bool operator() (CATSGCompositePtr& iComposite)
    {
        if (iComposite.IsValid()) {
            iComposite->OnRingEvt(eRingOpRingDeleting);
            iComposite->SetOwner(_nullRing);
        }
        return true;
    }
};

//template<>
//struct NAT<CATSGRingChainElement>
//{
//    static CATSGRingChainElement value()
//    {
//        return CATSGRingChainElement();
//    }
//};

//template<>
//struct Op<CATSGRingChainElement>
//{
//       static HRESULT Swap(CATSGRingChainElement& iT0, CATSGRingChainElement& iT1)
//       {
//           CATSGRingChainElement saved = iT0;
//           iT0 = iT1;
//           iT1 = saved;
//           return S_OK;
//       }
//       static const int Compare(const CATSGRingChainElement& iT0, const CATSGRingChainElement& iT1)
//       {
//           int res = 0;
//           if (iT0.GetValue() > iT1.GetValue()) {
//               res = -1;
//           } else if (iT1.GetValue() > iT0.GetValue()) {
//               res = 1;
//           }
//           return res;
//       }
//       static const bool Equal(const CATSGRingChainElement& iT0, const CATSGRingChainElement& iT1)
//       {
//           return (iT0.GetValue() == iT1.GetValue());
//       }
//};

inline void GetChainedRingForContext(const CATSGContext& iCtx, CATRep& iRep, CATSGCompositeRingPtr& oRing)
{
    CATSGCompositeRing* ring = iRep.GetCompositeRing();
    if (ring != nullptr) {
        oRing = ring->GetChainedRingForContext(iCtx);
    }
}

inline void GetChainedRingForContext(const CATSGContext& iCtx, CATRep* const iRep, CATSGCompositeRingPtr& oRing)
{
    if (iRep != nullptr) {
        CATSGCompositeRing* ring = iRep->GetCompositeRing();
        if (ring != nullptr) {
            oRing = ring->GetChainedRingForContext(iCtx);
        }
    }
}

CATBoolean ExportedBySGComposites CATSGDrawPathOverride(CATRep* iRep, CATRender& iRender, int iInside, CATRepPath& iPath);
/// ioOkToDraw : 1 (yes), 0 (no), -1 (don't know)
CATBoolean ExportedBySGComposites CATSGDrawShadingOverride(CATRep* iRep, CATRender& iRender, int iInside, int& ioOkToDraw);

#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompositeRing_H


