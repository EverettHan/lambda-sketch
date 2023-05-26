//===================================================================
// COPYRIGHT Dassault Systemes 2015/07/02
//===================================================================
// CATAsyncPLMTasksFactory.cpp
// Header definition of class CATAsyncPLMTasksFactory
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2015/07/02 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATAsyncPLMTasksFactory_H
#define CATAsyncPLMTasksFactory_H

#include "CATPLMAsync.h"
#include "CATAsyncTasksFactory_NG.h"

#include "CATIPLMQueryFilter.h"
#include "CATIPLMExpandResultHandler.h"
#include "CATIPLMCompStatementService.h"

class IPLMDumpAndTransmitExpandHandlerFactory;

//-----------------------------------------------------------------------

class ExportedByCATPLMAsync CATAsyncPLMTasksFactory: public CATAsyncTasksFactory
{
public:
  // Standard constructors and destructors
  // -------------------------------------
  CATAsyncPLMTasksFactory ();
  virtual ~CATAsyncPLMTasksFactory ();

  /**
  * Creates an Asynchronous QueryFilter Task.
  * This task has a physical task behavior @see usage note.
  *
  * If the MP Platform is used, this PLMQL physical task executes the service :
  *   <code>ExecuteTask(CATIPLMQueryFilter& iQueryFilter, CATIPLMCompRecordReadSet *& oRecordReadSet,...)</code>
  *
  *
  * @param
  * <br/> [out] oAsyncTaskId : id of the task
  * <br/> [in] iQueryFilter : the query to perform
  * <br/> [in] iAsyncTaskCompletionCallBack : callback that is called when task is completed
  * <br/> [in][opt] iAsyncTaskParentId : Logical Task on which the new created Physical Task will be attached
  * @return
  * <code>S_OK</code>: the task has been scheduled with success
  * <code>E*</code>: unexpected error: task has not been scheduled
  *
  */
  HRESULT CreateAsyncPLMQueryTask( CATAsyncTaskID & oAsyncTaskId,
                                   CATIPLMQueryFilter& iQueryFilter,
                                   CATIAsyncTaskCompletionCallBackBase& iAsyncTaskCompletionCallBack,
                                   const CATAsyncTaskID & iAsyncTaskParentId = CATAsyncTaskID_Null );

  /**
  * TO BE USED ONLY BY REMOTE STATUS ENGINE
  * Creates an Asynchronous QueryFilter Task.
  * This task has a physical task behavior @see usage note.
  *
  * If the MP Platform is used, this PLMQL physical task executes the service :
  *   <code>ExecuteTask(CATIPLMQueryFilter& iQueryFilter, CATIPLMCompRecordReadSet *& oRecordReadSet,...)</code>
  *
  *
  * @param
  * <br/> [out] oAsyncTaskId : id of the task
  * <br/> [in] iQueryFilter : the query to perform
  * <br/> [in] iAsyncTaskCompletionCallBack : callback that is called when task is completed
  * <br/> [in][opt] iAsyncTaskParentId : Logical Task on which the new created Physical Task will be attached
  * @return
  * <code>S_OK</code>: the task has been scheduled with success
  * <code>E*</code>: unexpected error: task has not been scheduled
  *
  */
  HRESULT CreateAsyncPLMQueryTaskWithNoSRStatus( CATAsyncTaskID& oAsyncTaskId,
                                                 CATIPLMQueryFilter& iQueryFilter,
                                                 CATBoolean iForceNoMultiProcessExecution,
                                                 CATIAsyncTaskCompletionCallBackBase& iAsyncTaskCompletionCallBack,
                                                 const CATAsyncTaskID & iAsyncTaskParentId = CATAsyncTaskID_Null );

  /**
  * TO BE USED ONLY BY REMOTE STATUS ENGINE
  * Creates an Asynchronous QueryFilter Task.
  * This task has a physical task behavior @see usage note.
  *
  * If the MP Platform is used, this PLMQL physical task executes the service :
  *   <code>ExecuteTask(CATIPLMQueryFilter& iQueryFilter, CATIPLMCompRecordReadSet *& oRecordReadSet,...)</code>
  *
  *
  * @param
  * <br/> [out] oAsyncTaskId : id of the task
  * <br/> [in] iQueryFilter : the query to perform
  * <br/> [in] iAsyncTaskCompletionCallBack : callback that is called when task is completed
  * <br/> [in][opt] iAsyncTaskParentId : Logical Task on which the new created Physical Task will be attached
  * @return
  * <code>S_OK</code>: the task has been scheduled with success
  * <code>E*</code>: unexpected error: task has not been scheduled
  *
  */
  HRESULT CreateAsyncPLMQueryTaskWithNoSRStatus( CATAsyncTaskID & oAsyncTaskId,
                                                 CATIPLMQueryFilter& iQueryFilter,
                                                 CATBoolean iForceNoMultiProcessExecution,
                                                 CATIAsyncTaskCompletionCallBackBase& iAsyncTaskCompletionCallBack,
                                                 CATIPLMExpandResultHandler& iExpandHandler,
                                                 const CATAsyncTaskID & iAsyncTaskParentId = CATAsyncTaskID_Null );

  /**
  * Creates an Asynchronous PLMQL Task.
  * This task has a physical task behavior @see usage note.
  *
  * If the MP Platform is used, this PLMQL physical task executes the service :
  *   <code>ExecuteTask(CATIPLMQueryFilter& iQueryFilter,CATIPLMExpandResultHandler& iExpandHandler,</code>
  *
  *
  * @param
  * <br/> [out] oAsyncTaskId : id of the task
  * <br/> [in] iQueryFilter : the query to perform
  * <br/> [in] iExpandHandler : Push Expand callback. As soon as the deported process has received enough data from the server, it will awake CATIA
  *                              and call the EpandHandler to provide it with the latest data retrieved from the server
  * <br/> [in] iAsyncTaskCompletionCallBack : callback that is called when task is completed
  * <br/> [in][opt] iAsyncTaskParentId : Logical Task on which the new created Physical Task will be attached
  * @return
  * <code>S_OK</code>: the task has been scheduled with success
  * <code>E*</code>: unexpected error: task has not been scheduled
  *
  */
  HRESULT CreateAsyncPLMQueryTask( CATAsyncTaskID & oAsyncTaskId,
                                   CATIPLMQueryFilter& iQueryFilter,
                                   CATIAsyncTaskCompletionCallBackBase& iAsyncTaskCompletionCallBack,
                                   CATIPLMExpandResultHandler& iExpandHandler,
                                   const CATAsyncTaskID & iAsyncTaskParentId = CATAsyncTaskID_Null );

  /**
  * Creates an asynchronous PLMQuery task that leverage the persistant data cache (aka L1 Cache
  * for attributes) in order to optimize the quantity of data retrieved from the server.
  *
  * @param
  * <br/> [out] oAsyncTaskId : id of the task
  * <br/> [in] iQueryFilter : the query to perform
  * <br/> [in] iAppId : the application identifier that describes the attributes to retrieve.
  * <br/> [in] iAsyncTaskCompletionCallBack : callback that is called when task is completed
  * <br/> [in][opt] iAsyncTaskParentId : Logical Task on which the new created Physical Task will be attached
  * @return
  * <code>S_OK</code>: the task has been scheduled with success
  * <code>E*</code>: unexpected error: task has not been scheduled
  */
  HRESULT CreateAsyncPDCQueryPhysicalTask( CATAsyncTaskID & oAsyncTaskId,
                                           CATIPLMQueryFilter& iQueryFilter,
                                           CATIPLMCompStatementService::ApplicationIdentifier iAppId,
                                           CATIAsyncTaskCompletionCallBackBase& iAsyncTaskCompletionCallBack,                                        
                                           const CATAsyncTaskID & iAsyncTaskParentId = CATAsyncTaskID_Null );  

  /**
  * Creates an asynchronous PLMQuery task that leverage the persistant data cache (aka L1 Cache
  * for attributes) in order to optimize the quantity of data retrieved from the server.
  *
  * @param
  * <br/> [out] oAsyncTaskId : id of the task
  * <br/> [in] iQueryFilter : the query to perform
  * <br/> [in] iAppId : the application identifier that describes the attributes to retrieve.
  * <br/> [in] iExpandHandler : Push Expand callback. As soon as the deported process has received enough data from the server, it will awake CATIA
  *                             and call the EpandHandler to provide it with the latest data retrieved from the server
  * <br/> [in] iAsyncTaskCompletionCallBack : callback that is called when task is completed
  * <br/> [in][opt] iAsyncTaskParentId : Logical Task on which the new created Physical Task will be attached
  * @return
  * <code>S_OK</code>: the task has been scheduled with success
  * <code>E*</code>: unexpected error: task has not been scheduled
  */
  HRESULT CreateAsyncPDCQueryPhysicalTask( CATAsyncTaskID & oAsyncTaskId,
                                           CATIPLMQueryFilter& iQueryFilter,
                                           CATIPLMCompStatementService::ApplicationIdentifier iAppId,
                                           CATIAsyncTaskCompletionCallBackBase& iAsyncTaskCompletionCallBack,
                                           CATIPLMExpandResultHandler& iExpandHandler,
                                           const CATAsyncTaskID & iAsyncTaskParentId = CATAsyncTaskID_Null );

private:

  IPLMDumpAndTransmitExpandHandlerFactory& _Factory() const;

  // Copy constructor and equal operator
  // -----------------------------------
  CATAsyncPLMTasksFactory (CATAsyncPLMTasksFactory &);
  CATAsyncPLMTasksFactory& operator=(CATAsyncPLMTasksFactory&);
};

//-----------------------------------------------------------------------

#endif