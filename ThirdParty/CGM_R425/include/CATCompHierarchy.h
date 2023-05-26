#ifndef CATCompHierarchy_H
#define CATCompHierarchy_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATSGComposite.h"
#include "CATCompositeTPtr.h"
#include "CATSGCompositeRing.h"

/**
 * When present in a composite ring it is expected that this component allows
 * you to navigate to the parent's composite ring and to the children composite
 * rings.
 *
 * When rings are attached to rep any implementation on this should for example
 * rely on rep hierarchies to provide answers !
 */
class ExportedBySGComposites CATCompHierarchy : public CATSGComposite
{
public:
    /**
     * You should at least allow someone to set another composite as a parent...
     */
    virtual HRESULT 	            SetParent(CATSGCompositeRingWeakPtr& iComp) = 0;

    /**
     * Symmetric method of SetParent.
     */
    virtual CATSGCompositeRingWeakPtr&          GetParent() = 0;
    virtual const CATSGCompositeRingWeakPtr&    GetParent() const = 0;

    /**
     * You can decide in your own implementation whether you want to support DAGs
     * or not (in which case you are a simple tree).
     * If you don't support diamonds, AddParent / RemoveParents should return
     * E_NOTIMPL and GetParents should return a list with only the main parent.
     */
    virtual HRESULT                 AddParent(CATSGCompositeRingWeakPtr& iComp) = 0;
    /**
     * See comments of SupportsDiamonds.
     */
    virtual HRESULT                 RemoveParent(CATSGCompositeRingWeakPtr& iComp) = 0;

    virtual HRESULT                 RemoveAllParents() = 0;

    /**
     * Get the list of direct parents.
     */
    virtual CATSGCompositeWRings&           GetParents() = 0;
    virtual const CATSGCompositeWRings&     GetParents() const = 0;

    /**
     * The whole purpose of the Hierarchy trait is to support tree like (or DAG) structure.
     * Thus you need to support adding children and to remove them.
     */
    virtual HRESULT                 AddChild(CATSGCompositeRingPtr& iComp) = 0;

    /**
     * See comments of AddChild.
     */
    virtual HRESULT                 RemoveChild(CATSGCompositeRingPtr& iComp) = 0;

    /**
     * Get the list of children !
     */
    virtual CATSGCompositeRings&        GetChildren() = 0;
    virtual const CATSGCompositeRings&  GetChildren() const = 0;
};

// {598F2CED-CEFC-4F4E-8A7A-535D5624EE5A}
static const IID GUID_CATCompHierarchyTrait =
{ 0x598f2ced, 0xcefc, 0x4f4e, { 0x8a, 0x7a, 0x53, 0x5d, 0x56, 0x24, 0xee, 0x5a } };

template<>
class CATTraitInfo<CATCompHierarchy>
{
public:
	static const GUID& 			GetTraitGUID()
	{
		return GUID_CATCompHierarchyTrait;
	}
	static const int			GetTraitTag() {
	    return CATTraitTag(CATECompositeTagHierarchy);
	}
	static const CATECompositionMode	GetCompositeMode()
	{
		return CATECompositionModeExclusive;
	}
	static const CATTraitRawInfo 		GetRaw()
	{
        DefaultGetRawImplementation;
	}
};

typedef CATCompositeTWeakPtr<CATCompHierarchy>  CATCompHierarchyWeakPtr;
typedef CATCompositeTPtr<CATCompHierarchy>      CATCompHierarchyPtr;
typedef CATOnStackBorrowPtr<CATCompHierarchy>   CATCompHierarchyBorrowPtr;

#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompHierarchy_H
