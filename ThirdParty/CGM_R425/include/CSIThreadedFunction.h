//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2017/09/18
//===================================================================

#ifndef CSIThreadedFunction_H
#define CSIThreadedFunction_H

#include "CSICommandBinderModule.h"

#include "CSIChannel.h"
#include "CSIFunctionInterface.h"
#include "CSIParameters.h"

#include "CATSysErrorDef.h"

#include <thread>

namespace CSI
{
template <class T>
class ThreadedFunction : public FunctionInterface
{
public:
  template <class... Args>
  ThreadedFunction(Args&&... args)
    : FunctionInterface()
    , function_(std::forward<Args>(args)...)
  {
    // NOTHING
  }

  ~ThreadedFunction()
  {
    if (thread_.joinable())
    {
      thread_.join();
    }
  }

  HRESULT OnCall(const Parameters& parameters, Channel& origin) override
  {
    thread_ = std::thread(&ThreadedFunction::Execute, this, parameters, origin);
    return S_OK;
  }

  void Execute(Parameters parameters, Channel origin)
  {
    function_.OnCall(parameters, origin);
  }

private:
  T function_;
  std::thread thread_;
};
}

#endif /*CSIThreadedFunction_H*/
