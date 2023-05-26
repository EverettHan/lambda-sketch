#include "CATIPGMTopOperatorImplDeclare.h"

  // ---------- CATBRepToDRepOperator

  virtual HRESULT AddDeclarativeManifoldAgent(CATDeclarativeManifoldAgent *&ioAgent);

  virtual HRESULT GenerateBaseAgents(
    CATDeclarativeApplication iAppli,
    CATDeclarativeContext &iContext,
    CATDeclarativeOriginModeler iModeler);

  virtual HRESULT GenerateMandatoryAgents(
    CATDeclarativeApplication iAppli,
    CATDeclarativeContext &iContext,
    CATDeclarativeOriginModeler iModeler,
    CATLISTP(CATAgentRelationNode) &iMandatoryNodes,
    CATLISTP(CATAgentRelationNode) &iForbiddenNodes);

  virtual void SetUserDefinedSelection(CATLISTP(CATFace) &iUserSelection);

  virtual void SetCandidateIndustryList(CATListOfInt &iCandidateIndustryList);

  virtual void GetRecommendedIndustryList(CATListOfInt &oRecommendedIndustryList);

  virtual void GetLostFilletList(
    CATDeclarativeContextIndustry iIndustry,
    CATLISTP(CATCell) &oLostFilletList,
    double &oMinLostRadius,
    double &oMaxLostRadius);

  virtual void GetRecognizedFilletList(
    CATDeclarativeContextIndustry iIndustry,
    CATLISTP(CATCell) &oRecognizedFilletList,
    double &oMinRecogRadius,
    double &oMaxRecogRadius);

  virtual void GetLostChamferList(
    CATDeclarativeContextIndustry iIndustry,
    CATLISTP(CATCell) &oLostChamferList,
    double &oMinLostDistance,
    double &oMaxLostDistance);

  virtual void GetRecognizedChamferList(
    CATDeclarativeContextIndustry iIndustry,
    CATLISTP(CATCell) &oRecognizedChamferList,
    double &oMinRecogDist,
    double &oMaxRecogDist);

