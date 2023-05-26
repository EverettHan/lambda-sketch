#ifndef Vis2DFixedSizeNodeGroupRep_H
#define Vis2DFixedSizeNodeGroupRep_H

// COPYRIGHT DASSAULT SYSTEMES 2022

#include "SGInfra.h"
#include "CAT2DBagRep.h"

#include "CATVisMacroForInterfaces.h"

class IVisSG2DFixedSizeNodeGroup;
class Vis2DFixedSizeNodeGroupRepIVisSG2DFixedSizeNodeGroupBOAImpl;

class CATRender;
class CATMathPoint2Df;

/**
* Class to create graphical objects which will be rendering in fixed onscreen size.
* This class is derived from bag rep thus any rep can be inserted as a child.
*/
class ExportedBySGInfra Vis2DFixedSizeNodeGroupRep : public CAT2DBagRep
{
  CATDeclareClass;

public:

  static Vis2DFixedSizeNodeGroupRep* CreateRep();

  virtual ~Vis2DFixedSizeNodeGroupRep();

  CATVisDeclarePublicInterfaceAdhesion(
    Vis2DFixedSizeNodeGroupRep,
    IVisSG2DFixedSizeNodeGroup,
    Vis2DFixedSizeNodeGroupRepIVisSG2DFixedSizeNodeGroupBOAImpl);

  /**
  * This factor is used to change on screen size of model.
  * by default its value is 1, on screen size of model will be same as its actual size.
  * For ex: a cube of size 100 units will apear 10cm on screen if the factor is 1.0
  */
  void SetScaleFactor(float iScale);
  float GetScaleFactor() const;

  /**
  * Model will be scaled with anchor as invariant point (in local space).
  * If this methode is not called, local origine (0, 0) is taken as invarient point.
  */
  void SetInvariantPoint(const CATMathPoint2Df& iInvariantPoint);

  /**
  * Resets the invarient point to BE center
  */
  void ResetInvariantPoint();

  /**
  * If returned value is NULL, it means SetInvariantPoint was never called
  */
  const CATMathPoint2Df* GetInvariantPoint() const;

  /** Draw functions */
  virtual void DrawShading(CATRender& ioRender, int iInside) override final;
  virtual void DrawPath(CATRender& ioRender, int iInside, CATRepPath& ioPath) override final;
  virtual void Draw(CATRender& iRender, int iInside) override final;
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

  /** BoundingElement management */
  virtual void AddBoundingElement(const CAT2DBoundingBox& iBE);

protected:

  Vis2DFixedSizeNodeGroupRep();

  float m_scaleFactor = 1.f;
  CATMathPoint2Df* m_pInvariantPoint = nullptr;

  CAT3x3Matrix GetFixedScalingMatrix(const CATRender& iRender) const;
};

#endif // Vis2DFixedSizeNodeGroupRep_H

