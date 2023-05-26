#include "CATIPGMDynOperatorImplDeclare.h"

  // ---------- CATDynChamfer

  virtual void Append(CATDynChamferRibbon *iRibbonToAppend);

  virtual void SetPrevisualizationOnly();

  virtual void AddLimitingElement(
    CATBody *iBody,
    CATDomain *iSkin,
    const CATOrientation iOrientation);

  virtual void SetTrueMultiRibbonOnly();

  virtual void GetSplittingElements(
    int iSupport,
    CATLISTP(CATGeometry) &oElementsList,
    CATListOfInt &oSides);

  /* Already defined in a parent class
  virtual CATContextForFastRun *GetContextForFastRun(CATBoolean iGetOnly);
  */

  virtual CATDynChamferContextForFastRun *GetDynChamferContextForFastRun(
    CATBoolean iGetOnly);

