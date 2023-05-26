#ifndef CATSGCompositesFactory_H
#define CATSGCompositesFactory_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATSGComposite.h"
#include "CATCompositeTPtr.h"
#include "CATCompSerializationContext.h"
#include "CATCompSerializationSurrogate.h"
#include "CATCompStream.h"

class CATIOBuffer;

/**
 * The role of the CATSGCompositesFactory is to serve as a central place to allocate
 * composites or composites list per context !
 */
class ExportedBySGComposites CATSGCompositesFactory : public CATSGComposite
{
public:
    virtual CATTraitRawInfo         GetTraitByGUID(const GUID& iTraitGuid) const = 0;
    virtual CATTraitRawInfo         GetTraitByTag(const CATTraitTag& iTraitTag) const = 0;

	/**
	 * Will provide the default known implementation of the specified Trait.
	 * If there is no such 'known' implementation you will be returned an invalid CATSGCompositePtr
	 * so you should check the validity of the returned compositePtr.
	 * At the moment this method is only useful for a few composite implementation that we want
	 * to keep within VisualizationFoundation (ex. CATCompRenderable implementations, NRE team
	 * request and simplifies things at this point).
	 */
	virtual CATSGCompositePtr 	    GetComp(const CATTraitRawInfo& iTraitRawInfo, CATSGContext* iContext = NULL) const = 0;

    /**
     * See GetComp.
     */
    virtual CATSGCompositePtr       GetCompByGUID(const GUID& iTraitGuid, CATSGContext* iContext = NULL) const = 0;

    /**
     * See GetComp.
     */
    virtual CATSGCompositePtr       GetCompByTag(const CATTraitTag& iTraitTag, CATSGContext* iContext = NULL) const = 0;

	/**
	 * Will return a pointer to a newly allocated CATSGComposites.
	 */
	virtual CATSGCompositesList* 	GetCompositesList() const = 0;

	/**
	 * When you are done with a CATSGComposites that you have got through GetCompositesArray
	 * method you should really pass it to below method. You should not delete it yourself
	 * even if you are under the impression things are working all right.
	 */
	virtual HRESULT				    ReturnCompositesListToPool(CATSGCompositesList*& iCompositesArray) const = 0;

    /**
	 * Will return a pointer to a newly allocated CATIOBuffer.
	 */
    virtual CATIOBuffer*            GetBuffer() const = 0;

    virtual HRESULT GetSerializationContext(CATCompStreamPtr& iStream, CATCompSerializationContextPtr& oCtx) = 0;
    virtual HRESULT GetSerializationContextForCGR(CATCompStreamPtr& iStream, CATCompSerializationContextPtr& oCtx) = 0;
    virtual CATCompSerializationSurrogatePtr GetSerializationSurrogateByGUID(const GUID& iTraitGuid) const = 0;
};

// {5B1112E4-D43C-44E1-B5C1-6BD896E14211}
const GUID GUID_CATSGCompositesFactoryTrait =
{ 0x5b1112e4, 0xd43c, 0x44e1, { 0xb5, 0xc1, 0x6b, 0xd8, 0x96, 0xe1, 0x42, 0x11 } };


/**
 * See documentation of unspecialized CATTraitInfo template class for more information
 * on why this specialization is needed / useful.
 */
template<>
class CATTraitInfo<CATSGCompositesFactory>
{
public:
	static const GUID& 					GetTraitGUID()
	{
		return GUID_CATSGCompositesFactoryTrait;
	}
	static const int					GetTraitTag() { return CATTraitTag(-1); }
	static const CATECompositionMode	GetCompositeMode()
	{
		return CATECompositionModeNOWAY;
	}
	static const CATTraitRawInfo 		GetRaw()
	{
        DefaultGetRawImplementation;
	}
};

typedef CATCompositeTPtr<CATSGCompositesFactory>	CATSGCompositesFactoryPtr;

#endif // SG_COMPOSITES_MULTIOS
#endif // CATSGCompositesFactory_H
