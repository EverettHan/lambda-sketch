#ifndef CATCompChannel_H
#define CATCompChannel_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "SGComposites.h"
#include "CATCompositeTPtr.h"
// #include "CATCompositePtrList.h"
#include "CATSGComposite.h"
#include "CATCompStream.h"

#include <unordered_map>

class CATSGSerializationContext;

class ExportedBySGComposites CATCompChannel : public CATSGComposite
{
public:
    virtual CATSGTableId    GetChannelId() const = 0;
    virtual HRESULT         GetChannelIds(CATSGTableIds& oChannelIds) const = 0;
    virtual CATSG::uint16   GetSurrogateVersion() const = 0;
    virtual HRESULT         SetSurrogateVersion(CATSG::uint16 iVersion) = 0;
    virtual HRESULT         GetSurrogate(CATSGCompositePtr& oSurrogate) const = 0;
    virtual HRESULT         SetSurrogate(CATSGCompositePtr iSurrogate) = 0;
    virtual CATTraitRawInfo GetSupportedTrait() const = 0;

protected:
    friend class CATSGSerializationContext;

    virtual HRESULT SetChannelId(const CATSGTableId iNewChannelId) = 0;
    virtual HRESULT AddChannelId(const CATSGTableId iNewChannelId) = 0;

    virtual HRESULT SetStream(CATCompStreamPtr& iStream) = 0;

    /**
     * 'S_OK' (0) means that the streaming of the composite has been done or requested (a valid oRef is returned).
     * 'S_FALSE' (1) means that the streaming of the composite has been done or requested in a previous call (a valid oRef is returned).
     */
    virtual HRESULT PushBack(const CATSGCompositePtr& iComposite, CATSGRef& oRef) = 0;
    virtual HRESULT PushBack(const CATSGRef& iRef, CATSGCompositePtr& oComp) = 0;
    virtual HRESULT FlushForStream() = 0;
    virtual HRESULT FlushForUnStream(CATSGComposites& oComposites) = 0;

    /** For internal use only. Do not call this method outside of the serialization classes. */
    virtual HRESULT Stream(const CATSGCompositePtr& iComposite, CATCompStreamPtr& iStream, const CATSGRef& iRef) = 0;
    /** For internal use only. Do not call this method outside of the serialization classes. */
    virtual HRESULT UnStream(CATSGCompositePtr& oComposite) = 0;
};

// {6CDC9398-AF7F-4525-B59B-333CA959C0B6}
static const IID GUID_CATCompChannelTrait =
{ 0x6cdc9398, 0xaf7f, 0x4525, { 0xb5, 0x9b, 0x33, 0x3c, 0xa9, 0x59, 0xc0, 0xb6 } };


template<>
class CATTraitInfo<CATCompChannel>
{
public:
    static const GUID&               GetTraitGUID()
    {
        return GUID_CATCompChannelTrait;
    }
    static const int                 GetTraitTag() {
        return CATTraitTag(-1);
    }
    static const CATECompositionMode GetCompositeMode()
    {
        return CATECompositionModeExclusive;
    }
    static const CATTraitRawInfo     GetRaw()
    {
        DefaultGetRawImplementation;
    }
};

typedef CATCompositeTWeakPtr<CATCompChannel>           CATCompChannelWeakPtr;
typedef CATCompositeTPtr<CATCompChannel>               CATCompChannelPtr;
typedef CATOnStackBorrowPtr<CATCompChannel>            CATCompChannelBorrowPtr;
typedef std::unordered_map<CATTraitRawInfo, CATCompChannelPtr, Hash<CATTraitRawInfo>>   CATCompChannels;

#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompChannel_H
