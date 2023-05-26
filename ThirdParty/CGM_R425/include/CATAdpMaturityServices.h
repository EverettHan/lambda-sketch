/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2006
/**
* @CAA2Level L1
* @CAA2Usage U1  
*/
#ifndef CATAdpMaturityServices_H
#define CATAdpMaturityServices_H

#include "CATPLMIntegrationAccess.h"
#include "CATErrorDef.h"
#include "CATCollec.h"
class CATLISTV(CATUnicodeString);
class CATIAdpPLMIdentificator;
class CATUnicodeString;
class CATIAdpPLMErrorReviewer;

/**
 * Class of services enabling to manage maturity of references in the database.
 *
 * <br><b>Role</b>: Provides a set of services enabling the user to manage maturity of a reference in the database.
 * <ul>
 * <li> To process a lock operation, you will need a PLM identificator, @href CATIAdpPLMIdentificator interface pointer. 
 * You can use @href CATAdpQueryServices to retrieve it.</li>
 * </ul>
 */
class ExportedByCATPLMIntegrationAccess CATAdpMaturityServices
{
public:

/** 
 * Returns the current maturity state of a reference and its possible maturity transitions.
 * <br><b>Role:</b> Retrieves in the database the current maturity state of a reference and the transitions which can be applied on the current maturity state. 
 * <ul>
 * <li>The database informations are imbedded in the identifier of the object itself.</li>
 * <li>The applicable transitions depend of the input object type and of its current maturity state.</li>
 * <li>Error is available through @href CATError#CATGetLastError if no maturity graph is defined in the metadata for the component.</li>
 * </ul>
 *
 * @param iComponent [in]
 *   The identifier of the reference.
 *   It is invalid if :
 *   <ul>
 *   <li> The pointer is nul.</li>
 *   <li> Or, if it is not a reference (<b>CATPLMCoreReference</b> or <b>CATPLMCoreRepReference</b>).</li>
 *   </ul>
 * @param oState [out]
 *   The current maturity state of the reference.
 * @param oTransitions [out]
 *   The transitions which can possibly be applied to the reference to make its maturity state evolve.
 * @param iopErrorReviewer [inout]
 *   The ErrorReviewer dedicated to store and handle all PLM Errors raised during the execution of this service.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the maturity informations were successfully read in the database.</li>
 *   <li><code>E_INVALIDARG</code> if <tt>iComponent</tt> is invalid.</li>
 *   <li><code>E_FAIL</code> if the maturity information could not be read in the database or the component has no maturity graph.
 *   Nothing was done during the operation. 
 *   The blocking error can be accessed through @href CATError#CATGetLastError method.</li>
 *   </ul>
 */
  static HRESULT GetStateAndPossibleTransitions( CATIAdpPLMIdentificator * iComponent, 
                                                 CATUnicodeString & oState, CATLISTV(CATUnicodeString) & oTransitions, CATIAdpPLMErrorReviewer *  iopErrorReviewer = NULL );

/** 
 * Applies the provided transition to the provided reference.
 * <br><b>Role:</b> Makes the maturity of the reference evolve in the database by applying the provided transition. 
 * <ul>
 * <li>The database informations are imbedded in the identifier of the object itself.</li>
 * <li><code>ERR_02_MATURITY</code> error is available through @href CATError#CATGetLastError if the given transition cannot be applied to the component.</li>
 * <li>Error is available through @href CATError#CATGetLastError if no maturity graph is defined in the metadata for the component.</li>
 * </ul>
 *
 * @param iComponent [in]
 *   The identifier of the reference which maturity is required to evolve. 
 *   If so, result will be <code>E_FAIL</code>.
 *   It is invalid if :
 *   <ul>
 *   <li> The pointer is nul.</li>
 *   <li> Or, if it is not a reference (<b>CATPLMCoreReference</b> or <b>CATPLMCoreRepReference</b>).</li>
 *   </ul>
 * @param iTransition [in]
 *   The transition requested to be applied to the reference.
 *   <ul>
 *   <li> To ensure that the transition can be applied, make sure it was obtained through the @href CATAdpMaturityServices#GetStateAndPossibleTransitions.</li> 
 *   <li> Null strings are invalid transition and result in a <code>E_INVALIDARG</code> return.</li> 
 *   </ul>
 * @param iopErrorReviewer [inout]
 *   The ErrorReviewer dedicated to store and handle all PLM Errors raised during the execution of this service.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the the maturity transition could successfully be applied to the reference in the database.</li>
 *   <li><code>E_INVALIDARG</code> if <tt>iComponent</tt> or <b>iTransition</b> are invalid.</li>
 *   <li><code>E_FAIL</code> if the operation failed. Nothing was done during the operation. The blocking error can be accessed through @href CATError#CATGetLastError method.</li>
 *   </ul>
 */
  static HRESULT ApplyMaturityTransition( CATIAdpPLMIdentificator * iComponent, const CATUnicodeString & iTransition, CATIAdpPLMErrorReviewer *  iopErrorReviewer = NULL );
};
#endif
