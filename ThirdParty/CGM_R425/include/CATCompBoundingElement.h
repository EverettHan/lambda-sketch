#ifndef CATCompBoundingElement_H
#define CATCompBoundingElement_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATBaseUnknown.h"

#include "CATCompositeTPtr.h"
#include "CATCompositePtrList.h"
#include "CATSGComposite.h"

#include "CATSGGenVec3.h"
#include "CATAABox.h"

class CATRepRender;

class ExportedBySGComposites CATCompBoundingElement : public CATSGComposite
{
public:
	virtual HRESULT 	          Render(CATRepRender& iRender, int iInside) = 0;
    virtual CATSG::CATSGVec3      GetCenter() const = 0;
    virtual float                 GetRadius() const = 0;
    virtual HRESULT               SetBoundingElement(const CATSG::CATSGVec3& center, float radius) = 0;
    virtual HRESULT               SetBoundingBox(const CATAABox& box) = 0;
    virtual CAT3DBoundingSphere   GetBoundingElement() const = 0;
    virtual CATAABox              GetBoundingBox() const = 0;

#ifdef _EMSCRIPTEN_TESTS
    virtual bool                  GetValidity() const = 0;
    virtual void                  SetValidity(bool iVal) = 0;
#endif//_EMSCRIPTEN_TESTS
};

// {2C6C9A6F-F39E-493C-AFC6-9ABA176B704F}
static const GUID GUID_CATCompBoundingElementTrait =
{ 0x2c6c9a6f, 0xf39e, 0x493c, { 0xaf, 0xc6, 0x9a, 0xba, 0x17, 0x6b, 0x70, 0x4f } };

template<>
class CATTraitInfo<CATCompBoundingElement>
{
public:
	static const GUID& 				GetTraitGUID()
	{
		return GUID_CATCompBoundingElementTrait;
	}
	static const int					GetTraitTag() { return CATTraitTag(CATECompositeTagBoundingElement); }
	static const CATECompositionMode	GetCompositeMode()
	{
		return CATECompositionModeExclusive;
	}
	static const CATTraitRawInfo 		GetRaw()
	{
        DefaultGetRawImplementation;
	}
};

typedef CATCompositeTPtr<CATCompBoundingElement>		CATCompBoundingElementPtr;
typedef CATOnStackBorrowPtr<CATCompBoundingElement>	CATCompBoundingElementBorrowPtr;

#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompBoundingElement_H
