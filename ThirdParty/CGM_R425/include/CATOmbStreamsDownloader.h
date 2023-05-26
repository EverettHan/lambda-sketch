#ifndef __CATOmbStreamsDownloader_H
#define __CATOmbStreamsDownloader_H

#include "CATLISTV_CATComponentId.h"
#include "CATBaseUnknown.h"
#include "CATPLMID.h"
#include "CATOmxArray.h"
#include "CATPLMStreamDefinition.h"
#include "CATListPtrCATPLMStreamDescriptor.h"
#include  "CATVVSURLConnection.h"
#include "CATOmxSR.h"

#include "CATOmyVVSURLConnectionHolder.h"


#undef ExportedByCATOmbStreamDownloader

#if defined __CATPLMStreamDescriptor
#define ExportedByCATOmbStreamDownloader DSYExport
#else
#define ExportedByCATOmbStreamDownloader DSYImport
#endif
#include "DSYExport.h"

class CATPLMIDHashTable;
class CATIPLMQueryFilter;


/**
* This class represent the status of one SD at a given time. 
* UrlConnection within this object locks the stream in cache. 
* When this object is released and if UrlConnection has not been retrieved streams may be deleted at any time from the cache
*/
class ExportedByCATOmbStreamDownloader CATOmbSDStatus
{
friend class CATPLMUrlDownloaderHelper;
friend class CATOmbComponentSDs;

public:
  enum SDSynchronousStateWithDB
  {
    syncstatus_undefined = 0,
    syncstatus_synchronized = 1,
    syncstatus_unsynchronized = 2,
    syncstatus_notinserver = 3,
    syncstatus_notinsession = 4
  };

  enum SDStreamInCache
  {
    cache_undefined = 0,
    cache_inCache = 1,
    cache_notInCache = 2
  };

  
  CATOmbSDStatus(CATPLMStreamDefinition& iSD);
  ~CATOmbSDStatus();
  CATOmbSDStatus(const CATOmbSDStatus& iStatus); // pour CATOmxArray
  CATOmbSDStatus(); // pour CATOmxArray...
  /**
  * To retrieve access to the stream in cache. (return NULL if stream is not in cache)
  */
  CATVVSURLConnection* GetUrlConnection();  

  CATPLMStreamDefinition _SD;
  SDSynchronousStateWithDB _SyncStatus;
  SDStreamInCache _CacheStatus;  
  
private:
  CATOmbSDStatus(CATPLMStreamDefinition& iSD, SDSynchronousStateWithDB iSyncStatus, SDStreamInCache iCacheStatus);  
  
  CATOmxSR< CATOmyVVSURLConnectionHolder > _spHolder;
    

};

template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmbSDStatus>::manager();

class ExportedByCATOmbStreamDownloader CATOmbComponentSDs
{
friend class CATPLMUrlDownloaderHelper;
public:
  CATOmbComponentSDs(CATPLMID& iPlMID);
  CATOmbComponentSDs(const CATOmbComponentSDs& iSDs);  
  ~CATOmbComponentSDs();
  /**
  * To be used to construct the CATPLMIDHashTable when calling the services 
  */
  HRESULT Append(CATOmbSDStatus& iSDState);
  /**
  * Iterates through the SDs of a component
  * First call shall be made with ioRestart == TRUE to rewind iterator
  * @return S_OK : next SD is provided
  *         E_FAIL : no more SD to iterate
  */
  HRESULT Next(CATOmbSDStatus& oSDState, CATBoolean& ioRestart);
  CATPLMID _PLMID;  // PLMID of the component
 
private:
  CATOmbComponentSDs();
  HRESULT UpdateSDState(CATListPtrCATPLMStreamDescriptor& iListOfSDServer);
  CATOmxArray < CATOmbSDStatus > _SDStates;
  int _pos;
};

/**
* CallBack to be implemented when using the services UpdateSDStatusAndLockInCacheWhenPossibleAsync and LockSynchronousStreamsInCacheAsync
* OnTaskCompleted will be called by the async platform on completion of all tasks scheduled by the previous services. 
* HRESULT is only for debug. It will be lost by the platform. Error management shall be treated using @CATIOmyIncidentCollector. Remember that caller of OnTaskCompleted is not the caller of UpdateSDStatusAndLockInCacheWhenPossibleAsync.
*/
class ExportedByCATOmbStreamDownloader CATOmbStreamDownloaderCBAdaptor : public CATBaseUnknown
{
public:
  virtual HRESULT OnTaskCompleted(CATPLMIDHashTable& oHtablePLMID_SDs) {return E_NOTIMPL;}
};


class ExportedByCATOmbStreamDownloader CATOmbStreamsDownloader
{  
public:
  
  /**
  * For the provided components loaded in session, this service will check for each of the SDs aggregated under each component
  * - if streams are available in cache
  * - if SDs are synchronous with the server (if iDoNotQuery is not set)
  * - download synchronous streams  (no donwload is iDotNotQuery is set since the synchronous status is undefined)
  * - lock streams in cache (Persistent Lock or Session Lock)
  * The output is a snapshot provided at a given time. Its result may become inaccurate right after. In ConcurrentEngineering, one may have update a SD at any time
  * @param [in]   iComponentsToTreat : List of Components loaded in session
  * @param [in]   iPersistentLock : if TRUE Streams will be locked in cache by LocalSave, if FALSE streams can be released as soon as URLConnection retrieved is destroyed. (basic cache behaviour)
  * @param [in]   iDoNotQuery : do not perform query on database : only set cache status for each SDs and lock available streams in cache
  * @param [in]   iCB : Callback that will be called when all tasks performed by the service has been performed. Note iCB can be called after the return of this service (asynchronous mode) or before the return of this service (synchronous mode)
  * 
  * @return : S_OK : all tasks have been scheduled (not executed with success : iCB::OnTaskCompleted will be called)
  *         : E_*  : at least a task could nor be scheduled... However, iCB::OnTaskCompleted will be called
  * NOTE : RETURN code is provided only for info. You do not have to worry too much about it. Instead iterate on the CATPLMIDHashTable structure in the CallBack. If some parts of the service has failed, the cache status / sync status will be set to undefined
  * This is a batch service, so service may fail since the treatement has failed for one component. But it might have succeeded for all the other ones. 
  * This an asynchronous service. This method will return before any treatments. 
  *
  */
  static HRESULT UpdateSDStatusAndLockInCacheWhenPossibleAsync(CATComponentIds& ComponentsToTreat, CATBoolean iPersistentLock, CATBoolean iDoNotQuery, CATOmbStreamDownloaderCBAdaptor& iCB);
  
  /**
  * For the provided hashtable of SDViews, this service will check for each SD
  * - if streams are available in cache
  * - if SDs are synchronous with the server (if iDoNotQuery is not set)
  * - download synchronous streams  (no donwload is iDotNotQuery is set since the synchronous status is undefined)
  * - lock streams in cache (Persistent Lock or Session Lock)
  * The output is a snapshot provided at a given time. Its result may become inaccurate right after. In ConcurrentEngineering, one may have update a SD at any time
  * @param [in]   iComponentsToTreat : List of Components loaded in session
  * @param [in]   iPersistentLock : if TRUE Streams will be locked in cache by LocalSave, if FALSE streams can be released as soon as URLConnection retrieved is destroyed. (basic cache behaviour)
  * @param [in]   iDoNotQuery : do not perform query on database : only set cache status for each SDs and lock available streams in cache
  * @param [in]   iCB : Callback that will be called when all tasks performed by the service has been performed. Note iCB can be called after the return of this service (asynchronous mode) or before the return of this service (synchronous mode)
  * 
  * @return : S_OK : all tasks have been scheduled (not executed with success : iCB::OnTaskCompleted will be called)
  *         : E_*  : at least a task could nor be scheduled... However, iCB::OnTaskCompleted will be called
  * NOTE : RETURN code is provided only for info. You do not have to worry too much about it. Instead iterate on the CATPLMIDHashTable structure in the CallBack. If some parts of the service has failed, the cache status / sync status will be set to undefined
  * This is a batch service, so service may fail since the treatement has failed for one component. But it might have succeeded for all the other ones. 
  * This an asynchronous service. This method will return before any treatments. 
  *
  */
  static HRESULT LockSynchronousStreamsInCacheAsync(CATPLMIDHashTable& ioHtablePLMID_SDs,CATBoolean iPersistentLock, CATBoolean iDoNotQuery,CATOmbStreamDownloaderCBAdaptor& iCB);
  
  /**
  * For the provided components loaded in session, this service will check for each of the SDs aggregated under each component
  * - if streams are available in cache
  * - if SDs are synchronous with the server (if iDoNotQuery is not set)
  * - download synchronous streams  (no donwload if iDotNotQuery is set since the synchronous status is undefined)
  * - lock streams in cache (Persistent Lock or Session Lock)
  * The output is a snapshot provided at a given time. Its result may become inaccurate right after. In ConcurrentEngineering, one may have update a SD at any time
  * @param [in]   iComponentsToTreat : List of Components loaded in session
  * @param [in]   iPersistentLock : if TRUE Streams will be locked in cache by LocalSave, if FALSE streams can be released as soon as URLConnection retrieved is destroyed. (basic cache behaviour)
  * @param [in]   iDoNotQuery : do not perform query on database : only set cache status for each SDs and lock available streams in cache
  * @param [out]  oHtablePLMID_SDs : HashTable indexed on PLMIDs. For each components with SDs, one can retrieve a CATOmbComponentSDs objects. One can iterate on the structure using  HRESULT Visit(CATPLMIDHashTableVisitor & iVisitor)
  * 
  * @return : S_OK : all tasks have been executed with success
  *         : E_*  : at least a task has not completed with success
  * NOTE : RETURN code is provided only for info. You do not have to worry too much about it. Instead iterate on the CATPLMIDHashTable structure. If some parts of the service has failed, the cache status / sync status will be set to undefined
  * This is a batch service, so service may fail since the treatement has failed for one component. But it might have succeeded for all the other ones. 
  *
  */
  static HRESULT UpdateSDStatusAndLockInCacheWhenPossible(CATComponentIds& iComponentsToTreat, CATBoolean iPersistentLock, CATBoolean iDoNotQuery, CATPLMIDHashTable*& oHtablePLMID_SDs);
  
  /**
  * For the provided hashtable of SDViews, this service will check for each SD
  * - if streams are available in cache
  * - if SDs are synchronous with the server (if iDoNotQuery is not set)
  * - download synchronous streams  (no donwload is iDotNotQuery is set since the synchronous status is undefined)
  * - lock streams in cache (Persistent Lock or Session Lock)
  * The output is a snapshot provided at a given time. Its result may become inaccurate right after. In ConcurrentEngineering, one may have update a SD at any time
  * @param [in]   iComponentsToTreat : List of Components loaded in session
  * @param [in]   iPersistentLock : if TRUE Streams will be locked in cache by LocalSave, if FALSE streams can be released as soon as URLConnection retrieved is destroyed. (basic cache behaviour)
  * @param [in]   iDoNotQuery : do not perform query on database : only set cache status for each SDs and lock available streams in cache
  * @param [in/out]  ioHtablePLMID_SDs : HashTable indexed on PLMIDs. For each components with SDs, one can retrieve a CATOmbComponentSDs objects. One can iterate on the structure using  HRESULT Visit(CATPLMIDHashTableVisitor & iVisitor)
  * 
  * @return : S_OK : all tasks have been executed with success
  *         : E_*  : at least a task has not completed with success
  * NOTE : RETURN code is provided only for info. You do not have to worry too much about it. Instead iterate on the CATPLMIDHashTable structure. If some parts of the service has failed, the cache status / sync status will be set to undefined
  * This is a batch service, so service may fail since the treatement has failed for one component. But it might have succeeded for all the other ones. 
  *
  */
  static HRESULT LockSynchronousStreamsInCache(CATPLMIDHashTable& ioHtablePLMID_SDs,CATBoolean iPersistentLock,CATBoolean iDoNotQuery);

  static HRESULT CleanAll(CATPLMIDHashTable& ioHtablePLMID_SDs);
private:  
  static HRESULT RetrieveSDs(CATComponentIds& ComponentsToTreat,CATPLMIDHashTable& ioHtablePLMID_SDs);
  static HRESULT CreateQueryFilter(CATPLMIDHashTable& ioHtablePLMID_SDs, CATIPLMQueryFilter*& opFilter);
  static HRESULT AddCoreTypeToQuery(CATIPLMQueryFilter* ipFilter, const CATUnicodeString& Type);
  static HRESULT AddCoreTypeToQueryDeprecated(CATIPLMQueryFilter* ipFilter,const  CATUnicodeString& Type);
};

#endif
