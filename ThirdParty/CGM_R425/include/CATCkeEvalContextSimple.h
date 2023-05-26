// Copyright Dassault Systemes 2000
#ifndef CATCkeEvalContextSimple_h
#define CATCkeEvalContextSimple_h


#include "CATLifExpressions.h"
#include "CATOmbLifeCycleRootsBag.h"
class CATSoftwareConfiguration;

// include module definition
#include "CATCkeEvalContext.h"
class CATCkeFvar;
class CATICkeObject_var;
class CATIInstance_var;
class CATKWEError;

// S56 Progress Bar
//class CATIKnowledgeProgressBarMath;
//class CATIKnowledgeProgressBarDialog;

#include "CATIKnowledgeProgressBarMath.h"
#include "CATIKnowledgeProgressBarDialog.h"

#include "CATIParmPublisher.h"
#include "CATListOfInt.h"
#include "CATListOfCATBoolean.h"

/**
 * Interface dedicated to evaluation context information management.
 * <b>Role</b>: When a relation is evaluated, it creates such an object that is known by all the evaluators of the expression tree.<br>
 * Those evaluators can then use this context to know the container or relation for example<br>
 */
class ExportedByCATLifExpressions CATCkeEvalContextSimple : public CATCkeEvalContext
{

public:

  /**
     * @nodoc
   */
  CATCkeEvalContextSimple(const int iPreventObjectModification = 0, const int iBRContext = 0,
    const CATCkeEvalContext::SourceKind iSourceKind = CATCkeEvalContext::Undefined);

  // Constructor used when called from CATICkeFunctionFactory::CreateEvaluationContext
  CATCkeEvalContextSimple(const CATIParmPublisher_var& root,			 // Source of evaluation
    const int iPreventObjectModification = 0,	 // Indicates that we do not allow object modification
    const int iBRContext = 0,                   // BR Context: yes/no
    const CATCkeEvalContext::SourceKind iSourceKind = CATCkeEvalContext::Undefined);

  /**
     * @nodoc
   */
  virtual ~CATCkeEvalContextSimple();

  /**
     * @nodoc
   */
  CATCkeEvalContextSimple(const CATCkeEvalContextSimple&);

  /**
     * Returns the current relations.
   */
  virtual CATICkeRelation_var Relation() const;

  /**
     *  Returns the objet source of the error (relation was too restrictive).
   */
  virtual CATICkeNaming_var Source() const;

  /**
     *  Returns the objet source of the error (CATICkeNaming was too restrictive).
   */
  virtual CATICkeObject_var SourceAsObject() const;

  /**
     * Returns the current container.
   */
  virtual CATICkeParmFactory_var   Container() const;

  /**
  * Expressional relations allow datum geometry valuation (for example: point.1 = point(0mm, 10mm, 20mm)).
  * To enable such a functionality, functions have to return temporary geometry whose geometrical result is to
  * be copied into the datum. This temporary geometry life cycle can not be managed by function code because
  * the returned object can be used several times in the expression, so it has to be valid until the end of the expression
  * evaluation. This method allows to solve this problem: the relation stores the temporary geometry and manages itself
  * its life cycle. It is mandatory to call this method for any returned geometry that is created inside a function.
  * Note that if the function needs to create several geometrical features, it has either to delete them before returning result or
  * to call StoreAndUpdateTemporaryObject for each of them.
  * <b>This method updates argument (and possibly raises an error), so caller should not do it himself</b>
  * @param iObject
  * the temporary object whose life cycle has to be managed by the relation
  * @return
  * E_FAIL if object is NULL_var or is aggregated, S_OK otherwise
  */
  virtual HRESULT StoreAndUpdateTemporaryObject(const CATBaseUnknown_var& iObject);

  //---------------------------------------------------------------
  //** 
// * how to manage the temporary objects used in operators ? The operators produce some
// * objects that will have to be stored as components of the relation,
// * 
// * At the beginning of an evaluation, the list of previous temporary objects is given to the EvalContext
// * case 1 - In the operator, if the resulting parameter is set, the operator developer must check that 
// * the resulting value is of good type and can be the output of the evaluator. 
// * If he agrees the choice, he must use the Keep method to indicate that he wants to keep this object
// *
// * case 2 - If the resulting parameter is not set, he can ask for it to see if the object has been created before.
// * (using the Ask method). If the Ask method returns a value we're back to case 1. If not, it's case 3
// *
//* case 3 - The operator developer creates an object. To indicate he wants to keep it in the relation
// * he uses the Keep Method
// */
//---------------------------------------------------------------

 /**
  * @nodoc
  */
  virtual void               Keep(const CATBaseUnknown_var&) const;

  /**
   * @nodoc
   */
  virtual CATBaseUnknown_var Ask() const;

  /**
   * @nodoc
   */
  virtual void Start(CATLISTV(CATBaseUnknown_var)& beginning, CATLISTV(CATBaseUnknown_var)& ending);

  /**
 * @nodoc
 */
  virtual CATCke::Boolean NoChange() const;

  /**
   * @nodoc
   */
  virtual CATCke::Boolean TryToFindOutput(const CATICkeParm_var& res, CATBaseUnknown_var& spec) const;

  /**
   * @nodoc
   */
  virtual void UpdateAndKeep(const CATBaseUnknown_var& spec) const;


  /**
   * @nodoc
   */
  virtual void SetAttrInfo(const CATUnicodeString& s, const AttributeAccess aa);

  /**
   * @nodoc
   */
  virtual void GetAttrInfo(CATUnicodeString&, AttributeAccess&) const;

  /**
   * @nodoc
   */
  virtual void SetSignature(const CATICkeSignature_var& iSig);

  /**
   * @nodoc
   */
  virtual CATICkeSignature_var GetSignature() const;


  // S56 Progress Bar
  virtual CATIKnowledgeProgressBarDialog_var GetProgressBarDialog() const;
  virtual CATIKnowledgeProgressBarMath_var GetProgressBarMath() const;
  virtual void SetProgressBar(CATIKnowledgeProgressBarDialog_var ispProgressBarDialog, CATIKnowledgeProgressBarMath_var ispProgressBarMath);

  /**
  * Send Error.
  *
  * @param iMessage Message.
  * @param iSeverity Severity.
  * @param iSource Source
  */
  virtual HRESULT SendError(const CATUnicodeString& iMessage = " ",
    const CATKWEErrorSeverity::Severity		iSeverity = CATKWEErrorSeverity::Information,
    const CATBaseUnknown_var& iSource = NULL_var)const;


  virtual void ValuateResult(const CATBaseUnknown_var& p, CATBoolean iMarkDatum = FALSE);
  void SetOutputFvar(const CATCkeFvar*);
  CATCkeFvar* GetOutputFvar();


  // Pour recuperer la configuration de la relation
  virtual CATSoftwareConfiguration* GetConfiguration();


  /**
     * Returns the current root if any. The root is used to compute object path when we want to raise errors and
   * show the path of the objects
   * may be NULL
   */
  virtual CATIParmPublisher_var Root() const;

  /**
     *  Indicates if the evaluation prevents object modification
   */
  virtual boolean  PreventsObjectModification() const { return (_preventObjectModification == 0) ? FALSE : TRUE; };

  /**
     *  Indicates if the evaluation is done thru a business rule
   */
  virtual boolean  BusinessRulesContext() const { return (_BRContext == 0) ? FALSE : TRUE; };

  virtual void SetLineno(const int& iLineno);
  virtual int GetLineno()const;

  /**
     *  Sets the current container
   */
  virtual   void SetContainer(const CATICkeParmFactory_var& iContainer);

  /**
     *  Clear intermediate features
   */
  virtual   void ClearIntermediates();


  virtual CATCkeEvalContext::SourceKind GetSourceKind() const;

  virtual void SetBag(CATOmbLifeCycleRootsBag* iBag);
  virtual CATOmbLifeCycleRootsBag* GetBag();

  void DisableErrors(CATBoolean iIgnoreErrs, CATBoolean iIgnoreWarns, CATBoolean iIgnoreInfos/*, const CATListOfCATUnicodeString &iIgnoredFuncs*/);
  void EnableErrors();
  void GetErrorOptions(CATBoolean& oIgnoreErrs, CATBoolean& oIgnoreWarns, CATBoolean& oIgnoreInfos/*, CATListOfCATUnicodeString &oIgnoredFuncs*/);
  void StartFunction(const CATUnicodeString* iFunction, CATBoolean isRelevantForStack = FALSE, int lineno = -1);
  void EndFunction(CATBoolean isRelevantForStack = FALSE);
  CATUnicodeString GetCurrentFunction();
  CATListOfInt GetStackLinesNos();
  CATListOfCATUnicodeString GetStackNames();
  CATBoolean HasAlreadyBeenUsedProxy(const CATIInstance_var& iProxy);
  void StoreProxyAsUsed(const CATIInstance_var& iProxy);

  void OptimizeComputationPerformance();


  /**
   * Returns TRUE if the debug is currently disabled
   *         FALSE otherwise
   */
  virtual CATBoolean IsDebugDisabled() const;
  virtual void SetDebugDisabled(CATBoolean iDebugDisabled);

  virtual void DisableUndo();


  void StartLoop();
  int IsLooping();
  void EndLoop();
  void BreakLoop();
  void ContinueLoop();
  virtual void CallExit();
  virtual void CallUnexit();
  CATBoolean IsLoopBroken();
  CATBoolean IsLoopContinued();
  void EndLoopIteration();
  virtual CATBoolean ShouldJumpInstruction();
  void AddToLoggedErrors(CATKWEError* iError);
  CATBoolean HasAlreadyBeenLogged(CATKWEError* iError);

  CATBoolean IsLineNumDisabled();
  void DisableLineNumbers(const CATBoolean& line);

  CATBoolean IsFunctionNameDisabled();
  void DisableFunctionName(const CATBoolean& line);

  void CallExitFunction();
  void CallUnexitFunction();

  int GetDeleteWebServiceStatus();
  void SetDeleteWebServiceStatus(const int& ibAllowDeleteWebService);

  CATBoolean CheckPreexistingInNewFunction() { return _CheckPreexistingInNewFunction; };
  void CheckPreexistingInNewFunction(CATBoolean iCheck) { _CheckPreexistingInNewFunction = iCheck; };

private:
  void InitRandSeed();

  // attribute name & access
  CATUnicodeString attrname_;
  AttributeAccess  attraccess_;

  CATICkeSignature_var sig_;

  CATCkeFvar* OutputFvar_;
  int _lineno;

  CATIParmPublisher_var _root;
  int _preventObjectModification;
  int _BRContext;
  CATCkeEvalContext::SourceKind _sourceKind;

  CATOmbLifeCycleRootsBag* _bag;
  // If no bag is given to the context from the outside, it still has one to perform opening queries when needed
  // Beware though, this bag will not survive the end of the evaluation, thus all objects
  // hold by the bag will be lost if they have not been bagged somewhere else.
  CATOmbLifeCycleRootsBag _localBag;

  int _manualErrorHandling;
  CATListPV _FunctionNamesStack;
  CATListPV _RelevantFunctionNamesStack;
  CATListOfInt _RelevantFunctionLineNoStack;
  //  CATListPV _IgnoredFunctionsStack;
  //  CATListOfInt _NumberOfIgnoredFunctionsStack;
  CATListOfCATBoolean _ShouldIgnoreErrorsStack;
  CATListOfCATBoolean _ShouldIgnoreWarningsStack;
  CATListOfCATBoolean _ShouldIgnoreInfosStack;
  CATLISTV(CATBaseUnknown_var) _AlreadyUsedProxies;

  int _IsLooping;
  CATBoolean _IsLoopBroken;
  CATBoolean _IsLoopContinued;
  CATListPV _LoggedErrors;
  CATBoolean _DebugDisabled;
  static int _DetectRecursivity;
  CATBoolean _UndoDisabled;

  CATBoolean _disabledLineNum;
  CATBoolean _disableFunctionOrigin;

  // S56 Progress Bar
  CATIKnowledgeProgressBarDialog_var _spProgressBarDialog;
  CATIKnowledgeProgressBarMath_var _spProgressBarMath;

  // 0 : Status Not set, 1 : Allow Delete, 2 : Block Delete.
  int _iDeleteWebServiceStatus;

  CATBoolean _CheckPreexistingInNewFunction;
protected:
  CATBaseUnknown_var _container;
  CATBoolean _ComputationPerformanceActivated;
  CATBoolean _ExitCalled;
  CATBoolean _ExitFunctionCalled;

private:
  bool _bBagSetByDPC;
};

#endif
