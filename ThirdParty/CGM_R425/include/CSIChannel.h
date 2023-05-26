#ifndef CSIChannel_H
#define CSIChannel_H

#include "CSICommandBinderModule.h"
#include "EKStatus.h"
#include "CATSysErrorDef.h"
#include <memory>

class CATUnicodeString;

namespace EK
{
class CASSession;
class ChannelId;
class ChannelInfos;
class Credentials;
class Interruption;
}

namespace JSON
{
class JIStream;
}

namespace CSI
{
class ChannelImpl;
class Message;
class Parameters;

/**
 * Give access to the channel with the client node.
 * Allow to send messages and retrieve credentials information.
 */
class ExportedByCSIBinderModule Channel
{
public:
  Channel();
  explicit Channel(ChannelImpl& channelImpl);
  ~Channel();

  Channel(const Channel& rhs);
  Channel& operator=(const Channel& rhs);

  EK::ChannelId GetId() const;
  EK::ChannelInfos GetInfos() const;
  EK::Status GetStatus() const;

  /**
   * Discard all future messages from this sender and close the connection.
   * The optional reason message will be published into the monitoring.
   */
  HRESULT Reject();
  HRESULT Reject(const CATUnicodeString& reason);

  /**
   * Getting information returned by the 3DPassport CAS server.
   * return E_FAIL if the connection is not authenticated.
   */
  [[deprecated("EXECUTION FRAMEWORK - DEPRECATED - 2020/08/11 - Use CSI::Channel::GetInfos instead")]]
  HRESULT GetCredentials(EK::Credentials& credentials) const;

  /**
   * Get the interruption state for the channel.
   * Return true if the client node ask the channel to be interrupted.
   */
  bool IsInterrupted();

  /**
   * Return true if the client has registered a progress callback and expects some progress message.
   */
  bool HasProgressCallback() const;

  /**
   * The call related to this Interruption will be automatically interrupted
   * when the parent Interruption is interrupted.
   */
  EK::Interruption GetChainedInterrupt() const;

  /**
   * Send a success parameters to the client node.
   * Cannot be called after an AnswerError.
   * Cannot be called more than once for function implementation.
   * The parameters to send have to be compatible with the format defined in the declarative file.
   */
  HRESULT AnswerSuccess(const Parameters& parameters);

  /**
   * Send a success parameters to the client node.
   * Only available for function implementation.
   * Cannot be called after an AnswerError.
   * Cannot be called more than once for function implementation.
   * A Parameter will be constructed from the JSON description, the JSON description
   * must be compatible with the format defined in the declarative file.
   */
  HRESULT AnswerSuccess(const JSON::JIStream& jis);

  [[deprecated("CSI COMMAND BINDER - DEPRECATED - 2019/10/01 - Method Channel::Answer(const Parameters& parameters) is deprecated, please use Channel::AnswerSuccess(const Parameters& parameters) instead")]]
  HRESULT Answer(const Parameters& parameters);

  /**
   * Send a success message to the client node.
   * Cannot be called after a previous AnswerError.
   * Only available for command implementation.
   */
  [[deprecated("CSI COMMAND BINDER - DEPRECATED - 2019/06/12 - Method Channel::Answer(const Message& message) is deprecated, please use Channel::AnswerSuccess(message.ToParameter()) instead")]]
  HRESULT Answer(const Message& message);

  /**
   * Send an error parameters to the client node.
   * Cannot be called more than once.
   * Cannot be called after an AnswerSuccess for function implementation.
   * The parameters to send have to be compatible with the format defined in the declarative file.
   */
  HRESULT AnswerError(const Parameters& parameters);

  /**
   * Send an error parameters to the client node.
   * Only available for function implementation.
   * Cannot be called more than once.
   * Cannot be called after an AnswerSuccess for function implementation.
   * A Parameter will be constructed from the JSON description, the JSON description
   * must be compatible with the format defined in the declarative file.
   */
  HRESULT AnswerError(const JSON::JIStream& jis);

  /**
   * Send a CSIError parameters to the client node.
   * Cannot be called more than once.
   * Cannot be called after an AnswerSuccess for function implementation.
   * The parameters sent have the type CSIError.
   */
  HRESULT AnswerCSIError(int errorCode, const CATUnicodeString& error);

  /**
   * Send a progress parameters to the client node.
   * Only available for function implementation.
   * Cannot be called after a previous Answer or AnswerError.
   * The parameters send have to be compatible with the format defined in the declarative file.
   */
  HRESULT AnswerProgress(const Parameters& parameters);

  /**
   * Send a progress parameters to the client node.
   * Only available for function implementation.
   * Cannot be called after a previous Answer or AnswerError.
   * A Parameter will be constructed from the JSON description, the JSON description
   * must be compatible with the format defined in the declarative file.
   */
  HRESULT AnswerProgress(const JSON::JIStream& jis);

  /**
   * Emit some content to all clients that have subscribed to a specific event.
   * Only available for function implementation.
   * The event must be declared in the function definition and the parameters must respect the event definition
   */
  HRESULT Emit(const CATUnicodeString& event, const Parameters& content);

  /**
   * Emit some content to all clients that have subscribed to a specific event.
   * Only available for function implementation.
   * The event must be declared in the function definition and the parameters must respect the event definition
   */
  HRESULT Emit(const CATUnicodeString& event, const JSON::JIStream& content);

  /**
   * Emit some content to all clients that have subscribed to a specific event.
   * Only clients that have subscribed to that event/subject pair will be notified. Clients that have subscribed
   * to the event, but not to the subject will not be notified.
   * Only available for function implementation.
   * The event must be declared in the function definition and the parameters must respect the event definition
   */
  HRESULT Emit(const CATUnicodeString& event, const CATUnicodeString& subject, const Parameters& content);

  /**
   * Emit some content to all clients that have subscribed to a specific event.
   * Only clients that have subscribed to that event/subject pair will be notified. Clients that have subscribed
   * to the event, but not to the subject will not be notified.
   * Only available for function implementation.
   * The event must be declared in the function definition and the parameters must respect the event definition
   */
  HRESULT Emit(const CATUnicodeString& event, const CATUnicodeString& subject, const JSON::JIStream& content);

  /**
   * Create an authenticated session including a CASTGC cookie if a secret is available on the local Hypervisor.
   * If there is no secret on this installation, the returned pointer is null.
   * If the passport server fails or the secret is invalid/revoked, the pointer is not null but there is no CASTGC cookie in it.
   *   Since this last scenario can happens during the deployment (new VM meaning new secret broadcast and the old one is revoked),
   *   this method automatically retries after 2 seconds if the first attempt fails to create the authenticated session.
   *   You can also implement your own retry in recalling this API.
   */
  std::unique_ptr<EK::CASSession> RequestCASSessionBySecret() const;

  bool operator<(const Channel& rhs) const;
  bool operator==(const Channel& rhs) const;
  bool operator!=(const Channel& rhs) const;

private:
  ChannelImpl* impl_;
  friend ChannelImpl& getImpl(const Channel& channel);
};
} // namespace CSI

#endif
