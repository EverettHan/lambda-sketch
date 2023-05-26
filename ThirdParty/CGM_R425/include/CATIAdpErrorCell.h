/* -*-c++-*- */
/**
* @level Protected
* @usage U3
*/

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2008
//-----------------------------------------------------------------------------
//
// class CATIAdpErrorMonitor.h
//
// Handle dedicated to the access to unitary Error Cell managed by the Error Monitor
// 
//-----------------------------------------------------------------------------
// 04/07/2008 Creation - United Colors of Error Management                  VCS
//-----------------------------------------------------------------------------

#ifndef CATIAdpErrorCell_H
#define CATIAdpErrorCell_H

#include "CATPLMIntegrationAccess.h"
#include "CATIAdpPLMError.h"
#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATLISTV_CATPLMID.h"
#include "CATOmxSR.h"
#include "CATOmxDeprecated.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationAccess IID IID_CATIAdpErrorCell;
#else
extern "C" const IID IID_CATIAdpErrorCell ;
#endif

class CATError;
class CATIPLMComponent;

/**
 * [[deprecated("Use HideError() instead")]]
 * @deprecated V6R422
 * @use CATIAdpErrorCell#HideError
 */
enum AdpErrorFilter
{
  ERR_UNEXPECTED=-1, 
  ERR_NOFILTER=0,  
  ERR_DEPRECATED=1
};

/**
* Interface intended to handle the unitary Error Cell managed by the Error Monitor.
* <br><b>Role</b>: Accesses to the elementary data elements on the Error Cell.
* These data are usefull to Interpret/Filter the Cell and Display/Report its usefull content to end user.
* <p>
* For use only - This interface cannot be re-implemented by applications using it.
*/

class ExportedByCATPLMIntegrationAccess CATIAdpErrorCell: public CATIAdpPLMError
{
  CATDeclareInterface;

public:

	/**
	* @deprecated V6R422
	* @use CATIAdpErrorCell#HideError
	*/
	OMX_DEPRECATED("Use HideError() instead") virtual HRESULT InterpretAs(AdpErrorFilter iFilter) = 0;

	/**
	* @deprecated V6R422
	* Useless, does nothing
	*/
	OMX_DEPRECATED("Useless. Does nothing") virtual const HRESULT IsInterpretedAs(AdpErrorFilter & oFilter) = 0;

	/**
	* Compares the Error Cell's key/catalog to input ones
	* <br><b>Role:</b> Compares the error cells reference in catalog to input one
	* @param iErrorKey
	*        the Error key the Error Cell's one is compared to 
	* @param iErrorCatalog
	*        the Error catalog the Error Cell's one is compared to 
	* @return
	*		 S_OK : comparison successfull
	* <br> E_FAIL : comparison failed
	*/
	virtual const CATBoolean IsAnOccurrenceOf(const CATString iErrorKey, const CATString iErrorCatalog) = 0;

	/**
	* factorizes components on whose this error has been raised
	* <br><b>Role:</b> Adds another component in the list of components triggering this error 
	* @param iFilter
	*        the Filter to be applied on the Error Cell
	* @return
	*		 S_OK : operation successfull
	* <br> E_FAIL : operation failed
	*/
	virtual HRESULT AddComponent(CATIPLMComponent * ipComponent) = 0;

	/**
	* Gets the eventual Display identifier of the component in error
	* <br><b>Role:</b> Gets the eventual Display identifier of the component triggering this error
	* @param oDisplayId
	*        The Display Identifier of the component
	* @return
	*		 S_OK  : the display identifier is output
	* <br> S_FALSE : the display identifier is not yet computed : a blank string is output
	*/
	virtual const HRESULT GetDisplayIdentifier(CATUnicodeString & oDisplayId) = 0;

  /**
   * Checks if components are associated to this error.
   * @return
   *  TRUE if components are associated to this error,
   *  FALSE otherwise.
   */
  virtual CATBoolean HasAssociatedComponents() const = 0;

  /**
   * Retrieves the components associated to this error.
   * @param oAssociatedComponents [out] the components associated to this error 
   *  (empty if none available).
   * @return 
   *  S_OK if the associated components were successfully retrieved,
   *  S_FALSE if associated components are not available,
   *  E_UNEXPECTED if any error occurred.
   */
  virtual HRESULT GetAssociatedComponents(CATPLMIDs & oAssociatedComponents) const = 0;

  /**
   * Adds a component to associate to this error.
   * The add order is kept and one component can be added several times.
   * @param iComponentToAssociate [in] The component to associate.
   * @return 
   *  S_OK if successful,
   *  E_UNEXPECTED if any error occurred.
   */
  virtual HRESULT AddAssociatedComponent(const CATPLMID & iComponentToAssociate) = 0;

  /**
   * Adds components to associate to this error.
   * The add order is kept and one component can be added several times.
   * @param iComponentsToAssociate [in] The components to associate.
   * @return 
   *  S_OK if successful,
   *  E_UNEXPECTED if any error occurred.
   */
  virtual HRESULT AddAssociatedComponents(const CATPLMIDs & iComponentsToAssociate) = 0;

	/**
	* Gets the identifier of the PLM component that raised this error.
	* <br><b>Role:</b> This method gets a handle on the unique database identifier of the PLM component that raised this error.
	* @return 
	*		 empty PLMID if no component is attached to the error.
	*/
	virtual CATPLMID GetPLMID()=0;

	/**
	* Returns the standard object describing the error.
	* @return
	*		 nullptr if no error is available
	*/
  virtual CATOmxSR<CATError> GetCATError()=0;

	/**
	* Enables the user to hide the error so that it is not returned anymore by the @href CATIAdpErrorMonitor.
	*/
	virtual void HideError() = 0;

	/**
	* Enables the user to know if error will be retrieved when calling @href CATIAdpErrorMonitor#GetErrorIterator.
	*/
	virtual bool IsHidden() = 0;
};
CATDeclareHandler(CATIAdpErrorCell, CATBaseUnknown);
#endif
