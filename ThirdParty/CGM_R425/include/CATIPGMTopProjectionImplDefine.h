#include "CATIPGMTopOperatorImplDefine.h"

// ---------- CATTopProjection

void CATCGM_ITF_IMPL_CLASS::SetDomainToProject(CATDomain *iDomain)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetDomainToProject(iDomain);
}

void CATCGM_ITF_IMPL_CLASS::SetDomainSupport(CATDomain *iDomain)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetDomainSupport(iDomain);
}

void CATCGM_ITF_IMPL_CLASS::SetMaxDistance(double iDistance)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetMaxDistance(iDistance);
}

void CATCGM_ITF_IMPL_CLASS::SetBestSolWanted(CATLONG32 bestsol)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetBestSolWanted(bestsol);
}

double CATCGM_ITF_IMPL_CLASS::GetDistance(CATDomain *iDomainOfResultBody)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetDistance(iDomainOfResultBody);
}

CATBody *CATCGM_ITF_IMPL_CLASS::GetLine(CATDomain *iDomainOfResultBody)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetLine(iDomainOfResultBody);
}

double CATCGM_ITF_IMPL_CLASS::GetMaxDistance()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetMaxDistance();
}

