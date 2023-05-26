 
/**
 * @level Protected
 * @usage U1
 */

#ifndef CATOmyExposedCacheServicesForLocalSave_H
#define CATOmyExposedCacheServicesForLocalSave_H

#include "CATOMYUtils.h"
#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATUuid.h"
#include "CATOmxList.h"

class CATOmyCioUrlUsageSavingCtx;

class ExportedByCATOMYUtils CATOmyExposedCacheServicesForLocalSave
{
  friend class CATOmyPowerIOCachingBusinessLogic;
public:
  enum Instanciation
  {
      InitOK,
      Empty,
      TemporaryCache,
    CuteIOMode
  };

  /** 
  * Instanciates PowerIO for LS and executes the first check
  * @param oInstanciationResult [out]
  *  The instanciation result enumeration.
  * @return
  *   <code>S_OK</code> everything ran ok.
  *   <code>E_FAIL</code> Something went wrong.
  */
  static HRESULT CheckPowerIO(Instanciation &oInstanciationResult);

   /** 
  * Does the complete check of PowerIO Cache.
  * @param oInstanciationResult [out]
  *  The check result enumeration.
  * @return
  *   <code>S_OK</code> everything ran ok.
  *   <code>E_FAIL</code> Something went wrong.
  */
  static HRESULT FullCheckPowerIO(Instanciation &oInstanciationResult);

  /** 
  * Retrieves a new local save ID.
  * ID in [0,29], otherwise CATAssert.
  * @param oLSId [out]
  *  The Local Save ID.
  * @return
  *   <code>S_OK</code> everything ran ok.
  *   <code>E_FAIL</code> Something went wrong.
  */
  static HRESULT ReserveLsId(CATUuid& oIdLs);
  
  /** 
  * Specifies whether the Local Save ID is reserved or not.
  * @param iLSId [in]
  *   The Local Save ID.
  * @return
  *   <code>S_OK</code> The ID is reserved.
  *   <code>S_FALSE</code> The ID is not reserved.
  *   <code>E_FAIL</code> Something went wrong.
  */
  static HRESULT IsLsIdBelongs(CATUuid& iIdLs);
 
    /** 
  * Specifies a new id to reserve
  * The ID must has been previously reserved.
  * @param iLSId [in]
  *   The Local Save ID.
  * @return
  *   <code>S_OK</code> Everything ran Ok.
  *   <code>S_FALSE</code> The ID is not reserved.
  *   <code>E_FAIL</code> Something went wrong.
  */
  static HRESULT AddLSId(CATUuid& iIdLs);
  
  /** 
  * Don't use this ls id as current anymore
  * The ID must has been previously reserved.
  * @param iLSId [in]
  *   The Local Save ID.
  * @return
  *   <code>S_OK</code> Everything ran Ok.
  *   <code>S_FALSE</code> The ID is not reserved.
  *   <code>E_FAIL</code> Something went wrong.
  */
  static HRESULT DetachLSId(CATUuid& iIdLs);

  /** 
  * Releases the specified local save ID.
  * The ID must has been previously reserved.
  * @param iLSId [in]
  *   The Local Save ID.
  * @return
  *   <code>S_OK</code> Everything ran Ok.
  *   <code>S_FALSE</code> The ID is not reserved.
  *   <code>E_FAIL</code> Something went wrong.
  */
  static HRESULT ReleaseLSId(CATUuid& iIdLs);

  /** 
  * Release the streams from iListOfSUsageCtx 
  * with the LSID stored in the static CATOmyPowerIOCachingBusinessLogic
  */
  static HRESULT ReleaseUrlLSId(CATOmxList<CATOmyCioUrlUsageSavingCtx> & iListOfSUsageCtx);
};
#endif
