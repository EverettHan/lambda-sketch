/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATAdpDWSQueryWorkspaceIdResult_H
#define CATAdpDWSQueryWorkspaceIdResult_H

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
class CATPLMIDHashTable;
class CATIAdpPLMIdentificator;
class CATIAdpPLMIdentificator_var;

class ExportedByCATPLMIntegrationAccess CATAdpDWSQueryWorkspaceIdResult
{
public:
  CATAdpDWSQueryWorkspaceIdResult();
  virtual ~CATAdpDWSQueryWorkspaceIdResult();

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
 * The Component which attached Workspace is described in the result.
 * @param oWorkspaceId [out]
 * The Workspace Identifier the Component is attached to.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if everything ran ok.</li>
 *   <li><code>S_FALSE</code> if no more result is available. All the results of the set were parsed.</li>
 *   <li><code>E_UNEXPECTED</code> if the iteration was not started.</li>
 *   <li><code>E_FAIL</code> if a fatal error occured during the operation. Nothing was done during the operation.</li>
 *  </ul>
 */
  HRESULT NextWorkspaceResult( CATIAdpPLMIdentificator_var & oComponent, CATIAdpPLMIdentificator_var & oWorkspaceId );

/**
 * Get a specific result.
 * <br><b>Role:</b>This method enables to get the Workspace the given Component is attached to.
 *
 * @param iComponent [in]
 * The Component which Workspace is required.
 * @param oWorkspaceId [out]
 * The Workspace the Component is attached to.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if everything ran ok.</li>
 *   <li><code>S_FALSE</code> if there is no result associated to the component.</li>
 *   <li><code>E_INVALIDARG</code> if the given @href CATIAdpPLMIdentificator is invalid.</li>
 *   <li><code>E_FAIL</code> if a fatal error occured during the operation. Nothing was done during the operation.</li>
 *  </ul>
 */
  HRESULT GetWorkspaceResult( CATIAdpPLMIdentificator * iComponent, CATIAdpPLMIdentificator_var & oWorkspaceId );

/**
 * @nodoc
 */
  HRESULT AddWorkspaceResult( CATIAdpPLMIdentificator * iComponent, CATIAdpPLMIdentificator * iWorkspace );
  int ComputeSize();

private:
  CATAdpDWSQueryWorkspaceIdResult( const CATAdpDWSQueryWorkspaceIdResult & );
  CATAdpDWSQueryWorkspaceIdResult & operator =( const CATAdpDWSQueryWorkspaceIdResult & );

  HRESULT ClearResults();

private:
  CATPLMIDHashTable * _Results;
  unsigned int _EnumerationIndex;
};
#endif
