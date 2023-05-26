//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2015/05/01
//===================================================================

#ifndef CSINode_HXX
#define CSINode_HXX

#include "CSITypes.h"

#include "EKBind.h"

namespace CSI
{
template <typename T>
HRESULT Node::CreateMessageBalancer(const CATUnicodeString& destinationPool, MessageBalancer& balancer, bool (T::*OnError)(MessageBalancer&, const SentRequest&, const std::vector<Parameters>&), T& instance)
{
  return CreateMessageBalancer(destinationPool, balancer, EK::bind(OnError, &instance));
}

template <class T>
IterativeRequest Node::CreateIterativeRequest(const EK::NodeId& destinationNodeId, const CATUnicodeString& command, int version, HRESULT (T::*method)(const Parameters&), T& instance, bool useDebugMode)
{
  return CreateIterativeRequest(destinationNodeId, command, version, EK::bind(method, &instance), useDebugMode);
}

template <class T>
Request Node::CreateRequest(const EK::NodeId& destinationNodeId, const CATUnicodeString& command, int version, HRESULT (T::*method)(const Parameters&), T& instance, bool useDebugMode)
{
  return CreateRequest(destinationNodeId, command, version, EK::bind(method, &instance), useDebugMode);
}

template <class T>
HRESULT Node::Subscribe(const EK::NodeId& targetNodeId, const CATUnicodeString& event, HRESULT (T::*method)(const Parameters&), T& instance)
{
  SubscriptionId id;
  return Subscribe(targetNodeId, event, EK::bind(method, &instance), id);
}

template <class T>
HRESULT Node::Subscribe(const EK::NodeId& targetNodeId, const CATUnicodeString& event, HRESULT (T::*method)(const Parameters&), T& instance, SubscriptionId& oSubId)
{
  return Subscribe(targetNodeId, event, EK::bind(method, &instance), oSubId);
}

template <class T>
HRESULT Node::Subscribe(const EK::NodeId& targetNodeId, const CATUnicodeString& event, const CATUnicodeString& subject, HRESULT (T::*method)(const Parameters&), T& instance, SubscriptionId& oSubId)
{
  return Subscribe(targetNodeId, event + "/" + subject, EK::bind(method, &instance), oSubId);
}

template <class T>
Parameters Node::CreateParameters(const CATUnicodeString& type, const T& value) const
{
  return GetTypes().CreateParameters(type, value);
}

template <class T>
T* Node::GetPoolData(const CATUnicodeString& poolName) const
{
  return static_cast<T*>(GetPoolData(poolName));
}

template <class T>
T* Node::GetData()
{
  return static_cast<T*>(GetData());
}
}

#endif /*CSINode_HXX*/
