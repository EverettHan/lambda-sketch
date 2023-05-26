#ifndef CATCompSerializationContext_H
#define CATCompSerializationContext_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATSGComposite.h"
#include "CATCompositeTPtr.h"
#include "CATCompStream.h"
#include "CATCompChannel.h"
#include "CATBoolean.h"

class CATCompSerializationSurrogateHelper;
class CATSGCompositesFactory;
typedef CATCompositeTPtr<CATSGCompositesFactory> CATSGCompositesFactoryPtr;

typedef enum {
    CATSGPropagationPolicy_ZeroPropagation              =  0,
    CATSGPropagationPolicy_Owner                        =  1,
    CATSGPropagationPolicy_Children                     =  2,
    CATSGPropagationPolicy_OwnerChildren                =  3,
    CATSGPropagationPolicy_Parents                      =  4,
    CATSGPropagationPolicy_OwnerParents                 =  5,
    CATSGPropagationPolicy_ChildrenParents              =  6,
    CATSGPropagationPolicy_OwnerChildrenParents         =  7
} CATSGPropagationPolicy;
#define CATSGPropagationPolicy_Default CATSGPropagationPolicy_OwnerChildrenParents

/**
 * The serialization context is a central place for all streaming and persistence operations.
 * In under to use one you need to register a stream to map to the underlying transport to which
 * you want to emit information to. You also have to register channels that will handle the
 */
class ExportedBySGComposites CATCompSerializationContext : public CATSGComposite
{
public:
    /**
     * This is the version of the Serialization system. Much like CGRVersion, it can impact whether and how composites are streamed/unstreamed.
     */
    virtual HRESULT             GetCurrentVersion(CATUINT32& oMajor, CATUINT32& oInter, CATUINT32& oMinor) const = 0;

    /**
     * Use this method to change the output (or input) CATCompStream for this Context.
     */
    virtual HRESULT             SetStream(CATCompStreamPtr& iStream) = 0;
    virtual HRESULT             BorrowStream(CATCompStreamBorrowPtr& oStream) = 0;

    virtual HRESULT             GetFactory(CATSGCompositesFactoryPtr& oFactory) = 0;

    /**
     * Use this method to add a channel to the SerializationContext.
     * Notes:
     * - A Channel is associated to a Trait.
     * - If the context does not contain a channel for one trait, composites of this trait will not be streamed/unstreamed.
     */
    virtual HRESULT             AddChannel(const CATTraitRawInfo& iTrait, CATCompChannelPtr& iChannel) = 0;
    virtual HRESULT             RemoveChannel(const CATTraitRawInfo& iTrait) = 0;
    virtual HRESULT             BorrowChannel(const CATTraitRawInfo& iTrait, CATCompChannelBorrowPtr& oChannel) = 0;
    virtual HRESULT             RequestChannelId(const CATTraitRawInfo& iTrait, CATSGTableId& oChannelId) = 0;

    /**
     * IsStreamable will return TRUE if one channel is associated with the given trait.
     * It will return FALSE otherwise.
     */
    virtual CATBoolean          IsStreamable(const CATTraitRawInfo& iTrait) const = 0;

    /**
     * The CATSGPropagationPolicy defines whether links to other composites should be followed during the streaming pass.
     * You can set a Policy for just one composite (root != NULL) or for all composites (root == NULL).
     */
    virtual HRESULT             SetPropagationPolicy(CATSGPropagationPolicy iPolicy, void* iPropagationRoot) = 0;
    virtual HRESULT             GetPropagationPolicy(CATSGPropagationPolicy& oPolicy, void*& oPropagationRoot) const = 0;

    /**
     * This method should be called only once. It will dump relevant information into the Stream
     * (like version number and channel IDs).
     */
    virtual HRESULT             StreamHeaderInfo() = 0;

    /**
     * This method should be called only once. It will read relevant information from the Stream
     * (like version number and channel IDs).
     */
    virtual HRESULT             UnStreamHeaderInfo() = 0;
     /** Do not use this method unless you know what you are doing. */
    virtual HRESULT             UnStreamHeaderInfo2() = 0;

    /**
     * This is the main stream method. It will look up the history to see if the composite has already been streamed.
     * If so, it will just return the ref. If it has not yet been streamed, it will call the Channel.
     */
    virtual HRESULT             Stream(const CATSGCompositePtr& iComp, CATSGRef& oRef) = 0;

    /**
     * This is the main unstream method. It will look up the history to see if the composite has already been unstreamed.
     * If so, it will just return the pointer. If it has not yet been unstreamed, it will call the Channel.
     */
    virtual HRESULT             UnStream(const CATSGRef& iRef, CATSGCompositePtr& oComp) = 0;

    /**
     * This method will dump into the Stream all the composites that have passed through the context and its channels.
     * It should be called only once (when all streaming actions are finished).
     */
    virtual HRESULT             FlushStream() = 0;

    /**
     * This method will read from the Stream all the composites that have passed through the context and its channels.
     * It should be called only once.
     */
    virtual HRESULT             FlushUnStream(CATSGComposites& oComposites) = 0;

    virtual CATBoolean          IsANullRef(const CATSGRef& iRef) = 0;
    virtual HRESULT             GetNullRef(CATSGRef& oRef) = 0;

protected:
    friend class CATCompSerializationSurrogateHelper;
    /** For internal use only. Do not call this method outside of the serialization classes. */
    virtual HRESULT             Stream(const CATSGCompositePtr& iComp, const CATTraitRawInfo& iTrait, CATCompStreamPtr& iStream) = 0;
    /** For internal use only. Do not call this method outside of the serialization classes. */
    virtual HRESULT             UnStream(CATSGCompositePtr& oComp, const CATTraitRawInfo& iTrait) = 0;
};

// {2AE5AE07-D137-4535-BAB7-5574225E0A4C}
static const IID GUID_CATCompSerializationContextTrait =
{ 0x2ae5ae07, 0xd137, 0x4535, { 0xba, 0xb7, 0x55, 0x74, 0x22, 0x5e, 0xa, 0x4c } };


template<>
class CATTraitInfo<CATCompSerializationContext>
{
public:
	static const GUID& 			GetTraitGUID()
	{
		return GUID_CATCompSerializationContextTrait;
	}
	static const int			GetTraitTag() {
	    return CATTraitTag(-1);
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

typedef CATCompositeTWeakPtr<CATCompSerializationContext>	CATCompSerializationContextWeakPtr;
typedef CATCompositeTPtr<CATCompSerializationContext>		CATCompSerializationContextPtr;
typedef CATOnStackBorrowPtr<CATCompSerializationContext>	CATCompSerializationContextBorrowPtr;

#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompSerializationContext_H
