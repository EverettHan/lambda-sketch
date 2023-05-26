#ifndef CATCompSerializationSurrogate_H
#define CATCompSerializationSurrogate_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATBaseUnknown.h"

#include "CATSGComposite.h"
#include "CATCompositeTPtr.h"
#include "CATCompositePtrList.h"
#include "CATCompSerializationContext.h"
#include "CATCompStream.h"

typedef CATSG::uint16 CATSGSurrogateVersion;

/**
 * Serialization surrogate are here to serialize a specific family of composites.
 */
class ExportedBySGComposites CATCompSerializationSurrogate : public CATSGComposite
{
public:
    virtual const GUID&             GetGUID() const = 0;
    virtual CATSGSurrogateVersion   GetVersion() const = 0;
    virtual HRESULT                 SetVersion(CATSGSurrogateVersion iVersion) = 0;

    /**
     * Identifies the family of composites that can be serialized through this surrogate.
     */
    virtual CATTraitRawInfo     GetSupportedTrait() const = 0;

    /**
     * Prepares the Composite for the Stream operation.
     * Note: In most cases, this method should just return S_OK without doing anything else.
     */
    virtual HRESULT             PreStream(CATCompSerializationContextWeakPtr& iSerializationCtx, const CATSGCompositePtr& iCompositeToSerialize, const CATSGComposite*& oAdd) = 0;

    /**
     * Stream the content through the associated serialization context.
     */
    virtual HRESULT             Stream(CATCompSerializationContextWeakPtr& iSerializationCtx, CATCompStreamPtr& iStream, const CATSGCompositePtr& iCompositeToSerialize) = 0;

    /**
     * Unstream the content through the associated serialization context.
     * Warning: ioDeserializedComposite must have a valid pointer to allocated memory before calling this method.
     */
    virtual HRESULT             UnStream(CATCompSerializationContextWeakPtr& iSerializationCtx, CATCompStreamPtr& iStream, CATSGCompositePtr& ioDeserializedComposite) = 0;
};

// {BF668640-D4E1-4850-825B-9A7390692219}
static const IID GUID_CATCompSerializationSurrogateTrait =
{ 0xbf668640, 0xd4e1, 0x4850, { 0x82, 0x5b, 0x9a, 0x73, 0x90, 0x69, 0x22, 0x19 } };


template<>
class CATTraitInfo<CATCompSerializationSurrogate>
{
public:
    static const GUID&             GetTraitGUID()
    {
        return GUID_CATCompSerializationSurrogateTrait;
    }
    static const int            GetTraitTag() {
        return CATTraitTag(-1);
    }
    static const CATECompositionMode    GetCompositeMode()
    {
        return CATECompositionModeExclusive;
    }
    static const CATTraitRawInfo         GetRaw()
    {
        DefaultGetRawImplementation;
    }
};

typedef CATCompositeTWeakPtr<CATCompSerializationSurrogate>             CATCompSerializationSurrogateWeakPtr;
typedef CATCompositeTPtr<CATCompSerializationSurrogate>                 CATCompSerializationSurrogatePtr;
typedef CATOnStackBorrowPtr<CATCompSerializationSurrogate>              CATCompSerializationSurrogateBorrowPtr;

#define DeclareSurrogateImplementation(Type, Guid)                                                                                                                                  \
class ExportedBySGComposites CATSGSerializationSurrogate##Type : public CATSGCompositeHost1<CATCompSerializationSurrogate, CATSGComposite>                                               \
{                                                                                                                                                                                   \
public:                                                                                                                                                                             \
    CATSGSerializationSurrogate##Type();                                                                                                                                            \
    virtual ~CATSGSerializationSurrogate##Type();                                                                                                                                   \
    virtual const GUID&             GetGUID() const { return Guid; }                                                                                                                \
    virtual CATSGSurrogateVersion   GetVersion() const;                                                                                                                             \
    virtual HRESULT                 SetVersion(CATSGSurrogateVersion iVersion);                                                                                                     \
    virtual CATTraitRawInfo         GetSupportedTrait() const;                                                                                                                      \
    virtual HRESULT                 PreStream(CATCompSerializationContextWeakPtr& iSerializationCtx, const CATSGCompositePtr& iCompositeToSerialize, const CATSGComposite*& oAddr); \
    virtual HRESULT                 Stream(CATCompSerializationContextWeakPtr& iSerializationCtx, CATCompStreamPtr& iStream, const CATSGCompositePtr& iCompositeToSerialize);       \
    virtual HRESULT                 UnStream(CATCompSerializationContextWeakPtr& iSerializationCtx, CATCompStreamPtr& iStream, CATSGCompositePtr& ioDeserializedComposite);         \
private:                                                                                                                                                                            \
    CATSGSurrogateVersion   _version;                                                                                                                                               \
};


#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompSerializationSurrogate_H
