/**
 * @level Protected
 * @usage U1
 */
#ifndef CATAdpDWSMappingTableResult_H
#define CATAdpDWSMappingTableResult_H

#include "CATPLMIntegrationAccess.h"
#include "CATAdpDWSMappingTableEntity.h"
#include "CATOmxSharable.h"

class CATIAdpPLMIdentificator;
class CATPLMID;
class CATPLMIDHashTable;
/**
 * Class representing an enumerator on a list of entities from a DWS Mapping Table.
 */
class ExportedByCATPLMIntegrationAccess CATAdpDWSMappingTableResult : public CATOmxSharable
{
  friend class CATAdpProtectedDWSMappingTableQuery;
  friend class CATDWSMappingTableQueryRecordParser;
  friend class CATDWSMappingTableSynchroRecordParser;

public:

  CATAdpDWSMappingTableResult();
  virtual ~CATAdpDWSMappingTableResult();

  /**
   * Start the enumeration of the results.
   */
  HRESULT StartEnumeration();

  /**
   * Enumerates the entities available.
   * @param oEntity [out]
   *   The entity of the DWS Mapping table.
   * @return
   *   <ul>
   *   <li><code>S_OK</code> if everything ran ok.</li>
   *   <li><code>S_FALSE</code> if no more result is available. All the results of the set were parsed.</li>
   *   <li><code>E_UNEXPECTED</code> if the iteration was not started.</li>
   *   <li><code>E_FAIL</code> if a fatal error occured during the operation. Nothing was done during the operation.</li>
   *  </ul>
   */
  HRESULT NextMappingTableResult(CATAdpDWSMappingTableEntity & oEntity);

  /**
   * Gets the entity corresponding to a component in the workspace.
   * @param iComponentInWorkspace [in]
   *   The identifier of a component in the workspace.
   * @param oEntity [out]
   *   The corresponding entity of the DWS Mapping table.
   * @return
   *   <ul>
   *   <li><code>S_OK</code> if the entity was found among these results.</li>
   *   <li><code>S_FALSE</code> if the entity was NOT found among these results.</li>
   *   <li><code>E_FAIL</code> if a fatal error occured during the operation. Nothing was done during the operation.</li>
   *  </ul>
   */
  HRESULT GetEntityForWorkspaceComponent(CATIAdpPLMIdentificator * iComponentInWorkspace,
                                         CATAdpDWSMappingTableEntity & oEntity);

  /**
   * Gets the entity corresponding to a component in the parent workspace.
   * @param iComponentInParentWorkspace [in]
   *   The identifier of a component in the parent workspace.
   * @param oEntity [out]
   *   The corresponding entity of the DWS Mapping table.
   * @return
   *   <ul>
   *   <li><code>S_OK</code> if the entity was found among these results.</li>
   *   <li><code>S_FALSE</code> if the entity was NOT found among these results.</li>
   *   <li><code>E_FAIL</code> if a fatal error occured during the operation. Nothing was done during the operation.</li>
   *  </ul>
   */
  HRESULT GetEntityForParentWorkspaceComponent(CATIAdpPLMIdentificator * iComponentInParentWorkspace,
                                               CATAdpDWSMappingTableEntity & oEntity);

private:

  HRESULT ClearResults();
  HRESULT AddMappingTableEntity(CATPLMID & iComponentId,
                                CATPLMID & iParentComponentId,
                                CATPLMID & iWorkspaceId,
                                CATPLMID & iParentWorkspaceId,
                                CATAdpDWSMappingTableEntity::CATPLMWorkspaceStatus iStatus,
                                CATAdpDWSMappingTableEntity::CATPLMWorkspaceReservationStatus iReservedLocal,
                                CATAdpDWSMappingTableEntity::CATPLMWorkspaceReservationStatus iReservedParent,
                                CATPLMCEStamp & iCEStamp);

  HRESULT GetEntityForParentWorkspaceComponent(CATIAdpPLMIdentificator * iComponentInParentWorkspace,
                                               CATAdpDWSMappingTableEntity *& oEntity);

  CATPLMIDHashTable * _Results;
  CATPLMIDHashTable * _ResultsByParentId;
  unsigned int _EnumerationIndex;

  /* forbidden operations */
  CATAdpDWSMappingTableResult( const CATAdpDWSMappingTableResult & );
  CATAdpDWSMappingTableResult & operator =( const CATAdpDWSMappingTableResult & );

};

#endif
