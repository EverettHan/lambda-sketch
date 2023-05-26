#include "CATICGMTopOperatorImplDeclare.h"

  // ---------- CATTopSilhOperator

  virtual void SetProjectionScreenForShadows(
    CATBody *iScreenBody,
    CATBoolean iLightSourceInFront,
    CATBoolean iFillHoles);

  virtual void SetProjectionScreenForShadows(
    const CATMathPlane &iScreenPlane,
    CATBoolean iLightSourceInFront,
    CATBoolean iFillHoles);

  virtual void EnableWireMode();
