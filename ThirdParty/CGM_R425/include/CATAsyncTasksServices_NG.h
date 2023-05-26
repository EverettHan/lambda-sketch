//===================================================================
// COPYRIGHT Microsoft 2012/02/10
//===================================================================
// CATAsyncTasksServices_NG.cpp
// Header definition of class CATAsyncTasksServices_NG
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2012/02/10 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATAsyncTasksServices
#define CATAsyncTasksServices CATAsyncTasksServices_NG
#endif

#ifndef CATAsyncTasksServices_NG_H
#define CATAsyncTasksServices_NG_H

#include "CATAsyncTasksPlatform_NG.h"
#include "CATAsyncTaskID_NG.h"
#include "CATOmxArray.h"
#include "CATAsyncTasksUtils.h"
#include "CATAsyncTaskContext_NG.h"

//-----------------------------------------------------------------------

class CATAsyncTaskListener;

class ExportedByCATAsyncTasksPlatform CATAsyncTasksServices
{
public:
  // Standard constructors and destructors
  // -------------------------------------
  CATAsyncTasksServices ();
  virtual ~CATAsyncTasksServices ();

  /**
  * Adds a Task (logical or physical) to the Logical Task iLogicalTaskId
  * 
  * The task can be add only if 
  * . These following conditions are always respected:
  *   - The Task is not started
  *   - The Task is not already contained in another Logical Task
  *   - The Task is either a physical or a non empty Logical Task
  *   - The two tasks in param are different
  * And
  * . One of following conditions is respected:
  *   - The main Logical Task is not started.
  *   - The main logical task is started and the method is called in the main Logical Task Context (ie during a call-back linked to the logical task) 
  * @param
  * <br/> [in] iLogicalTaskId: the logical task id
  * <br/> [in] iTaskId: the task id to add
  * @return
  * <code>S_OK</code>: The task is correctly added to the main logical task
  * <code>E*</code>: the physical task is not added to the logical task because:
  *                   - the conditions above are not complied
  *                   - the async task platform is not working
  */
  HRESULT AddAsyncTask(const CATAsyncTaskID & iLogicalTaskId, const CATAsyncTaskID & iAsyncTaskId);

  /**
  * Starts the asynchronous task.
  * The task may be logical or physical, however a physical task cannot be started if it is attached to a logical task.
  * A started task cannot be started again (ended or not).
  * A started task does not mean it is running immediatly, the task can be effectively launched at any time by the async tasks platform.
  * Beware that the CallBack of the task can be called by the call of this method (except if the the CallBack is always called on the Event Loop)
  *
  * @param
  * <br/> [in] iTaskId: the async task to start
  * @return
  * <code>S_OK</code>: the async is correctly started
  * <code>E*</code>: the async task is not stared started because:
  *                   - a condition is not repected
  *                   - the async task platform is not working
  */
  HRESULT StartAsyncTask(const CATAsyncTaskID & iTaskId);

  /**
  * Ask to the platform if the task is started, meaning that a call to StartAsyncTask or StartAsyncTaskAndWait has been made on the Task in parameter
  * The task has to exist, otherwise the boolean status is meaningless
  * The boolean status returns TRUE if the task is ended
  *
  * @param
  * <br/> [in] iTaskId: the async task to start
  * <br/> [out] obAsyncTaskStarted: TRUE if the task is started, FALSE otherwise
  * @return
  * <code>S_OK</code>: The Task do exist
  * <code>E*</code>: an error occured:
  *                   - the task does not exist
  *                   - unkwnon error
  */
  HRESULT IsAsyncTaskStarted(const CATAsyncTaskID & iTaskId, CATBoolean & obAsyncTaskStarted);

  /**
  * Starts the asynchronous task.
  * The task may be logical or physical, however a physical task cannot be started if it is attached to a logical task.
  * A started task cannot be started again (ended or not).
  * A started task does not mean it is running immediatly, the task can be effectively launched at any time by the async tasks platform.
  * Beware that the CallBack of the task can be called by the call of this method (except if the the CallBack is always called on the Event Loop)
  *
  * After starting wait the completion of the asynchronous task.
  * If the task is a logical task, the call to this method will wait the completion of all physical tasks attached (only if they are not finished).
  * This method cannot work if you are in the context of starting task 
  *
  * /!\ BE WARNED THAT ALL THE COMPLETION CALLBACKS WILL BE CALLED BEFORE THE RETURN OF THE METHOD
  * /!\ CALLING THIS METHOD CAN FORCE THE COMPLETION OF OTHER ASYNC TASKS
  *
  * @param
  * <br/> [in] iTaskId: the async task to start
  * @return
  * <code>S_OK</code>: the async is correctly started
  * <code>CATOmy_E_Waited_Task_On_Reentrant_Pattern</code> : the async task should be started inside another start stack. The Platform cannot handle such start situation, so it cannot wait a task that cannot be started
  * <code>E*</code>: the async task is not stared started because:
  *                   - a condition is not repected
  *                   - the async task platform is not working
  */
  HRESULT StartAsyncTaskAndWait(const CATAsyncTaskID & iTaskId);

  /**
  * Starts the asynchronous task and waif for new tasks.
  * The task has to be a logical
  * The task never ends until calling <code>Terminate</code> method
  *
  * A started task cannot be started again (ended or not).
  * A started task does not mean it is running immediatly, the task can be effectively launched at any time by the async tasks platform.
  *
  * @param
  * <br/> [in] iTaskId: the async task to start
  * @return
  * <code>S_OK</code>: the async is correctly started
  * <code>CATOmy_E_Waited_Task_On_Reentrant_Pattern</code> : the async task should be started inside another start stack. The Platform cannot handle such start situation, so it cannot wait a task that cannot be started
  * <code>E*</code>: the async task is not stared started because:
  *                   - a condition is not repected
  *                   - the async task platform is not working
  */
  HRESULT StartAsyncTaskAndWaitForTasks(const CATAsyncTaskID & iTaskId);

  /**
  * Wait the completion of the asynchronous task.
  * If the task is a logical task, the call to this method will wait the completion of all physical tasks attached (only if they are not finished).
  * This method cannot work if you are in the context of starting task 
  *
  * /!\ BE WARNED THAT ALL THE COMPLETION CALLBACKS WILL BE CALLED BEFORE THE RETURN OF THE METHOD
  * /!\ CALLING THIS METHOD CAN FORCE THE COMPLETION OF OTHER ASYNC TASKS
  *
  * @param
  * <br/> [in] iTaskId: the async task to start
  * @return
  * <code>S_OK</code>: the async task has been waited and is completed
  * <code>CATOmy_E_Waited_Task_On_Reentrant_Pattern</code> : the async task should be started inside another start stack. The Platform cannot handle such start situation, so it cannot wait a task that cannot be started
  * <code>E_FAIL</code>: the async has been waited but is not completed
  * <code>E*</code>: another error occured
  */
  HRESULT WaitAsyncTask(const CATAsyncTaskID & iTaskId);

  /**
  * Wait the completion of all scheduled asynchronous tasks.
  * If the task is a logical task, the call to this method will wait the completion of all physical tasks attached (only if they are not finished).
  * This method cannot work if you are in the context of starting task 
  *
  * /!\ IF THIS METHOD HAS TO BE CALLED, IT IS ADVISED TO CALLED BEFORE THE METHOD <code>AsyncTaskToWait</code>
  * /!\ BE WARNED THAT ALL THE COMPLETION CALLBACKS WILL BE CALLED BEFORE THE RETURN OF THE METHOD
  * /!\ CALLING THIS METHOD CAN FORCE THE COMPLETION OF OTHER ASYNC TASKS
  *
  * @param
  * <br/> [in] iTaskId: the async task to start
  * @return
  * <code>S_OK</code>: the async taks have been waited and all are completed
  * <code>CATOmy_E_Waited_Task_On_Reentrant_Pattern</code> : the async task should be started inside another start stack. The Platform cannot handle such start situation, so it cannot wait a task that cannot be started
  * <code>E_FAIL</code>: the async tasks have been waited but at least of them is not completed
  * <code>E*</code>: another error occured
  */
  HRESULT WaitAllAsyncTasks();

  /**
  * If the value of <code>ibNotifyProgression</code> is TRUE, the task will notify the progression
  * by calling the <code>OnTaskProgressed</code> callback (@see CATIAsyncTaskCompletionCallBack)
  * WARNING: If the method is called on a Logical Task, it is not propagate on children Physical Task 
  * The data containing the progression are stored in the CATAsyncTaskContextBase.ProgressionData structure (@see CATAsyncTaskContext)
  * The data content is depending on the kind of Async Task :
  * . LogicalTask :
  *   - CATAsyncTaskContext.ProgressionData[0] : Physical Tasks Completed count
  *   - CATAsyncTaskContext.ProgressionData[1] : Physical Tasks not Completed
  * . PhysicalTask :
  *   . VVSRequest   : @see CATAsyncProgressVVSData
  *   . PLMQLRequest : @see CATAsyncProgressPLMQLData
  * @param
  * <br/> [in] iTaskId: The Async Tasks that notifies
  * <br/> [in] ibNotifyProgression: Active/Deactive progression notification
  * @return
  * <code>S_OK</code>: The Async task will notify the progression
  * <code>E*</code>: An error occured, the task will not notify the progression
  */
  HRESULT SetNotifyProgression(const CATAsyncTaskID & iTaskId, CATBoolean ibNotifyProgression);

  /**
  * Indicates if the task in param notifies its progression
  * if the task is completed or does not exist, method failed and <code>obNotifyProgression</code> is not relevant
  *
  * @param
  * <br/> [in] iTaskId: Async Tasks
  * <br/> [in] obNotifyProgression: TRUE is task nofities its progression, FALSE otherwise
  * @return
  * <code>S_OK</code>: The Async task will notify the progression
  * <code>E_FAIL</code>: The Async task is completed or does not exist
  * <code>E*</code>: An error occured
  */
  HRESULT IsProgressionNotified(const CATAsyncTaskID & iTaskId, CATBoolean& obNotifyProgression);

  /*
  * Adds a task listener on the given task.
  *
  * @param
  * <br/> [in] iTaskId: Async Tasks
  * <br/> [in] CATAsyncTaskListener: the task listener
  *
  * @return
  * <code>S_OK</code>: The task listener has been added on the task
  * <code>E_FAIL</code>: The Async task is completed or does not exist
  */
  HRESULT AddTaskListener(const CATAsyncTaskID & iTaskId, CATAsyncTaskListener* ipTaskListener);

  /**
  * Cancels the asynchronous task.
  * The task may be logical or physical, however a physical task cannot be canceled if it is attached to a logical task.
  * A not stared task cannot be canceled.
  * An ended task cannot be canceled.
  * If the task is a logical task, all the physical tasks attached are canceled (only if they are not finished).
  * The CallBack of all async tasks implied by the cancel order are called.
  * All async tasks implied by the cancel have their status turning to Fail. (<code>IsAsyncTaskSucceeded</code> method return <code>E_FAIL</code>)
  *
  * @param
  * <br/> [in] iTaskId: the async task to cancel
  * @return
  * <code>S_OK</code>: the async is correctly canceled (and all the potential physical tasks attached too)
  * <code>E*</code>: unexpected error:the async task is not canceled because:
  *                   - a condition is not repected
  *                   - the async task platform is not working
  */
  HRESULT CancelAsyncTask(const CATAsyncTaskID & iTaskId);

  /**
  * ...
  *
  * @param
  * <br/> [int] iTaskID: ...
  * <br/> [out] oAsyncTaskContext: ...
  * @return
  * <code>S_OK</code>: ...
  * <code>E*</code>: ...
  */
  HRESULT GetAsyncTaskContext(const CATAsyncTaskID & iTaskID, CATAsyncTaskContextBase & oAsyncTaskContext);

  /**
  * Get the async task in the current context.
  * The method is only useful when called during the CallBack of an async task (so it returns the associated taskId of the async task).
  * Otherwise the method systematically fails. 
  *
  * @param
  * <br/> [out] oTaskId: The Aync Task in the current context
  * @return
  * <code>S_OK</code>: the AsyncTaskId returned is correct 
  * <code>E*</code>: the AsyncTaskId is unusable, there is no async task in the context
  */
  HRESULT GetAsyncTaskInContext(CATAsyncTaskID & oTaskId);

  /**
  * Gets the Logical Task which has the physical task given in parameter attached
  * The method succeeds only if the physical is effectively attached to a logical task
  *
  * @param
  * <br/> [in] iTaskId: the child task
  * <br/> [out] oLogicalTaskId: the logical task associated 
  * @return
  * <code>S_OK</code>: the parent task does exist
  * <code>S_FALSE</code>: the task has not parent task, oLogicalTaskId is NULL
  * <code>E*</code>: an error occured, the iTaskId may not exist
  */
  HRESULT GetParentLogicalTask(const CATAsyncTaskID & iTaskId, CATAsyncTaskID & oLogicalTaskId, CATBoolean ibLastParent = FALSE);

  /**
  * Gets the Physical Tasks which have the Logical Task in parameter as parent
  *
  * @param
  * <br/> [in] iLogicalTask: the logical task
  * <br/> [out] oChildrenPhysicalTasks: the physical tasks attached
  */
  HRESULT GetChildrenAsyncTasks(const CATAsyncTaskID &iLogicalTask, CATOmxArray<CATAsyncTaskID> &oChildrenAsyncTasks);

  /**
  * Ask to the platform if the task does exist
  * If the task exists, oAsyncTaskType indicates the task type (@see CATAsyncTasksUtils)
  *
  * @param
  * <br/> [in] iTaskId: the async task to check existence
  * <br/> [out] oAsyncTaskType: Task type if it exists
  * @return
  * <code>S_OK</code>: The Task does exist
  * <code>S_FALSE</code>: The Task does not exist
  * <code>E*</code>: an error occured
  */
  HRESULT IsAsyncTaskExisting(const CATAsyncTaskID & iTaskId, CATAsyncTask_Type & oAsyncTaskType);

  /**
  * Indicates if the async task given in parameter is a logical task
  *
  * @param
  * <br/> [in] iTaskId: the async task
  * @return
  * <code>S_OK</code>: if the async task is an async logical task
  * <code>S_FALSE</code>: if the async task is not an async logical task (the task may not exist)
  * <code>E*</code>: unexpected error
  */
  HRESULT IsLogicalTask(const CATAsyncTaskID & iTaskId);

  /**
  * Indicates if the async task given in parameter is a physical task
  *
  * @param
  * <br/> [in] iTaskId: the async task
  * @return
  * <code>S_OK</code>: if the async task is an async physical task
  * <code>S_FALSE</code>: if the async task is not an async physical task (the task may not exist)
  * <code>E*</code>: unexpected error
  */
  HRESULT IsPhysicalTask(const CATAsyncTaskID & iTaskId);

  /**
  * Indicates if the async task given in parameter is succeeded.
  * The method is pertinent only if the task exists and it is completed.
  *
  * @param
  * <br/> [in] iTaskId: the async task
  * @return
  * <code>S_TASK_OK</code>: The task is succeeded
  * <code>E_TASK_NOT_COMPLETED</code>: The task is not completed yet
  * <code>E_TASK_CANCEL_BY_USER</code>: The task has been canceled by user
  * <code>E_TASK_CANCEL_BY_PLATFORM</code>: The task has been automatically canceled by the async tasks platform
  * <code>E_TASK_FUNC_ERROR</code>: A functionnal error occured (ex: bad query)
  * <code>E_TASK_SYST_ERROR</code>: A system error occured (ex: issue with the async platform)
  * <code>E_TASK_NOT_EXISTING</code>: The task in parameter does not exist
  */
  CATAsyncTaskStatus GetAsyncTaskStatus(const CATAsyncTaskID & iTaskId);

  /**
  * Deletes the async task given in parameter, meaning all the structures associated to the task inside the async task platform will be released.
  * The method succeeds only if the async taskit is not started or it is completed
  *
  * This method is useful only to free the memory, there is no functionnal effect except to keep no trace of the async task (ie the async task platform don't keep no other trace of the task)
  *
  * @param
  * <br/> [in] iTaskId: the async task to delete
  * @return
  * <code>S_OK</code>: the task is correctly deleted
  * <code>E*</code>: the task is not deleted, it may not exist or it is started and not completed 
  */
  HRESULT DeleteAsyncTask(const CATAsyncTaskID & iTaskId);

  /**
  * After calling this method,
  * new Tasks can be added to input logical task (<code>AddAsyncTask</code>) until explicit call to <code>Terminate</code>
  * The task never ends until then.
  *
  * @param
  * <br/> [in] iTaskId: the id of the logical async task to keep alive
  * @return
  * <code>S_OK</code>: the task is correctly set in WaitForTasks mode.
  * <code>E*</code>: Platform cannot keep task alive.
  */
  HRESULT WaitForTasks(const CATAsyncTaskID & iLogicalTaskId);

  /**
  * Keep the task alive and running until an explicit call to Terminate is made.
  *
  * @param
  * <br/> [in] iTaskId: the id of the logical async task to keep alive
  * @return
  * <code>S_OK</code>: the task is correctly set in keep alive mode.
  * <code>E*</code>: Platform cannot keep task alive.
  */
  HRESULT KeepAliveUntilExplicitCallToTerminate(const CATAsyncTaskID & iLogicalTaskId);

  /**
  * Terminate the logical task.
  * Two cases :
  *   .If NeverEnding Task :
  *       This is syncronous (blocking) call.
  *       All tasks are canceled and the following callbacks will be called:
  *         - callbacks of Physical Task 
  *         - callbacks of Logical Task 
  *   .If WaitForTasks Task :
  *       No blocking call
  *       The input tasks returns to basic logical task behavior :
  *         - Cannot add new tasks outside logical task context
  *         - Callback of logical task is called when all tasks attached are completed
  *
  * @param
  * <br/> [in] iTaskId: the id of the logical async task to terminate
  * @return
  * <code>S_OK</code>: the task is correctly terminated.
  * <code>E*</code>: The task is not properly terminated, or called on a not basic logical task.
  */
  HRESULT Terminate(const CATAsyncTaskID & iLogicalTaskId);

  /**
  * Flush all the physical tasks that are not running in the logical task.
  *
  * @param
  * <br/> [in] iTaskId: the id of the logical async task to terminate
  * @return
  * <code>S_OK</code>: tasks are correctly flushed.
  * <code>E*</code>: tasks are not properly flushed.
  */
  HRESULT FlushAllNonRunningTask(const CATAsyncTaskID & iLogicalTaskId);

  /**
  * Get the async tasks builder settings
  * Works only if iTasksBuilderId is an AsyncTaskBuilder Id
  *
  * @param
  * <br/> [in] iTasksBuilderId: Task Builder Id
  * <br/> [out] oTasksBuilderSettings: Task Builder Settings
  * @return
  * <code>S_OK</code>: oTasksBuilderSettings contains the task builder settings requesteded
  * <code>E*</code>: an error occured, the iTasksBuilderId may not exist or is not a task builder
  */
  HRESULT GetAsyncTasksBuilderSettings(const CATAsyncTaskID & iTasksBuilderId, AsyncTasksBuilderSettings& oTasksBuilderSettings);

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATAsyncTasksServices (CATAsyncTasksServices &);
  CATAsyncTasksServices& operator=(CATAsyncTasksServices&);

};

//-----------------------------------------------------------------------

#endif