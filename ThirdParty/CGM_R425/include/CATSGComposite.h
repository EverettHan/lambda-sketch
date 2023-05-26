#ifndef CATISGComposite_H
#define CATISGComposite_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include <vector>

class CATIOJob;
class CATSGContext;
class CATRep;
class CATSGComposite;

template<typename T> class CATCompositeTPtr;
template<typename T> class CATCompositeTWeakPtr;
template<typename T> class CATOnStackBorrowPtr;
typedef CATCompositeTPtr<CATSGComposite>        CATSGCompositePtr;
typedef CATCompositeTWeakPtr<CATSGComposite>    CATSGCompositeWeakPtr;
typedef CATOnStackBorrowPtr<CATSGComposite>     CATSGCompositeBorrowPtr;
template<typename T> class CATSGTraverse;
typedef CATSGTraverse<CATSGCompositePtr>        CATSGCompositesTraverse;
template<typename T> class CATSGConstTraverse;
typedef CATSGConstTraverse<CATSGCompositePtr>   CATSGCompositesConstTraverse;

class CATCompOutOfCore;
typedef CATOnStackBorrowPtr<CATCompOutOfCore>   CATCompOutOfCoreBorrowPtr;

// {00EDBFFF-514C-46EA-9B52-83B3C1432F19}
static const GUID GUID_ClassicTraverseExecutionGroup =
{ 0xedbfff, 0x514c, 0x46ea, { 0x9b, 0x52, 0x83, 0xb3, 0xc1, 0x43, 0x2f, 0x19 } };

/**
 * Composites participate to the scene graph. As such most of the time they will be use when the graph
 * get traversed. Composites are authorized to directly call methods on other composites only if these
 * are parts of the same execution group. If they are not they should instead build an async call
 * through make async or any equivalent and post the associated job to the execution group which
 * will know when to resolve it!
 *
 * Below implementation is currently empty, it is here only to show how things will be handled
 * when we need to rely more on cross thread composite co work.
 */
class ExportedBySGComposites CATSGExecutionGroup
{
public:
    CATSGExecutionGroup(const GUID& iGuid) : _guid(iGuid) {}
    virtual ~CATSGExecutionGroup() {}

    const GUID& GetGuid() const { return _guid; }

    HRESULT OnStart() { return E_NOTIMPL; }
    HRESULT OnEnd() { return E_NOTIMPL; }

    HRESULT Schedule(CATIOJob* /*iJob*/) { return E_NOTIMPL; }
    HRESULT UnSchedule(CATIOJob* /*iJob*/) { return E_NOTIMPL; }
private:
    GUID    _guid;
};

// {DCBAFE39-9FA8-47A3-8261-AACE48923AAA}
const GUID GUID_CATSGCompositeTrait =
{ 0xdcbafe39, 0x9fa8, 0x47a3, { 0x82, 0x61, 0xaa, 0xce, 0x48, 0x92, 0x3a, 0xaa } };

typedef int CATTraitTag;

/**
 * We know these composites to be used a lot in critical code path so we want to
 * be able to query these by tag on top of GUID!
 */
#ifdef _EMSCRIPTEN_TESTS
enum CATECompositeTags {
    CATECompositeTagRenderable = 0,
    CATECompositeTagCullable = 1,
    CATECompositeTagTransform = 2,
    CATECompositeTagHierarchy = 3,
    CATECompositeTagBoundingElement = 4,
    CATECompositeTagIdentifier = 5,
    CATECompositeTagPickable = 6,
    CATECompositeTagOutOfCore = 7,
    CATECompositeTagClassicRep = 8,
    CATECompositeTagMesh = 9,
    CATECompositeTagTopo = 10,
    CATECompositeTagLegacyHint = 11,
    CATECompositeTagDrawInformation = 12,
    CATECompositeTagShading = 13,
    CATECompositeTagSkeleton = 14, // XK7 GPU_SKINNING ++
    CATECompositeTagSkinAnimation = 15,
    CATECompositeTagCustomPassFilter = 16,
};
#else
enum CATECompositeTags {
    CATECompositeTagOutOfCore = 0,
    CATECompositeTagRenderable = 1,
    CATECompositeTagCullable = 2,
    CATECompositeTagPickable = 3,
    CATECompositeTagClassicRep = 4,
    CATECompositeTagTransform = 5,
    CATECompositeTagHierarchy = 6,
    CATECompositeTagMesh = 7,
    CATECompositeTagTopo = 8,
    CATECompositeTagLegacyHint = 9,
    CATECompositeTagDrawInformation = 10,
    CATECompositeTagShading = 11,
    CATECompositeTagBoundingElement = 12,
    CATECompositeTagIdentifier = 13,
    CATECompositeTagSkeleton = 14,  // XK7 GPU_SKINNING ++
    CATECompositeTagSkinAnimation = 15,
    CATECompositeTagCustomPassFilter = 16,
    CATECompositeTagPolyhedralFlags = 17,
    CATECompositeTagRenderPath = 18,
    CATECompositeTagAlternateRep = 19,
    CATECompositeTagStreamOptionsForRep = 20,
    CATECompositeTagVizPrimitiveCache = 21
};
#endif

const int CATTraitTagCount = 22;

#ifdef _EMSCRIPTEN_TESTS
const int CATTraitTagCountLDH = 6;
#else
const int CATTraitTagCountLDH = 1;
#endif

/**
 * Ring event are sent to composites when the ring is modified, aka on additions
 * removal of other composites. See CATRingEvt.
 */
enum CATERingOperation {
    eRingOpUndefined = 0,
    eRingOpCompAdded = 1,
    eRingOpCompRemoved = 2,
    eRingOpRingDeleting = 3
};

/**
 * CATRingEvt are sent to composites each time the list of their sibling composites
 * gets modified.
 */
class ExportedBySGComposites CATRingEvt
{
private:
    CATERingOperation   _operation;
public:
    CATRingEvt(CATERingOperation iOperation = eRingOpUndefined);
    CATRingEvt(const CATRingEvt& iOther);
    ~CATRingEvt();
    CATERingOperation GetOperation() const;
};

class ExportedBySGComposites CATRingChainEvt
{
public:
    CATRingChainEvt() {}
    CATRingChainEvt(const CATRingChainEvt& iOther) {}
    ~CATRingChainEvt() {}
};

/**
 * See CATCompositeEvt
 */
enum CATECompositeChange {
    eCompositeStateChanged = 0,
    eCompositeUndefinedChange = 1
};

class CATCompositeEvt;

/**
 * Events are dispatched to composited when the associated rep does change.
 * This happen for several types of changes specified through this enum.
 */
enum CATERepChange {
    eHierarchyChanged = 0,
    eMoved = 1,
    eGAS = 2,
    eMaterial = 3,
    eGeometry = 4,
    eUndefined = 5
};

class CATRepEvt;

/**
 * See documentation of CATSGComposite. Basically in some situation
 * we might have several composites of the same type attached to
 * a Rep. For other types of composites sometime we might want
 * to explicitly state that it should not happen. This enum
 * serves to identify the composition mode that we want to associate
 * with our composite.
 */
enum CATECompositionMode {
    CATECompositionModeUnset = 0,
    CATECompositionModeExclusive = 1,
    CATECompositionModeMultiple = 2,
    CATECompositionModeNOWAY = 3,
    CATECompositionModeParticular = 4
};

/**
 * Composites can be considered traits of the rep they are associated
 * with. When defining a composite you will specify and abstract base class
 * used as an interface for the specific composite family of rep's trait.
 * These information exist as CATTraitRawInfo and as CATTraitInfo (see below)
 * for implementation reasons. In practice for a new composite family you only
 * have to specify a specialization of CATTraitInfo. See CATSGComposite documentation
 * for more details!
 */
class ExportedBySGComposites CATTraitRawInfo
{
public:
    CATTraitRawInfo() : _guid(NAT<GUID>::value()), _compositionMode(CATECompositionModeUnset), _tag(-1)
    {
    }

    CATTraitRawInfo(const GUID& iTraitGUID,
                    const CATECompositionMode iCompositionMode) : _guid(iTraitGUID), _compositionMode(iCompositionMode), _tag(-1)
    {

    }

    CATTraitRawInfo(const GUID& iTraitGUID, const CATTraitTag iTraitTag,
                    const CATECompositionMode iCompositionMode) : _guid(iTraitGUID), _compositionMode(iCompositionMode), _tag(iTraitTag)
    {

    }

    CATTraitRawInfo(const CATTraitRawInfo& iOther)
    {
        CATSGCopyGUID(_guid, iOther.GetTraitGUID());
        _tag                = iOther.GetTraitTag();
        _compositionMode    = iOther.GetCompositeMode();
    }

    virtual ~CATTraitRawInfo()
    {

    }

    /**
     * GUID associated with the composite family or said
     * other wire Rep's trait.
     */
    const GUID&                    GetTraitGUID() const { return _guid; }

    /**
     * Some composites are just over used and in some critical code
     * path retrieving them from the ring through their GUID might
     * become expensive. To prepare for situation like these we also
     * offer an API that allow us to retrieve them through a type
     * tag (an int). Depending on implementation behind this method
     * has the potential to be nearly as fast as virtual method call.
     */
    const CATTraitTag            GetTraitTag() const { return _tag; }

    /**
     * Gives indication on the composite mode associated with the trait.
     * Some trait support multiple instances in the same ring, associated
     * with the same Rep some other trait require to be exclusive (only one
     * such trait per ring is allowed).
     */
    const CATECompositionMode     GetCompositeMode() const { return _compositionMode; }



    /**
     * Returns a basically empty Trait Raw Info.
     */
    static CATTraitRawInfo NaTValue()
    {
        return CATTraitRawInfo();
    }

    /**
     * Implement to be able to use CATTraitRawInfo as key of std::map
    */
    bool operator<(const CATTraitRawInfo& iK) const
    {
        GUID traitGUID_1 = GetTraitGUID();
        GUID traitGUID_2 = iK.GetTraitGUID();

        return (*((unsigned int*)&traitGUID_1))<(*((unsigned int*)&traitGUID_2));
    }

private:
    GUID _guid;
    CATTraitTag _tag;
    CATECompositionMode _compositionMode;
};

template<>
struct Hash<CATTraitRawInfo>
{
    unsigned int operator()(const CATTraitRawInfo& iK) const
    {
        GUID traitGUID = iK.GetTraitGUID();
        return *((unsigned int*)&traitGUID);
    }
};

/**
 */
inline const bool operator==(const CATTraitRawInfo& iOther0, const CATTraitRawInfo& iOther1)
{
    return ((CATCmpGuid(&(iOther0.GetTraitGUID()), &(iOther1.GetTraitGUID()))
        &&(iOther0.GetCompositeMode()==iOther1.GetCompositeMode()))) ? true : false;
}

inline const bool operator!=(const CATTraitRawInfo& iOther0, const CATTraitRawInfo& iOther1)
{
    return ((!CATCmpGuid(&(iOther0.GetTraitGUID()), &(iOther1.GetTraitGUID()))
        ||(iOther0.GetCompositeMode()!=iOther1.GetCompositeMode()))) ? true : false;
}

typedef std::vector<CATTraitRawInfo> CATTraitsRawInfo;

#define DefaultGetRawImplementation                                                         \
    static const CATTraitRawInfo raw(GetTraitGUID(), GetTraitTag(), GetCompositeMode());    \
    return raw;

/**
 * You have to specialize this class for the types you plan to use as
 * part of composites. If you don't you will have compilation errors.
 *
 * Specializing this template class allows you to specific both the trait
 * (the composite family) GUID as well as the composition mode within the ring.
 *
 * In the specialization you need to provide implementations only of GetTraitGUID
 * and GetCompositeMode.
 *
 * See documentation of CATTrairRawInfo and CATSGComposite for more information
 * on why and how you should specialize this class.
 */
template<typename T>
class CATTraitInfo
{
public:
    static const GUID&                  GetTraitGUID() {}
    static const CATTraitTag            GetTraitTag() { return CATTraitTag(-1); }
    static const CATECompositionMode    GetCompositeMode() { return CATECompositionModeUnset; }
    static const CATTraitRawInfo        GetRaw()
    {
        DefaultGetRawImplementation;
    }
};

/**
 * Specialization for composite.
 */
template<>
class CATTraitInfo<CATSGComposite>
{
public:
    static const GUID&                   GetTraitGUID()
    {
        return GUID_CATSGCompositeTrait;
    }
    static const CATTraitTag             GetTraitTag() { return CATTraitTag(-1); }
    static const CATECompositionMode     GetCompositeMode()
    {
        return CATECompositionModeMultiple;
    }
    static const CATTraitRawInfo         GetRaw()
    {
        DefaultGetRawImplementation;
    }
};

/**
 * CATSGComposites can be added to a ring of composites which in turn can be
 * associated with a SG Rep. Then Rep's will transfer execution control for
 * specific methods to well identified composites.
 *
 * This class is abstract. When you want to create a new composite implementation
 * these is in fact two situations. If you want to create a new implementation for
 * an existing family of composite which already has it's abstract interface well defined
 * with all the associated trait information then you only need to provide the implementation
 * class and made it inherit from the abstract interface through a CATSGCompositeHost<>.
 * Here is an example for the CATSGCompositeRing interface/trait :
 * class ExportedBySGComposites CATSGCompositeRingDefaultImpl : public CATSGCompositeHost1<CATSGCompositeRing, CATSGComposite>
 *
 * As you can see you should specify through the host the list of traits that you want to expose
 * yourself as.
 *
 * If on the other you also want to provide a new trait (a new composite family) then you will
 * have to write the abstract class also and make it inherit from the right trait. When doing so
 * you need to provide also a GUID for your trait as well as associated information. Again we can
 * take the ring as an example here:
 *
 *  class ExportedBySGComposites CATSGCompositeRing : public CATSGComposite
 * {
 * public:
 *   virtual HRESULT    SetAssociation(CATRep* iAssociation) = 0;
 *   virtual CATRep*    GetAssociation() = 0;
 *
 *   virtual HRESULT AddComposite(CATSGCompositePtr iComposite) = 0;
 *   virtual HRESULT RemoveComposite(CATSGCompositePtr iComposite) = 0;
 *
 *   virtual CATSGCompositePtr GetView(const GUID& iIID) = 0;
 *
 *   virtual HRESULT TraverseAll(CATSGCompositesTraverse& iTraverse) = 0;
 * };
 *
 * // {F4B214CE-52CB-4FF1-950F-33DE7D25F9E9}
 * const IID GUID_CATSGCompositeRingTrait = { 0xf4b214ce, 0x52cb, 0x4ff1, { 0x95, 0xf, 0x33, 0xde, 0x7d, 0x25, 0xf9, 0xe9 } };
 *
 * template<>
 * class CATTraitInfo<CATSGCompositeRing>
 * {
 * public:
 *   static const GUID&         GetTraitGUID()
 *   {
 *     return GUID_CATSGCompositeRingTrait;
 *   }
 *   static const CATECompositionMode GetCompositeMode()
 *   {
 *     return CATECompositionModeNOWAY;
 *   }
 *   static const CATTraitRawInfo     GetRaw()
 *   {
 *     return CATTraitRawInfo(GetTraitGUID(), GetCompositeMode());
 *   }
 * };
 *
 * writing all this might appear as too much to do but basically you have only provided
 * a GUID for your type that you had to write one way or another and a simple template
 * specialization which allow you to specify in a non intrusive (and not too verbose whatever
 * you may think :)) the composition mode of your composite as well as it's GUID association.
 *
 * You might wonder why composites don't derive from IUnknown, as there are ref counted there
 * was little to add... in fact this would have make the rule of composition of composite in the
 * ring less clear and potentially much more complex. Composite are not IUnknown interfaces even
 * though they are based on abstract interfaces because they are different things.
 *
 */
class ExportedBySGComposites CATSGComposite
{
public:
    /**
     * Composites are ref counted.
     */
    virtual CATINT32 __stdcall AddRef() = 0;
    /**
     * Composites are ref counted.
     */
    virtual CATINT32 __stdcall Release() = 0;

    /**
     * Composites are owned by the ring they are part of. Use this method to set it.
     */
    virtual HRESULT                    SetOwner(CATSGCompositeWeakPtr iOwner) = 0;
    /**
     * Composites are owned by the ring they are part of. Use this method to get it.
     * The method will return NULL if the composite is not currently attached to any ring.
     */
    virtual CATSGCompositeWeakPtr    GetOwner() const = 0;

    /**
     * You should override this method if you want to be notified of any change to the ring.
     * If you are acquiring any reference to other composite because you depend on them you should
     * absolutely override this one to acquire again the references you need from the newly modified
     * ring as it is now.
     */
    virtual HRESULT        OnRingEvt(const CATRingEvt& iRingEvt) = 0;

    /**
     * You should override this method if you want to get notified of any composite event dispatched
     * by any other composite in your ring.
     */
    virtual HRESULT        OnCompositeEvt(CATCompositeEvt& iCompositeEvt) = 0;

    /**
     * You should override this method if you want to get notified when the Rep to which this
     * composite is associated do change. For example if you composite generates information
     * based on the Rep geometry of children hierarchy and that you need to take appropriate
     * actions when this happen, you should override this method to have an opportunity
     * to check that the Rep is still consistent with the state you have used to generate
     * your own information.
     */
    virtual HRESULT        OnRepEvt(const CATRepEvt& iRepEvt) = 0;

    /**
     * Composites can throw events. Below method will dispatch a composite event
     * to all registered event listeners.
     */
    virtual HRESULT        DispatchCompositeEvt(CATCompositeEvt& iCompositeEvt) = 0;

    /**
     * As composites are full blown event source, you can register to get notified of events
     * they generate. In fact it is the only way to get notified of composite events. In that
     * respect they differ a bit from Rep and Ring events that will be automatically routed
     * to all composites participating in a ring.
     */
    virtual HRESULT        RegisterEvtListener(CATSGCompositePtr &iCompositeEvtListener) = 0;
    virtual HRESULT        UnRegisterEvtListener(CATSGCompositePtr &iCompositeEvtListener) = 0;

    /**
     * This method returns a list of supported traits information.
     */
    virtual CATTraitsRawInfo    GetTraits() const = 0;

    /**
     * This method returns the most derived trait supported.
     */
    virtual CATTraitRawInfo        GetTrait() const = 0;

    /**
     * This method enables anyone to query whether a specific composite do support
     * a given trait.
     */
    virtual const bool            IsTraitSupported(const GUID& iTraitGUID) const = 0;

    /**
     * This method enables anyone to query whether a specific composite do support a given trait.
     * Warning: cannot work for iTraitTag<0
     */
    virtual const bool            IsTraitSupported(const CATTraitTag& iTraitTag) const = 0;

    /**
     * Guess what this method will return the size in bytes of the composite.
     */
    virtual unsigned int         GetSizeInBytes(const int iIncludeStructuralSize = 1) = 0;

#ifndef _EMSCRIPTEN_TESTS
    /**
     * This method will return the composite execution group. This is an important
     * information. Basically before calling directly into another composite methods
     * you should check that it does participate to the same execution group you are
     * part of. If it is indeed the case then even if your execution group supports
     * multi threaded execution this means that you can call into the other composite
     * and that it should be able to handle the situation himself.
     */
    virtual CATSGExecutionGroup*        GetExecutionGroup() = 0;
    virtual const CATSGExecutionGroup*  GetExecutionGroup() const = 0;
#endif

    /**
     * Composites are usually created within a specific execution context. This method allows
     * you to query in by which execution context this composite is owned.
     */
    virtual CATSGContext*           GetContext() = 0;
    virtual const CATSGContext*        GetContext() const = 0;

    /**
     * All composites should support a notion of being 'out of core' ! This method will
     * return a E_NOTIMPL if the specific implementation on which you are calling it
     * doesn't support it. On the contrary if it does support it you should get back
     * S_OK and a borrowed pointer that let you load or unload the composite and that
     * offer the other services offered by the CATCompOutOfCore interface.
     */
    virtual HRESULT               BorrowOutOfCoreView(CATCompOutOfCoreBorrowPtr& oOutOfCore) = 0;

protected:
    /**
     * ONLY FOR INTERNAL USE.
     */
    virtual void SetContext(CATSGContext* iNewContext) = 0;

#ifdef _EMSCRIPTEN_TESTS
protected:
    virtual ULONG RefCount() const = 0;
#endif
};

#include "CATCompositeTPtr.h"

/**
* We want composites to be able to notify other composites that their internal
* state has changed. Clearly they should do this only when needed to avoid
* over stressing the system. There might be quite a few composites that
* will handle that event thus it should be limited to the minimum which means:
*
* If on specific changes you know you want to propagate information to other types
* of composite of which you are already well aware of then do so directly.
* If on the other hand you anticipate that some changes need to be notified to all
* composites even families of composites that you might not yet be aware of then
* you can consider using these events... But still you should take time to double think
* about it :). If in doubt don't do it.
 */
class ExportedBySGComposites CATCompositeEvt
{
private:
    CATECompositeChange      _modification;
    CATSGCompositePtr        _modifiedComposite;
public:
    CATCompositeEvt();
    CATCompositeEvt(CATSGCompositePtr iComposite, CATECompositeChange iModification);
    CATCompositeEvt(const CATCompositeEvt& iOther);
    ~CATCompositeEvt();

    /**
     * Type of composite modification, not much variations at the moment.
     */
    CATECompositeChange& GetModification();

    /**
     * The sibling composite (composite in the same ring) that did change and thus
     * which is responsible of this event being triggered.
     */
    CATSGCompositePtr& GetComposite();
};

/**
 * Events are dispatched to composited when the associated rep does change.
 * This happen for several types of changes specified through this enum.
 * One might worry why specific types of composites would not be called directly
 * by the Rep on specific modifications and in fact in the current implementation
 * some stuff are done this way. The thing is that it would be really
 * difficult to anticipate all the needs of composites to come thus it
 * is much more flexible to rely on these events even though flexibility
 * might come at a cost when maintenance is concerned.
 */
class ExportedBySGComposites CATRepEvt
{
private:
    CATERepChange   _change;
    CATRep* _rep;

public:
    CATRepEvt();
    CATRepEvt(CATRep* iRep, CATERepChange iChange);
    CATRepEvt(const CATRepEvt& iOther);
    CATRepEvt& operator=(const CATRepEvt& iOther);
    ~CATRepEvt();
    /**
     * Type of Rep event.
     */
    CATERepChange GetChange() const;

    /**
     * Rep from which the event originates.
     */
    const CATRep* GetRep() const;

    /**
     * Rep from which the event originates.
     */
    CATRep* GetRep();
};

#include "CATCompositePtrList.h"
typedef std::vector<CATSGCompositePtr>          CATSGComposites;
typedef CATCompositePtrList<CATSGCompositePtr>  CATSGCompositesList;

#endif // SG_COMPOSITES_MULTIOS
#endif // CATISGComposite_H


