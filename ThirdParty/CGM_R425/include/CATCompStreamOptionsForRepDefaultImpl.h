#ifndef CATCompStreamOptionsForRepDefaultImpl_h_
#define CATCompStreamOptionsForRepDefaultImpl_h_

#include "SGComposites.h"

// SGInfra (ProtectedInterfaces)
#include "CATSGUtil.h"
#include "CATCompStreamOptionsForRep.h"
#include "CATSGCompositeHost.h"

class ExportedBySGComposites CATCompStreamOptionsForRepDefaultImpl : public CATSGCompositeHost1NoListeners<CATCompStreamOptionsForRep, CATSGComposite>
{
public:
    CATCompStreamOptionsForRepDefaultImpl();
    virtual ~CATCompStreamOptionsForRepDefaultImpl();

    virtual HRESULT SetAllowStreamingInCGR(const bool iAllowStreamingInCGR);
    virtual const bool GetAllowStreamingInCGR() const;

private:
    bool _allowStreamingInCGR;
};

#endif // !CATCompStreamOptionsForRepDefaultImpl_h_
