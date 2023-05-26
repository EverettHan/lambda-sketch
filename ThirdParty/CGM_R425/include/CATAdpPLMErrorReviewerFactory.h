/* -*-c++-*- */
/**
* @CAA2Level L1
* @CAA2Usage U1
*/
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2008
//-----------------------------------------------------------------------------
//
// class CATAdpPLMErrorReviewerFactory :
// 
// Services to manage applicative Life Cycle of Error Monitor(s) intended to 
// collect all PLM Errors raised by a (series of) PLM action(s).
// 
//-----------------------------------------------------------------------------
// 30/09/08 Creation                                                        VCS
//-----------------------------------------------------------------------------

#ifndef CATAdpPLMErrorReviewerFactory_H
#define CATAdpPLMErrorReviewerFactory_H

// System
#include "CATBaseUnknown.h"
#include "CATPLMIntegrationAccess.h"

class CATIAdpPLMErrorReviewer;

/**
* Services to manage PLMError Reviewer objects.
* <br> This class proposes a method to <b>create</b> a PLM Error Reviewer object, that can be handled through the interface @href CATIAdpPLMErrorReviewer.
* <br> A PLMError Reviewer object is deleted from the current session when all its interface pointers are released.
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
*   ...
* } 
*  
* // delete the PLM Error Reviewer after use
* piErrorReviewer->Release();
* piErrorReviewer = NULL;
</pre>
* @see CATIAdpPLMErrorReviewer , CATIAdpPLMErrorIterator , CATIAdpPLMError
*/
class ExportedByCATPLMIntegrationAccess CATAdpPLMErrorReviewerFactory
{
public:

	/**
	* Creates a PLMError Reviewer object. 
	* <br><b>Role:</b> This method creates an Error Reviewer to be handled by callers.
	* @param opiErrorReviewer [out, CATBaseUnknown#Release]
	*     The interface pointer on the Error Reviewer object created by the factory.
	* @return
	*		 S_OK : Error Reviewer created and operation successfull.
	* <br> E_FAIL : creation failed: Error Reviewer not created, output has a NULL value.
	*/
	static HRESULT CreateErrorReviewer(CATIAdpPLMErrorReviewer* & opiErrorReviewer);
};
#endif
