#ifndef CATCompHierarchyDefaultImpl_h_
#define CATCompHierarchyDefaultImpl_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATCompHierarchy.h"
#include "CATSGComposite.h"
#include "CATSGCompositeHost.h"
#include "CATSGCompositeRing.h"

class ExportedBySGComposites CATCompHierarchyDefaultImpl : public CATSGCompositeHost1<CATCompHierarchy, CATSGComposite>
{
 public:
    CATCompHierarchyDefaultImpl();
    virtual ~CATCompHierarchyDefaultImpl();
    HRESULT 	                SetParent(CATSGCompositeRingWeakPtr& iComp);
    CATSGCompositeRingWeakPtr&  GetParent();
    const CATSGCompositeRingWeakPtr& GetParent() const;
    HRESULT                     AddParent(CATSGCompositeRingWeakPtr& iComp);
    HRESULT                     RemoveParent(CATSGCompositeRingWeakPtr& iComp);
    HRESULT                     RemoveAllParents();
    CATSGCompositeWRings&       GetParents();
    const CATSGCompositeWRings& GetParents() const;
    HRESULT                     AddChild(CATSGCompositeRingPtr& iComp);
    HRESULT                     RemoveChild(CATSGCompositeRingPtr& iComp);
    HRESULT                     RemoveAllChildren();
    CATSGCompositeRings&        GetChildren();
    const CATSGCompositeRings&  GetChildren() const;
    HRESULT                     OnRingEvt(const CATRingEvt& iRingEvt);
    HRESULT                     OnRepEvt(const CATRepEvt& iRepEvt);
 protected:
     CATSGCompositeRingWeakPtr  _parent;
     CATSGCompositeWRings       _parents;
     CATSGCompositeRings        _children;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATCompHierarchyDefaultImpl_h_
