//===================================================================
// COPYRIGHT Dassault Syst�mes 2013-10-01
//===================================================================
// 2013-10-01 Creation: D6K
//===================================================================

#ifndef CATVidCtlWebViewer_H
#define CATVidCtlWebViewer_H

// VisuImmersiveDialog
#include <CATVidCtl.h>
#include <CATVidWebTypes.h>
#include <VisuDialog.h>
// UIVCoreTools
#include <CATSYPDeferredJSResult.h>
// System
#include <CATListOfCATUnicodeString.h>
// std
#include <functional>
#include <stdint.h>

#ifndef DEPRECATED_HEADER
#define DEPRECATED_HEADER \
  "\n" \
  "################################################################################\n" \
  "DEPRECATED\n" \
  "################################################################################\n"
#endif

#ifndef DEPRECATED_FOOTER
#define DEPRECATED_FOOTER \
  "\n################################################################################\n"
#endif

#ifndef WEBVIEWER_DEPRECATED
#ifdef __GNUC__
#define WEBVIEWER_DEPRECATED(msg, func) func __attribute__((deprecated))
#elif defined(_MSC_VER)
#define WEBVIEWER_DEPRECATED(msg, func) \
  __declspec(deprecated(DEPRECATED_HEADER msg DEPRECATED_FOOTER)) func
#else
#define WEBVIEWER_DEPRECATED(msg, func) func
#endif
#endif

namespace MMW
{
  class ConsoleNotification;
  class DownloadDialogNotification;
  class DownloadProgressNotification;
  class HTTPErrorNotification;
  class JSMessageNotification;
  class LoadNotification;
  class LoadErrorNotification;
  class LoadResourceErrorNotification;
  class PermissionNotification;
  class WebRecordNotification;
} // namespace MMW

namespace webrec
{
  class PropertyWrapper;
}

class CATDlgFile;
class CATSYPProperties;
class CATVidDnDData;
class CATVidInteractionRecorderData;
class CATVidInteractionReplayerData;
class CATVidWebRecorderDelegate;
class l_CATVidCtlWebViewer;

/**
 * @ingroup VIDControls
 * Viewer class that provides common web browser features
 * by embedding an offscreen browser.
 */
class ExportedByVisuDialog CATVidCtlWebViewer: public CATVidCtl
{
  CATDeclareClass;

public:
  /**
   * Constructor.
   * Creates an anonymous widget, with an optional home URL.
   * The home URL will be loaded automatically upon creation.
   */
  CATVidCtlWebViewer(const CATUnicodeString& i_url = "");
  /**
   * Constructor.
   * Creates a named widget (required for Record tests), with an optional home URL.
   * The home URL will be loaded automatically upon creation.
   *
   */
  CATVidCtlWebViewer(
    CATCommand* i_pParent, const CATString& i_id, const CATUnicodeString& i_url = "");
  /** Destructor. */
  virtual ~CATVidCtlWebViewer();

  /**
   * @name Creation settings
   * Settings that can only be defined before @ref Build() is called.
   */
  /** @{ */

  /**
   * Returns 1 if JavaScript is enabled.
   */
  int GetUseJavaScriptFlag() const;
  /**
   * See @ref GetUseJavaScriptFlag.
   * @param i_enable
   *   Set to 1 to enable JavaScript in the browser (else set to 0).
   * @note
   *   Default value is 1.
   */
  void SetUseJavaScriptFlag(const int i_enable);

  /**
   * Returns 1 if file:// URLs can access other local resources.
   */
  WEBVIEWER_DEPRECATED(
    "GetFileAccessFromFileURLsFlag is now deprecated and marked for removal.\n"
    "Due to NetworkService requirements file_access_from_file_urls has been configured globally via command-line flags.",
  int GetFileAccessFromFileURLsFlag() const);

  /**
   * See @ref GetFileAccessFromFileURLsFlag.
   * @param i_enable
   *   Set to 1 to let file:// URLs access other files.
   * @note
   *   Default value is 0.
   */
  WEBVIEWER_DEPRECATED(
    "SetFileAccessFromFileURLsFlag is now deprecated and marked for removal.\n" 
    "Due to NetworkService requirements file_access_from_file_urls has been configured globally via command-line flags.",
  void SetFileAccessFromFileURLsFlag(const int i_enable));

  /**
   * Returns 1 if a same-origin policy (restrictions on cross-domain requests) is enforced by the
   * browser.
   */
  int GetSameOriginPolicyFlag() const;
  /**
   * See @ref GetSameOriginPolicyFlag.
   * Can be used to disable the security rule for development or debug involving local resources and
   * cross-domain requests.
   * @param i_enforce
   *   Set to 1 to enforce a same-origin policy in the browser.
   * @note
   *   Default value is 1.
   */
  void SetSameOriginPolicyFlag(const int i_enforce);
  /**
   * Returns 1 if the browser texture can have a transparent background.
   */
  int GetTransparencyFlag() const;
  /**
   * See @ref GetTransparencyFlag.
   * @param i_enable
   *   Set to 1 to enable transparency on the textures created by the offscreen browser.
   * @note
   *   Default value is 0.
   */
  void SetTransparencyFlag(const int i_enable);
  /**
   * Returns 1 if WebRTC is allowed to use the microphone for audio capture.
   */
  int GetEnableAudioMediaStream() const;
  /**
   * See @ref GetEnableAudioMediaStream.
   * @param i_enable
   *   Set to 1 to enable audio capture for WebRTC.
   * @note
   *   Default value is 0.
   */
  void SetEnableAudioMediaStream(const int i_enable);
  /**
   * Returns 1 if WebRTC is allowed to use the webcam for video capture.
   */
  int GetEnableVideoMediaStream() const;
  /**
   * See @ref GetEnableVideoMediaStream.
   * @param i_enable
   *   Set to 1 to enable video capture for WebRTC.
   * @note
   *   Default value is 0.
   */
  void SetEnableVideoMediaStream(const int i_enable);
  /**
   * Returns the maximum framerate for the web view, in frames per second.
   */
  int GetMaxFramerate() const;
  /**
   * Sets a maximum framerate for the web view, in frames per second.
   * @note
   *   Default value is 60, which is also the maximum value.
   */
  void SetMaxFramerate(const int i_fps);

  /** @} */

  /**
   * Starts the creation of the offscreen browser.
   * It is mandatory to build the browser before using it.
   *
   * @note
   *   The whole operation is async, so you need to subscribe to the @ref Start() event to if you
   *   need to execute code on the browser as soon as possible.
   *
   *   If the widget is displayed, Build() will be called automatically.
   */
  HRESULT Build();
  /**
   * Returns TRUE if the @ref Build() method has already been used.
   *
   * @note
   *   It only means that the Build() method was called, so the browser might not be ready.
   *   See @ref BrowserStarted().
   */
  CATBoolean IsBuilt() const;
  /**
   * Returns TRUE if the offscreen browser is active and ready to be used.
   */
  CATBoolean BrowserStarted() const;
  /**
   * Loads an URL in the browser.
   * @warning
   *   Make sure the widget is built (using @ref Build()) before using this method.
   * @param i_url
   *   The URL to load.
   */
  void LoadURL(const CATUnicodeString& i_url);
  /**
   * Loads the contents of the string parameter in the browser.
   * @param i_content
   *   The string content to load.
   * @param i_fakeURL
   *   The fake URL that will be affected to that content.
   *   It should start with a standard scheme like "http://"
   *   or behaviors like link clicks and web security restrictions
   *   may not behave as expected.
   */
  void LoadContent(const CATUnicodeString& i_content, const CATUnicodeString& i_fakeURL);
  /**
   * Stops processing the page that is currently loading in the browser.
   * @warning
   *   Make sure the widget is built (using @ref Build()) before using this method.
   */
  void StopLoading();
  /**
   * Loads the browser homepage.
   * @warning
   *   Make sure the widget is built (using @ref Build()) before using this method.
   */
  void LoadHomepage();
  /**
   * Loads the previous page from the current navigation history.
   * Navigation history is lost when the widget is destroyed.
   * @warning
   *   Make sure the widget is built (using @ref Build()) before using this method.
   */
  void LoadPreviousURL();
  /**
   * Loads the next page from the current navigation history.
   * Navigation history is lost when the widget is destroyed.
   * @warning
   *   Make sure the widget is built (using @ref Build()) before using this method.
   */
  void LoadNextURL();
  /**
   * Reloads the page that is currently displayed by the browser.
   * @param i_ignoreCacheFlag
   *   Set to 1 to reload the page without using the browser cache (use 0 for a regular reload).
   * @warning
   *   Make sure the widget is built (using @ref Build()) before using this method.
   */
  void Refresh(const int i_ignoreCacheFlag);
  
  /**
   * Executes JavaScript code before each page loading.
   * @param i_jsCode
   *   The JavaScript code to run.
   * @param i_url
   *   The URL for the script. It will be displayed in the stack if an error happens.
   * @param i_line
   *   The starting line for the script. It will also be displayed in the stack.
   *   If you run a multiline script, the error location will be relative to the provided line
   *   number.
   * @warning
   *   Make sure the widget is NOT YET built (@ref Build()) before using this method.
   */
  void RunJavaScriptBeforePagesLoading(const CATUnicodeString& i_jsCode, const CATUnicodeString& i_url = "", const int i_line = 1);
    
  /**
   * Executes JavaScript code on the current page.
   * @param i_jsCode
   *   The JavaScript code to run.
   * @param i_url
   *   The URL for the script. It will be displayed in the stack if an error happens.
   * @param i_line
   *   The starting line for the script. It will also be displayed in the stack.
   *   If you run a multiline script, the error location will be relative to the provided line
   *   number.
   * @warning
   *   Make sure the widget is built (using @ref Build()) before using this method.
   */
  void RunJavaScript(
    const CATUnicodeString& i_jsCode, const CATUnicodeString& i_url = "", const int i_line = 1);

  /**
   * Executes JavaScript code on the current page and return result or error
   * in the provided callbacks.
   * The result is the last expression of the snippet: same behavior as the `eval()` function in JS
   * or the interactive console in the DevTools of a browser.
   * @param i_jsCode
   *   The JavaScript code to run.
   * @param i_resultCallback
   *   The callback that will be executed with the result of the provided code.
   *   Called asynchronously on the main thread.
   * @param i_errorCallback
   *   The callback that will be executed with error details if the provided code triggers an
   *   exception.
   *   Called asynchronously on the main thread.
   * @param i_url
   *   The URL for the script. It will be displayed in the stack if an error happens.
   * @param i_line
   *   The starting line for the script. It will also be displayed in the stack.
   *   If you run a multiline script, the error location will be relative to the provided line
   *   number.
   * @warning
   *   Make sure the widget is built (using @ref Build()) before using this method.
   * @warning
   *   Results only work for primitive values for now, i.e. objects and arrays are excluded.
   */
  void EvalJavaScript(const CATUnicodeString& i_jsCode,
    std::function<void(const CATSYPJSValue&)> i_resultCallback,
    std::function<void(const CATSYPJSError&)> i_errorCallback,
    const CATUnicodeString& i_url = "",
    const int i_line = 1);
  /**
   * Executes JavaScript code on the current page and return an object that allows to wait for the
   * result or an error.
   * The result is the last expression of the snippet: same behavior as the `eval()` function in JS
   * or the interactive console in the DevTools of a browser.
   * @param i_jsCode
   *   The JavaScript code to run.
   * @param i_url
   *   The URL for the script. It will be displayed in the stack if an error happens.
   * @param i_line
   *   The starting line for the script. It will also be displayed in the stack.
   *   If you run a multiline script, the error location will be relative to the provided line
   *   number.
   * @warning
   *   Make sure the widget is built (using @ref Build()) before using this method.
   * @warning
   *   Results only work for primitive values for now, i.e. objects and arrays are excluded.
   * @return
   *   An object that will provide a result or an error.
   */
  CATSYPDeferredJSResult EvalJavaScriptSync(
    const CATUnicodeString& i_jsCode, const CATUnicodeString& i_url = "", const int i_line = 1);

  /**
   * If set to anything other than 0, all user actions coming from
   * the mouse or the keyboard will be ignored.
   * In this case, events will not be consumed by the widget.
   * Note: PassiveMode has priority over OverlayMode.
   */
  void SetPassiveMode(const int);
  /**
   * Returns 1 if the widget doesn't handle or consume events
   * coming from the mouse and the keyboard.
   */
  int GetPassiveMode() const;
  /**
   * If set to anything other than 0, user actions coming from
   * the mouse, touch or the keyboard will go through transparent areas.
   * If event coordinates are located within such areas, events will not
   * be consumed by the widget.
   * Note: PassiveMode has priority over OverlayMode.
   */
  void SetOverlayMode(const int);
  /**
   * Returns 1 if the widget doesn't consume events on transparent areas.
   */
  int GetOverlayMode() const;
  /**
   * Returns the homepage address.
   */
  const CATUnicodeString& GetHomeURL() const;
  /**
   * Sets a new address for the homepage.
   */
  void SetHomeURL(const CATUnicodeString& i_homeURL);
  /**
   * Returns a list of all handled custom schemes.
   */
  CATListOfCATUnicodeString GetCustomSchemes() const;
  /**
   * Sets a new list of custom schemes to handle.
   */
  void SetCustomSchemes(const CATListOfCATUnicodeString& i_schemeList);
  /**
   * Returns the current page URL.
   * @warning
   *   The string is changed asynchronously by the offscreen browser when
   *   it has finished loading the page.
   */
  const CATUnicodeString& GetNavigationURL() const;
  /**
   * Sets a new URL that the browser will load eventually.
   * If the autoload flag is set to 1, the URL will be automatically loaded.
   * @note
   *   This is useful if an address bar is used to navigate.
   *   To simply load an URL, use @ref LoadURL.
   */
  void SetNavigationURL(const CATUnicodeString& i_navURL);
  /**
   * Returns the current zoom level.
   * @note
   *   A value of 0.0 is equivalent to a 100% zoom factor.
   */
  double GetZoomLevel() const;
  /**
   * Sets a new zoom level for the browser.
   * This is an override operation, not an increment or decrement on the current level.
   * @note
   *   If @c DisableZoomFlag is set to 1, the level will still change,
   *   but it will have no effect until it is reset to 0.
   */
  void SetZoomLevel(const double i_level);
  /**
   * Returns 1 if the navigation URL is loaded as soon as it's modified.
   */
  int GetAutoLoadFlag() const;
  /**
   * Sets a new autoload flag.
   * @param i_enable
   *   Set to 1 to force @ref SetNavigationURL to load the new URL (else set to 0).
   * @note
   *   Default value is 0.
   */
  void SetAutoLoadFlag(const int i_enable);
  /**
   * Returns 1 if context menus are enabled.
   */
  int GetUseContextMenuFlag() const;
  /**
   * See @ref GetUseContextMenuFlag.
   * @param i_enable
   *   Set to 1 to allow context menus to be displayed after a right click (else set to 0).
   * @note
   *   Default value is 1.
   */
  void SetUseContextMenuFlag(const int i_enable);
  /**
   * Returns 1 if mixed-content behavior is allowed, e.g. loading a resource
   * over HTTP from a page that was loaded using HTTPS.
   */
  int GetAllowInsecureContentFlag() const;
  /**
   * See @ref GetAllowInsecureContentFlag.
   * Can be used to avoid errors when loading resources over an insecure
   * protocol when the origin is using a secure one (e.g. HTTP vs. HTTPS).
   * @param i_allow
   *   Set to 1 to allow mixed content to be loaded.
   * @note
   *   Default value is 0.
   */
  void SetAllowInsecureContentFlag(const int i_allow);
  /**
   * Returns the behavior that is currently applied to every popup window creation.
   */
  CATVidWeb::PopupBehavior GetPopupBehavior() const;
  /**
   * Change the behavior to be applied for popup window creations.
   * @param
   *   Behavior to apply for all popup windows before they open: block, open in current window, etc.
   */
  void SetPopupBehavior(const CATVidWeb::PopupBehavior);
  /**
   * Returns 1 if context menu actions must trigger keyboard shortcuts instead of using the browser
   * API. For example, sending CTRL + "c" instead of calling <browser>::Copy().
   */
  int GetOverrideContextMenuActionsFlag() const;
  /**
   * See @ref GetOverrideContextMenuActionsFlag.
   * @param i_override
   *   Set to 1 to force the widget to use keyboard shortcuts when clicking on a context menu entry.
   * @note
   *   Default value is 0.
   */
  void SetOverrideContextMenuActionsFlag(const int i_override);
  /**
   * Returns 1 if the widget can update its containing window title when a web document requires it.
   */
  int GetAllowTitleUpdateFlag() const;
  /**
   * See @ref GetAllowTitleUpdateFlag.
   * @param i_allow
   *   Set to 1 to allow the widget to update its containing window title.
   * @note
   *   Default value is 0.
   */
  void SetAllowTitleUpdateFlag(const int i_allow);
  /**
   * Returns 1 if zoom changes are allowed by the browser.
   */
  int GetAllowZoomFlag() const;
  /**
   * See @ref GetAllowZoomFlag.
   * @param i_allow
   *   Set to 1 to allow the browser to apply zoom changes.
   * @note
   *   Default value is 1.
   */
  void SetAllowZoomFlag(const int i_allow);
  /**
   * Returns 1 if the @c ConsoleMessage can be dispatched on every use of the Console API in a
   * webapp.
   */
  int GetEnableConsoleMessageFlag() const;
  /**
   * See @ref GetEnableConsoleMessageFlag.
   * @param i_enableFlag
   *   Set to 1 to enable the @c ConsoleMessage event.
   * @note
   *   Default value is 0.
   *   This is necessary mostly because lots of people have an excessive
   *   use of console.log() in their JS programs.
   */
  void SetEnableConsoleMessageFlag(const int i_enableFlag);
  /**
   * Returns 1 if the browser can go to the previous or the next page from its navigation history,
   * or 0 if it can't.
   */
  int GetAllowBackForwardFlag() const;
  /**
   * Enable or disable the ability to load the previous/next pages from the navigation history.
   * @param i_backForwardFlag
   *   Set to 1 to enable, or 0 to disable.
   * @note
   *   Default value is 1.
   */
  void SetAllowBackForwardFlag(const int i_backForwardFlag);
  /**
   * Returns 1 if the browser can reload the current page.
   */
  int GetAllowReloadFlag() const;
  /**
   * Enable or disable the ability to reload the page that is currently displayed by the browser.
   * @param i_reloadFlag
   *   Set to 1 to enable, or 0 to disable.
   *   Disabling this will also prevent the browser from loading the same URL again.
   * @note
   *   Default value is 1.
   */
  void SetAllowReloadFlag(const int i_reloadFlag);
  /**
   * Returns the default location for all downloads.
   * See @ref SetDefaultDownloadDirectory
   */
  const CATUnicodeString& GetDefaultDownloadDirectory() const;
  /**
   * Defines a default location for all downloads.
   * If the path is not empty, the download prompt will never show
   * and all downloads will start automatically.
   * @param i_path
   *   An absolute path to an existing directory with write access.
   */
  void SetDefaultDownloadDirectory(const CATUnicodeString& i_path);
  /**
   * Returns 1 if the cache is used for HTTP requests.
   */
  int GetEnableCache() const;
  /**
   * Enable or disable caching for HTTP requests sent by the browser.
   * @param i_enable
   *   Set to 1 to enable, or 0 to disable.
   *   Disabling the cache is done through HTTP request headers (Cache-Control).
   * @note
   *   Default value is 1.
   *   Pre-existing cache is still preserved when this is disabled.
   */
  void SetEnableCache(const int i_enable);
  /**
   * Returns 1 if the browser allows user to grant or deny specific permissions.
   */
  int GetEnableUserPermissions();
  /**
   * Enable or disable basic principles for requesting permissions at runtime
   * when the user starts to interact with the feature that requires it.
   * @param i_enable
   *   Set to 1 to enable, or 0 to disable.
   *   Disabling requesting permissions at runtime.
   * @note
   *   Default value is 0.
   */
  void SetEnableUserPermissions(const int i_enable);

  /**
   * Returns the inner dimensions of the web viewer, i.e. the viewable area, including scrollbars.
   */
  void GetInnerDimensions(int& o_width, int& o_height) const;
  /**
   * Apply static dimensions to the inner web view to stop it from syncing with the dimensions
   * of this UI control and/or its parent window.
   * @param i_width i_height
   *   The static dimensions to apply to the inner web view, in pixels.
   * @note
   *   Default behavior is sync.
   *   After using this method, passing a null dimension will enable dimension sync again, e.g.
   *     - SetInnerDimensions(0, height);
   *     - SetInnerDimensions(width, 0);
   *     - SetInnerDimensions(0, 0);
   */
  void SetInnerDimensions(const int i_width, const int i_height);
  /**
   * Starts the pending download item in a temp location
   * and open it with the default application, depending on its extension.
   */
  void RunDownloadDialogOpen();
  /**
   * Starts the pending download item and save the file to a chosen location.
   * @param i_path
   *   An absolute path (including file name) to the save location.
   */
  void RunDownloadDialogSaveAs(const CATUnicodeString& i_path);
  /**
   * Cancels the pending download dialog.
   */
  void CancelDownloadDialog();
  /**
   * Cancels one download item.
   * @param i_id
   *   The identifier for the download item to cancel.
   */
  void CancelDownload(const uint32_t i_id);
  /**
   * Accept the permission request as an explicit user action.
   */
  void RunPermissionDialogAccept();
  /**
   * Deny the permission request as an explicit user action.
   */
  void RunPermissionDialogDeny();
  /**
   * Dismiss the permission request as an explicit user action.
   */
  void RunPermissionDialogDismiss();
  /**
   * Ignore the permission request.
   */
  void RunPermissionDialogIgnore();
  
  /**
   * Specifies if the webview visibility should be synchronized with this 
   * widget's Hide/Show status. The impact of this synchronization is not
   * negligeable as a hidden webview has acces to much less ressources than 
   * a visible one.
   * @param i_webview_synchronized_mode
   *   if true, the webview is synchronized with the hide status of this widget
   */
  void WebViewVisuMode(const bool i_webview_synchronized_mode);

  // Implemented in CATVidCtlWebViewer_record.cpp.
  /**
   * @name Record / Replay
   */
  /** @{ */

  int PreInteractionRecord(CATVidInteractionRecorderData&);
  void PostInteractionRecord(CATVidInteractionRecorderData&, const CATSYPProperties&);
  void InteractionReplay(CATVidInteractionReplayerData&);

  /** @} */

  /**
   * Returns 1 if popup windows are enabled.
   */
  WEBVIEWER_DEPRECATED(
    "GetPopupWindowsFlag is now deprecated. Please use GetPopupBehavior instead.",
    int GetPopupWindowsFlag() const);
  /**
   * See @ref GetPopupWindowsFlag.
   * @param i_allow
   *   Set to 1 to allow the browser to create popup windows (else set to 0).
   * @note
   *   Default value is 1.
   */
  WEBVIEWER_DEPRECATED(
    "SetPopupWindowsFlag is now deprecated. Please use SetPopupBehavior instead.",
    void SetPopupWindowsFlag(const int i_allow));
  /**
   * Adds a new scheme on which @ref CustomScheme events will be dispatched.
   * Use this if a non-standard scheme needs to be handled in a specific way.
   * @note
   *   If you wish to send large data or text containing non-ASCII characters from a web page,
   *   please use "multipart/form-data" as the form content type (the "enctype" attribute).
   *   The default content type is "application/x-www-form-urlencoded").
   *   More details on the data format for each type:
   * http://www.w3.org/TR/html401/interact/forms.html#form-content-type
   * @warning
   *   Don't include "://" when registering a new scheme.
   *   Don't try to register standard schemes, as it may lead to critical loading errors.
   *   Standard scheme examples (for protocols registered by the IANA): "http", "https", "ftp", etc.
   */
  WEBVIEWER_DEPRECATED(
    "Custom schemes are misused to transfer data by posting forms.\n"
    "Use the following JavaScript binding instead: dscef.sendString().",
    void AddCustomScheme(const CATUnicodeString& i_scheme));
  /**
   * @nodoc
   */
  WEBVIEWER_DEPRECATED(
    "Use SetAllowZoomFlag(const int) instead.", void SetDisableZoomFlag(const int));
  /**
   * @nodoc
   */
  WEBVIEWER_DEPRECATED(
    "GetLocale() doesn't do anything.\n"
    "Use CATNLSUtilities to get the current language.",
    CATUnicodeString GetLocale() const);
  /**
   * @nodoc
   */
  WEBVIEWER_DEPRECATED(
    "SetLocale() doesn't do anything.\n"
    "The browser will use the same language as the main application.",
    void SetLocale(const CATUnicodeString&));
  /**
   * @nodoc
   */
  WEBVIEWER_DEPRECATED(
    "GetUserAgent() doesn't do anything.", CATUnicodeString GetUserAgent() const);
  /**
   * @nodoc
   */
  WEBVIEWER_DEPRECATED(
    "SetUserAgent() doesn't do anything.", void SetUserAgent(const CATUnicodeString&));

  /**
   * @name Events
   * The events dispatched by @ref CATVidCtlWebViewer instances.
   */
  /** @{ */

  /**
   * Get the @c Abend event.
   *
   * The @c Abend event is dispatched when the browser has been terminated for an unknown reason
   * (subprocess crash) and doesn't respond anymore.
   * It's possible to handle these issues by reloading the page or navigating to another one.
   *
   * @par EventProperties
   *   - Name: @c "Abend"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return The event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent* Abend();
  /**
   * Get the @c Auth event.
   *
   * The @c Auth event is dispatched after an authentication attempt ends
   * in the native client.
   *
   * @par EventProperties
   *   - Name: @c "Auth"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidAuthEventArgs
   */
  static CATSYPEvent* Auth();
  /**
   * Get the @c ConsoleMessage event.
   *
   * The @c ConsoleMessage event is dispatched when the current document
   * uses the Console API to write information in the console.
   * The usual functions used for this are @c console.log() and @c console.info().
   *
   * If the origin is null, it means the console was used to execute the call.
   *
   * @par EventProperties
   *   - Name: @c "ConsoleMessage"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidJSMessageEventArgs
   *
   * @return The event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent* ConsoleMessage();
  /**
   * Get the @c ContextMenu event.
   *
   * The @c ContextMenu event is dispatched before a context menu is displayed.
   * It doesn't run synchronously after a right button click.
   *
   * Action groups will be displayed in the same order they were added to @c
   * CATVidWebContextMenuEventArgs instance. A separator item will be added between each group.
   *
   * @par EventProperties
   *   - Name: @c "ContextMenu"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidWebContextMenuEventArgs
   */
  static CATSYPEvent* ContextMenu();
   /**
   * Get the @c CustomScheme event.
   *
   * The @c CustomScheme event is dispatched when a registered
   * scheme is encountered by the browser while processing a load request.
   *
   * @par EventProperties
   *   - Name: @c "CustomScheme"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidLoadEventArgs
   *
   * @return The event instance. @c AddRef has NOT been called on the returned pointer.
   */
  WEBVIEWER_DEPRECATED(
    "The CustomScheme event has been deprecated.\n"
    "Instead, use the JSMessage event with CATVidJSMessageEventArgs parameters.",
    static CATSYPEvent* CustomScheme());
  /**
   * @nodoc
   */
  WEBVIEWER_DEPRECATED("Does not do anything.", static CATSYPEvent* DocumentSize());
  /**
   * Get the @c DOMReady event.
   *
   * The @c DOMReady event is dispatched when the entire DOM has been built.
   * This is based on the DOMContentLoaded event described in the HTML5 specs.
   *
   * @par EventProperties
   *   - Name: @c "DOMReady"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return The event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent* DOMReady();
  /**
   * Get the @c DownloadDialog event.
   *
   * The @c DownloadDialog event is dispatched when the download starts
   * and the browser needs to know what to do about it: save, cancel, etc.
   *
   * @par EventProperties
   *   - Name: @c "DownloadDialog"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidDownloadDialogEventArgs
   */
  static CATSYPEvent* DownloadDialog();
  /**
   * Get the @c DownloadProgress event.
   *
   * The @c DownloadProgress event is dispatched every time new progress info
   * is available for one download item: completion status, speed, etc.
   *
   * @par EventProperties
   *   - Name: @c "DownloadProgress"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidDownloadProgressEventArgs
   */
  static CATSYPEvent* DownloadProgress();
  /**
   * Get the @c JSMessage event.
   *
   * The @c JSMessage event is dispatched when one or multiple messages
   * are being pushed from the web view (JS) to the native controller (C++).
   *
   * The JavaScript function used to trigger this is @c dscef.sendString(...args).
   *
   * @par EventProperties
   *   - Name: @c "JSMessage"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidJSMessageEventArgs
   *
   * @return The event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent* JSMessage();
  /**
   * Get the @c LoadEnd event.
   *
   * The @c LoadEnd event is dispatched when the browser finished
   * loading a document or part(s) of a document.
   *
   * @par EventProperties
   *   - Name: @c "LoadEnd"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidLoadEventArgs
   *
   * @return The event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent* LoadEnd();
  /**
   * Get the @c LoadError event.
   *
   * The @c LoadError event is dispatched when an error occurs
   * while the browser is loading a resource.
   *
   * @par EventProperties
   *   - Name: @c "LoadError"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidLoadEventArgs
   *
   * @return The event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent* LoadError();
  /**
   * Get the @c LoadResourceError event.
   *
   * The @c LoadResourceError event is dispatched when an error occurs
   * while the browser is loading a resource.
   *
   * @par EventProperties
   *   - Name: @c "LoadResourceError"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidLoadEventArgs
   *
   * @return The event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent* LoadResourceError();
  /**
   * Get the @c LoadStart event.
   *
   * The @c LoadStart event is dispatched when the browser starts
   * loading a new document or part(s) of a document.
   *
   * @par EventProperties
   *   - Name: @c "LoadStart"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidLoadEventArgs
   *
   * @return The event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent* LoadStart();
  /**
   * Get the @c PermissionDialog event.
   *
   * The @c PermissionDialog event is dispatched when the permission request starts
   * and the browser needs to know what to do about it: accept, deny, dismiss or ignore.
   *
   * @par EventProperties
   *   - Name: @c "PermissionDialog"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidPermissionDialogEventArgs 
   */
  static CATSYPEvent* PermissionDialog();
  /**
   * Get the @c Start event.
   *
   * The @c Start event is dispatched when the browser has been created and is ready to use.
   *
   * @par EventProperties
   *   - Name: @c "Start"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return The event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent* Start();
  /**
   * Get the @c TitleUpdate event.
   *
   * The @c TitleUpdate event is dispatched when the title of the document
   * loaded in the browser has changed.
   *
   * @par EventProperties
   *   - Name: @c "TitleUpdate"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return The event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent* TitleUpdate();
  /**
   * Get the @c URLUpdate event.
   *
   * The @c URLUpdate event is dispatched when the address of the document
   * loaded in the browser has changed.
   *
   * @par EventProperties
   *   - Name: @c "URLUpdate"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidLoadEventArgs
   *
   * @return The event instance. @c AddRef has NOT been called on the returned pointer.
   */
  static CATSYPEvent* URLUpdate();
  /**
   * Get the @c ZoomUpdate event.
   *
   * The @c ZoomUpdate event is dispatched after the zoom level has changed.
   *
   * @par EventProperties
   *   - Name: @c "ZoomUpdate"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidZoomEventArgs
   */
  static CATSYPEvent* ZoomUpdate();

  /** @} */

  /** Event handlers. */
  /** @nodoc */
  void HandlePrevious(CATBaseUnknown*, CATSYPEventArgs*);
  /** @nodoc */
  void HandleForward(CATBaseUnknown*, CATSYPEventArgs*);
  /** @nodoc */
  void HandleRefresh(CATBaseUnknown*, CATSYPEventArgs*);
  /** @nodoc */
  void HandleStop(CATBaseUnknown*, CATSYPEventArgs*);
  /** @nodoc */
  void HandleHome(CATBaseUnknown*, CATSYPEventArgs*);
  /** @nodoc */
  void HandleLoad(CATBaseUnknown*, CATSYPEventArgs*);

protected:
  /**
   * @copydoc CATVidWidget#Update
   */
  virtual void Update();
  /**
   * @copydoc CATVidWidget#TunnelInformation
   */
  virtual void TunnelInformation(const CATVidInformation&);

private:
  // Grants access to the letter for private and protected methods.
  friend class l_CATVidCtlWebViewer;
  
  // Grants access to A2X CSI Function for private and protected methods.
  friend class A2XWebInWin;

  // Common initializer for constructors.
  void Init();

  // Event dispatchers.
  // Those that require feedback from the containing component return a boolean.

  void OnAbend();
  bool OnBeforeContextMenu();
  void OnConsoleMessage(MMW::ConsoleNotification*);
  void OnDOMReady();
  bool OnDownloadDialog(MMW::DownloadDialogNotification*);
  bool OnDownloadProgress(MMW::DownloadProgressNotification*);
  void OnHTTPError(MMW::HTTPErrorNotification*);
  void OnJSMessage(MMW::JSMessageNotification*);
  void OnLoad(MMW::LoadNotification*);
  void OnLoadError(MMW::LoadErrorNotification*);
  void OnLoadResourceError(MMW::LoadResourceErrorNotification*);
  void OnLogin(const bool);
  bool OnPermissionDialog(MMW::PermissionNotification*);
  void OnStart();
  void OnTitleUpdate(const CATUnicodeString&);
  void OnURLUpdate(const CATUnicodeString&);
  void OnZoomUpdate(const double);
  void OnWebRecord(MMW::WebRecordNotification*);

  // Download dialog event handlers.
  void OnDownloadDialogSave(CATCommand*, CATNotification*, CATCommandClientData);
  void OnDownloadDialogCancel(CATCommand*, CATNotification*, CATCommandClientData);
  
  void DispatchCustomScheme(MMW::JSMessageNotification*);
  void DispatchJSMessage(MMW::JSMessageNotification*);

  // File open dialog event handlers.
  void OnFileOpenDialogOK(CATCommand*, CATNotification*, CATCommandClientData);
  void OnFileOpenDialogCancel(CATCommand*, CATNotification*, CATCommandClientData);

  void DismissFileDialog(CATDlgFile*);

  bool HasEventHandlersFor(CATSYPEvent*);

  l_CATVidCtlWebViewer& _impl;

  // Only instantiated for Record ODTs (capture and replay).
  CATVidWebRecorderDelegate* _pRecorderDelegate;
};

#endif // CATVidCtlWebViewer_H
