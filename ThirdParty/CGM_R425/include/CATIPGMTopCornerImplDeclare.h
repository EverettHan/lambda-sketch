#include "CATIPGMTopTangentCurveOperatorImplDeclare.h"

  // ---------- CATTopCorner

/* Already defined in a parent class
  virtual int Run();
*/

  virtual CATLONG32 GetNumberOfCorners() const;

  virtual void BeginningCorner();

  virtual CATBoolean NextCorner();

  virtual CATBody *GetCorner(CATCGMJournalList *iCurrentJournal);

  virtual void GetCurOrients(
    CATOrientation &ioOr1,
    CATOrientation &ioOr2,
    CATOrientation &ioOr3) const;

  virtual void GetCurBeginOfCorner(int &oNumWire);

  virtual void GetCenterRadius(CATMathPoint &ioCenter, double &ioRadius);

  virtual void SetOffsetOrientation(
    int iOrientCrv1,
    int iOrientCrv2,
    int iOrientCrv3);

  virtual void SetBeginOfCorner(int iNumWire);

  virtual void GetBeginOfCorner(int &oNumWire);

  virtual void GetOffsetOrientation(
    int &ioOrientCrv1,
    int &ioOrientCrv2,
    int &ioOrientCrv3) const;

/* Already defined in a parent class
  virtual CATBody *GetResult();
*/

  virtual CATLONG32 SetSupportTrimmingMode(const CATLONG32 iTrimmingMode);

  virtual CATLONG32 GetSupportTrimmingMode(CATLONG32 &iTrimmingMode);

  virtual CATLONG32 SetSupportTrimmingSideAndMode(
    const CATLONG32 iTrimmingSide,
    const CATLONG32 iTrimmingMode);

  virtual CATLONG32 GetSupportTrimmingSideAndMode(
    CATLONG32 &oTrimmingSide,
    CATLONG32 &oTrimmingMode);

  virtual CATLONG32 SetSupportTrim(
    const CATLONG32 iTrimmingSide,
    const CATLONG32 iTrimmingMode);

  virtual CATLONG32 GetSupportTrim(
    CATLONG32 iTrimmingSide,
    CATLONG32 &oTrimmingMode);

  virtual CATLONG32 SetCircleMode(
    CATCircleMode iCircleMode,
    double iStart,
    double iEnd);

  virtual void GetCircleMode(
    CATCircleMode &ioCircleMode,
    double &ioStart,
    double &ioEnd);

  virtual CATBoolean GetCircularData(
    CATMathPoint &oCenter,
    CATAngle &oRadius,
    CATMathDirection &oFirst,
    CATMathDirection &oSecond,
    CATAngle &oStartAngle,
    CATAngle &oEndAngle) const;

  virtual void SetDirection(const CATMathDirection &iDirectionFor3DCorner);

  virtual void GetDirection(
    CATMathDirection &oDirectionFor3DCorner,
    CATBoolean &oAutomaticModeForDirection);

