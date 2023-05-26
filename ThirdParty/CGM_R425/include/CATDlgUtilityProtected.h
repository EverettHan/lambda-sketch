#ifndef UIUTILPRO_H
#define UIUTILPRO_H

#include "CATDlgUtility.h"

// DBE Nov 2004 
// For R201
// We do not intend to document thoses styles for CAA
//
// CATDialog styles
//-----------------

// Toolbar
//--------
#define CATDlgTlbTaskBar      (1 << 24)
#define CATDlgTlbPalette      (1 << 25) // DBE Jan 2010
#define CATDlgTlbCompass      (1 << 26)
#define CATDlgTlbAction       (1 << 27) 

// DBE Nov 2007
// Style created for 3DViaShape
// CATDlgDocument
//---------------
// On Windows, this style is relevant only if CATDlgWndFrameMDI style is not set and it removes 
// the default 4 pixel margin added on right and on bottom.
// On Unix, no effect, as this default margin does not exist.
#define CATDlgWndNoMargin     (1 << 17)

// Currently implemented on Windows only.
//
// From one session to another one and based on the window name, the position and size of the windows are stored as "preferences" and
// retrieved with the following specifications. 
// 1 - For SDI CATDlgDocument windows, the restored width (resp. height) is the maximum of the previously stored width (resp. height) and of
//     the default initial width (resp. height) defined by the window contents. It is a 3DVia Shape specification.
// 2 - The restored position and size are adjusted so that the new session window is entirely displayed on the monitor (or on one monitor).
//     It is both a 3DViaShape specification and a Microsoft Ergonomy recommandation.   
#define CATDlgWndKeepPosAndSize (1 << 18)

// NCT Apr 2016
// Style created for CATFrmWindow in CID_FRAME
// CATDlgDialog
//-------------
#define CATDlgWndChildEmbedded (1ULL << 32)

// Style created for extracted windows in CID_FRAME
// CATDlgDialog
//-------------
#define CATDlgWndExtracted (1ULL << 33)

// Style created for windows which must not take focus when they are created
// CATDlgDialog
//-------------
#define CATDlgWndNoDefaultActivation (1ULL << 34)

#endif
