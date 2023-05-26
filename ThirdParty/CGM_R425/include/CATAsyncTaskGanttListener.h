#ifndef CATAsyncTaskGanttListener_H
#define CATAsyncTaskGanttListener_H

#include "CATAsyncTasksPlatform_NG.h"
#include "CATAsyncTaskListener.h"
#include "CATOmxCxxPortability.h"

class ExportedByCATAsyncTasksPlatform CATAsyncTaskGanttListener : public CATAsyncTaskListener
{
public:
  CATAsyncTaskGanttListener();
  virtual ~CATAsyncTaskGanttListener();

  virtual HRESULT HandleTaskScheduled(CATAsyncTaskContextBase& iContext) OMX_Cxx11_OVERRIDE;
  virtual HRESULT HandleTaskRunning(CATAsyncTaskContextBase& iContext) OMX_Cxx11_OVERRIDE;
  virtual HRESULT HandleTaskProgressing(CATAsyncTaskContextBase& iContext) OMX_Cxx11_OVERRIDE;
  virtual HRESULT HandleTaskProgressed(CATAsyncTaskContextBase& iContext) OMX_Cxx11_OVERRIDE;
  virtual HRESULT HandleTaskCompleting(CATAsyncTaskContextBase& iContext) OMX_Cxx11_OVERRIDE;
  virtual HRESULT HandleTaskCompleted(CATAsyncTaskContextBase& iContext) OMX_Cxx11_OVERRIDE;

private:
  /**
   * Define the display preferences for the Gantt Diagram
   * 
   * @param ioConfigJson Config JSON object which will be updated with new settings
   */
  virtual void _AddJsonConfigPreferences(CATOmxJsonObject& ioConfigJson) = 0;

protected:
  CATBoolean _allowRootTaskOnly;
};

#endif
