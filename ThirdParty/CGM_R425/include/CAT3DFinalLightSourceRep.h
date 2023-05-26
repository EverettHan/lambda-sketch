#ifndef CAT3DFinalLightSourceRep_H
#define CAT3DFinalLightSourceRep_H

#include "CAT3DLightSourceRep.h"

/**
* xxxFinalxxxRep 
* Final means all virtual draw methods are made final in this class.
* Derived classes can't override any of these draw methods.
* This ensures rendering behavior is not altered by derived class
*/

class ExportedBySGInfra CAT3DFinalLightSourceRep : public CAT3DLightSourceRep
{
  CATDeclareClass;

public:
  /**
  * Factory method to create object of this class. 
  * Constructor is made protected/private to avoid creating objects using 'new'
  */
  static CAT3DFinalLightSourceRep* CreateRep();
  static CAT3DFinalLightSourceRep* CreateRep(const CATLightSourceType  iType,
                                             const CATLightSourceMode  iMode,
                                             const CATMathPointf&      iOrigin,
                                             const CATMathDirectionf&  iDirection,
                                             const float               iSpotAngle = 180.f);
  static CAT3DFinalLightSourceRep* CreateRep(const CAT3DFinalLightSourceRep& iLightSourceRep);

  /** @nodoc */
  void DrawShading(CATRender &ioRender, int iInside) override final;

  /** @nodoc */
  void DrawPath(CATRender &ioRender, int iInside, CATRepPath &ioPath) override final;

  /** @nodoc */
  void Draw(CATRender &ioRender, int iInside) override final;
  
  /** @nodoc */
  int  IsOkToDraw(CATRender &ioRender, int ioInside) override final;

protected:
  CAT3DFinalLightSourceRep(void);
  CAT3DFinalLightSourceRep(const CATLightSourceType iType,
                           const CATLightSourceMode iMode,
                           const CATMathPointf&     iOrigin,
                           const CATMathDirectionf& iDirection,
                           const float              iSpotAngle = 180.f);
  CAT3DFinalLightSourceRep(const CAT3DFinalLightSourceRep& iLightSourceRep);
};

#endif
