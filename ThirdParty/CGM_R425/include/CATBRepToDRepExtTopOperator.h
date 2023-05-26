#ifndef CATBRepToDRepExtTopOperator_H
#define CATBRepToDRepExtTopOperator_H

#include "CATPersistentExtTopOperator.h"
#include "AdvOpeInfra.h"

#include "CATBody.h"
#include "ListPOfCATDeclarativeManifoldAgent.h"
#include "ListPOfCATManifoldNavigator.h"
#include "CATManifoldNavigator.h"
#include "CATRecognizerContext.h"
#include "ListPOfCATCellManifold.h"
#include "CATGMLiveShapeIndustryAssistantOpe.h"

class CATGeoFactory;
class CATTopData;
class CATString;
class CATDeclarativeManifoldAgent;


class ExportedByAdvOpeInfra CATBRepToDRepExtTopOperator : public CATPersistentExtTopOperator
{
public:
  
/** @nodoc 
  * cannot be called
  */
  // Constructor
  CATBRepToDRepExtTopOperator(CATGeoFactory &iFactory, CATTopData &iTopData, CATBody &iInputBody);
  
  //------------------------
  // Surcharge du new/delete
  //------------------------
  CATCGMNewClassArrayDeclare;


  HRESULT AddDeclarativeManifoldAgent(CATDeclarativeManifoldAgent* &ioAgent);
  HRESULT GetDeclarativeManifoldAgents(ListPOfCATDeclarativeManifoldAgent &oAgents);

  // Runs the operator
   virtual int RunPersistentOperator();

  // IZE wk. 25 2010
  //Init Methods for Tolerance & Recognizer parameters
  void SetRecognizerContext(CATRecognizerContext *iContext);
  CATRecognizerContext *GetRecognizerContext();

  // For Local Recognition
  void SetUserDefinedSelection(ListPOfCATFace &iUserSelection);
  void GetUserDefinedSelection(ListPOfCATFace &ioUserSelection);

  void SetFeaturesToRedeclare(ListPOfCATManifoldNavigator &iFeaturesToRedeclare);
  void GetFeaturesToRedeclare(ListPOfCATManifoldNavigator &ioFeaturesToRedeclare);

  // For debug only, internal CGM only
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

  void CreateIndustryAssistantOpe();

  // ------------------
  // CGMReplay Methodes
  // ------------------
  static const CATString *GetDefaultOperatorId() { return &_OperatorId; }
  const CATString * GetOperatorId() const;
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  void WriteInput(CATCGMStream  & Str);
  void Dump( CATCGMOutput& os ) ;
  void DumpOutput(CATCGMOutput &os);
  void RequireDefinitionOfInputAndOutputObjects();

protected:
  // Destructor
  virtual ~CATBRepToDRepExtTopOperator();

private:
  // Internal Data
  CATBody& _InputBody;
  ListPOfCATDeclarativeManifoldAgent _DMAgents;
  //ListPOfCATManifoldNavigator _CreatedNavigators;
  CATRecognizerContext * _Context;

  static CATBoolean BRepToDRepForceSmartGeometryIsActive();
  CATBoolean _NavigatorsClaimed;

  // For local recognition
  ListPOfCATFace                        _UserDefinedSelection;
  ListPOfCATManifoldNavigator           _FeaturesToRedeclare;

  // For Industry Assistant
  CATListOfInt                          _CandidateIndustryList;
  CATGMLiveShapeIndustryAssistantOpe *  _IndustryAssistantOpe;

  // For Debug only, internal CGM only : to overwrite the inpputBody
  CATBoolean                            _OverWriteTheInputBody;

  // --------------------
  // Data FOR CGMReplay
  static CATString _OperatorId;
};

 INLINE void CATBRepToDRepExtTopOperator::SetOverWriteTheInputBody(CATBoolean iOverWriteTheInputBody) {
  _OverWriteTheInputBody = iOverWriteTheInputBody; }

#endif
