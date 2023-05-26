#include "CATIPGMVirtualImplDeclare.h"

  // ---------- CATDistanceBodyBody2

  virtual int Run();

  virtual double GetDistance();

  virtual void GetResultPoints(
    CATMathPoint &oMathPoint1,
    CATMathPoint &oMathPoint2);

  virtual void GetLinkPoints(CATPoint *&oPoint1, CATPoint *&oPoint2);

  virtual void GetSupportCells(CATCell *&oCell1, CATCell *&oCell2);

  virtual void SetReferencePoint(const CATMathPoint &iRefPoint);

  virtual void GetReferencePoint(CATMathPoint &oRefPoint);

  virtual void SetDistanceUpperBound(double iDistanceUpperBound);

  virtual void SetTargetCells(
    CATLISTP(CATCell) &iCellsOnBody1,
    CATLISTP(CATCell) &iCellsOnBody2);

  virtual void SetDistanceType(CATDistanceBodyBodyType iType);

  virtual CATDistanceBodyBodyType GetDistanceType();

  virtual void SetDistanceMode(CATDistanceBodyBodyMode iMode);

  virtual CATDistanceBodyBodyMode GetDistanceMode();

  virtual void ReplaceBody(
    CATBody *iBodyToReplace,
    CATGeoFactory *iFactoryOfNewBody,
    CATBody *iNewBody,
    const CATMathTransformation &iNewBodyTransformation);

