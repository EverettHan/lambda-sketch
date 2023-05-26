#ifndef CATCompCullable_H
#define CATCompCullable_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATBaseUnknown.h"
#include "CATRender.h"
#include "CATCullingRender.h"

#include "CATSGManager.h"
#include "CATCompositeTPtr.h"
#include "CATCompositePtrList.h"
#include "CATSGComposite.h"

class CATRep;

class CATCompactingLODRender;

class ExportedBySGComposites CATCompCullable : public CATSGComposite
{
public:

	virtual HRESULT 	Cull(CATCullingRender& iRender, int iInside) = 0;
	virtual HRESULT 	CullPath(CATCullingRender& iRender, int iInside, CATRepPath& iRepPath) = 0;

    virtual HRESULT 	Cull(CATCompactingLODRender& iRender, int iInside) = 0;

    virtual CATSG::uint32 GetFlag() = 0;
    virtual void SetFlag(CATSG::uint32 iFlag) = 0;
};

// {44E78CE7-E0DD-4EF4-9D06-DBF9C4A12780}
static const GUID GUID_CATCompCullableTrait =
{ 0x1ff08409, 0x5b6, 0x43c7, { 0xb7, 0x2e, 0x25, 0x2, 0x1e, 0x18, 0xef, 0xdc } };

template<>
class CATTraitInfo<CATCompCullable>
{
public:
	static const GUID& 				GetTraitGUID()
	{
		return GUID_CATCompCullableTrait;
	}
	static const int					GetTraitTag() { return CATTraitTag(CATECompositeTagCullable); }
	static const CATECompositionMode	GetCompositeMode()
	{
		return CATECompositionModeExclusive;
	}
	static const CATTraitRawInfo 		GetRaw()
	{
        DefaultGetRawImplementation;
	}
};

typedef CATCompositeTPtr<CATCompCullable>		CATCompCullablePtr;
typedef CATOnStackBorrowPtr<CATCompCullable>	CATCompCullableBorrowPtr;

#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompCullable_H
