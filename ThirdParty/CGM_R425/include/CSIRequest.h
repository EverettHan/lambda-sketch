#ifndef CSIRequest_H
#define CSIRequest_H

#include "CSICommandBinderModule.h"

#include "CATSysErrorDef.h"

#include <functional>

namespace CSI
{
class Parameters;
class CommandRequestImpl;

/**
 * Request object for C++ client side.
 * It is used to call a server side's command's callbacks (OnBegin(), OnCommand(), OnEnd())
 * through one unique message for all callback, thus it should be more optimized for bandwith in most case,
 * than when using IterativeRequest
 *
 * the Request object stores a callback pointer which will be called on the server's answer.
 *
 * when the Request is created, on the server side, the constructor of Command class is called
 * When the Request is destroyed, on the server side, the corresponding Command class instance is deleted.
 */
class ExportedByCSIBinderModule Request
{
public:
           Request();
  explicit Request(CommandRequestImpl& impl);
          ~Request();

  Request(const Request&);
  Request& operator=(const Request&);

  /** Asynchronous call to server OnCommand()
   * \param parameters parameters to send to server
   * \return S_OK if successful, E_FAIL otherwise
   */
  HRESULT Send(const Parameters& beginParams, const Parameters& sendParams, const Parameters& endParams);

  /** Synchronous call to server OnCommand()
   * \param parameters parameters to send to server
   * \return S_OK if successful, E_FAIL otherwise
   */
  HRESULT SendAndWait(const Parameters& beginParams, const Parameters& sendParams, const Parameters& endParams);

  /** Asynchronous call to server OnCommand() that will be sent on disconnection
   * \param parameters parameters to send to server
   * \return S_OK if successful, E_FAIL otherwise
   */
  HRESULT SendOnDisconnection(const Parameters& beginParams, const Parameters& sendParams, const Parameters& endParams);

  /** Interrupt the request
   * \return S_OK if successful, E_FAIL otherwise
   */
  HRESULT Interrupt();

  /**
   * Set the callback which will be called when the command answer an error
   * \param errorCallback: the function to call when the error message is received
   * \return S_OK if successful, E_FAIL otherwise
   */
  HRESULT OnErrorCallback(const std::function<HRESULT(const Parameters&)>& errorCallback);

  /**
   * Set the callback which will be called when the command instance is deleted.
   * No more answer will be received after that.
   * \param terminateCallback: the function to call when the instance is deleted
   * \return S_OK if successful, E_FAIL otherwise
   */
  HRESULT OnTerminateCallback(const std::function<HRESULT()>& terminateCallback);

private:
  CommandRequestImpl* impl_;
};
}

#endif
