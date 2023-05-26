#ifndef CSIIterativeRequest_H
#define CSIIterativeRequest_H

#include "CSICommandBinderModule.h"

#include "CATSysErrorDef.h"

#include <functional>

namespace CSI
{
class Parameters;
class CommandRequestImpl;

/**
IterativeRequest object for C++ client side.
It is used to call a server side's command's callbacks (OnBegin(), OnCommand(), OnEnd())
through disjoint messages per callback

the IterativeRequest object stores a callback pointer which will be called on the server's answer.

when the IterativeRequest is created, on the server side, the constructor of Command class is called
When the IterativeRequest is destroyed, on the server side, the corresponding Command class instance is deleted.
*/
class ExportedByCSIBinderModule IterativeRequest
{
public:
           IterativeRequest();
  explicit IterativeRequest(CommandRequestImpl& impl);
          ~IterativeRequest();

  IterativeRequest(const IterativeRequest& rhs);
  IterativeRequest& operator=(const IterativeRequest& rhs);

  /** Asynchronous Begin Command with Parameters to target server
  \param parameters parameters to send to server
  \return S_OK if successful, E_FAIL otherwise
  */
  HRESULT Begin(const Parameters& parameters);

  /** Asynchronous send Command with Parameters to target server
  \param parameters parameters to send to server
  \return S_OK if successful, E_FAIL otherwise
  */
  HRESULT Send(const Parameters& parameters);

  /** Asynchronous End Command with Parameters to target server
  \param parameters parameters to send to server
  \return S_OK if successful, E_FAIL otherwise
  */
  HRESULT End(const Parameters& parameters);

  /** Synchronous Begin Command with Parameters to target server
  \param parameters parameters to send to server
  \return S_OK if successful, E_FAIL otherwise
  */
  HRESULT BeginAndWait(const Parameters& parameters);

  /** Synchronous send Command with Parameters to target server
  \param parameters parameters to send to server
  \return S_OK if successful, E_FAIL otherwise
  */
  HRESULT SendAndWait(const Parameters& parameters);

  /** Synchronous End Command with Parameters to target server
  \param parameters parameters to send to server
  \return S_OK if successful, E_FAIL otherwise
  */
  HRESULT EndAndWait(const Parameters& parameters);

  /** Interrupt the request
  \return S_OK if successful, E_FAIL otherwise
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

  /* when replay mode is set, translate parameters will be untranslated */
  void SetReplayMode();

private:
  CommandRequestImpl* impl_;
};
}

#endif
