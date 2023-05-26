#ifndef CATVisitorAdapter_H
#define CATVisitorAdapter_H

// COPYRIGHT DASSAULT SYSTEMES 1999-2001


// Export Module 
#include "CATLifSpecs.h"

// inherit from
#include "CATBaseUnknown.h"

#include "CATIVisitor.h"




/**   
 * CAA Adapter to CATIVisitor Interface.
 * <b>Role</b>: This class should be derived to implement features extension to CATIVisitor.<br>
 * @see CATIVisitor
 */

class ExportedByCATLifSpecs CATVisitorAdapter : public CATIVisitor
{
public:

   /** 
    * Constructs the extension.
    */ 
    CATVisitorAdapter();

   /** 
    * Deletes the extension.
    */ 
    virtual ~CATVisitorAdapter();

	/**
	* Operates on the submitted object and returns a continuation code.
	*
	* @param iInstance Object to be performed on.
	* @return S_OK to continue the scan, E_FAIL to stop.
	*/ 
	virtual HRESULT   Visit      (CATBaseUnknown* iInstance);

	/**
	* For optimization purpose.
	* if VisitChildren is called with recursive argument, allows to control
	* if given publisher is to be visited
	* @param the tested publisher
	* @return
	* S_OK is the publisher is to be visited, E_FAIL else
	*/
	virtual HRESULT VisitPublisherForRecursion(const CATIParmPublisher_var &publisher);

	/**
	* In some cases, special data is needed to be visited.
	* @return
	* NULL if no special data is to be visited, else a list of strings containing format specifications
	* (these formats have to be discussed between callers and providers)
	*/
	virtual const CATListOfCATUnicodeString* SpecialDataNeeded();


private:
 
  /**
   * copy constructor
   */
   CATVisitorAdapter(const CATVisitorAdapter&);
};


#endif
