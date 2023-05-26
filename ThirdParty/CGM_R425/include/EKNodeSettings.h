//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2015/04/16
//===================================================================

#ifndef EKNodeSettings_H
#define EKNodeSettings_H

#include "EKAuthenticationHelpers.h"
#include "EKExportedByKernel.h"
#include <string>

class CATUnicodeString;

namespace EK
{
class ExportedByKernel NodeSettings
{
public:
  NodeSettings();

public:
  /**
   * Set the identifier of this Node.
   */
  NodeSettings& SetIdentifier(const CATUnicodeString& identifier);
  NodeSettings& SetIdentifier(const char* identifier);

  /**
   * Set the address used for websocket connections to this Node.
   * It is the full address i.e. ws://ip:port
   */
  NodeSettings& SetPublicAddress(const CATUnicodeString& publicAddress);
  NodeSettings& SetPublicAddress(const char* publicAddress);

  /**
   * Set the hostname used for websocket connections to this Node.
   */
  NodeSettings& SetHostname(const CATUnicodeString& hostname);
  NodeSettings& SetHostname(const char* hostname);

  /**
   * Set the private ip used for socket connections to this Node.
   */
  NodeSettings& SetPrivateIp(const CATUnicodeString& privateIp);
  NodeSettings& SetPrivateIp(const char* privateIp);

  /**
   * Set the websocket port used by this Node.
   */
  NodeSettings& SetWebSocketPort(int port);

  /**
   * Set this setting if the node is launched inside a Docker container.
   */
  NodeSettings& SetContainerized();

  /*
   * Set the authorization header used for websocket connection used by this Node.
   */
  NodeSettings& SetAuthorizationHeader(const CATUnicodeString& header);
  NodeSettings& SetAuthorizationHeader(const char* header);

  /*
   * Add HTTP header used for websocket connection used by this Node.
   */
  NodeSettings& AddWebsocketHeader(const CATUnicodeString& key, const CATUnicodeString& value);
  NodeSettings& AddWebsocketHeader(const char* key, const char* value);

  /*
   * Set the proxy url used for websocket connection used by this Node.
   */
  NodeSettings& SetProxyUrl(const CATUnicodeString& proxy);
  NodeSettings& SetProxyUrl(const char* proxy);

  /**
   * Set the callback called when the connection to the proxy requires an authentication.
   */
  NodeSettings& SetProxyAuthenticationCallback(const ProxyAuthenticationCallback& callback);

  /**
   * Specify if this node can disconnect from its Hypervisor.
   * This works only for nodes connected to their Hypervisors via websocket.
   */
  NodeSettings& SetCanDisconnectFromHypervisor(bool canDisconnectFromHypervisor);

  /**
   * This node will connect to other Nodes with Socket instead of WebSocket.
   */
  NodeSettings& SetDirectConnection();

  /*
   * Set the Kubernetes ID used by this Node.
   */
  NodeSettings& SetPodId(const CATUnicodeString& podId);
  NodeSettings& SetPodId(const char* podId);

private:
  std::string identifier_;
  std::string publicAddress_;
  std::string hostname_;
  std::string privateIp_;
  std::string headers_;
  std::string proxy_;
  ProxyAuthenticationCallback callback_;
  std::string podId_;
  int webSocketPort_;
  bool containerized_;
  bool directConnection_;
  bool canDisconnect_;

private:
  friend class NodeImpl;
};
}

#endif /*EKNodeSettings_H*/
