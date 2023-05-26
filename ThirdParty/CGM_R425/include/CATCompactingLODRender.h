#ifndef CATCompactingLODRender_H
#define CATCompactingLODRender_H
//
// Copyright Dassault Systemes 2014
//------------------------------------------------------------------------------
// Abstract :  Traverse the graph and compact entities that don't need to be 
// fully tesselated all the time. At the moment will only compact the cylinders
// that can have two different states, using a canonic or having the full blown
// tesselation.
//
//------------------------------------------------------------------------------
// Usage :
//
//------------------------------------------------------------------------------
// Main methods :
//
//------------------------------------------------------------------------------
// Inheritance : CATCompactingRender
//                  CATRepRender
//                     CATRender
//
//------------------------------------------------------------------------------
#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATDataType.h"
#include "SGComposites.h"
#include "CATRepRender.h"
#include "CATGraphicAttributeSet.h"
#include "CATMathPointf.h"
#include "CATMathPoint2Df.h"
#include "CATGraphicMaterial.h"
//#include "CATSupport.h"

class CAT4x4Matrix;
class CAT3x3Matrix;

class ExportedBySGComposites CATCompactingLODRender : public CATRepRender
{
  	CATDeclareClass_Deprec;
  public :

    // Construction and destruction methods:
    // -------------------------------------

    CATCompactingLODRender(const CATSupport& support);
    CATCompactingLODRender(const CATCompactingLODRender& iOther);
    virtual ~CATCompactingLODRender();

    virtual void BeginDraw(CATViewpoint&);
    virtual void EndDraw(CATViewpoint&);

    virtual void PushReference();
    virtual void PopReference();

    virtual CATRender* PushMatrix(CAT4x4Matrix&);
    virtual CATRender* PushMatrix(CAT3x3Matrix&);
    virtual void PopMatrix(CATRender*);

#ifdef _EMSCRIPTEN_TESTS
    //without this, the other version of PushMatrix/PopMatrix in CATCompactingLODRender hides the version in CATRepRenderEmsc
    virtual HRESULT PushMatrix(CATSG::CATSGTransformMatrix44& iModelMatrix);
    virtual HRESULT PopMatrix();
#endif//_EMSCRIPTEN_TESTS

    virtual int DrawRepresentation(CATRep&, int, void*&);

    virtual int IsDrawable(const CATGraphicAttributeSet&, const CAT3DBoundingSphere&, const CATRep&, CATGraphicMaterial*);
    virtual int IsToSmall(const CAT3DBoundingSphere&);
    virtual int IsInside(const CAT3DBoundingSphere&);
    virtual int IsOutside(const float, const float, const float);
    virtual int IsSeen(const float*, const float*);

    CATBoolean AllowForceDownload();
    void IncrAllowForceDownload();
    void ResetForceDownloadCount();
private:
    CATUINT32               _forceDownloadCount;
};

#endif // SG_COMPOSITES_MULTIOS
#endif
