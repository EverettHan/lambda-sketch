#ifndef CATDlgDefCur_H
#define CATDlgDefCur_H

#include "DI0PANV2.h"

#include "CATDialog.h"

class CATString;

/**
 * @deprecated R421 Use CATDialog::GetCursor(const CATUnicodeString&) to load cursor from PNG file
 *
 * Create a new custom cursor
 * @param iWidth, iHeight the cursor size
 * @param iHotSpotX, iHotSpotY the cursor hot spot position
 * @param iContent the cursor content as a spaces/dots/stars buffer
 * @param iStarColor the RGB components of the '*' star character
 * @param iDotColor the RGB components of the '.' dot character
 * @return the new cursor (to be destroyed with CATDialog::FreeCursor)
 */
CATDlgCursorID ExportedByDI0PANV2 CATDlgDefCur(int iWidth, int iHeight, int iHotSpotX, int iHotSpotY, const char *iContent, unsigned char iStarColor[3], unsigned char iDotColor[3]);

/**
 * @deprecated R421 Use CATDialog::GetCursor(const CATUnicodeString&) to load cursor from PNG file
 *
 * Create a new custom cursor from a bitmap file (Windows only)
 * @param iHotSpotX, iHotSpotY the cursor hot spot position
 * @param iFileName the bitmap file name
 * @return the new cursor (to be destroyed with CATDialog::FreeCursor)
 */
CATDlgCursorID ExportedByDI0PANV2 CATDlgDefCur(int iHotSpotX, int iHotSpotY, const CATString& iFileName);

#endif
