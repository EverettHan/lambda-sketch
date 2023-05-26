// COPYRIGHT DASSAULT SYSTEMES 2015

#ifndef CATCefPlugin_Defines_H
#define CATCefPlugin_Defines_H

#if defined(_WINDOWS_SOURCE)
#define catcefpluginwindowhandle_c HWND
#elif defined(_LINUX_SOURCE)
#define catcefpluginwindowhandle_c unsigned long
#endif

extern "C" {

   // States of Native Record when it is enabled and running.
  enum catceftypes_recordmode {
    // Default mode.
    // - On the main process: native Record is not running.
    // - On a subprocess: native Record is not running or WebRecord should be ignored.
    UNKNOWN = 0,
    // Disabled mode: if native Record is running, WebRecord modules will not be loaded for
    // capture or replay and any replay attempt will be ignored
    // (i.e. each interaction will still end with a success code).
    // - On the main process: native Record is running but should have no effect on web views.
    // - On a subprocess: (not always needed) native Record is not running or WebRecord should be ignored.
    DISABLED,
    // Capture/Record mode: enabled when using "mkodt -s <odtname> -C".
    CAPTURE,
    // Replay mode: enabled when launching tests with "mkodt -s <odtname>".
    REPLAY
  };
  
  /**
   * Behavior to enable when the browser is about to open a popup window.
   */
  enum catceftypes_popupbehavior
  {
  // Do nothing: the popup will not open. If `window.open` was used, it will return `null`.
    POP_IGNORE = 0,
    // Let the browser open a new window.
    POP_OPEN,
    // Deny the popup creation and open the target URL in the current window instead.
    // If `window.open` was used, it will return `null`.
    POP_OPEN_EXTERNAL,
    // Default behavior.
    POP_DEFAULT = POP_OPEN
  };   
  
  // Types for notifications that are dispatched without parameters.
  enum catceftypes_notificationtype {
    NT_UNKNOWN = 0,
    // The browser has been created and is ready.
    NT_START,
    // The 'BrowserClosed' event has been fired.
    NT_END,
    // The DOMContentLoaded event has been fired.
    NT_DOM_READY,
    // The 'load' event has been fired.
    NT_LOAD,
    // The unload event has been fired.
    NT_UNLOAD,
    // The WebView has changed: a new texture is available.
    NT_REDRAW,
    // The renderer process for the current browser has been terminated (crash or process kill).
    NT_ABEND
  };

  
  // Only support primitive values because of time constraints and possible performance issues due
  // to lots of copying between each implementation layer.
  enum catceftypes_jstype
  {
    JS_UNDEFINED = 0,
    JS_NULL,
    JS_NAN,
    JS_BOOLEAN,
    JS_NUMBER,
    JS_STRING
    // TODO: Study the best way to introduce objects in case it's needed.
    // In the meantime, objects (including arrays) should be passed as JSON strings.
  };
  
  /**
   * Mouse button identifiers.
   */
  enum catceftypes_mousebutton
  {
    MOUSE_LEFT = 0,
    MOUSE_MIDDLE,
    MOUSE_RIGHT,
    MOUSE_UNKNOWN
  };
    
  enum catceftypes_mousebuttonstate
  {
    MOUSE_DOWN = 0,
    MOUSE_UP,
    MOUSE_NOSTATE
  };
  
  enum catceftypes_keymodifiermask
  {
    KM_NONE  = 0,
    KM_CTRL  = 1 << 0,
    KM_ALT   = 1 << 1,
    KM_SHIFT = 1 << 2,
    KM_META  = 1 << 3,
    KM_SUPER = 1 << 4
  };
  
  /**
   * Bit flags for drag&drop operations.
   */
  enum catceftypes_dragmodemask
  {
    // No drag operation allowed.
    DRAG_NONE = 0,
    // Data can be copied.
    DRAG_COPY = 1 << 0,
    // Data can be shared.
    DRAG_LINK = 1 << 1,
    // Operation defined by target.
    DRAG_GENERIC = 1 << 2,
    // Operation set privately between the source and the target.
    DRAG_PRIVATE = 1 << 3,
    // Data can be moved.
    DRAG_MOVE = 1 << 4,
    // Data can be deleted.
    DRAG_DELETE = 1 << 5,
    // All of the above operations.
    DRAG_ALL = 0xFFFFFFFF
  };  
  
  enum catceftypes_downloaddialogresponse
  {
    // Cancel the download.
    DL_DLG_CANCEL = 0,
    // Save the file in a temporary location and open it with the associated application.
    DL_DLG_OPEN,
    // Display a file dialog so the user can choose where he/she wants to save the file.
    DL_DLG_SAVEAS
  };
  
   /**
   * Bit flags for possible actions on editable and non-editable nodes.
   */
  enum catceftypes_contextmenueditmask
  {
    // No option
    CM_EDIT_NONE = 0,
    // The selected node can be copied in the clipboard.
    CM_EDIT_COPY = 1 << 0,
    // The selected node can be cut and copied in the clipboard.
    CM_EDIT_CUT = 1 << 1,
    // What is in the clipboard can be paste in that node.
    CM_EDIT_PASTE = 1 << 2,
    // The selected node can be deleted.
    CM_EDIT_DELETE = 1 << 3,
    // The selected node can undo an action.
    CM_EDIT_UNDO = 1 << 4,
    // The selected node can redo an action that has been undone.
    CM_EDIT_REDO = 1 << 5,
    // The selected node can be translated.
    CM_EDIT_TRANSLATE = 1 << 6,
    // All the content in the selected node can be selected.
    CM_EDIT_SELECT_ALL = 1 << 7
  };
  
  /**
   * Bit flags for media nodes.
   */
  enum catceftypes_contextmenumediamask
  {
    // No option.
    CM_MEDIA_NONE = 0,
    // The selected media can be saved on a drive.
    CM_MEDIA_SAVE = 1 << 0,
    // The selected media can be printed.
    CM_MEDIA_PRINT = 1 << 1,
    // The selected media has audio.
    CM_MEDIA_HAS_AUDIO = 1 << 2,
    // The selected media has video.
    CM_MEDIA_HAS_VIDEO = 1 << 3,
    // The selected media is currently muted (audio & video).
    CM_MEDIA_IS_MUTED = 1 << 4,
    // The selected media is currently paused (audio & video).
    CM_MEDIA_IS_PAUSED = 1 << 5
  };
  
  /**
   * Bit flags for HTML node types triggering context menus.
   */
  enum catceftypes_contextmenutypemask
  {
    // No node was selected.
    CM_TYPE_NONE = 0,
    // Top page.
    CM_TYPE_PAGE = 1 << 0,
    // Hyperlink.
    CM_TYPE_LINK = 1 << 2,
    // Text or mixed selection.
    CM_TYPE_SELECTION = 1 << 3,
    // Editable node: forms, editors...
    CM_TYPE_EDITABLE = 1 << 4,
    // Media: audio & video.
    CM_TYPE_MEDIA = 1 << 5,
    // Subframe page.
    CM_TYPE_SUBFRAME = 1 << 6
  };
  
  enum catceftypes_contextmenumediatype
  {
    // No media type.
    CM_MEDIA_NOTYPE = 0,
    // Image.
    CM_MEDIA_IMAGE_T,
    // Audio.
    CM_MEDIA_AUDIO_T,
    // Video.
    CM_MEDIA_VIDEO_T,
    // File.
    CM_MEDIA_FILE_T,
    // Plugin.
    CM_MEDIA_PLUGIN_T,
  };
  
  /**
   * JavaScript dialog types.
   */
  enum catceftypes_jsdialogtype
  {
    // JS alert dialog box: displays a message and an "OK" button.
    JS_DLG_ALERT = 0,
    // JS confirmation dialog box: displays a message and two buttons "OK" and "Cancel".
    JS_DLG_CONFIRM,
    // JS prompt dialog box: used to get user input (label + field) and two buttons "OK" and
    // "Cancel".
    JS_DLG_PROMPT,
    // JS dialog box created by the Window.OnBeforeUnload event.
    // Similar to a confirmation, but asking if you want to stay or leave the current page.
    JS_DLG_ONBEFOREUNLOAD
  };
  
  /**
   * Notification levels for information dispatched by a browser.
   */
  enum catceftypes_notificationlevel
  {
    // Basic information.
    NTF_INFO = 0,
    // Warnings.
    NTF_WARNING,
    // Errors.
    NTF_ERROR,
    // A higher level for errors just in case.
    NTF_CRITICAL
  };
  
  /**
   * Key types.
   */
  enum catceftypes_keytype
  {
    // Pressed key.
    KEY_DOWN = 0,
    // Released key.
    KEY_UP,
    // Additional type for characters, e.g. 'b' => keydown 0x42, char 0x62, keyup 0x42.
    KEY_CHAR
  };   
  
   /**
   * Dialog type for file selection.
   */
  enum catceftypes_filedialogtype
  {
    // Select a single file to open.
    FILE_OPEN = 0,
    // Select one or multiple files to open.
    FILE_OPEN_MULTI,
    // Select a directory to open.
    FILE_OPEN_DIR,
    // Select a location to save a file.
    FILE_SAVE
  };
  
  /**
   * Touch state.
   */
  enum catceftypes_touchstate
  {
    TOUCH_DOWN = 0,
    TOUCH_UP,
    TOUCH_MOVE,
    TOUCH_CLEAR,
    TOUCH_NOSTATE
  };
  
  /**
   * Identifiers for mouse cursors that might be used by the browser.
   */
  enum catceftypes_mousecursor
  {
    // Browser-specific cursors
    // ------------------------

    // No cursor.
    MC_NONE = 0,
    // Hand with spread fingers.
    MC_HAND_OPEN,
    // Grabbing hand.
    MC_HAND_GRABBING,
    // "+" magnifying glass.
    MC_ZOOM_IN,
    // "-" magnifying glass.
    MC_ZOOM_OUT,
    // Double vertical bars with an arrow on each side.
    MC_SIZE_COL,
    // Double horizontal bars with an arrow on each side.
    MC_SIZE_ROW,
    // Vertical text edit.
    MC_TEXT_EDIT_VER,
    // Alias or shortcut cursor.
    MC_ALIAS,
    // Cell edition cross.
    MC_CELL,
    // Arrow with little "+" sign.
    MC_COPY,

    // Predefined system cursors
    // -------------------------

    // Standard arrow.
    MC_ARROW,
    // Arrow with hourglass or spinner.
    MC_PROGRESS,
    // Hand pointing top.
    MC_HAND_POINTING,
    // Hourglass or spinner.
    MC_WAIT,
    // Horizontal text edit.
    MC_TEXT_EDIT,
    // Crosshair.
    MC_CROSS,
    // Arrow with question mark.
    MC_HELP,
    // Slashed circle.
    MC_FORBIDDEN,
    // Four-arrow cross.
    MC_PAN,
    // Horizontal resize.
    MC_SIZE_H,
    // Vertical resize.
    MC_SIZE_V,
    // Double arrow, North West and South East.
    MC_SIZE_NWSE,
    // Double arrow, North East and South West.
    MC_SIZE_NESW,

    // Number of supported cursors.
    MC_ENUM_SIZE
  };

  enum catceftypes_permission_request_mask{
    CATCEF_PERMISSION_TYPE_NONE = 0,
    CATCEF_PERMISSION_TYPE_ACCESSIBILITY_EVENTS = 1 << 0,
    CATCEF_PERMISSION_TYPE_AR_SESSION = 1 << 1,
    CATCEF_PERMISSION_TYPE_CAMERA_PAN_TILT_ZOOM = 1 << 2,
    CATCEF_PERMISSION_TYPE_CAMERA_STREAM = 1 << 3,
    CATCEF_PERMISSION_TYPE_CLIPBOARD = 1 << 4,
    CATCEF_PERMISSION_TYPE_DISK_QUOTA = 1 << 5,
    CATCEF_PERMISSION_TYPE_LOCAL_FONTS = 1 << 6,
    CATCEF_PERMISSION_TYPE_GEOLOCATION = 1 << 7,
    CATCEF_PERMISSION_TYPE_IDLE_DETECTION = 1 << 8,
    CATCEF_PERMISSION_TYPE_MIC_STREAM = 1 << 9,
    CATCEF_PERMISSION_TYPE_MIDI_SYSEX = 1 << 10,
    CATCEF_PERMISSION_TYPE_MULTIPLE_DOWNLOADS = 1 << 11,
    CATCEF_PERMISSION_TYPE_NOTIFICATIONS = 1 << 12,
    CATCEF_PERMISSION_TYPE_PROTECTED_MEDIA_IDENTIFIER = 1 << 13,
    CATCEF_PERMISSION_TYPE_REGISTER_PROTOCOL_HANDLER = 1 << 14,
    CATCEF_PERMISSION_TYPE_SECURITY_ATTESTATION = 1 << 15,
    CATCEF_PERMISSION_TYPE_STORAGE_ACCESS = 1 << 16,
    CATCEF_PERMISSION_TYPE_U2F_API_REQUEST = 1 << 17,
    CATCEF_PERMISSION_TYPE_VR_SESSION = 1 << 18,
    CATCEF_PERMISSION_TYPE_WINDOW_MANAGEMENT = 1 << 19,
  } ;

  enum catceftypes_permission_request_result {
    // Accept the permission request as an explicit user action.
    CATCEF_PERMISSION_RESULT_ACCEPT,
    // Deny the permission request as an explicit user action.
    CATCEF_PERMISSION_RESULT_DENY,
    // Dismiss the permission request as an explicit user action.
    CATCEF_PERMISSION_RESULT_DISMISS,
    // Ignore the permission request. If the prompt remains unhandled (e.g.
    // OnShowPermissionPrompt returns false and there is no default permissions
    // UI) then any related promises may remain unresolved.
    CATCEF_PERMISSION_RESULT_IGNORE,
  };
}
  
#endif
