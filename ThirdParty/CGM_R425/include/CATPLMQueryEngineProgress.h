/* -*-c++-*- */
#ifndef CATPLMQueryEngineProgress_H
#define CATPLMQueryEngineProgress_H
//
// CATIA Version 6 Release 208
// Copyright   : Dassault Systemes 2009
//-----------------------------------------------------------------------------
// Description :
// C++ class header file for the class named "CATPLMQueryEngineProgress"
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Inheritance : CATPLMQueryEngineProgress
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//

/**
 * @level Protected
 * @usage U1
 */

#include "CATPLMModelBuilder.h"
#include "CATBaseUnknown.h"

#define TASKID_Expand 0
#define TASKID_Open   1
#define TASKID_Stream 2
#define TASKID_Model  3
#define TASKID_Switch 4

#define TASKNAME_Expand "expand"
#define TASKNAME_Open   "open"
#define TASKNAME_Stream "stream"
#define TASKNAME_Model  "model"
#define TASKNAME_Switch "switch"

/**
 * Describe informations related to the progression of a CATPLMOperationContext/CATPLMQueryEngine query execution.
 * @see CATPLMOperationContext
 * @see CATPLMQueryEngine
 * Informations are organized as a list of tasks, each task having an id, a name, a current progression value
 * and may have an optional max value (for exemple, it is currently impossible to know the number of objects given by
 * an Expand operation on server side. As a consequence, it is impossible to evaluate a max value).
 * 
 * Sample 1: Get informations related to current task:
 *   CATPLMQueryEngineProgress *progress = ...;
 *   unsigned int taskID = 0;
 *   const char *taskName = NULL;
 *   unsigned int value = 0;
 *   unsigned int max = 0;
 *   if (SUCCEEDED(progress->GetProgress(taskID, taskName, value, max))) {
 *      ...
 *   }
 * 
 * Sample 2: Get informations related to a specific task:
 *   CATPLMQueryEngineProgress *progress = ...;
 *   if (SUCCEEDED(progress->SetTask(TASKID_Stream))) {
 *      unsigned int taskID = 0;
 *      const char *taskName = NULL;
 *      unsigned int value = 0;
 *      unsigned int max = 0;
 *      if (SUCCEEDED(progress->GetProgress(taskID, taskName, value, max))) {
 *         ...
 *      }
 *   }
 * 
 * Sample 3: Get informations related to the entire list of tasks:
 *   CATPLMQueryEngineProgress *progress = ...;
 *   if (SUCCEEDED(progress->ResetLoop())) {
 *      unsigned int taskID = 0;
 *      const char *taskName = NULL;
 *      unsigned int value = 0;
 *      unsigned int max = 0;
 *      while (SUCCEEDED(progress->Next())) {
 *         if (SUCCEEDED(progress->GetProgress(taskID, taskName, value, max))) {
 *            ...
 *         }
 *      }
 *   }
 */	
class ExportedByCATPLMModelBuilder CATPLMQueryEngineProgress : public CATBaseUnknown
{
public:
	/**
	 * The the current task to a given id.
	 * @param iTaskId
	 *    Task id.
	 * @return
	 *    S_OK  : Ok.
	 *    E_FAIL: task is not active.
	 */	
	virtual HRESULT SetTask(unsigned int iTaskId) =0;

	/**
	 * Init the current task loop. To be called before Next.
	 * @return
	 *    S_OK  : Ok.
	 *    E_FAIL: Otherwise.
	 */	
	virtual HRESULT ResetLoop() =0;

	/**
	 * Go to the next task in the list.
	 * @return
	 *    S_OK  : Ok.
	 *    E_FAIL: No more task in the list.
	 */	
	virtual HRESULT Next() =0;

	/**
	 * Get current task progression informations.
	 * @param oTaskId
	 *    The task ID.
	 * @param oTaskName
	 *    The task name.
	 * @param oValue
	 *    The current progression value for this task.
	 * @param oMaxValue
	 *    The maximum progression value that this task can have.
	 *    If 0, this information is irrelevant.
	 * @return
	 *    S_OK  : Ok.
	 *    E_FAIL: Otherwise.
	 */	
	virtual HRESULT GetProgress(unsigned int &oTaskId, const char *&oTaskName, unsigned int &oValue, unsigned int &oMaxValue) =0;

	/**
	 * Get current task progression extra informations.
	 * @param oExtraInfos
	 *    Extra information associated to current task.
	 * @return
	 *    S_OK  : Ok.
	 *    E_FAIL: Otherwise.
	 */	
	virtual HRESULT GetExtraInfos(unsigned int &oExtraInfos) =0;
protected:
	CATPLMQueryEngineProgress() {};
};
#endif
