/**
 * @level Protected
 * @usage U5
 */
#ifndef CATIAdpDWSMappingTableQueryCB_H
#define CATIAdpDWSMappingTableQueryCB_H

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationAccess IID IID_CATIAdpDWSMappingTableQueryCB;
#else
extern "C" const IID IID_CATIAdpDWSMappingTableQueryCB ;
#endif

class CATAdpDWSMappingTableResult;
class CATAdpDWSMappingTableQueryDefinition;

/**
 * Interface representing a notifier to follow actions taken by CATAdpProtectedDWSMappingTableQuery.
 */
class ExportedByCATPLMIntegrationAccess CATIAdpDWSMappingTableQueryCB: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
   * Informs that the service has just received data from a mapping table. Starts an update transaction.
   * The call of this method precedes calls of either ResultAvailable() or ErrorEncountered().
   * @return
   *   <code>S_OK</code> if everything ran ok, otherwise <code>E_FAIL</code>.
   */
  virtual HRESULT BeginUpdate() = 0;

  /**
   * Informs that the service has just received a list of entities from a mapping table.
   * <br><b>Role</b>: CATAdpProtectedDWSMappingTableQuery informs caller that it received a list of entities corresponding
   * to the query definition given as input of @see CATAdpProtectedDWSMappingTableQuery#ProcessQuery.
   * The call of this method is preceded by BeginUpdate(), and is followed by EndUpdate().
   * @param iResult [in]
   *   An enumerator on the list of entities.
   * @return
   *   <code>S_OK</code> if everything ran ok, otherwise <code>E_FAIL</code>.
   */
  virtual HRESULT ResultAvailable(CATAdpDWSMappingTableResult & iResult) = 0;

  /**
   * Informs that an error occurred during query.
   * <br><b>Role</b>: CATAdpProtectedDWSMappingTableQuery informs caller that an error occurred.
   * The error is sent to the Error monitor given to CATAdpProtectedDWSMappingTableQuery.
   * @return
   *   <code>S_OK</code> if everything ran ok, otherwise <code>E_FAIL</code>.
   */
  virtual HRESULT ErrorEncountered() = 0;

  /**
   * Closes an update transaction.
   * @return
   *   <code>S_OK</code> if everything ran ok, otherwise <code>E_FAIL</code>.
   */
  virtual HRESULT EndUpdate() = 0;

  /**
   * Informs that the query is now complete.
   * @param iQueryDefinition [in]
   *   The corresponding query definition.
   * @return
   *   <code>S_OK</code> if everything ran ok, otherwise <code>E_FAIL</code>.
   */
  virtual HRESULT CloseWithRequest(const CATAdpDWSMappingTableQueryDefinition & iQueryDefinition) = 0;

};

#endif
