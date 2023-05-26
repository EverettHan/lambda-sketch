#ifndef CATDLGFRAMEPROTECTED_H
#define CATDLGFRAMEPROTECTED_H

#include "DI0PANV2.h"

#include "CATBoolean.h"

class CATDlgFrame;
class CATNotification;

class ExportedByDI0PANV2 CATDlgFrameProtected
{
public :
  // If one child and this child is a CATDlgBlackBox, gives keyboard focus to the CATDlgBlackBox representation
  // (which in turn gives focus to the native window embedded; ref to CATViewer structure)
  // else gives focus to the frame representation 
  static void SetKeyboardFocusOn(CATDlgFrame* iFrame); // DBE Jun 2014 Implemented on Windows only.

  // When a CATDlgFrame or one of its children is clicked, we send this notification
  // It is usefull for CID_FRAME when clicking inside a Dialog workbench needs to activate a CID_FRAME title
  static CATNotification * GetActivateNotification(CATDlgFrame * iFrame); // NCT Feb 2016 Implemented on Windows only.
};

#endif
