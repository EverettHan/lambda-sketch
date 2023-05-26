/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
/**
* @level Protected
* @usage U1  
*/
#ifndef CATAdpProtectedDeleteServices_H
#define CATAdpProtectedDeleteServices_H
#include "CATPLMIntegrationAccessRestrictedModelerUse.h"
#include "IUnknown.h"
#include "CATCollec.h"
class CATLISTP(CATIAdpPLMIdentificator);
class CATAdpResultIterator;
class CATIAdpErrorMonitor;

/**
* Services to manage deletion of PLM components from a database.
*
* <br><b>Role</b>: Provides all basic functions to delete PLM data from a database.
*/
class ExportedByCATPLMIntegrationAccessRestrictedModelerUse CATAdpProtectedDeleteServices
{
public:

  /** 
  * Enables to delete the provided references from the database.
  *
  * <br><b>Role</b>: This method deletes the provided references from the database.
  * <ul>
  * <li> If no provider is currently connected, the query will result in a E_FAIL return.</li>
  * <li> In the EV5 provider, the components aggregated under the deleted reference will be deleted as well.</li>
  * <li> In the EV5 provider, the mono-instantiated representation references of the instances aggregated under the deleted references will be deleted as well.</li>
  * <li> In the EV5 provider, the instances of the deleted reference will be destroyed as well. It could be different in the future.</li>
  * </ul>
  *
  * @param iReferencesToDelete [in]
  *   The identificators of the references which will be deleted from the database.
  *   <ul>
  *   <li>At least one reference must be provided.</li>
  *   <li>Only references and representation references can be provided by the user.</li>
  *   <li>if some of the provided references are available in the session, they will be unloaded if possible. If not , and if the delete command succeeds in repository, the api will return S_FALSE</li>
  *   </ul>
  *
  * @param iopErrorMonitor [inout]
  *   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this service.
  *
  * @return
  *   <ul>
  *   <li><code>S_OK</code> if the references were all removed from the database.</li>
  *   <li><code>S_FALSE</code> if the references were all removed from the database and if some of these references were present in session and were not all unloaded.</li>
  *   <li><code>E_FAIL</code> if at least one reference could not be removed or an error occured. Nothing was done during the operation.
  *   The blocking error can be accessed through @href CATError#CATGetLastError protocol.</li>
  *   <li><code>E_INVALIDARG</code> if the provided <tt>iReferencesToDelete</tt> is invalid.</li>
  *   </ul>
  *
  */
  static HRESULT DeleteReferences( const CATLISTP(CATIAdpPLMIdentificator) & iReferencesToDelete, CATIAdpErrorMonitor * iopErrorMonitor = 0);

  /** 
  * Enables to simulate the deletion of the provided references from the database.
  *
  * <br><b>Role</b>: This method simulates the deletion of the provided references from the database. It provides
  * to the user the ability to see which deletion errors would occur during such a deletion operation on the server,
  * this depending on the propagation rules.
  * <ul>
  * <li> If no provider is currently connected, the query will result in a E_FAIL return.</li>
  * <li> Deletion rule: the components aggregated under the deleted reference will be deleted as well.</li>
  * <li> Deletion rule: the mono-instantiated representation references of the instances aggregated under the deleted references will be deleted as well.</li>
  * </ul>
  * The result can be obtained by the user through the @href CATAdpResultIterator#Next protocol. Here are the possible
  * errors for a provided reference:
  * <ul>
  * <li> <code>ERR_01</code>: The component is opened in the session</li> 
  * <li> <code>ERR_02</code>: The reference is still instantiated outside the deletion scope</li> 
  * <li> <code>ERR_03</code>: The reference is not VPLM controlled</li> 
  * <li> <code>ERR_05</code>: The component is opened in the session. The component can be unloaded but some tied modifications in session will be lost</li> 
  * <li> <code>ERR_06</code>: The component is opened in the session and can not be unloaded from the session</li> 
  * <li> <code>ERR_07</code>: The component is opened in the session, it can be unloaded from the session but at least another component is held in session</li> 
  * <li> <code>ERR_09</code>: The reference is instantiated outside the deletion scope but you don’t have sufficient privileges to access the instance</li> 
  * <li> <code>ERR_10</code>: The reference instantiating this mono-intantiated representation cannot be deleted so it cannot be deleted either</li> 
  * <li> <code>ERR_11</code>: The given component is not compliant with this deletion protocol. Only IRPC reference, IRPC repreference and pure ER businesstype are compliant with this protocol</li> 
  * </ul>
  *
  * @param iReferencesToDelete [in]
  *   The identificators of the references which will be deleted from the database.
  *   <ul>
  *   <li>At least one reference must be provided.</li>
  *   <li>Only references and representation references can be provided by the user. Other types of components will result in a E_INVALIDARG return.</li>
  *   <li>The provided references must not be available in the session.</li>
  *   </ul>
  *
  * @param oIterator [out, delete]
  *   Access to a description of the errors which occured for each reference provided.
  *
  * @return
  *   <ul>
  *   <li><code>S_OK</code> if the simulation ran succesfully. The result of the simulation is available on the returned iterator.</li>
  *   <li><code>E_FAIL</code> if an unrecoverable error occured during the simulation. Nothing was done during the operation.
  *   The blocking error can be accessed through @href CATError#CATGetLastError protocol.</li>
  *   <li><code>E_INVALIDARG</code> if the provided <tt>iReferencesToDelete</tt> is invalid.</li>
  *   </ul>
  *
  */
  static HRESULT SimulateDeletion( const CATLISTP(CATIAdpPLMIdentificator) & iReferencesToDelete,  
    CATAdpResultIterator *& oIterator );

};
#endif
