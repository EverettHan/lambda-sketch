#include "CATIPGMTopOperatorImplDeclare.h"

  // ---------- CATDistanceBodyBody

  virtual double GetDistance();

  virtual void GetPoints(CATMathPoint &oPoint1, CATMathPoint &oPoint2);

  virtual void GetPoints(CATPoint *&oPoint1, CATPoint *&oPoint2);

  virtual void GetSupportCells(CATCell *&oCell1, CATCell *&oCell2);

  virtual void SetReferencePoint(const CATMathPoint &iRefPoint);

  virtual void GetReferencePoint(CATMathPoint &oRefPoint);

  virtual void ReplaceBody(CATBody *iBodyToReplace, CATBody *iNewBody);

  virtual void SetDistanceMax(double iDistanceMax);

  virtual void SetDistanceUpperBound(double iDistanceUpperBound);

  virtual void SetTargetCells(
    CATLISTP(CATCell) &iCellsOnBody1,
    CATLISTP(CATCell) &iCellsOnBody2);

  virtual void SetDistanceType(CATDistanceBodyBodyType iType);

  virtual void SetDistanceMode(CATDistanceBodyBodyMode iMode);

