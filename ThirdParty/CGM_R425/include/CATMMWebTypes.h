//===================================================================
// COPYRIGHT Dassault Syst�mes 2013-05-06
//===================================================================
//
// Useful type definitions for web browsers.
//
//===================================================================
// 2013-05-06 Creation: D6K
//===================================================================

#ifndef CATMMWebTypes_H
#define CATMMWebTypes_H

// MultimediaInterfaces
#include "CATMM2DTypes.h"
#include "MultimediaItf.h"
// System
#include "CATBinary.h"
#include "CATTime.h"
// SystemTS
#include "DSYString.h"

// System/PublicInterfaces/CATErrorMacros.h defines try/catch/throw as
// ERROR; as a consequence #include <map> may fail to compile since
// it is based on a template so its code is inlined and may
// contain exception code.
#undef try
#undef catch
#undef throw
#include <functional>
#include <map>
#include <memory>
#include <vector>

namespace MMW
{
  typedef int KeyModifiers;

  // ----------------------------------------------------------------------------
  // Enumerators
  // ----------------------------------------------------------------------------

  /**
   * Browser rendering mode.
   */
  enum RenderingMode
  {
    // Windowed rendering with dialogs.
    RM_DEFAULT = 0,
    // Offscreen (or windowless) rendering without dialogs.
    RM_OFFSCREEN
  };
  /**
   * Key types.
   */
  enum KeyType
  {
    // Pressed key.
    KEY_DOWN = 0,
    // Released key.
    KEY_UP,
    // Additional type for characters, e.g. 'b' => keydown 0x42, char 0x62, keyup 0x42.
    KEY_CHAR
  };
  /**
   * Mouse button identifiers.
   */
  enum MouseButton
  {
    MOUSE_LEFT = 0,
    MOUSE_MIDDLE,
    MOUSE_RIGHT,
    MOUSE_UNKNOWN
  };
  /**
   * Mouse button states.
   */
  enum MouseButtonState
  {
    MOUSE_DOWN = 0,
    MOUSE_UP,
    MOUSE_NOSTATE
  };
  /**
   * Identifiers for mouse cursors that might be used by the browser.
   */
  enum MouseCursor
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
    // Slashed circle.
    MC_DRAG_NONE,
    // Arrow with double square in which one contains a little "+" sign.
    MC_DRAG_MOVE,
    // Arrow with double square
    MC_DRAG_COPY,
    // Arrow with double square in which one contains a little edition cross.
    MC_DRAG_LINK,

    // Number of supported cursors.
    MC_ENUM_SIZE
  };
  /**
   * Touch state.
   */
  enum TouchState
  {
    TOUCH_DOWN = 0,
    TOUCH_UP,
    TOUCH_MOVE,
    TOUCH_CLEAR,
    TOUCH_NOSTATE
  };
  /**
   * Bit flags for keyboard modifiers.
   */
  enum KeyModifierFlag
  {
    KM_CTRL = 1 << 0,
    KM_ALT = 1 << 1,
    KM_SHIFT = 1 << 2,
    KM_META = 1 << 3,
    KM_SUPER = 1 << 4
  };
  typedef int KeyModifierMask;
  /**
   * Bit flags for HTML node types triggering context menus.
   */
  enum ContextMenuTypeFlag
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
  typedef int ContextMenuTypeMask;
  /**
   * Bit flags for HTML possible permission request.
   */
  enum PermissionType
  {
    PR_TYPE_NONE = 0,
    PR_TYPE_ACCESSIBILITY_EVENTS = 1 << 0,
    PR_TYPE_AR_SESSION = 1 << 1,
    PR_TYPE_CAMERA_PAN_TILT_ZOOM = 1 << 2,
    PR_TYPE_CAMERA_STREAM = 1 << 3,
    PR_TYPE_CLIPBOARD = 1 << 4,
    PR_TYPE_DISK_QUOTA = 1 << 5,
    PR_TYPE_LOCAL_FONTS = 1 << 6,
    PR_TYPE_GEOLOCATION = 1 << 7,
    PR_TYPE_IDLE_DETECTION = 1 << 8,
    PR_TYPE_MIC_STREAM = 1 << 9,
    PR_TYPE_MIDI_SYSEX = 1 << 10,
    PR_TYPE_MULTIPLE_DOWNLOADS = 1 << 11,
    PR_TYPE_NOTIFICATIONS = 1 << 12,
    PR_TYPE_PROTECTED_MEDIA_IDENTIFIER = 1 << 13,
    PR_TYPE_REGISTER_PROTOCOL_HANDLER = 1 << 14,
    PR_TYPE_SECURITY_ATTESTATION = 1 << 15,
    PR_TYPE_STORAGE_ACCESS = 1 << 16,
    PR_TYPE_U2F_API_REQUEST = 1 << 17,
    PR_TYPE_VR_SESSION = 1 << 18,
    PR_TYPE_WINDOW_PLACEMENT = 1 << 19,
  };
  /**
   * Bit flags for HTML possible permission result.
   */
  enum PermissionResult
  {
    // Accept the permission request as an explicit user action.
    PR_RESULT_ACCEPT,
    // Deny the permission request as an explicit user action.
    PR_RESULT_DENY,
    // Dismiss the permission request as an explicit user action.
    PR_RESULT_DISMISS,
    // Ignore the permission request.
    PR_RESULT_IGNORE
  };
  /**
   * Bit flags for possible actions on editable and non-editable nodes.
   */
  enum ContextMenuEditFlag
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
  typedef int ContextMenuEditMask;
  /**
   * Media node types.
   */
  enum ContextMenuMediaType
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
   * Bit flags for media nodes.
   */
  enum ContextMenuMediaFlag
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
  typedef int ContextMenuMediaMask;
  /**
   * JavaScript dialog types.
   */
  enum JSDialogType
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
   * Download dialog response types.
   */
  enum DownloadDialogResponse
  {
    // Cancel the download.
    DL_DLG_CANCEL = 0,
    // Save the file in a temporary location and open it with the associated application.
    DL_DLG_OPEN,
    // Display a file dialog so the user can choose where he/she wants to save the file.
    DL_DLG_SAVEAS
  };
  /**
   * Dialog type for file selection.
   */
  enum FileDialogType
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
   * Error codes for load events.
   * Ranges:
   *   0-99    System related errors
   *   100-199 Connection related errors
   *   200-299 Certificate errors
   *   300-399 HTTP errors
   *   400-499 Cache errors
   *   500-599 ?
   */
  enum LoadErrorCode
  {
    // OK, no error.
    LDERR_NONE = 0,
    // A generic failure occurred.
    LDERR_FAILED = -2,
    // An operation was aborted (due to user action).
    LDERR_ABORTED = -3,
    // An argument to the function is incorrect.
    LDERR_INVALID_ARGUMENT = -4,
    // The handle or file descriptor is invalid.
    LDERR_INVALID_HANDLE = -5,
    // The file or directory cannot be found.
    LDERR_FILE_NOT_FOUND = -6,
    // An operation timed out.
    LDERR_TIMED_OUT = -7,
    // The file is too large.
    LDERR_FILE_TOO_BIG = -8,
    // An unexpected error. This may be caused by a programming mistake or an invalid assumption.
    LDERR_UNEXPECTED = -9,
    // Permission to access a resource, other than the network, was denied.
    LDERR_ACCESS_DENIED = -10,
    // The operation failed because of unimplemented functionality.
    LDERR_NOT_IMPLEMENTED = -11,
    // There were not enough resources to complete the operation.
    LDERR_INSUFFICIENT_RESOURCES = -12,
    // Memory allocation failed.
    LDERR_OUT_OF_MEMORY = -13,
    // The file upload failed because the file's modification time was different
    // from the expectation.
    LDERR_UPLOAD_FILE_CHANGED = -14,
    // The socket is not connected.
    LDERR_SOCKET_NOT_CONNECTED = -15,
    // The file already exists.
    LDERR_FILE_EXISTS = -16,
    // The path or file name is too long.
    LDERR_FILE_PATH_TOO_LONG = -17,
    // Not enough room left on the disk.
    LDERR_FILE_NO_SPACE = -18,
    // The file has a virus.
    LDERR_FILE_VIRUS_INFECTED = -19,
    // The client chose to block the request.
    LDERR_BLOCKED_BY_CLIENT = -20,
    // The network changed.
    LDERR_NETWORK_CHANGED = -21,
    // The request was blocked by the URL block list configured by the domain
    // administrator.
    LDERR_BLOCKED_BY_ADMINISTRATOR = -22,
    // The socket is already connected.
    LDERR_SOCKET_IS_CONNECTED = -23,
    // The request was blocked because the forced reenrollment check is still
    // pending.
    LDERR_BLOCKED_ENROLLMENT_CHECK_PENDING = -24,
    // The upload failed because the upload stream needed to be re-read, due to a
    // retry or a redirect, but the upload stream doesn't support that operation.
    LDERR_UPLOAD_STREAM_REWIND_NOT_SUPPORTED = -25,
    // The request failed because the URLRequestContext is shutting down, or has
    // been shut down.
    LDERR_CONTEXT_SHUT_DOWN = -26,
    // The request failed because the response was delivered along with requirements
    // which are not met ('X-Frame-Options' and 'Content-Security-Policy' ancestor
    // checks and 'Cross-Origin-Resource-Policy', for instance).
    LDERR_BLOCKED_BY_RESPONSE = -27,
    // The request was blocked by system policy disallowing some or all cleartext
    // requests. Used for NetworkSecurityPolicy on Android.
    LDERR_CLEARTEXT_NOT_PERMITTED = -29,
    // The request was blocked by a Content Security Policy
    LDERR_BLOCKED_BY_CSP = -30,
    // The request was blocked because of no H/2 or QUIC session.
    LDERR_H2_OR_QUIC_REQUIRED = -31,
    // A connection was closed (corresponding to a TCP FIN).
    LDERR_CONNECTION_CLOSED = -100,
    // A connection was reset (corresponding to a TCP RST).
    LDERR_CONNECTION_RESET = -101,
    // A connection attempt was refused.
    LDERR_CONNECTION_REFUSED = -102,
    // A connection timed out as a result of not receiving an ACK for data sent. This can include a
    // FIN packet that did not get ACK'd.
    LDERR_CONNECTION_ABORTED = -103,
    // A connection attempt failed.
    LDERR_CONNECTION_FAILED = -104,
    // The host name could not be resolved.
    LDERR_NAME_NOT_RESOLVED = -105,
    // The Internet connection has been lost.
    LDERR_INTERNET_DISCONNECTED = -106,
    // An SSL protocol error occurred.
    LDERR_SSL_PROTOCOL_ERROR = -107,
    // The IP address or port number is invalid (e.g., cannot connect to the IP address 0 or the
    // port 0).
    LDERR_ADDRESS_INVALID = -108,
    // The IP address is unreachable. This usually means that there is no route to the specified
    // host or network.
    LDERR_ADDRESS_UNREACHABLE = -109,
    // The server requested a client certificate for SSL client authentication.
    LDERR_SSL_CLIENT_AUTH_CERT_NEEDED = -110,
    // A tunnel connection through the proxy could not be established.
    LDERR_TUNNEL_CONNECTION_FAILED = -111,
    // No SSL protocol versions are enabled.
    LDERR_NO_SSL_VERSIONS_ENABLED = -112,
    // The client and server don't support a common SSL protocol version or cipher suite.
    LDERR_SSL_VERSION_OR_CIPHER_MISMATCH = -113,
    // The server requested a renegotiation (rehandshake).
    LDERR_SSL_RENEGOTIATION_REQUESTED = -114,
    // The proxy requested authentication (for tunnel establishment) with an
    // unsupported method.
    LDERR_PROXY_AUTH_UNSUPPORTED = -115,
    // The SSL handshake failed because of a bad or missing client certificate.
    LDERR_BAD_SSL_CLIENT_AUTH_CERT = -117,
    // A connection attempt timed out.
    LDERR_CONNECTION_TIMED_OUT = -118,
    // There are too many pending DNS resolves, so a request in the queue was
    // aborted.
    LDERR_HOST_RESOLVER_QUEUE_TOO_LARGE = -119,
    // Failed establishing a connection to the SOCKS proxy server for a target host.
    LDERR_SOCKS_CONNECTION_FAILED = -120,
    // The SOCKS proxy server failed establishing connection to the target host
    // because that host is unreachable.
    LDERR_SOCKS_CONNECTION_HOST_UNREACHABLE = -121,
    // The request to negotiate an alternate protocol failed.
    LDERR_ALPN_NEGOTIATION_FAILED = -122,
    // The peer sent an SSL no_renegotiation alert message.
    LDERR_SSL_NO_RENEGOTIATION = -123,
    // Winsock sometimes reports more data written than passed.  This is probably
    // due to a broken LSP.
    LDERR_WINSOCK_UNEXPECTED_WRITTEN_BYTES = -124,
    // An SSL peer sent us a fatal decompression_failure alert. This typically
    // occurs when a peer selects DEFLATE compression in the mistaken belief that
    // it supports it.
    LDERR_SSL_DECOMPRESSION_FAILURE_ALERT = -125,
    // An SSL peer sent us a fatal bad_record_mac alert. This has been observed
    // from servers with buggy DEFLATE support.
    LDERR_SSL_BAD_RECORD_MAC_ALERT = -126,
    // The proxy requested authentication (for tunnel establishment).
    LDERR_PROXY_AUTH_REQUESTED = -127,
    // Could not create a connection to the proxy server. An error occurred
    // either in resolving its name, or in connecting a socket to it.
    // Note that this does NOT include failures during the actual "CONNECT" method
    // of an HTTP proxy.
    LDERR_PROXY_CONNECTION_FAILED = -130,
    // A mandatory proxy configuration could not be used. Currently this means
    // that a mandatory PAC script could not be fetched, parsed or executed.
    LDERR_MANDATORY_PROXY_CONFIGURATION_FAILED = -131,
    // We've hit the max socket limit for the socket pool while preconnecting.  We
    // don't bother trying to preconnect more sockets.
    LDERR_PRECONNECT_MAX_SOCKET_LIMIT = -133,
    // The permission to use the SSL client certificate's private key was denied.
    LDERR_SSL_CLIENT_AUTH_PRIVATE_KEY_ACCESS_DENIED = -134,
    // The SSL client certificate has no private key.
    LDERR_SSL_CLIENT_AUTH_CERT_NO_PRIVATE_KEY = -135,
    // The certificate presented by the HTTPS Proxy was invalid.
    LDERR_PROXY_CERTIFICATE_INVALID = -136,
    // An error occurred when trying to do a name resolution (DNS).
    LDERR_NAME_RESOLUTION_FAILED = -137,
    // Permission to access the network was denied. This is used to distinguish
    // errors that were most likely caused by a firewall from other access denied
    // errors. See also ERR_ACCESS_DENIED.
    LDERR_NETWORK_ACCESS_DENIED = -138,
    // The request throttler module cancelled this request to avoid DDOS.
    LDERR_TEMPORARILY_THROTTLED = -139,
    // We were unable to sign the CertificateVerify data of an SSL client auth
    // handshake with the client certificate's private key.
    //
    // Possible causes for this include the user implicitly or explicitly
    // denying access to the private key, the private key may not be valid for
    // signing, the key may be relying on a cached handle which is no longer
    // valid, or the CSP won't allow arbitrary data to be signed.
    LDERR_SSL_CLIENT_AUTH_SIGNATURE_FAILED = -141,
    // The message was too large for the transport.  (for example a UDP message
    // which exceeds size threshold).
    LDERR_MSG_TOO_BIG = -142,
    // Websocket protocol error. Indicates that we are terminating the connection
    // due to a malformed frame or other protocol violation.
    LDERR_WS_PROTOCOL_ERROR = -145,
    // Returned when attempting to bind an address that is already in use.
    LDERR_ADDRESS_IN_USE = -147,
    // An operation failed because the SSL handshake has not completed.
    LDERR_SSL_HANDSHAKE_NOT_COMPLETED = -148,
    // SSL peer's public key is invalid.
    LDERR_SSL_BAD_PEER_PUBLIC_KEY = -149,
    // The certificate didn't match the built-in public key pins for the host name.
    // The pins are set in net/http/transport_security_state.cc and require that
    // one of a set of public keys exist on the path from the leaf to the root.
    LDERR_SSL_PINNED_KEY_NOT_IN_CERT_CHAIN = -150,
    // Server request for client certificate did not contain any types we support.
    LDERR_CLIENT_AUTH_CERT_TYPE_UNSUPPORTED = -151,
    // An SSL peer sent us a fatal decrypt_error alert. This typically occurs when
    // a peer could not correctly verify a signature (in CertificateVerify or
    // ServerKeyExchange) or validate a Finished message.
    LDERR_SSL_DECRYPT_ERROR_ALERT = -153,
    // There are too many pending WebSocketJob instances, so the new job was not
    // pushed to the queue.
    LDERR_WS_THROTTLE_QUEUE_TOO_LARGE = -154,
    // The SSL server certificate changed in a renegotiation.
    LDERR_SSL_SERVER_CERT_CHANGED = -156,
    // The SSL server sent us a fatal unrecognized_name alert.
    LDERR_SSL_UNRECOGNIZED_NAME_ALERT = -159,
    // Failed to set the socket's receive buffer size as requested.
    LDERR_SOCKET_SET_RECEIVE_BUFFER_SIZE_ERROR = -160,
    // Failed to set the socket's send buffer size as requested.
    LDERR_SOCKET_SET_SEND_BUFFER_SIZE_ERROR = -161,
    // Failed to set the socket's receive buffer size as requested, despite success
    // return code from setsockopt.
    LDERR_SOCKET_RECEIVE_BUFFER_SIZE_UNCHANGEABLE = -162,
    // Failed to set the socket's send buffer size as requested, despite success
    // return code from setsockopt.
    LDERR_SOCKET_SEND_BUFFER_SIZE_UNCHANGEABLE = -163,
    // Failed to import a client certificate from the platform store into the SSL
    // library.
    LDERR_SSL_CLIENT_AUTH_CERT_BAD_FORMAT = -164,
    // Resolving a hostname to an IP address list included the IPv4 address
    // "127.0.53.53". This is a special IP address which ICANN has recommended to
    // indicate there was a name collision, and alert admins to a potential
    // problem.
    LDERR_ICANN_NAME_COLLISION = -166,
    // The SSL server presented a certificate which could not be decoded. This is
    // not a certificate error code as no X509Certificate object is available. This
    // error is fatal.
    LDERR_SSL_SERVER_CERT_BAD_FORMAT = -167,
    // Certificate Transparency: Received a signed tree head that failed to parse.
    LDERR_CT_STH_PARSING_FAILED = -168,
    // Certificate Transparency: Received a signed tree head whose JSON parsing was
    // OK but was missing some of the fields.
    LDERR_CT_STH_INCOMPLETE = -169,
    // The attempt to reuse a connection to send proxy auth credentials failed
    // before the AuthController was used to generate credentials. The caller should
    // reuse the controller with a new connection. This error is only used
    // internally by the network stack.
    LDERR_UNABLE_TO_REUSE_CONNECTION_FOR_PROXY_AUTH = -170,
    // Certificate Transparency: Failed to parse the received consistency proof.
    LDERR_CT_CONSISTENCY_PROOF_PARSING_FAILED = -171,
    // The SSL server required an unsupported cipher suite that has since been
    // removed. This error will temporarily be signaled on a fallback for one or two
    // releases immediately following a cipher suite's removal, after which the
    // fallback will be removed.
    LDERR_SSL_OBSOLETE_CIPHER = -172,
    // When a WebSocket handshake is done successfully and the connection has been
    // upgraded, the URLRequest is cancelled with this error code.
    LDERR_WS_UPGRADE = -173,
    // Socket ReadIfReady support is not implemented. This error should not be user
    // visible, because the normal Read() method is used as a fallback.
    LDERR_READ_IF_READY_NOT_IMPLEMENTED = -174,
    // No socket buffer space is available.
    LDERR_NO_BUFFER_SPACE = -176,
    // There were no common signature algorithms between our client certificate
    // private key and the server's preferences.
    LDERR_SSL_CLIENT_AUTH_NO_COMMON_ALGORITHMS = -177,
    // TLS 1.3 early data was rejected by the server. This will be received before
    // any data is returned from the socket. The request should be retried with
    // early data disabled.
    LDERR_EARLY_DATA_REJECTED = -178,
    // TLS 1.3 early data was offered, but the server responded with TLS 1.2 or
    // earlier. This is an internal error code to account for a
    // backwards-compatibility issue with early data and TLS 1.2. It will be
    // received before any data is returned from the socket. The request should be
    // retried with early data disabled.
    LDERR_WRONG_VERSION_ON_EARLY_DATA = -179,
    // TLS 1.3 was enabled, but a lower version was negotiated and the server
    // returned a value indicating it supported TLS 1.3. This is part of a security
    // check in TLS 1.3, but it may also indicate the user is behind a buggy
    // TLS-terminating proxy which implemented TLS 1.2 incorrectly.
    LDERR_TLS13_DOWNGRADE_DETECTED = -180,
    // The server's certificate has a keyUsage extension incompatible with the
    // negotiated TLS key exchange method.
    LDERR_SSL_KEY_USAGE_INCOMPATIBLE = -181,
    // The ECHConfigList fetched over DNS cannot be parsed.
    LDERR_INVALID_ECH_CONFIG_LIST = -182,
    // ECH was enabled, but the server was unable to decrypt the encrypted
    // ClientHello.
    LDERR_ECH_NOT_NEGOTIATED = -183,
    // ECH was enabled, the server was unable to decrypt the encrypted ClientHello,
    // and additionally did not present a certificate valid for the public name.
    LDERR_ECH_FALLBACK_CERTIFICATE_INVALID = -184,
    // The server responded with a certificate whose common name did not match the host name.
    LDERR_CERT_COMMON_NAME_INVALID = -200,
    // The server responded with a certificate that, by our clock, appears to either not yet be
    // valid or to have expired.
    LDERR_CERT_DATE_INVALID = -201,
    // The server responded with a certificate that is signed by an authority we don't trust.
    LDERR_CERT_AUTHORITY_INVALID = -202,
    // The server responded with a certificate that contains errors. This error is not recoverable.
    LDERR_CERT_CONTAINS_ERRORS = -203,
    // The certificate has no mechanism for determining if it is revoked. In effect, this
    // certificate cannot be revoked.
    LDERR_CERT_NO_REVOCATION_MECHANISM = -204,
    // Revocation information for the security certificate for this site is not available.
    LDERR_CERT_UNABLE_TO_CHECK_REVOCATION = -205,
    // The server responded with a certificate has been revoked.
    LDERR_CERT_REVOKED = -206,
    // The server responded with a certificate that is invalid. This error is not recoverable.
    LDERR_CERT_INVALID = -207,
    // The server responded with a certificate that is signed using a weak signature algorithm.
    LDERR_CERT_WEAK_SIGNATURE_ALGORITHM = -208,
    // The host name specified in the certificate is not unique.
    LDERR_CERT_NON_UNIQUE_NAME = -210,
    // The server responded with a certificate that contains a weak key (e.g. a too-small RSA key).
    LDERR_CERT_WEAK_KEY = -211,
    // The certificate claimed DNS names that are in violation of name constraints.
    LDERR_CERT_NAME_CONSTRAINT_VIOLATION = -212,
    // The certificate's validity period is too long.
    LDERR_CERT_VALIDITY_TOO_LONG = -213,
    // Certificate Transparency was required for this connection, but the server
    // did not provide CT information that complied with the policy.
    LDERR_CERTIFICATE_TRANSPARENCY_REQUIRED = -214,
    // The certificate chained to a legacy Symantec root that is no longer trusted.
    LDERR_CERT_SYMANTEC_LEGACY = -215,
    // The certificate is known to be used for interception by an entity other
    // the device owner.
    LDERR_CERT_KNOWN_INTERCEPTION_BLOCKED = -217,
    // The value immediately past the last certificate error code.
    LDERR_CERT_END = -219,
    // The URL is invalid.
    LDERR_INVALID_URL = -300,
    // The scheme of the URL is disallowed.
    LDERR_DISALLOWED_URL_SCHEME = -301,
    // The scheme of the URL is unknown.
    LDERR_UNKNOWN_URL_SCHEME = -302,
    // Attempting to load an URL resulted in a redirect to an invalid URL.
    LDERR_INVALID_REDIRECT = -303,
    // Attempting to load an URL resulted in too many redirects.
    LDERR_TOO_MANY_REDIRECTS = -310,
    // Attempting to load an URL resulted in an unsafe redirect (e.g., a redirect to file:// is
    // considered unsafe).
    LDERR_UNSAFE_REDIRECT = -311,
    // Attempting to load an URL with an unsafe port number.
    LDERR_UNSAFE_PORT = -312,
    // The server's response was invalid.
    LDERR_INVALID_RESPONSE = -320,
    // Error in chunked transfer encoding.
    LDERR_INVALID_CHUNKED_ENCODING = -321,
    // The server did not support the request method.
    LDERR_METHOD_NOT_SUPPORTED = -322,
    // The response was 407 (Proxy Authentication Required), yet we did not send the request to a
    // proxy.
    LDERR_UNEXPECTED_PROXY_AUTH = -323,
    // The server closed the connection without sending any data.
    LDERR_EMPTY_RESPONSE = -324,
    // The headers section of the response is too large.
    LDERR_RESPONSE_HEADERS_TOO_BIG = -325,
    // The evaluation of the PAC script failed.
    LDERR_PAC_SCRIPT_FAILED = -327,
    // The response was 416 (Requested range not satisfiable) and the server cannot
    // satisfy the range requested.
    LDERR_REQUEST_RANGE_NOT_SATISFIABLE = -328,
    // The identity used for authentication is invalid.
    LDERR_MALFORMED_IDENTITY = -329,
    // Content decoding of the response body failed.
    LDERR_CONTENT_DECODING_FAILED = -330,
    // An operation could not be completed because all network IO
    // is suspended.
    LDERR_NETWORK_IO_SUSPENDED = -331,
    // FLIP data received without receiving a SYN_REPLY on the stream.
    LDERR_SYN_REPLY_NOT_RECEIVED = -332,
    // Converting the response to target encoding failed.
    LDERR_ENCODING_CONVERSION_FAILED = -333,
    // The server sent an FTP directory listing in a format we do not understand.
    LDERR_UNRECOGNIZED_FTP_DIRECTORY_LISTING_FORMAT = -334,
    // There are no supported proxies in the provided list.
    LDERR_NO_SUPPORTED_PROXIES = -336,
    // There is an HTTP/2 protocol error.
    LDERR_HTTP2_PROTOCOL_ERROR = -337,
    // Credentials could not be established during HTTP Authentication.
    LDERR_INVALID_AUTH_CREDENTIALS = -338,
    // An HTTP Authentication scheme was tried which is not supported on this
    // machine.
    LDERR_UNSUPPORTED_AUTH_SCHEME = -339,
    // Detecting the encoding of the response failed.
    LDERR_ENCODING_DETECTION_FAILED = -340,
    // (GSSAPI) No Kerberos credentials were available during HTTP Authentication.
    LDERR_MISSING_AUTH_CREDENTIALS = -341,
    // An unexpected, but documented, SSPI or GSSAPI status code was returned.
    LDERR_UNEXPECTED_SECURITY_LIBRARY_STATUS = -342,
    // The environment was not set up correctly for authentication (for
    // example, no KDC could be found or the principal is unknown.
    LDERR_MISCONFIGURED_AUTH_ENVIRONMENT = -343,
    // An undocumented SSPI or GSSAPI status code was returned.
    LDERR_UNDOCUMENTED_SECURITY_LIBRARY_STATUS = -344,
    // The HTTP response was too big to drain.
    LDERR_RESPONSE_BODY_TOO_BIG_TO_DRAIN = -345,
    // The HTTP response contained multiple distinct Content-Length headers.
    LDERR_RESPONSE_HEADERS_MULTIPLE_CONTENT_LENGTH = -346,
    // HTTP/2 headers have been received, but not all of them - status or version
    // headers are missing, so we're expecting additional frames to complete them.
    LDERR_INCOMPLETE_HTTP2_HEADERS = -347,
    // No PAC URL configuration could be retrieved from DHCP. This can indicate
    // either a failure to retrieve the DHCP configuration, or that there was no
    // PAC URL configured in DHCP.
    LDERR_PAC_NOT_IN_DHCP = -348,
    // The HTTP response contained multiple Content-Disposition headers.
    LDERR_RESPONSE_HEADERS_MULTIPLE_CONTENT_DISPOSITION = -349,
    // The HTTP response contained multiple Location headers.
    LDERR_RESPONSE_HEADERS_MULTIPLE_LOCATION = -350,
    // HTTP/2 server refused the request without processing, and sent either a
    // GOAWAY frame with error code NO_ERROR and Last-Stream-ID lower than the
    // stream id corresponding to the request indicating that this request has not
    // been processed yet, or a RST_STREAM frame with error code REFUSED_STREAM.
    // Client MAY retry (on a different connection).  See RFC7540 Section 8.1.4.
    LDERR_HTTP2_SERVER_REFUSED_STREAM = -351,
    // HTTP/2 server didn't respond to the PING message.
    LDERR_HTTP2_PING_FAILED = -352,
    // The HTTP response body transferred fewer bytes than were advertised by the
    // Content-Length header when the connection is closed.
    LDERR_CONTENT_LENGTH_MISMATCH = -354,
    // The HTTP response body is transferred with Chunked-Encoding, but the
    // terminating zero-length chunk was never sent when the connection is closed.
    LDERR_INCOMPLETE_CHUNKED_ENCODING = -355,
    // There is a QUIC protocol error.
    LDERR_QUIC_PROTOCOL_ERROR = -356,
    // The HTTP headers were truncated by an EOF.
    LDERR_RESPONSE_HEADERS_TRUNCATED = -357,
    // The QUIC crytpo handshake failed.  This means that the server was unable
    // to read any requests sent, so they may be resent.
    LDERR_QUIC_HANDSHAKE_FAILED = -358,
    // Transport security is inadequate for the HTTP/2 version.
    LDERR_HTTP2_INADEQUATE_TRANSPORT_SECURITY = -360,
    // The peer violated HTTP/2 flow control.
    LDERR_HTTP2_FLOW_CONTROL_ERROR = -361,
    // The peer sent an improperly sized HTTP/2 frame.
    LDERR_HTTP2_FRAME_SIZE_ERROR = -362,
    // Decoding or encoding of compressed HTTP/2 headers failed.
    LDERR_HTTP2_COMPRESSION_ERROR = -363,
    // Proxy Auth Requested without a valid Client Socket Handle.
    LDERR_PROXY_AUTH_REQUESTED_WITH_NO_CONNECTION = -364,
    // HTTP_1_1_REQUIRED error code received on HTTP/2 session.
    LDERR_HTTP_1_1_REQUIRED = -365,
    // HTTP_1_1_REQUIRED error code received on HTTP/2 session to proxy.
    LDERR_PROXY_HTTP_1_1_REQUIRED = -366,
    // The PAC script terminated fatally and must be reloaded.
    LDERR_PAC_SCRIPT_TERMINATED = -367,
    // The server was expected to return an HTTP/1.x response, but did not. Rather
    // than treat it as HTTP/0.9, this error is returned.
    LDERR_INVALID_HTTP_RESPONSE = -370,
    // Initializing content decoding failed.
    LDERR_CONTENT_DECODING_INIT_FAILED = -371,
    // Received HTTP/2 RST_STREAM frame with NO_ERROR error code.  This error should
    // be handled internally by HTTP/2 code, and should not make it above the
    // SpdyStream layer.
    LDERR_HTTP2_RST_STREAM_NO_ERROR_RECEIVED = -372,
    // The pushed stream claimed by the request is no longer available.
    LDERR_HTTP2_PUSHED_STREAM_NOT_AVAILABLE = -373,
    // A pushed stream was claimed and later reset by the server. When this happens,
    // the request should be retried.
    LDERR_HTTP2_CLAIMED_PUSHED_STREAM_RESET_BY_SERVER = -374,
    // An HTTP transaction was retried too many times due for authentication or
    // invalid certificates. This may be due to a bug in the net stack that would
    // otherwise infinite loop, or if the server or proxy continually requests fresh
    // credentials or presents a fresh invalid certificate.
    LDERR_TOO_MANY_RETRIES = -375,
    // Received an HTTP/2 frame on a closed stream.
    LDERR_HTTP2_STREAM_CLOSED = -376,
    // Client is refusing an HTTP/2 stream.
    LDERR_HTTP2_CLIENT_REFUSED_STREAM = -377,
    // A pushed HTTP/2 stream was claimed by a request based on matching URL and
    // request headers, but the pushed response headers do not match the request.
    LDERR_HTTP2_PUSHED_RESPONSE_DOES_NOT_MATCH = -378,
    // The server returned a non-2xx HTTP response code.
    //
    // Not that this error is only used by certain APIs that interpret the HTTP
    // response itself. URLRequest for instance just passes most non-2xx
    // response back as success.
    LDERR_HTTP_RESPONSE_CODE_FAILURE = -379,
    // The certificate presented on a QUIC connection does not chain to a known root
    // and the origin connected to is not on a list of domains where unknown roots
    // are allowed.
    LDERR_QUIC_CERT_ROOT_NOT_KNOWN = -380,
    // A GOAWAY frame has been received indicating that the request has not been
    // processed and is therefore safe to retry on a different connection.
    LDERR_QUIC_GOAWAY_REQUEST_CAN_BE_RETRIED = -381,
    // The ACCEPT_CH restart has been triggered too many times
    LDERR_TOO_MANY_ACCEPT_CH_RESTARTS = -382,
    // The cache does not have the requested entry.
    LDERR_CACHE_MISS = -400,
    // Unable to read from the disk cache.
    LDERR_CACHE_READ_FAILURE = -401,
    // Unable to write to the disk cache.
    LDERR_CACHE_WRITE_FAILURE = -402,
    // The operation is not supported for this entry.
    LDERR_CACHE_OPERATION_NOT_SUPPORTED = -403,
    // The disk cache is unable to open this entry.
    LDERR_CACHE_OPEN_FAILURE = -404,
    // The disk cache is unable to create this entry.
    LDERR_CACHE_CREATE_FAILURE = -405,
    // Multiple transactions are racing to create disk cache entries. This is an
    // internal error returned from the HttpCache to the HttpCacheTransaction that
    // tells the transaction to restart the entry-creation logic because the state
    // of the cache has changed.
    LDERR_CACHE_RACE = -406,
    // The cache was unable to read a checksum record on an entry. This can be
    // returned from attempts to read from the cache. It is an internal error,
    // returned by the SimpleCache backend, but not by any URLRequest methods
    // or members.
    LDERR_CACHE_CHECKSUM_READ_FAILURE = -407,
    // The cache found an entry with an invalid checksum. This can be returned from
    // attempts to read from the cache. It is an internal error, returned by the
    // SimpleCache backend, but not by any URLRequest methods or members.
    LDERR_CACHE_CHECKSUM_MISMATCH = -408,
    // Internal error code for the HTTP cache. The cache lock timeout has fired.
    LDERR_CACHE_LOCK_TIMEOUT = -409,
    // Received a challenge after the transaction has read some data, and the
    // credentials aren't available.  There isn't a way to get them at that point.
    LDERR_CACHE_AUTH_FAILURE_AFTER_READ = -410,
    // Internal not-quite error code for the HTTP cache. In-memory hints suggest
    // that the cache entry would not have been useable with the transaction's
    // current configuration (e.g. load flags, mode, etc.)
    LDERR_CACHE_ENTRY_NOT_SUITABLE = -411,
    // The disk cache is unable to doom this entry.
    LDERR_CACHE_DOOM_FAILURE = -412,
    // The disk cache is unable to open or create this entry.
    LDERR_CACHE_OPEN_OR_CREATE_FAILURE = -413,
    // The server's response was insecure (e.g. there was a cert error).
    LDERR_INSECURE_RESPONSE = -501,
    // An attempt to import a client certificate failed, as the user's key
    // database lacked a corresponding private key.
    LDERR_NO_PRIVATE_KEY_FOR_CERT = 502,
    // An error adding a certificate to the OS certificate database.
    LDERR_ADD_USER_CERT_FAILED = -503,
    // An error occurred while handling a signed exchange.
    LDERR_INVALID_SIGNED_EXCHANGE = -504,
    // An error occurred while handling a Web Bundle source.
    LDERR_INVALID_WEB_BUNDLE = -505,
    // A Trust Tokens protocol operation-executing request failed for one of a
    // number of reasons (precondition failure, internal error, bad response).
    LDERR_TRUST_TOKEN_OPERATION_FAILED = -506,
    // When handling a Trust Tokens protocol operation-executing request, the system
    // was able to execute the request's Trust Tokens operation without sending the
    // request to its destination: for instance, the results could have been present
    // in a local cache (for redemption) or the operation could have been diverted
    // to a local provider (for "platform-provided" issuance).
    LDERR_TRUST_TOKEN_OPERATION_SUCCESS_WITHOUT_SENDING_REQUEST = -507,
    // A generic error for failed FTP control connection command.
    // If possible, please use or add a more specific error code.
    LDERR_FTP_FAILED = -601,
    // The server cannot fulfill the request at this point. This is a temporary
    // error.
    // FTP response code 421.
    LDERR_FTP_SERVICE_UNAVAILABLE = -602,
    // The server has aborted the transfer.
    // FTP response code 426.
    LDERR_FTP_TRANSFER_ABORTED = -603,
    // The file is busy, or some other temporary error condition on opening
    // the file.
    // FTP response code 450.
    LDERR_FTP_FILE_BUSY = -604,
    // Server rejected our command because of syntax errors.
    // FTP response codes 500, 501.
    LDERR_FTP_SYNTAX_ERROR = -605,
    // Server does not support the command we issued.
    // FTP response codes 502, 504.
    LDERR_FTP_COMMAND_NOT_SUPPORTED = -606,
    // Server rejected our command because we didn't issue the commands in right
    // order.
    // FTP response code 503.
    LDERR_FTP_BAD_COMMAND_SEQUENCE = -607,
    // PKCS #12 import failed due to incorrect password.
    LDERR_PKCS12_IMPORT_BAD_PASSWORD = -701,
    // PKCS #12 import failed due to other error.
    LDERR_PKCS12_IMPORT_FAILED = -702,
    // CA import failed - not a CA cert.
    LDERR_IMPORT_CA_CERT_NOT_CA = -703,
    // Import failed - certificate already exists in database.
    // Note it's a little weird this is an error but reimporting a PKCS12 is ok
    // (no-op).  That's how Mozilla does it, though.
    LDERR_IMPORT_CERT_ALREADY_EXISTS = -704,
    // CA import failed due to some other error.
    LDERR_IMPORT_CA_CERT_FAILED = -705,
    // Server certificate import failed due to some internal error.
    LDERR_IMPORT_SERVER_CERT_FAILED = -706,
    // PKCS #12 import failed due to invalid MAC.
    LDERR_PKCS12_IMPORT_INVALID_MAC = -707,
    // PKCS #12 import failed due to invalid/corrupt file.
    LDERR_PKCS12_IMPORT_INVALID_FILE = -708,
    // PKCS #12 import failed due to unsupported features.
    LDERR_PKCS12_IMPORT_UNSUPPORTED = -709,
    // Key generation failed.
    LDERR_KEY_GENERATION_FAILED = -710,
    // Failure to export private key.
    LDERR_PRIVATE_KEY_EXPORT_FAILED = -712,
    // Self-signed certificate generation failed.
    LDERR_SELF_SIGNED_CERT_GENERATION_FAILED = -713,
    // The certificate database changed in some way.
    LDERR_CERT_DATABASE_CHANGED = -714,
    // DNS resolver received a malformed response.
    LDERR_DNS_MALFORMED_RESPONSE = -800,
    // DNS server requires TCP
    LDERR_DNS_SERVER_REQUIRES_TCP = -801,
    // DNS server failed.  This error is returned for all of the following
    // error conditions:
    // 1 - Format error - The name server was unable to interpret the query.
    // 2 - Server failure - The name server was unable to process this query
    //     due to a problem with the name server.
    // 4 - Not Implemented - The name server does not support the requested
    //     kind of query.
    // 5 - Refused - The name server refuses to perform the specified
    //     operation for policy reasons.
    LDERR_DNS_SERVER_FAILED = -802,
    // DNS transaction timed out.
    LDERR_DNS_TIMED_OUT = -803,
    // The entry was not found in cache or other local sources, for lookups where
    // only local sources were queried.
    // TODO(ericorth): Consider renaming to DNS_LOCAL_MISS or something like that as
    // the cache is not necessarily queried either.
    LDERR_DNS_CACHE_MISS = -804,
    // Suffix search list rules prevent resolution of the given host name.
    LDERR_DNS_SEARCH_EMPTY = -805,
    // Failed to sort addresses according to RFC3484.
    LDERR_DNS_SORT_ERROR = -806,
    // Failed to resolve the hostname of a DNS-over-HTTPS server.
    LDERR_DNS_SECURE_RESOLVER_HOSTNAME_RESOLUTION_FAILED = -808,
    // DNS identified the request as disallowed for insecure connection (http/ws).
    // Error should be handled as if an HTTP redirect was received to redirect to
    // https or wss.
    LDERR_DNS_NAME_HTTPS_ONLY = -809,
    // All DNS requests associated with this job have been cancelled.
    LDERR_DNS_REQUEST_CANCELLED = -810
  };
  /**
   * Bit flags for drag&drop operations.
   */
  enum DragModeFlag
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
  typedef int DragModeMask;
  /**
   * Notification levels for information dispatched by a browser.
   */
  enum NotificationLevel
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
   * Record types to identify execution contexts.
   */
  enum RecordType
  {
    // Capture mode.
    REC_CAPTURE = 0,
    // Replay mode.
    REC_REPLAY,
    // Normal context, no record tool.
    REC_UNKNOWN
  };
  /**
   * Record capture level for notifications coming from a web view.
   */
  enum CaptureLevel
  {
    // Strict mode: capture as much as possible.
    CAP_STRICT = 0,
    // Soft mode: capture limited set.
    CAP_SOFT,
    CAP_UNKNOWN
  };
  /**
   * Policies to apply when the current page wants to open a popup window.
   */
  enum PopupPolicy
  {
    // Do nothing: the popup will not open. If `window.open` was used, it will return `null`.
    POP_IGNORE = 0,
    // Let the browser open a new window.
    POP_OPEN,
    // Deny the popup creation and open the target URL in the current window instead.
    // If `window.open` was used, it will return `null`.
    POP_OPEN_CURRENT,
    // Default behavior.
    POP_DEFAULT = POP_OPEN
  };

  // ----------------------------------------------------------------------------
  // Structures
  // ----------------------------------------------------------------------------

  /**
   * Properties for popup windows.
   */
  struct PopupProperties
  {
    // Position and size of the popup (anchor point is top left).
    CATMM2D::Rect<int> rect;
    // URL to load in the popup window.
    CATUnicodeString targetURL;
    // Title of the popup window.
    CATUnicodeString title;
    // Is the popup fullscreen?
    bool isFullscreen;
    // Is the popup resizable?
    bool isResizable;
    // Does it have an address bar? (line editor for URLs).
    bool isAddressBarVisible;
    // Does it have a menu bar? (actions, parameters, etc.).
    bool isMenuBarVisible;
    // Does it display scrollbars?
    bool isScrollBarVisible;
    // Does it have a status bar? (preview URLs, errors, etc.).
    bool isStatusBarVisible;
    // Does it have a tool bar? (navigation buttons and such).
    bool isToolBarVisible;

    PopupProperties()
      : isFullscreen(false)
      , isResizable(true)
      , isAddressBarVisible(false)
      , isMenuBarVisible(false)
      , isScrollBarVisible(true)
      , isStatusBarVisible(false)
      , isToolBarVisible(false)
    {
    }
    PopupProperties(const PopupProperties& i_properties)
      : rect(i_properties.rect)
      , targetURL(i_properties.targetURL)
      , title(i_properties.title)
      , isFullscreen(i_properties.isFullscreen)
      , isResizable(i_properties.isResizable)
      , isAddressBarVisible(i_properties.isAddressBarVisible)
      , isMenuBarVisible(i_properties.isMenuBarVisible)
      , isScrollBarVisible(i_properties.isScrollBarVisible)
      , isStatusBarVisible(i_properties.isStatusBarVisible)
      , isToolBarVisible(i_properties.isToolBarVisible)
    {
    }
  };
  /**
   * Properties for context menus.
   */
  struct ContextMenuProperties
  {
    // Relative menu position (to the view origin).
    int x, y;
    // Possible actions on the node: cut, copy, paste, delete, etc.
    ContextMenuEditMask editFlags;
    // Media-related state of the node: can be saved, has video, etc.
    ContextMenuMediaMask mediaFlags;
    // Node type: link, media, selection, etc.
    ContextMenuTypeMask typeFlags;
    // Media type of the node: file, image, video, etc.
    ContextMenuMediaType mediaType;
    // URL of the link enclosing the node.
    CATUnicodeString linkURL;
    // Unfiltered URL of the link enclosing the node (use for "Copy link" command).
    CATUnicodeString unfilteredLinkURL;
    // URL of the current frame.
    CATUnicodeString currentURL;
    // Selected text (if any) in the current frame.
    CATUnicodeString selectedText;
    // Source URL of the node if it's a media (image, audio, video).
    CATUnicodeString sourceURL;
    // Set to TRUE if the node is editable.
    bool isEditable;

    ContextMenuProperties()
      : x(0)
      , y(0)
      , editFlags(CM_EDIT_NONE)
      , mediaFlags(CM_MEDIA_NONE)
      , typeFlags(CM_TYPE_NONE)
      , mediaType(CM_MEDIA_NOTYPE)
      , isEditable(false)
    {
    }
    ContextMenuProperties(const ContextMenuProperties& i_properties)
      : x(i_properties.x)
      , y(i_properties.y)
      , editFlags(i_properties.editFlags)
      , mediaFlags(i_properties.mediaFlags)
      , typeFlags(i_properties.typeFlags)
      , mediaType(i_properties.mediaType)
      , isEditable(i_properties.isEditable)
      , linkURL(i_properties.linkURL)
      , unfilteredLinkURL(i_properties.unfilteredLinkURL)
      , currentURL(i_properties.currentURL)
      , selectedText(i_properties.selectedText)
      , sourceURL(i_properties.sourceURL)
    {
    }
  };
  /**
   * Key event.
   */
  struct KeyEvent
  {
    KeyType type;
    int charCode;
    int vkCode;
    int keyCode;
    KeyModifiers modifiers;

    KeyEvent()
      : type(KEY_DOWN)
      , charCode(0)
      , keyCode(0)
      , vkCode(0)
      , modifiers(0)
    {
    }
    KeyEvent(const KeyType i_type,
      int i_charCode,
      int i_vkCode,           
      const KeyModifiers i_modifiers,
      int i_keyCode=0)
      : type(i_type)
      , charCode(i_charCode)
      , keyCode(i_keyCode)
      , vkCode(i_vkCode)
      , modifiers(i_modifiers)
    {
    }
  };
  /**
   * Mouse event.
   */
  struct MouseEvent
  {
    int x, y;
    MouseButton button;
    KeyModifiers modifiers;

    MouseEvent()
      : x(0)
      , y(0)
      , button(MOUSE_LEFT)
      , modifiers(0)
    {
    }
    MouseEvent(
      const int i_x, const int i_y, const MouseButton i_button, const KeyModifiers i_modifiers)
      : x(i_x)
      , y(i_y)
      , button(i_button)
      , modifiers(i_modifiers)
    {
    }
  };
  /**
   * Location info for function calls, errors, etc.
   */
  struct StackFrameLocation
  {
    CATUnicodeString url;
    int line;
    int column;

    StackFrameLocation()
      : line(1)
      , column(1)
    {
    }
    StackFrameLocation(const CATUnicodeString& i_url, const int i_line, const int i_column)
      : url(i_url)
      , line(i_line)
      , column(i_column)
    {
    }
    StackFrameLocation(const StackFrameLocation& i_other)
      : url(i_other.url)
      , line(i_other.line)
      , column(i_other.column)
    {
    }
  };
  /**
   * Boolean options for recordable notifications.
   */
  struct RecordOptions
  {
    bool recordable;
    bool captureAll;

    RecordOptions()
      : recordable(false)
      , captureAll(true)
    {
    }
  };
  /**
   * Result struct for replay interactions handled with WebRecord.
   */
  struct ReplayResult
  {
    int code;
    CATUnicodeString message;

    ReplayResult(const int i_code, const CATUnicodeString& i_message)
      : code(i_code)
      , message(i_message)
    {
    }
    ReplayResult(const ReplayResult& i_other)
      : code(i_other.code)
      , message(i_other.message)
    {
    }
  };
  /**
   * Group of fields that identify a subject or an issuer for a certificate.
   * https://www.ietf.org/rfc/rfc5280.txt
   * https://tools.ietf.org/html/rfc2511
   */
  struct SSLCertificateEntity
  {
    // CN field.
    CATUnicodeString commonName;
    // C field.
    CATUnicodeString countryName;
    // L field.
    CATUnicodeString localityName;
    // S or ST field.
    CATUnicodeString stateOrProvinceName;
    // DC fields.
    std::vector<CATUnicodeString> domainComponents;
    // O fields.
    std::vector<CATUnicodeString> organizationNames;
    // OU fields.
    std::vector<CATUnicodeString> organizationUnitNames;
    // STREET fields.
    std::vector<CATUnicodeString> streetAddresses;

    CATUnicodeString GetDisplayName() const
    {
      if (commonName.GetLengthInChar() > 0) return commonName;
      if (!organizationNames.empty()) return organizationNames[0];
      if (!organizationUnitNames.empty()) return organizationUnitNames[0];
      return "";
    }
  };
  /**
   * SSL certificate properties and data.
   */
  struct SSLCertificate
  {
    // Certificate issuer i.e. who provided the certificate.
    SSLCertificateEntity issuer;
    // Certificate subject i.e. what is being secured.
    SSLCertificateEntity subject;
    // DER encoded data.
    CATBinary encodedData;
    // DER encoded serial number.
    CATBinary serialNumber;
    // First day of validity: the certificate is invalid before that date.
    CATTime validityStart;
    // Last day of validity: the certificate will be invalid after that date.
    CATTime validityEnd;
  };
  /**
   * Touch point.
   */
  struct Touch
  {
    // Identification number for a touch point.
    int id;
    // Touch event type.
    TouchState type;
    // Horizontal coordinate in pixels in the client area.
    int x;
    // Vertical coordinate in pixels in the client area.
    int y;
  };
  /**
   * JS values.
   */
  struct JSValue
  {
    // Only support primitive values because of time constraints and possible performance issues due
    // to lots of copying between each implementation layer.
    enum class Type
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

    Type type;

    // Boolean value to read if `type` is `JS_BOOLEAN`.
    bool boolValue;
    // Number value to read if `type` is `JS_NUMBER`.
    double numberValue;
    // String value to read if `type` is `JS_STRING`.
    CATUnicodeString stringValue;
  };
  /**
   * JS errors.
   */
  struct JSError
  {
    // Error description.
    CATUnicodeString message;
    // Source code (only one line) that generated the error.
    CATUnicodeString code;
    // URL for the script that generated the error, if it comes from a script resource (not inline).
    CATUnicodeString scriptURL;
    // Line number in the script that generated the error.
    int line;
    // Column index on the source code line that generated the error.
    int column;
  };

  // ----------------------------------------------------------------------------
  // Classes
  // ----------------------------------------------------------------------------

  class ExportedByMultimediaItf FileDialogCallback
  {
  public:
    typedef std::function<void(const int, const std::vector<CATUnicodeString>&)> AcceptCallback;
    typedef std::function<void()> CancelCallback;

    FileDialogCallback() = delete;
    FileDialogCallback(AcceptCallback&&, CancelCallback&&);
    ~FileDialogCallback();

    void Accept(const int i_filterIndex, const std::vector<CATUnicodeString>& i_paths);
    void Cancel();

  private:
    void Clear();

    AcceptCallback _accept;
    CancelCallback _cancel;
  };

  class ExportedByMultimediaItf HTTPAuthCallback
  {
  public:
    typedef std::function<void(const CATUnicodeString&, const CATUnicodeString&)> LoginCallback;
    typedef std::function<void()> CancelCallback;

    HTTPAuthCallback() = delete;
    HTTPAuthCallback(LoginCallback&&, CancelCallback&&);
    ~HTTPAuthCallback();

    void Submit(const CATUnicodeString& i_username, const CATUnicodeString& i_password);
    void Cancel();

  private:
    void Clear();

    LoginCallback _login;
    CancelCallback _cancel;
  };

  class ExportedByMultimediaItf JSEvalCallback
  {
  public:
    typedef std::function<void(const JSValue&)> ResultCallback;
    typedef std::function<void(const JSError&)> ErrorCallback;

    JSEvalCallback(ResultCallback&&, ErrorCallback&&);
    ~JSEvalCallback();

    void ApplyResult(const JSValue&);
    void ApplyError(const JSError&);

  private:
    JSEvalCallback();
    JSEvalCallback(const JSEvalCallback&);
    JSEvalCallback& operator=(const JSEvalCallback&);

    void Clear();

    ResultCallback _resultCallback;
    ErrorCallback _errorCallback;
  };

  class ExportedByMultimediaItf PermissionCallback
  {
  public:
    typedef std::function<void(const PermissionResult&)> ContinueCallback;

    PermissionCallback(ContinueCallback&&);
    ~PermissionCallback();

    void Continue(const PermissionResult&);

  private:
    PermissionCallback();
    PermissionCallback(const PermissionCallback&);
    PermissionCallback& operator=(const PermissionCallback&);

    void Clear();

    ContinueCallback _callback;
  };
} // namespace MMW

#endif // CATMMWebTypes_H
