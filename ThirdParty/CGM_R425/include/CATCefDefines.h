//===================================================================
// COPYRIGHT Dassault Systèmes 2015-10-27
//===================================================================
// Abstract: Type definitions for ChromiumEmbedded
//===================================================================
// 2015-10-27 Creation: D6K
//===================================================================

#ifndef CATCefDefines_H
#define CATCefDefines_H

// ----------------------------------------------------------------------------
// Chromium cursor resource IDs
// Taken from ui_unscaled_resources.h (generated file in CEF)
// ----------------------------------------------------------------------------

#define IDC_ALIAS          4500
#define IDC_CELL           4501
#define IDC_COLRESIZE      4502
#define IDC_COPYCUR        4503
#define IDC_CURSOR_NONE    4504
#define IDC_HAND_GRAB      4505
#define IDC_HAND_GRABBING  4506
#define IDC_PAN_EAST       4507
#define IDC_PAN_MIDDLE     4508
#define IDC_PAN_NORTH      4509
#define IDC_PAN_NORTH_EAST 4510
#define IDC_PAN_NORTH_WEST 4511
#define IDC_PAN_SOUTH      4512
#define IDC_PAN_SOUTH_EAST 4513
#define IDC_PAN_SOUTH_WEST 4514
#define IDC_PAN_WEST       4515
#define IDC_ROWRESIZE      4516
#define IDC_VERTICALTEXT   4517
#define IDC_ZOOMIN         4518
#define IDC_ZOOMOUT        4519

// ----------------------------------------------------------------------------
// Platform-specific types for handles
// ----------------------------------------------------------------------------

#if defined(_WINDOWS_SOURCE) // HWND

#define CATCefCursorHandle HCURSOR
#define CATCefEventHandle  MSG*
#define CATCefWindowHandle HWND

#elif defined(_DARWIN_SOURCE)

class NSCursor;
class NSEvent;
struct NSView;

#define CATCefCursorHandle NSCursor*
#define CATCefEventHandle  NSEvent*
#define CATCefWindowHandle NSView*

#elif defined(_LINUX_SOURCE)

#define CATCefCursorHandle void*
#define CATCefEventHandle  GdkEvent*
#define CATCefWindowHandle unsigned long

#endif

#endif // CATCefDefines_H
