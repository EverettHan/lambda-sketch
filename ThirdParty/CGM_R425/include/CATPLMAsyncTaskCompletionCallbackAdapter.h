/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2009
#ifndef CATPLMAsyncTaskCompletionCallbackAdapter_H
#define CATPLMAsyncTaskCompletionCallbackAdapter_H

/**
 * @level Protected
 * @usage U2
 */
#include "CATPLMIntegrationInterfaces.h"
#include "CATIPLMAsyncTaskCompletionCallback.h"

class CATIPLMAsyncTaskResult;

class ExportedByCATPLMIntegrationInterfaces CATPLMAsyncTaskCompletionCallbackAdapter: public CATIPLMAsyncTaskCompletionCallback
{
public:

  /**
  * @see CATIPLMAsyncTaskCompletionCallback#AsyncCallback
  */
  HRESULT AsyncCallback(CATIPLMAsyncTaskResult * iAsyncResult);
};


#endif
