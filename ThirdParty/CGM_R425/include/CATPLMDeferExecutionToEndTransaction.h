#ifndef CATPLMDeferExecutionToEndTransaction_H
#define CATPLMDeferExecutionToEndTransaction_H

#include "CATPLMIdentificationAccess.h"
#include "CATBaseUnknown.h"
#include "CATOmxKernel.h"


class CATPLMDeferredExecutionFunctor: public CATBaseUnknown
{
public:
  virtual void Execute(CATOmxIter<IUnknown>& iData) = 0;
};

/**
 * register an operation to be executed at the end of an "engine" transaction.
 * supported engines are "open" and "switch" (for now)
 * if no engine is currently executing, return code is false and the callback is not registered and will not be called
 * else, return code is true and the callback will be executed once the engine transaction has ended.
 */
ExportedByCATPLMIdentificationAccess bool CATPLMDeferExecutionToEndTransaction(CATPLMDeferredExecutionFunctor& iFunctor,IUnknown& iData);

#endif
