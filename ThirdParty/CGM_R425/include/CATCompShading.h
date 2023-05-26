#ifndef CATCompShading_H
#define CATCompShading_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATSGComposite.h"
#include "CATCompositeTPtr.h"

class ExportedBySGComposites CATCompShading : public CATSGComposite
{
public:
    virtual HRESULT SetDiffuseColor(const CATSGColor& color) = 0;
    virtual HRESULT GetDiffuseColor(CATSGColor& color) const = 0;
};

// {7FE41D08-3089-4ED9-9E87-733CE5856D7E}
static const IID GUID_CATCompShadingTrait =
{ 0x7fe41d08, 0x3089, 0x4ed9, { 0x9e, 0x87, 0x73, 0x3c, 0xe5, 0x85, 0x6d, 0x7e } };

template<>
class CATTraitInfo<CATCompShading>
{
public:
	static const GUID& 			GetTraitGUID()
	{
		return GUID_CATCompShadingTrait;
	}
	static const int			GetTraitTag() {
	    return CATTraitTag(CATECompositeTagShading);
	}
	static const CATECompositionMode	GetCompositeMode()
	{
		return CATECompositionModeExclusive;
	}
	static const CATTraitRawInfo 		GetRaw()
	{
        DefaultGetRawImplementation;
	}
};

typedef CATCompositeTWeakPtr<CATCompShading>        CATCompShadingWeakPtr;
typedef CATCompositeTPtr<CATCompShading>            CATCompShadingPtr;
typedef CATOnStackBorrowPtr<CATCompShading>         CATCompShadingBorrowPtr;

#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompShading_H
