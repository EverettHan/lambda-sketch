#ifndef CATCompAnim_H
#define CATCompAnim_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "SGComposites.h"

#include "CATSGComposite.h"
//#include "CATVisuAnimation.h"

#include "CATCompositeTPtr.h"
#include "CATCompositePtrList.h"

class CATViewer;
class CATVisuAnimation;

class ExportedBySGComposites CATCompAnim : public CATSGComposite
{
public:
	virtual CATVisuAnimation* GetAnimation(CATViewer* ipViewer) = 0;
    virtual HRESULT StartAnimation(CATViewer* ipViewer) = 0;
    virtual HRESULT StopAnimation(CATViewer* ipViewer) = 0;
	virtual std::uint64_t GetNbViewers() const = 0;
};

static const GUID GUID_CATCompAnimTrait =
{ 0x9a5554fd, 0xfe25, 0x4eaf, { 0x88, 0xf3, 0xe8, 0x67, 0x47, 0x00, 0x9b, 0xde } };

template<>
class CATTraitInfo<CATCompAnim>
{
public:
	static const GUID& 				GetTraitGUID()
	{
		return GUID_CATCompAnimTrait;
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

typedef CATCompositeTPtr<CATCompAnim>		CATCompAnimPtr;
typedef CATCompositeTWeakPtr<CATCompAnim>	CATCompAnimWeakPtr;

#endif // SG_COMPOSITES_MULTIOS
#endif
