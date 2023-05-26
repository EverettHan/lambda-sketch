/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2009
#ifndef CATIPLMAsyncTaskResult_H
#define CATIPLMAsyncTaskResult_H

#include "CATPLMAsyncTaskStatus.h"

/**
 * @level Protected
 * @usage U3
 */
#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMAsyncTaskResult;
#else
extern "C" const IID IID_CATIPLMAsyncTaskResult ;
#endif

/**
 * Is representing the result of an asynchronous task.
 * This interface is accessible only on completion callback.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMAsyncTaskResult: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * The asynchronous task status.
  *
  * @param oStatus
  *        The status
  * @return
  *        S_OK   : if request succeeded.
  *        E_FAIL : if request failed.
  */
  virtual HRESULT GetStatus(CATPLMAsyncTaskStatus & oStatus) = 0;

  /**
  * Commit integrates the modifications in PLM session.
  *
  * @return 
  *        S_OK           : if request succeeded.
  *        E_ACCESSDENIED : if operation is no more possible.
  *        E_FAIL         : if request failed.
  */
  virtual HRESULT Commit() = 0;

  /**
  * Abort stops the asynchronous operation.
  *
  * @return 
  *        S_OK   : if request succeeded.
  *        E_FAIL : if request failed.
  */
  virtual HRESULT Abort() = 0;
};
CATDeclareHandler( CATIPLMAsyncTaskResult, CATBaseUnknown );
#endif
