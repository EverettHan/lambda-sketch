/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2009
#ifndef CATIPLMAsyncTask_H
#define CATIPLMAsyncTask_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"

class CATIPLMAsyncTaskCompletionCallback;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMAsyncTask;
#else
extern "C" const IID IID_CATIPLMAsyncTask ;
#endif

/**
 * Handle on an asynchronous task.
 * The running status is volontary not accessible to avoid CPU loop if caller is using while operator.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMAsyncTask: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Start an asynchronous task.
  * 
  * @param iCompletionCallback
  *        This callback is mandatory and will be invoked when asynchronous part is finalysed or aborted.
  * @return
  *        S_OK           : if request succeeded.
  *        E_ACCESSDENIED : if task is exclusive and if an other task is still running.
  *        E_FAIL         : if request failed.
  */
  virtual HRESULT RequestStart(CATIPLMAsyncTaskCompletionCallback * iCompletionCallback) = 0;

  /**
  * Abort an asynchronous task.
  *
  *        S_OK           : if request succeeded.
  *        E_FAIL         : if request failed.
  */
  virtual HRESULT RequestAbort() = 0;
};
CATDeclareHandler( CATIPLMAsyncTask, CATBaseUnknown );
#endif
