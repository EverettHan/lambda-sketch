#ifndef CATCompClassicRep_H
#define CATCompClassicRep_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATSGComposite.h"
#include "CATCompositeTPtr.h"

class CATRep;
class CAT3DBoundingSphere;

class ExportedBySGComposites CATCompClassicRep : public CATSGComposite
{
public:
	virtual HRESULT       SetRep(CATRep* iRep, CATBoolean iRelease = TRUE) = 0;
	virtual CATRep*       GetRep() = 0;
	virtual const CATRep* GetRep() const = 0;

	virtual HRESULT 	GetBoundingSphere(CAT3DBoundingSphere& oBoundingSphere) const = 0;
};

// {E99CC910-09E4-45F4-9CC6-FB4C175E5AF7}
static const IID GUID_CATCompClassicRepTrait =
{ 0xe99cc910, 0x9e4, 0x45f4, { 0x9c, 0xc6, 0xfb, 0x4c, 0x17, 0x5e, 0x5a, 0xf7 } };

template<>
class CATTraitInfo<CATCompClassicRep>
{
public:
	static const GUID& 				GetTraitGUID()
	{
		return GUID_CATCompClassicRepTrait;
	}
	static const int					GetTraitTag() { return CATTraitTag(CATECompositeTagClassicRep); }
	static const CATECompositionMode	GetCompositeMode()
	{
		return CATECompositionModeExclusive;
	}
	static const CATTraitRawInfo 		GetRaw()
	{
		DefaultGetRawImplementation;
	}
};

typedef CATCompositeTWeakPtr<CATCompClassicRep>     CATCompClassicRepWeakPtr;
typedef CATCompositeTPtr<CATCompClassicRep>         CATCompClassicRepPtr;
typedef CATOnStackBorrowPtr<CATCompClassicRep>      CATCompClassicRepBorrowPtr;

#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompClassicRep_H
