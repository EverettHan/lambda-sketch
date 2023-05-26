#ifndef CAT3DFinalBagRep_H
#define CAT3DFinalBagRep_H

#include "CAT3DBagRep.h"

/**
* xxxFinalxxxRep 
* Final means all virtual draw methods are made final in this class.
* Derived classes can't override any of these draw methods.
* This ensures rendering behavior is not altered by derived class
*/

class ExportedBySGInfra CAT3DFinalBagRep : public CAT3DBagRep
{
  CATDeclareClass;

public:
  /**
  * Factory method to create object of this class. 
  * Constructor is made protected/private to avoid creating objects using 'new'
  */
  static CAT3DFinalBagRep* CreateRep();

  /** @nodoc */
  void DrawShading(CATRender &ioRender, int iInside) override final;

  /** @nodoc */
  void DrawPath(CATRender &ioRender, int iInside, CATRepPath &ioPath) override final;

  /** @nodoc */
  void Draw(CATRender &ioRender, int iInside) override final;
  
  /** @nodoc */
  int  IsOkToDraw(CATRender &ioRender, int ioInside) override final;


protected:
  CAT3DFinalBagRep(void);
  CAT3DFinalBagRep(CATModelIdentificator& id, CATVisuController* ctrl);
  virtual ~CAT3DFinalBagRep() = default;
};

#endif
