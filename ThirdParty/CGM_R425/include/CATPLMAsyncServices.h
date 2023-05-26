/**
* @level Protected
* @usage U3
*/

#ifndef CATPLMAsyncServices_H
#define CATPLMAsyncServices_H

#include "CATBoolean.h"
#include "CATPLMAsync.h"
#include "CATAsyncTaskID_NG.h"
#include "CATListOfCATOmyCioUrlUsageCtx.h"


class CATIPLMAsyncProviderInterfaces;
class CATIOmyAsyncTaskCompletionCallBack;
class CATIPLMQueryFilter;
class CATIPLMRecordRead;
class CATIPLMExpandResultHandler;
class CATIPLMCompRecordReadSet;
class CATOmyVVSAsyncCallBackNotifier;
class CATIOmyAsyncResult;
class CATOmxKeyValueBlock;
class CATIAsyncTaskCompletionCallBackBase; //Defined in ObjectModelerSystem
class CATIPLMCompConnectionInstance;

/**
* This service provides the ability to perform PLMQL Query and PowerIO Transaction as a task.
* <Role/> Task can be executed asynchronously (meaning task is performed on a different process than the caller.) or synchronously
* In both cases, when the task is completed, caller in the original process is awaken and called on the provided callback.
* This class is intended to be created on the stack as follow :
* <code>
*      CATPLMAsyncServices service;
*      rc = service.ExecuteTask(*_pQueryFilter,oRecordReadSet,*pTransactionCallBack,pAsyncResult);
*</code>
*
*/
class ExportedByCATPLMAsync CATPLMAsyncServices
{
friend class CATAsyncMTPLMQueryTasksFactory;
friend class MTPLMQueryCB;
friend class CATPLMAsyncProviderServicesQL;
friend class CATPLMxQueryAdapter;
friend class CATExaleadCommand;
friend class TSTCATPLMxQueryCondOnExtCondOnExt3;                  
friend class CATPLMDebugQueryBase; 
friend class CATPLMQueryFilter;
public:


	CATPLMAsyncServices();
	~CATPLMAsyncServices();

  /**
  * DEPRECATED R419 : Migrate on CATAsyncPLMTasksFactory::CreateAsyncPLMQueryTask
  */
	HRESULT ExecuteTask(CATIPLMQueryFilter& iQueryFilter, CATIPLMCompRecordReadSet *& oRecordReadSet,CATIOmyAsyncTaskCompletionCallBack& iAsyncTaskCompletionCallBack ,CATIOmyAsyncResult *& oAsyncResult);

	/**
  * DEPRECATED R419 : Migrate on CATAsyncPLMTasksFactory::CreateAsyncPLMQueryTask
  */
  HRESULT ExecuteTask(CATIPLMQueryFilter& iQueryFilter,CATIPLMExpandResultHandler& iExpandHandler,CATIOmyAsyncTaskCompletionCallBack& iAsyncTaskCompletionCallBack ,CATIOmyAsyncResult *& oAsyncResult);

	/**
  * DEPRECATED R419 : Migrate on CATAsyncVVSTasksFactory::CreateAsyncVVSTask
  */
	HRESULT ExecuteTask(const CATListOfCATOmyCioUrlUsageCtx& iSelection, CATOmyVVSAsyncCallBackNotifier& iAsyncTaskCompletionCallBack, CATIOmyAsyncResult *& oAsyncResult);
 
	/**
	* When env variable OMY_TEST_PLMQL_XML is set to a directory,
	* This service will dump into a xml file the content of a QueryFiler.
	* Then a new filter is created from the dump of the first filter.
	* Callers can then replace the orginal filter with the one generated from the xml file
	* It allows checking in synchronous mode if the query sent to the external process is correct
	*
	* If variable is not set, oFilter is the same filter os iFilter
	*
	* To replace in your code the old filter by the new one, please use the following API
	*     CATPLMAsyncServices debugservices;
  *     CATIPLMQueryFilter* pFilter = NULL;
  *     debugservices.DumpFilterAndReloadItFromDump(pQueryFilter,pFilter);
  *     pQueryFilter->CloneQuery(pFilter);
  *     CATSysReleasePtr(pFilter);
	*
	* @param [in] iFilter : the filter to be dumped
	* @param [out] oFilter : the filter that is generated from the dump
	* @return
	*    <code>S_OK</code> : oFilter is created and shall be released
	*    <code>E_*</code> : Note oFiler might be created. So release it :)
	*/
	HRESULT DumpFilterAndReloadItFromDump(CATIPLMQueryFilter * iFilter,CATIPLMQueryFilter *& oFilter);

  /**
	* When env variable OMY_TEST_RECORD_BIN is set to a directory,
	* This service will dump into a binary file the content of a RecordRead.
	* Then a new RecordRead is created from the dump of the first RecordRead.
	* Callers can then replace the orginal RecordRead with the one generated from the binary file
	* It allows checking in synchronous mode if the RecordRead sent from the external process is correct
	*
	* If variable is not set, opiRecord is the same filter as ipiRecord
	*
	*
	* @param [in] ipiRecord : the record to be dumped
	* @param [out] opiRecord : the record that is generated from the dump
	* @return
	*    <code>S_OK</code> : opiRecord is created and shall be released
  *    <code>S_FALSE</code> : OMY_TEST_RECORD_BIN not set
	*    <code>E_*</code> : Note opiRecord might be created. So release it :)
	*/
  HRESULT DumpRecordAndReloadItFromDump(CATIPLMRecordRead * ipiRecord, CATIPLMRecordRead *& opiRecord);  

/**
 * Disconnects the async processes associated to the given connection.
 */
  HRESULT DisconnectAuxilliaryProcess( CATIPLMCompConnectionInstance * ipiCompCnx ); 

  CATBoolean IsXMQLHandled(CATIPLMQueryFilter * iFilter, CATIPLMExpandResultHandler * iExpandHandler = NULL, CATBoolean iCheckContext = TRUE);

  private:
  
  // JRZ only 1 signature with iExpandHandler NULL or not
  HRESULT ExecuteAsyncXMqlQuery2(CATAsyncTaskID& oID,CATIPLMQueryFilter * iFilter,  CATIPLMExpandResultHandler * iExpandHandler,   CATIAsyncTaskCompletionCallBackBase& iAsyncTaskCompletionCallBack, CATBoolean iWithSRRemoteStatus);

  CATIPLMAsyncProviderInterfaces* ConnectToAdapterImplx();

};

class AdapterQLBridge{
public:
  virtual CATBoolean IsXMQLHandled(CATIPLMQueryFilter * iFilter, CATIPLMExpandResultHandler * iExpandHandler = NULL) = 0;
  static AdapterQLBridge* Get();
}; 


#endif
