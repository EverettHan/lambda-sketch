#ifndef CATOMBCACHEFILESTATUSMANAGER_H
#define CATOMBCACHEFILESTATUSMANAGER_H

#include "CATOmbCacheFileStatus.h"
#include "CATOmxOHMap.h"
#include "CATOmbPersistency.h"

class CATOmbLoadableDataUniqueKey;
template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmxPair<const CATBaseUnknown* /*Rep*/, CATOmbLoadableDataUniqueKey> >::manager();
template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmbCacheFileStatus>::manager();

class ExportedByCATOmbPersistency CATOmbCacheFileStatusManager
{
public:
  ~CATOmbCacheFileStatusManager() = default;

  static CATOmbCacheFileStatusManager& Get();

  /* 
  Add a SD to analyse for a grouped request
  iRep should be loaded in session
  an SD with iKey as key identifier has to be attached to the rep;
  Return E_XXX : something went wrong. ie the rep is not in session or doesn't have an SD identified by iKey
  */
  HRESULT AddRequest(const CATBaseUnknown* iRep, const CATOmbLoadableDataUniqueKey& iKey);

  /*
  Computes status for all requests added to the CATOmbCacheFileStatusManager
  return
    E_XXX : catastrophic failure, nothing done
    S_FALSE : some requests failed (entirely or partially). details on error will be found in CATOmbCacheFileStatus
    S_OK : everything is ok
  */
  HRESULT ComputeRequests();

  /*
  Get Result for a given request
  if the asked result has not been computed (or request never added), an empty status with an error will be returned
  Each CATOmbCacheFileStatus contains its own error if something went wrong. Check these out.
  non exhaustive errors/warning list :
  ERR_OMB_1300 = "No stream descriptor found with this key : /p1,/p2,/p3";
  ERR_OMB_1301 = "Empty stream is associated to stream descriptor";
  WAR_OMB_1302 = "No network speed is available";
  ERR_OMB_1303 = "No cache status for this SD key";
  WAR_OMB_1304 = "Cache Status computation not called. Empty results";
  */
  CATOmbCacheFileStatus GetResult(const CATBaseUnknown* iRep, const CATOmbLoadableDataUniqueKey& iKey);

  /*
  Clear all requests and results stored in CATOmbCacheFileStatusManager and free memory
  */
  void ClearContent();

  /* 
  Run a single cache status for a given SD, identified by a iKey on the iRep
  iRep has to be loaded in session
  oStatus contains all cache status information, and eventual errors if any occured.
  non exhaustive errors/warning list :
  ERR_OMB_1300 = "No stream descriptor found with this key : /p1,/p2,/p3";
  ERR_OMB_1301 = "Empty stream is associated to stream descriptor";
  WAR_OMB_1302 = "No network speed is available";
  ERR_OMB_1303 = "No cache status for this SD key";
  WAR_OMB_1304 = "Cache Status computation not called. Empty results";
  return :
    S_OK : everything ran good
    S_FALSE : some information are missing;
    E_XXX : nothing could be done
  */
  static HRESULT ComputeSingleRequest(const CATBaseUnknown* iRep, const CATOmbLoadableDataUniqueKey& iKey, CATOmbCacheFileStatus& oStatus);


private:
  CATOmbCacheFileStatusManager() = default;
  CATOmxOHMap<CATOmxPair<const CATBaseUnknown* /*Rep*/, CATOmbLoadableDataUniqueKey>, CATOmbCacheFileStatus> _requests;
};

#endif
