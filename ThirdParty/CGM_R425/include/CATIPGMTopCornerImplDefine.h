#include "CATIPGMTopTangentCurveOperatorImplDefine.h"
#include "CATTopCornerCx2.h"

// ---------- CATTopCorner

/* Already defined in a parent class
int CATCGM_ITF_IMPL_CLASS::Run()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.Run();
}
*/

CATLONG32 CATCGM_ITF_IMPL_CLASS::GetNumberOfCorners() const
{
  const CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetNumberOfCorners();
}

void CATCGM_ITF_IMPL_CLASS::BeginningCorner()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.BeginningCorner();
}

CATBoolean CATCGM_ITF_IMPL_CLASS::NextCorner()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.NextCorner();
}

CATBody *CATCGM_ITF_IMPL_CLASS::GetCorner(CATCGMJournalList *iCurrentJournal)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetCorner(iCurrentJournal);
}

void CATCGM_ITF_IMPL_CLASS::GetCurOrients(
    CATOrientation &ioOr1,
    CATOrientation &ioOr2,
    CATOrientation &ioOr3) const
{
  const CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetCurOrients(
    ioOr1,
    ioOr2,
    ioOr3);
}

void CATCGM_ITF_IMPL_CLASS::GetCurBeginOfCorner(int &oNumWire)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetCurBeginOfCorner(oNumWire);
}

void CATCGM_ITF_IMPL_CLASS::GetCenterRadius(CATMathPoint &ioCenter, double &ioRadius)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetCenterRadius(ioCenter, ioRadius);
}

void CATCGM_ITF_IMPL_CLASS::SetOffsetOrientation(
    int iOrientCrv1,
    int iOrientCrv2,
    int iOrientCrv3)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetOffsetOrientation(
    iOrientCrv1,
    iOrientCrv2,
    iOrientCrv3);
}

void CATCGM_ITF_IMPL_CLASS::SetBeginOfCorner(int iNumWire)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetBeginOfCorner(iNumWire);
}

void CATCGM_ITF_IMPL_CLASS::GetBeginOfCorner(int &oNumWire)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetBeginOfCorner(oNumWire);
}

void CATCGM_ITF_IMPL_CLASS::GetOffsetOrientation(
    int &ioOrientCrv1,
    int &ioOrientCrv2,
    int &ioOrientCrv3) const
{
  const CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetOffsetOrientation(
    ioOrientCrv1,
    ioOrientCrv2,
    ioOrientCrv3);
}

/* Already defined in a parent class
CATBody *CATCGM_ITF_IMPL_CLASS::GetResult()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetResult();
}
*/

CATLONG32 CATCGM_ITF_IMPL_CLASS::SetSupportTrimmingMode(const CATLONG32 iTrimmingMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.SetSupportTrimmingMode(iTrimmingMode);
}

CATLONG32 CATCGM_ITF_IMPL_CLASS::GetSupportTrimmingMode(CATLONG32 &iTrimmingMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetSupportTrimmingMode(iTrimmingMode);
}

CATLONG32 CATCGM_ITF_IMPL_CLASS::SetSupportTrimmingSideAndMode(
    const CATLONG32 iTrimmingSide,
    const CATLONG32 iTrimmingMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.SetSupportTrimmingSideAndMode(
    iTrimmingSide,
    iTrimmingMode);
}

CATLONG32 CATCGM_ITF_IMPL_CLASS::GetSupportTrimmingSideAndMode(
    CATLONG32 &oTrimmingSide,
    CATLONG32 &oTrimmingMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetSupportTrimmingSideAndMode(
    oTrimmingSide,
    oTrimmingMode);
}

CATLONG32 CATCGM_ITF_IMPL_CLASS::SetSupportTrim(
    const CATLONG32 iTrimmingSide,
    const CATLONG32 iTrimmingMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.SetSupportTrim(
    iTrimmingSide,
    iTrimmingMode);
}

CATLONG32 CATCGM_ITF_IMPL_CLASS::GetSupportTrim(
    CATLONG32 iTrimmingSide,
    CATLONG32 &oTrimmingMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetSupportTrim(
    iTrimmingSide,
    oTrimmingMode);
}

CATLONG32 CATCGM_ITF_IMPL_CLASS::SetCircleMode(
    CATCircleMode iCircleMode,
    double iStart,
    double iEnd)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.SetCircleMode(
    iCircleMode,
    iStart,
    iEnd);
}

void CATCGM_ITF_IMPL_CLASS::GetCircleMode(
    CATCircleMode &ioCircleMode,
    double &ioStart,
    double &ioEnd)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetCircleMode(
    ioCircleMode,
    ioStart,
    ioEnd);
}

CATBoolean CATCGM_ITF_IMPL_CLASS::GetCircularData(
    CATMathPoint &oCenter,
    CATAngle &oRadius,
    CATMathDirection &oFirst,
    CATMathDirection &oSecond,
    CATAngle &oStartAngle,
    CATAngle &oEndAngle) const
{
  const CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetCircularData(
    oCenter,
    oRadius,
    oFirst,
    oSecond,
    oStartAngle,
    oEndAngle);
}

void CATCGM_ITF_IMPL_CLASS::SetDirection(const CATMathDirection &iDirectionFor3DCorner)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  // Pour faire plaisir à Rémy
  ((CATTopCornerCx2 &)HandledObject).SetDirection(iDirectionFor3DCorner);
}

void CATCGM_ITF_IMPL_CLASS::GetDirection(
    CATMathDirection &oDirectionFor3DCorner,
    CATBoolean &oAutomaticModeForDirection)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  // Pour faire plaisir à Rémy
  ((CATTopCornerCx2 &)HandledObject).GetDirection(
    oDirectionFor3DCorner,
    oAutomaticModeForDirection);
}

