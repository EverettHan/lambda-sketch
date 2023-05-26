#ifndef __CATIOmxBackgroundTasks_H
#define __CATIOmxBackgroundTasks_H

#include "CATOmxKernel.h"
#include "CATOmxSharable.h"
#include "CATDataType.h"
#include "CATOmxSR.h"

class CATIOmxBackgroundTaskController;

/**
 * Task interface for CATIOmxBackgroundTasks
 */
class CATIOmxBackgroundTask: public CATOmxSharable
{
public:
  typedef int Id;
  /**
   * Execute the task.
   */
  virtual void Execute(CATIOmxBackgroundTaskController& ) = 0;
};


/**
 * This interface allows to start tasks in background threads and to wait for their completion in "main" thread.
 * You should preferably use directly CATOmxBackgroundTasks which allows stronger typing.
 * 
 * Notice that by default the number of background threads is one.
 * Notice that destructor will wait completion of running tasks but will not launch pending tasks.
 */
class CATIOmxBackgroundTasks: public CATOmxSharable
{
public:
  /** factory*/
  ExportedByCATOmxKernel static CATIOmxBackgroundTasks* Create(unsigned int iFlags = 0);

  /**
   * Queue a task. 
   * Task will be started when a free execution thread will be available
   * @param iTask
   *  the task to launch in separate thread
   * @param oId
   *   the id of the queued task
   * Notice that by default, if SetJobs has not been called, there is one unique execution thread.
   */
  virtual HRESULT QueueTask(CATIOmxBackgroundTask* iTask,CATIOmxBackgroundTask::Id* oId = NULL) = 0;

  /** @see iTimeoutMilliSeconds argument of following method */
#define OMXBT_NOWAIT CATLONG64(0)
#define OMXBT_INFINITE  CATLONG64(-1)

  /** see iId argument of following method*/
#define OMXBT_NEXTTASK ((CATIOmxBackgroundTask::Id)-1)

  /* @see return codes of following method*/
#define OMXBT_E_NOTASK   MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF,0x95AD)
#define OMXBT_E_TIMEOUT  MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF,0x95AE)
#define OMXBT_E_DEADLOCK MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF,0x95AF)

  /**
   * Wait for the completion of a task.
   * @param iTimeoutMilliSeconds:
   *   Time out value.
   *     OMX_NOWAIT       :  do not wait for task completion
   *     OMX_INFINITE     :  wait until task is completed
   *     strictly positive:  wait this amount of time (Not implemented on all levels)
   * @param iId
   *   id of the task to return
   *   OMXBT_NEXTTASK means that returned tasks are in the same order as they have been queued
   *   no other value supported for the moment
   * @return
   *   S_OK: success
   *   OMXBT_E_NOTASK    : No task queued/all tasks already completed and returned
   *   OMXBT_E_TIMEOUT   : time out
   *   OMXBT_E_DEADLOCK: Job count is 0
   */
  virtual HRESULT WaitTaskCompletion(CATLONG64 iTimeoutMilliSeconds,CATIOmxBackgroundTask::Id iId,CATIOmxBackgroundTask*& oTask,CATIOmxBackgroundTask::Id* oTaskId = NULL) = 0;

  /**
   * Set the number of background threads.
   * @param iJobs
   *   Must be positive or zero.
   *   Zero means that all threads will be put in a paused state until a new call to SetJobs() with iJobs>0
   * @param iWait
   *   Can be used only with iJobs=0
   *   In this case this method will wait the completion of already running tasks if any.
   * Notice that threads are lazily created when tasks are queued of if there are pending tasks. 
   */
  virtual HRESULT SetJobs(int iJobs,CATBoolean iWait=FALSE)=0;

  /** Output of GetInfos method*/
  struct Infos 
  {
    /** Number of jobs*/
    int Jobs;
    /** Number of running jobs (can be greater than Jobs)*/
    int RunningJobs;
    /** Number of completed tasks (Retrievable by WaitTaskCompletion with no wait)*/
    int CompletedTasks;
    /** Number of pending tasks (Queued but not started)*/
    int PendingTasks;
  };

  /**
   * Retrive informations on the background tasks
   * 
   */
  virtual HRESULT GetInfos(Infos& oInfos)=0;

};

/**
 * The same class as CATIOmxBackgroundTasks with strong typing
 * Usage:
 *   class MyTask: public CATIOmxBackgroundTask
 *   {
 *     virtual void Execute(CATIOmxBackgroundTaskController& ) 
 *     {
 *       //Do some work
 *     }
 *   };
 *   
 *   CATOmxSR<CATOmxBackgroundTasks<MyTask> > hBackgroundTasks(CATOmxSR<CATOmxBackgroundTasks<MyTask> >::Create());
 *
 *   //Queue a task
 *   CATOmxSR<MyTask> task(new MyTask(...),Steal);
 *   hBackgroundTasks->QueueTask(task);
 *
 *   //Do some work in this thread...
 *
 *   //Wait task completion
 *   task = NULL;
 *   hBackgroundTasks->WaitTaskCompletion(task);
 *   
 */
template<class Task>
class CATOmxBackgroundTasks: public CATIOmxBackgroundTasks
{
  inline CATIOmxBackgroundTasks* Base() {return this;}
public:
  /** factory*/
  inline static CATOmxSR<CATOmxBackgroundTasks<Task> > Create(unsigned int iFlags = 0) 
  {
    return CATOmxSR<CATOmxBackgroundTasks<Task> >(static_cast<CATOmxBackgroundTasks<Task>*>(CATIOmxBackgroundTasks::Create(iFlags)),Steal);
  }

  /** @see CATIOmxBackgroundTasks::QueueTask*/
  inline HRESULT QueueTask(Task* iTask) {return Base()->QueueTask(iTask,NULL);}

  /** @see CATIOmxBackgroundTasks::WaitTaskCompletion*/
  inline HRESULT WaitTaskCompletion(CATOmxSR<Task>& oTask) 
  {
    return Base()->WaitTaskCompletion(OMXBT_INFINITE,OMXBT_NEXTTASK,reinterpret_cast<CATIOmxBackgroundTask*&>(oTask.AsPtrRef()),NULL);
  }

  /** @see CATIOmxBackgroundTasks::WaitTaskCompletion*/
  inline HRESULT WaitTaskCompletion(CATLONG64 iTimeoutMilliSeconds,CATOmxSR<Task>& oTask) 
  {
    return Base()->WaitTaskCompletion(iTimeoutMilliSeconds,OMXBT_NEXTTASK,reinterpret_cast<CATIOmxBackgroundTask*&>(oTask.AsPtrRef()),NULL);
  }
};


#endif
