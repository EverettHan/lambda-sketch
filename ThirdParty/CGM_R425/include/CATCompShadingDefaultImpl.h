#ifndef CATCompShadingDefaultImpl_h_
#define CATCompShadingDefaultImpl_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATCompShading.h"
#include "CATSGComposite.h"
#include "CATSGCompositeHost.h"

class ExportedBySGComposites CATCompShadingDefaultImpl : public CATSGCompositeHost1<CATCompShading, CATSGComposite>
{
 public:
     CATCompShadingDefaultImpl();
     virtual ~CATCompShadingDefaultImpl();

     HRESULT   SetDiffuseColor(const CATSGColor& color);
     HRESULT   GetDiffuseColor(CATSGColor& color) const;

private:
    CATSGColor            _diffuseColor;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATCompShadingDefaultImpl_h_
