#ifndef CATSGSerializationContext_h_
#define CATSGSerializationContext_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATCompSerializationContext.h"
#include "CATSGComposite.h"
#include "CATSGCompositeHost.h"
#include "CATSGCompositesFactory.h"
#include "CATCompStream.h"
#include "CATCompChannel.h"
#include "CATUuid.h"
#include <unordered_map>

class CATSGSerializationVersion
{
public:
    static CATSG::uint32 major;
    static CATSG::uint32 inter;
    static CATSG::uint32 minor;
};

class ExportedBySGComposites CATSGSerializationContext : public CATSGCompositeHost1<CATCompSerializationContext, CATSGComposite>
{
private:
    typedef std::unordered_map<CATSGTableId, CATTraitRawInfo> CATChannelTraits;

public:
     static CATSGSerializationContext* Create(CATSGContext* iSGContext, CATSGCompositesFactoryPtr& iFactory, const CATSG::uint32& iNumberOfChannels);
     static CATSGSerializationContext* CreateForCGR(CATSGContext* iSGContext, CATSGCompositesFactoryPtr& iFactory, const CATSG::uint32& iNumberOfChannels);
     virtual ~CATSGSerializationContext();

     HRESULT            GetCurrentVersion(CATSG::uint32& oMajor, CATSG::uint32& oInter, CATSG::uint32& oMinor) const;

     HRESULT            SetStream(CATCompStreamPtr& iStream);
     HRESULT            BorrowStream(CATCompStreamBorrowPtr& oStream);

     HRESULT            GetFactory(CATSGCompositesFactoryPtr& oFactory);

     HRESULT            AddChannel(const CATTraitRawInfo& iTrait, CATCompChannelPtr& iChannel);
     HRESULT            RemoveChannel(const CATTraitRawInfo& iTrait);
     HRESULT            BorrowChannel(const CATTraitRawInfo& iTrait, CATCompChannelBorrowPtr& oChannel);
     HRESULT            RequestChannelId(const CATTraitRawInfo& iTrait, CATSGTableId& oChannelId);

     CATBoolean         IsStreamable(const CATTraitRawInfo& iTrait) const;

     HRESULT            SetPropagationPolicy(CATSGPropagationPolicy iPolicy, void* iPropagationRoot);
     HRESULT            GetPropagationPolicy(CATSGPropagationPolicy& oPolicy, void*& oPropagationRoot) const;

     HRESULT            StreamHeaderInfo();
     HRESULT            UnStreamHeaderInfo();
     /** Do not use this method unless you know what you are doing. */
     HRESULT            UnStreamHeaderInfo2();

     HRESULT            Stream(const CATSGCompositePtr& iComp, CATSGRef& oRef);
     HRESULT            UnStream(const CATSGRef& iRef, CATSGCompositePtr& oComp);

     HRESULT            FlushStream();
     HRESULT            FlushUnStream(CATSGComposites& oComposites);

     CATBoolean         IsANullRef(const CATSGRef& iRef);
     HRESULT            GetNullRef(CATSGRef& oRef);

protected:
     /** For internal use only. Do not call this method outside of the serialization classes. */
     HRESULT            Stream(const CATSGCompositePtr& iComp, const CATTraitRawInfo& iTrait, CATCompStreamPtr& iStream);
     /** For internal use only. Do not call this method outside of the serialization classes. */
     HRESULT            UnStream(CATSGCompositePtr& oComp, const CATTraitRawInfo& iTrait);

private:
     CATSGSerializationContext(const CATSG::uint32& iNumberOfChannels = 16);
     CATSGSerializationContext(CATSGContext& iSGContext, const CATSG::uint32& iNumberOfChannels = 16);

     HRESULT UnStreamChannelInformation();

     /** Return TRUE only if current version is (strictly) Less Than given version. */
     CATBoolean         CompareVersionLT(CATSG::uint32 iMajor, CATSG::uint32 iInter, CATSG::uint32 iMinor) const;
     /** Return TRUE only if current version is Less or Equal to given version. */
     CATBoolean         CompareVersionLE(CATSG::uint32 iMajor, CATSG::uint32 iInter, CATSG::uint32 iMinor) const;
     /** Return TRUE only if current version is (strictly) More Than given version. */
     CATBoolean         CompareVersionGT(CATSG::uint32 iMajor, CATSG::uint32 iInter, CATSG::uint32 iMinor) const;
     /** Return TRUE only if current version is More or Equal to given version. */
     CATBoolean         CompareVersionGE(CATSG::uint32 iMajor, CATSG::uint32 iInter, CATSG::uint32 iMinor) const;

private: // Undefined default methods
    CATSGSerializationContext(const CATSGSerializationContext&);
    CATSGSerializationContext& operator=(const CATSGSerializationContext&);

private:
    CATSG::uint32       _versionMajor;
    CATSG::uint32       _versionInter;
    CATSG::uint32       _versionMinor;
    CATUuid             _writeUUID;
    CATUuid             _readUUID;
    CATBoolean          _isReadUUIDSet;
    void*                   _propagationRoot;
    CATSGPropagationPolicy  _propagationPolicy;
    CATSGCompositesFactoryPtr _factory;
    CATCompStreamPtr    _stream;
    CATCompChannels     _channels;
    CATChannelTraits    _channelTraits;
    CATSGTableId        _nextChannelId;
    CATBoolean          _cgrStreaming;
    CATSGRef            _cachedNullRef;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATSGSerializationContext_h_
