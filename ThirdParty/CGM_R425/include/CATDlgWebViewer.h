//===================================================================
// COPYRIGHT Dassault Systemes 2020-08-04
//===================================================================
// 2020-08-04 Creation: D6K
//===================================================================

#ifndef CATDlgWebViewer_H
#define CATDlgWebViewer_H

// CATWebViewDialog
#include "CATDlgWebTypes.h"
#include "CATWebViewDialog.h"
// Dialog
#include "CATDlgBlackBox.h"
#include "CATDlgUtility.h"
// SystemTS
#include "DSYString.h"

class CATDlgWebViewerImpl;

/**
 * A web browser control like CATDlgHtmlView that uses CEF instead of IE for its backend.
 */
class ExportedByCATWebViewDialog CATDlgWebViewer: public CATDlgBlackBox
{
  CATDeclareClass;

public:

  // Instantiate an empty web view.
  CATDlgWebViewer(CATDialog* i_pParent, const CATString& i_name, CATDlgStyle i_style = 0)
  : CATDlgWebViewer(CATUnicodeString(),i_pParent,i_name,i_style) 
  {}  
  // Instantiate a web view using the first arg as its homepage.
  CATDlgWebViewer(const CATUnicodeString& i_url, CATDialog* i_pParent, const CATString& i_name, CATDlgStyle i_style = 0);
  ~CATDlgWebViewer();

  // Deleted constructors
  CATDlgWebViewer() = delete;
  CATDlgWebViewer(const CATDlgWebViewer&) = delete;
  CATDlgWebViewer& operator=(const CATDlgWebViewer&) = delete;

  // Load a new URL in the web view.
  void Navigate(const CATUnicodeString& i_url);
  // Load the previous page in the navigation history.
  // Does nothing if there is no past navigation entries.
  void GoBack();
  // Load the next page in the navigation history.
  // Does nothing if there is no subsequent navigation entries.
  void GoForward();
  // Reload the current page or resource.
  // Pass `true` to ignore the HTTP cache for a single reload. The cache will not be cleared.
  void Refresh(const bool i_ignoreCache = false);
  // Stop loading the current page or resource.
  void Stop();
  // Return the URL for the current page.
  CATUnicodeString GetURL() const;

  // Evaluate JavaScript code in the current page's context (top frame).
  // Child frames (e.g. for iframes) cannot be targeted with this method.
  // The optional second and third parameters can be useful if your code can produce errors:
  // the call stack will include the origin and the line number you defined for the execution so
  // you can identify the error's origin.
  void RunScript(
    const CATUnicodeString& i_script, const CATUnicodeString& i_origin = "", const int i_line = 0);

  // Return the behavior that is currently applied to all requests to open a popup window.
  webview::PopupBehavior GetPopupBehavior() const;
  // Set to true to allow access to audio media streams (microphones) for WebRTC.
  void SetAudioMediaStreamsEnabled(const bool);
  // Define a behavior to apply to all requests to open a popup window.
  void SetPopupBehavior(const webview::PopupBehavior);
  // Set to true to enable the dispatch of notifications after every use of the Console API.
  void SetConsoleMessageEventsEnabled(const bool);
  // Set to true to allow access to video media streams (webcams) for WebRTC.
  void SetVideoMediaStreamsEnabled(const bool);

  void SetVisibility(CATULong);
  void InvalidateRect();

private:
  void SubscribeDialogEvents(CATDialog*);

  void OnCreate(CATCommand*, CATNotification*, CATCommandClientData);
  void OnResize(CATCommand*, CATNotification*, CATCommandClientData);
  void OnVisibilityChange(CATCommand*, CATNotification*, CATCommandClientData);
  void OnWindowMinimize(CATCommand*, CATNotification*, CATCommandClientData);
  void OnWindowRestore(CATCommand*, CATNotification*, CATCommandClientData);

  CATDlgWebViewerImpl* _pImpl = nullptr;

  // Used in GTK context for now
  CATSysWidgetEx _nativeWindow;
};

#endif // CATDlgWebViewer_H
