//===================================================================
// COPYRIGHT Dassault Systemes 2013-05-31
//===================================================================
//
// Abstract: Notifications for web browser events.
//
//===================================================================
// 2013-05-31 Creation: D6K
//===================================================================

#ifndef CATMMWebNotifications_H
#define CATMMWebNotifications_H

// MultimediaInterfaces
#include "CATMMWebTypes.h"
#include "MultimediaItf.h"
// System
#include "CATNotification.h"
// SystemTS
#include "DSYString.h"
#include "CATIAV5Level.h"
// std
#include <memory>
#include <stdint.h>

#ifdef CATIAR426
#define _R426__REMOVE_DEPRECATED_SIGNATURES
#endif

// System/PublicInterfaces/CATErrorMacros.h defines try/catch/throw as
// ERROR; as a consequence #include <vector> may fail to compile since
// it is based on a template so its code is inlined and may
// contain exception code.
#undef try
#undef catch
#undef throw

#include <functional>
#include <vector>

namespace MMW
{
  enum NotificationType
  {
    NT_UNKNOWN = 0,
    // The browser has been created and is ready.
    NT_START,
    // The 'BrowserClosed' event has been fired.
    NT_END,
    // The 'DOMContentLoaded' event has been fired.
    NT_DOM_READY,
    // The 'load' event has been fired.
    NT_LOAD,
    // The 'unload' event has been fired.
    NT_UNLOAD,
    // The WebView has changed: a new texture is available.
    NT_REDRAW,
    // The renderer process for the current browser has been terminated (crash or process kill).
    NT_ABEND
  };

  // Notification for string data sent from JS contexts during CATRecord captures.
  class ExportedByMultimediaItf RecordableNotification: public CATNotification
  {
    CATDeclareClass;

    // TODO: Declare an interface that returns a CATSYPProperties for record.
    // Each recordable notification type will implement it to return the appropriate data.

  public:
    explicit RecordableNotification(const CaptureLevel i_level)
      : captureLevel(i_level)
    {
    }
    explicit RecordableNotification(const RecordOptions& i_options)
    {
      if (i_options.recordable)
        captureLevel = i_options.captureAll ? CAP_STRICT : CAP_SOFT;
      else
        captureLevel = CAP_UNKNOWN;
    }

    CaptureLevel captureLevel;
  };

  // Generic notification for events that don't need to carry parameters.
  class ExportedByMultimediaItf GenericNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    explicit GenericNotification(const NotificationType i_type)
      : type(i_type)
    {
    }

    NotificationType type;
  };

  // Notification for JavaScript context creation.
  class ExportedByMultimediaItf JSContextNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    explicit JSContextNotification(const bool i_exists)
      : exists(i_exists)
    {
    }

    // true means the context was just created; false means it was destroyed.
    bool exists;
  };

  // Notification for keyboard events that should be redispatched by the receiver.
  class ExportedByMultimediaItf KeyNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    explicit KeyNotification(const KeyEvent& i_event)
      : props(i_event)
    {
    }

    KeyEvent props;
  };

  // Notification for mouse cursor changes.
  class ExportedByMultimediaItf MouseCursorNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    explicit MouseCursorNotification(const MouseCursor i_cursor)
      : cursorType(i_cursor)
    {
    }

    MouseCursor cursorType;
  };

  // Notification for messages coming from a JS context.
  class ExportedByMultimediaItf JSMessageNotification: public RecordableNotification
  {
    CATDeclareClass;

  public:
    JSMessageNotification()
      : RecordableNotification(CAP_STRICT)
    {
    }
    JSMessageNotification(const std::vector<CATUnicodeString>& i_args,
      const StackFrameLocation& i_origin,
      const RecordOptions& i_options)
      : RecordableNotification(i_options)
      , args(i_args)
      , origin(i_origin)
    {
    }
    ~JSMessageNotification() {}

    std::vector<CATUnicodeString> args;
    StackFrameLocation origin;
  };

  // Notification for permission dialog boxes.
  class ExportedByMultimediaItf PermissionNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    PermissionNotification(const CATUnicodeString& i_originURL,
      const PermissionType i_type,
      std::unique_ptr<PermissionCallback> i_callback)
      : originURL(i_originURL)
      , type(i_type)
      , callback(std::move(i_callback))
    {
    }
    ~PermissionNotification() {}

    CATUnicodeString originURL;
    PermissionType type;
    std::unique_ptr<PermissionCallback> callback;
  };

  // Notification for popup window creation.
  class ExportedByMultimediaItf PopupNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    PopupNotification(const PopupProperties& i_properties, const int i_browserID)
      : properties(i_properties)
      , browserID(i_browserID)
    {
    }

    PopupProperties properties;
    int browserID;
  };

  // Notification for popup window destruction.
  class ExportedByMultimediaItf PopupCloseNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    PopupCloseNotification(const int i_browserID)
      : browserID(i_browserID)
    {
    }

    int browserID;
  };

  // Notification for window title changes.
  class ExportedByMultimediaItf TitleNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    explicit TitleNotification(const CATUnicodeString& i_title)
      : newTitle(i_title)
    {
    }

    CATUnicodeString newTitle;
  };

  // Notification for URL changes.
  class ExportedByMultimediaItf URLNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    explicit URLNotification(const CATUnicodeString& i_URL)
      : newURL(i_URL)
    {
    }

    CATUnicodeString newURL;
  };

  // Notification for context menu handling.
  class ExportedByMultimediaItf ContextMenuNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    explicit ContextMenuNotification(const ContextMenuProperties& i_properties)
      : properties(i_properties)
    {
    }

    ContextMenuProperties properties;
  };

  // Notification for tooltips.
  class ExportedByMultimediaItf TooltipNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    explicit TooltipNotification(const CATUnicodeString& i_content)
      : text(i_content)
    {
    }

    CATUnicodeString text;
  };

  // Notification for JavaScript dialog boxes.
  class ExportedByMultimediaItf JSDialogNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    JSDialogNotification()
      : type(JS_DLG_CONFIRM)
    {
    }
    JSDialogNotification(const JSDialogType i_type,
      const CATUnicodeString& i_originURL,
      const CATUnicodeString& i_message)
      : type(i_type)
      , originURL(i_originURL)
      , message(i_message)
    {
    }

    JSDialogType type;
    CATUnicodeString originURL;
    CATUnicodeString message;
    CATUnicodeString defaultPromptText;
  };

  // Notification for download dialog boxes.
  class ExportedByMultimediaItf DownloadDialogNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    DownloadDialogNotification(const uint32_t i_id,
      const CATUnicodeString& i_fileName,
      const CATUnicodeString& i_originURL,
      const CATUnicodeString& i_mimeType,
      const int64_t i_totalBytes)
      : id(i_id)
      , fileName(i_fileName)
      , originURL(i_originURL)
      , mimeType(i_mimeType)
      , totalBytes(i_totalBytes)
    {
    }

    uint32_t id;
    CATUnicodeString fileName;
    CATUnicodeString originURL;
    CATUnicodeString mimeType;
    int64_t totalBytes;
  };

  // Notification for download progress info.
  class ExportedByMultimediaItf DownloadProgressNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    DownloadProgressNotification(const uint32_t i_id,
      const int64_t i_receivedBytes,
      const int64_t i_totalBytes,
      const int64_t i_speed,
      const bool i_complete)
      : id(i_id)
      , receivedBytes(i_receivedBytes)
      , totalBytes(i_totalBytes)
      , speed(i_speed)
      , complete(i_complete)
    {
    }

    uint32_t id;
    int64_t receivedBytes;
    int64_t totalBytes;
    int64_t speed; // Download speed in bytes per second.
    bool complete;
  };

  // Notification for file selections.
  class ExportedByMultimediaItf FileDialogNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    struct Filter
    {
      // List of file extensions, e.g. "jpg", "png"...
      std::vector<CATUnicodeString> extensions;
      // Human-readable description for the list of extensions.
      CATUnicodeString description;
    };

    FileDialogNotification() {}
    FileDialogNotification(const FileDialogType i_type,
      const std::vector<Filter>& i_filters,
      std::unique_ptr<FileDialogCallback> i_callback)
      : type(i_type)
      , filters(i_filters)
      , callback(std::move(i_callback))
    {
    }

    FileDialogType type;
    std::vector<Filter> filters;
    std::unique_ptr<FileDialogCallback> callback;
  };

  // Notification for load events.
  class ExportedByMultimediaItf LoadNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    LoadNotification()
      : isLoading(false)
    {
    }
    LoadNotification(const bool i_isLoading, const CATUnicodeString& i_url)
      : isLoading(i_isLoading)
      , url(i_url)
    {
    }

    bool isLoading;
    CATUnicodeString url;
  };

  // Notification for non-HTTP load resources errors: connectivity, certificates, etc.
  class ExportedByMultimediaItf LoadResourceErrorNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    LoadResourceErrorNotification()
      : errorCode(0)
    {
    }
    LoadResourceErrorNotification(
      const int i_code, const CATUnicodeString& i_name, const CATUnicodeString& i_url)
      : errorCode(i_code)
      , errorName(i_name)
      , failingURL(i_url)
    {
    }

    int errorCode;
    CATUnicodeString errorName;
    CATUnicodeString failingURL;
  };

  // Notification for non-HTTP load errors: connectivity, certificates, etc.
  class ExportedByMultimediaItf LoadErrorNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    LoadErrorNotification()
      : errorCode(0)
    {
    }
    LoadErrorNotification(
      const int i_code, const CATUnicodeString& i_name, const CATUnicodeString& i_url)
      : errorCode(i_code)
      , errorName(i_name)
      , failingURL(i_url)
    {
    }

    int errorCode;
    CATUnicodeString errorName;
    CATUnicodeString failingURL;
  };

  // Notification for HTTP request errors, typically in the 400-499 and 500-599 ranges.
  class ExportedByMultimediaItf HTTPErrorNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    HTTPErrorNotification()
      : status(0)
    {
    }
    HTTPErrorNotification(const int i_status,
      const CATUnicodeString& i_text,
      const CATUnicodeString& i_method,
      const CATUnicodeString& i_url)
      : status(i_status)
      , statusText(i_text)
      , method(i_method)
      , requestURL(i_url)
    {
    }

    int status;
    CATUnicodeString statusText;
    CATUnicodeString method;
    CATUnicodeString requestURL;
  };

  // Notification for document size events.
  class ExportedByMultimediaItf DocSizeNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    DocSizeNotification()
      : documentWidth(0)
      , documentHeight(0)
    {
    }
    DocSizeNotification(const int i_width, const int i_height)
      : documentWidth(i_width)
      , documentHeight(i_height)
    {
    }

    int documentWidth;
    int documentHeight;
  };

  // Notification for console messages (JS console.log()/info()).
  class ExportedByMultimediaItf ConsoleNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    ConsoleNotification(const CATUnicodeString& i_message,
      const CATUnicodeString& i_sourceURL,
      const int i_sourceLine)
      : message(i_message)
      , sourceURL(i_sourceURL)
      , sourceLine(i_sourceLine)
    {
    }

    CATUnicodeString message;
    CATUnicodeString sourceURL;
    int sourceLine;
  };

  // Notification for drag&drop start.
  class ExportedByMultimediaItf StartDragNotification: public CATNotification
  {
    CATDeclareClass;

  public:

#ifndef _R426__REMOVE_DEPRECATED_SIGNATURES
    // TODO: Remove this constructor when CATCefClientHandler stops using it.
    StartDragNotification(
      void* i_pDragData, const DragModeFlag i_allowedDragModes, const bool i_fakeDrag)
      : pDragData(i_pDragData)
      , allowedDragModes(i_allowedDragModes)
      , fakeDrag(i_fakeDrag)
    {
    }
    StartDragNotification(void* i_pDragData, const DragModeFlag i_allowedDragModes) 
      : allowedDragModes(i_allowedDragModes)
    {
    }    
    void* pDragData;
    // TODO: Remove fakeDrag in StartDragNotification when the bypass is not needed anymore.
    bool fakeDrag;
#endif
    StartDragNotification(const DragModeFlag i_allowedDragModes)
      : allowedDragModes(i_allowedDragModes)
    {}    
  
    DragModeFlag allowedDragModes;
  };
      
  // Notification for displaying messages to the user on critical actions.
  class ExportedByMultimediaItf InfoNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    InfoNotification(const NotificationLevel i_level,
      const CATUnicodeString& i_text,
      const float i_suggestedUptime = 0.f)
      : level(i_level)
      , text(i_text)
      , suggestedUptime(i_suggestedUptime)
    {
    }

    NotificationLevel level;
    CATUnicodeString text;
    float suggestedUptime;
  };

  // Notification for telling if the user login succeeded or not.
  class ExportedByMultimediaItf LoginNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    explicit LoginNotification(const bool i_success)
      : success(i_success)
    {
    }

    bool success;
  };

  // Notification for basic HTTP authentication.
  class ExportedByMultimediaItf HTTPAuthNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    HTTPAuthNotification() {}
    HTTPAuthNotification(const CATUnicodeString& i_url,
      const CATUnicodeString& i_host,
      const int i_port,
      const bool i_isProxy,
      std::unique_ptr<HTTPAuthCallback> i_callback)
      : url(i_url)
      , host(i_host)
      , port(i_port)
      , isProxy(i_isProxy)
      , callback(std::move(i_callback))
    {
    }

    CATUnicodeString url;
    CATUnicodeString host;
    int port;
    bool isProxy;
    std::unique_ptr<HTTPAuthCallback> callback;
  };

  // Notification for SSL client certificate selection.
  class ExportedByMultimediaItf ClientCertificateSelectionNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    ClientCertificateSelectionNotification(const uint64_t i_id,
      const std::vector<MMW::SSLCertificate>& i_certificates,
      const CATUnicodeString& i_domain)
      : id(i_id)
      , certificates(i_certificates)
      , domain(i_domain)
    {
    }

    uint64_t id;
    std::vector<MMW::SSLCertificate> certificates;
    CATUnicodeString domain;
  };

  // Notification for zoom changes.
  class ExportedByMultimediaItf ZoomNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    explicit ZoomNotification(const double i_level)
      : level(i_level)
    {
    }

    double level;
  };

  // Notification for dispatching record data or replay info from webapps.
  class ExportedByMultimediaItf WebRecordNotification: public CATNotification
  {
    CATDeclareClass;

  public:
    explicit WebRecordNotification(const CATUnicodeString& i_data)
      : recordData(i_data)
    {
    }

    CATUnicodeString recordData;
  };
} // namespace MMW

#endif
