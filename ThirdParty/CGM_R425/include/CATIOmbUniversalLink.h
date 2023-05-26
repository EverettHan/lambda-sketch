#ifndef CATIOmbUniversalLink_h
#define CATIOmbUniversalLink_h
// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIOmbUniversalLink.h
//
//===================================================================
//
// Usage notes:
// Interface to manage persistent linkability in CATIA session.
//
//===================================================================
//  Sept 2006  Creation: pbv 
//===================================================================
/**
  * @CAA2Required                   
  */
#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_CATIOmbUniversalLink;
#else
extern "C" const IID IID_CATIOmbUniversalLink;
#endif

/**
 * Interface to represent a link intention.
 * <b>Role:</b> This interface repesents an exposed view of a link intention that is created by the @href CATOmbUniversalLinkFactory factory. 
 * It is used to establish a link thanks to @href CATISpecAttrAccess#SetExternalLink.
 * <br>Refer to Object Modeler technical article for more information.
 */
class ExportedByCATObjectModelerBase CATIOmbUniversalLink : public CATBaseUnknown
{
  CATDeclareInterface;
public:

	/**
   	 * Retrives the pointed object for the link intention represented by the CATIOmbUniversalLink.
     * <b>WARNING:</b> in some specific cases, the virtual object will not be available until 
     * the link has been established with @href CATISpecAttrAccess#SetExternalLink (in which case 
     * E_ACCESSDENIED will be returned).
   	 * @param oObj
   	 *   The address of a pointer variable that will receive the interface pointer requested.
	 * @param iIID
   	 *   The identifier of the interface being requested.
   	 * @return
   	 *   An HRESULT value. 
   	 *   <br><b>Legal values</b>:
   	 *   <dl>
   	 *     <dt>S_OK</dt>
   	 *     <dd>The query succeeded.</dd>
   	 *     <dt>E_INVALIDARG</dt>
   	 *     <dd>There is no associated virtual object.</dd>
   	 *     <dt>E_NOINTERFACE</dt>
   	 *     <dd>The interface does not exist.</dd>
   	 *     <dt>E_FAIL</dt>
   	 *     <dd>The object is not valid.</dd>
   	 *     <dt>E_ACCESSDENIED</dt>
   	 *     <dd>The virtual object is not yet available 
     *         (the link is not yet established with 
     *         @href CATISpecAttrAccess#SetExternalLink ).</dd>
   	 *     <dt>E_OUTOFMEMORY</dt>
   	 *     <dd>Memory allocation failed</bb>
   	 *     <dt>E_UNEXPECTED </dt>
   	 *     <dd>The query failed for other reasons</dd>
   	 *   </dl>
	 */
	virtual HRESULT GetReferencedObject(void ** oObj, const IID & iIID) =0;
	/**
   	 * Retrives the unfolded pointed object for the link intention represented by the CATIOmbUniversalLink. There is no need to set the link for this service.However an AttrAccess and an AttrKey inputs are needed.
   	 * @param result
   	 *   The pointed result.
	 * @param AttrAccess
   	 *  Feature or StartUp
   	 * @AttrKey
   	 *  Attribute Key
   	 *   <br><b>Legal values</b>:
   	 *   <dl>
   	 *     <dt>S_OK</dt>
   	 *     <dd>The query succeeded.</dd>
   	 *     <dt>E_FAIL</dt>
   	 *     <dd>No Valid Result.</dd>
   	 *     <dt>E_UNEXPECTED </dt>
   	 *     <dd>The query failed for other reasons</dd>
   	 *   </dl>
	 */

	virtual HRESULT GetUnfoldTarget(CATBaseUnknown_var & result,CATBaseUnknown * AttrAccess,CATBaseUnknown * AttrKey)=0;
};

#endif
