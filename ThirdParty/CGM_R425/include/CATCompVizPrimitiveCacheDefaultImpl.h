#ifndef CATCompVizPrimitiveCacheDefaultImpl_h_
#define CATCompVizPrimitiveCacheDefaultImpl_h_

#include "SGComposites.h"

// SGInfra (ProtectedInterfaces)
#include "CATSGUtil.h"
#include "CATSGComposite.h"
#include "CATSGCompositeHost.h"
#include "CATCompVizPrimitiveCache.h"
#include "CATVizPrimitive.h"
#include "CATVizVertexBuffer.h"

#include <vector>
#include <cstddef>

class ExportedBySGComposites CATCompVizPrimitiveCacheDefaultImpl : public CATSGCompositeHost1NoListeners<CATCompVizPrimitiveCache, CATSGComposite>
{
public:
    CATCompVizPrimitiveCacheDefaultImpl();
    virtual ~CATCompVizPrimitiveCacheDefaultImpl();

    virtual std::size_t Size() const;
    virtual HRESULT Reserve(const std::size_t& iSize);

    virtual CATVizPrimitive* GetVizPrimitive(const std::size_t& iPos) const;
    virtual HRESULT Find(CATVizPrimitive*& iVizPrimitive, std::size_t& oPos) const;

    virtual HRESULT PushBack(CATVizPrimitive* iNewVizPrimitive);
    virtual HRESULT Insert(const std::size_t& iPos, CATVizPrimitive* iNewVizPrimitive);
    virtual HRESULT Erase(const std::size_t& iPos);
    virtual HRESULT Erase(CATVizPrimitive* iOldVizPrimitive);

    virtual CATVizVertexBuffer* GetVertexBuffer() const;
    virtual HRESULT SetVertexBuffer(CATVizVertexBuffer* iNewVizVertexBuffer);

    virtual HRESULT Clear();

private:
    CATVizVertexBuffer*             _vertexBuffer;
    std::vector<CATVizPrimitive*>   _vizPrimitives;
};

#endif // !CATCompVizPrimitiveCacheDefaultImpl_h_
