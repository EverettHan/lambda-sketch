#ifndef CATDlgWindowProtected_H
#define CATDlgWindowProtected_H

#include "DI0PANV2.h"

class CATDlgWindow;

#include "CATBoolean.h"

/**
 * This class provides access to non public API over CATDlgWindow
 */
class ExportedByDI0PANV2 CATDlgWindowProtected
{
public:
  /**
   * @deprecated R422 Use RequestTranslatedContextualMenuEx
   * Request next contextual menu to be displayed with translated position regarding event position
   * @param iWindow the window for which contextual menu will be invoked
   * @param iDeltaX the horizontal translation to be used for menu display
   * @param iDeltaY the vertical translation to be used for menu display
   */
  static void RequestTranslatedContextualMenu(CATDlgWindow * iWindow, int iDeltaX, int iDeltaY);

  /**
   * Request next contextual menu to be displayed with translated position regarding event position
   * @param iWindow the window for which contextual menu will be invoked
   * @param iDeltaX the horizontal translation to be used for menu display
   * @param iDeltaY the vertical translation to be used for menu display
   * @param iAlreadyScaled specifies if translation parameters respect the current display scaling
   * When FALSE, iDeltaX, iDeltaY must match a 100% display scaling, they will be automatically scaled according to current display scaling
   * When TRUE, iDeltaX, iDeltaY must match the current display scaling, they won't be scaled
   */
  static void RequestTranslatedContextualMenuEx(CATDlgWindow * iWindow, int iDeltaX, int iDeltaY, CATBoolean iAlreadyScaled);
};

#endif
