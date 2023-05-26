#ifndef CATICkeFunction_H
#define CATICkeFunction_H

// COPYRIGHT Dassault Systemes 2000

  /** 
 * @CAA2Level L1
 * @CAA2Usage U4 CATCkeLawAdapter
 */

// module definition
#include "CATLifSpecs.h"

// inherits from
#include "CATBaseUnknown.h"

// forwards
#include "CATICkeRelationForwards.h"
class CATCkeEvalContext;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATICkeFunction ;
#else
extern "C" const IID IID_CATICkeFunction ;
#endif
 

/**
 * Interface to describe functions.
 * <b>Role</b>: This interface defines functions that can be used in our language.<br>
 * This interface gives access to a CATICkeSignature which contains the<br>
 * description of this function (arguments, name, comment, etc...<br>
 * It is also used to evaluate the function.
 * <br>
 * Implementations of that interface should derive from CATCkeLawAdapter.
 *
 * <p><b>BOA information</b>: this interface CANNOT be implemented
 * using the BOA (Basic Object Adapter).
 * To know more about the BOA, refer to the CAA Encyclopedia home page.
 * Click Middleware at the bottom left, then click the Object Modeler tab page.
 * Several articles deal with the BOA.</p>
 * @see CATICkeSignature, CATICkeArg, CATICkeParm, CATITypeDictionary.
 */
class ExportedByCATLifSpecs CATICkeFunction: public CATBaseUnknown
{
  CATDeclareInterface;

  public:
  
  /**
  * Returns the description of this function.
  *@return The signature of the function.
	  */
  virtual CATICkeSignature_var GetDescription () const = 0;

  /**
   * Indicates if this Knowledge function can be evaluated.
   * @return TRUE if Knowledge function can be evaluated
   */
  virtual CATCke::Boolean IsRunnable () const = 0;

  /**
   * Evaluates the function on a list of parameters.<br>
   * This method may raise evaluation error (CATLifEvaluationError). No ability to catch them in CAA.<br>
   * @param iListOfParameters
   *     List of parameters in argument of the function.<br>
   *     Those arguments can be in input or in output of the function.<br>
   *     (Note that CATCkeListOfParm is a CATLISTV(CATBaseUnknown_var)* )
   * @param iReturnedParameter
   *     parameter returned by the function.<br>
   * @param iEvaluationContext
   *     context of evaluation.<br>
   */
  virtual void Run (CATCkeListOfParm iListOfParameters,const CATICkeParm_var &iReturnedParameter,const CATCkeEvalContext *iEvaluationContext=NULL) const =0; 

};

CATDeclareHandler(CATICkeFunction,CATBaseUnknown);
//------------------------------------------------------------------

#endif
