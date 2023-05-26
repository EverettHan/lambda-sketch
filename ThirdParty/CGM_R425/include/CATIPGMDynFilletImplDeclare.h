#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATIPGMDynOperatorImplDeclare.h"

  // ---------- CATDynFillet

  virtual void Append(CATDynFaceFaceFilletRibbon *iRibbonToAppend);

  virtual void Append(CATDynEdgeFilletRibbon *iRibbonToAppend);

  virtual void Append(CATDynRemoveFaceFilletRibbon *iRibbonToRemove);

  virtual void SetPrevisualizationOnly();

  virtual void SetVertexBlendList(
    CATLISTP(CATDynFilletBlendVertex) &iVertexBlendList);

  virtual CATDynBlendVertexDiag *CreateVertexBlendDiag(int iVertexBlendIndex);

#ifdef CATIACGMV5R23
  virtual void AddLimitingElement(
    CATBody *iBody,
    CATDomain *iSkin,
    const CATOrientation iOrientation);
#endif

  virtual void AddLimitingElement(
    CATBody *iBody,
    CATDomain *iSkin,
    const CATOrientation iOrientation,
    const int iSmartCrossParting);

  virtual void SetTrueMultiRibbonOnly();

  virtual void GetSplittingElements(
    int iSupport,
    CATLISTP(CATGeometry) &oElementsList,
    CATListOfInt &oSides);

  virtual void SetHelpPoint(CATMathPoint &iHelpPoint);

/* Already defined in a parent class
  virtual CATContextForFastRun *GetContextForFastRun(CATBoolean iGetOnly);
*/

  virtual CATDynFilletContextForFastRun *GetDynFilletContextForFastRun(
    CATBoolean iGetOnly);

