#include "CATIPGMHybOperatorImpImplDefine.h"
#include "CATExtHybProject.h"

// ---------- CATHybProject

/* Already defined in a parent class
int CATCGM_ITF_IMPL_CLASS::Run()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.Run();
}
*/

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

/* Already defined in a parent class
double CATCGM_ITF_IMPL_CLASS::GetDistance(CATDomain *iDomainOfResultBody)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetDistance(iDomainOfResultBody);
}
*/

void CATCGM_ITF_IMPL_CLASS::SetSuppressFlattenDomainMode(int yes_or_no)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetSuppressFlattenDomainMode(yes_or_no);
}

int CATCGM_ITF_IMPL_CLASS::GetSuppressFlattenDomainMode() const
{
  const CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetSuppressFlattenDomainMode();
}

void CATCGM_ITF_IMPL_CLASS::SetCoveredFaces(CATLISTP(CATFace) &iCoveredFaces)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetCoveredFaces(iCoveredFaces);
}

int CATCGM_ITF_IMPL_CLASS::IsCoveredFacesActive() const
{
  const CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.IsCoveredFacesActive();
}

void CATCGM_ITF_IMPL_CLASS::SetMaxDistanceValue(double iMaxDistance)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetMaxDistanceValue(iMaxDistance);
}

double CATCGM_ITF_IMPL_CLASS::GetMaxDistanceValue() const
{
  const CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetMaxDistanceValue();
}

int CATCGM_ITF_IMPL_CLASS::IsMaxDistanceActive() const
{
  const CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.IsMaxDistanceActive();
}

CATHybProjectionContext CATCGM_ITF_IMPL_CLASS::GetContext()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetContext();
}

void CATCGM_ITF_IMPL_CLASS::SetContext(CATHybProjectionContext iContext)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetContext(iContext);
}

void CATCGM_ITF_IMPL_CLASS::SetSimplificationMode(CATBoolean iSimplification)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetSimplificationMode(iSimplification);
}

CATBoolean CATCGM_ITF_IMPL_CLASS::GetSimplificationMode() const
{
  const CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetSimplificationMode();
}

CATBoolean CATCGM_ITF_IMPL_CLASS::IsCompletelyLaidDown()
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.IsCompletelyLaidDown();
}

CATExtHybProject *CATCGM_ITF_IMPL_CLASS::GetHybProjectExtensible() const
{
  const CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GetHybProjectExtensible();
}

void CATCGM_ITF_IMPL_CLASS::SetNewSmoothing(CATLONG32 iSmooth)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetNewSmoothing(iSmooth);
}

void CATCGM_ITF_IMPL_CLASS::GetNewSmoothing(CATLONG32 &oSmooth)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetNewSmoothing(oSmooth);
}

void CATCGM_ITF_IMPL_CLASS::SetOutputWireCleaning3DMode(CATLONG32 iOutputWireCleaning3DMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetOutputWireCleaning3DMode(iOutputWireCleaning3DMode);
}

void CATCGM_ITF_IMPL_CLASS::GetOutputWireCleaning3DMode(CATLONG32 &oOutputWireCleaning3DMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetOutputWireCleaning3DMode(oOutputWireCleaning3DMode);
}

#ifdef CATIACGMR419CAA
void CATCGM_ITF_IMPL_CLASS::SetExtrapolationMode(short iExtrapolationMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetExtrapolationMode(iExtrapolationMode);
}

void CATCGM_ITF_IMPL_CLASS::GetExtrapolationMode(short &oExtrapolationMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetExtrapolationMode(oExtrapolationMode);
}
#else
void CATCGM_ITF_IMPL_CLASS::SetExtrapolationMode(short iExtrapolationMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  ((CATExtHybProject *)(&HandledObject))->SetExtrapolationMode(iExtrapolationMode);
}

void CATCGM_ITF_IMPL_CLASS::GetExtrapolationMode(short &oExtrapolationMode)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  ((CATExtHybProject *)(&HandledObject))->GetExtrapolationMode(oExtrapolationMode);
}
#endif

