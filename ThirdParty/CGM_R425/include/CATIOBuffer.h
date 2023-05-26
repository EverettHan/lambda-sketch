#ifndef CATIOBuffer_H
#define CATIOBuffer_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATCompositeTPtr.h"
#include "CATSGComposite.h"

#include "CATMutex.h"

#include "VisGPGPUTypes.h" // for alignement directives (needed for atomic operaitions)
#include "CATIOAtomics.h"

class ExportedBySGComposites CATIOBuffer : public CATSGComposite
{
public:
    virtual HRESULT Reserve(const unsigned int iSize) = 0;

    virtual HRESULT SetSize(const unsigned int iSize) = 0;
    virtual unsigned int GetSize() = 0;
    virtual void *AsVoid() = 0;

    virtual HRESULT SetInPlace(void *iBuffer, const unsigned int iBufferSize) = 0;
    virtual HRESULT Append(const void *iBuffer, const unsigned int iBufferSize) = 0;
    /**
     * If not supported by your implementation (network stream...) should return E_NOTIMPL.
     */
    virtual HRESULT RemoveSlice(const unsigned iAt, const unsigned iSize) = 0;
    virtual HRESULT Dump(void *ioBuffer, const unsigned int iBufferSize, unsigned int &oDumpedSize) = 0;
};

// {CBEBAC5E-1312-4B35-A8D3-62A8B4A299E6}
static const GUID GUID_CATIOBufferTrait =
{ 0xcbebac5e, 0x1312, 0x4b35, { 0xa8, 0xd3, 0x62, 0xa8, 0xb4, 0xa2, 0x99, 0xe6 } };

template<>
class CATTraitInfo<CATIOBuffer>
{
public:
    static const GUID &GetTraitGUID()
    {
        return GUID_CATIOBufferTrait;
    }
    static const int GetTraitTag() { return CATTraitTag(-1); }
    static const CATECompositionMode GetCompositeMode()
    {
        return CATECompositionModeNOWAY;
    }
    static const CATTraitRawInfo GetRaw()
    {
        DefaultGetRawImplementation;
    }
};

typedef CATCompositeTPtr<CATIOBuffer>            CATIOBufferPtr;


#endif // SG_COMPOSITES_MULTIOS
#endif // CATIOBuffer_H
