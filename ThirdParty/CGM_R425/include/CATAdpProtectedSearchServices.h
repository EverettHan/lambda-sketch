/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
/**
 * @level Protected
 * @usage U1  
 */
#ifndef CATAdpProtectedSearchServices_H
#define CATAdpProtectedSearchServices_H
#include "CATPLMIntegrationAccessRestrictedBatchUse.h"
#include "IUnknown.h"
#include "CATCollec.h"
#include "CATPLMCoreType.h"
class CATLISTP(CATIAdpPLMIdentificator);
class CATIAdpErrorMonitor;

/**
* Services to search PLM components in a database.
*
* <br><b>Role</b>: Provides basic functions to search PLM data in a database.
 * <ul>
 * <li> Only batch applications can use those protected services.</li>
 * </ul>
*/
class ExportedByCATPLMIntegrationAccessRestrictedBatchUse CATAdpProtectedSearchServices
{
  public:

/**
 * Description of the two kind of depth used to perform the search operation.
 * <dt> <code><b>FirstLevel</b></code>     <dd> Only components from the first level are searched under the roots.
 * <dt> <code><b>FullLevel</b></code>      <dd> Components are searched recursively under the root.
 */
  enum SearchLevel { FirstLevel, FullLevel };

/**
 * Searches under the provided root references components from a given type.
 * <br><b>Role:</b>This methods enables the user to find components from a given type in the trees of the provided roots.
 * <ul>
 * <li> This method is for migration batches use only.</li>
 * <li> Each root is expanded independantly from the others at the provided level.</li>
 * <li> Only the components from the required type are returned to the user.</li>
 * <li> The provided roots are returned only if from <b>iSearchedType</b> type.</li>
 * <li> No structural in formation is kept on the retrieved components. It is just a set of independant components.</li>
 * </ul>
 * @param iRootReferences [in]
 *   The references which will be expanded. It is invalid if : 
 *   <ul>
 *   <li> The set is empty.</li>
 *   <li> The provided identifiers are invalid.</li>
 *   <li> At least one provided root is not a <b>PLMCoreReference</b> (@href CATPLMCoreType ).</li>
 *   </ul>
 * @param iLevel [in]
 *   The level used to expand the provided references. It is invalid if its value is not defined.
 * @param iSearchedCoreType [in]
 *   The core type of the components which are searched.
 * @param oComponents [out, CATBaseUnknown#Release]
 *   The components found in the database. The list is emptied by the beginning of the method. The returned indentifiers must be released when useless.
 * @param iopErrorMonitor [inout]
 *   The ErrorMonitor dedicated to store and handle all PLM Errors raised during the execution of this service.
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt> if the service could successfully enquire the database. If no component of the provided was found, the returned <b>oComponents</b> list is empty.</li> 
 *   <li><tt>E_FAIL</tt> if a failure occured when searching the components. The blocking error can be accessed through @href CATError#CATGetLastError method.</li>
 *   <li><tt>E_INVALIDARG</tt> if some provided entries are invalid.</li>
 *   </ul>
 */ 
  static HRESULT SearchComponentsFromRoot( const CATLISTP(CATIAdpPLMIdentificator) & iRootReferences, SearchLevel iLevel, 
                                           const CATPLMCoreType & iSearchedCoreType, CATLISTP(CATIAdpPLMIdentificator) & oComponents,
										   CATIAdpErrorMonitor* iopErrorMonitor = NULL);
};
#endif
