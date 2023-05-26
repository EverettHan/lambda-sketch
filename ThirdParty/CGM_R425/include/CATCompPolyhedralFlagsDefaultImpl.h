#ifndef CATCompPolyhedralFlagsDefaultImpl_h_
#define CATCompPolyhedralFlagsDefaultImpl_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "SGComposites.h"
#include "CATCompPolyhedralFlags.h"
#include "CATSGComposite.h"
#include "CATSGCompositeHost.h"

class ExportedBySGComposites CATCompPolyhedralFlagsDefaultImpl : public CATSGCompositeHost1Dedicated<CATCompPolyhedralFlags, CATSGComposite>
{
public:
    CATCompPolyhedralFlagsDefaultImpl();
    virtual ~CATCompPolyhedralFlagsDefaultImpl();

    virtual HRESULT SetOwner(CATSGCompositeWeakPtr iOwner);
    virtual CATSGCompositeWeakPtr GetOwner() const;
    virtual CATSGContext* GetContext();
    virtual const CATSGContext* GetContext() const;

    virtual HRESULT GetRepOriginFlag(unsigned char& oRepOriginFlag) const;
    virtual HRESULT SetRepOriginFlag(unsigned char iRepOriginFlag);

    virtual HRESULT GetTopologyFlag(unsigned char& oTopologyFlag) const;
    virtual HRESULT SetTopologyFlag(unsigned char iTopologyFlag);

private:
    CATCompPolyhedralFlagsDefaultImpl(const CATCompPolyhedralFlagsDefaultImpl&);
    CATCompPolyhedralFlagsDefaultImpl& operator=(const CATCompPolyhedralFlagsDefaultImpl&);

private:
    CATSGCompositeWeakPtr           _owner;
    unsigned char                   _repOriginFlag;
    unsigned char                   _topologyFlag;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATCompPolyhedralFlagsDefaultImpl_h_
