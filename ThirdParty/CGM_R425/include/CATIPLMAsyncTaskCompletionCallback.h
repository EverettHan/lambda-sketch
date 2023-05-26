#ifndef CATIPLMAsyncTaskCompletionCallback_H
#define CATIPLMAsyncTaskCompletionCallback_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010

//===================================================================
//
// CATIPLMAsyncTaskCompletionCallback.h
// Define the CATIPLMAsyncTaskCompletionCallback interface
//
//===================================================================
//
// We reserve the right to add at any time additional member function to the itf, to add other import capacities.
// Hence implementations of the itf must always C++ derived from the associated adaptor CATPLMAsyncTaskCompletionCallbackAdapter
// never directly from the interface. 
//
//===================================================================

/**
 * @level Protected
 * @usage U4
 */
#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"

class CATIPLMAsyncTaskResult;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMAsyncTaskCompletionCallback;
#else
extern "C" const IID IID_CATIPLMAsyncTaskCompletionCallback ;
#endif

/**
 * Callback for completion used by an asynchronous task.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMAsyncTaskCompletionCallback: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Call invoked for completion when asynchronous task is finalysed with success or failure.
  * 
  * @param iAsyncResult
  *        This object allows to drive asynchronous task
  * @return
  *        S_OK   : if request succeeded.
  *        E_FAIL : if request failed.
  */
  virtual HRESULT AsyncCallback(CATIPLMAsyncTaskResult * iAsyncResult) = 0;
};
CATDeclareHandler( CATIPLMAsyncTaskCompletionCallback, CATBaseUnknown );
#endif
