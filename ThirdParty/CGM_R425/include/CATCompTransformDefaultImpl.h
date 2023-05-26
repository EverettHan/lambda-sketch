#ifndef CATCompTransformDefaultImpl_h_
#define CATCompTransformDefaultImpl_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATCompTransform.h"
#include "CATSGComposite.h"
#include "CATSGCompositeHost.h"
#include "CATSGTransformMatrix44.h"

#ifndef _EMSCRIPTEN_TESTS
class CAT4x4Matrix;
#endif

class ExportedBySGComposites CATCompTransformDefaultImpl : public CATSGCompositeHost1<CATCompTransform, CATSGComposite>
{
public:
    #ifndef _EMSCRIPTEN_TESTS
    HRESULT SetFromCAT4x4Mat(const CAT4x4Matrix& iMat);
    #endif
    HRESULT SetFromMatrix44(const CATSG::CATSGTransformMatrix44& iMat);
    HRESULT GetAsMatrix44(CATSG::CATSGTransformMatrix44& oMat) const;

    void Translate(const CATSG::CATSGDVector& iTranslation);
    void Rotate(const CATSG::CATSGDVector& iAxis, double iRadAngle);
    void SetScale(double iScale);
    double GetScale() const;

    void SetPosition(const CATSG::CATSGDPoint& iPosition);
    const CATSG::CATSGDPoint& GetPosition() const;

protected:
    CATSG::CATSGTransformMatrix44    _mat;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATCompTransformDefaultImpl_h_
