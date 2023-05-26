#ifndef CATAsyncTasksUtils_H
#define CATAsyncTasksUtils_H

#include "CATAsyncBasicTypes.h"
#include "CATAsyncTaskID_NG.h"

#include "CATOmyAsyncProcessMonitor.h"

//===================================================================
//  Async Tasks Traces
//===================================================================
#define KOALA_TRACE(TRACE) ASYNC_TRACE(AsyncTraceLevel_Debug_Dev, AsyncString("KOALA: ") + TRACE)
#define KOALA_TRACE_WARNING(TRACE) ASYNC_TRACE_WARNING(AsyncTraceLevel_Debug_Dev, AsyncString("KOALA: ") + TRACE)
#define KOALA_TRACE_ERROR(TRACE) ASYNC_TRACE_ERROR(AsyncTraceLevel_Debug_Dev, AsyncString("KOALA: ") + TRACE)

const char* AsyncRequestTypeToStr(CATAsyncRequest_Type type);

//===================================================================
//  Async Task In Context Struct
//===================================================================
class ExportedByCATAsyncTasksPlatform CATAsyncTaskInContext
{
public:
  CATAsyncTaskInContext(const CATAsyncTaskID& iAsyncTaskID);
  ~CATAsyncTaskInContext();
  void UnsetTaskId() 
    {return _UnsetTaskId(); }
    
private:
  void _UnsetTaskId();
  CATBoolean     _bUnset;
  CATAsyncTaskID _asyncTaskID;
};

#endif
