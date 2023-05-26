#ifndef CSIMessageBalancer_H
#define CSIMessageBalancer_H

#include "CSIRequest.h"
#include "CSIParameters.h"
#include "EKBind.h"
#include <functional>

namespace CSI
{
class MessageBalancerImpl;

class ExportedByCSIBinderModule MessageBalancer
{
public:
  /**
   * A message balancer is used to send messages to multiples nodes from the same pool,
   * and optionally wait until all answers are treated.
   * Use NodePool::CreateMessageBalancer to create it.
   */
   MessageBalancer();
  ~MessageBalancer();

  MessageBalancer(const MessageBalancer& rhs);
  MessageBalancer& operator=(const MessageBalancer& rhs);

  /**
   * Send a message to one Node of the pool.
   * The message is sent asynchronously (non-blocking method).
   */
  template <class T>
  Request CreateRequest(const CATUnicodeString& command, int version, HRESULT (T::*method)(const Parameters&), T& instance)
  {
    return CreateRequest(command, version, EK::bind(method, &instance));
  }

  /**
   * Wait until all target Nodes have reacted to all sent messages (after Node::OnBinary / OnText).
   * All answers are treated before the method stops waiting.
   *
   * Can't be used inside the Compute thread.
   * In this case, an error is returned.
   */
  HRESULT WaitAll();

private:
  Request CreateRequest(const CATUnicodeString& command, int version, const std::function<HRESULT(const Parameters&)>& callback);

private:
  MessageBalancerImpl* impl_;

public:
  explicit MessageBalancer(MessageBalancerImpl& impl);
};
}

#endif /*CSIMessageBalancer_H*/
