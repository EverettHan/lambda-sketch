/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATAdpDWSQueryAttachmentResult_H
#define CATAdpDWSQueryAttachmentResult_H

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
#include "CATBooleanDef.h"
class CATIAdpPLMIdentificator;
class CATIAdpPLMIdentificator_var;
class CATPLMIDHashTable;

class ExportedByCATPLMIntegrationAccess CATAdpDWSQueryAttachmentResult
{
public:
  CATAdpDWSQueryAttachmentResult();
  virtual ~CATAdpDWSQueryAttachmentResult();

/**
 * Start the enumeration of the results.
 * <br><b>Role:</b>This method enables to initialize the enumeration of the results.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if everything ran ok.</li>
 *   <li><code>E_FAIL</code> if a fatal error occured during the operation. Nothing was done during the operation.</li>
 *  </ul>
 */
  HRESULT StartEnumeration();

/**
 * Enumerates the results available.
 * <br><b>Role:</b>This method enables to enumerate the set of results.
 *
 * @param oComponent [out]
 * The Component which attachment status is described in the result.
 * @param oStatus [out]
 * The attachment status of the Component.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if everything ran ok.</li>
 *   <li><code>S_FALSE</code> if no more result is available. All the results of the set were parsed.</li>
 *   <li><code>E_UNEXPECTED</code> if the iteration was not started.</li>
 *   <li><code>E_FAIL</code> if a fatal error occured during the operation. Nothing was done during the operation.</li>
 *  </ul>
 */
  HRESULT NextAttachmentResult( CATIAdpPLMIdentificator_var & oComponent, CATBoolean & oStatus );

/**
 * Get a specific result.
 * <br><b>Role:</b>This method enables to get the attachment status of a specific Component.
 *
 * @param iComponent [in]
 * The Component which attachment status is required.
 * @param oStatus [out]
 * The attachment status of the Component.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if everything ran ok.</li>
 *   <li><code>S_FALSE</code> if there is no result associated to the component.</li>
 *   <li><code>E_INVALIDARG</code> if the given @href CATIAdpPLMIdentificator is invalid.</li>
 *   <li><code>E_FAIL</code> if a fatal error occured during the operation. Nothing was done during the operation.</li>
 *  </ul>
 */
  HRESULT GetAttachmentResult( CATIAdpPLMIdentificator * iComponent, CATBoolean & oStatus );

/**
 * @nodoc
 */
  HRESULT AddAttachmentResult( CATIAdpPLMIdentificator * iComponent, CATBoolean iStatus );
  int ComputeSize();

private:
  CATAdpDWSQueryAttachmentResult( const CATAdpDWSQueryAttachmentResult & );
  CATAdpDWSQueryAttachmentResult & operator =( const CATAdpDWSQueryAttachmentResult & );

private:
  CATPLMIDHashTable * _Results;
  unsigned int _EnumerationIndex;
};
#endif
