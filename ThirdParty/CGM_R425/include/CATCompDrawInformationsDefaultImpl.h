#ifndef CATCompDrawInformationsDefaultImpl_h_
#define CATCompDrawInformationsDefaultImpl_h_

#if 0

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATCompDrawInformations.h"
#include "CATSGComposite.h"
#include "CATSGCompositeHost.h"

class ExportedBySGComposites CATCompDrawInformationsDefaultImpl : public CATSGCompositeHost1<CATCompDrawInformations, CATSGComposite>
{
 public:
    CATCompDrawInformationsDefaultImpl();
    virtual ~CATCompDrawInformationsDefaultImpl();

    HRESULT             SetDefault(const vDrawInformations::Iterator& iDefault);
    vDrawInformation*   GetVDrawInformation();

    HRESULT             AddVDrawInformation(vDrawInformation* iVDrawInfo);
    HRESULT             RemoveVDrawInformation(const vDrawInformations::Iterator& iVDrawInfoToRemove);
    
    vDrawInformations&  GetVDrawInformations();
 private:
    vDrawInformations           _vDrawInformations;
    vDrawInformations::Iterator _currentDefault;
};
#endif
#endif // SG_COMPOSITES_MULTIOS
#endif // !CATCompDrawInformationsDefaultImpl_h_
