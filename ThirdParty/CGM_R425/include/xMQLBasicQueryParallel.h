//===================================================================
// COPYRIGHT Dassault Systemes 2018/02/21
//===================================================================
// xMQLBasicQueryParallel.cpp
// Header definition of class xMQLBasicQueryParallel
//===================================================================
//
//      Example of usage : 
//    CreateMainTask();
//    AddParallelTask();
//        ...
//    AddParallelTask();
//    LaunchParallelTasks();
// 
// Usage notes:
//   This class allows to send parallels XMQL BASIC QUERIES
//===================================================================
//  2018/02/21 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef xMQLBasicQueryParallel_H
#define xMQLBasicQueryParallel_H

#include "CATPLMxMQL.h"
#include "CATXMQLRequestBase.h"
#include "CATOmxList.h"
#include "CATAsyncXMQLCollections.h"
#include "CATPLMOmxCollections.h"
#include "CATAsyncTaskID_NG.h"
#include "CATAsyncTaskCompletionCallBack_NG.h"

class CATIXMQLCallBack;
class CATAsyncTaskCompletionCallBackBase;

//-----------------------------------------------------------------------

class ExportedByCATPLMxMQL xMQLBasicQueryParallel
{

public:

  enum ObjectTypes { Bus, Conn };
  // Standard constructors and destructors
  // -------------------------------------
  xMQLBasicQueryParallel();
  virtual ~xMQLBasicQueryParallel();


  /**
  *
  * <br><b>Creates a main Task (a logical task) with a given CallBack where physical task could be attached with the procedure 'AddParallelTask' </b>:
  * @param oTaskId
  * The ID of the logical task
  * @param ipCB
  * Call back to be called by the tasks
  * @return
  * <dl>
  * <dt><code>S_OK</code> if the task has been successfully created<dd>
  * <dt><code>E_FAIL</code> if the creation has failed  <dd>
  * </dl>
  */
  HRESULT CreateMainTask(CATAsyncTaskID & oTaskId, CATIXMQLCallBack* ipCB);



  /**
  *
  * <br><b> Creates a new physical task attached to the mainTask
  *         If the number of CATXMQLRequestBase in 'requests' is greater than 1
  *         the request attached to 'mainTask' will be send as a multirequest.
  *
  * </b>:
  * @param iMainTask
  *  The ID of the logical task where the new physical task will be attached
  * @param iRequests
  *  List of the XMQL Basic Query
  * @return
  * <dl>
  * <dt><code>S_OK</code> if the task has been successfully attached to 'iMainTask' <dd>
  * <dt><code>E_FAIL</code>if the add of the physical task has failed <dd>
  * </dl>
  */
  HRESULT AddParallelTask(CATAsyncTaskID & iMainTask, CATOmxList<CATXMQLRequestBase> iRequests, xMQLRequest::Args &oArgs);



  /**
  *
  * <br><b>Launch the logical 'iMainTask' task and the associated physical task </b>:
  * @param iMainTask
  *  The ID of the logical task where  physical tasks are attached
  * @param isAsync
  *  if 'TRUE' the requests are sent async.
  * @return
  * <dl>
  * <dt><code>S_OK</code>  if the tasks have been successfully sent <dd>
  * <dt><code>E_FAIL</code> if something gone wrong<dd>
  * </dl>
  */
  HRESULT LaunchParallelTasks(CATAsyncTaskID & iMainTask, CATBoolean isAsync);



private:
  // Copy constructor and equal operator
  // -----------------------------------
  xMQLBasicQueryParallel(xMQLBasicQueryParallel &);
  xMQLBasicQueryParallel& operator=(xMQLBasicQueryParallel&);

  CATAsyncTaskCompletionCallBackBase* _pPlatformCompletionCallBack;


};

//-----------------------------------------------------------------------

#endif
