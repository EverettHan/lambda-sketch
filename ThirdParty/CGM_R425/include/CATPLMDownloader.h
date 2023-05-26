#ifndef _CATPLMDownloader_H
#define _CATPLMDownloader_H

/**
* @level Protected
* @usage U1
*/

// ---------------------------------------------------------------------------------------------
#define AuthorizedModule                             999
#define CATPLMSynchronization                        AuthorizedModule
#define CATPLMIntegration                            AuthorizedModule
#define CATPLMComponentChecker                       AuthorizedModule
#define CATPLMSynchronizationEngine                  AuthorizedModule
#define CATOxiSessionManager                         AuthorizedModule
#define CATOxiMinorMajor                             AuthorizedModule
#define CATOxiGenSession                             AuthorizedModule
#define CATOxiGenSessionDefineFilter                 AuthorizedModule
#define CATOxiGenSessionDefineFilterBase             AuthorizedModule
#define CATOxiGenSessionWithRepDefineFilter          AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden Access To CATPLMDownloader
// Fatal error on solaris
@error
#endif

#undef AuthorizedModule
#undef CATPLMSynchronization
#undef CATPLMIntegration
#undef CATPLMComponentChecker
#undef CATPLMSynchronizationEngine
#undef CATOxiSessionManager
#undef CATOxiMinorMajor
#undef CATOxiGenSession
#undef CATOxiGenSessionDefineFilter
#undef CATOxiGenSessionDefineFilterBase
#undef CATOxiGenSessionWithRepDefineFilter
// ---------------------------------------------------------------------------------------------

#include "CATPLMIntegration.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATPLMID.h"
#include "CATLISTV_CATComponentId.h"
#include "CATOmyVVSAsyncCallBackNotifier.h"

#include "CATIAV5Level.h"
#include "CATAsyncTaskCompletionCallBack_NG.h"
#include "CATAsyncTaskID.h"

#include "CATProxySpace.h"
#include "CATIPLMCompStatementService.h"
#include "CATOmxOrderedOHMap.h"
#include "CATPLMDownloaderEntry.h"
#include "CATOmxSR.h"

class CATIPLMRecordRead;
class CATIPLMQueryFilter;
class CATIPLMCompRecordReadSet;
class CATPLMEngineErrorReporter;
class CATIPLMCompStatement;
class CATPLMIDHashTable;
class CATPLMDownloaderVisitor;
class CATIPLMSynchronizationSolution;
class CATPLMSyncrhonizationAsyncQueryCallBack;
class CATPLMSyncrhonizationVVSQueryCallBack;
class CATPLMDownloader;
class CATPLMSessionOperationSet;
class CATPLMRepositoryName;
class CATPLMOpenQueryPreparator;
class CATPLMFastenerConnectionFilter;
class PLMOpenMessageChecker;
class CATPLMDecodingBuffer;
class CATIPLMIntegRecordRead;

class CATPLMAsyncData
{
public:
  CATPLMAsyncData();
  ~CATPLMAsyncData();
  HRESULT AddAsync(CATAsyncTaskID iAsyncTask, CATIPLMCompStatement* iCompStatement, CATIPLMQueryFilter* iQueryFilter);
  HRESULT ReleaseAsync(CATAsyncTaskID iAsyncTask);
  CATBoolean IsEmpty();
private:
  CATAsyncTaskID              _AsyncTask[2];
  CATIPLMCompStatement* _CompStatement[2];
  CATIPLMQueryFilter* _QueryFilter[2];
};

class CATPLMDownloader : public CATAsyncTaskCompletionCallBackBase
{
  CATDeclareClass;

public:
  ExportedByCATPLMIntegration CATPLMDownloader(CATPLMRepositoryName* iRepoName = NULL);
  ExportedByCATPLMIntegration ~CATPLMDownloader();
  /**
  * Download core datum (attributes)
  * In every case (async or not), the downloader is filled with the records, so to get the results
  * you should use the visitor and NOT the asyncContext in async case
  * Camm this method if you want to keep the completion level
  */
  ExportedByCATPLMIntegration HRESULT DownloadMetadata(const CATComponentIds& iOperationSet, CATPLMEngineErrorReporter* iErrorReporter, CATAsyncTaskID& oAsyncTaskID);

  /**
  * Download core datum (attributes)
  * In every case (async or not), the downloader is filled with the records, so you should use the visitor
  * and NOT the asyncContext in async case
  * You must specify the wanted completion level, use ComponentIds version to keep the same completion level
  */
  ExportedByCATPLMIntegration HRESULT DownloadMetadata(const CATLISTV(CATPLMID)& iComponentsToTreat, CATPLMEngineErrorReporter* iErrorReporter, CATAsyncTaskID& oAsyncTaskID);

  HRESULT DownloadStreams(CATPLMEngineErrorReporter* iErrorReporter, CATAsyncTaskID& oAsyncTaskID);

  ExportedByCATPLMIntegration CATPLMDownloaderEntry* Find(const CATPLMID& iPLMID);

  ExportedByCATPLMIntegration CATPLMDownloaderEntry* Find(const CATComponentId& iCID);

  HRESULT Visit(CATPLMDownloaderVisitor& iVisitor);

  CATOmxList<CATIPLMRecordRead>::IteratorType GetOldOpenIterator();

  void OnTaskCompleted(CATAsyncTaskContextBase& iAsyncTaskContext);

  HRESULT SetQueryCallerCB(CATAsyncTaskCompletionCallBackBase& iCallerCB);
  HRESULT SetVVSCallerCB(CATAsyncTaskCompletionCallBackBase& iCallerCB);

  HRESULT SetSnapShotMode();
  HRESULT SetFastenerMode(const CATProxySpace& iProxySpace); //Filters the fasteners, needed for secondary fastener ("MCXX") open
  HRESULT SetOpenChecker();

  void SetSpace(const CATProxySpace& iSpace);

  enum DownloadMode { Standard = 0, PereDodu = 1, Offline = 3 };
  HRESULT SetDownloadMode(DownloadMode iMode);

  void KeepLegacyOrdering()
  {
    _KeepLegacyOrdering = true;
  }

private:

  void SetErrorReporter(CATPLMEngineErrorReporter* iErrorReporter);

  HRESULT CheckRecord(CATIPLMRecordRead* iRecordRead);

  HRESULT CreateInputMessage(CATIPLMCompStatement*& oStatement, CATIPLMQueryFilter*& oQueryFilter);

  HRESULT FillMessage(const CATLISTV(CATPLMID)& iComponentsToTreat, CATIPLMQueryFilter* ioMessage);

  HRESULT CollectInformationAsync(const CATLISTV(CATPLMID)& iComponentsToTreat, CATAsyncTaskID& oAsyncTaskID);
  HRESULT CollectInformation(const CATLISTV(CATPLMID)& iComponentsToTreat, CATIPLMCompRecordReadSet*& oRecordReadSet);

  /**
  * <br><b>Role</b>:
  * @param iComponentsToTreat
  *
  * @param oRecordReadSet [out, CATBaseUnknown#Release]
  *
  * @param iErrorReporter
  *
  * @param iMode
  *
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  HRESULT CollectInformationFromRepository(const CATLISTV(CATPLMID)& iComponentsToTreat, CATIPLMCompRecordReadSet*& oRecordReadSet);
  HRESULT CollectInformationFromPereDodu(const CATLISTV(CATPLMID)& iComponentsToTreat, CATPLMOpenQueryPreparator* iPereDoduPreparator, CATIPLMCompRecordReadSet*& oRecordReadSet, const CATIPLMCompStatementService::ApplicationIdentifier& iAppId);


  HRESULT CheckCollectedInformationAndInsertRecords(CATIPLMCompRecordReadSet& iRecordReadSet);
  HRESULT CheckRecordReadSet(CATIPLMCompRecordReadSet& iRecordReadSet, PLMOpenMessageChecker& iPLMMessageChecker);
  HRESULT CheckAndInsertRecords(CATIPLMCompRecordReadSet& iRecordReadSet, PLMOpenMessageChecker& iPLMMessageChecker);

  //CATPLMIDHashTable * _HashTable;
  HRESULT CreateDownloaderEntry(CATIPLMRecordRead* iRR);
  HRESULT PopRecords(CATPLMDecodingBuffer& iOpenOrderLegacy, CATOmxList<CATIPLMIntegRecordRead>& ioIntegRecordsBulk);
  HRESULT AddBulkOrSingle(CATOmxSR<CATIPLMRecordRead>& iRecord, CATOmxList<CATIPLMIntegRecordRead>& ioIntegRecordsBulk);
  HRESULT ProcessIntegRecords(const CATOmxList<CATIPLMIntegRecordRead>& iIntegRecords);
  CATOmxOrderedOHMap<CATPLMID, CATPLMDownloaderEntry> _OrderedPLMIDToEntry;
  CATOmxList<CATIPLMRecordRead> _OldOpenOrder;


  CATOmxSR<CATAsyncTaskCompletionCallBackBase> _pQueryCallerCB;
  CATOmxSR<CATAsyncTaskCompletionCallBackBase> _pVVSCallerCB;
  CATOmxSR<CATPLMEngineErrorReporter> _pErrorReporter;
  CATPLMRepositoryName* _pRepoName; //No ref counter, don't delete
  CATBoolean _bSnapShotMode;
  CATPLMAsyncData  _AsyncData;
  CATProxySpace _CurrentSpace;  // To get CEStamp info if any  
  DownloadMode _DownloadMode;
  CATOmxSR<CATPLMFastenerConnectionFilter> _fastenerCnxFilter;
  bool _KeepLegacyOrdering;
};


#endif

