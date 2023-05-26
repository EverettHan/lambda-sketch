#ifndef CAT2DFinalLineRep_H
#define CAT2DFinalLineRep_H

#include "CAT2DLineRep.h"

/**
* xxxFinalxxxRep 
* Final means all virtual draw methods are made final in this class.
* Derived classes can't override any of these draw methods.
* This ensures rendering behavior is not altered by derived class
*/

class ExportedBySGInfra CAT2DFinalLineRep : public CAT2DLineRep
{
  CATDeclareClass;

public:
  /**
  * Factory method to create object of this class. 
  * Constructor is made protected/private to avoid creating objects using 'new'
  * ... see CAT2DLineRep.h for more information.
  */
  static CAT2DFinalLineRep* CreateRep();
  static CAT2DFinalLineRep* CreateRep(const float iPoints[4]);
  static CAT2DFinalLineRep* CreateRep(const CATMathPoint2Df& iFirstPoint, const CATMathPoint2Df& iSecondPoint);
  static CAT2DFinalLineRep* CreateRep(const float iPoints[], const int iNbPoints,
    const int iAlloc = ALLOCATE, const int iLinetype = LINES, const TessFlag iTessFlag = LINE);

  /** @nodoc */
  void DrawShading(CATRender &ioRender, int iInside) override final;

  /** @nodoc */
  void DrawPath(CATRender &ioRender, int iInside, CATRepPath &ioPath) override final;

  /** @nodoc */
  void Draw(CATRender &ioRender, int iInside) override final;
  
  /** @nodoc */
  int  IsOkToDraw(CATRender &ioRender, int ioInside) override final;

protected:
  CAT2DFinalLineRep(void);
  CAT2DFinalLineRep(const float iPoints[4]);
  CAT2DFinalLineRep(const CATMathPoint2Df& iFirstPoint, const CATMathPoint2Df& iSecondPoint);
  CAT2DFinalLineRep(const float iPoints[], const int iNbPoints,
    const int iAlloc = ALLOCATE, const int iLinetype = LINES, const TessFlag iTessFlag = LINE);
};

#endif
