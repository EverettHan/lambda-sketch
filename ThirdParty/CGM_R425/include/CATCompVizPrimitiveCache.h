#ifndef CATCompVizPrimitiveCache_h_
#define CATCompVizPrimitiveCache_h_

#include "SGComposites.h"

// SGInfra (ProtectedInterfaces)
#include "CATSGUtil.h"
#include "CATSGComposite.h"
#include "CATCompositeTPtr.h"
#include "CATCompVizPrimitiveCacheBehavior.h"

#include <cstddef>

class CATVizPrimitive;
class CATVizVertexBuffer;

/**
* This composite is for holding CATVizPrimitive associated with a CATRep.
* It is particularly useful in the case of CAT3DCanonicalRep which generates CATVizPrimitive on-the-fly in CATRender,
* but the lifecycle of these CATVizPrimitive objects is by default limited to the CATRender draw pass.
* In some cases, we want to extend lifecycle of these generated CATVizPrimitive objects beyond a single draw pass.
*/
class ExportedBySGComposites CATCompVizPrimitiveCache : public CATSGComposite
{
public:
    virtual std::size_t Size() const = 0;
    virtual HRESULT Reserve(const std::size_t& iSize) = 0;

    virtual CATVizPrimitive* GetVizPrimitive(const std::size_t& iPos) const = 0;
    virtual HRESULT Find(CATVizPrimitive*& iVizPrimitive, std::size_t& oPos) const = 0;

    virtual HRESULT PushBack(CATVizPrimitive* iNewVizPrimitive) = 0;
    virtual HRESULT Insert(const std::size_t& iPos, CATVizPrimitive* iNewVizPrimitive) = 0;
    virtual HRESULT Erase(const std::size_t& iPos) = 0;
    virtual HRESULT Erase(CATVizPrimitive* iOldVizPrimitive) = 0;

    virtual CATVizVertexBuffer* GetVertexBuffer() const = 0;
    virtual HRESULT SetVertexBuffer(CATVizVertexBuffer* iNewVizVertexBuffer) = 0;

    virtual HRESULT Clear() = 0;
};

// {9869688D-38AE-411d-87A9-3B31122A9F62}
static const GUID GUID_CATCompVizPrimitiveCache =
{ 0x9869688d, 0x38ae, 0x411d, { 0x87, 0xa9, 0x3b, 0x31, 0x12, 0x2a, 0x9f, 0x62 } };

template<>
class CATTraitInfo<CATCompVizPrimitiveCache>
{
public:
    static const GUID& GetTraitGUID()
    {
        return GUID_CATCompVizPrimitiveCache;
    }
    static const int GetTraitTag()
    {
        return CATECompositeTagVizPrimitiveCache;
    }
    static const CATECompositionMode GetCompositeMode()
    {
        return CATECompositionModeExclusive;
    }
    static const CATTraitRawInfo GetRaw()
    {
        DefaultGetRawImplementation;
    }
};

typedef CATCompositeTPtr<CATCompVizPrimitiveCache>        CATCompVizPrimitiveCachePtr;
typedef CATCompositeTWeakPtr<CATCompVizPrimitiveCache>    CATCompVizPrimitiveCacheWeakPtr;
typedef CATOnStackBorrowPtr<CATCompVizPrimitiveCache>     CATCompVizPrimitiveCacheBorrowPtr;

/**
* Get the VizPrimitiveCache composite from the ring attached to the CATRep.
*     iCreateCompAndRing==false: oVizPrimitiveCache will be null if either the ring or the composite do not exist.
*     iCreateCompAndRing==true: oVizPrimitiveCache will never be null, because the ring and/or the composite will be created if they do not exist.
*/
HRESULT ExportedBySGComposites GetVizPrimitiveCacheFromRep(CATRep* iRep, CATCompVizPrimitiveCachePtr& oVizPrimitiveCache, bool iCreateCompAndRing = false);

/**
* Remove the VizPrimitiveCache composite from the ring attached to the CATRep (if any).
*/
HRESULT ExportedBySGComposites RemoveVizPrimitiveCacheFromRep(CATRep* iRep);

#endif // !CATCompVizPrimitiveCache_h_
