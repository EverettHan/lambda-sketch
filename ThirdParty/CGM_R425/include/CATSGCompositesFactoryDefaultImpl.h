#ifndef CATSGCompositesFactoryDefaultImpl_h_
#define CATSGCompositesFactoryDefaultImpl_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATSGCompositesFactory.h"
#include "CATSGComposite.h"
#include "CATSGCompositeHost.h"
#include "CATCompSerializationContext.h"

class ExportedBySGComposites CATSGCompositesFactoryDefaultImpl : public CATSGCompositeHost1<CATSGCompositesFactory, CATSGComposite>
{
public:
    CATTraitRawInfo         GetTraitByGUID(const GUID& iTraitGuid) const;
    CATTraitRawInfo         GetTraitByTag(const CATTraitTag& iTraitTag) const;

	CATSGCompositePtr 	    GetComp(const CATTraitRawInfo& iTraitRawInfo, CATSGContext* iContext = NULL) const;
    CATSGCompositePtr       GetCompByGUID(const GUID& iTraitGuid, CATSGContext* iContext = NULL) const;
    CATSGCompositePtr       GetCompByTag(const CATTraitTag& iTraitTag, CATSGContext* iContext = NULL) const;

	CATSGCompositesList* 	GetCompositesList() const;
	HRESULT				    ReturnCompositesListToPool(CATSGCompositesList*& iCompositesArray) const;

    CATIOBuffer*            GetBuffer() const;

    HRESULT                 GetSerializationContext(CATCompStreamPtr& iStream, CATCompSerializationContextPtr& oCtx);
    HRESULT                 GetSerializationContextForCGR(CATCompStreamPtr& iStream, CATCompSerializationContextPtr& oCtx);

    CATCompSerializationSurrogatePtr GetSerializationSurrogateByGUID(const GUID& iTraitGuid) const;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATSGCompositesFactoryDefaultImpl_h_
