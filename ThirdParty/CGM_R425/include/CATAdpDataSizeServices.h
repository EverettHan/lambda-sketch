/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2006
/**
* @CAA2Level L1
* @CAA2Usage U1  
*/
#ifndef CATAdpDataSizeServices_H
#define CATAdpDataSizeServices_H

#include "CATPLMIntegrationAccess.h"
#include "CATErrorDef.h"
#include "CATCollec.h"
class CATLISTP(CATIAdpPLMIdentificator);
class CATIAdpPLMErrorReviewer;

/**
 * Class of services enabling to get the size of data stored in vault.
 *
 * <br><b>Role</b>: Provides a set of services enabling the user to retrieve the size of data in vault.
 * <ul>
 * <li> To process a lock operation, you will need a PLM identificator, @href CATIAdpPLMIdentificator interface pointer. 
 * You can use @href CATAdpQueryServices to retrieve it, or use the @href CATIPLMComponent#GetAdpID method if 
 * your component is already in session.</li>
 * </ul>
 */
class ExportedByCATPLMIntegrationAccess CATAdpDataSizeServices
{
public:

/** 
 * Gets the size in vault of representations.
 * <br><b>Role:</b>Retrieves the cumulative size of the set of representations provided. The returned size is
 * independent from the session.
 * @param iRepresentationsIds [in]
 *   The identifiers of representations. Only representations are supported. The set is invalid if :
 *   <ul>
 *   <li> The list is empty.</li>
 *   <li> Or, at least one element of the list is not a representation.</li>
 *   </ul>
 * @param oRepsSize [out]
 *   The global size in vault of the set of representations. The unit is the kilobyte.
 * @param iopErrorReviewer [inout]
 *   The ErrorReviewer dedicated to store and handle all PLM Errors raised during the execution of this service.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the size was succesfully computed.</li>
 *   <li><code>E_INVALIDARG</code> if an invalid set of representations was provided.</li>
 *   <li><code>E_FAIL</code> if a fatal error occured during the operation. The blocking error can be accessed through @href CATError#CATGetLastError method.</li>
 *   </ul>
 */
  static HRESULT GetRepresentationsDataSize( const CATLISTP(CATIAdpPLMIdentificator) & iRepresentationsIds, unsigned int & oRepsSize, CATIAdpPLMErrorReviewer *  iopErrorReviewer = NULL );

};
#endif
