//===================================================================
// COPYRIGHT Dassault Systemes 2020-08-04
//===================================================================
// 2020-08-04 Creation: D6K
//===================================================================

#ifndef CATDlgWebNotifications_H
#define CATDlgWebNotifications_H

// CATWebViewDialog
#include "CATWebViewDialog.h"
#include "CATDlgWebTypes.h"
// System
#include "CATNotification.h"
// SystemTS
#include "DSYString.h"
// UIVCoreTools
#include "CATSYPArray.h"
// std
#include <functional>

class ExportedByCATWebViewDialog CATDlgWebConsoleMessage: public CATNotification
{
  CATDeclareClass;

public:
  explicit CATDlgWebConsoleMessage(const CATUnicodeString& i_message,
    const CATUnicodeString& i_sourceURL,
    const int i_sourceLine)
    : message(i_message)
    , sourceURL(i_sourceURL)
    , sourceLine(i_sourceLine)
  {
  }

  ~CATDlgWebConsoleMessage() {}

  CATDlgWebConsoleMessage() = delete;
  CATDlgWebConsoleMessage(const CATDlgWebConsoleMessage&) = delete;

  CATDlgWebConsoleMessage& operator=(const CATDlgWebConsoleMessage&) = delete;

  const int sourceLine;
  const CATUnicodeString message;
  const CATUnicodeString sourceURL;
};

class ExportedByCATWebViewDialog CATDlgWebDownloadProgress: public CATNotification
{
  CATDeclareClass;

public:
  CATDlgWebDownloadProgress(const int i_id,
    const int i_receivedBytes,
    const int i_speed,
    const int i_totalBytes,
    const bool i_complete)
    : details{i_id, i_receivedBytes, i_speed, i_totalBytes, i_complete}
  {
  }

  ~CATDlgWebDownloadProgress() {}

  CATDlgWebDownloadProgress() = delete;
  CATDlgWebDownloadProgress(const CATDlgWebDownloadProgress&) = delete;

  CATDlgWebDownloadProgress& operator=(const CATDlgWebDownloadProgress&) = delete;

  struct Details
  {
    // Unique identifier for this download
    int id;
    // Number of received bytes
    int receivedBytes;
    // Simple speed estimate in bytes/s
    int speed;
    // Total number of bytes
    int totalBytes;
    // Download status
    bool complete;
  };

  const Details details;
};

class ExportedByCATWebViewDialog CATDlgWebHTTPError: public CATNotification
{
  CATDeclareClass;

public:
  CATDlgWebHTTPError(const int i_status,
    const CATUnicodeString& i_text,
    const CATUnicodeString& i_method,
    const CATUnicodeString& i_url)
    : eventType(webview::EventType::HTTP_ERROR)
    , status(i_status)
    , statusText(i_text)
    , method(i_method)
    , requestURL(i_url)
  {
  }

  ~CATDlgWebHTTPError() {}

  CATDlgWebHTTPError() = delete;
  CATDlgWebHTTPError(const CATDlgWebHTTPError&) = delete;

  CATDlgWebHTTPError& operator=(const CATDlgWebHTTPError&) = delete;

  const int status;
  const CATUnicodeString statusText;
  const CATUnicodeString method;
  const CATUnicodeString requestURL;
  const webview::EventType eventType;
};

class ExportedByCATWebViewDialog CATDlgWebJSMessage: public CATNotification
{
  CATDeclareClass;

public:
  CATDlgWebJSMessage(const CATSYPConstArray<CATUnicodeString>& i_messages,
    const CATUnicodeString& i_url,
    const int i_line,
    const int i_column)
    : messages(i_messages)
    , origin{i_url, i_line, i_column}
  {
  }

  ~CATDlgWebJSMessage() {}

  CATDlgWebJSMessage() = delete;
  CATDlgWebJSMessage(const CATDlgWebJSMessage&) = delete;

  CATDlgWebJSMessage& operator=(const CATDlgWebJSMessage&) = delete;

  struct Origin
  {
    // URL of the script from where the messages were sent.
    CATUnicodeString url;
    // Line of the script that sent the messages.
    int line = 0;
    // Column of the script that sent the messages.
    int column = 0;
  };

  // Message list.
  const CATSYPConstArray<CATUnicodeString> messages;
  // Details on the script that sent the messages.
  const Origin origin;
};

class ExportedByCATWebViewDialog CATDlgWebLoadEnd: public CATNotification
{
  CATDeclareClass;

public:
  explicit CATDlgWebLoadEnd(const CATUnicodeString& i_url)
    : eventType(webview::EventType::LIFECYCLE)
    , url(i_url)
  {
  }

  ~CATDlgWebLoadEnd() {}

  CATDlgWebLoadEnd() = delete;
  CATDlgWebLoadEnd(const CATDlgWebLoadEnd&) = delete;

  CATDlgWebLoadEnd& operator=(const CATDlgWebLoadEnd&) = delete;

  // URL of the page.
  const CATUnicodeString url;
  const webview::EventType eventType;
};

class ExportedByCATWebViewDialog CATDlgWebLoadError: public CATNotification
{
  CATDeclareClass;

public:
  explicit CATDlgWebLoadError(const int i_errorCode,
    const CATUnicodeString& i_errorCodeName,
    const CATUnicodeString& i_failingURL)
    : eventType(webview::EventType::LOAD_ERROR)
    , errorCode(i_errorCode)
    , errorCodeName(i_errorCodeName)
    , failingURL(i_failingURL)
  {
  }

  ~CATDlgWebLoadError() {}

  CATDlgWebLoadError() = delete;
  CATDlgWebLoadError(const CATDlgWebLoadError&) = delete;

  CATDlgWebLoadError& operator=(const CATDlgWebLoadError&) = delete;

  bool IsLastKnowURL() { return true; }

  const int errorCode;
  const CATUnicodeString errorCodeName;
  const CATUnicodeString failingURL;
  const webview::EventType eventType;
};

class ExportedByCATWebViewDialog CATDlgWebLoadResourceError: public CATNotification
{
  CATDeclareClass;

public:
  explicit CATDlgWebLoadResourceError(const int i_errorCode,
    const CATUnicodeString& i_errorCodeName,
    const CATUnicodeString& i_failingURL)
    : eventType(webview::EventType::LOAD_RESOURCE_ERROR)
    , errorCode(i_errorCode)
    , errorCodeName(i_errorCodeName)
    , failingURL(i_failingURL)
  {
  }

  ~CATDlgWebLoadResourceError() {}

  CATDlgWebLoadResourceError() = delete;
  CATDlgWebLoadResourceError(const CATDlgWebLoadResourceError&) = delete;

  CATDlgWebLoadResourceError& operator=(const CATDlgWebLoadResourceError&) = delete;

  bool IsLastKnowURL() { return false; }

  const int errorCode;
  const CATUnicodeString errorCodeName;
  const CATUnicodeString failingURL;
  const webview::EventType eventType;
};

class ExportedByCATWebViewDialog CATDlgWebLoadStart: public CATNotification
{
  CATDeclareClass;

public:
  explicit CATDlgWebLoadStart(const CATUnicodeString& i_url)
    : eventType(webview::EventType::LIFECYCLE)
    , url(i_url)
  {
  }

  ~CATDlgWebLoadStart() {}

  CATDlgWebLoadStart() = delete;
  CATDlgWebLoadStart(const CATDlgWebLoadStart&) = delete;

  CATDlgWebLoadStart& operator=(const CATDlgWebLoadStart&) = delete;

  // URL of the page.
  const CATUnicodeString url;
  const webview::EventType eventType;
};

class ExportedByCATWebViewDialog CATDlgWebPermissionDialog: public CATNotification
{
  CATDeclareClass;

public:
  typedef std::function<void(const int)> ContinueCallback;

  explicit CATDlgWebPermissionDialog(const CATUnicodeString& i_originURL,
    const int i_type,
    ContinueCallback i_callback)
    : originURL(i_originURL)
    , type(i_type)
    , callback(i_callback)
  {
  }

  ~CATDlgWebPermissionDialog() {}

  void Continue(const int i_result) { if (callback) { callback(i_result); Clear(); } }

  CATDlgWebPermissionDialog() = delete;
  CATDlgWebPermissionDialog(const CATDlgWebPermissionDialog&) = delete;

  CATDlgWebPermissionDialog& operator=(const CATDlgWebPermissionDialog&) = delete;

  const CATUnicodeString originURL;
  const int type;

private:
  void Clear() { callback = nullptr; }

  ContinueCallback callback;
};

#endif // CATDlgWebNotifications_H
