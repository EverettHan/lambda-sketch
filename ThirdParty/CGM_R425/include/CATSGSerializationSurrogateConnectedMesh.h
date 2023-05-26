/**
 * COPYRIGHT Dassault Systemes 2016/05/19
 * ==================================================================
 *
 * CATSGSerializationSurrogateConnectedMesh.h
 * Definition of the CATSGSerializationSurrogateConnectedMesh class
 *
 * ===================================================================
 * 2016/05/19 Creation
 */

#ifndef CATSGSerializationSurrogateConnectedMesh_h_
#define CATSGSerializationSurrogateConnectedMesh_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATSGCompositesFactoryDefaultImpl.h"
#include "CATCompSerializationSurrogate.h"


// {7925CAA1-CA4A-4C80-9FB4-8F2DC03833A7}
static const GUID GUID_CATSGSerializationSurrogateConnectedMeshVersion =
{ 0x7925caa1, 0xca4a, 0x4c80, { 0x9f, 0xb4, 0x8f, 0x2d, 0xc0, 0x38, 0x33, 0xa7 } };



DeclareSurrogateImplementation(ConnectedMesh, GUID_CATSGSerializationSurrogateConnectedMeshVersion)



class CATSGCompressFactory : public CATSGCompositesFactoryDefaultImpl
{
    CATCompSerializationSurrogatePtr GetSerializationSurrogateByGUID(const GUID& iTraitGuid) const
    {
        if (CATCmpGuid(&iTraitGuid, &GUID_CATSGSerializationSurrogateConnectedMeshVersion))
            return new CATSGSerializationSurrogateConnectedMesh();
        return CATSGCompositesFactoryDefaultImpl::GetSerializationSurrogateByGUID(iTraitGuid);
    }
};


#if 0
class CATSGSerializationSurrogateConnectedMesh : public CATSGCompositeHost1<CATCompSerializationSurrogate, CATSGComposite>
{
public:
    CATSGSerializationSurrogateConnectedMesh();
    virtual ~CATSGSerializationSurrogateConnectedMesh();
    CATSGSurrogateVersion   GetVersion() const;
    HRESULT                 SetVersion(CATSGSurrogateVersion iVersion);
    CATTraitRawInfo    GetSupportedTrait() const;
    HRESULT            PreStream(CATCompSerializationContextWeakPtr& iSerializationCtx, const CATSGCompositePtr& iCompositeToSerialize, const CATSGComposite*& oAddr);
    HRESULT            Stream(CATCompSerializationContextWeakPtr& iSerializationCtx, CATCompStreamPtr& iStream, const CATSGCompositePtr& iCompositeToSerialize);
    HRESULT            UnStream(CATCompSerializationContextWeakPtr& iSerializationCtx, CATCompStreamPtr& iStream, CATSGCompositePtr& ioDeserializedComposite);
    virtual const GUID&                    GetGUID() const;
private:
    CATSGSurrogateVersion   _version;
};
#endif

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATSGSerializationSurrogateConnectedMesh_h_
