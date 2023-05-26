//===================================================================
// COPYRIGHT Dassault Systèmes 2012-10-15
//===================================================================
// 2012-10-15 Creation: D6K
//===================================================================

#ifndef CATCefBrowser_H
#define CATCefBrowser_H

// ChromiumEmbedded
#include "CATCefBrowserLib.h"
#include "CATCefDefines.h"

// MultimediaInterfaces
#include "CATMM2DTypes.h"
#include "CATMMWebTypes.h"
// SpecialAPI
#include "CATSysErrorDef.h"
// SystemTS
#include "DSYString.h"
// UIVCoreTools
#include "CATSYPRefCounted.h"
// std
#include <functional>
#include <memory>
#include <stdint.h>

class CATBaseUnknown;
class CATPixelImage;
class CATCefEventManager;

typedef struct _catcefclient_c   catcefclient_c;

/**
 * Wrapping class for a CEF-based web browser.
 * @warning
 *   This API is to be used on the main application thread only.
 */
class ExportedByCATCefBrowserLib CATCefBrowser: public CATSYPRefCounted
{
public:
  /**
   * Constructors only initialize the CEF context.
   * You need to call CATCefBrowser::Build to start the browser.
   */
  CATCefBrowser(const CATUnicodeString& i_homeURL=CATUnicodeString(""));
  ~CATCefBrowser();

  static void InitContext();

  // ------------------------------------------------------------------------
  // "Classic" browser methods (also work in offscreen mode)
  // ------------------------------------------------------------------------

  /**
   * Creates a new instance of the browser.
   * @param i_parentWindowHandle
   *   The parent window handle.
   *   Leave it to NULL if the browser is offscreen.
   * @param i_rect
   *   The area where the view must be drawn.
   * @param i_renderMode
   *   The rendering mode: default or offscreen rendering.
   */
  HRESULT Build(const CATCefWindowHandle i_parentWindowHandle,
    const CATMM2D::Rect<int>& i_rect,
    const MMW::RenderingMode i_renderMode = MMW::RM_DEFAULT);
  /** Binds that wrapper to a browser that was not created by itself (e.g. the wrapper). */
  HRESULT BindTo(const int i_browserID);
  /** Loads a new URL in the browser. */
  HRESULT LoadURL(const CATUnicodeString&);
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
  HRESULT LoadContent(const CATUnicodeString& i_content, const CATUnicodeString& i_fakeURL);
  /** Loads the browser homepage. */
  HRESULT GoHome();
  /** @return true if the browser can go back in its navigation history. */
  bool CanGoBack();
  /** Loads the previous page in the browser history. */
  HRESULT GoBack();
  /** @return true if the browser can go forward in its navigation history. */
  bool CanGoForward();
  /** Loads the next page in the browser history. */
  HRESULT GoForward();
  /** Reloads the page in the browser. */
  HRESULT Reload();
  /** Reloads the page in the browser while ignoring what is in the cache. */
  HRESULT ReloadWithoutCache();
  /** Stops loading the page in the browser. */
  HRESULT StopLoading();
  /** Executes the "Copy" command in the browser. */
  HRESULT Copy();
  /** Executes the "Cut" command in the browser. */
  HRESULT Cut();
  /** Executes the "Paste" command in the browser. */
  HRESULT Paste();
  /** Executes the "Delete" command in the browser. */
  HRESULT Delete();
  /** Executes the "Select All" command in the browser. */
  HRESULT SelectAll();
  /** Executes the "Undo" command in the browser. */
  HRESULT Undo();
  /** Executes the "Redo" command in the browser. */
  HRESULT Redo();
  /** @return The URL of the current page. */
  const CATUnicodeString GetCurrentURL() const;
    
  /**
   * Runs the input string as JavaScript code in the browser current page 
   * before the page is loaded
   * @param i_code
   *   The JavaScript code to run in the browser.
   * @param i_origin
   *   The URL for the script. It will be displayed in the stack if an error happens.
   * @param i_line
   *   The starting line for the script. It will also be displayed in the stack.
   */
  HRESULT RunJavaScriptBeforePagesLoading(
    const CATUnicodeString& i_code, const CATUnicodeString& i_origin, const int i_line);

  /**
   * Runs the input string as JavaScript code in the browser current page.
   * @param i_code
   *   The JavaScript code to run in the browser.
   * @param i_origin
   *   The URL for the script. It will be displayed in the stack if an error happens.
   * @param i_line
   *   The starting line for the script. It will also be displayed in the stack.
   */
  HRESULT RunJavaScript(
    const CATUnicodeString& i_code, const CATUnicodeString& i_origin, const int i_line);
  /**
   * Runs the input string as JavaScript code in the browser current page
   * and provides an async result through the callback parameter.
   * @param i_code
   *   The JavaScript code to run in the browser.
   * @param i_origin
   *   The URL for the script. It will be displayed in DevTools if an error happens.
   *   It doesn't have to be a real URL, as long as it parses like an URL.
   *   It is mostly for determining if an error comes from code that was ran with this method.
   * @param i_line
   *   The starting line for the script. It will also be displayed in the stack.
   * @param i_callback
   *   The callback that will be executed with the result or the error from the code.
   */
  HRESULT EvalJavaScript(const CATUnicodeString& i_code,
    const CATUnicodeString& i_origin,
    const int i_line,
    std::unique_ptr<MMW::JSEvalCallback> i_callback);
  /** @return true if the browser was initialized with offscreen rendering mode. */
  bool OffscreenRenderingEnabled() const;
  /**
   * Registers a new custom URI scheme (or protocol).
   * A notification will be dispatched if a registered protocol is executed by the browser.
   */
  HRESULT RegisterCustomURIScheme(const CATUnicodeString&);
  /**
   * Sets a new zoom level on the browser current page.
   * @param
   *   The new zoom level. Default value (100%) is 0.0.
   */
  HRESULT SetZoomLevel(const double);
  /**
   * Increase or decrease the current browser zoom level.
   * @param i_delta
   *   The value to add to the current zoom level.
   */
  HRESULT ModifyZoomLevel(const double i_delta);
  /** @return The browser home page URL. */
  const CATUnicodeString GetHomeURL() const;
  /** Sets a new home page for the browser. */
  HRESULT SetHomeURL(const CATUnicodeString&);
  /**
   * @return
   *   The current maximum framerate, in frames per second.
   * @note
   *   Use only on an offscreen browser.
   */
  int GetMaxFramerate() const;
  /**
   * Sets a maximum framerate for the web view.
   * @note
   *   Use only on an offscreen browser.
   *   Valid values are between 1 and 60.
   * @param
   *   The maximum framerate for the web view, in frames per second.
   */
  HRESULT SetMaxFramerate(const int);
  /** @return true if JavaScript is enabled. */
  bool JavaScriptEnabled() const;
  /** Set to true to enable JavaScript use. */
  HRESULT SetJavaScriptEnabled(const bool);
  /** @return true if file access from file:// URLs is enabled. */
  bool FileAccessFromFileURLsEnabled() const;
  /** Set to true to enable file access from file:// URLs. */
  HRESULT SetFileAccessFromFileURLsEnabled(const bool);
  /** @return true if the same-origin policy is enforced. */
  bool SameOriginPolicyEnabled() const;
  /**
   * Set to true to enable same-origin policy.
   * @note
   *   It must be called before the Build method or it will have no effect.
   */
  HRESULT SetSameOriginPolicyEnabled(const bool);
  /**
   * @return
   *   true if mixed-content behavior is allowed, e.g. loading resources over
   *        HTTP from a page that was loaded over HTTPS.
   *   false (default) if it should be blocked and trigger errors.
   */
  bool InsecureContentAllowed() const;
  /** Set to true to allow mixed-content behavior. */
  HRESULT SetInsecureContentAllowed(const bool);
  /** @return true if plugins are enabled.
   * 
   * @deprecated("Stopped being relevant. Will be removed")
  */
  bool PluginsEnabled() const;
  /**
   * Set to true to allow plugins to launch in the browser.
   * @note
   *   It must be called before the Build method or it will have no effect.
   * @deprecated("Stopped being relevant. Will be removed")
   */
  HRESULT SetPluginsEnabled(const bool);
  /** @return The policy that is currently applied regarding the instantiation of popup windows. */
  MMW::PopupPolicy GetPopupPolicy() const;
  /**
   * Changes the policy regarding the instantiation of popup windows.
   * @param
   *   The new policy to apply.
   */
  HRESULT SetPopupPolicy(const MMW::PopupPolicy);
  /** @return true if the browser can display transparency in its viewport. */
  bool TransparencyEnabled() const;
  /** Set to true to enable transparency in the browser viewport. */
  HRESULT SetTransparencyEnabled(const bool);
  /** @return true if backward and forward navigation is enabled. */
  bool BackForwardEnabled() const;
  /** Set to true if the browser can navigate backward and forward through its navigation history.
   */
  HRESULT SetBackForwardEnabled(const bool);
  /** @return true if reloading the current page is enabled. */
  bool ReloadEnabled() const;
  /** Set to true if the browser can reload the current page. */
  HRESULT SetReloadEnabled(const bool);
  /** @return true if zoom changes are allowed. */
  bool ZoomEnabled() const;
  /** Set to true to allow zoom changes to be applied. */
  HRESULT SetZoomEnabled(const bool);
  /** @return true if disk cache is used for HTTP requests. */
  bool CacheEnabled() const;
  /** Set to true to enable caching for HTTP requests. */
  HRESULT SetCacheEnabled(const bool);
  /** @return true if notifications can be dispatched after every use of the Console API. */
  bool ConsoleMessageEventsEnabled() const;
  /** Set to true to allow the dispatch of console notifications. */
  HRESULT SetConsoleMessageEventsEnabled(const bool);
  /** @return true if focus is set on an editable DOM element like <input> or <textarea>. */
  bool HasFocusOnEditField() const;
  /** @return The default location for all downloads. */
  CATUnicodeString GetDefaultDownloadDirectory() const;
  /** Sets a new location for all future downloads. */
  HRESULT SetDefaultDownloadDirectory(const CATUnicodeString&);
  /** @return true if audio streams (i.e. microphones) can be queried for WebRTC. */
  bool AudioMediaStreamsEnabled() const;
  /** Set to true to enable audio streams for WebRTC. They are disabled by default. */
  HRESULT SetAudioMediaStreamsEnabled(const bool);
  /** @return true if video streams (i.e. webcams) can be queried for WebRTC. */
  bool VideoMediaStreamsEnabled() const;
  /** Set to true to enable video streams for WebRTC. They are disabled by default. */
  HRESULT SetVideoMediaStreamsEnabled(const bool);
  /** Creates a new window containing the developer tools. */
  HRESULT StartDevTools();
  /** Closes the developer tools window that was opened by this browser instance. */
  HRESULT CloseDevTools();

  /**
   * Cancels one ongoing download.
   * @param
   *   The identifier for the download item to cancel.
   */
  HRESULT CancelDownload(const uint32_t);

  /** Returns the browser event manager that dispatches callbacks from the offscreen browser. */
  CATBaseUnknown* GetEventManager() const;

  /**
   * Invalidates the specified rect and triggers a new draw on the texture.
   * - If offscreen rendering is enabled, it will notify a dirty rect area on the main texture that
   * requires an update.
   * - If window rendering is enabled, it will ignore the parameter and only notify the web view
   * that it is going to move and get resized.
   * @param
   *   Rect to invalidate and redraw.
   */
  HRESULT Invalidate(const CATMM2D::Rect<int>&);

  // ------------------------------------------------------------------------
  // Only offscreen browser methods (device events, callbacks...)
  // ------------------------------------------------------------------------

  /** Set to true to notify the browser it's hidden so it can stop rendering. */
  HRESULT SetHiddenState(const bool);
  /**
   * Returns the rendered image from the offscreen browser
   * and locks its mutex so the image stays untouched while
   * the embedder is using it.
   * @warning
   *   The embedder is responsible for unlocking the mutex.
   * @return
   *   The rendered image from the offscreen browser.
   */
  CATPixelImage* GetSafePixelImage() const;
  /**
   * Unlocks the mutex in the offscreen browser.
   * Call this method if GetSafePixelImage() was used.
   */
  void Unlock();
  /**
   * Gets the browser view size.
   * @param o_width
   *   The browser width.
   * @param o_height
   *   The browser height.
   */
  HRESULT GetSize(int& o_width, int& o_height) const;
  /**
   * Resizes the browser view area where the web page is rendered.
   * @param i_width
   *   The new browser width.
   * @param i_height
   *   The new browser height.
   */
  HRESULT SetSize(const int i_width, const int i_height);
  /**
   * Returns the ratio that scales physical pixels to logical pixels.
   */
  float GetDevicePixelRatio() const;
  /**
   * Defines the ratio that scales physical pixels to logical pixels.
   * For example, with physical dimensions of 800x600 and a ratio of 1.25,
   * texture buffers should come with 1000x750 pixels.
   * @note
   *   Use only on an offscreen browser.
   *   Default value is 1.
   */
  HRESULT SetDevicePixelRatio(const float);
  /**
   * Sends a focus event to the browser.
   * @note
   *   Use only on an offscreen browser.
   * @param
   *   true if the browser gains focus.
   *   false if it loses focus.
   */
  HRESULT SendFocusEvent(const bool);
  
  /**
   * Sends the keyboard event to the browser.
   * @note
   *   Use only on an offscreen browser.
   * @param i_keyType
   *   The key type (up, down, etc.).
   * @param i_keyCode
   *   The key code matching the event.
   *   On Windows, send the VK code.
   * @param i_modifiers
   *   The key modifiers (CTRL, SHIFT, etc.).
   */
  HRESULT SendKeyEvent(const MMW::KeyEvent i_keyType);
  
  /**
   * Sends the mouse click event to the browser.
   * @note
   *   Use only on an offscreen browser.
   * @param i_x
   *   The horizontal coordinate of the mouse event.
   * @param i_y
   *   The vertical coordinate of the mouse event.
   * @param i_mouseButton
   *   The clicked mouse button.
   * @param i_mouseButtonState
   *   It indicates if the mouse button is being pressed or released.
   * @param i_clickCount
   *   The actual number of clicks this event must be accounted for.
   */
  HRESULT SendMouseClickEvent(const int i_x,
    const int i_y,
    const MMW::MouseButton i_mouseButton,
    const MMW::MouseButtonState i_mouseButtonState,
    const int i_clickCount);
  /**
   * Sends the mouse move event to the browser.
   * @note
   *   Use only on an offscreen browser.
   * @param i_x
   *   The horizontal coordinate of the mouse event.
   * @param i_y
   *   The vertical coordinate of the mouse event.
   * @param i_leave
   *   If true, indicates that the cursor is leaving the browser view area.
   */
  HRESULT SendMouseMoveEvent(const int i_x, const int i_y, const bool i_leave);
  /**
   * Sends the mouse scroll event to the browser.
   * @note
   *   Use only on an offscreen browser.
   * @param i_x
   *   The horizontal coordinate of the mouse event.
   * @param i_y
   *   The vertical coordinate of the mouse event.
   * @param i_deltaX
   *   The horizontal scroll delta value.
   * @param i_deltaY
   *   The vertical scroll delta value.
   */
  HRESULT SendMouseScrollEvent(
    const int i_x, const int i_y, const int i_deltaX, const int i_deltaY);
  /**
   * Sends a multi-touch event.
   * @param
   * All touch points with their own type and coordinates.
   */
  HRESULT SendMultiTouchEvent(const std::vector<MMW::Touch>&);
  /**
   * Sends a response for the last JS dialog box.
   * @param i_accept
   *   true if the user validated the message.
   *   false if the user dismissed it.
   * @param i_userInput
   *   Only relevant if a JS prompt dialog was displayed, asking for user input.
   */
  HRESULT SendJSDialogResponse(const bool i_accept, const CATUnicodeString& i_userInput);
  /**
   * Sends a response for the download dialog box.
   * @param
   *   The user response. Usually "open", "save as" or "cancel".
   */
  HRESULT SendDownloadDialogResponse(
    const MMW::DownloadDialogResponse, const CATUnicodeString& i_downloadPath = "");
  /**
   * Sends the index for the certificate to select for a pending request demanding authentication.
   * @param i_id
   *   The unique identifier for the callback to execute.
   * @param i_index
   *   The index of the selected certificate from the list that was sent with
   * ClientCertificateSelectionNotification. Send a negative number to cancel the request.
   */
  HRESULT SendCertificateSelection(const int i_id, const int i_index);
  /**
   * Notifies the browser the drag&drop operation ended with the successful drop.
   * @param i_x i_y
   *   Coordinates where the drag ended.
   * @param i_appliedDragMode
   *   The operation that was applied (move, copy, link...).
   */
  HRESULT DragEndedAt(const int i_x, const int i_y, const MMW::DragModeFlag i_appliedDragMode);
  /**
   * Notifies the browser a drag motion entered its web view.
   * @param i_pDragData
   * @param i_mouseEvent
   * @param i_allowedDragModes
   */
  HRESULT DragEnter(void* i_pDragData,
    const MMW::MouseEvent& i_mouseEvent,
    const MMW::DragModeMask i_allowedDragModes);
  /**
   * Notifies the browser a drag motion left its web view.
   * @param i_x i_y
   *   Coordinates where the drag left the web view.
   */
  HRESULT DragLeave(const int i_x, const int i_y);
  /**
   * Notifies the browser a drag motion is hovering its web view.
   * @param i_mouseEvent
   * @param i_allowedDragModes
   */
  HRESULT DragOver(const MMW::MouseEvent& i_mouseEvent, const MMW::DragModeMask i_allowedDragModes);
  /**
   * Notifies the browser a drop occurred on its web view.
   * @param i_mouseEvent
   *   The drop coordinates.
   */
  HRESULT Drop(const MMW::MouseEvent& i_mouseEvent);
  /**
   * Returns a pointer to the current drag data object.
   */
  void* GetCurrentDragData() const;
  /**
   * Returns the current drag operation.
   */
  MMW::DragModeFlag GetCurrentDragMode() const;
  /**
   * Returns true if the web view is handling a drag operation.
   */
  bool IsDragging() const;
  /**
   * Triggers a replay for a given interaction on a webapp.
   * @param
   *   The record data describing the web interaction to replay.
   *   Should be a JSON string.
   * @return
   *   The result for this interaction replay.
   *   .code == 0 means success while others mean failure.
   *   .message should contain a short description of the error in case of failure.
   */
  MMW::ReplayResult Replay(const CATUnicodeString& i_recordData);

  /**
   * Registers a callback that will be called right before the internal browser instance is
   * destroyed with all its dependencies (e.g. event handlers, settings, state, etc).
   * @note
   *   The callback will be executed on a worker thread (UI thread for CEF).
   * @return
   *   Total number of callbacks after this one is added.
   */
  size_t AddCloseCallback(const std::function<void()>&);

private:
  CATCefBrowser(const CATCefBrowser&) = delete;
  CATCefBrowser& operator=(const CATCefBrowser&) = delete;

  // Handles all the calls to the CEF API.
  // Using a pointer for forward declaration and avoid exposing CEF headers.
  catcefclient_c        * _pClient;
  
  // Event dispatcher for System's CATNotifications
  CATCefEventManager    * _pNotificationsDispatcher;
  
  // true if the browser is using offscreen mode.
  bool _offscreenEnabled = false;
};

#endif
