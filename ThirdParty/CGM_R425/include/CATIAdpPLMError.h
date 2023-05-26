/* -*-c++-*- */
/**
* @CAA2Level L1
* @CAA2Usage U3
*/
//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2008
//-----------------------------------------------------------------------------
//
// CATIAdpPLMError.h
// Defines the CATIAdpPLMError interface
// Accesses the content of each unitary Error Cell stored by a given Error Reviewer
// 
//-----------------------------------------------------------------------------
//
// Usage notes:
//
//-----------------------------------------------------------------------------
//  30/09/2008  United Colors of PLM Error Management                      VCS
//-----------------------------------------------------------------------------
//
#ifndef CATIAdpPLMError_H
#define CATIAdpPLMError_H

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationAccess IID IID_CATIAdpPLMError;
#else
extern "C" const IID IID_CATIAdpPLMError ;
#endif

class CATError;
class CATIAdpPLMIdentificator;

//-----------------------------------------------------------------------------
/**
* Interface intended to access the content of each unitary PLM Error stored by an ErrorReviewer.
* <br><b>Role</b>: This interface accesses the elementary data on each PLM Error collected by a given ErrorReviewer
* used while performing PLM server Access operations.
* <br> These operations handle PLM components that may be individually involved in an error case: 
* - The component identification is then stored on the PLMError
* <br> but the error case might also be a global system problem impacting all components handled by the operation:
* - No component identification is stored on the PLMError
* <p>
* @see CATAdpPLMErrorReviewerFactory , CATIAdpPLMErrorReviewer , CATIAdpPLMErrorIterator
*/
class ExportedByCATPLMIntegrationAccess CATIAdpPLMError: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

	/**
	* Returns the standard object describing the error.
	* @param opError [out, CATBaseUnknown#Release]
	*    The generic System object describing the error.
	*    Refer to <tt>CATError</tt> class to get all NLS informations about the error message.
	* @return
	*		 S_OK  : the generic Error has been retrieved from PLMError
	* <br> E_FAIL  : the generic Error retrieval failed. an unexpected NULL output pointer is given.
	*/
	virtual const HRESULT GetError(CATError ** opError)=0;
	
	/**
	* Gets the identifier of the PLM component that raised this error.
	* <br><b>Role:</b> This method gets a handle on the unique database identifier of the PLM component that raised this error.
	* @param opAdpIdentificator [out, CATBaseUnknown#Release]
	*        the handle on the unique identifier of the component in the DataBase
	* @return
	*		 S_OK  : identification successfull: a valid opAdpIdentificator output pointer is given.
	* <br> S_FALSE : no component associated to this PLM error: this is a global system error. a NULL output pointer is given.
	* <br> E_FAIL  : identification failed for the component that raised this error: an unexpected NULL output pointer is given.
	*/
    virtual const HRESULT GetPLMComponentIdentifier (CATIAdpPLMIdentificator* & opAdpIdentificator)=0;

};
//-----------------------------------------------------------------------------
 CATDeclareHandler( CATIAdpPLMError, CATBaseUnknown );

#endif
