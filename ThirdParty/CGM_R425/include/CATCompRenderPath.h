#ifndef CATCompRenderPath_H
#define CATCompRenderPath_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATBaseUnknown.h"

#include "CATCompositeTPtr.h"
#include "CATCompositePtrList.h"
#include "CATSGComposite.h"
#include "CATRepRender.h"

class ExportedBySGComposites CATCompRenderPath : public CATSGComposite
{
public:
	virtual HRESULT 	Render(CATRepRender& iRender, int iInside, CATRepPath& path) = 0;
};


// {B5001DBB-EE45-4D16-83E6-7ACAF1B9A17F}
static const GUID GUID_CATCompRenderPathTrait =
{ 0xb5001dbb, 0xee45, 0x4d16, { 0x83, 0xe6, 0x7a, 0xca, 0xf1, 0xb9, 0xa1, 0x7f } };

template<>
class CATTraitInfo<CATCompRenderPath>
{
public:
	static const GUID& 				GetTraitGUID()
	{
		return GUID_CATCompRenderPathTrait;
	}
	static const int					GetTraitTag()
	{
		return CATECompositeTagRenderPath;
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

typedef CATCompositeTPtr<CATCompRenderPath>		CATCompRenderPathPtr;
typedef CATOnStackBorrowPtr<CATCompRenderPath>	CATCompRenderPathBorrowPtr;

#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompRenderPath_H
