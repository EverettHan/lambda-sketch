#ifndef CAT2DFinalRep_H
#define CAT2DFinalRep_H

#include "CAT2DRep.h"

/**
* xxxFinalxxxRep 
* Final means all virtual draw methods are made final in this class.
* Derived classes can't override any of these draw methods.
* This ensures rendering behavior is not altered by derived class
*/

class ExportedBySGInfra CAT2DFinalRep : public CAT2DRep
{
  CATDeclareClass;

public:
  /**
  * Factory method to create object of this class. 
  * Constructor is made protected/private to avoid creating objects using 'new'
  */
  static CAT2DFinalRep* CreateRep();

  /** @nodoc */
  void DrawShading(CATRender &ioRender, int iInside) override final;

  /** @nodoc */
  void DrawPath(CATRender &ioRender, int iInside, CATRepPath &ioPath) override final;

  /** @nodoc */
  void Draw(CATRender &ioRender, int iInside) override final;
  
  /** @nodoc */
  int  IsOkToDraw(CATRender &ioRender, int ioInside) override final;

protected:
  CAT2DFinalRep(void);
};

#endif
