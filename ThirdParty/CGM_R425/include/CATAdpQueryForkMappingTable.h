#ifndef __CATAdpQueryForkMappingTable_H
#define __CATAdpQueryForkMappingTable_H

// System
#include "CATUnicodeString.h"
// ObjectModelerCollection
#include "CATOmxOHMap.h"
#include "CATOmxPortability.h"
// CATPLMIdentificationAccess
#include "CATPLMID_Simple.h"
// CATPLMIntegrationAccess
#include "CATPLMIntegrationAccess.h"

constexpr int ADP_QUERY_FORK_SOURCE_TO_CLONE = 1;
constexpr int ADP_QUERY_FORK_CLONE_TO_SOURCE = -1;

constexpr HRESULT E_DUPLICATEFORKMAPPINGTABLEENTRIES = MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x8e6F);

/**
 * Query server fork mapping table (see fork server documentation and/or CATIPLMTransferToNewProject documentation)
 * @param iCollabSpace
 *   collaborative space where the fork operations are performed (target/"sistership" collab space)
 * @param iDirection
 *    ADP_QUERY_FORK_SOURCE_TO_CLONE: search clone/"sistership" PLMIDs from source/"prototype" PLMIDs
 *    ADP_QUERY_FORK_CLONE_TO_SOURCE: search source/"prototype" PLMIDs from clone/"sistership" PLMIDs
 * @param ioPLMIDMap
 *  in input, keys must contain the PLMIDs to search (see iDirection parameter)
 *  in output, values are assigned "mapped" PLMIDs if found
 */
ExportedByCATPLMIntegrationAccess HRESULT CATAdpQueryForkMappingTable(const CATUnicodeString& iCollabSpace, int iDirection, CATOmxOHMap<CATPLMID_Simple, CATPLMID_Simple>& ioPLMIDMap);


#endif
