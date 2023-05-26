#ifndef CATCkeEvalContext_h
#define CATCkeEvalContext_h


// COPYRIGHT DASSAULT SYSTEMES 1999
  
/** 
 * @CAA2Level L1
 * @CAA2Usage U1 
 */

/*  CAA2Reviewed by FRH */

// include module definition
#include "CATLifSpecs.h"
#include "CATKWEErrorSeverity.h"

// forwards
#include "CATICkeRelationForwards.h"
#include "CATICkeRelation.h"
#include "CATICkeSignature.h"
class CATSoftwareConfiguration;
class CATIParmPublisher_var;
class CATICkeObject_var;
class CATICkeNaming_var;

class CATICkeParmFactory_var;


/**   
 * Class dedicated to evaluation context information management.
 * <b>Role</b>: When a Knowledge relation or a Knowledge expression is evaluated, it creates such an object that is known by all the evaluators of the expression tree.<br>
 * Those evaluators can then use this context to know the container or relation for example.<br>
 */
class ExportedByCATLifSpecs CATCkeEvalContext
{

public:

	/**
     * @nodoc to be exposed
	 */
	CATCkeEvalContext ();

	/**
     * @nodoc to be exposed
	 */
	virtual ~CATCkeEvalContext ();

	/**
     * @nodoc to be exposed
	 */
    CATCkeEvalContext (const CATCkeEvalContext &);

	/**
     *  Returns the current relation if any.
	 */

	virtual CATICkeRelation_var Relation () const =0;

	/**
     *  Returns the objet source of the error (relation was too restrictive).
	 */
	virtual CATICkeNaming_var Source () const =0;
	
	/**
     *  Returns the objet source of the error (CATICkeNaming was too restrictive).
	 */
	virtual CATICkeObject_var SourceAsObject () const =0;

	/**
     *  Returns the current container if any.
	 */
    virtual CATICkeParmFactory_var   Container () const =0;

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
	virtual HRESULT StoreAndUpdateTemporaryObject(const CATBaseUnknown_var &iObject) = 0;

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
	  * @nodoc to be exposed
	  */
     virtual void               Keep (const CATBaseUnknown_var &) const=0;

	 /**
	  * @nodoc to be exposed
	  */
	 virtual CATBaseUnknown_var Ask  () const =0;

	 /**
	  * @nodoc to be suppressed
	  */
	 virtual void Start (CATLISTV(CATBaseUnknown_var) &beginning,CATLISTV(CATBaseUnknown_var) &ending)=0;  

     /**
	  * @nodoc to be suppressed
	  */
	 virtual CATCke::Boolean NoChange () const=0;

	 /**
	  * @nodoc to be exposed
	  */
	 virtual CATCke::Boolean TryToFindOutput (const CATICkeParm_var &res,CATBaseUnknown_var &spec) const =0;

 	 /**
	  * @nodoc to be exposed
	  */
     virtual void UpdateAndKeep (const CATBaseUnknown_var &spec) const =0;

	 /**
	  * @nodoc to be suppressed
	  */
	 enum AttributeAccess { ReadAttribute,WriteAttribute};

	 /**
	  * @nodoc to be suppressed
	  */
	 virtual void SetAttrInfo (const CATUnicodeString &s,const AttributeAccess aa)=0;

	 /**
	  * @nodoc to be suppressed
	  */
	 virtual void GetAttrInfo (CATUnicodeString &,AttributeAccess &) const=0;

	 /**
	  * @nodoc to be suppressed
	  */
	 virtual void SetSignature (const CATICkeSignature_var &iSig)=0;

	 /**
	  * @nodoc to be suppressed
	  */
	 virtual CATICkeSignature_var GetSignature () const=0;

	/**
	* Send Error. To be used in the definition of user functions.
	*
	* @param iMessage Message. Must be NLS.
	* @param iSeverity Severity.
	* @param iSource Source
	* @return classic HRESULT
	*/
	virtual HRESULT SendError (const CATUnicodeString&			iMessage	= " ", 
		const CATKWEErrorSeverity::Severity					iSeverity	= CATKWEErrorSeverity::Information,
        const CATBaseUnknown_var&		iSource		= NULL_var) const =0;

	/**
	* @nodoc to be suppressed
	*/

	virtual CATSoftwareConfiguration* GetConfiguration() = 0;

	/**
     * Returns the current root if any. The root is used to compute object path when we want to raise errors and show the path of the objects.
	 * May be NULL
	 * @return The current root if any.
	 */
	virtual CATIParmPublisher_var Root () const =0;

	/**
     *  Indicates if the evaluation prevents object modification.
	 * @return TRUE is the evaluation prevents object modification.
	 */
	virtual boolean  PreventsObjectModification () const =0;
	
	/**
	* Indicates if the evaluation is done in Business Rule context.
	 * @return TRUE is the evaluation is done in the business rule context.
	*/
	virtual boolean BusinessRulesContext() const =0;

	/**
     * Sets the current container.
	 * @param iContainer container that becomes the current one.
	 */
    virtual   void SetContainer (const CATICkeParmFactory_var &iContainer)  =0;

	/**
     *  Clear intermediate features.
	 */
    virtual   void ClearIntermediates ()  =0;

	/**
	 * Enumerated value that defines which kind of Knowledge object .<br>
	 * @param Undefined
 	 * The source is undefined.
	 * @param Formula
	 * The source is a formula.
	 * @param Law
	 * The source is a Law.
	 * @param Rule
	 * The source is a Knowledge Advisor rule.
	 * @param Check
	 * The source is a Knowledge Advisor check.
	 * @param Reaction
	 * The source is a Knowledge Advisor reaction or an action.
	 * @param SetOfEquations
	 * The source is a Knowledge Advisor set of equation.
	 * @param Pattern
	 * The source is a Product Knowledge Template pattern.
	 * @param OptimizationConstraint
	 * The source is a Product Engineering optimizer optimization constraint.
	 * @param ConstraintSatisfaction
	 * The source is a Product Engineering optimizer constraint satisfaction.
	 * @param ExpertRule
	 * The source is a Knowledge Expert rule.
	 * @param ExpertCheck
	 * The source is a Knowledge Expert check.
	 * @param UIEvent
	 * The source is a UI Event (Knowledge Based Dialogs).
	 * @param Behavior
	 * The source is a Behavior(Engineering process automation).
	 * @param Method
	 * The source is a Method(Engineering process automation).
	 * @param BusinessRules
	 * The source is a business rules.
	 * @param Expression
	 * The source is a simple expression.
	 */
	  enum SourceKind { Undefined, Formula, Law, Rule, Check, Reaction, SetOfEquations, Pattern, OptimizationConstraint, ConstraintSatisfaction, 
						ExpertRule, ExpertCheck, UIEvent, Behavior, Method, BusinessRules, Expression, Generative, Graph};
	
	/**
   	 * Returns the source kind.
	 *
	 * @return Source kind
	 */
	  virtual CATCkeEvalContext::SourceKind GetSourceKind () const =0;

	  
	  /**
	  * Some instances (objects) are locked and cannot be modified.
	  * Default implementation returns S_FALSE
	  * @param iObject object that we want to test
	  * @return S_TRUE is the instance is locked, S_FALSE instead.
	  */
      virtual HRESULT IsInstanceLocked(const CATBaseUnknown_var &iObject) ;

};

#endif
