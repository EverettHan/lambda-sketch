#ifndef CATIInstancesProvider_H
#define CATIInstancesProvider_H

// COPYRIGHT DASSAULT SYSTEMES 2000

// inherited class 
#include "CATBaseUnknown.h"

// load module
#include "CATLifSpecs.h"

// forward declaration
class CATIInstancesVisitor_var;

// Interface ID
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATIInstancesProvider ;
#else
extern "C" const IID IID_CATIInstancesProvider ;
#endif



/**   
 * Interface dedicated to providing instances.
 *
 * <b>Role</b>: Knowledge Expert needs to be able to scan a hierarchy of objects
 * starting from a root, without knowing the intrinsics of that root. This interface
 * allows Knowledge Expert to scan this root.<br>
 *
 * This interface will be automatically used on a @href CATIInstance object who has
 * already been found by another object implementing this interface.
 *
 * @see CATIInstance
 * @see CATIInstancesVisitor
 */

class ExportedByCATLifSpecs CATIInstancesProvider: public CATBaseUnknown
{
	CATDeclareInterface;
	
public:
	/**
	* Finds instances provided by this object.
	*
	* This method is to be called recursively on your objects.<br>
	* Each time you find a CATIInstance (<tt>inst</tt>), simply call
	* <tt>iVisitor->AcceptInstance (inst)</tt>.
	*
	* @param iVisitor visitor gathering instances.
	*/ 
	virtual void   FindInstances  (const CATIInstancesVisitor_var &iVisitor) = 0;
       
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler(CATIInstancesProvider, CATBaseUnknown) ;

#endif
