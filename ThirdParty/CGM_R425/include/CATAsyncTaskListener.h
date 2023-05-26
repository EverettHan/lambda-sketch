//===================================================================
// COPYRIGHT Dassault Systemes 2017/11/15
//===================================================================
// CATAsyncTaskListener.cpp
// Header definition of class CATAsyncTaskListener
//===================================================================
//
// Usage notes:
// Task listener interface.
//
//===================================================================
//  2017/11/15 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATAsyncTaskListener_H
#define CATAsyncTaskListener_H

#include "CATAsyncTasksPlatform_NG.h"
#include "CATOmxSharable.h"
#include "CATAsyncTaskContext_NG.h"
#include "CATOmxCollecManager.h"

//-----------------------------------------------------------------------
// Modules Restriction
//-----------------------------------------------------------------------
#define AuthorizedModule 999
// Check No Hack
#if _MK_MODNAME_ == AuthorizedModule
#error Forbidden Access To CATAsyncTaskListener from a non-authorized module
@error
#endif

// List of authorized infrastructure modules
#define CATAsyncTasksPlatform_NG                  AuthorizedModule
#define CATPLMxMQL                                AuthorizedModule
#define CATPLMAsync                               AuthorizedModule
#define CATPLMImplAdapterAsync                    AuthorizedModule
#define CATPLMxReadWriteXMQL                      AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden Access To CATAsyncTaskListener from a non-authorized module
@error
#endif

#undef CATAsyncTasksPlatform_NG
#undef CATPLMxMQL
#undef CATPLMAsync
#undef CATPLMImplAdapterAsync
#undef CATPLMxReadWriteXMQL
//-----------------------------------------------------------------------

class ExportedByCATAsyncTasksPlatform CATAsyncTaskListener : public CATOmxSharable
{
public:
  CATAsyncTaskListener();
  virtual ~CATAsyncTaskListener();

  virtual HRESULT HandleTaskScheduled(CATAsyncTaskContextBase& iContext) = 0;
  virtual HRESULT HandleTaskRunning(CATAsyncTaskContextBase& iContext) = 0;
  virtual HRESULT HandleTaskProgressing(CATAsyncTaskContextBase& iContext) = 0;
  virtual HRESULT HandleTaskProgressed(CATAsyncTaskContextBase& iContext) = 0;
  virtual HRESULT HandleTaskCompleting(CATAsyncTaskContextBase& iContext) = 0;
  virtual HRESULT HandleTaskCompleted(CATAsyncTaskContextBase& iContext) = 0;
};

template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATAsyncTaskListener*>::manager();

#endif
