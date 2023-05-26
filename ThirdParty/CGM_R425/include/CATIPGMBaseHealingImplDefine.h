#include "CATIPGMTopOperatorImplDefine.h"

// ---------- CATBaseHealing

int CATCGM_ITF_IMPL_CLASS::SetBodyToHeal(CATBody *iBodyToHeal)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.SetBodyToHeal(iBodyToHeal);
}

/* Already defined in a parent class
void CATCGM_ITF_IMPL_CLASS::SetFreezeMode(CATBodyFreezeMode iFreezeMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetFreezeMode(iFreezeMode);
}
*/

int CATCGM_ITF_IMPL_CLASS::SetGlobalContinuity(const short iOrder)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.SetGlobalContinuity(iOrder);
}

void CATCGM_ITF_IMPL_CLASS::SetG0Tolerance(const double iTolG0)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetG0Tolerance(iTolG0);
}

void CATCGM_ITF_IMPL_CLASS::SetMaxG0Tolerance(const double iTolG0Max)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetMaxG0Tolerance(iTolG0Max);
}

void CATCGM_ITF_IMPL_CLASS::SetMaxG1Tolerance(const double iTolAngular)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetMaxG1Tolerance(iTolAngular);
}

void CATCGM_ITF_IMPL_CLASS::SetG1Tolerance(const double iTolAngular)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetG1Tolerance(iTolAngular);
}

void CATCGM_ITF_IMPL_CLASS::SetSharpnessTolerance(const double iTolSharpness)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetSharpnessTolerance(iTolSharpness);
}

int CATCGM_ITF_IMPL_CLASS::Add(CATEdge *iE, const short iOrder)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.Add(iE, iOrder);
}

int CATCGM_ITF_IMPL_CLASS::SetFace(
    CATFace *iF,
    const CATBoolean iIsGeomFree,
    const CATBoolean iIsTypeFree)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.SetFace(
    iF,
    iIsGeomFree,
    iIsTypeFree);
}

int CATCGM_ITF_IMPL_CLASS::SetFace(
    const CATLISTP(CATFace) &iListOfFaces,
    const CATBoolean iIsGeomFree,
    const CATBoolean iIsTypeFree)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.SetFace(
    iListOfFaces,
    iIsGeomFree,
    iIsTypeFree);
}

int CATCGM_ITF_IMPL_CLASS::SetFace(
    const CATGeometricType iType,
    const CATBoolean iIsGeomFree,
    const CATBoolean iIsTypeFree)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.SetFace(
    iType,
    iIsGeomFree,
    iIsTypeFree);
}

int CATCGM_ITF_IMPL_CLASS::SetCanonic(
    const CATBoolean iIsGeomFree,
    const CATBoolean iIsTypeFree)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.SetCanonic(
    iIsGeomFree,
    iIsTypeFree);
}

int CATCGM_ITF_IMPL_CLASS::SetEdge(CATEdge *iE, const short iOrder)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.SetEdge(iE, iOrder);
}

int CATCGM_ITF_IMPL_CLASS::SetEdge(const CATLISTP(CATEdge) &iListOfEdges, const short iOrder)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.SetEdge(iListOfEdges, iOrder);
}

int CATCGM_ITF_IMPL_CLASS::SetAdjustPCurve(const short iAdjustPCurve)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.SetAdjustPCurve(iAdjustPCurve);
}

int CATCGM_ITF_IMPL_CLASS::Add(
    CATVertex *iVertexToHeal,
    CATEdge *iEdgeToFix,
    const short iOrder)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.Add(
    iVertexToHeal,
    iEdgeToFix,
    iOrder);
}

int CATCGM_ITF_IMPL_CLASS::SetVertex(
    CATVertex *iVertexToFix,
    CATEdge *iEdge,
    const short iOrder)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.SetVertex(
    iVertexToFix,
    iEdge,
    iOrder);
}

void CATCGM_ITF_IMPL_CLASS::SetMaxIter(const int iMaxIter)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetMaxIter(iMaxIter);
}

double CATCGM_ITF_IMPL_CLASS::G0MaxError()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.G0MaxError();
}

double CATCGM_ITF_IMPL_CLASS::G1MaxError()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.G1MaxError();
}

CATBoolean CATCGM_ITF_IMPL_CLASS::IsSatisfied()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.IsSatisfied();
}

int CATCGM_ITF_IMPL_CLASS::G0MaxError(CATEdge *iE, double &ioG0Error)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.G0MaxError(iE, ioG0Error);
}

int CATCGM_ITF_IMPL_CLASS::G1MaxError(CATEdge *iE, double &ioG1Error)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.G1MaxError(iE, ioG1Error);
}

int CATCGM_ITF_IMPL_CLASS::IsSatisfied(CATEdge *iE, CATBoolean &ioIsSatisfied)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.IsSatisfied(iE, ioIsSatisfied);
}

int CATCGM_ITF_IMPL_CLASS::GetOpenEdges(CATLISTP(CATEdge) &ioListOfEdges)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetOpenEdges(ioListOfEdges);
}

int CATCGM_ITF_IMPL_CLASS::GetSharpEdges(CATLISTP(CATEdge) &ioListOfEdges)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetSharpEdges(ioListOfEdges);
}

int CATCGM_ITF_IMPL_CLASS::GetMaxDeformationOnEdge(CATEdge *iE, double &oMaxDef)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetMaxDeformationOnEdge(iE, oMaxDef);
}

int CATCGM_ITF_IMPL_CLASS::GetAutoMaxShapeDeformation(double &oMaxDef)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetAutoMaxShapeDeformation(oMaxDef);
}

