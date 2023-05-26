#ifndef CATAsyncBasicTypes_H
#define CATAsyncBasicTypes_H

#include "CATAsyncTasksPlatform_NG.h"
#include "CATBoolean.h"
#include "CATOmxVector.h"
#include "CATOmxList.h"
#include "CATOmyCioUrlUsageCtx.h"
#include "CATOmxSR.h"
#include "CATOmxSharable.h"

class CATUnicodeString;

//===================================================================
//  Async Request Types
//===================================================================
enum CATAsyncRequest_Type
{
  CATAsyncRequest_NoRequest,
  CATAsyncRequest_VVS,
  CATAsyncRequest_FCS,
  CATAsyncRequest_PLM_Query,
  CATAsyncRequest_PDC_Query, // PLMAdapter query using Persistant Data Cache (aka Pere Dodu)
  CATAsyncRequest_Push_PDC_Query, // PLMAdapter query using Persistant Data Cache (aka Pere Dodu)
  CATAsyncRequest_Push_PLM_Query,
  CATAsyncRequest_AutoComplete,
  CATAsyncRequest_ProcedureCall,
  CATAsyncRequest_HTTP,
  CATAsyncRequest_XMQL,
  CATAsyncRequest_PLMGeneric,
  CATAsyncRequest_WebService,
  CATAsyncRequest_Background,
  CATAsyncRequest_ODT
};

//===================================================================
//  Async Tasks Types
//===================================================================
enum CATAsyncTask_Type
{
  CATAsyncTask_Null = 0,  // No Existing Task 
  CATAsyncTask_Empty,     // Empty Task (only settings can be changed)
  CATAsyncTask_Logical,   // Logical Task (embedded physical tasks)
  CATAsyncTask_Physical,  // Physical Task (embedded async requests)
  CATAsyncTask_Completed  // Task can be either Logical or Physical but is completed (it can be just deleted)
};

//===================================================================
//  Async Tasks Status
//===================================================================
enum CATAsyncTaskStatus
{
  S_TASK_CANCEL_BY_USER = 1,       // Task is completed and was canceled by user
  S_TASK_OK = 0,                   // Task is completed and succeeded
  E_TASK_NOT_COMPLETED = -1,       // Task is not completed (running or waiting)
  E_TASK_CANCEL_BY_PLATFORM = -2,  // Task is completed and was canceled by the asynchrosnism platform (because of a platform error)
  E_TASK_FUNC_ERROR = -3,          // Task is completed and has failed during its execution
  E_TASK_SYST_ERROR = -4,          // Task is completed and has failed before its execution (because of a platform error)
  E_TASK_NOT_HANDLED = -5,         // Task is completed and has failed - request is not handle by the platform
  E_TASK_SERVER_DISCONNECTED = -6, // Task is completed and has failed - server is disconnected
  E_TASK_NOT_EXISTING = -7         // The task is not existing
};

class ExportedByCATAsyncTasksPlatform CATAsyncTaskStatusHelpers
{
public:
  static CATUnicodeString Type2String(CATAsyncRequest_Type iAsyncTaskType);
  static CATUnicodeString Convert(CATAsyncTaskStatus ieAsyncTaskStatus);
};

//===================================================================
//  Async Progression Data (APD) - ProgressionData Tabs Index
//===================================================================
// Logical Task Progression Data Indexes
#define APD_PHYSICAL_TASKS_COMPLETED      0
#define APD_PHYSICAL_TASKS_NOT_COMPLETED  1

class TaskStarterControler : public CATOmxSharable
{
  public :
  virtual CATBoolean IsTaskAuthorizedToBeStarted(CATAsyncRequest_Type iRequestType) = 0;
};

//===================================================================
//  Async Tasks Builders Data 
//===================================================================
//Adding Elements
enum AsyncBuilderDuplicateElements { AsyncBuilderDuplicateElements_KeepAll, AsyncBuilderDuplicateElements_MergeCurrent, AsyncBuilderDuplicateElements_MergeAll };
typedef void* AsyncBuilderElements;
// Builder Settings
struct ExportedByCATAsyncTasksPlatform AsyncTasksBuilderSettings
{
  AsyncTasksBuilderSettings();

  AsyncTasksBuilderSettings(AsyncBuilderDuplicateElements iDuplicateElementsStrategy, CATBoolean iTasksBuiltNotification, 
    CATBoolean iWaitAllBuiltTasksCompletion, CATBoolean iPropagateCancel, const CATUnicodeString& iBuilderName);
  bool operator==(AsyncTasksBuilderSettings iSettings);
  bool operator!=(AsyncTasksBuilderSettings iSettings) {return !operator==(iSettings);}

  AsyncBuilderDuplicateElements DuplicateElementsStrategy;
  CATBoolean TasksBuiltNotification;
  CATBoolean WaitAllBuiltTasksCompletion;
  CATBoolean PropagateCancel;
  CATUnicodeString builderName;

  static const AsyncTasksBuilderSettings Default;
};

//===================================================================
//  Asynchronous Communication Technology
//===================================================================
typedef unsigned int CATAsyncRequest_CommTech;
#define CATAsyncRequest_NoTech        0x00 // no technology used
#define CATAsyncRequest_BackBone      0x01 // BackBone for IPC
#define CATAsyncRequest_CommandAsync  0x02 // CommandAsync for ITC

enum CATAsyncAnswer_Type
{
  CATAsyncAnswer_TCL,
  CATAsyncAnswer_JSON,
  CATAsyncAnswer_Undefined
};

//===================================================================
//  Async Platforms Types
//===================================================================
typedef unsigned int CATAsyncRequestsPlatform_Types;
enum CATAsyncRequestsPlatform_Type
{
  CATAsyncRequestsPlatform_MultiProcesses  = 0x01,
  CATAsyncRequestsPlatform_FCSAsync        = 0x02,
  CATAsyncRequestsPlatform_HTTPAsync       = 0x04,
  CATAsyncRequestsPlatform_HTTPClientsPool = 0x08,
  CATAsyncRequestsPlatform_ThreadPool      = 0x10,
  CATAsyncRequestsPlatform_ODT             = 0x20,
  CATAsyncRequestsPlatform_None            = 0x00
};
#define CATAsyncRequestsPlatform_TypeMaskMIN CATAsyncRequestsPlatform_MultiProcesses
#define CATAsyncRequestsPlatform_TypeMaskMAX CATAsyncRequestsPlatform_ODT

typedef CATOmxVector<CATOmyCioUrlUsageCtx> CATOmyCioUrlUsageCtxVector;
typedef CATOmxList<CATOmyCioUrlUsageCtx>   CATOmyCioUrlUsageCtxList;

template <> CATOmxCollecManager & CATOmxDefaultCollecManager <CATAsyncTaskStatus>::manager();  

#endif
