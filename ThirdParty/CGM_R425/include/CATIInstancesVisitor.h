#ifndef CATIInstancesVisitor_H
#define CATIInstancesVisitor_H

// COPYRIGHT DASSAULT SYSTEMES 2000

// inherited class 
#include "CATBaseUnknown.h"

// load module
#include "CATLifSpecs.h"

// forward declaration
class CATIInstance_var;
class CATUnicodeString;

// Interface ID
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATIInstancesVisitor ;
#else
extern "C" const IID IID_CATIInstancesVisitor ;
#endif
 

/**   
 * Interface dedicated to implementing a visitor of instances.
 *
 * <b>Role</b>: a visitor is used to to gather instances provided by a
 * @href CATIInstancesProvider according to some inner conditions.
 *
 * This allows to improve performance : for instance, the visitor
 * could want to cancel the search after the first acceptable instance. It then
 * avoids the whole scan.<br>
 *
 * The visitor can provide the instances provider with information on the kind of
 * instances it is looking for. If not, all instances will be submitted to the visitor.
 *
 * @see CATIInstance
 * @see CATIInstancesProvider
 */

class ExportedByCATLifSpecs CATIInstancesVisitor: public CATBaseUnknown
{
	CATDeclareInterface;
	
public:
	/**
	* Accepts an instance.
	*
	* The visitor decides whether it should do something
	* with the instance or not. If yes, then it should return S_OK.
	* If not, it should return S_FALSE.
	*
	* @param iInstance proposed instance.
	*/ 
	virtual int AcceptInstance      (const CATIInstance_var &iInstance)=0;

	/**
	* Gives some information on the kind of instances the visitor is looking for.
	*
	* @param iContext explanatory string.
	*/
	virtual int ContextualSearch    (const CATUnicodeString& iContext)=0;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler(CATIInstancesVisitor, CATBaseUnknown) ;

#endif
