/**
* @level Protected
* @usage U1
*/

#ifndef CATOmyMetaDataCache_H
#define CATOmyMetaDataCache_H

#include "CATOMYCuteIO.h"
#include "CATOmxSharable.h"
#include "CATOmxSR.h"
#include "CATUnicodeString.h"

class ExportedByCATOMYCuteIO CATOmyMetaDataCacheLifeCycleManager : public CATOmxSharable
{  
public:
  CATOmyMetaDataCacheLifeCycleManager() {}
  virtual ~CATOmyMetaDataCacheLifeCycleManager() {}
  virtual HRESULT Configure(const CATUnicodeString& MetaDataCachePath, CATULONG32 iMaxCacheSizeInMo, CATULONG32 iMaxCacheElements, CATBoolean iPersistentCache)=0;
  virtual HRESULT GetCurrentCacheMaxSize(CATULONG32& oCurrentCacheSize)=0;
  virtual HRESULT GetCurrentCacheElements(CATULONG32& oNumbersOfElements)=0;
  virtual HRESULT ReduceNbrOfElements(CATULONG32 iNbElementToDelete)=0;
  virtual HRESULT ReduceSizeOnDisk(CATUINT32 iSizeToDeleteInMo)=0;
  virtual HRESULT CleanAll()=0;
};

/** 
FMR-6650194
CAADELWkiExposeUseItf.tst CAAWKIRestoreSpecificPropertyCmd_20xfd07
DELPLMWorkInstructionUINew.tst	DELWKIR421IR-617423_3AxisExplode_20xfd07
DELPLMWorkInstructionUINew.tst	DELWKIR421Fun078591_AT1_RestoreSpec_20xfd07
DELPLMWorkInstructionUINew.tst	DELWKIR421FUN076980_3AxisExplode_AT7_20xfd07
DELPLMWorkInstructionUINew.tst	DELWKIR419Fun074805_AT3_CAAWKIViewEdition_MarkerPosition_20xfd07
DELPLMWorkInstructionUINew.tst	DELWKIR421FUN076351_AVP_AT9_SubViewContextBar_20xfd07
DELPLMWorkInstructionUINew.tst	DELWKIR419Fun074805_AT2_EKLWKIVieEdi_SetItmPtdByDsp_20xfd07
*/
class Enveloppe
{
public:
  Enveloppe() {
  }

  Enveloppe(CATOmyMetaDataCacheLifeCycleManager& iMetaDataCache) {
    _hMetaDataCache = &iMetaDataCache;
  }

  ~Enveloppe() {
    _hMetaDataCache = NULL;
  }

  void SetMetaDataCache(CATOmyMetaDataCacheLifeCycleManager* ipMetadataCache) {
    _hMetaDataCache = ipMetadataCache;
  }

  // NO AddRef()
  CATOmyMetaDataCacheLifeCycleManager* GetMetaDataCache(){
    return _hMetaDataCache.Ref();
  }

private:
  // Copy constructor and equal operator
  // -----------------------------------
  Enveloppe(Enveloppe &);
  Enveloppe& operator=(Enveloppe&);

  CATOmxSR<CATOmyMetaDataCacheLifeCycleManager> _hMetaDataCache;
};

class ExportedByCATOMYCuteIO CATOmyMetaDataCacheServices
{
public:

  /**
  * Let's PowerIO manage the MetaData PereDodu Cache
  */
	static HRESULT SetMetaDataCacheLifecyleManager(CATOmyMetaDataCacheLifeCycleManager& iMetaDataCache);

 /**
  * Get the number of elements in the metadata cache.
  * @param oNbrElements [out]
  *   The Number of elements.
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise E_FAIL;
  */
  static HRESULT GetCurrentCacheMetaDataElements(CATULONG32 &oNbrElements);

private :
  static Enveloppe _enveloppe;
  static HRESULT CleanPartial();  
  static HRESULT CleanAll();

  friend class CATOmyPowerIOCachingBusinessLogic;
};

#endif
