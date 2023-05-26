#ifndef CATCompTransform_H
#define CATCompTransform_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATSGComposite.h"
#include "CATSGCompositeHost.h"
#include "CATCompositeTPtr.h"

#include "CATSGGenVec3.h"

namespace CATSG
{
    class CATSGTransformMatrix44;
};

class ExportedBySGComposites CATCompTransform : public CATSGComposite
{
public:
    #ifndef _EMSCRIPTEN_TESTS
    virtual HRESULT SetFromCAT4x4Mat(const CAT4x4Matrix& iMat) = 0;
    #endif
    virtual HRESULT SetFromMatrix44(const CATSG::CATSGTransformMatrix44& iMat) = 0;
    virtual HRESULT GetAsMatrix44(CATSG::CATSGTransformMatrix44& oMat) const = 0;

    virtual void Translate(const CATSG::CATSGDVector& iTranslation) = 0;
    virtual void Rotate(const CATSG::CATSGDVector& iAxis, double iRadAngle) = 0;
    virtual void SetScale(double iScale) = 0;
    virtual double GetScale() const = 0;

    virtual void SetPosition(const CATSG::CATSGDPoint& iPosition) = 0;
    virtual const CATSG::CATSGDPoint& GetPosition() const = 0;
};

// {E02F0D30-7430-4A88-A933-68754B04B6CB}
static const IID GUID_CATCompTransformTrait =
{ 0xe02f0d30, 0x7430, 0x4a88, { 0xa9, 0x33, 0x68, 0x75, 0x4b, 0x4, 0xb6, 0xcb } };

template<>
class CATTraitInfo<CATCompTransform>
{
public:
    static const GUID& 			GetTraitGUID()
    {
        return GUID_CATCompTransformTrait;
    }
    static const int			GetTraitTag() {
        return CATTraitTag(CATECompositeTagTransform);
    }
    static const CATECompositionMode	GetCompositeMode()
    {
        return CATECompositionModeExclusive;
    }
    static const CATTraitRawInfo 	GetRaw()
    {
        DefaultGetRawImplementation;
    }
};

typedef CATCompositeTWeakPtr<CATCompTransform>  CATCompTransformWeakPtr;
typedef CATCompositeTPtr<CATCompTransform>      CATCompTransformPtr;
typedef CATOnStackBorrowPtr<CATCompTransform>   CATCompTransformBorrowPtr;

#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompTransform_H
