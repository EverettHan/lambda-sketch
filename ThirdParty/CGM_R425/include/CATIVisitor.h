#ifndef CATIVisitor_H
#define CATIVisitor_H

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @CAA2Level L1
 * @CAA2Usage U3 
*/

//System.  inherited class 
#include "CATBaseUnknown.h"

//Knowledge Interfaces. load module
#include "CATLifSpecs.h"
#include "CATListOfCATUnicodeString.h"

class CATIParmPublisher_var;

// forward declaration

// Interface ID
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATIVisitor ;
#else
extern "C" const IID IID_CATIVisitor ;
#endif
 

/**   
 * Interface dedicated to implementing a visitor pattern.
 *
 * <b>Role</b>: The visitor performs operations on objects submitted by a provider
 * (cf. Design Patterns by the Gang of Four, Addison-Wesley, chapter 5 "Visitor").<br>
 *
 * The provider scans recursively a structure and submit objects to the visitor. The visitor
 * returns a result code indicating if the scan should continue or not.<br>
 *
 * It provides performance improvements over the method
 * consisting in creating a list of interesting elements and then
 * performing operations on them.
 *
 * <p><b>BOA information</b>: this interface CAN be implemented
 * using the BOA (Basic Object Adapter).
 * To know more about the BOA, refer to the CAA Encyclopedia home page.
 * Click Middleware at the bottom left, then click the Object Modeler tab page.
 * Several articles deal with the BOA.</p>
 */

class ExportedByCATLifSpecs CATIVisitor: public CATBaseUnknown
{
	CATDeclareInterface;
	
public:
	/**
	* Operates on the submitted object and returns a continuation code.
	*
	* @param iInstance Object to be performed on.
	* @return S_OK to continue the scan, E_FAIL to stop.
	*/ 
	virtual HRESULT   Visit      (CATBaseUnknown* iInstance)=0;

	/**
	* For optimization purpose.
	* if VisitChildren is called with recursive argument, allows to control
	* if given publisher is to be visited
	* @param publisher the tested publisher
	* @return S_OK if the publisher is to be visited, E_FAIL else
	*/
	virtual HRESULT VisitPublisherForRecursion(const CATIParmPublisher_var &publisher) = 0;

	/**
	* In some cases, special data is needed to be visited.
	* @return
	* NULL if no special data is to be visited, else a list of strings containing format specifications
	* (these formats have to be discussed between callers and providers)
	*/
	virtual const CATListOfCATUnicodeString* SpecialDataNeeded() = 0;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler(CATIVisitor, CATBaseUnknown) ;

#endif
