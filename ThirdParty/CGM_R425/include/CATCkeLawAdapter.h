// Copyright Dassault Systemes 2005
#ifndef CATCkeLawAdapter_H
#define CATCkeLawAdapter_H

#include "KnowledgeItf.h"

/** 
* @CAA2Level L1
* @CAA2Usage U2 
*/

// forwards
//#include "CATIForwardsDecl.h"
#include "CATBaseUnknown.h"
#include "CATICkeFunction.h"
class CATICkeSignature_var;
class CATCompositeLaw;
class CATICkeParm_var;


/**
* Class to be used as an adapter for objects that want to implement CATICkeLaw and CATICkeFunction interface.
*
* First of all, it is an adapter of CATICkeLaw interface. This interface is used
* to create a formal expression that can be reused in geometrical operators such as parallel curves or in Knowledge relations
*
* It is also an adapter of CATICkeFunction. This interface defines functions that can be used in Knowledge language.
*
* In addition to extension, you must create the TIE object with 
* - TIEchain_CATICkeLaw
* - TIEchain_CATICkeFunction
* @see CATICkeLaw, CATICkeFunction
*/

class ExportedByKnowledgeItf CATCkeLawAdapter : public CATBaseUnknown
{
public:
	
	/**
	 * Constructor.
	 */
	CATCkeLawAdapter();
	/**
	 * Desstructor.
	 */
	virtual ~CATCkeLawAdapter() ;
		
	//-------------------------------------------
	// Interface CATICkeLaw implementation
	//-------------------------------------------
	
	/**  Returns the function attributed to the Law.
	*@return The function.
	*/
	virtual CATICkeFunction_var GetFunction () const ;
	
	/** Returns the domain of validity of the law.
	*@param oMin Minimum limit of the domain
	*@param oMax Maximum limit of the domain
	*/
	virtual void GetDomain (double &oMin, double &oMax) const ; 
	
	/** Computes a CATCompositeLaw. 
	*@return The CATCompositeLaw.
	*/
	virtual CATCompositeLaw* ComputesCompositeLaw () const ;
	
	/** Returns the list of the formal parameters. 
	* @return The list of parameters of the law.
	*/
	virtual CATCkeListOfParm GetFormalParameters () const ;
	
	/**
	*  Adds a formal parameter to the law.
	* @param iParm The parameter to be added to the law.
	*/
	virtual	void AddFormalParameter (const CATICkeParm_var &iParm) const ;
	
	/** 
	* Removes a formal parameter to the law.
	* @param iParm Removes the specified formal parameter.
	*/
	virtual	void RemoveFormalParameter (const CATICkeParm_var &iParm) const ;
	

  	//-------------------------------------------
	// Interface CATICkeFunction implementation
	//-------------------------------------------
	

  /**
   * Returns the description of this function.
 	  *@return The signature of the function.
  */
  virtual CATICkeSignature_var GetDescription () const ;

  /**
  * Indicates if this function can be evaluated.
  *@return true : the function is runnable, false : the function is not runnable
  */
  virtual CATCke::Boolean IsRunnable () const ;

  /**
   * Evaluates the function on a list of parameters.
   * @param iListOfParameters
   *     List of parameters in argument of the function.<br>
   *     Those arguments can be in input or in output of the function.<br>
   *     (Note that CATCkeListOfParm is a CATLISTV(CATBaseUnknown_var)* )
   * @param iReturnedParameter
   *     parameter returned by the function.<br>
   * @param iEvaluationContext
   *     context of evaluation.<br>
   */
  virtual void Run (CATCkeListOfParm iListOfParameters,const CATICkeParm_var &iReturnedParameter,const CATCkeEvalContext *iEvaluationContext=NULL) const ; 
};

#endif
