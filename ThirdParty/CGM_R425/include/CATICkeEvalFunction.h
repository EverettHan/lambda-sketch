// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATICkeEvalFunction.h
// Define the CATICkeEvalFunction interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Jun 2009  Creation: Code generated by the CAA wizard  FRH
//===================================================================
#ifndef CATICkeEvalFunction_H
#define CATICkeEvalFunction_H

#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"
#include "CATICkeExpressionForwards.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATICkeEvalFunction;
#else
extern "C" const IID IID_CATICkeEvalFunction ;
#endif

class CATCkeEvalContext;

//------------------------------------------------------------------

/**
* Interface representing xxx.
*
* <br><b>Role</b>: Components that implement
* CATICkeEvalFunction are ...
* <p>
* Do not use the CATICkeEvalFunction interface for such and such

*
* @example
*  // example is optional
*  CATICkeEvalFunction* currentDisplay = NULL;
*  rc = window-&gt;QueryInterface(IID_CATICkeEvalFunction,
*                                     (void**) &amp;currentDisplay);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByCATLifSpecs CATICkeEvalFunction: public CATBaseUnknown
{
  CATDeclareInterface;

  public:


    /** 
	 * Evaluation
	*/
	virtual void Do (CATCkeListOfParm plist,const CATICkeParm_var &iRes,const CATCkeEvalContext *pevalcontext) const =0; 
	
	

};

CATDeclareHandler(CATICkeEvalFunction,CATBaseUnknown);
//------------------------------------------------------------------

#endif