#ifndef CATCompPickable_H
#define CATCompPickable_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

#include "CATPickingRender.h"

#include "CATSGManager.h"
#include "CATCompositeTPtr.h"
#include "CATCompositePtrList.h"
#include "CATSGComposite.h"

class CATRep;

class ExportedBySGComposites CATCompPickable : public CATSGComposite
{
public:
	virtual HRESULT 	Pick(CATPickingRender& iRender, int iInside) = 0;
};

// {44E78CE7-E0DD-4EF4-9D06-DBF9C4A12780}
static const GUID GUID_CATCompPickableTrait =
{ 0x9059de7b, 0xeb9e, 0x463e, { 0x8d, 0x26, 0xd7, 0xb3, 0xd7, 0x99, 0xf7, 0xbd } };

template<>
class CATTraitInfo<CATCompPickable>
{
public:
	static const GUID& 				GetTraitGUID()
	{
		return GUID_CATCompPickableTrait;
	}
	static const int					GetTraitTag() { return CATTraitTag(CATECompositeTagPickable); }
	static const CATECompositionMode	GetCompositeMode()
	{
		return CATECompositionModeExclusive;
	}
	static const CATTraitRawInfo 		GetRaw()
	{
        DefaultGetRawImplementation;
	}
};

typedef CATCompositeTPtr<CATCompPickable>		CATCompPickablePtr;
typedef CATOnStackBorrowPtr<CATCompPickable>	CATCompPickableBorrowPtr;

#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompPickable_H
