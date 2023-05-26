/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2006
/**
* @CAA2Level L1
* @CAA2Usage U1  
*/
#ifndef CATAdpVersioningServices_H
#define CATAdpVersioningServices_H

#include "CATPLMIntegrationAccess.h"
#include "CATErrorDef.h"
#include "CATCollec.h"
class CATLISTP(CATAdpQueryResult);
class CATIAdpPLMIdentificator;
class CATTime;
class CATIAdpPLMErrorReviewer;

/**
 * Class of services enabling to manage versioning of components in the database.
 *
 * <br><b>Role</b>: Provides a set of services enabling the user to manage versioning of components in the database.
 * <ul>
 * <li> To process such operations, you will need a @href CATIAdpPLMIdentificator . You can obtain it by using Query services 
 * before using versioning services (@href CATAdpQueryServices ).</li>  
 * </ul>
 */
class ExportedByCATPLMIntegrationAccess CATAdpVersioningServices
{
public:

/** 
 * Creates a new major version of a component.
 * <br><b>Role:</b> Creates a new major version of a reference, a representation reference or an entity in the database. 
 * This operation is not available if the corresponding component is loaded in the session, nor if the component
 * is not the last major version of a version family.
 * <ul>
 * <li>The database informations are imbedded in the identifier of the object itself.</li>
 * <li><code>ERR_01_NEWVERSION</code> error is available through @href CATError#CATGetLastError if the given component is in session.</li>
 * </ul>
 *
 * @param iObjectToTreat [in]
 *   The identifier of the component to version.
 *   <ul>
 *   <li>The component must not be loaded in a session. If so, result will be <code>E_FAIL</code>.</li>
 *   <li>The component must be a reference, a representation reference or an entity. If not, result will be <code>E_INVALIDARG</code>.</li>
 *   <li>The component must be the last major version of a version family. If not, the call will result in a server error.</li>
 *   </ul>
 * @param iApplicabilityDate [in]
 *   The applicability date of the new major version of the component.
 * @param oVersioned [out]
 *   The identifier of the new major version of the component.
  * @param iopErrorReviewer [inout]
 *   The ErrorReviewer dedicated to store and handle all PLM Errors raised during the execution of this service.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the new major version of the component was created in the database.</li>
 *   <li><code>E_INVALIDARG</code> if <tt>iObjectToTreat</tt> is not a reference or is null.</li>
 *   <li><code>E_FAIL</code> if the new version could not be created in the database. Nothing was done during the operation. 
 *   The blocking error can be accessed through @href CATError#CATGetLastError method.</li>
 *   </ul>
 */
  static HRESULT NewVersion( CATIAdpPLMIdentificator * iObjectToTreat, CATTime & iApplicabilityDate,
                             CATIAdpPLMIdentificator *& oVersioned, CATIAdpPLMErrorReviewer *  iopErrorReviewer = NULL );

/** 
 * Gets the available major versions of a component.
 * <br><b>Role:</b> Retrieves in the database all the available major versions of a reference or a representation reference.
 * <ul>
 * <li>The database informations are imbedded in the identifier of the object itself.</li>
 * <li>No order is guaranteed in return for the new versions of the component.</li>
 * <li><code>ERR_02_NEWVERSION</code> error is available through @href CATError#CATGetLastError if at least one major version could not be retrieved for this component.</li>
 * </ul>
 *
 * @param iComponent [in]
 *   The identifier of the component which major versions are required. The component must be a reference or a representation reference. 
 *   If not, result will be <code>E_INVALIDARG</code>.
 * @param oQueryResults [out]
 *   Returned list with all retrieved objects given access through @href CATAdpQueryResult contract. 
 *   <ul>
 *   <li> The list is emptied by the beginning of the method.</li> 
 *   <li> You must delete the elements of the list when useless.</li> 
 *   <li> These objects are not loaded in a session. </li>
 *   <li> Objects are identified through @href CATIAdpPLMIdentificator by using the @href CATAdpQueryResult#GetIdentifier method.</li>
 *   <li> The attributes obtained through the @href CATAdpQueryResult#GetAttributeSet method are <tt>PLM_ExternalID</tt> and <tt>V_Version</tt>.</li>
 *   </ul>
 * @param iopErrorReviewer [inout]
 *   The ErrorReviewer dedicated to store and handle all PLM Errors raised during the execution of this service.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the all the major versions of the component could be retrieved in the database.</li>
 *   <li><code>E_INVALIDARG</code> if <tt>iComponent</tt> is not a reference or is null.</li>
 *   <li><code>E_FAIL</code> if the operation failed. The returned list is empty. The blocking error can be accessed through @href CATError#CATGetLastError method.</li>
 *   </ul>
 */
  static HRESULT GetAllVersions( CATIAdpPLMIdentificator * iComponent, 
                                 CATLISTP(CATAdpQueryResult) & oQueryResults, CATIAdpPLMErrorReviewer *  iopErrorReviewer = NULL );
};
#endif
