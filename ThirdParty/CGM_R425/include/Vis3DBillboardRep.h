#ifndef Vis3DBillboardRep_h
#define Vis3DBillboardRep_h

// COPYRIGHT DASSAULT SYSTEMES 2011

#include "SGInfra.h"
#include "CAT3DBagRep.h"

#include "CATVisMacroForInterfaces.h"

#include "CATMathVectorf.h"

class IVisSG3DBillboard;
class Vis3DBillboardRepIVisSG3DBillboardBOAImpl;

class CATRender;

/** 
 * Scene graph node class to create billboards
 * <b>Role</b>: Scene graph node class to create billboards
 * A billboard is a node that causes its children to always "face" the viewpoint. This is
 * performed by a set of dynamic (viewpoint's dependent) rotations.
 * There are two types of billboards:
 *  - Spherical billboard nodes will cause the local z axis of its children to be aligned
 *    with the viewpoint's sight vector and the local y axis of its children to be alinged
 *    with the viewpoint's up vector.
 *  - Cylindrical billboard nodes will cause the local z axis of its children to be in
 *    the same plane of the viewpoint's sight vector by only rotating around
 *    the local y axis of its children.
 */
class ExportedBySGInfra Vis3DBillboardRep : public CAT3DBagRep
{
  CATDeclareClass;

public:
  enum Vis3DBillboardType
  {
    Vis3DCylindricalBillboard,
    Vis3DSphericalBillboard
  };

  static Vis3DBillboardRep* CreateRep(Vis3DBillboardType iType = Vis3DCylindricalBillboard);

protected:

  /** @deprecated R417 : Use CreateRep instead.*/
  Vis3DBillboardRep();

public:

  virtual ~Vis3DBillboardRep();

  CATVisDeclarePublicInterfaceAdhesion(
    Vis3DBillboardRep,
    IVisSG3DBillboard,
    Vis3DBillboardRepIVisSG3DBillboardBOAImpl);

  Vis3DBillboardType GetBillboardType() const;
  void SetBillboardType(Vis3DBillboardType iType);

  /** Reimplemented from CAT3DBagRep */
  virtual void DrawShading(CATRender& ioRender, int iInside) override final;

  /** Reimplemented from CAT3DBagRep */
  virtual void DrawPath(CATRender& ioRender, int iInside, CATRepPath& ioPath) override final;

  // AZX: (A2X migration) Making draw functions final 
  virtual void Draw(CATRender& iRender, int iInside) override final;
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

  /** Reimplemented from CAT3DBagRep */
  virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

  /** Reimplemented from CAT3DBagRep */
  virtual void SetBoundingElement(const CAT3DBoundingSphere& iBoundingSphere);

  /** Reimplemented from CAT3DBagRep */
  virtual void ComputeBoundingElement(int iShowSpace = 1);

  /** Reimplemented from CAT3DRep */
  virtual void AddBoundingElement(const CAT3DBoundingSphere& iBoundingSphere);

protected:
  void ComputeCylindricalTransform(
    CATRender& ioRender, CAT4x4Matrix& oMatrix);

  void ComputeSphericalTransform(
    CATRender& ioRender, CAT4x4Matrix& oMatrix);

  void ComputeAlignAxisTransform(
    CATMathVectorf& iAxis1,
    CATMathVectorf& iAxis2,
    CAT4x4Matrix& oMatrix);

private:
  Vis3DBillboardType _type = Vis3DCylindricalBillboard;
};

#endif  // Vis3DBillboardRep_h
