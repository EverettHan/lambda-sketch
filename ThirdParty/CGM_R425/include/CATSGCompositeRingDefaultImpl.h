#ifndef CATSGCompositeRingDefaultImpl_h_
#define CATSGCompositeRingDefaultImpl_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATSGCompositesContainer.h"
#include "CATSGCompositeHost.h"

class CATRep;
class CATSGContext;

/**
 * Default implementation of the composite Ring. Nothing special to say on that one.
 * There is no special traitments for specific composite that will be used most often,
 * like Renderable, CUllable, Pickable. When this will done performances of GetView
 * using a GUID as parameter need to be measured against an equivalent method using
 * an int type tag instead (only for the reduced list of composite we know will be used most
 * of the time).
 * TODO : See comment above.
 */
class ExportedBySGComposites CATSGCompositeRingDefaultImpl : public CATSGCompositeHost1<CATSGCompositeRing, CATSGComposite>
{
public:
    CATSGCompositeRingDefaultImpl();
    CATSGCompositeRingDefaultImpl(CATSGContext &iSGContext);
    virtual ~CATSGCompositeRingDefaultImpl();

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

    /**
     * See CATSGCompositeRing doc.
     */
    virtual std::size_t Count() const;

    /**
     * See CATSGCompositeRing doc.
     */
    void Flush();

    /**
     * See CATSGCompositeRing doc.
     */
    CATSGCompositeRing *GetReserved(const CATExContext iExCtx);

    CATSGComposites &GetComposites()
    {
        return _container.GetComposites();
    }

protected:
    CATRep *GetRep() const { return _pAssociatedRep; }
    void SetRep(CATRep *ipRep) { _pAssociatedRep = ipRep; }

    CATSGCompositeRingPtr GetNext() const { return _nextRingPtr; }
    CATSGCompositeRingPtr &GetNextByRef() { return _nextRingPtr; }
    const CATSGCompositeRingPtr &GetNextByRef() const { return _nextRingPtr; }
    void SetNext(CATSGCompositeRingPtr iNextRingPtr) { _nextRingPtr = iNextRingPtr; }

protected:
    CATSGCompositesContainer2 _container;
    CATRep *_pAssociatedRep;
    CATSGCompositeRingPtr _nextRingPtr;
    CATSGCompositeRing *_pNreCached;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATSGCompositeRingDefaultImpl_h_
