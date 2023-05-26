#ifndef CATIPLMSTATUTREMOTEENGINE_H
#define CATIPLMSTATUTREMOTEENGINE_H

/**
 * @level Private
 * @usage U1
 */

#include "CATPLMImplAdapterItf.h"
#include "CATBaseUnknown.h"
#include "CATUuid.h"
#include "CATAsyncTaskID_NG.h"
#include "CATOmxSR.h"
#include "CATOmxSharable.h"
#include "CATOmxList.h"

class CATIPLMQueryFilter;

class CATIPLMCompRecordReadSet;
class CATIPLMRecordReadSet;
class CATIPLMRecordRead;
class CATIAsyncTaskCompletionCallBackBase;
class CATPLMRecordReadSetAdapterImpl;

class ExportedByCATPLMImplAdapterItf CATIPLMStatutRemoteEngine : public CATOmxSharable
{
public:
     virtual HRESULT SetQueryFilter(CATIPLMQueryFilter * iQueryFilter) = 0;

     /**
      * Launch synchronous execution of the engine.
      * The engine computes all synchro statuses of the semantic relations contained in the records.
      *
      * @param iopiRecordReadSet
      *    Input and output record read set.
      *       The records that contain SRs which need to be computed have to implement CATIPLMRecordReadModifySRAndSDAndExt interface.
      *       A brand new record read set will be given in output, with synchro statuses computed.
      *
      * @return  
      *    S_OK: everything went fine.
      *    E_* : some problem occurred.
      *         
      */	
     virtual HRESULT Run(CATIPLMCompRecordReadSet *&iopiRecordReadSet) = 0;

     /**
      * Launch synchronous execution of the engine.
      * The engine computes all synchro statuses of the semantic relations contained in the records.
      *
      * @param iRecords
      *    Input list of record read.
      *       The records that contain SRs which need to be computed have to implement CATIPLMRecordReadModifySRAndSDAndExt interface.
      *       The records contained in the list will be modified, but the list itself will not.
      *
      * @return  
      *    S_OK: everything went fine.
      *    E_* : some problem occurred.
      *         
      */	
     virtual HRESULT Run(const CATOmxList<CATIPLMRecordRead>& iRecords) = 0;


     /**
      * Alternate way to do the same
      * Run1 signature is becoming obsolete in R420 and may be removed
      *
      * @param iQueryFilter
      *    To detect which SR should be calculated synchro status, and which should not
      *
      * @param iRecordReadSetWithoutSync
      *    Input record read set without sync info
      * 
      * @param oRecordReadSetWitSync
      *    output record read set with calculated sync info
      *
      * @return  
      *    S_OK: everything went fine.
      *    E_* : some problem occurred.
      *         
      */	
     virtual HRESULT Run1(CATIPLMQueryFilter * iQueryFilter, CATIPLMRecordReadSet *iRecordReadSetWithoutSync, CATIPLMCompRecordReadSet *&oRecordReadSetWitSync) = 0;
     virtual HRESULT Run2(CATIPLMQueryFilter * iQueryFilter, CATIPLMRecordReadSet *iRecordReadSetWithoutSync, CATPLMRecordReadSetAdapterImpl *&oRecordReadSetWitSync) = 0;

     /**
      * Launch asynchronous execution of the engine.
      * The engine computes all synchro statuses of the semantic relations contained in the records.
      *
      * @param ipiRRS
      *    Input record read set, whose semantic relations are to be computed by the engine. 
      *
      *         The records that contain SRs which need to be computed have to implement CATIPLMRecordReadModifySRAndSDAndExt interface.
      *
      *         ############ 
      *         #   WARNING  # Shall not be used by caller anymore. The callee has released it !
      *         ############
      *
      * @param oAsyncTaskId
      *    Async logical task id created by engine.
      *         If CATAsyncTaskID_Null is returned, no task has been created. 
      *         Execution has been done synchronously, and callback has already been called.
      * @param iAsyncTaskCompletionCallBack
      *    Callback provided by caller, that will be called on TaskCompleted when job is done.
      *         The resulting record read set will be provided in the async context (TaskCompleted).
      *         
      * @return  
      *    S_OK: everything went fine.
      *    E_* : some problem occurred.
      */	
     virtual HRESULT RunAsync( CATIPLMCompRecordReadSet *ipiRRS,
                               CATAsyncTaskID &oAsyncTaskId,
                               CATIAsyncTaskCompletionCallBackBase &iAsyncTaskCompletionCallBack) = 0;

      /**
      * Launch asynchronous execution of the engine.
      * The engine computes all synchro statuses of the semantic relations contained in the records.
      *
      * @param iRecords
      *    Input list of records, whose semantic relations are to be computed by the engine. 
      *
      *         The records that contain SRs which need to be computed have to implement CATIPLMRecordReadModifySRAndSDAndExt interface.
      *         The records contained in the list will be modified, but the list itself will not.
      *
      * @param oAsyncTaskId
      *    Async logical task id created by engine.
      *         If CATAsyncTaskID_Null is returned, no task has been created. 
      *         Execution has been done synchronously, and callback has already been called.
      * @param iAsyncTaskCompletionCallBack
      *    Callback provided by caller, that will be called on TaskCompleted when job is done.
      *         The resulting record read set will be provided in the async context (TaskCompleted).
      *         
      * @return  
      *    S_OK: everything went fine.
      *    E_* : some problem occurred.
      */	
     virtual HRESULT RunAsync( const CATOmxList<CATIPLMRecordRead>& iRecords,
                            CATAsyncTaskID &oAsyncTaskID,
                            CATIAsyncTaskCompletionCallBackBase &iAsyncTaskCompletionCallBack) = 0;
};

#endif
