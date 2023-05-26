#include "CATIPGMTopOperatorImplDefine.h"

// ---------- CATBRepToDRepOperator

HRESULT CATCGM_ITF_IMPL_CLASS::AddDeclarativeManifoldAgent(CATDeclarativeManifoldAgent *&ioAgent)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.AddDeclarativeManifoldAgent(ioAgent);
}

HRESULT CATCGM_ITF_IMPL_CLASS::GenerateBaseAgents(
    CATDeclarativeApplication iAppli,
    CATDeclarativeContext &iContext,
    CATDeclarativeOriginModeler iModeler)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GenerateBaseAgents(
    iAppli,
    iContext,
    iModeler);
}

HRESULT CATCGM_ITF_IMPL_CLASS::GenerateMandatoryAgents(
    CATDeclarativeApplication iAppli,
    CATDeclarativeContext &iContext,
    CATDeclarativeOriginModeler iModeler,
    CATLISTP(CATAgentRelationNode) &iMandatoryNodes,
    CATLISTP(CATAgentRelationNode) &iForbiddenNodes)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  return HandledObject.GenerateMandatoryAgents(
    iAppli,
    iContext,
    iModeler,
    iMandatoryNodes,
    iForbiddenNodes);
}

void CATCGM_ITF_IMPL_CLASS::SetUserDefinedSelection(CATLISTP(CATFace) &iUserSelection)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetUserDefinedSelection(iUserSelection);
}

void CATCGM_ITF_IMPL_CLASS::SetCandidateIndustryList(CATListOfInt &iCandidateIndustryList)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.SetCandidateIndustryList(iCandidateIndustryList);
}

void CATCGM_ITF_IMPL_CLASS::GetRecommendedIndustryList(CATListOfInt &oRecommendedIndustryList)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetRecommendedIndustryList(oRecommendedIndustryList);
}

void CATCGM_ITF_IMPL_CLASS::GetLostFilletList(
    CATDeclarativeContextIndustry iIndustry,
    CATLISTP(CATCell) &oLostFilletList,
    double &oMinLostRadius,
    double &oMaxLostRadius)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetLostFilletList(
    iIndustry,
    oLostFilletList,
    oMinLostRadius,
    oMaxLostRadius);
}

void CATCGM_ITF_IMPL_CLASS::GetRecognizedFilletList(
    CATDeclarativeContextIndustry iIndustry,
    CATLISTP(CATCell) &oRecognizedFilletList,
    double &oMinRecogRadius,
    double &oMaxRecogRadius)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetRecognizedFilletList(
    iIndustry,
    oRecognizedFilletList,
    oMinRecogRadius,
    oMaxRecogRadius);
}

void CATCGM_ITF_IMPL_CLASS::GetLostChamferList(
    CATDeclarativeContextIndustry iIndustry,
    CATLISTP(CATCell) &oLostChamferList,
    double &oMinLostDistance,
    double &oMaxLostDistance)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetLostChamferList(
    iIndustry,
    oLostChamferList,
    oMinLostDistance,
    oMaxLostDistance);
}

void CATCGM_ITF_IMPL_CLASS::GetRecognizedChamferList(
    CATDeclarativeContextIndustry iIndustry,
    CATLISTP(CATCell) &oRecognizedChamferList,
    double &oMinRecogDist,
    double &oMaxRecogDist)
{
  CATCGM_ITF_CONCRETE_CLASS &HandledObject = (CATCGM_ITF_CONCRETE_CLASS &)_InternalData.GetHandledObject();
  HandledObject.GetRecognizedChamferList(
    iIndustry,
    oRecognizedChamferList,
    oMinRecogDist,
    oMaxRecogDist);
}

