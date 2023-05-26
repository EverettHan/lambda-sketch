#ifndef  CATICkeRelation_H
#define  CATICkeRelation_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */

/*  CAA2Reviewed by FRH */

// module declaration
#include "KnowledgeItf.h"

// Inherited from
#include "CATICkeNaming.h"

// forwards
#include "CATICkeRelationForwards.h"


// interface used
#include "CATIParmPublisher.h"
#include "CATICkeParm.h"
#include "CATICkeArg.h"

// OLE
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByKnowledgeItf IID_CATICkeRelation;
#else
extern "C" const IID IID_CATICkeRelation;
#endif

/**   
 * Interface dedicated to Knowledge relations management.
 * <b>Role</b>: A relation is an oriented link stored between persistent parameters.<br>
 * It manages the propagation of input modifications to outputs.<br>
 * A parameter can be a literal, a list feature, a geometric datum or a reference to a persistent feature.<br>
 * This interface is implemented on relations.
 * @see CATICkeParm
 */
class ExportedByKnowledgeItf CATICkeRelation : public CATICkeNaming
{

  CATDeclareInterface;

public:


/**
 * Clears the links to all parameters.
 * Do not use this method on expressional relations.
 */
virtual void    ClearParameters () = 0;

/**
 * Add a parameter in Input or Output.
 * (deactivates relation)<br>
 * @param  iParameter parameter to add
 * @param  iMode <br><b>Legal values</b>: the mode can be either
 * <tt>In</tt> when parameter will be used as an input.
 * <tt>Out</tt> when parameter will be used as an output.
 * Do not use this method on expressional relations.
 * The parameter must be in the same container as the relation. This rule will be enforced in a future release to enable only authorized data models.
 */
virtual void    Add (const CATICkeParm_var &iParameter,const CATICkeArg::Mode iMode) = 0;

/**
 * Suppresses a link to a given parameter in Input or Output.
 * (deactivates relation) <br>
 * Do not use this method on expressional relations.
 * @param  iParameter parameter to suppress
 */
virtual void    Suppress (const CATICkeParm_var &iParameter) = 0;

/**
 * Replaces a parameter by another.
 * (keep the order and mode)
 * @param  iParameterToReplace parameter that is replaced
 * @param  iReplacingParameter parameter that replaces the other
 * Do not use this method on expressional relations.
 * The parameter must be in the same container as the relation. This rule will be enforced in a future release to enable only authorized data models.
 */
virtual void    Replace (CATICkeParm_var &iParameterToReplace,CATICkeParm_var &iReplacingParameter) =0;


/**
 * Returns the list of all parameters linked. 
 * @return list of all parameters (not to be deallocated)
 */
virtual CATCkeListOfParm Parameters    () const = 0;

/**
 * Returns the list of parameters linked in output. 
 * @return list of parameters in output (not to be deallocated)
 */
virtual CATCkeListOfParm OutParameters () const = 0;

/**
 * Returns the list of parameters linked in input.
 * @return list of parameters in input (not to be deallocated)
 */
virtual CATCkeListOfParm InParameters  () const = 0;


//--------------------------------------------------
// synchronous mode of update
//--------------------------------------------------

/**
 * Indicates if update will be synchronous or not.
 * @return <br><b>Legal values</b>: the test can be either
 * <tt>CATCke::True</tt> if is is synchronous
 * <tt>CATCke::False</tt> if it isn't.
 */
virtual CATCke::Boolean IsSynchronous() const = 0;

/**
 * Defines if update will be synchronous or not.
 * @param iSynchronous
 * <br><b>Legal values</b>: the test can be either
 * <tt>CATCke::True</tt> if is is synchronous
 * <tt>CATCke::False</tt> if it isn't.
 */
virtual void    SetSynchronous (const CATCke::Boolean &iSynchronous) = 0;


//--------------------------------------------------
// Update 
//--------------------------------------------------

/**
 * Indicates if the relation can be evaluated.<br>
 * This method may raise syntax error (CATCkeParseException). No ability to catch them in CAA.<br>
 * @return <br><b>Legal values</b>: the test can be either
 * <tt>CATCke::True</tt> if it can be evaluated
 * <tt>0</tt> if it can't.
 */
virtual CATCke::Boolean CanBeEvaluated () const = 0;

/**
 * Evaluates the relation.
 * This method may raise evaluation error (CATLifEvaluationError). No ability to catch them in CAA.<br
 * @return <br><b>Legal values</b>: 
 * <tt>CATCke::True</tt> if evaluation is Ok
 * <tt>CATCke::False</tt> if evaluation is Ko.
 */
virtual CATCke::Boolean Evaluate() = 0;

/**
 * Indicates if the relation is updated.
 * @return <br><b>Legal values</b>: 
 * <tt>CATCke::True</tt> if it is already updated
 * <tt>CATCke::False</tt> if it must be updated.
*/
virtual CATCke::Boolean IsUpdated () const = 0;


/**
 * @nodoc to be suppressed
 * Indicates to the relation that a parameter in input has been modified.
 * Way to simulate a modification also.
 * @param iInputParameter parameter modified
 */
virtual void              SetNotUpdated (const CATICkeParm_var &iInputParameter  = NULL_var) = 0;

/**
 * @nodoc to be suppressed
 * Returns the list of currently modified parameters since last update.
 * @return list of literals modified since last update (list to be deallocated)
 */
virtual CATCkeListOfParm  ModifiedParms () const = 0;





/**
 * @nodoc to be suppressed
 * Use KnowledgeInterfaces CATIKweActivable::SetActivationStatus method.  
 * Activates the relation. 
 * This method may raise activation error (CATKWELifLoopDetected). No ability to catch them in CAA.<br>
 */
virtual void    Activate() = 0;

/**
 * @nodoc to be suppressed
 * Use KnowledgeInterfaces CATIKweActivable::SetActivationStatus method.  
 * Deactivates the relation.
 */
virtual void    Desactivate() = 0;

/**
 * @nodoc to be suppressed
 * Use KnowledgeInterfaces CATIKweActivable::IsActivated method.  
 * Tests if the relation is activated.
 * @return 
 * <br><b>Legal values</b>: 
 * <tt>CATCke::True</tt> if it is activated
 * <tt>CATCke::False</tt> if it isn't.
 */
virtual CATCke::Boolean IsActivated() const = 0;

/**
 * @nodoc to be suppressed
 * Use KnowledgeInterfaces CATIKweActivable::ActivityFacet method.  
 * Returns the parameter managing relations activity.
 * @return activity (Boolean literal)
 */
virtual CATICkeParm_var    ActivityFacet () const = 0;

/**
 * Returns the root of the relation.
 * A relation knows a root of object.<br>
 * This root is the place in which the relation can find its parameters.<br>
 * It corresponds in fact to the SpecObject where the relation is agregated.<br>
 * (to be more precise, it corresponds to the owner of the relation set)<br>
 * the root can be null
 */
virtual CATIParmPublisher_var Root () const = 0;



/**
 * Indicates if the relation is Broken.<br>
 * Broken means that it cannot be runned.<br> 
 * 2 reasons for that: an operator doesn't exist anymore in our session b/c of licensing<br>
 * or a parameter has been lost in multi-document context<br>
 * @return <b>Legal values</b>: the test can be either
 * <tt>CATCke::True</tt> if it is broken
 * <tt>CATCke::False</tt> if it isn't.
 */
virtual CATCke::Boolean IsBroken () const = 0;

 
/**
* @nodoc to be suppressed
*/
virtual CATCkeListOfParm ParametersAndPubs    () const = 0;
/**
* @nodoc to be suppressed
*/
virtual CATCkeListOfParm OutParametersAndPubs () const = 0;
/**
* @nodoc to be suppressed
*/
virtual CATCkeListOfParm InParametersAndPubs  () const = 0;

/**
 * Defines if the relation will be evaluated during the update process.
 * This can only be done if your relation is in a part document.
 * @param iYesOrNo <br><b>Legal values</b>:  
 * <tt>S_OK</tt> The relation has been integrated to update.
 * <tt>CATCke::False</tt> The relation has not been integrated to update.
 * @return <br><b>Legal values</b>: 
 * <tt>0</tt> The relation will not be integrated to update.
 * <tt>1</tt> The relation will be integrated to update.
 */
virtual HRESULT IntegrateToUpdateProcess(const int& iYesOrNo) const = 0;

/**
 * Indicates if the relation is evaluated during the update process.
 * @return <br><b>Legal values</b>: 
 * <tt>1</tt> The relation is integrated to update.
 * <tt>0</tt> The relation is not integrated to update.
 */
virtual int IsIntegratedToUpdateProcess() const = 0;


};

CATDeclareHandler(CATICkeRelation,CATICkeNaming);


#endif


