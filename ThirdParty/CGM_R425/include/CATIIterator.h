// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIIterator.h
// Define the CATIIterator interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Nov 2005  Creation: Code generated by the CAA wizard  LLV
//===================================================================
/**
  * @level Protected
  * @usage U3
*/

#ifndef CATIIterator_H
#define CATIIterator_H

#include "CATPLMComponentInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMComponentInterfaces IID IID_CATIIterator;
#else
extern "C" const IID IID_CATIIterator ;
#endif

//------------------------------------------------------------------

/**
* Interface used to enumerate the objects that belong to a collection. 
*
* <br><b>Role</b>: Components that implement CATIIterator are collection of objects.
* The CATIIterator interface is used to enumerate the element that belongs to a collection,
* one by one using the Next method.
* <p>
*
* @example
*
*  CATIIterator_var spIter = ....
*  CATBaseUnknown_var spEntity;
*  while( SUCCEEDED(spIter->Next(spEntity )) ){
*     ... 
*  }
*
*/
class ExportedByCATPLMComponentInterfaces CATIIterator: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

	/**
	*   Returns an interface smart pointer on the next element of the collection.
	*   @param oNext
	*      The interface smart pointer on the next element.
	*	@return
	*		An HRESULT value. 
	*		<br><b>Legal values</b>:
	*		<dl>
	*       <dt><tt>S_OK</tt></dt>
	*       <dd>The next element was successfully returned.</dd>
	*       <dt><tt>E_FAIL</tt></dt>
	*       <dd>There is no more element to enumerate.</dd>
	*       </dl>
	*/

      virtual HRESULT Next(CATBaseUnknown_var & oNext) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------
CATDeclareHandler( CATIIterator, CATBaseUnknown );

#endif
