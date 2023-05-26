#ifndef CATIOmbComponentObject_H
#define CATIOmbComponentObject_H


// COPYRIGHT DASSAULT SYSTEMES 2005


/**
* @level Private
* @usage U3
*/

#include "CATBaseUnknown.h"
#include "CATObjectModelerBase.h"
#include "CATLISTV_CATBaseUnknown.h"

class CATIComponent_var;
class CATSysSimpleHashTable;


extern ExportedByCATObjectModelerBase IID IID_CATIOmbComponentObject;


/** 
* Interface to retrieve the component containing an object.
*/
class ExportedByCATObjectModelerBase CATIOmbComponentObject : public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/**
  * FOR INTERNAL USAGE ONLY, THE GOOD CHOICE IS TO USE THE FOLLOWING SERVICES
  *
  * @href CATIPLMComponentServices#GetPLMComponentOf
  * @href CATPLMComponentInterfacesServices#GetPLMComponentOf
  *
	* Retrieves the component containing the current object.
	* @param oComponent
	*   The component.
	* @return
	*	An HRESULT value: 
	*	<dl>
	*   <dt>S_OK</dt>
	*     <dd>The component is retrieved.</dd>
	*		<dt>S_FALSE</dt>
	*     <dd>The current object does not belong to a component.</dd>
	*   <dt>E_FAIL</dt>
	*     <dd>The component has failed to be retrieved.</dd>
	*	</dl>
	*/
	virtual HRESULT GetComponent( CATIComponent_var& oComponent ) const =0;

	/**
  * DEPRECATED
  *
	* Retrieves all components that point the current component.
	* <br><b>Note:</b>The current object must be a component.
	* <br>Only "tk_ext" links are taken into account.
	* @param oPointingComponents
	*	 The table of pointing components.
	* @return 
	*	 An HRESULT value: 
	*	 <dl>
	*		<dt>S_OK</dt>
	*			<dd>The pointing components have been retrieved successfully.</dd>
	*		<dt>E_FAIL</dt>
	*			<dd>The object is not a component or the pointing components have failed to be retrieved</dd>
	*	 </dl>
	*/
	virtual HRESULT GetPointingComponents( CATSysSimpleHashTable& ioPointingComponents ) const =0;

	/**
   * DEPRECATED
   *
	 * Loads the current component globally.
	 * <br><b>Note:</b>The current object must be a component.
	 * @return
	 *  An HRESULT value: 
	 *  <dl>
	 *   <dt>E_FAIL</dt>
	 *    <dd>The object is not a component or the component can't be globally loaded.</dd>
	 *   <dt>S_FALSE</dt>
	 *    <dd>The component is already globally loaded.</dd>
	 *   <dt>S_OK</dt>
	 *    <dd>The component has been globally loaded successfully.</dd>
	 *  </dl>
	 */
	virtual HRESULT LoadGlobally() =0;

	/**
   * DEPRECATED
   *
	 * Retrieves the list of entities inside the component.
	 * @param oPointingEntity
	 *  The list of entities.
	 * @return
	 *  An HRESULT value: 
	 *	 <dl>
	 *		<dt>S_OK</dt>
	 *			<dd>The entities have been retrieved successfully.</dd>
	 *		<dt>E_FAIL</dt>
	 *			<dd>The entities have failed to be retrieved.</dd>
	 *	 </dl> 
	 */
	virtual HRESULT GetPointingEntity( CATLISTV( CATBaseUnknown_var )& oPointingEntity )=0;
};

CATDeclareHandler( CATIOmbComponentObject, CATBaseUnknown );

#endif

