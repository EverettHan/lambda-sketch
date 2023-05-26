/* -*-c++-*- */
/**
* @CAA2Level L1
* @CAA2Usage U3
*/
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2008
//-----------------------------------------------------------------------------
//
// class CATIAdpPLMErrorIterator.h
// Defines the CATIAdpPLMErrorIterator interface
//
// Scans and reads all PLM Errors logged in a given ErrorReviewer  
// by a (series) of PLM action(s) enabled to collect errors (Engines, AdpServices, ..)
// 
//-----------------------------------------------------------------------------
// 30/09/2008 Creation                                                     VCS
//-----------------------------------------------------------------------------
#ifndef CATIAdpPLMErrorIterator_H
#define CATIAdpPLMErrorIterator_H

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"

class CATIAdpPLMError;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationAccess IID IID_CATIAdpPLMErrorIterator;
#else
extern "C" const IID IID_CATIAdpPLMErrorIterator ;
#endif

//-----------------------------------------------------------------------------

/**
* Iterator to handle the set of PLM errors logged by a PLM Error Reviewer.
* <br><b>Role</b>: This interface scans sequentially the set of errors logged by a given PLM ErrorReviewer (@href CATIAdpPLMErrorReviewer ) :
* <p>
* <br>When the Error Reviewer is passed to a PLMServer access operation, it is filled with all PLM errors eventually raised by this operation. 
* <br>These PLM Errors are added to the set of PLM errors that may already be stored in the Error Reviewer.
* <br>The set of errors is only reset when deleting the Reviewer.
* <p>
* <br>The Iterator is to be created first using @href CATIAdpPLMErrorReviewer#GetErrorIterator :
* <br>The returned iteration pointer enables to scan the <b>current</b> set of Errors stored by the PLMError Reviewer.
* <p>
* <br>When the Error Reviewer is used to perform another PLMServer access operation, another Iterator is to be
* <br>created to scan the updated set of PLM Errors.
* example:
* <pre>
* // Use a PLM Error Reviewer calling service(s) that may fill it with PLMErrors
* HRC = CATAdpOpenSaveServices::Save(NULL, piErrorReviewer);
* 
* </pre> 
* <br>// Scan eventual errors raised using @href CATIAdpPLMErrorIterator and @href CATIAdpPLMError
* <pre> 
* if (FAILED(HR))
* {
*   CATIAdpPLMErrorIterator * piErrorIterator = NULL;
*   CATIAdpPLMError* piPLMError = NULL;
*   HR = piErrorReviewer->GetPLMErrorIterator(piErrorIterator);
*   if (SUCCEEDED(HR) && piErrorIterator)
*   {
*     while (SUCCEEDED(piErrorIterator->Next(piPLMError)) && piPLMError)
*     {
* </pre> 
* <br>// Read error content using @href CATIAdpPLMError
* <pre> 
*        ...
*	      piPLMError->Release();
*	      piPLMError = NULL;
*     }
*   }
* }
* </pre> 
* <p>
* @see CATAdpPLMErrorReviewerFactory , CATIAdpPLMErrorReviewer , CATIAdpPLMError
*/

class ExportedByCATPLMIntegrationAccess CATIAdpPLMErrorIterator: public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/**
	* Rewinds iterator for another iteration.
	* @return
	*		 S_OK : Rewind successfull
	* <br> E_FAIL : Rewind failed
	*/
	virtual HRESULT Rewind()= 0;

	/**
	* Iterates on the next PLM Error.
	* <br><b>Role:</b> This method gets the next PLM Error Cell stored by the ErrorReviewer.
	* @param opPLMError
	*        the PLM Error read by the iterator or NULL when the end of the error set has been reached.
	* @return
	*		 S_OK : iteration successfull
	* <br> E_FAIL : iteration failed
	*/
	virtual HRESULT Next(CATIAdpPLMError* & opPLMError)= 0;
};

//-----------------------------------------------------------------------------
 CATDeclareHandler( CATIAdpPLMErrorIterator, CATBaseUnknown );

#endif
