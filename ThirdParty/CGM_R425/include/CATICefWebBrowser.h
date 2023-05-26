//===================================================================
// COPYRIGHT Dassault Systemes 2013-09-19
//===================================================================
// 2013-09-19 Creation: D6K
//===================================================================

#ifndef CATICefWebBrowser_H
#define CATICefWebBrowser_H

// MultimediaInterfaces
#include "CATMM2DTypes.h"
#include "CATMMWebTypes.h"

// SpecialAPI
#include "CATSysErrorDef.h"

// SystemTS
#include "DSYString.h"
#include "DSYSysRefCounter.h"

// std
#include <stdint.h>

class CATPixelImage;
class CATBaseUnknown;
class CATICefWebBrowser;

typedef CATICefWebBrowser* (*CefWebBrowserFactory)();

/**
 * Web browser interface exposing methods for common actions,
 * such as loading URLs, refreshing a page, etc.
 */
class CATICefWebBrowser
{
public:
  ///////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////
  //          CTOR & DTOR
  ///////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////
  CATICefWebBrowser() {}
  virtual ~CATICefWebBrowser() {}

  ///////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////
  //          From CATIWebBrowser.h
  ///////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////

  // ------------------------------------------------------------------------
  // Browser methods for both dialog and offscreen mode
  // ------------------------------------------------------------------------

  // One of these build methods must be called to start the web browser.

  /**
   * Initializes the browser for a dialog context.
   * @param i_pParentWindowHandle
   *   The parent window handle.
   * @param i_width
   *   The width of the view.
   * @param i_height
   *   The height of the view.
   */
  virtual HRESULT BuildDialogBrowser(
    void* i_pParentWindowHandle, const int i_width, const int i_height) = 0;
  /**
   * @return
   *   The URL of the current frame.
   */
  virtual CATUnicodeString GetCurrentUrl() const = 0;
  
  /**
   * @return
   *   The browser home page URL.
   */
  virtual CATUnicodeString GetHomeUrl() const = 0;
  
  /**
   * Sets a new home page for the browser.
   */
  virtual HRESULT SetHomeURL(const CATUnicodeString&) = 0;
  /**
   * Sets a new zoom level on the browser current page.
   * @param i_zoomLevel
   *   The new zoom level. Default value (100%) is 0.0.
   */
  virtual HRESULT SetZoomLevel(const double i_zoomLevel) = 0;
  /**
   * Increase or decrease the current browser zoom level.
   * @param i_delta
   *   The value to add to the current zoom level.
   */
  virtual HRESULT ModifyZoomLevel(const double i_delta) = 0;
  /**
   * @return
   *   true if focus is set on an editable DOM element like <input> or <textarea>.
   *   false if focus is set on a non-editable DOM element or if the page is not focused at all.
   */
  virtual bool HasFocusOnEditField() const = 0;
  /**
   * @return
   *   The default location for all downloads.
   *   If it is not empty, all downloads will start automatically
   *   and they will be saved at that location.
   */
  virtual CATUnicodeString GetDefaultDownloadDir() const = 0;
  
  /**
   * Sets a new default location for all future downloads.
   * @param i_path
   *   An absolute path to a valid directory (exists and has write access).
   */
  virtual HRESULT SetDefaultDownloadDirectory(const CATUnicodeString& i_path) = 0;
  /**
   * Loads a new page in the browser.
   * @param
   *   The URL to load.
   */
  virtual HRESULT LoadURL(const CATUnicodeString&) = 0;
  /**
   * Loads the contents of the string parameter in the browser.
   * @param i_content
   *   The string content to load.
   * @param i_fakeURL
   *   The fake URL that will be affected to that content.
   */
  virtual HRESULT LoadContent(
    const CATUnicodeString& i_content, const CATUnicodeString& i_fakeURL) = 0;
  /**
   * Loads the browser home page.
   */
  virtual HRESULT GoHome() = 0;
  /**
   * Returns true if the browser can load the previous page in the browser history.
   * @return
   *   true if there is at least one page back in the browser history.
   *   false if there is not.
   */
  virtual bool CanGoBack() = 0;
  /**
   * Loads the previous page in the browser history.
   * Does nothing if there is no previous page.
   */
  virtual HRESULT GoBack() = 0;
  /**
   * Returns true if the browser can load the next page in the browser history.
   * @return
   *   true if there is at least one page forward in the browser history.
   *   false if there is not.
   */
  virtual bool CanGoForward() = 0;
  /**
   * Loads the next page in the browser history.
   * Does nothing if there is no next page.
   */
  virtual HRESULT GoForward() = 0;
  /**
   * Reloads the current page in the browser.
   */
  virtual HRESULT Reload() = 0;
  /**
   * Reloads the current page in the browser while ignoring what is in the cache.
   */
  virtual HRESULT ReloadWithoutCache() = 0;
  /**
   * Stops loading the page in the browser.
   */
  virtual HRESULT StopLoading() = 0;
  /**
   * Executes the "Copy" command in the browser.
   */
  virtual HRESULT Copy() = 0;
  /**
   * Executes the "Cut" command in the browser.
   */
  virtual HRESULT Cut() = 0;
  /**
   * Executes the "Paste" command in the browser.
   */
  virtual HRESULT Paste() = 0;
  /**
   * Executes the "Delete" command in the browser.
   */
  virtual HRESULT Delete() = 0;
  /**
   * Executes the "Select All" command in the browser.
   */
  virtual HRESULT SelectAll() = 0;
  /**
   * Executes the "Undo" command in the browser.
   */
  virtual HRESULT Undo() = 0;
  /**
   * Executes the "Redo" command in the browser.
   */
  virtual HRESULT Redo() = 0;
  
  /**
   * Executes JavaScript code before each page loading.
   * @param i_jsCode
   *   The JavaScript code to run.
   * @param i_origin
   *   The url for the script. It will be displayed in the stack if an error happens.
   * @param i_line
   *   The starting line for the script. It will also be displayed in the stack.
   * @warning
   *   Make sure the widget is NOT YET built (@ref Build()) before using this method.
   */
  virtual HRESULT RunJavaScriptBeforePagesLoading(const CATUnicodeString& i_jsCode, const CATUnicodeString& i_origin, const int i_line) 
  { return E_NOTIMPL;}
  
  /**
   * Runs the input string as JavaScript code in the browser current page.
   * @param i_code
   *   The JavaScript code to run in the browser.
   * @param i_origin
   *   The url for the script. It will be displayed in the stack if an error happens.
   * @param i_line
   *   The starting line for the script. It will also be displayed in the stack.
   */
  virtual HRESULT RunJavaScript(
    const CATUnicodeString& i_code, const CATUnicodeString& i_origin, const int i_line) = 0;
  /**
   * Registers a new custom scheme in the browser.
   * The browser must dispatch a callback if it loads a request with one
   * of the registered schemes.
   * @param
   *   The scheme to register.
   */
  virtual HRESULT RegisterCustomURIScheme(const CATUnicodeString&) = 0;
  /**
   * Creates a new window containing the developer tools.
   */
  virtual HRESULT StartDevTools() = 0;
  /**
   * Closes the developer tools window if there is one for this browser instance.
   */
  virtual HRESULT CloseDevTools() = 0;

  /**
   * Returns the browser event manager that dispatches callbacks from the offscreen browser.
   */
  virtual CATBaseUnknown* GetEventManager() const = 0;

  /**
   * Cancels one ongoing download.
   * @param i_id
   *   The identifier for the download item to cancel.
   */
  virtual HRESULT CancelDownload(const uint32_t i_id) = 0;
  /**
   * Sends a response for the JS dialog box that was just displayed by the browser.
   * @param i_accept
   *   true if the user validated the message.
   *   false if the user dismissed it.
   * @param i_userInput
   *   This string can be filled in case of user input in a JS prompt window.
   */
  virtual HRESULT SendJSDialogResponse(
    const bool i_accept, const CATUnicodeString& i_userInput = "") = 0;
  /**
   * Sends a response for the download dialog box that was just displayed by the browser.
   * @param i_response
   *   The response from the user.
   * @param i_downloadPath
   *   The location where the downloaded file should be saved.
   */
  virtual HRESULT SendDownloadDialogResponse(
    const MMW::DownloadDialogResponse, const CATUnicodeString& i_downloadPath = "") = 0;
  /**
   * Sends the index for the certificate to select for a pending request demanding authentication.
   * @param i_id
   *   The unique identifier for the callback to execute.
   * @param i_index
   *   The index of the selected certificate from the list that was sent with
   *   ClientCertificateSelectionNotification.
   *   Send a negative number to cancel the request.
   */
  virtual HRESULT SendCertificateSelection(const uint64_t i_id, const int i_index) = 0;

  /**
   * Triggers a replay for a given interaction on a webapp.
   * @param
   *   The record data describing the web interaction to replay.
   *   Should be a JSON string.
   */
  virtual MMW::ReplayResult Replay(const CATUnicodeString& i_recordData) = 0;

  ///////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////
  //         From CATWebOffscreenBrowser.h
  ///////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////
  /**
   * Initializes the browser for an offscreen context.
   * @note
   *   Suitable when the browser has its own dialog window.
   * @param i_pParentWindowHandle
   *   The parent window handle, if the browser has its own dialog window.
   *   Else, don't use the parameter or set it to nullptr.
   * @param i_width
   *   The width of the view.
   * @param i_height
   *   The height of the view.
   */
  virtual HRESULT BuildOffscreenBrowser(void* i_pParentWindowHandle = nullptr) { return S_OK; }
  /**
   * Binds that wrapper to a browser that was not created by itself.
   * @param i_browserID
   *   Identifier of the browser to bind.
   */
  virtual HRESULT BindOffscreenBrowser(const int i_browserID) { return S_OK; }
  /**
   * @return
   *   The current maximum framerate, in frames per second.
   * @note
   *   Use only on an offscreen browser.
   */
  virtual int GetMaxFramerate() const { return 0; }
  /**
   * Sets a maximum framerate for the web view.
   * @param
   *   The maximum framerate, in frames per second.
   * @note
   *   Use only on an offscreen browser.
   */
  virtual HRESULT SetMaxFramerate(const int) { return S_OK; }
  /**
   * Returns the rendered image from the offscreen browser.
   * @note
   *   Use only on an offscreen browser.
   * @return
   *   The rendered image from the offscreen browser.
   */
  virtual CATPixelImage* GetPixelImage() const { return nullptr; }
  /**
   * Returns the rendered image from the offscreen browser
   * and locks its mutex so the image stays untouched while
   * the embedder is using it.
   * @warning
   *   The embedder is responsible for unlocking the mutex.
   * @return
   *   The rendered image from the offscreen browser.
   */
  virtual CATPixelImage* GetSafePixelImage() const { return nullptr; }
  /**
   * Unlocks the mutex in the offscreen browser.
   * Call this method if GetSafePixelImage() was used.
   */
  virtual void UnlockPixelImage() {}
  virtual void Unlock() {} // deprecated
  /**
   * Returns a timestamp for the latest texture grabbed from the offscreen browser.
   */
  virtual int64_t GetImageTimestamp() const { return 0; }
  /**
   * Gets the browser view size.
   * @note
   *   Use only on an offscreen browser.
   * @param o_width
   *   The browser width.
   * @param o_height
   *   The browser height.
   */
  virtual HRESULT GetSize(int& o_width, int& o_height) const { return S_OK; }
  /**
   * Resizes the browser view area where the web page is rendered.
   * @note
   *   Use only on an offscreen browser.
   * @param i_width
   *   The new browser width.
   * @param i_height
   *   The new browser height.
   */
  virtual HRESULT SetSize(const int i_width, const int i_height) { return S_OK; }
  /**
   * Returns the ratio that scales physical pixels to logical pixels.
   */
  virtual float GetDevicePixelRatio() const { return 1.f; }
  /**
   * Defines the ratio that scales physical pixels to logical pixels.
   * For example, with physical dimensions of 800x600 and a ratio of 1.25,
   * texture buffers should come with 1000x750 pixels.
   * @note
   *   Use only on an offscreen browser.
   *   Default value is 1.
   */
  virtual HRESULT SetDevicePixelRatio(const float) { return S_OK; }
  /**
   * Gets the browser position (top left corner).
   * @note
   *   Use only on an offscreen browser.
   * @param o_x
   *   The browser horizontal coordinate.
   * @param o_y
   *   The browser vertical coordinate.
   */
  virtual HRESULT GetPosition(int& o_x, int& o_y) const { return S_OK; }
  /**
   * Sets the absolute position of the browser (top left corner).
   * It is useful if right-click menus are handled by the OS.
   * @note
   *   Use only on an offscreen browser.
   * @param i_x
   *   The new browser horizontal coordinate.
   * @param i_y
   *   The new browser vertical coordinate.
   */
  virtual HRESULT SetPosition(const int i_x, const int i_y) { return S_OK; }
  /**
   * Invalidates the specified area and triggers a new draw on the texture.
   * @note
   *   Use only on an offscreen browser.
   * @param
   *   The area that needs to be redrawn.
   */
  virtual HRESULT Invalidate(const CATMM2D::Rect<int>&) { return S_OK; }
  /**
   * Set to true to notify the browser it's hidden so it can stop rendering.
   */
  virtual HRESULT SetHiddenState(const bool) { return S_OK; }
  /**
   * Sends a focus event to the browser.
   * @note
   *   Use only on an offscreen browser.
   * @param i_focus
   *   true if the browser gains focus.
   *   false if it loses focus.
   */
  virtual HRESULT SendFocusEvent(const bool i_focus = true) { return S_OK; }
  /**
   * Sends the keyboard event to the browser.
   * @note
   *   Use only on an offscreen browser.
   * @param i_keyType
   *   Legal values are:
   *     - KEY_DOWN: pressed a non-character key.
   *     - KEY_UP: released a non-character key.
   *     - KEY_CHAR: pressed a character key.
   * @param i_keyCode
   *   The key code matching the event.
   *   On Windows, send the VK code.
   * @param i_modifiers
   *   The key modifiers.
   *   Use flags:
   *     - CTRL  == 0x01
   *     - ALT   == 0x02
   *     - SHIFT == 0x04
   */
  virtual HRESULT SendKeyEvent(const MMW::KeyEvent iEvt)
  {
  	int kCode = (iEvt.vkCode!=0) ? (iEvt.vkCode) : (iEvt.charCode);
    return SendKeyEvent(iEvt.type,kCode,iEvt.modifiers);
  }
  virtual HRESULT SendKeyEvent(const MMW::KeyType, const int i_keyCode, const int i_modifiers)
  {
    return S_OK;
  }
  /**
   * Sends the mouse click event to the browser.
   * @note
   *   Use only on an offscreen browser.
   * @param i_x i_y
   *   The coordinates of the mouse event.
   * @param i_mouseButton
   *   The clicked mouse button.
   *   Legal values are: MOUSE_LEFT, MOUSE_MIDDLE, MOUSE_RIGHT.
   * @param i_mouseButtonState
   *   It indicates if the mouse button is being pressed or released.
   *   Legal values are: MOUSE_UP, MOUSE_DOWN.
   * @param i_clickCount
   *   The actual number of clicks this event must be accounted for.
   */
  virtual HRESULT SendMouseClickEvent(const int i_x,
    const int i_y,
    const MMW::MouseButton,
    const MMW::MouseButtonState,
    const int i_clickCount)
  {
    return S_OK;
  }
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
  virtual HRESULT SendMouseMoveEvent(const int i_x, const int i_y, const bool i_leave = false)
  {
    return S_OK;
  }
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
  virtual HRESULT SendMouseScrollEvent(
    const int i_x, const int i_y, const int i_deltaX, const int i_deltaY)
  {
    return S_OK;
  }
  /**
   * Sends a multi-touch event.
   * @param i_touches
   * All touch points with their own type and coordinates.
   */
  virtual HRESULT SendMultiTouchEvent(const std::vector<MMW::Touch>& i_touches) { return S_OK; }
  /**
   * Drag source method: signals the drag ended, successfully or not.
   * @param i_x i_y
   *   Coordinates where the drag ended, relative to the web view origin (upper left corner).
   * @param i_appliedDragMode
   *   The drag effect that was applied.
   */
  virtual HRESULT DragEndedAt(
    const int i_x, const int i_y, const MMW::DragModeFlag i_appliedDragMode)
  {
    return S_OK;
  }
  /**
   * Drag target method: signals a drag entering the web view.
   * @param i_pDragData
   *   The data object that is being dragged into the web view.
   * @param i_mouseEvent
   *   Current key modifiers and the coordinates of the mouse cursor, relative to the
   *   web view origin.
   * @param i_allowedDragModes
   *   The drag effects that can be applied.
   */
  virtual HRESULT DragEnter(void* i_pDragData,
    const MMW::MouseEvent& i_mouseEvent,
    const MMW::DragModeMask i_allowedDragModes)
  {
    return S_OK;
  }
  /**
   * Drag target method: signals a drag leaving the web view.
   * @param i_x i_y
   *   Coordinates where the drag left the web view, relative to the upper left corner.
   */
  virtual HRESULT DragLeave(const int i_x, const int i_y) { return S_OK; }
  /**
   * Drag target method: signals a drag moving over the web view.
   * @param i_mouseEvent
   *   Current key modifiers and the coordinates of the mouse cursor, relative to the
   *   web view origin.
   * @param i_allowedDragModes
   *   The drag effects that can be applied.
   */
  virtual HRESULT DragOver(
    const MMW::MouseEvent& i_mouseEvent, const MMW::DragModeMask i_allowedDragModes)
  {
    return S_OK;
  }
  /**
   * Drag target method: signals a drop occuring inside the web view.
   * @param
   *   Current key modifiers and the coordinates of the mouse cursor, relative to the
   *   web view origin.
   */
  virtual HRESULT Drop(const MMW::MouseEvent&) { return S_OK; }
  /**
   * Returns a pointer to the current drag data object.
   */
  virtual void* GetCurrentDragData() const { return nullptr; }
  /**
   * Returns the current drag mode (i.e. the accepted drop operation).
   */
  virtual MMW::DragModeFlag GetCurrentDragMode() const { return MMW::DRAG_NONE; }
  /**
   * Returns true if the web view is handling a drag operation.
   */
  virtual bool IsDragging() const { return false; }

  // @deprecated Duplicate with SendDownloadDialogResponse
  // TODO: To be removed after CATCefBrowser migrates.
  virtual HRESULT RunDownloadDialog(
    const MMW::DownloadDialogResponse, const CATUnicodeString& i_path = "")
  {
    return S_OK;
  }

  ///////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////
  //         From CATWebSettingManager.h
  ///////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////
  /**
   * Returns true if the browser is using offscreen rendering.
   * @return
   *   true if the browser was started in offscreen mode.
   *   false if it was not.
   */
  virtual bool OffscreenRenderingEnabled() const { return false; }
  /**
   * @return
   *   true if JavaScript is enabled.
   *   false if it is disabled.
   */
  virtual bool JavaScriptEnabled() const { return true; }
  /**
   * Set to true to enable JavaScript use.
   */
  virtual HRESULT SetJavaScriptEnabled(const bool) { return S_OK; }
  /**
   * @return
   *   true if file access from file:// URLs is enabled.
   *   false if it is disabled.
   */
  virtual bool FileAccessFromFileURLsEnabled() const { return false; }
  /**
   * Set to true to enable file access from file:// URLs.
   * @note
   *   It must be called before the Build method or it will have no effect.
   */
  virtual HRESULT SetFileAccessFromFileURLsEnabled(const bool) { return S_OK; }
  /**
   * @return
   *   true if the same-origin policy is enforced.
   *   false if it is not.
   */
  virtual bool SameOriginPolicyEnabled() const { return true; }
  /**
   * Set to true to enable same-origin policy.
   * @note
   *    It must be called before the Build method or it will have no effect.
   */
  virtual HRESULT SetSameOriginPolicyEnabled(const bool) { return S_OK; }
  /**
   * @return
   *   true if mixed-content behavior is allowed, e.g. loading resources over
   *        HTTP from a page that was loaded over HTTPS.
   *   false (default) if it should be blocked and trigger errors.
   */
  virtual bool InsecureContentAllowed() const { return false; }
  /**
   * Set to true to allow mixed-content behavior.
   */
  virtual HRESULT SetInsecureContentAllowed(const bool) { return S_OK; }
  /**
   * @return
   *   true if plugins are enabled.
   *   false if they are disabled.
   */
  virtual bool PluginsEnabled() const { return false; }
  /**
   * Set to true to allow plugins to launch in the browser.
   */
  virtual HRESULT SetPluginsEnabled(const bool) { return S_OK; }
  /**
   * @deprecated
   * @return
   *   true if popup window creation is allowed.
   *   false if popup windows are blocked.
   */
  virtual bool PopupWindowsEnabled() const { return true; }
  /**
   * @deprecated
   * Set to true to allow popup windows to be created by the browser.
   */
  virtual HRESULT SetPopupWindowsEnabled(const bool) { return S_OK; }
  /**
   * @return
   *   The policy that is currently applied to the creation of popup windows.
   */
  virtual MMW::PopupPolicy GetPopupPolicy() const { return MMW::POP_DEFAULT; }
  /**
   * Change the policy to be applied on requests to open popup windows.
   */
  virtual HRESULT SetPopupPolicy(const MMW::PopupPolicy) { return S_OK; }
  /**
   * @return
   *   true if the browser can display transparency in its viewport.
   *   false if the browser only displays opaque colors.
   */
  virtual bool TransparencyEnabled() const { return false; }
  /**
   * Set to true to enable transparency in the browser viewport.
   */
  virtual HRESULT SetTransparencyEnabled(const bool) { return S_OK; }
  /**
   * @return
   *   true if backward and forward navigation is enabled.
   *   false if it is disabled.
   */
  virtual bool BackForwardEnabled() const { return true; }
  /**
   * Set to true to enable backward and forward navigation.
   */
  virtual HRESULT SetBackForwardEnabled(const bool) { return S_OK; }
  /**
   * @return
   *   true if reloading the current page is enabled.
   *   false if it is disabled.
   */
  virtual bool ReloadEnabled() const { return true; }
  /**
   * Set to true to enable reloading the current page.
   */
  virtual HRESULT SetReloadEnabled(const bool) { return S_OK; }
  /**
   * @return
   *   true if zoom changes can be applied.
   *   false if they cannot.
   */
  virtual bool ZoomEnabled() const { return true; }
  /**
   * Set to true to enable zoom changes.
   */
  virtual HRESULT SetZoomEnabled(const bool) { return S_OK; }
  /**
   * @return
   *   true if cache is used for HTTP requests.
   *   false if cache is ignored for HTTP requests.
   */
  virtual bool CacheEnabled() const { return true; }
  /**
   * Set to true to enable HTTP cache usage.
   */
  virtual HRESULT SetCacheEnabled(const bool) { return S_OK; }
  /**
   * This doesn't actually enable or disable the console output.
   * It only affects the dispatch of MMW::ConsoleNotification.
   * @note
   *   This is necessary mostly because lots of people have an excessive
   *   use of console.log() in their JS programs.
   * @return
   *   true if console notifications can be dispatched.
   *   false if they cannot.
   */
  virtual bool ConsoleMessageEventsEnabled() const { return false; }
  /**
   * Set to true to enable the dispatch of notifications after every use of the Console API.
   */
  virtual HRESULT SetConsoleMessageEventsEnabled(const bool) { return S_OK; }
  /**
   * @return
   *   true if access to audio media streams (microphones) is allowed for WebRTC.
   *   false (default) if access is denied.
   */
  virtual bool AudioMediaStreamsEnabled() const { return false; }
  /**
   * Set to true to allow access to audio media streams (microphones) for WebRTC.
   */
  virtual HRESULT SetAudioMediaStreamsEnabled(const bool) { return S_OK; }
  /**
   * @return
   *   true if access to video media streams (webcams) is allowed for WebRTC.
   *   false (default) if access is denied.
   */
  virtual bool VideoMediaStreamsEnabled() const { return false; }
  /**
   * Set to true to allow access to video media streams (webcams) for WebRTC.
   */
  virtual HRESULT SetVideoMediaStreamsEnabled(const bool) { return S_OK; }

  /**
   * Runs the input string as JavaScript code in the browser current page.
   * @param i_code
   *   The JavaScript code to run in the browser.
   * @param i_origin
   *   The url for the script. It will be displayed in the stack if an error happens.
   * @param i_line
   *   The starting line for the script. It will also be displayed in the stack.
   * @param i_callback
   *   Callbacks for eval result and error gathered in the same object.
   */
  virtual HRESULT EvalJavaScript(const CATUnicodeString& i_code,
    const CATUnicodeString& i_origin,
    const int i_line,
    std::unique_ptr<MMW::JSEvalCallback> i_callback)
  {
    return S_OK;
  }
};

#endif
