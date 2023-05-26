 
/**
 * @level Protected
 * @usage U1
 */

#ifndef CATOmyExposedCacheServicesForDownload_H
#define CATOmyExposedCacheServicesForDownload_H

#include "CATOMYUtils.h"
#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATUuid.h"
#include "CATOmxList.h"

class CATOmyCioUrlUsageSavingCtx;

class ExportedByCATOMYUtils CATOmyExposedCacheServicesForDownload
{
  friend class CATOmyPowerIOCachingBusinessLogic;
public:
   // =============================================================
  // Download ID management 
  // =============================================================

  /** 
  * Retrieves a new download ID.
  * ID in [0,29], otherwise CATAssert.
  * @param oDLId [out]
  *  The download ID.
  * @return
  *   <code>S_OK</code> everything ran ok.
  *   <code>E_FAIL</code> Something went wrong.
  */
  static HRESULT ReserveDLId(CATUuid& oDLId);
  
  /** 
  * Specifies whether the download ID is reserved or not.
  * @param iDLId [in]
  *   The downloadID.
  * @return
  *   <code>S_OK</code> The ID is reserved.
  *   <code>S_FALSE</code> The ID is not reserved.
  *   <code>E_FAIL</code> Something went wrong.
  */
  static HRESULT IsDLIdBelongs(CATUuid& iDLId);
 
    /** 
  * Specifies a new id to reserve
  * The ID must has been previously reserved.
  * @param iDLId [in]
  *   The download ID.
  * @return
  *   <code>S_OK</code> Everything ran Ok.
  *   <code>S_FALSE</code> The ID is not reserved.
  *   <code>E_FAIL</code> Something went wrong.
  */
  static HRESULT AddDLId(CATUuid& iDLId);
  
  /** 
  * Don't use this download id as current anymore
  * The ID must has been previously reserved.
  * @param iDLId [in]
  *   The Download ID.
  * @return
  *   <code>S_OK</code> Everything ran Ok.
  *   <code>S_FALSE</code> The ID is not reserved.
  *   <code>E_FAIL</code> Something went wrong.
  */
  static HRESULT DetachDLId(CATUuid& iDLId);

  /** 
  * Releases the specified local save ID.
  * The ID must has been previously reserved.
  * @param iDLId [in]
  *   The Download ID.
  * @return
  *   <code>S_OK</code> Everything ran Ok.
  *   <code>S_FALSE</code> The ID is not reserved.
  *   <code>E_FAIL</code> Something went wrong.
  */
  static HRESULT ReleaseDLId(CATUuid& iDLId);
};
#endif
