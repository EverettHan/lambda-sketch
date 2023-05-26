#ifndef CATDLGNOTIFYPROTECTED_H
#define CATDLGNOTIFYPROTECTED_H
#include "DI0PANV2.h"
class CATDlgNotify;
class CATUnicodeString;

class ExportedByDI0PANV2 CATDlgNotifyProtected
{
  public :
  static int DisplayBlockedSimplified(CATDlgNotify* iNotif, const CATUnicodeString& iMessage, const CATUnicodeString& iWnd_title);
  /**
   * Enables to set default button different from first one
   *
   * (effective on Windows only).
   *
   * @param iNotif
   *  The CATDlgNotify object.
   * @param iDefaultButtonNumber
   *  The value ranges from 1 to the number of buttons (4 at most).  
   */
  static void SetDefaultButton(CATDlgNotify* iNotif, int iDefaultButtonNumber);

  static void HideCurrentEasyWarningMessage();
};
#endif


