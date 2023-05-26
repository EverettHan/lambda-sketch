#ifndef CATMakeRectVisible_H
#define CATMakeRectVisible_H

#include "DI0PANV2.h"

// DRECT
#include "CATDlgUtility.h"

/**
 * Make a rectangle area visible on screen
 * @param iRect the input area
 * @param oRect the output area
 * @param iAllowResize set to 1 to resize the rectangle area when it is bigger than screen
 * @param iUserIntersectionRect set to 1 to use the monitor whose intersection with rectangle area is bigger than the others,
 *                              otherwise we use the monitor which contains the rectangle area top/left origin
 */
void ExportedByDI0PANV2 CATMakeRectVisible(const DRECT& iRect, DRECT& oRect, int iAllowResize = 0, int iUseIntersectionRect = 0);

#ifdef DRIVER_WINDOWS

class CRect;
// @deprecated R425
void ExportedByDI0PANV2 CATMakeRectVisible(CRect &rectIn, CRect &rectOut, int resize=0, int useIntersectionRect =0);

#endif

#endif
