#ifndef CATSGCompositeRingZero_h_
#define CATSGCompositeRingZero_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATSGCompositesContainer.h"
#include "CATSGCompositeHost.h"
#include "CATSGContext.h"

class CATRep;

class ExportedBySGComposites CATSGCompositeRingZero : public CATSGCompositeHost1Dedicated<CATSGCompositeRing, CATSGComposite>
{
public:
    CATSGCompositeRingZero();
    CATSGCompositeRingZero(CATSGContext& iSGContext);
    virtual ~CATSGCompositeRingZero();

    virtual CATSGContext* GetContext() {
        return &CATSGContext::Get(ECATExContexReservedDefault);
    }
    virtual const CATSGContext* GetContext() const {
        return &CATSGContext::Get(ECATExContexReservedDefault);
    }

    virtual HRESULT   OnRingEvt(const CATRingEvt& iRingEvt);
    virtual HRESULT   OnRepEvt(const CATRepEvt& iRepEvt);

    virtual unsigned int GetSizeInBytes(const int iIncludeStructuralSize = 1);

    HRESULT AddComposite(CATSGCompositePtr iComposite, CATERingOpMode iOpMode = CATERingOpModeSingle);
    HRESULT RemoveComposite(CATSGCompositePtr iComposite, CATERingOpMode iOpMode = CATERingOpModeSingle);

    CATSGCompositePtr GetView(const CATTraitRawInfo& iTraitRawInfo);
    CATSGCompositePtr GetViewFromTag(const CATTraitTag iTraitTag);
    HRESULT BorrowView(const CATTraitRawInfo& iTraitRawInfo, CATOnStackBorrowBasePtr& oBorrowedPtr);
    HRESULT BorrowViewFromTag(const CATTraitTag iTraitTag, CATOnStackBorrowBasePtr& oBorrowedPtr);

    HRESULT TraverseAll(CATSGCompositesTraverse& iTraverse);
    HRESULT TraverseAll(CATSGCompositesConstTraverse& iTraverse) const;

    virtual std::size_t Count() const;

    void Flush();

    CATSGCompositeRing* GetReserved(const CATExContext iExCtx);

protected:

    CATRep* GetRep() const { return _pAssociatedRep; }
    void SetRep(CATRep* ipRep) { _pAssociatedRep = ipRep; }

    CATSGCompositeRingPtr GetNext() const { return _nextRingPtr; }
    CATSGCompositeRingPtr& GetNextByRef() { return _nextRingPtr; }
    const CATSGCompositeRingPtr& GetNextByRef() const { return _nextRingPtr; }
    void SetNext(CATSGCompositeRingPtr ipNextRing) { _nextRingPtr = ipNextRing; }

protected:
    CATSGComposite*           _polyFlags;

    CATRep*                   _pAssociatedRep;
    CATSGCompositeRingPtr     _nextRingPtr;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATSGCompositeRingZero_h_
