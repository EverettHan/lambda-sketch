//===================================================================
// COPYRIGHT Dassault Systemes 2015/09/02
//===================================================================
// CATAsyncBackgroundRequest.cpp
// Header definition of class CATAsyncBackgroundRequest
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2015/09/02 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATAsyncBackgroundRequest_H
#define CATAsyncBackgroundRequest_H

#include "CATOMYBackground.h"
#include "CATAsyncRequest.h"
#include "CATOmxSharable.h"
#include "CATIAsyncTaskCompletionCallBackBase.h"

//-----------------------------------------------------------------------

// End Value
enum CATAsyncBGTask_EndValue
{
  CATAsyncBGTask_OK,
  CATAsyncBGTask_CANCELED,
  CATAsyncBGTask_FAILED
};

// BG IUnknown Methods
typedef CATAsyncBGTask_EndValue(IUnknown::*CATAsyncBGTask_RunFct)();
typedef void(IUnknown::*CATAsyncBGTask_StopFct)();

// BG Static Methods
typedef CATAsyncBGTask_EndValue(*CATAsyncBGTask_Static_RunFct)();
typedef void(*CATAsyncBGTask_Static_StopFct)();

// BG CATIAsyncBGTask Impl
struct ExportedByCATOMYBackground CATIAsyncBGTask : public CATOmxSharable
{
  struct Progression { virtual void EmitEvent() = 0; };
  virtual CATAsyncBGTask_EndValue operator()(Progression& iProgression) = 0;
  virtual void Stop() { }
};

class ExportedByCATOMYBackground CATAsyncBackgroundRequest: public CATAsyncRequest
{
public:

  enum kind { IUnknown_Meth, Static_Func, Itf_Impl };

  struct ExportedByCATOMYBackground Params : public CATAsyncRequest::Params
  {
    Params():Run(NULL),Cancel(NULL),StaticRun(NULL),StaticCancel(NULL){}
    virtual ~Params(){Run=NULL;Cancel=NULL;StaticRun=NULL;StaticCancel=NULL;}
    // IUnknown Methods
    CATOmxSR<IUnknown> Object;
    CATAsyncBGTask_RunFct Run;
    CATAsyncBGTask_StopFct Cancel;
    // Static Function
    CATAsyncBGTask_Static_RunFct StaticRun;
    CATAsyncBGTask_Static_StopFct StaticCancel;
    // Interface Impl
    CATOmxSR<CATIAsyncBGTask> Task;
  };

  // Standard constructors and destructors
  // -------------------------------------
  CATAsyncBackgroundRequest(const Params& iParams);

  virtual ~CATAsyncBackgroundRequest();

  /**
  * CATAsyncRequest Implementation
  */
  virtual const char * GetRequestName() { return "Background"; }

  virtual CATAsyncRequestsPlatform_Type GetWorkablePlatform() { return CATAsyncRequestsPlatform_ThreadPool; }

  virtual CATIAsyncRequestsPlatformStrategy * CreatePlatformInstance(CATAsyncRequestsPlatform_Type platformType);

   /**
  * Return TRUE if request can be run synchronously, FALSE otherwise
  *
  * @return [CATBoolean]
  */
  virtual CATBoolean HandleSyncRun() { return TRUE; }

  /**
  * Run the request synchronously
  *
  * @return [Status], the end status request
  */
  virtual void RunSync(CATIAsyncTaskCompletionCallBackBase * ipAsyncTaskCompletionCallBack);

  kind Kind() { return _kind; }

  CATBoolean HasCancel()
  { 
    return  Itf_Impl == _kind                                  ||
           (IUnknown_Meth == _kind && NULL != _params.Cancel)      ||
           (Static_Func == _kind   && NULL != _params.StaticCancel);
  }
            

  // IUnknown Methods
  IUnknown& GetObjectAsRef() { return *_params.Object; }

  CATAsyncBGTask_RunFct GetRunFct() { return _params.Run; }

  CATAsyncBGTask_StopFct GetCancelFct() { return _params.Cancel; }

  // Static Function
  CATAsyncBGTask_Static_RunFct GetStaticRunFct() { return _params.StaticRun; }

  CATAsyncBGTask_Static_StopFct GetStaticCancelFct() { return _params.StaticCancel; }

  // Interface Impl
  CATIAsyncBGTask& GetTaskAsRef() { return *_params.Task; }
  
private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATAsyncBackgroundRequest (CATAsyncBackgroundRequest &);
  CATAsyncBackgroundRequest& operator=(CATAsyncBackgroundRequest&);

  // Params
  Params _params;

  kind _kind;
};

//-----------------------------------------------------------------------

#endif