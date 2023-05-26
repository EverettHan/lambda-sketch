#ifndef __CATAdpQueryPLMIDByPhysicalId_H
#define __CATAdpQueryPLMIDByPhysicalId_H

#include "CATPLMIntegrationAccess.h"
#include "CATOmxPortability.h"
#include "IUnknown.h"
#include "CATOmxOHMap.h"
#include "CATPLMID_Any.h"
#include "CATPLMID.h"

/** @see CATAdpQueryPLMIDByPhysicalId */
#define ADP_QUERY_INDEX     0x1
/** @see CATAdpQueryPLMIDByPhysicalId */
#define ADP_QUERY_M1        0x2
/** @see CATAdpQueryPLMIDByPhysicalId */
#define ADP_QUERY_NO_CACHE  0x4
/** @see CATAdpQueryPLMIDByPhysicalId */
#define ADP_QUERY_DEFAULT (ADP_QUERY_INDEX|ADP_QUERY_M1)

/**
 * Query a set of PLMID from their physicalid.
 * By default it uses the PLMID cache (on client side) to try to avoid a roundtrip query on server.
 * The missing PLMIDs from cache are requested on server (index or M1).
 * The cache is populated dynamically with retrieved PLMIDs from server.
 * If you want to use this method to detect deleted objects, do not use the cache: ADP_QUERY_NO_CACHE
 * @param ioPhysicalIdToPLMIDMap
 *   a physicalid to PLMID dictionary.
 *   in input, only the physicalids (non null CATPLMID_Any) must be provided with a NULL associated CATPLMID (CATPLMID_Null).
 *   If you have the CATPLMID_Any in its hexadecimal string form, you can convert it to a CATPLMID_Any (uuid) thanks to CATPLMID_Any::FromString 
 *   in output PLMID fields will be filled (if found)
 * @param iQueryTarget
 *   Legal values:
 *     ADP_QUERY_INDEX:     query on "index" server (servlet: /ematrix/mcs/SidlChunked?cmd=Sidl+Request&ProcName=IPML_ReadProcessor)
 *     ADP_QUERY_M1:        query on "M1" server (or TSTProvider) (servlet: /ematrix/i3dx/services/xmql)
 *     ADP_QUERY_NO_CACHE:  do not use PLMID cache, PLMIDs will be requested on the server only.
 *     ADP_QUERY_DEFAULT:   query the cache and then try query on "index" and "M1" until success o(rder is unspecified, use other values if you require a specific order).
 * @return
 *    S_OK:    all PLMIDs have been retrieved succesfully
 *    S_FALSE: only part of the PLMIDs have been retrieved succesfully (the others remaining NULL in ioPhysicalIdToPLMIDMap)
 *    E_XXX:   the query entirely failed.
 *
 */
extern "C" ExportedByCATPLMIntegrationAccess HRESULT CATAdpQueryPLMIDByPhysicalId(unsigned int iQueryTarget,CATOmxOHMap<CATPLMID_Any,CATPLMID>& ioPhysicalIdToPLMIDMap);

/**
 * Shortcut for previous API.
 */
ExportedByCATPLMIntegrationAccess CATPLMID CATAdpQueryPLMIDByPhysicalId(const CATPLMID_Any& iPhysicalId);

#endif
