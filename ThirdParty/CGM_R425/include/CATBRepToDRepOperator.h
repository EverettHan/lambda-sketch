#ifndef CATBRepToDRepOperator_H
#define CATBRepToDRepOperator_H

#include "AdvOpeInfra.h"
#include "CATTopOperator.h"
#include "ListPOfCATManifoldNavigator.h"
#include "CATDeclarativeApplication.h"
#include "CATDeclarativeContext.h"
#include "CATDeclarativeOriginModeler.h"
#include "ListPOfCATCellManifold.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATAgentRelationNode.h"
#include "ListPOfCATDeclarativeManifoldAgent.h"

class CATBRepToDRepExtTopOperator; 
class CATDeclarativeManifoldAgent;


class ExportedByAdvOpeInfra CATBRepToDRepOperator : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATBRepToDRepOperator);
public:
	
/** @nodoc 
  * cannot be called
  */
	// Constructor
  CATBRepToDRepOperator(CATGeoFactory* iFactory, CATTopData* iTopData, CATBRepToDRepExtTopOperator* iImpl);

  // Destructor
	virtual ~CATBRepToDRepOperator();

  HRESULT AddDeclarativeManifoldAgent(CATDeclarativeManifoldAgent* &ioAgent);
  HRESULT GetDeclarativeManifoldAgents(ListPOfCATDeclarativeManifoldAgent &oAgents);

  // @nocgmitf
  //void GetNavigators(ListPOfCATManifoldNavigator &ioNavigators);

  HRESULT GenerateBaseAgents(CATDeclarativeApplication iAppli, CATDeclarativeContext& iContext, CATDeclarativeOriginModeler iModeler);
  
  HRESULT GenerateMandatoryAgents(CATDeclarativeApplication iAppli, CATDeclarativeContext& iContext, CATDeclarativeOriginModeler iModeler, ListPOfCATAgentRelationNode& iMandatoryNodes, ListPOfCATAgentRelationNode& iForbiddenNodes);

  void SetUserDefinedSelection(ListPOfCATFace &iUserSelection);

  // For debug only, internal CGM only
  // @nocgmitf
  void SetOverWriteTheInputBody(CATBoolean iOverWriteTheInputBody);

  // ---------------------------
  // Industry Assistant Methods
  // ---------------------------
  // The Set has to be done before the Get Method.
  void SetCandidateIndustryList(CATListOfInt & iCandidateIndustryList);
  // Return the recommended industries among the candidate industries.
  void GetRecommendedIndustryList(CATListOfInt & oRecommendedIndustryList);
  // The iIndustry has to be among the candidate industries.
  void GetLostFilletList (CATDeclarativeContextIndustry   iIndustry,
                          ListPOfCATCell                & oLostFilletList,
                          double                        & oMinLostRadius,
                          double                        & oMaxLostRadius);
  // The iIndustry has to be among the candidate industries.
  void GetRecognizedFilletList (CATDeclarativeContextIndustry   iIndustry,
                          ListPOfCATCell                & oRecognizedFilletList,
                          double                        & oMinRecogRadius,
                          double                        & oMaxRecogRadius);
  // The iIndustry has to be among the candidate industries.
  void GetLostChamferList(CATDeclarativeContextIndustry   iIndustry,
                          ListPOfCATCell                & oLostChamferList,
                          double                        & oMinLostDistance,
                          double                        & oMaxLostDistance);
  // The iIndustry has to be among the candidate industries.
  void GetRecognizedChamferList (CATDeclarativeContextIndustry   iIndustry,
                          ListPOfCATCell                & oRecognizedChamferList,
                          double                        & oMinRecogDist,
                          double                        & oMaxRecogDist);

  // ------------------
  // CGMReplay Methodes
  // ------------------
  // @nocgmitf
  static const CATString *GetDefaultOperatorId();
  // @nocgmitf
  const CATString * GetOperatorId();
  // @nocgmitf
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  // @nocgmitf
  void WriteInput(CATCGMStream  & Str);
  // @nocgmitf
  void Dump( CATCGMOutput& os ) ;
  // @nocgmitf
  void DumpOutput(CATCGMOutput &os);
  // @nocgmitf
  void RequireDefinitionOfInputAndOutputObjects();
  /** @nodoc @nocgmitf */
  CATBoolean ValidateTopOutput(CATTopCheckJournal* iEquivalent, CATCGMOutput& os);
	
protected:
  virtual int RunOperator();

  CATBRepToDRepExtTopOperator * GetBRepToDRepOperatorImpl();
};

// ----------------------------
// CATCreateBRepToDRepOperator creation method.
// Release iContext after use.
// ----------------------------
ExportedByAdvOpeInfra CATBRepToDRepOperator * CATCreateBRepToDRepOperator(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iBody, 
                                                                          CATDeclarativeApplication iAppli, CATDeclarativeContext& iContext, CATDeclarativeOriginModeler iModeler); 

// ----------------------------
// Old creation method for CATCreateBRepToDRepOperator
// Soon Deprecated
// ----------------------------
ExportedByAdvOpeInfra CATBRepToDRepOperator * CATCreateBRepToDRepOperator(CATGeoFactory* iFactory, CATTopData* iTopData, CATBody* iBody); 


#endif
