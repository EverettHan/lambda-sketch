#ifndef CAT3DMirrorRep_H
#define CAT3DMirrorRep_H

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "CAT3DRep.h"
#include "SGInfra.h"
#include "CATMathPointf.h"
#include "CATMathVectorf.h"
#include "list.h"

class CAT3DMirrorGP;
class CATRepPath;
class ExportedBySGInfra CAT3DMirrorRep : public CAT3DRep
{
    CATDeclareClass;

public:
    static CAT3DMirrorRep* CreateRep(
        const float  iVertices[],
        const int    iVerticesArraySize,
        const float  iNormals[],
        const int    iTriangleIndice[],
        const int    iNbTriangle,
        const int    iTriangleStripIndice[],
        const int    iNbTriangleStrip,
        const int    iNbVertexPerTriangleStrip[],
        const int    iTriangleFanIndice[],
        const int    iNbTriangleFan,
        const int    iNbVertexPerTriangleFan[]
        );

protected:

    /** @deprecated R417 : Use CreateRep instead.*/
    CAT3DMirrorRep(
        const float  iVertices[],
        const int    iVerticesArraySize,
        const float  iNormals[],
        const int    iTriangleIndice[],
        const int    iNbTriangle,
        const int    iTriangleStripIndice[],
        const int    iNbTriangleStrip,
        const int    iNbVertexPerTriangleStrip[],
        const int    iTriangleFanIndice[],
        const int    iNbTriangleFan,
        const int    iNbVertexPerTriangleFan[]
        );

    virtual ~CAT3DMirrorRep();

public:
    void DefineMirroredRep(const CATRepPath& iMirroredRepPath);
    void AddMirroredRep(const CATRepPath& iMirroredRepPath);
    void EmptyMirroredRep();
    inline CAT3DRep* GetMirroredReps();

    void SetBlurring(float iLevel, unsigned int iNumPass = 1);    
    float GetBlurringLevel();
    unsigned int GetBlurringNumPass();

    // draw
  // AZX: (A2X migration) Making draw functions final 
    virtual void DrawShading(CATRender&, int) override final;
    virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) override final;
    virtual void Draw(CATRender& iRender, int iInside) override final;
    virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;
    virtual void UpdateTextureCoordinates(CATMappingOperator* iOperator = NULL);

    inline void GetMirrorCoord(CATMathPointf& oCenter, CATMathVectorf& oNormal);
    inline unsigned int IsLinkToGP(const CAT3DMirrorGP* iGP);

protected:
  const virtual vDrawInformation* GetDrawInformation();

private :
    CATMathPointf       _center;
    CATMathVectorf      _normal;

    CAT3DMirrorGP*      _gp;

    CAT3DRep*           _mirroredReps;
};

inline void CAT3DMirrorRep::GetMirrorCoord(CATMathPointf& oCenter, CATMathVectorf& oNormal)
{
    oCenter = _center;
    oNormal = _normal;
}

inline unsigned int CAT3DMirrorRep::IsLinkToGP(const CAT3DMirrorGP* iGP)
{
    return (iGP ? iGP==_gp : 0);
}

inline CAT3DRep* CAT3DMirrorRep::GetMirroredReps()
{
    return _mirroredReps;
}



#endif
