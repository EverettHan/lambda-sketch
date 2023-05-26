#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATICGMDynOperatorImplDeclare.h"

  // ---------- CATDynFillet

  virtual void Append(CATDynFaceFaceFilletRibbon *iRibbonToAppend);

  virtual void Append(CATDynEdgeFilletRibbon *iRibbonToAppend);

  virtual void Append(CATDynRemoveFaceFilletRibbon *iRibbonToRemove);

  virtual void SetPrevisualizationOnly();

#ifdef CATIACGMV5R23
  virtual void AddLimitingElement(
    CATBody *iBody,
    CATDomain *iSkin,
    const CATOrientation iOrientation);
#endif

  virtual void SetTrueMultiRibbonOnly();

  virtual void SetHelpPoint(CATMathPoint &iHelpPoint);

