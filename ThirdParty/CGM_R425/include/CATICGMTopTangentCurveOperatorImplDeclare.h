#include "CATICGMTopMultiResultImplDeclare.h"

  // ---------- CATTopTangentCurveOperator

  virtual void SetTangentOrientation(int iTangentOrientation, int iRankWire);

  virtual void SetCurvatureOrientation(int iCurvatureOrientation, int iIWire);

  virtual void GetOrientationOnWire(
    int &ioTangentOrient,
    int &ioCurvatureOrient,
    int &ioIdem,
    int iRankWire);

  virtual void GetDiscriminationIndex(int &ioIndex);

  virtual int GetTangentOrientation(int iRankWire) const;

  virtual int GetCurvatureOrientation(int iRankWire) const;

  virtual CATBody *GetResultWithConditions(
    CATOrientation *iCrvOr,
    CATOrientation *iTngOr,
    int iIndex,
    CATBoolean &oUseOrientationCondition,
    CATBoolean &oUseIndexCondition,
    CATCGMJournalList *CurJourn);

