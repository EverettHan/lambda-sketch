#ifndef  CATICkeRelationExp_H
#define  CATICkeRelationExp_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */

/*  CAA2Reviewed by FRH */

// module declaration
#include "KnowledgeItf.h"

//Inherited from
#include "CATICkeRelation.h"
#include "CATIParmPublisher.h"

// forwards
class CATICkeExpression_var;



// OLE
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATICkeRelationExp;
#else
extern "C" const IID IID_CATICkeRelationExp;
#endif



/**   
 * Interface dedicated to Knowledge relations with textual body management (formulas/Checks/Rules).
 * <b>Role</b>: An expressional relation is a relation whose links between parameters is defined 
 * by a language contained in a text.<br>
 * - Formulas valuate one parameter from several ones.<br>
 * - Rules valuate several parameters from several ones.<br>
 * - Checks use several parameters in input and produces a diagnosis.<br>
 * - Set of equations use several parameters from several ones.
 * This interface is implemented on those 3 objects<br>
 * This interface is multi implemented.
 * @see CATICkeRelation
 */
class ExportedByKnowledgeItf CATICkeRelationExp : public CATICkeRelation
{

  CATDeclareInterface;

public:

/**
 * Modifies the body and the list of parameters.<br>
 * Watch out: to use this service, you need to have the Knowledge Advisor license at runtime for rules, check, set of equation edition.<br> 
 * This method may raise syntax error (CATCkeParseException). No ability to catch them in CAA.<br>
 * This method may raise evaluation error (CATLifEvaluationError). No ability to catch them in CAA.<br>
 * @param  iListParameters list of parameters that can be used in the body
 * @param  iBody string describing the body
 * @param  iRoot used to name parameters with RelativeName (root) method <br>
 *                     and so to be able to recognize parameters by their name<br>
 *                     Not used in realnames = false mode<br>
 * @param iRealnames  = 2 possibilities to name a parameter in the body.
 * <br><b>Legal values</b>:
 * <tt>CATCke::True</tt> names used are the one returned by RelativeName (root) and we try to recognize names used in the body with parameters of iListParameters..
 * <tt>CATCke::False</tt> names used are a1,a2,a3,etc...<br>
 *                        a1 meaning the first parameter of iListParameters, a2, the second one, etc....<br>
 * We advise you strongly to use this second method in your application to avoid NLS problems . 
 * <p>
 * @return true if parse OK, false instead.<br>
 * if a syntax error occurs, a CATCkeParseException exception is raised in realname=true
 * else a CATLifError is "raised" that you can catch with CATLifErrorManager services
 * The parameters referenced must be in the same container as the relation. This rule will be enforced in future releases to allow the definition 
 * of only supported models
 */
	virtual CATCke::Boolean Modify (const CATCkeListOfParm      iListParameters,
							        const CATUnicodeString     &iBody,
								    const CATIParmPublisher_var  &iRoot = NULL_var,
									const CATCke::Boolean      &iRealnames = 1) = 0;

/**
 * Get the relations body.
 * @param  iReCompute true if body is to be recomputed
 * @param  iRoot used to name parameters with RelativeName (root) method 
 * @return body
 */
virtual CATUnicodeString       Body (const CATCke::Boolean &iReCompute = 0,
				   const CATIParmPublisher_var &iRoot = NULL_var) const = 0;


/**
 * @nodoc to be suppressed
 */
virtual void Update (const CATICkeExpression_var  &rule, 
		       CATCkeListOfParm LstParam,
		       const CATCke::Boolean shared = 0) = 0;
 
/**
 * @nodoc to be suppressed
 */virtual CATICkeSignature_var Signature() = 0;

/**
 * @nodoc no equivalent. Not usable.
 * Returns the underlying expression.
 */
virtual CATICkeExpression_var      Expression () const = 0;



/**
 * Checks magnitude coherence.<br> 
 * This method may raise syntax errors (CATCkeErrorMKS). No ability to catch them in CAA.<br>
 * @return <br><b>Legal values</b>: the test can be either
 * <tt>CATCke::True</tt> if magnitude coherence is Ok
 * <tt>CATCke::False</tt> if it isn't.
 */
virtual CATCke::Boolean  CheckMagnitude () const = 0;

/**
* @nodoc
* Integrates this relation to update.
* <br><b>Role:</b>: for relations using features, relations are not synchroneous and so are not immediately updated
* when an inputs changes. This method allows to have this sort of relation updated along the part.<br>
* Restriction : This method works only for relations embedded in a part, and using features
* @param yes
* if equal to 0 : removes integration to part update, if not : integrates to part update
* @return
* S_OK if the method succeeds, E_FAIL else 
*/
	virtual HRESULT IntegrateToUpdate(int yes) = 0;

/**
* @nodoc
* Tests if the relation is integrated with part update.
* @return
*	1 if true , else 0
*/
	virtual int IsIntegratedToUpdate() = 0;

/**
* Defines if the relation will catch evaluation error.
* @param yes
*	equal true if you want to catch evaluation error
*/
	virtual void CatchEvaluationError(int yes) = 0;

/**
* Indicates if an evaluation error has been caught.
* @return
*	1 if true , else 0
*/
	virtual int IsEvaluationErrorCatched() = 0;
};


CATDeclareHandler(CATICkeRelationExp,CATICkeRelation);


#endif
