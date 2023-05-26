#include "CATIPGMTopOperatorImplDeclare.h"

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

  virtual void SetViewPoint(const CATMathPoint &iPt);

  virtual void SetViewDirection(const CATMathDirection &iDir);

  virtual void DisableReflectLineComputation();

  virtual void SetShadowScreen(
    CATBody *iScreenBody,
    int iOutputDim,
    int iViewSide);

  virtual void SetSilhouetteSelectionMode(
    int iSilhTypes,
    int iStoreOutputDomainTypes);

  virtual void GetOutputDomainType(
    CATDomain *iOutputDomain,
    int &oSilhDomainType);

