#ifndef CSINode_H
#define CSINode_H

#include "CSICommandBinderModule.h"
#include "EKPolicy.h"
#include "CSIIterativeRequest.h"
#include "CSIMessage.h"
#include "CSIParameters.h"
#include "CSIRequest.h"
#include "CSISubscriptionId.h"
#include "CATSysErrorDef.h"

#include <functional>

#include "DSYExport.h"

class CATUnicodeString;

namespace JSON
{
class JIStream;
class JOStream;
}

namespace EK
{
class CallbackNode;
class ChannelInfos;
class Criterion;
class ExecuteOptions;
class Interruption;
class Node;
class NodeId;
}

namespace CSI
{
class Callbacks;
class Message;
class MessageBalancer;
class NodeImpl;
class Response;
class SentRequest;
class Types;

/** Node that will be used to send or receive messages.
Must be created on both Client and Serve sides.
May be derived by client for storing user data (add user data in constructor's parameters)
*/
class ExportedByCSIBinderModule Node
{
public:
  /** Client Side method : connect to server and select a node from the destination pool
  NodeId is a "connection tube" between this node and the least load node of destination pool (load balancing)
  \param destinationPool destination server's pool
  \param nodeId output NodeId
  \param infos user's connection informations which are transferred. After, this connection is locked for this user.
  \return S_OK if successful, E_FAIL otherwise
  */
  HRESULT Select(const CATUnicodeString& destinationPool, EK::NodeId& nodeId);
  HRESULT Select(const CATUnicodeString& destinationPool, EK::NodeId& nodeId, const EK::Criterion& criterion);
  HRESULT Select(const CATUnicodeString& destinationPool, EK::NodeId& nodeId, const EK::ChannelInfos& infos);
  HRESULT Select(const CATUnicodeString& destinationPool, EK::NodeId& nodeId, const EK::Criterion& criterion, const EK::ChannelInfos& infos);
  HRESULT SelectMyself(EK::NodeId& me);
  HRESULT SelectMyself(EK::NodeId& me, const EK::ChannelInfos& infos);

  template <class T>
  IterativeRequest CreateIterativeRequest(const EK::NodeId& destinationNodeId, const CATUnicodeString& command, int version, HRESULT (T::*method)(const Parameters&), T& instance, bool useDebugMode = false);

  IterativeRequest CreateIterativeRequest(const EK::NodeId& destinationNodeId, const CATUnicodeString& command, int version, const std::function<HRESULT(const Parameters&)>& callback = nullptr, bool useDebugMode = false);

  template <class T>
  Request CreateRequest(const EK::NodeId& destinationNodeId, const CATUnicodeString& command, int version, HRESULT (T::*method)(const Parameters&), T& instance, bool useDebugMode = false);

  Request CreateRequest(const EK::NodeId& destinationNodeId, const CATUnicodeString& command, int version, const std::function<HRESULT(const Parameters&)>& callback = nullptr, bool useDebugMode = false);

  HRESULT Call(const EK::NodeId& remoteNodeId, const CATUnicodeString& functionName, int functionVersion, const Parameters& arguments, const CSI::Callbacks& callbacks, bool debugMode = false);
  HRESULT Call(const EK::NodeId& remoteNodeId, const CATUnicodeString& functionName, int functionVersion, const JSON::JOStream& arguments, const CSI::Callbacks& callbacks, bool debugMode = false);

  HRESULT Call(const EK::NodeId& remoteNodeId, const CATUnicodeString& functionName, int functionVersion, const Parameters& arguments, const CSI::Callbacks& callbacks, EK::Interruption& interruption, bool debugMode = false);
  HRESULT Call(const EK::NodeId& remoteNodeId, const CATUnicodeString& functionName, int functionVersion, const JSON::JOStream& arguments, const CSI::Callbacks& callbacks, EK::Interruption& interruption, bool debugMode = false);

  HRESULT CallAndWait(const EK::NodeId& remoteNodeId, const CATUnicodeString& functionName, int functionVersion, const Parameters& arguments, const CSI::Callbacks& callbacks, bool debugMode = false);
  HRESULT CallAndWait(const EK::NodeId& remoteNodeId, const CATUnicodeString& functionName, int functionVersion, const JSON::JOStream& arguments, const CSI::Callbacks& callbacks, bool debugMode = false);

  /** create a Parameters */
  Parameters CreateParameters() const;
  /** create a Message */
  Message CreateMessage() const;

  /** create a MessageBalancer */
  template <typename T>
  HRESULT CreateMessageBalancer(const CATUnicodeString& destinationPool, MessageBalancer& balancer, bool (T::*OnError)(MessageBalancer&, const SentRequest&, const std::vector<Parameters>&), T& instance);

  HRESULT CreateMessageBalancer(const CATUnicodeString& destinationPool, MessageBalancer& balancer, const std::function<bool(MessageBalancer&, const SentRequest&, const std::vector<Parameters>&)>& onError = nullptr);

  HRESULT CreateMessageBalancerResendIfNoAnswer(const CATUnicodeString& destinationPool, MessageBalancer& balancer);

  template <class T>
  Parameters CreateParameters(const CATUnicodeString& type, const T& value) const;

  /** Stop Node
  */
  HRESULT Stop();

  /**
  * Return true if the node is stopped.
  */
  bool IsStopped() const;

  /**
  * Return true if Select() can be successful for this 'pool'
  */
  bool IsPoolSelectable(const CATUnicodeString& pool) const;

  /** Get EK::CallbackNode
  return a non null value only if this node has been created with Pool::CreateCallbackNode();
  */
  EK::CallbackNode* GetCallbackNode() const;

  /** Get EK::Node
  return a non null value only if this node has been created with Pool::CreateNode();
  */
  EK::Node* GetEKNode() const;

  /**
  Launch an arbitrary executable.
  */
  HRESULT Execute(const CATUnicodeString& executable, /*enum EK::ExecutePolicy*/int policy = EK::hideWindow);
  HRESULT ExecuteAndWait(const CATUnicodeString& executable, enum EK::ExecutePolicy policy = EK::hideWindow);
  HRESULT ExecuteAndWait(const CATUnicodeString& executable, const EK::ExecuteOptions& executeOptions);

  /** Subscribe to an event
  \param targetNodeId target
  \param eventName event name
  \param response list of callbacks per domain
  \return S_OK if successful, E_FAIL otherwise
  */
  [[deprecated("Use signature returning a SubscriptionId instead")]]
  HRESULT Subscribe(const EK::NodeId& targetNodeId, const CATUnicodeString& event, const Response& response);
  template <class T>
  [[deprecated("Use signature returning a SubscriptionId instead")]]
  HRESULT Subscribe(const EK::NodeId& targetNodeId, const CATUnicodeString& event, HRESULT (T::*method)(const Parameters&), T& instance);
  [[deprecated("Use signature returning a SubscriptionId instead")]]
  HRESULT Subscribe(const EK::NodeId& targetNodeId, const CATUnicodeString& event, const std::function<HRESULT(const Parameters&)>& callback);

  /** Subscribe to an event emitted by a specific node
  \param targetNodeId node that will emit the event
  \param event event name
  \param response list of callbacks per domain
  \param oSubId subscription ID
  \return S_OK if successful, E_FAIL otherwise
  */
  HRESULT Subscribe(const EK::NodeId& targetNodeId, const CATUnicodeString& event, const Response& response, SubscriptionId& oSubId);

  /** Subscribe to an event emitted by a specific node
  \param targetNodeId node that will emit the event
  \param event event name
  \param method callback to be called when an event is emitted (class method)
  \param instance object containing the callback method
  \param oSubId subscription ID
  \return S_OK if successful, E_FAIL otherwise
  */
  template <class T>
  HRESULT Subscribe(const EK::NodeId& targetNodeId, const CATUnicodeString& event, HRESULT (T::*method)(const Parameters&), T& instance, SubscriptionId& oSubId);

  /** Subscribe to an event emitted by a specific node, with a specific subject.
   * Only events that are emitted for this specific event/subject pair by the target node will be received.
   * If the target node emits the event without the corresponding subject, no callback will be called.
  \param targetNodeId node that will emit the event
  \param event event name
  \param subject subject for this event
  \param method callback to be called when an event is emitted (class method)
  \param instance object containing the callback method
  \param oSubId subscription ID
  \return S_OK if successful, E_FAIL otherwise
  */
  template <class T>
  HRESULT Subscribe(const EK::NodeId& targetNodeId, const CATUnicodeString& event, const CATUnicodeString& subject, HRESULT (T::*method)(const Parameters&), T& instance, SubscriptionId& oSubId);

  /** Subscribe to an event emitted by a specific node
  \param targetNodeId node that will emit the event
  \param event event name
  \param callback callback to be called when an event is emitted
  \param oSubId subscription ID
  \return S_OK if successful, E_FAIL otherwise
  */
  HRESULT Subscribe(const EK::NodeId& targetNodeId, const CATUnicodeString& event, const std::function<HRESULT(const Parameters&)>& callback, SubscriptionId& oSubId);

  /** Subscribe to an event emitted by a specific node, with a specific subject.
   * Only events that are emitted for this specific event/subject pair by the target node will be received.
   * If the target node emits the event without the corresponding subject, no callback will be called.
  \param targetNodeId node that will emit the event
  \param event event name
  \param subject subject for this event
  \param callback callback to be called when an event is emitted
  \param oSubId subscription ID
  \return S_OK if successful, E_FAIL otherwise
  */
  HRESULT Subscribe(const EK::NodeId& targetNodeId, const CATUnicodeString& event, const CATUnicodeString& subject, const std::function<HRESULT(const Parameters&)>& callback, SubscriptionId& oSubId);

  /** Unsubscribe from an event
  \param targetNodeId target
  \param eventName event name
  \return S_OK if successful, E_FAIL otherwise
  */
  [[deprecated("Use signature taking a SubscriptionId instead")]]
  HRESULT Unsubscribe(const EK::NodeId& targetNodeId, const CATUnicodeString& event);
  HRESULT Unsubscribe(SubscriptionId id);

  /** Emit a message to all clients that have subscribed to a specific event.
  \param event event name
  \param content data with parameters per domain
  \return S_OK if successful, S_FALSE if no clients have subscribed to the event, E_FAIL otherwise
  */
  HRESULT Emit(const CATUnicodeString& event, const Message& content) const;

  /** Emit some content to all clients that have subscribed to a specific event.
  \param event event name
  \param content parameters to be sent to the clients
  \return S_OK if successful, S_FALSE if no clients have subscribed to the event, E_FAIL otherwise
  */
  HRESULT Emit(const CATUnicodeString& event, const Parameters& content) const;

  /** Emit some content to all clients that have subscribed to a specific event.
  \param event event name
  \param content parameters in JSON format to be sent to the clients
  \return S_OK if successful, S_FALSE if no clients have subscribed to the event, E_FAIL otherwise
  */
  HRESULT Emit(const CATUnicodeString& event, const JSON::JIStream& content) const;

  /** Emit some content to all clients that have subscribed to a specific event.
   * Only clients that have subscribed to that event/subject pair will be notified. Clients that have subscribed
   * to the event, but not to the subject will not be notified.
  \param event event name
  \param subject emit the event to clients that have subscribed to this subject
  \param content parameters to be sent to the clients
  \return S_OK if successful, S_FALSE if no clients have subscribed to the event, E_FAIL otherwise
  */
  HRESULT Emit(const CATUnicodeString& event, const CATUnicodeString& subject, const Parameters& content) const;

  /** Emit some content to all clients that have subscribed to a specific event.
   * Only clients that have subscribed to that event/subject pair will be notified. Clients that have subscribed
   * to the event, but not to the subject will not be notified.
  \param event event name
  \param subject emit the event to clients that have subscribed to this subject
  \param content parameters in JSON format to be sent to the clients
  \return S_OK if successful, S_FALSE if no clients have subscribed to the event, E_FAIL otherwise
  */
  HRESULT Emit(const CATUnicodeString& event, const CATUnicodeString& subject, const JSON::JIStream& content) const;

  /** Emit some content to all clients that have subscribed to a specific event and
   * waits for all clients to answer before returning.
  \param event event name
  \param content parameters to be sent to the clients
  \return S_OK if successful, S_FALSE if no clients have subscribed to the event, E_FAIL otherwise
  */
  HRESULT EmitAndWait(const CATUnicodeString& event, const Parameters& content) const;

  /** Emit some content to all clients that have subscribed to a specific event and
   * waits for all clients to answer before returning.
  \param event event name
  \param content parameters in JSON format to be sent to the clients
  \return S_OK if successful, S_FALSE if no clients have subscribed to the event, E_FAIL otherwise
  */
  HRESULT EmitAndWait(const CATUnicodeString& event, const JSON::JIStream& content) const;

  /** Emit some content to all clients that have subscribed to a specific event and
   * waits for all clients to answer before returning.
   * Only clients that have subscribed to that event/subject pair will be notified. Clients that have subscribed
   * to the event, but not to the subject will not be notified.
  \param event event name
  \param subject emit the event to clients that have subscribed to this subject
  \param content parameters to be sent to the clients
  \return S_OK if successful, S_FALSE if no clients have subscribed to the event, E_FAIL otherwise
  */
  HRESULT EmitAndWait(const CATUnicodeString& event, const CATUnicodeString& subject, const Parameters& content) const;

  /** Emit some content to all clients that have subscribed to a specific event and
   * waits for all clients to answer before returning.
   * Only clients that have subscribed to that event/subject pair will be notified. Clients that have subscribed
   * to the event, but not to the subject will not be notified.
  \param event event name
  \param subject emit the event to clients that have subscribed to this subject
  \param content parameters in JSON format to be sent to the clients
  \return S_OK if successful, S_FALSE if no clients have subscribed to the event, E_FAIL otherwise
  */
  HRESULT EmitAndWait(const CATUnicodeString& event, const CATUnicodeString& subject, const JSON::JIStream& content) const;

  /** Get Default Response
  <=> set of client callbacks that will be called if a message is received for a domain
  */
  Response& GetDefaultResponse();

  template <class T>
  T* GetData();

  template <class T>
  T* GetPoolData(const CATUnicodeString& poolName) const;

public:
  explicit Node(NodeImpl& nodeImpl);
  ~Node() = default;

  Node(const Node&) = delete;
  Node& operator=(const Node&) = delete;

private:
  Types& GetTypes() const;
  void* GetData();
  void* GetPoolData(const CATUnicodeString &) const;

private:
  NodeImpl& impl_;

  friend NodeImpl& getImpl(const Node& node);
};
}

#include "CSINode.hxx"

#endif
