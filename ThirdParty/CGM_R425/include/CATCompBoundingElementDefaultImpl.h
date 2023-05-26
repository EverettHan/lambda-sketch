#ifndef CATCompBoundingElementDefaultImpl_h_
#define CATCompBoundingElementDefaultImpl_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATCompBoundingElement.h"
#include "CATSGComposite.h"
#include "CATSGCompositeHost.h"
#include "CATSGCompositeRing.h"
#include "CATSGGenVec3.h"

class ExportedBySGComposites CATCompBoundingElementDefaultImpl : public CATSGCompositeHost1<CATCompBoundingElement, CATSGComposite>
{
 public:
    virtual ~CATCompBoundingElementDefaultImpl();

    CATCompBoundingElementDefaultImpl(const CATAABox& box);
    CATCompBoundingElementDefaultImpl(const CATSG::CATSGVec3& center, float radius);
    CATCompBoundingElementDefaultImpl();

	HRESULT 	        Render(CATRepRender& iRender, int iInside);
    HRESULT             SetBoundingElement(const CATSG::CATSGVec3& center, float radius);
    HRESULT             SetBoundingBox(const CATAABox& box);
    CAT3DBoundingSphere GetBoundingElement() const;
    CATAABox            GetBoundingBox() const;

    CATSG::CATSGVec3    GetCenter() const;
    float               GetRadius() const;

#ifdef _EMSCRIPTEN_TESTS
    bool                GetValidity() const;
    void                SetValidity(bool iVal);
#endif//_EMSCRIPTEN_TESTS

 protected:
    CATAABox _box;
    bool _validity;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // !CATCompBoundingElementDefaultImpl_h_
