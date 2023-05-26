/* -*-c++-*- */
/**
* @CAA2Level L1
* @CAA2Usage U3
*/
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2008
//-----------------------------------------------------------------------------
//
// class CATIAdpPLMErrorReviewer.h
//
// Handle dedicated to the management of all errors raised by a (series) 
// of PLM action(s) enabled to collect PLM errors (Engines, AdpServices, ..)
// 
//-----------------------------------------------------------------------------
// 30/09/2008 Creation										                VCS
//-----------------------------------------------------------------------------

#ifndef CATIAdpPLMErrorReviewer_H
#define CATIAdpPLMErrorReviewer_H

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"

class CATIAdpPLMErrorIterator;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationAccess IID IID_CATIAdpPLMErrorReviewer;
#else
extern "C" const IID IID_CATIAdpPLMErrorReviewer ;
#endif

//-----------------------------------------------------------------------------

/**
* Interface to handle a PLM Error reviewer object.
* <br><b>Role</b>: This interface handles the PLM Error Reviewer object as the container for all PLM errors raised when 
* performing PLM server Access operations.
* <br>For example : 
* <ul>
* <li>QEOPS operation: @href CATAdpOpenSaveServices </li>
* <li>Components LifeCycle operation: @href CATAdpMaturityServices </li>
* </ul>
* 
* <br>The ErrorReviewer creation is invoked by application, using  @href CATAdpPLMErrorReviewerFactory#CreateErrorReviewer .
* <p>
* <br>Several ErrorReviewers may exist at the same time in the current session for distinct uses.
* <br>Any application using this decides wich PLM services are to be monitored by a given ErrorReviewer
* <br>and when errors have to be scanned and read on this reviewer for reporting and/or display.
* <p>
* <br>A same PLMError Reviewer can be used for while calling sequentially several PLM operations:
* <br>Eventual errors raised by each operation are added to the current set of errors contained by the Reviewer.
* <br>The set of error is only reset when deleting the Reviewer.
* <p>
* example:
* <pre>
* // Create a PLM Error Reviewer:
* CATIAdpPLMErrorReviewer* piErrorReviewer = NULL;
* HRESULT HRC = CATAdpPLMErrorReviewerFactory::CreateErrorReviewer(piErrorReviewer);
* if (SUCCEEDED(HRC) && piErrorReviewer)
* {
*   // Use this PLM Error Reviewer calling service(s) that may fill it with PLMErrors
*   HRC = CATAdpOpenSaveServices::Save(NULL, piErrorReviewer);
* </pre> 
* <br>// Analyse eventual errors raised using @href CATIAdpPLMErrorIterator and @href CATIAdpPLMError
* <pre> 
*   if (FAILED(HR))
*   {
* 	  CATIAdpPLMErrorIterator* piErrorIterator = NULL
* 	  piErrorReviewer->GetPLMErrorIterator(piErrorIterator);
* 	  ...
*   }
*   // delete the PLM Error Reviewer after use
*   piErrorReviewer->Release();
*   piErrorReviewer = NULL;
* }
</pre>
* 
* @see CATAdpPLMErrorReviewerFactory , CATIAdpPLMErrorIterator , CATIAdpPLMError
*/
class ExportedByCATPLMIntegrationAccess CATIAdpPLMErrorReviewer: public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/**
	* Gets an Iterator on the set of PLM Errors stored by this ErrorReviewer.
	* <br><b>Role:</b> This method gets an Iterator to scan the list of PLM Errors stored by this ErrorReviewer.
	* @param opErrorIterator
	*    An iterator on the set of PLM Errors <b>currently</b> stored by this PLMError Reviewer.
	*    When the same PLMError Reviewer is used later in another service raising errors,
	*    get another iterator to scan the updated set of errors.
	* @return
	*		 S_OK  : An error Iterator has been created from this ErrorReviewer.
	* <br> E_FAIL  : Error Iterator creation failed. an unexpected NULL output pointer is given.
	*/
	virtual HRESULT GetPLMErrorIterator(CATIAdpPLMErrorIterator* & opErrorIterator)= 0;

};
//-----------------------------------------------------------------------------
 CATDeclareHandler( CATIAdpPLMErrorReviewer, CATBaseUnknown );

#endif
