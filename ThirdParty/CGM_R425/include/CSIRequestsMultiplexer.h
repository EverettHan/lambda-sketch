#ifndef CSIRequestsMultiplexer_H
#define CSIRequestsMultiplexer_H

#include "CSICommandBinderModule.h"
#include "CSIRequest.h"
#include "CSIIterativeRequest.h"
#include "EKStringComparator.h"
#include "DSUnicodeString.h"
#include <atomic>
#include <map>

namespace EK
{
class NodeId;
}

namespace CSI
{
class Node;
class Parameters;
class RequestAnswers;

class ExportedByCSIBinderModule RequestsMultiplexer
{
public:
  explicit RequestsMultiplexer(Node& node);
  virtual ~RequestsMultiplexer();

  RequestsMultiplexer(const RequestsMultiplexer& rhs) = delete;
  RequestsMultiplexer& operator=(const RequestsMultiplexer&) = delete;

  virtual HRESULT OnUpdate(const CATUnicodeString& requestName, const Parameters& parameters) = 0;
  virtual HRESULT OnError(const CATUnicodeString& requestName, const Parameters& parameters, bool stopOnError = false);
  virtual HRESULT OnTerminate(const CATUnicodeString& requestName, int nbPendingRequests);

  Request CreateRequest(const CATUnicodeString& requestName, const EK::NodeId& nodeId, const CATUnicodeString& command, int version, CATUnicodeString& errorMsg, bool stopOnError = false);
  IterativeRequest CreateIterativeRequest(const CATUnicodeString& requestName, const EK::NodeId& nodeId, const CATUnicodeString& command, int version, CATUnicodeString& errorMsg);

  HRESULT OnTerminateRequest(const CATUnicodeString& requestName);

private:
  RequestAnswers* AddRequestAnswers(const CATUnicodeString& name, CATUnicodeString& errorMsg, const bool stopOnError);

  Node& node_;
  std::atomic<int> nbRequests_;
  std::map<CATUnicodeString, RequestAnswers*, EK::StringComparator> requestAnswers_;
};
}

#endif /*CSIRequestsMultiplexer_H*/
