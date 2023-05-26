#ifndef Vis3DFixedSizeNodeGroupRep_H
#define Vis3DFixedSizeNodeGroupRep_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "SGInfra.h"
#include "Vis3DNodeGroupRep.h"

#include "CATVisMacroForInterfaces.h"

class IVisSG3DFixedSizeNodeGroup;
class Vis3DFixedSizeNodeGroupRepIVisSG3DFixedSizeNodeGroupBOAImpl;

class CATRender;
class CATMathPointf;

/**
* Class to create graphical objects which will be rendering in fixed size onscreen.
* This class is derived from bag rep thus any rep can be inserted as a child. 
*/
class ExportedBySGInfra Vis3DFixedSizeNodeGroupRep : public Vis3DNodeGroupRep
{
  CATDeclareClass;

public:

  static Vis3DFixedSizeNodeGroupRep* CreateRep();
  
protected:

  /** @deprecated R417 : Use CreateRep instead.*/
  Vis3DFixedSizeNodeGroupRep();

public:
  
  virtual ~Vis3DFixedSizeNodeGroupRep();

  CATVisDeclarePublicInterfaceAdhesion(
    Vis3DFixedSizeNodeGroupRep,
    IVisSG3DFixedSizeNodeGroup,
    Vis3DFixedSizeNodeGroupRepIVisSG3DFixedSizeNodeGroupBOAImpl);

  /*
  * This factor is used to change on screen size of model.
  * by default its value is 1, on screen size of model will be same as its actual size.
  * For ex: a cube of size 100 units will apear 10cm on screen if the factor is 1.0
  */
  void SetScaleFactor(float iRatio);
  float GetScaleFactor() const;

  /*
  * @deprecated: use Set/GetScaleFactor 
  */
  void SetFixedSize(float iFixedSize);
  void SetFixedSizeRange(float iMinSize, float iMaxSize);
  void GetFixedSizeRange(float& oMinSize, float& oMaxSize) const;

  /**
  * Model will be scaled with anchor as invariant point (in local space).
  * If this methode is not called, center of bounding sphere is taken as invarient point.
  */
  void SetInvariantPoint (const CATMathPointf &iInvariantPoint);

  /**
  * Resets the invarient point to BE center
  */
  void ResetInvariantPoint();

  /**
  * If returned value is NULL, it means SetInvariantPoint was never called and BE center is treated as invariant point
  */
  const CATMathPointf* GetInvariantPoint() const;

  /*
  * @deprecated: use Set/GetInvariantPoint version which doesn't deal with pointers
  */
  void SetInvariantPoint (CATMathPointf *iInvariantPoint);

  /** Reimplemented from Vis3DNodeGroupRep */
  virtual void DrawShading(CATRender &ioRender, int iInside) override final;
  virtual void DrawPath(CATRender &ioRender, int iInside, CATRepPath &ioPath) override final;
  virtual void Draw(CATRender& iRender, int iInside) override final;
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

  /** Reimplemented from Vis3DNodeGroupRep */
  virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

  /** Manage BE */
  virtual void SetBoundingElement(const CAT3DBoundingSphere &iBoundingSphere) override;
  virtual void ComputeBoundingElement(int iShowSpace=1) override;
  virtual void AddBoundingElement(const CAT3DBoundingSphere& iBoundingSphere) override;

protected:
  float m_scaleFactor = 1.f;
  const CATMathPointf *m_pInvariantPoint = nullptr;

  CAT4x4Matrix GetFixedScalingMatrix(const CATRender& iRender) const;
};

#endif // Vis3DFixedSizeNodeGroupRep_H

